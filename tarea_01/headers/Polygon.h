#ifndef POLYGON_H
#define POLYGON_H

#include <Point.h>

template<class T>
class Polygon
{
    public:
        Polygon(std::vector<Point<T>> p_list);
        virtual ~Polygon();
        std::vector<Point<T>> get_points_vec() const;
        T get_area();
        bool is_in_ccw();
        bool contains_point(Point<T> &point);

    private:
        std::vector<Point<T>> points_list;
};

// Constructor
template<class T>
Polygon<T>::Polygon(std::vector<Point<T>> p_vec){
    points_list = p_vec;
}

// Destructor
template<class T>
Polygon<T>::~Polygon(){}

// Retornar vector de puntos
template<class T>
std::vector<Point<T>> Polygon<T>::get_points_vec() const{
    return points_list;
}

// Calcular area
template<class T>
T Polygon<T>::get_area(){
    T area = 0;
    for (int i = 0; i < points_list.size(); i++){
        Point<T> p0 = points_list[i];
        Point<T> p1 = points_list[(i + 1) % points_list.size()];
        area += (p1.get_x() - p0.get_x()) * (p1.get_y() + p0.get_y());
    }
    return area / 2;
}

// 1 si esta en CCW, -1 si no
template<class T>
bool Polygon<T>::is_in_ccw(){
    T area = this->get_area();
    if (area < 0) return true;
    else return false;
}

// 1 si el punto esta dentro, 0 si no
template<class T>
bool Polygon<T>::contains_point(Point<T> &point){
    // Verificar bounding box
    T x_min = 0;
    T x_max = 0;
    T y_min = 0;
    T y_max = 0;
    for (int i = 0; i < this->points_list.size(); i++){
        T p_x = points_list[i].get_x();
        T p_y = points_list[i].get_y();
        if (p_x < x_min)
            x_min = p_x;
        if (p_x > x_max)
            x_max = p_x;
        if (p_y < y_min)
            y_min = p_y;
        if (p_y > y_max)
            y_max = p_y;
    }
    if (point.get_x() < x_min || point.get_x() > x_max || point.get_y() < y_min || point.get_y() > y_max)
        return false;

    // Ray casting
    Point<T> extreme = Point<T>(x_max + 1, point.get_y());
    Segment<T> ext_segment = Segment<T>(point, extreme);
    int intersections = 0;

    for (int i = 0; i < points_list.size(); i++){
        Point<T> q1 = points_list[i];
        Point<T> q2 = points_list[(i + 1) % points_list.size()];
        Segment<T> edge= Segment<T>(q1, q2);

        if (ext_segment.intersects(edge)){
            // punto es colinear a la arista
            if (edge.isLeft(point) == 0)
                return edge.contains_point(point);
            intersections++;
        }
    }
    if (intersections % 2 == 0)
        return false;
    else
        return true;
}

#endif // POLYGON_H
