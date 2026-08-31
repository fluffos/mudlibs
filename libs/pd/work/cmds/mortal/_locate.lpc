#include <std.h>

inherit DAEMON;

int cmd_locate(string str) {
    object *inv;
    object ob;
    string obid;
    int num;
    int found = 0;

    if (!str) return notify_fail("Find what?\n");

    inv = deep_inventory(this_player());
    foreach (ob in inv)
    {
	if (member_array(str, ob->query_id()) != -1)
	{		
	    // We've found an object.  Our next objective is to figure out where
	    // it is located.

	    // if ob's environment is bag
	    if (environment(ob)->is_bag())
	    {
		// Get id of ob's environment
		obid = environment(ob)->query_id()[0]; 

		// loop through each item of obid
		num = 1;
		while(present(obid+" "+num, this_player()))
		{
		    if (present(obid+" "+num, this_player()) == environment(ob))
		    {
                           write(ob->query_short()+" was found in "+environment(ob)->query_short()+" "+num+"");

		    }
		    num++;
		}
		found = 1;
	    }
	    else 
	    {
		write(ob->query_short()+" was found in your inventory.");
		found = 1;
	    }
	}
    }

    if (!found){
	return notify_fail("No "+str+" was found.\n");
    }
    return 1;
}

void help() {
    write("Syntax: <locate [item]>\n"
      "This command will show all locations of an item in your inventory.\n");	
} 

