#include <stdio.h>
#include <math.h>

#include "square_solve.h"

char SolveSquare (double a, double b, double c, double *x1, double *x2){
    is_error (isfinite (a));
    is_error (isfinite (b));
    is_error (isfinite (c));
    is_error (x1 != NULL);
    is_error (x2 != NULL);
    is_error (x1 != x2);

    char type_equation = get_Type (a, b, c);
    switch (type_equation){
        case INF_ROOTS:
            return INF_ROOTS;

        case SQUARE:
            return _square_equation (a, b, c, x1, x2);

        case ONE_ROOT:
        {   
            _liner_equation (b, c, x1);
            *x2 = *x1;
            return 1;
        }
        
        case NO_ROOTS:
            return NO_ROOTS;

        default:
            return ANOTHER;
    }
}

char get_Type (double a, double b, double c){
    is_error (isfinite (a));
    is_error (isfinite (b));
    is_error (isfinite (c));

    if (IsZero (a))
        if (IsZero (b))
            if (IsZero (c))
                return INF_ROOTS;
            else
                return NO_ROOTS;
        else
            return ONE_ROOT;
    else
        return SQUARE;

    return ANOTHER;
}

static char _square_equation (double a, double b, double c, double *x1, double *x2){
    is_error (isfinite (a));
    is_error (isfinite (b));
    is_error (isfinite (c));
    is_error (x1 != NULL);
    is_error (x2 != NULL);
    is_error (!IsZero (a));

    if (IsZero (b)){
        if (IsZero (c)){
            *x1 = 0.0;
            return ONE_ROOT;
        }

        if (c * a > 0)
            return NO_ROOTS;

        if (c * a < 0){
            *x1 = -sqrt (-c / a);
            *x2 =  sqrt (-c / a);
            return SQUARE;
        }
    }

    if (IsZero (c)){
        if (b < 0){
            *x1 = 0.0;
            *x2 =  -b;
            return SQUARE;
        }

        if (b > 0){
            *x1 =  -b;
            *x2 = 0.0;
            return SQUARE;
        }
    }

    double D = Discriminant (a, b, c);

    double a2 = a * 2;

    if (IsZero (D)){
        *x1 = -b / a2;
        return ONE_ROOT;
    }

    if (D < 0.0)
        return NO_ROOTS;

    double sqrt_D = sqrt (D);

    if (D > 0.0){
        *x1 = (-b - sqrt_D) / a2;
        *x2 = (-b + sqrt_D) / a2;
        return SQUARE;
    }

    return ANOTHER;
}

double Discriminant (double a, double b, double c){
    is_error (isfinite (a));
    is_error (isfinite (b));
    is_error (isfinite (c));

    return b*b - 4*a*c;
}

static char _liner_equation (double a, double b, double *x){
    is_error (isfinite (a));
    is_error (isfinite (a));
    is_error (x != NULL);
    is_error (!IsZero (a));

    *x = -b / a;

    return ONE_ROOT;
}

bool read_arguments (double *a, double *b, double *c){
    is_error (a != NULL);
    is_error (b != NULL);
    is_error (c != NULL);

    if (scanf ("%lg%lg%lg", a, b, c) != 3){
        printf ("Invalid value entry\n");
        return false;
    }

    char ch = 0;
    while ((ch = (char)getchar()) != '\n' && ch != EOF){
        if (ch == ' ' || ch == '\t')
            continue;
        else{
            printf ("Too many values\n");
            return false;
        }

    }

    return true;
}

void write_result (char count_roots, double x1, double x2){
    switch (count_roots){
        case INF_ROOTS:
            printf ("Equation has an infinite number of solutions\n");
            break;

        case SQUARE:
            x1 = FixZero (x1);
            x2 = FixZero (x2);

            printf ("Equation has two different solutions\n");
            printf ("x1 = %lg\nx2 = %lg\n", x1, x2);
            break;

        case ONE_ROOT:
            printf ("Equation has exactly one solution\n");

            x1 = FixZero (x1);

            printf ("x = %lg\n", x1);
            break;

        case NO_ROOTS:
            printf ("Equation has no solution\n");
            break;

        case ANOTHER: [[fallthrough]]
        default:
            printf ("ERROR\n");
            break;
    }

    return;
}
