// 3.5-2.cpp 
//
#include <iostream>
#include <Windows.h>
class Triangle {
public:
    std::string name;
    int a;
    int b;
    int c;
    int d;
    int A;
    int B;
    int C;
    int D;
    Triangle(int a1, int b1, int c1, int A1, int B1, int C1) {
        name = "Треугольник: ";
        a = a1;
        b = b1;
        c = c1;
        A = A1;
        B = B1;
        C = C1;
    }

    void print() {
        std::cout << name << "\nСтороны: a=" << a << " b=" << b << " c=" << c;
        std::cout << "\nУглы: A=" << A << " B=" << B << " C=" << C << "\n\n";
    }
};

class Triangle_p : public Triangle {
public:
    
    Triangle_p(int a1, int b1, int c1, int A1) : Triangle(a1,b1,c1,A1,90,90-A1) {
        name = "Прямоугольный треугольник: ";
        //B = 90;
        //C = 180 - (A+B);
    }
};

class Triangle_rb : public Triangle {
public:

    Triangle_rb (int b1, int c1, int A1) : Triangle(b1,b1,c1, A1, A1, 180 - 2*A1) {
        name = "Равнобедренный треугольник: ";
        //a = b1;
        //C = B;
        //A = 180 - C * 2;
    }
};

class Triangle_rs : public Triangle {
public:

    Triangle_rs (int b1) : Triangle(b1, b1, b1, 60, 60, 60) {
        name = "Равносторонний треугольник: ";
        //a = c;
        //b = c;
        //A = 60;
        //B = A;
        //C = A;
    }
};
class Quadrangle : public Triangle {
public:
    Quadrangle(int a1, int b1, int c1, int d1, int A1, int B1, int C1, int D1) : Triangle(a1, b1, c1, A1, B1, C1) {
        name = "Четырёхугольник: ";
        //a = 10;
        //b = 20;
        //c = 30;
        d = 40;
        //A = 40;
        //B = 30;
        //C = 110;
        D = 12;
    }
   
    void print() {
        std::cout << name << "\nСтороны: a=" << a << " b=" << b << " c=" << c << " d=" << d;
        std::cout << "\nУглы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n\n";
    }
};
class Quadrangle_p : public Quadrangle {
public:
    Quadrangle_p(int a1, int b1, int A1, int B1) : Quadrangle(a1, b1, a1, b1, A1, B1, A1, B1){
        name = "Параллелограмм: ";
        //a = c;
        //b = d;
        //C = A;
        //D = B;
    }
};
class Quadrangle_r : public Quadrangle_p {
public:
    Quadrangle_r(int a1, int A1, int B1) : Quadrangle_p(a1, a1, A1, B1) {
        name = "Ромб: ";
        //b = a;
        //d = a;
    }
};
class Quadrangle_par : public Quadrangle_p {
public:
    Quadrangle_par(int a1, int b1 ) : Quadrangle_p(a1, b1, 90, 90) {
        name = "Прямоугольник: ";
        //A=B=C=D =90 ;
    }
};
class Quadrangle_kv : public Quadrangle_par {
public:
    Quadrangle_kv(int a1) : Quadrangle_par(a1, a1) {
        name = "Квадрат: ";
        //b = d = a;
    }
};


int main()
{
    setlocale(LC_ALL, "Russian");

    Triangle t(10, 20,30, 40, 30,110);
    t.print();
    
    Triangle_p t_p(10, 20, 30, 40);
    t_p.print();
    
    Triangle_rb rb(20, 30, 40);
    rb.print();
    
    Triangle_rs rs(40);
    rs.print();


    Quadrangle q(10, 20, 30, 40, 40, 30, 110, 12);
    q.print();

    Quadrangle_p p(20, 30, 30, 110);
    p.print();

    Quadrangle_r r(30, 30, 110);
    r.print();

    Quadrangle_par par(30, 50);
    par.print();

    Quadrangle_kv kv(50);
    kv.print();

    std::cout << "Конец файла!\n";
    return 0;
}