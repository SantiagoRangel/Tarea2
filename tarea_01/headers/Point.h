#ifndef POINT_H
#define POINT_H

#include <string>
#include <sstream>

template<class T>
class Point
{
    public:
        Point();
        Point(T coord);
        Point(T x_coord, T y_coord);
        Point(const Point<T> &point);
        ~Point();
        T get_x() const;
        T get_y() const;
        std::string coords_to_string();
        void print_coords();
        Point operator+(T value);
        Point operator-(T value);
        Point operator*(T value);
        Point operator/(T value);
        Point operator+(Point<T> &point);
        Point operator-(Point<T> &point);
        Point operator*(Point<T> &point);
        Point operator/(Point<T> &point);

    private:
        T x_coord;
        T y_coord;
};

// Constructores
template<class T>
Point<T>::Point(){
    x_coord = 0;
    y_coord = 0;
}

template<class T>
Point<T>::Point(T coord){
    x_coord = coord;
    y_coord = coord;
}

template<class T>
Point<T>::Point(T xCoord, T yCoord){
    x_coord = xCoord;
    y_coord = yCoord;
}

template<class T>
Point<T>::Point(const Point<T> &point){
    this->x_coord = point.get_x();
    this->y_coord = point.get_y();
}

// Destructor
template<class T>
Point<T>::~Point(){}

// Getters
template<class T>
T Point<T>::get_x() const{
    return x_coord;
}

template<class T>
T Point<T>::get_y() const{
    return y_coord;
}

// Obtener/imprimir coordenadas
template<class T>
void Point<T>::print_coords(){
    std::cout << "(x, y) = " << "(" << x_coord << ", " << y_coord << ")" << std::endl;
}

template<class T>
std::string Point<T>::coords_to_string(){
    std::ostringstream oss;
    oss << "(" + std::to_string(x_coord) + ", " + std::to_string(y_coord) + ")";
    return oss.str();
}

// Operadores
template<class T>
Point<T> Point<T>::operator+(T value) {
    return Point<T>(this->x_coord + value, this->y_coord + value);
}

template<class T>
Point<T> Point<T>::operator-(T value) {
    return Point<T>(this->x_coord - value, this->y_coord - value);
}

template<class T>
Point<T> Point<T>::operator*(T value) {
    return Point<T>(this->x_coord * value, this->y_coord * value);
}

template<class T>
Point<T> Point<T>::operator/(T value) {
    return Point<T>(this->x_coord / value, this->y_coord / value);
}

template<class T>
Point<T> Point<T>::operator+(Point<T> &point){
    return Point<T>(this->x_coord + point.x_coord, this->y_coord + point.y_coord);
}

template<class T>
Point<T> Point<T>::operator-(Point<T> &point){
    return Point<T>(this->x_coord - point.x_coord, this->y_coord - point.y_coord);
}

template<class T>
Point<T> Point<T>::operator*(Point<T> &point){
    return Point<T>(this->x_coord * point.x_coord, this->y_coord * point.y_coord);
}

template<class T>
Point<T> Point<T>::operator/(Point<T> &point){
    return Point<T>(this->x_coord / point.x_coord, this->y_coord / point.y_coord);
}


#endif // POINT_H
