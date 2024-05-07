#include "quadratic_equation.h"


int solve_equation(double a, double b, double c, double *root1, double *root2) {
if (a == 0) 
{
        if (b == 0) 
        {
            // Случай, когда a == 0 и b == 0
            if (c == 0) 
            {
                // Уравнение 0 = 0 имеет бесконечно много решений
                return -1; // Взял -1 для обозначения бесконечного числа решений
            } 
            else 
            {
                // Уравнение c = 0, где c != 0, не имеет решений
                return 0;
            }
        } 
        else 
        {
            // Линейное уравнение bx + c = 0
            *root1 = -c / b;
            *root2 = 0; // Второй корень не используется
            return 1;
        }
    }
    else 
    {
        double discriminant = b * b - 4 * a * c;
        
        if (discriminant > 0) 
        {
            *root1 = (-b + sqrt(discriminant)) / (2 * a);
            *root2 = (-b - sqrt(discriminant)) / (2 * a);
            return 2;
        } 
        else if (discriminant == 0) 
        {
            *root1 = -b / (2 * a);
            return 1;
        } 
        else 
        {
            // Не реализовал комплексные корни т.к. в задании про них не написано
            // Но если надо то и их можно реализовать
            *root1 = 0;
            *root2 = 0; // Значения для обозначения отсутствия действительных корней
            return 0;
        }
    }
}