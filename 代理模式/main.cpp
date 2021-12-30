#include <iostream>

/**
 * @brief Subject 类，定义了 RealSubject 和 Proxy 的共用接口，这样就在任何使用
 * RealSubject 的地方都可以使用 Proxy
 *
 */
class Subject {
public:
  Subject() {}
  ~Subject() {}

  virtual std::string Request() = 0;
};

/**
 * @brief RealSubject 类，定义 Proxy 所代表的真实实体
 *
 */
class RealSubject : public Subject {
public:
  RealSubject() {}
  ~RealSubject() {}

  std::string Request() override { return "RealSubject"; }
};

/**
 * @brief proxy 类，保存一个引用使得代理可以访问实体，并提供一个与 Subject
 * 接口相同的接口，这样代理就可以用来替代实体
 *
 */
class Proxy : public Subject {
public:
  Proxy() {}
  ~Proxy() {}

  std::string Request() override { return "[Proxy]" + m_RealSubject.Request(); }

private:
  RealSubject m_RealSubject;
};

void Print(Subject *subject) { std::cout << subject->Request() << std::endl; }

int main() {
  Proxy *proxy = new Proxy;

  Print(proxy);

  return 0;
}