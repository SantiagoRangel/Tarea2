#ifndef SEGMENT_H
#define SEGMENT_H

#include <math.h>
#include <string>
#include <Point.h>

template<class T>
class Segment
{
    public:
        Segment(const Point<T> &point_1, const Point<T> &point_2);
        virtual ~Segment();
        Point<T> get_p1() const;
        Point<T> get_p2() const;
        T get_length();
        int isLeft(Point<T> &point);
        bool contains_point(Point<T> &point);
        bool intersects(Segment<T> &seg);
        std::string points_to_string();

    private:
        Point<T> p1;
        Point<T> p2;
};

// Constructor
template<class T>
Segment<T>::Segment(const Point<T> &point_1, const Point<T> &point_2){
    this->p1 = point_1;
    this->p2 = point_2;
}

// Destructor
template<class T>
Segment<T>::~Segment(){}

// Getters
template<class T>
Point<T> Segment<T>::get_p1() const{
    return p1;
}

template<class T>
Point<T> Segment<T>::get_p2() const{
    return p2;
}

// Coordenadas de los puntos
template<class T>
std::string Segment<T>::points_to_string(){
    std::ostringstream oss;
    oss << p1.coords_to_string() << " ---> " << p2.coords_to_string();
    return oss.str();
}

// Calcular largo
template<class T>
T Segment<T>::get_length(){
    return sqrt (pow ((p2.get_x() - p1.get_x()), 2) + pow ((p2.get_y() - p1.get_y()), 2));
}

// Left = 1, right = -1, colinear = 0
template<class T>
int Segment<T>::isLeft(Point<T> &point){
    T val = (p2.get_x() - p1.get_x()) * (point.get_y() - p1.get_y()) - (p2.get_y() - p1.get_y()) * (point.get_x() - p1.get_x());
    if (val > 0)
        return 1;
    else if (val < 0)
        return -1;
    else
        return 0;
}

// true si segmento pasa por punto, false si no
template<class T>
bool Segment<T>::contains_point(Point<T> &point){
    T x_min = std::min(p1.get_x(), p2.get_x());
    T x_max = std::max(p1.get_x(), p2.get_x());
    T y_min = std::min(p1.get_y(), p2.get_y());
    T y_max = std::max(p1.get_y(), p2.get_y());

    if (point.get_x() <= x_max && point.get_x() >= x_min && point.get_y() <= y_max && point.get_y() >= y_min)
        return true;
    else
        return false;
}

// true si segmentos se intersectan, false si no
// idea sacada de https://bit.ly/2K8JRsD
template<class T>
bool Segment<T>::intersects(Segment<T> &seg){
    Point<T> q1 = seg.get_p1();
    Point<T> q2 = seg.get_p2();

    int o1 = this->isLeft(q1);
    int o2 = this->isLeft(q2);
    int o3 = seg.isLeft(p1);
    int o4 = seg.isLeft(p2);

    // Caso general
    if (o1 != o2 && o3 != o4)
        return true;

    // Casos especiales
    // q1 es colinear a p1p2 y esta contenido en el segmento
    if (o1 == 0 && this->contains_point(q1)) return true;
    // q2 es colinear a p1p2 y esta contenido en el segmento
    if (o2 == 0 && this->contains_point(q2)) return true;
    // p1 es colinear a q1q2 y esta contenido en el segmento
    if (o3 == 0 && seg.contains_point(p1)) return true;
     // p2 es colinear a q1q2 y esta contenido en el segmento
    if (o4 == 0 && seg.contains_point(p2)) return true;

    return false;
}

#endif // SEGMENT_H
