#include <iostream>

class AbstractClass {
public:
  AbstractClass() {}
  ~AbstractClass() {}
  virtual void PrimitiveOperation1() = 0;
  virtual void PrimitiveOperation2() = 0;

  void TemplateMethod() {
    PrimitiveOperation1();
    PrimitiveOperation2();
  }
};

class ConcreteClassA : public AbstractClass {
public:
  void PrimitiveOperation1() override {
    std::cout << "ConcreteClassA::PrimitiveOperation1" << std::endl;
  }
  void PrimitiveOperation2() override {
    std::cout << "ConcreteClassA::PrimitiveOperation2" << std::endl;
  }
};

class ConcreteClassB : public AbstractClass {
public:
  void PrimitiveOperation1() override {
    std::cout << "ConcreteClassB::PrimitiveOperation1" << std::endl;
  }
  void PrimitiveOperation2() override {
    std::cout << "ConcreteClassB::PrimitiveOperation2" << std::endl;
  }
};

int main() {
  AbstractClass *abstract;
  abstract = new ConcreteClassA;
  abstract->TemplateMethod();
  abstract = new ConcreteClassB;
  abstract->TemplateMethod();
  return 0;
}