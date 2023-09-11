#ifndef _SQUARE_H_
#define _SQUARE_H_

#include "../generals_func/generals.h"
#include "../log_info/log_errors.h"

/**
    \enum State
    \brief Represents the number of roots of the equation
*/
enum State {
    INF_ROOTS =  -1,    ///< The equation has an infinite number of solutions
    NO_ROOTS  =   0,    ///< The equation has no solutions
    ONE_ROOT  =   1,    ///< The equation has a maximum of one solutions
    SQUARE    =   2,    ///< The equation has a maximum of two solutions
    ANOTHER   =   3     ///< Another case
};

/** \brief Solution of the original equation
    \version 1.0.0
    \note The function returns one of the enum state's values
    \param [in] a input parameters of equation
    \param [in] b input parameters of equation
    \param [in] c input parameters of equation
    \param [out] x1 pointer of first equation root
    \param [out] x2 pointer of second equation root
    \return Number of solutions to the original equation
*/
char SolveSquare (double a, double b, double c, double *x1, double *x2);

/** \brief Determines the type of equation
    \version 1.0.0
    \note The function returns one of the enum state's values
    \param [in] a input parameters of equation
    \param [in] b input parameters of equation
    \param [in] c input parameters of equation
    \return Type of equation
*/
char get_Type (double a, double b, double c);

/** \brief Finding the discriminant of second degree equation
    \version 1.0.0
    \param [in] a input parameters of equation
    \param [in] b input parameters of equation
    \param [in] c input parameters of equation
    \return Value of discriminant
*/
double Discriminant (double a, double b, double c);

/** \brief Solution of a second degree equation
    \version 1.0.0
    \note The function returns one of the enum state's values
    \param [in] a input parameters of equation
    \param [in] b input parameters of equation
    \param [in] c input parameters of equation
    \param [out] x1 pointer of first equation root
    \param [out] x2 pointer of second equation root
    \return Number of roots
    \note if D = 0, x1 is assigned the value of the root, x2 does not change
    \note if D < 0, x1 and x2 do not change
    \note if D > 0, x1 and x2 are assigned the value of the root
    \code
        if (is_zero(D)){
            *x1 = -b / (2*a);
            return ONE_ROOT;
        }

        if(D < 0.0)
            return NO_ROOT;

        D = sqrt(D);
        a *= 2;

        if (D > 0.0){
            *x1 = (-b + D) / a;
            *x2 = (-b - D) / a;
            return SQUARE;
        }
    \endcode
*/
static char _square_equation (double a, double b, double c, double *x1, double *x2);

/** \brief Solution of a linear equation
    \note The function finds the root when the parameter a is zero
    \version 1.0.0
    \note The function returns one of the enum state's values
    \param [in] a input parameters of equation
    \param [in] b input parameters of equation
    \param [out] x pointer of equation root
    \return Number of roots
*/
static char _liner_equation (double a, double b, double *x);

/** \brief Reading input parameters
    \version 1.1.0
    \note The function returns one of the enum state's values
    \param [in] a input parameters of equation
    \param [in] b input parameters of equation
    \param [in] c input parameters of equation
    \return False - data entered incorrectly, True - data entered correctly
*/
bool read_arguments (double *a, double *b, double *c);

/** \brief Output of the number of roots and their values
    \version 1.1.0
    \param [in] count_roots number of roots of the equation
    \param [in] x1 value of second equation root
    \param [in] x2 value of equation
*/
void write_result (char count_roots, double x1, double x2);

#endif
