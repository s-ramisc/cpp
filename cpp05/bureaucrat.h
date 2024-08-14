//
// Created by sramis-c on 8/14/24.
//

#ifndef BUREAUCRAT_H
#define BUREAUCRAT_H
#include <string>
#include <iostream>
#include <stdexcept>


class Bureaucrat
{
    public:
      class GradeTooHighException : public std::exception
      {
        virtual const char* what() const throw();
      };

      class GradeTooLowException : public std::exception
      {
        virtual const char *what() const throw();
      };

      Bureaucrat(std::string name, int grade);
      ~Bureaucrat();

      //Methods
      void         incrementGrade();
      void         decrementGrade();

      //Getters
      std::string  getName() const;
      int          getGrade() const;

      //Setters
      void         setName(std::string name);
      void         setGrade(int grade);

    private:
      std::string          _name;
      int                  _grade;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs);


#endif //BUREAUCRAT_H
