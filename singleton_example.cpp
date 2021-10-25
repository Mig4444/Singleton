#include <iostream>
#include <cstdint>
#include <thread>

class Singleton
{
    public:
		static Singleton &getInstance()
		{
			static Singleton *instance_m = new Singleton();
			return *instance_m;
		}

		void printId()
		{
			std::cout << "[Singleton @"<< this << "] Id is = "<< this->Id  << ", value = " <<  unsigned(value_m) << std::endl;
		}

        void setValue(uint8_t value)
        {
            value_m = value;
        }

		void setId(std::string id)
		{
            this->Id = id;
            //Singleton &instance = getInstance();
			//instance.Id = id;
		}

		void printOnlineID()
		{
			std::cout<<"Id" <<std::endl;
		}

    private:
        Singleton(){};
        Singleton(const Singleton&);
        Singleton& operator=(const Singleton&);
        std::string Id;
        uint8_t value_m{42};
};


class Human
{
public:
	void callSingleton()
	{
		Singleton::getInstance();
	}
private:
	unsigned int Health;
};

Human human2_m;

void ThreadFoo(){
    // Following code emulates slow initialization.
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    std::cout << " -- ThreadFoo -- " << std::endl;
    Singleton& singleton = Singleton::getInstance();
    singleton.printId();
    singleton.setValue(33);
	singleton.printId();
    //Singleton::getInstance().printId();
}

void ThreadBar(){

    // Following code emulates slow initialization.
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << " -- ThreadBar -- " << std::endl;
    Singleton& singleton = Singleton::getInstance();
    singleton.printId();
    singleton.setValue(46);
	singleton.printId();
}

int main()
{
    Singleton::getInstance().setValue(199);
    //Singleton s;
    Singleton& instance = Singleton::getInstance();
    //instance.setValue(23);
    instance.printOnlineID();
    Human *human1_m = new Human();
    human1_m->callSingleton();

    instance.setId("1234");
    instance.printId();
    std::thread t1(ThreadFoo);
    std::thread t2(ThreadBar);
    t1.join();
    t2.join();

    Singleton& instance2 = Singleton::getInstance();
    instance2.printId();

    return 0;
}
