#include <iostream>

class Operation {
public:
  Operation() {}
  ~Operation() {}

  double m_NumA;
  double m_NumB;

  virtual double Calculate() = 0;
};

class OperationAdd : public Operation {
public:
  double Calculate() override {
    double result = m_NumA + m_NumB;
    return result;
  }
};

class OperationSub : public Operation {
public:
  double Calculate() override {
    double result = m_NumA - m_NumB;
    return result;
  }
};

class OperationMul : public Operation {
public:
  double Calculate() override {
    double result = m_NumA * m_NumB;
    return result;
  }
};

class OperationDiv : public Operation {
public:
  double Calculate() override {
    if (m_NumB == 0) {
      std::cout << "除数不能为0" << std::endl;
      return 0;
    }
    double result = m_NumA / m_NumB;
    return result;
  }
};

class OperationContext {
public:
  OperationContext(char operation) {
    OperationAdd *cs0 = new OperationAdd();
    OperationSub *cs1 = new OperationSub();
    OperationMul *cs2 = new OperationMul();
    OperationDiv *cs3 = new OperationDiv();
    switch (operation) {
    case '+':
      cs = cs0;
      break;
    case '-':
      cs = cs1;
      break;
    case '*':
      cs = cs2;
      break;
    case '/':
      cs = cs3;
      break;
    }
  }
  ~OperationContext() {}

  void SetA(double numA) {
    if (cs == nullptr) {
      return;
    }
    cs->m_NumA = numA;
  }

  void SetB(double numB) {
    if (cs == nullptr) {
      return;
    }
    cs->m_NumB = numB;
  }

  double GetA() {
    if (cs == nullptr) {
      return -1;
    }
    return cs->m_NumA;
  }

  double GetB() {
    if (cs == nullptr) {
      return -1;
    }
    return cs->m_NumB;
  }

  double GetResult() { return cs->Calculate(); }

private:
  Operation *cs;
};

int main() {
  OperationContext oper('+');
  oper.SetA(1);
  oper.SetB(2);
  std::cout << oper.GetA() << " + " << oper.GetB() << " = " << oper.GetResult()
            << std::endl;
  return 0;
}