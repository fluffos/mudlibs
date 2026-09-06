#include "../priest.h"

#define BOTTLE_FILE PRIEST_OBJ_DIR "priest_bottle"

#ifndef BOTTLE
#define BOTTLE 30
#endif

status fill_bag(int arg)
{
    object *inv;
    object bag,bottle;
    int i,count;

    if(!present("alchemist",this_object())) {
	notify_fail("The shop seems to be closed.\n");
	return 0;
    }
    if(arg && sscanf(arg,"%d",arg)!=1) {
	notify_fail("Invalid argument(s).\n");
	return 0;
    }
    if(!arg || arg<1) arg=1;
    if(this_player()->query_money() < (6*BOTTLE)) {
	notify_fail("You don't have enough money.\n");
	return 0;
    }
    if(!present("bag",this_player())) {
	notify_fail("You don't seem to own a bag.\n");
	return 0;
    }
    inv=all_inventory(this_player());
    for(i=0;i<sizeof(inv);i++)
	if(call_other(inv[i],"id","bag")) {
	    count++;
	    if(count==arg)
		bag=inv[i];
	}
    if(!bag) {
	notify_fail("You don't have that many bags.\n");
	return 0;
    }
    count = 0;
    for(i=0;i<6;i++) {
	bottle = clone_object(BOTTLE_FILE);
	if(transfer(bottle,bag)==0)
	    count++;
	else {
	    destruct(bottle);
	    break;
	}
    }
    if(!count) {
	notify_fail("Can't fit any bottles into that bag.\n");
	return 0;
    }
    this_player()->add_money(-(count*BOTTLE));
    write(count+" bottles bought, making a total of "+(count*BOTTLE)+
      " coins.\nOk.\n");
    say(this_player()->query_name()+" buys some bottles.\n",this_player());
    return 1;
}



