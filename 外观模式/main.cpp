#include <iostream>

class SubSystemOne {
public:
  SubSystemOne() {}
  ~SubSystemOne() {}

  void MethodOne() { std::cout << "MethodOne" << std::endl; }
};

class SubSystemTwo {
public:
  SubSystemTwo() {}
  ~SubSystemTwo() {}

  void MethodTwo() { std::cout << "MethodTwo" << std::endl; }
};

class SubSystemThree {
public:
  SubSystemThree() {}
  ~SubSystemThree() {}

  void MethodThree() { std::cout << "MethodThree" << std::endl; }
};

class SubSystemFour {
public:
  SubSystemFour() {}
  ~SubSystemFour() {}

  void MethodFour() { std::cout << "MethodFour" << std::endl; }
};

class Facade {
public:
  Facade() {
    one = new SubSystemOne;
    two = new SubSystemTwo;
    three = new SubSystemThree;
    four = new SubSystemFour;
  }
  ~Facade() {
    delete one;
    delete two;
    delete three;
    delete four;
  }

  void MethodA() {
    std::cout << "---- MethodA ----" << std::endl;
    one->MethodOne();
    three->MethodThree();
  }

  void MethodB() {
    std::cout << "---- MethodB ----" << std::endl;
    two->MethodTwo();
    three->MethodThree();
  }

private:
  SubSystemOne *one;
  SubSystemTwo *two;
  SubSystemThree *three;
  SubSystemFour *four;
};

int main() {
  Facade *facade = new Facade;
  facade->MethodA();
  facade->MethodB();
  return 0;
}