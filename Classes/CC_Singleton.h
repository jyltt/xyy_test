#ifndef CC_SINGLETON_H_
#define CC_SINGLETON_H_

#define CC_Singleton(Class) \
	public: static Class &getSingleton(){\
		static Class *single = nullptr;\
		if(single == nullptr)\
			single = new Class();\
		return *single;}\
	public: ~Class();\
	protected: Class();Class& operator=(const Class& rhs){}Class(Class& c){}
#endif