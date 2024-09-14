#include <stdio.h>
#include <math.h>

double pi = 3.14159265358979323846; //global definition of pi
double npi = -3.14159265358979323846; //global definition of negative pi

//factorial
unsigned int fact(unsigned int x) {
    int f = 1, i = 1;

    while (i <= x) {
        f *= i;
        i++;
    }
    return f;
}


//sine
double sn(double x, int n) {
    double sum = 0;
    double a = 0;
    int sign[4] = {0, 1, 0, -1};
    int der = 0;
    //quadrant adjustment
    while (x > pi) {
        x -= pi;
    }
    while (x < npi) {
        x += pi;
    }
    for (int i = 0; i < n; i++) {
        der = i;
        while (der > 3) {
            der -= 4;
        }
        sum += sign[der] * pow(x,i) / fact(i);
    }
    return sum;
}


//cosine
double cn(double x, int n) {
    double sum = 0;
    double a = 0;
    int sign[4] = {1, 0, -1, 0};
    int der = 0;
    //quadrant adjustment
    while (x > pi) {
        x -= pi;
    }
    while (x < npi) {
        x += pi;
    }
    for (int i = 0; i < n; i++) {
        der = i;
        while (der > 3) {
            der -= 4;
        }
        sum += sign[der] * pow(x,i) / fact(i);
    }
    return sum;
}


int main() {

    int x = 0;
    int factorial = 0;
    double sin = 0;
    double cos = 0;
    double tan = 0;
    double csc = 0;
    double sec = 0;
    double cot = 0;
    int term = 0;
    int selection = 0;

    printf("\nFor pi use 3.14159265358979323846\n");
    printf("Operator selection:\n1(factorial)\n2(sine)\n3(cosine)\n4(tangent)\n5(cosecant)\n6(secant)\n7(cotangent)\n");
    scanf("%d", &selection);
    //factorial
    if (selection == 1) {
        printf("x! for x = (input)\n");
        scanf("%d", &x);
        factorial = fact(x);
        printf("x! = %d", factorial);
    }
    //sine
    if (selection == 2) {
        printf("Sin(x) for x = (input)\n");
        scanf("%lf", &sin);
        printf("Number of terms:\n");
        scanf("%d", &term);
        sin = sn(sin,term);
        //error check
        if (sin > 1 || sin < -1) {
            printf("ERROR");
            return 1;
        }
        printf("Sin(x) = \n%.5lf", sin);
        return 0;
    }
    //cosine
    if (selection == 3) {
        printf("Cos(x) for x = (input)\n");
        scanf("%lf", &cos);
        printf("Number of terms:\n");
        scanf("%d", &term);
        cos = cn(cos,term);
        //error check
        if (sin > 1 || sin < -1) {
            printf("ERROR");
            return 1;
        }
        printf("Cos(x) = \n%.5lf", cos);
        return 0;
    }
    //tangent
    if (selection == 4) {
        printf("\n*NOTICE: Tan(pi/2) is undefined*\nTan(x) for x = (input)\n");
        scanf("%lf", &tan);
        //quadrant adjustment
        while (x > pi) {
            x -= pi;
        }
        while (x < npi) {
            x += pi;
        }
        //error for tan(pi/2)
        if (tan == pi/2 || tan == -pi/2) {
            printf("ERROR: Tan(pi/2) is undefined");
            return 1;
        }
        printf("Number of terms:\n");
        scanf("%d", &term);
        tan = sn(tan,term) / cn(tan,term);
        printf("Tan(x) = \n%.5lf", tan);
        return 0;
    }
    //cosecant
    if (selection == 5) {
        printf("\n*NOTICE: Csc(pi) is undefined*\nCsc(x) for x = (input)\n");
        scanf("%lf", &csc);
        //quadrant adjustment
        while (x > pi) {
            x -= pi;
        }
        while (x < npi) {
            x += pi;
        }
        //error for csc(pi/2)
        if (csc == pi || csc == npi) {
            printf("ERROR: Csc(pi) is undefined");
            return 1;
        }
        printf("Number of terms:\n");
        scanf("%d", &term);
        csc = 1 / sn(csc,term);
        printf("Csc(x) = \n%.5lf", csc);
        return 0;
    }
    //secant
    if (selection == 6) {
        printf("\n*NOTICE: Sec(pi/2) is undefined*\nSec(x) for x = (input)\n");
        scanf("%lf", &sec);
        //quadrant adjustment
        while (x > pi) {
            x -= pi;
        }
        while (x < npi) {
            x += pi;
        }
        //error for sec(pi)
        if (sec == pi/2 || sec == npi/2) {
            printf("ERROR: Csc(pi) is undefined");
            return 1;
        }
        printf("Number of terms:\n");
        scanf("%d", &term);
        sec = 1 / cn(sec,term);
        printf("Sec(x) = \n%.5lf", sec);
        return 0;
    }
    //cotangent
    if (selection == 7) {
        printf("\n*NOTICE: Cot(0) and Cot(pi) are undefined*\nCot(x) for x = (input)\n");
        scanf("%lf", &cot);
        //quadrant adjustment
        while (x > pi) {
            x -= pi;
        }
        while (x < npi) {
            x += pi;
        }
        //error for cot(0) and cot(pi)
        if (cot == 0 || cot == pi || cot == npi) {
            printf("ERROR: Cot(0) and Cot(2pi) are undefined");
            return 1;
        }
        printf("Number of terms:\n");
        scanf("%d", &term);
        cot = cn(cot,term) / sn(cot,term);
        printf("Cot(x) = \n%.5lf", cot);
        return 0;
    }


    return 0;     
}
