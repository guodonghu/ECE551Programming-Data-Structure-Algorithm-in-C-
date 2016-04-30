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
  virtual long evaluate() const = 0;
  virtual long getans() const = 0;
};

class NumExpression : public Expression {
private: 
  long num;
  long ans;
public:
  NumExpression(long n): num(n) {
    ans = n;
  }
  
  virtual std::string toString() const {
    std::stringstream s;
    s << num;
    std::string str;
    str = s.str();
    return str;
  }
  virtual std::string getexp() const {
    return toString();
  }
  
  virtual long evaluate() const {
    return ans;
  }

  virtual long getans() const {
    return ans;
  }
};

class OpExpression : public Expression{
protected:
  std::string lhso;
  std::string rhso;
  char op;
  long ans;
  long opl;
  long opr;
public:
  OpExpression(Expression *lhs, Expression *rhs) : lhso(lhs->getexp()), rhso(rhs->getexp()) {
    opl = lhs->getans();
    opr = rhs->getans();
    delete lhs;
    delete rhs;
  }

  virtual std::string toString() const {
    std::stringstream s;
    s << "(";
    s << lhso;
    s << " ";
    s << op;
    s << " ";
    s << rhso;
    s << ")";
    std::string str = s.str();  
    return str;
  }
  
  virtual std::string getexp() const {
    return toString();
 }
  
  virtual long getans() const {
    return ans;
  }
    
};

class PlusExpression : public OpExpression {  
public:
  PlusExpression(Expression *lhs, Expression *rhs) : OpExpression(lhs, rhs) { 
    op = '+';
    ans = evaluate();
  }  

  virtual long evaluate() const {
    long temp = opl + opr;
    return temp;
  }
};

class MinusExpression : public OpExpression {  
public:
  MinusExpression(Expression *lhs, Expression *rhs) : OpExpression(lhs, rhs) { 
    op = '-';
    ans = evaluate();
  }   
  
  virtual long evaluate() const {
    long temp = opl - opr;
    return temp;
  }
};

class TimesExpression : public OpExpression {  
public:
  TimesExpression(Expression *lhs, Expression *rhs) : OpExpression(lhs, rhs) { 
    op = '*';
    ans = evaluate();
  }   
  
  virtual long evaluate() const {
    long temp = opl * opr;
    return temp;
  }
};

class DivExpression : public OpExpression {  
public:
  DivExpression(Expression *lhs, Expression *rhs) : OpExpression(lhs, rhs) { 
    op = '/';
    ans = evaluate();
  }
  virtual long evaluate() const {
    long temp = opl / opr;
    return temp;
  }
};

    
#endif
