#include <iostream>

class Operation {
public:
  Operation() {}
  ~Operation() {}

  void SetA(double numA) { m_NumA = numA; }
  void SetB(double numB) { m_NumB = numB; }
  virtual double Result() = 0;

protected:
  double m_NumA;
  double m_NumB;
};

class OperationAdd : public Operation {
public:
  double Result() override { return m_NumA + m_NumB; }
};

class OperationSub : public Operation {
public:
  double Result() override { return m_NumA - m_NumB; }
};

class OperationMul : public Operation {
public:
  double Result() override { return m_NumA * m_NumB; }
};

class OperationDiv : public Operation {
public:
  double Result() override {
    if (m_NumB == 0) {
      std::cout << "除数不能为 0" << std::endl;
      return -1.0;
    }
    return m_NumA * m_NumB;
  }
};

class Factory {
public:
  virtual Operation *CreateOperation() = 0;
};

class AddFactory : public Factory {
public:
  Operation *CreateOperation() override { return new OperationAdd; }
};

class SubFactory : public Factory {
public:
  Operation *CreateOperation() override { return new OperationSub; }
};

class MulFactory : public Factory {
public:
  Operation *CreateOperation() override { return new OperationMul; }
};

class DivFactory : public Factory {
public:
  Operation *CreateOperation() override { return new OperationDiv; }
};

int main() {
  Factory *factoryAdd = new AddFactory;
  Operation *add = factoryAdd->CreateOperation();
  add->SetA(1);
  add->SetB(2);
  double result = add->Result();
  std::cout << "1 + 2 = " << result << std::endl;
  return 0;
}