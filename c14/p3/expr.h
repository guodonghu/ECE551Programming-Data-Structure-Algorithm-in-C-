#ifndef __EXPR_H__
#define __EXPR_H__

#include<iostream>
#include<sstream>
#include<string>

class Expression {
public:
  Expression() {}
  virtual std::string toString() const = 0;
  virtual std::string getexp() const = 0;
  virtual ~Expression() {}
};

class NumExpression : public Expression {
private: 
  long num;
public:
  NumExpression(long n): num(n) {}
  virtual std::string toString() const {
    std::stringstream s;
    s << num;
    std::string str;
    str = s.str();
    return str;
  }
  virtual std::string getexp() const {
    std::stringstream s;
    s<<num;
    std::string str;
    str = s.str();
    return str;
  }
};

class OpExpression : public Expression{
protected:
  std::string lhs;
  std::string rhs;
  char op;
public:
  OpExpression(Expression *lhs, Expression *rhs) : lhs(lhs->getexp()), rhs(rhs->getexp()) {
    delete lhs;
    delete rhs;
  }

  virtual std::string toString() const {
    std::stringstream s;
    s << "(";
    s << lhs;
    s << " ";
    s << op;
    s << " ";
    s << rhs;
    s << ")";
    std::string str = s.str();  
    return str;
  }
  
  virtual std::string getexp() const {
    return toString();
  }
};

class PlusExpression : public OpExpression {  
public:
  PlusExpression(Expression *lhs, Expression *rhs) : OpExpression(lhs, rhs) { 
    op = '+';
  }   
};

class MinusExpression : public OpExpression {  
public:
  MinusExpression(Expression *lhs, Expression *rhs) : OpExpression(lhs, rhs) { 
    op = '-';
  }   
};

class TimesExpression : public OpExpression {  
public:
  TimesExpression(Expression *lhs, Expression *rhs) : OpExpression(lhs, rhs) { 
    op = '*';
  }   
};

class DivExpression : public OpExpression {  
public:
  DivExpression(Expression *lhs, Expression *rhs) : OpExpression(lhs, rhs) { 
    op = '/';
  }   
};

    
#endif
