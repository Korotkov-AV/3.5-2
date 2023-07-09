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
    Triangle() {
        name = "Треугольник: ";
        a = 10;
        b = 20;
        c = 30;
        A = 40;
        B = 30;
        C = 110;
    }

    void print() {
        std::cout << name << "\nСтороны: a=" << a << " b=" << b << " c=" << c;
        std::cout << "\nУглы: A=" << A << " B=" << B << " C=" << C << "\n\n";
    }
};

class Triangle_p : public Triangle {
public:
    
    Triangle_p() {
        name = "Прямоугольный треугольник: ";
        B = 90;
        C = 180 - (A+B);
    }
};

class Triangle_rb : public Triangle {
public:

    Triangle_rb() {
        name = "Равнобедренный треугольник: ";
        a = b;
        C = B;
        A = 180 - C * 2;
    }
};

class Triangle_rs : public Triangle {
public:

    Triangle_rs() {
        name = "Равносторонний треугольник: ";
        a = c;
        b = c;
        A = 60;
        B = A;
        C = A;
    }
};
class Quadrangle : public Triangle {
public:
    Quadrangle() {
        name = "Четырёхугольник: ";
        a = 10;
        b = 20;
        c = 30;
        d = 40;
        A = 40;
        B = 30;
        C = 110;
        D = 12;
    }
   
    void print() {
        std::cout << name << "\nСтороны: a=" << a << " b=" << b << " c=" << c << " d=" << d;
        std::cout << "\nУглы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n\n";
    }
};
class Quadrangle_p : public Quadrangle {
public:
    Quadrangle_p() {
        name = "Параллелограмм: ";
        a = c;
        b = d;
        //c = 30;
        //d = 40;
        //A = 40;
        //B = 30;
        C = A;
        D = B;
    }
};
class Quadrangle_r : public Quadrangle_p {
public:
    Quadrangle_r() {
        name = "Ромб: ";
        //a = c;
        b = a;
        d = a;
        //C = A;
        //D = B;
    }
};
class Quadrangle_par : public Quadrangle_p {
public:
    Quadrangle_par() {
        name = "Прямоугольник: ";
        A=B=C=D =90 ;
    }
};
class Quadrangle_kv : public Quadrangle_par {
public:
    Quadrangle_kv() {
        name = "Квадрат: ";
        b = d = a;
    }
};


int main()
{
    setlocale(LC_ALL, "Russian");

    Triangle t;
    t.print();
    
    Triangle_p t_p;
    t_p.print();
    
    Triangle_rb rb;
    rb.print();
    
    Triangle_rs rs;
    rs.print();


    Quadrangle q;
    q.print();

    Quadrangle_p p;
    p.print();

    Quadrangle_r r;
    r.print();

    Quadrangle_par par;
    par.print();

    Quadrangle_kv kv;
    kv.print();

    std::cout << "Конец файла!\n";
    return 0;
}