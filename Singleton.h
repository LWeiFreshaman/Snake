#ifndef Singleton_H__
#define Singleton_H__

#include <iostream>
#include <mutex>
#include <atomic>

using std::cout;
using std::endl; 
using std::mutex;
using std::atomic;

template <typename T>
class Singleton
{
public:
	const T& getValue() { return value; }
	void setValue(const T& v) { value = v; }
	virtual ~Singleton() = default;
	static Singleton<T>* getInstance();
private:
	T value;
	static atomic<Singleton<T>*> instance;
	static mutex mtx;
	Singleton() { cout << "contruction." << endl; }
};

template <typename T>
atomic<Singleton<T>*> Singleton<T>::instance = nullptr;

template <typename T>
mutex Singleton<T>::mtx;

template <typename T>
Singleton<T>* Singleton <T>::getInstance()
{
	//就是把atomic_thread_fence操作移到原子变量本身
	Singleton<T>* tmp = instance.load(std::memory_order_acquire);		//第一次读取
	//std::atomic_thread_fence(std::memory_order_acquire);

	if (nullptr == tmp)
	{
		//tmp = instance.load(std::memory_order_acquire);
		std::unique_lock<mutex> uniLoc(mtx);
		tmp = instance.load(std::memory_order_relaxed);		//这个地方好像可以移到锁外面，
		if (nullptr == tmp)
		{
			//这个地方，new可能被cpu重排操作变成分配内存-赋值-构造，所以此处需要一个原子操作
			tmp = new Singleton<T>;	//只有这里需要保证原子操作
			//std::atomic_thread_fence(std::memory_order_release);
			instance.store(tmp, std::memory_order_release);		//这里不需要保证内存顺序
		}
	}

	return tmp;
}

#endif