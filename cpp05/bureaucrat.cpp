//
// Created by sramis-c on 8/14/24.
//

#include "bureaucrat.h"

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade too high\n");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade too low\n");
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    if (grade < 0)
      throw GradeTooHighException();
    else if (grade > 150)
      throw GradeTooLowException();
    else
      this->_grade = grade;
}

Bureaucrat::~Bureaucrat(){}

//Methods
void           Bureaucrat::incrementGrade()
{
  this->_grade--;
  if (this->_grade < 0)
    throw GradeTooHighException();
}
void           Bureaucrat::decrementGrade()
{
  this->_grade++;
  if (this->_grade > 150)
    throw GradeTooLowException();
}

//Getters
std::string    Bureaucrat::getName() const
{
  return (this->_name);
}
int            Bureaucrat::getGrade() const
{
  return (this->_grade);
}

//Setters
void           Bureaucrat::setName(std::string name)
{
  this->_name = name;
}
void           Bureaucrat::setGrade(int grade)
{
  this->_grade = grade;
}

//Overloads
std::ostream& operator<<(std::ostream& os, const Bureaucrat& rhs)
{
  os << rhs.getName() << ", bureaucrat grade" << rhs.getGrade();
  return(os);
}