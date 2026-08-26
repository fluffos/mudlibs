#include <rogues.h>
#include <mudlib.h>

#define SS "/d/class/warrior/Sharpshooter/"

int cmd_reason(string str){
    object targ, ob;

    if (!str) str = "BLAH";
    targ = present(str, environment(TP));
    ob = present("#CLASS_OBJECT#", TP);

    if (!ob || !ob->query("equipped")) {
	write ("You need to equip the Cybernetic eyelink for that.\n");
	return 1; 
    }

    if(!targ){
     write("Who do you want to threaten?\n");
	return 1;
    } else {
	write("You hold your gun to "+targ->query("cap_name")+
       "'s head and whisper, \"Just give me a reason.\"\n");
	say(wrap(TPN+" holds "+POSS+" gun to "+targ->query("cap_name")+
       "'s head and whispers, \"Just give me a reason.\""), ({ targ }) );
    }
    return 1;
}
