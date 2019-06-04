#ifndef VECTOR_H
#define VECTOR_H

#include <math.h>
#include <Point.h>

template<class T>
class Vector
{
    public:
        Vector();
        Vector(T coord);
        Vector(T x_coord, T y_coord);
        Vector(T x_coord, T y_coord, T z_coord);
        Vector(const Point<T> &point);
        Vector(const Point<T> &point_1, const Point<T> &point_2);
        Vector(const Vector<T> &vec);
        virtual ~Vector();
        T get_x() const;
        T get_y() const;
        T get_z() const;
        T get_norm() const;
        std::string coords_to_string();
        void print_coords();
        void normalize();
        Vector<T> operator+(T value);
        Vector<T> operator-(T value);
        Vector<T> operator*(T value);
        Vector<T> operator/(T value);
        Vector<T> operator+(Vector<T> &Vector);
        Vector<T> operator-(Vector<T> &Vector);
        T dot(Vector<T> &vec);
        Vector<T> cross(Vector<T> &vec);

    private:
        T x_coord;
        T y_coord;
        T z_coord;
};

// Constructores
template<class T>
Vector<T>::Vector(){
    x_coord = 0;
    y_coord = 0;
    z_coord = 0;
}

template<class T>
Vector<T>::Vector(T coord){
    x_coord = coord;
    y_coord = coord;
    z_coord = coord;
}

template<class T>
Vector<T>::Vector(T xCoord, T yCoord){
    x_coord = xCoord;
    y_coord = yCoord;
    z_coord = 0;
}

template<class T>
Vector<T>::Vector(T xCoord, T yCoord, T zCoord){
    x_coord = xCoord;
    y_coord = yCoord;
    z_coord = zCoord;
}

template<class T>
Vector<T>::Vector(const Point<T> &point){
    this->x_coord = point.get_x();
    this->y_coord = point.get_y();
    this->z_coord = 0;
}

template<class T>
Vector<T>::Vector(const Point<T> &point_1, const Point<T> &point_2){
    this->x_coord = point_2.get_x() - point_1.get_x();
    this->y_coord = point_2.get_y() - point_1.get_y();
    this->z_coord = 0;
}

template<class T>
Vector<T>::Vector(const Vector<T> &vec){
    this->x_coord = vec.get_x();
    this->y_coord = vec.get_y();
}

// Destructor
template<class T>
Vector<T>::~Vector(){}

// Getters
template<class T>
T Vector<T>::get_x() const{
    return x_coord;
}

template<class T>
T Vector<T>::get_y() const{
    return y_coord;
}

template<class T>
T Vector<T>::get_z() const{
    return z_coord;
}

template<class T>
T Vector<T>::get_norm() const{
    return sqrt(x_coord * x_coord + y_coord * y_coord + z_coord * z_coord);
}

template<class T>
std::string Vector<T>::coords_to_string(){
    std::ostringstream oss;
    oss << "(" + std::to_string(x_coord) + ", " + std::to_string(y_coord) + ", " + std::to_string(z_coord) + ")";
    return oss.str();
}

// Imprimir coordenadas
template<class T>
void Vector<T>::print_coords(){
    std::cout << "(x, y, z) = " << "(" << x_coord << ", " << y_coord << ", " << z_coord << ")" << std::endl;
}

//  Normalizar
template<class T>
void Vector<T>::normalize(){
    T norm = this->get_norm();
    x_coord = x_coord / norm;
    y_coord = y_coord / norm;
    z_coord = z_coord / norm;
}


// Operadores
template<class T>
Vector<T> Vector<T>::operator+(T value) {
    return Vector<T>(this->x_coord + value, this->y_coord + value, this->z_coord + value);
}

template<class T>
Vector<T> Vector<T>::operator-(T value) {
    return Vector<T>(this->x_coord - value, this->y_coord - value, this->z_coord - value);
}

template<class T>
Vector<T> Vector<T>::operator*(T value) {
    return Vector<T>(this->x_coord * value, this->y_coord * value, this->z_coord * value);
}

template<class T>
Vector<T> Vector<T>::operator/(T value) {
    return Vector<T>(this->x_coord / value, this->y_coord / value, this->z_coord / value);
}

template<class T>
Vector<T> Vector<T>::operator+(Vector<T> &vec){
    return Vector<T>(this->x_coord + vec.x_coord, this->y_coord + vec.y_coord, this->z_coord + vec.z_coord);
}

template<class T>
Vector<T> Vector<T>::operator-(Vector<T> &vec){
    return Vector<T>(this->x_coord - vec.x_coord, this->y_coord - vec.y_coord, this->z_coord - vec.z_coord);
}

template<class T>
T Vector<T>::dot(Vector<T> &vec) {
    return this->x_coord * vec.get_x() + this->y_coord * vec.get_y() + this->z_coord * vec.get_z();
}

template<class T>
Vector<T> Vector<T>::cross(Vector<T> &vec) {
    T x = this->y_coord * vec.get_z() - this->z_coord * vec.get_y();
    T y = this->z_coord * vec.get_x() - this->x_coord * vec.get_z();
    T z = this->x_coord * vec.get_y() - this->y_coord * vec.get_x();
    return Vector<T>(x, y, z);
}


#endif // VECTOR_H
