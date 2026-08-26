#include <rogues.h>
#include <mudlib.h>

#define SS "/d/class/warrior/Sharpshooter/"
object ob;


int cmd_CaMeL4711(string str) {
    ob = present("#CLASS_OBJECT#", TP);

    if (!ob || !ob->query("equipped")) {
	write ("You need to equip the Cybernetic eyelink for that.\n");
	return 1; 
    }
    if (!str) str = "index";

    if (this_player()->more(SS+"help/"+str) != 1) {
	write("Type thelp index.\n");
	return 1;
    }
    return 1;
}
