// This simul-efun is made to make sure .ACCESS is always created...

#ifndef _MASTER_C

#include "/include/config.h"

#endif

int
mkdir(string path)
{
    int x;
    if(!MASTER_OB->check_access(path, this_interactive(), "mkdir", 1))
	return 0;

    if(efun::mkdir(path)) {
	if (this_interactive()) {
	    MASTER_OB->set_access_data(path,
	      this_interactive()->query_real_name(), "owner");
	    MASTER_OB->set_access_data(path, 0, "r");
	}
	return 1;
    }
    return 0;
}
