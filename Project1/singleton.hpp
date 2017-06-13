#pragma once

#include <mutex>

template <typename T>
class Singleton {
public:
	template<typename... Args>
	static T* instance(Args&&... args) {
		if (m_pInstance == nullptr) {
			m_pInstance = new T(std::forward<Args>(args)...);
		}
		return m_pInstance;
	}

	static T* get_instance() {
		if (m_pInstance == nullptr) {
			throw std::logic_error("the instance is not init");
		}
		return m_pInstance;
	}

	static void destroy_instance() {
		delete m_pInstance;
		m_pInstance = nullptr;
	}

private:
	Singleton();
	virtual ~Signleton();
	Singleton(const Singleton&);
	Signleton& operator=(const Singleton&);

private:
	static T* m_pInstance;
};

template<class T>
T* Singleton<T>::m_pInstance = nullptr;

// demo use
struct A {
	A(const string&) {}
	A(string&& x) {}
	void foo() { }
};

void demo1() {
	string str = "hello";
	Signleton<A>::instance(str);

	Singleton<A>::get_instance()->foo();
}