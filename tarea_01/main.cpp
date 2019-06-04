#include <iostream>
#include <vector>

#include <Point.h>
#include <Vector.h>
#include <Segment.h>
#include <Polygon.h>

using namespace std;

int main()
{
    /* Pruebas para Point */
    cout << "-----------------" << endl;
    cout << "Point" << endl;
    cout << "-----------------" << endl;

    // int
    Point<int> p1 = Point<int>(3, 2);
    cout << "int" << endl;
    cout << "p1 = " << p1.coords_to_string() << endl;
    Point<int> p1_2 = p1 + 2;
    cout << "p1 + 2 = " << p1_2.coords_to_string() << endl;
    p1_2 = p1 * 5;
    cout << "p1 * 5 = " << p1_2.coords_to_string() << endl;
    p1_2 = p1 / 2;
    cout << "p1 / 2 = " << p1_2.coords_to_string() << endl;

    // float
    cout << endl;
    cout << "float" << endl;
    Point<float> p2 = Point<float>(3.0, 2.0);
    Point<float> p3 = Point<float>(4.56, 5.93);
    cout << "p2 = " << p2.coords_to_string() << endl;
    cout << "p3 = " << p3.coords_to_string() << endl;
    Point<float> p4 = p2 / 2;
    cout << "p2 / 2 = " << p4.coords_to_string() << endl;
    p4 = p2 + p3;
    cout << "p2 + p3 = " << p4.coords_to_string() << endl;
    p4 = p2 * p3;
    cout << "p2 * p3 = " << p4.coords_to_string() << endl;


    /* Pruebas para Vector */
    cout << endl;
    cout << endl;
    cout << "-----------------" << endl;
    cout << "Vector" << endl;
    cout << "-----------------" << endl;

    // int
    cout << "int" << endl;
    Vector<int> v0 = Vector<int>(3, 4, 5);
    Vector<int> v0_1 = v0 / 2;
    cout << "v0 = " << v0.coords_to_string() << endl;
    cout << "v0 / 2 = " << v0_1.coords_to_string() << endl;

    // float
    cout << endl;
    cout << "float" << endl;
    Vector<float> v1 = Vector<float>(4.5, 6.2, 7.8);
    cout << "v1 = " << v1.coords_to_string() << endl;
    Vector<float> v2 = Vector<float>(p3);
    cout << "v2 = Vector(p3) = " << v2.coords_to_string() << endl;
    Vector<float> v3 = Vector<float>(p2, p3);
    cout << "v3 = Vector(p2, p3) = " << v3.coords_to_string() << endl;
    Vector<float> v4 = v1 + v2;
    cout << "v1 + v2 = " << v4.coords_to_string() << endl;
    v4 = v1 - v2;
    cout << "v1 - v2 = " << v4.coords_to_string() << endl;
    float dot_prod = v1.dot(v2);
    cout << "v1.dot(v2) = " << dot_prod << endl;
    v4 = Vector<float>(1.0, 0.0, 0.0);
    cout << "v4 = " << v4.coords_to_string() << endl;
    Vector<float> v5 = Vector<float>(0.0, 1.0, 0.0);
    cout << "v5 = " << v5.coords_to_string() << endl;
    Vector<float> v6 = v4.cross(v5);
    cout << "v4.cross(v5) = " << v6.coords_to_string() << endl;
    v6 = Vector<float>(1.0, 1.0, 1.0);
    cout << "v6 = " << v6.coords_to_string() << endl;
    cout << "v6.get_norm() = " << v6.get_norm() << endl;
    v6.normalize();
    cout << "v6.normalize() = " << v6.coords_to_string() << endl;


    /* Pruebas para Segment */
    cout << endl;
    cout << endl;
    cout << "-----------------" << endl;
    cout << "Segment" << endl;
    cout << "-----------------" << endl;

    // float
    cout << "float" << endl;
    p4 = Point<float>(0.0, 0.0);
    cout << "p4 = " << p4.coords_to_string() << endl;
    Point<float> p5 = Point<float>(1.0, 0.0);
    cout << "p5 = " << p5.coords_to_string() << endl;
    Segment<float> s1 = Segment<float>(p4, p5);
    cout << "s1 = Segment(p4, p5) = " << s1.points_to_string() << endl;
    cout << "s1.get_length() = " << s1.get_length() << endl;
    Point<float> p6 = Point<float>(2.0, 0.5);
    cout << "p6 = " << p6.coords_to_string() << endl;
    cout << "s1.isLeft(p6) = " << s1.isLeft(p6) << endl;


    /* Pruebas para Polygon */
    cout << endl;
    cout << endl;
    cout << "-----------------" << endl;
    cout << "Polygon" << endl;
    cout << "-----------------" << endl;
    cout << endl;
    cout << "Ejemplo 1" << endl;
    cout << endl;

    Point<float> p7  = Point<float>(0.0, 0.0);
    Point<float> p8  = Point<float>(1.0, 0.0);
    Point<float> p9  = Point<float>(1.0, 1.0);
    Point<float> p10 = Point<float>(0.0, 1.0);
    cout << "p7 = "  << p7.coords_to_string()  << endl;
    cout << "p8 = "  << p8.coords_to_string()  << endl;
    cout << "p8 = "  << p8.coords_to_string()  << endl;
    cout << "p9 = "  << p9.coords_to_string()  << endl;
    cout << "p10 = " << p10.coords_to_string() << endl;

    vector<Point<float>> points;
    points.push_back(p7);
    points.push_back(p8);
    points.push_back(p9);
    points.push_back(p10);
    Polygon<float> polygon = Polygon<float>(points);
    cout << "polygon = Polygon(p7, p8, p9, p10)" << endl;
    cout << "polygon.get_area() = " << polygon.get_area() << endl;
    cout << "polygon.is_in_ccw() = " << polygon.is_in_ccw() << endl;

    cout << endl;
    cout << "Ejemplo 2" << endl;
    cout << endl;

    Point<float> p11 = Point<float>(1.0, 0.0);
    Point<float> p12 = Point<float>(1.0, 5.0);
    Point<float> p13 = Point<float>(4.0, 5.0);
    Point<float> p14 = Point<float>(6.0, 4.0);
    Point<float> p15 = Point<float>(5.0, 0.0);
    cout << "p11 = " << p11.coords_to_string() << endl;
    cout << "p12 = " << p12.coords_to_string() << endl;
    cout << "p13 = " << p13.coords_to_string() << endl;
    cout << "p14 = " << p14.coords_to_string() << endl;
    cout << "p15 = " << p15.coords_to_string() << endl;

    points.clear();
    points.push_back(p11);
    points.push_back(p12);
    points.push_back(p13);
    points.push_back(p14);
    points.push_back(p15);
    polygon = Polygon<float>(points);
    cout << "polygon = Polygon(p11, p12, p13, p14, p15)" << endl;
    cout << "polygon.get_area() = " << polygon.get_area() << endl;
    cout << "polygon.is_in_ccw() = " << polygon.is_in_ccw() << endl;
    cout << "polygon.contains(p6) = " << polygon.contains_point(p6) << endl;
    cout << "polygon.contains(p7) = " << polygon.contains_point(p7) << endl;
    cout << "polygon.contains(p11) = " << polygon.contains_point(p11) << endl;

    return 0;
}
