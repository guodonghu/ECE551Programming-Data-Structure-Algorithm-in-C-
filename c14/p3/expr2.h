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

class PlusExpression : public Expression {
private:
  std::string lhs;
  std::string rhs;
  char op;
public:
  PlusExpression(Expression *lhs, Expression *rhs) : lhs(lhs->getexp()), rhs(rhs->getexp()), op('+') {}
  
  virtual std::string toString() const {
    std::stringstream s;
    s << "(";
    s << lhs;
    s << " ";
    s << op;
    s << " ";
    s << rhs;
    s << ")";
    // s << '\n';
    std::string str = s.str();  
    return str;
  }
  virtual std::string getexp() const {
    return toString();
  }
};
    
class MinusExpression : public Expression {
private:
  std::string lhs;
  std::string rhs;
  char op;
public:
  MinusExpression(Expression *lhs, Expression *rhs) : lhs(lhs->getexp()), rhs(rhs->getexp()), op('-') {}
  
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

class TimesExpression : public Expression {
private:
  std::string lhs;
  std::string rhs;
  char op;
public:
  TimesExpression(Expression *lhs, Expression *rhs) : lhs(lhs->getexp()), rhs(rhs->getexp()), op('*') {}
  
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

class DivExpression : public Expression {
private:
  std::string lhs;
  std::string rhs;
  char op;
public:
  DivExpression(Expression *lhs, Expression *rhs) : lhs(lhs->getexp()), rhs(rhs->getexp()), op('/') {}
  
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

    
#endif
