#include <iostream>

/**
 * @brief Component 对象接口
 *
 * 可以给这些对象动态地添加职责
 */
class Component {
public:
  virtual std::string Operation() = 0;
};

/**
 * @brief Decorator 装饰抽象类
 *
 * 继承了 Component，从外类来扩展 Component
 * 类的功能，但对于 Component 来说，是无需知道 Decorator 的存在的
 */
class Decorator : public Component {
protected:
  Component *m_Component;

public:
  Decorator(Component *component) : m_Component(component) {}

  std::string Operation() override { return m_Component->Operation(); }
};

/**
 * @brief ConcreteComponent 具体对象
 *
 */
class ConcreteComponent : public Component {
public:
  std::string Operation() override { return "ConcreteComponent"; }
};

class ConcreteDecoratorA : public Decorator {
public:
  ConcreteDecoratorA(Component *component) : Decorator(component) {}

  std::string Operation() override {
    return "ConcreteDecoratorA(" + Decorator::Operation() + ")";
  }
};

class ConcreteDecoratorB : public Decorator {
public:
  ConcreteDecoratorB(Component *component) : Decorator(component) {}

  std::string Operation() override {
    return "ConcreteDecoratorB(" + Decorator::Operation() + ") : " + AddedBehavior();
  }

  std::string AddedBehavior() { return "AddedBehavior"; }
};

void Print(Component *component) {
  std::cout << "PRINT: " << component->Operation() << std::endl;
}

void Print(std::string str) { std::cout << "PRINT: " << str << std::endl; }

int main() {
  Component *core = new ConcreteComponent;
  Print(core);

  Component *decoratorA = new ConcreteDecoratorA(core);
  Component *decoratorB = new ConcreteDecoratorB(core);

  Print(decoratorA);
  Print(decoratorB);
  return 0;
}
