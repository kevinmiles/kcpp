#include "services.h"

class Driver {
public:
	int x;
	Driver() {
		capi_printk("inside constructor!\n");
	}
	~Driver() {
		capi_printk("inside destructor!\n");
	}
};

static Driver* driver;

extern "C" {
	int cpp_init(void);
	void cpp_exit(void);
}
int cpp_init() {
	driver = new Driver();

	return(0);
}

void cpp_exit() {
	delete driver;
}
