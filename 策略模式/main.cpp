#include <iostream>

class Operation {
public:
  Operation() {}
  ~Operation() {}

  virtual double Calculate(double numA, double numB) = 0;
};

class OperationAdd : public Operation {
public:
  double Calculate(double numA, double numB) override {
    double result = numA + numB;
    return result;
  }
};

class OperationSub : public Operation {
public:
  double Calculate(double numA, double numB) override {
    double result = numA - numB;
    return result;
  }
};

class OperationMul : public Operation {
public:
  double Calculate(double numA, double numB) override {
    double result = numA * numB;
    return result;
  }
};

class OperationDiv : public Operation {
public:
  double Calculate(double numA, double numB) override {
    if (numB == 0) {
      std::cout << "除数不能为0" << std::endl;
      return 0;
    }
    double result = numA / numB;
    return result;
  }
};

class OperationContext {
public:
  OperationContext(Operation *oper) { cs = oper; }

  ~OperationContext() {}

  double GetResult(double numA, double numB) {
    return cs->Calculate(numA, numB);
  }

private:
  Operation *cs;
};

int main() {
  OperationContext oper(new OperationAdd());
  double numA = 1;
  double numB = 2;
  std::cout << numA << " + " << numB << " = " << oper.GetResult(numA, numB)
            << std::endl;
  return 0;
}