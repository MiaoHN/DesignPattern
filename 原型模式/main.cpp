#include <iostream>

class Resume {
public:
  Resume() {}
  Resume(std::string name) : m_Name(name) {}

  void SetName(std::string name) { m_Name = name; }
  void SetAge(int age) { m_Age = age; }
  void SetSex(int sex) { m_Sex = sex; }

  void ShowInfo() {
    std::cout << "Info:" << std::endl;
    std::cout << "  Name: " << m_Name << std::endl;
    std::cout << "  Age : " << m_Age << std::endl;
    std::cout << "  Sex : " << ((m_Sex == 0) ? "woman" : "man") << std::endl;
  }

  Resume *clone() {
    Resume *resume = new Resume(this->m_Name);
    resume->SetAge(this->m_Age);
    resume->SetSex(this->m_Sex);
    return resume;
  }

private:
  std::string m_Name;
  int m_Age;
  int m_Sex; // 1: man, 0: woman
};

int main() {
  Resume *person1 = new Resume("张三");
  person1->SetAge(36);
  person1->SetSex(2);
  Resume *person2 = person1->clone();
  person2->SetName("李四");

  person1->ShowInfo();
  person2->ShowInfo();
}