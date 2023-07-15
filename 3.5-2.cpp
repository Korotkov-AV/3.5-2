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
    int A;
    int B;
    int C;

    Triangle(int a, int b, int c, int A, int B, int C) {
        name = "Треугольник: ";
       this-> a = a;
       this->b = b;
       this->c = c;
       this->A = A;
       this->B = B;
       this->C = C;
    }

    virtual void print() {
        std::cout << name << "\nСтороны: a=" << a << " b=" << b << " c=" << c;
        std::cout << "\nУглы: A=" << A << " B=" << B << " C=" << C << "\n\n";
    }
};

class Triangle_p : public Triangle {
public:
    
    Triangle_p(int a, int b, int c, int A) : Triangle(a,b,c,A,90,90-A) {
        name = "Прямоугольный треугольник: ";
        //B = 90;
        //C = 180 - (A+B);
    }
};

class Triangle_rb : public Triangle {
public:

    Triangle_rb (int b, int c, int A) : Triangle(b,b,c, A, A, 180 - 2*A) {
        name = "Равнобедренный треугольник: ";
        //a = b;
        //C = B;
        //A = 180 - C * 2;
    }
};

class Triangle_rs : public Triangle {
public:

    Triangle_rs (int b) : Triangle(b, b, b, 60, 60, 60) {
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
    int d;
    int D;
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) : Triangle(a, b, c, A, B, C) {
        name = "Четырёхугольник: ";
        //a = 10;
        //b = 20;
        //c = 30;
        this->d=d;
        //A = 40;
        //B = 30;
        //C = 110;
        this->D=D;
    }
   
    virtual void print() {
        std::cout << name << "\nСтороны: a=" << a << " b=" << b << " c=" << c << " d=" << d;
        std::cout << "\nУглы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n\n";
    }
};
class Quadrangle_p : public Quadrangle {
public:
    Quadrangle_p(int a, int b, int A, int B) : Quadrangle(a, b, a, b, A, B, A, B){
        name = "Параллелограмм: ";
        //a = c;
        //b = d;
        //C = A;
        //D = B;
    }
};
class Quadrangle_r : public Quadrangle_p {
public:
    Quadrangle_r(int a, int A, int B) : Quadrangle_p(a, a, A, B) {
        name = "Ромб: ";
        //b = a;
        //d = a;
    }
};
class Quadrangle_par : public Quadrangle_p {
public:
    Quadrangle_par(int a, int b ) : Quadrangle_p(a, b, 90, 90) {
        name = "Прямоугольник: ";
        //A=B=C=D =90 ;
    }
};
class Quadrangle_kv : public Quadrangle_par {
public:
    Quadrangle_kv(int a) : Quadrangle_par(a, a) {
        name = "Квадрат: ";
        //b = d = a;
    }
};

void print_info(Triangle* p) {
    p->print();
}


int main()
{
    setlocale(LC_ALL, "Russian");

    Triangle t(10, 20,30, 40, 30,110);
  /*  t.print();*/
    Triangle* t1 = &t;
    print_info(t1);
    
    Triangle_p t_p(10, 20, 30, 40);
    //t_p.print();
    Triangle* t_p1 = &t_p;
    print_info(t_p1);
    
    Triangle_rb rb(20, 30, 40);
    //rb.print();
    Triangle* rb1 = &rb;
    print_info(rb1);

    Triangle_rs rs(40);
   // rs.print();
    Triangle* rs1 = &rs;
    print_info(rs1);


    Quadrangle q(10, 20, 30, 40, 40, 30, 110, 12);
    //q.print();
    Triangle* q1 = &q;
    print_info(q1);

    Quadrangle_p p(20, 30, 30, 110);
    //p.print();
    Triangle* p1 = &p;
    print_info(p1);


    Quadrangle_r r(30, 30, 110);
    //r.print();
    Triangle* r1 = &r;
    print_info(r1);

    Quadrangle_par par(30, 50);
    //par.print();
    Triangle* par1 = &par;
    print_info(par1);

    Quadrangle_kv kv(50);
    //kv.print();
    Triangle* kv1 = &kv;
    print_info(kv1);


    std::cout << "Конец файла!\n";
    return 0;
}