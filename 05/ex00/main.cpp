#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        Bureaucrat b("Boi", 1);
        try
        {
            b.decrementGrade();
        }
        catch (std::exception & e)
        {
            std::cout << e.what() << std::endl;
        }
        std::cout << b << std::endl;
    }
    catch (std::exception & e)
    {
        std::cout << "Grade out of range " << e.what() << std::endl;
        return (0);
    }
    
    return (0);
}