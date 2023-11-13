#include "Bureaucrat.hpp"
#include "Form.hpp"

int main( void )
{

    try {
        Bureaucrat bureaucrat("ash",11);
        Form form("formName", 10, 10);

        bureaucrat.signForm(form);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}