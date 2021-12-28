#include <iostream>
#include <string>

class Operation {
public:
  Operation() {}
  ~Operation() {}

  double m_NumA;
  double m_NumB;

  virtual double GetResult() = 0;
};

class OperationAdd : public Operation {
  double GetResult() override {
    double result = 0.0;
    result = m_NumA + m_NumB;
    return result;
  }
};

class OperationSub : public Operation {
  double GetResult() override {
    double result = 0.0;
    result = m_NumA - m_NumB;
    return result;
  }
};

class OperationMul : public Operation {
  double GetResult() override {
    double result = 0.0;
    result = m_NumA * m_NumB;
    return result;
  }
};

class OperationDiv : public Operation {
  double GetResult() override {
    double result = 0.0;
    if (m_NumB == 0) {
      std::cout << "Error: 除数不能为0" << std::endl;
      return 0.0;
    }
    result = m_NumA / m_NumB;
    return result;
  }
};

class OperationFactory {
public:
  OperationFactory() {}
  ~OperationFactory() {}

  static Operation *createOperation(char operate) {
    Operation *oper = nullptr;
    switch (operate) {
    case '+':
      oper = new OperationAdd();
      break;
    case '-':
      oper = new OperationSub();
      break;
    case '*':
      oper = new OperationMul();
      break;
    case '/':
      oper = new OperationDiv();
      break;
    default:
      break;
    }
    return oper;
  }
};

int main() {
  Operation *oper;
  oper = OperationFactory::createOperation('+');
  oper->m_NumA = 1;
  oper->m_NumB = 2;
  double result = oper->GetResult();
  std::cout << oper->m_NumA << " + " << oper->m_NumB << " = " << result
            << std::endl;
  return 0;
}