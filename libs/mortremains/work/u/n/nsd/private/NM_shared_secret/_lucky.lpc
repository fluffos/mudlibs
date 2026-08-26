#include <rogues.h>
#include <mudlib.h>

#define SS "/d/class/warrior/Sharpshooter/"

int cmd_lucky(string str){
    object targ, ob;

    if (!str) str = "BLAH";
    targ = present(str, environment(TP));
    ob = present("#CLASS_OBJECT#", TP);

    if (!ob || !ob->query("equipped")) {
	write ("You need to equip the Cybernetic eyelink for that.\n");
	return 1; 
    }

    // if (targ) checks to see if the object 'targ' exists.
    if(!targ){
	say(TPN+" twirls "+POSS+" gun and says: Do ya feel lucky punk?\n");
	write("You twirl your gun and say: Do ya feel lucky punk?\n");
	return 1;
    } else {
	write("You hold your gun to "+targ->query("cap_name")+
	  "'s head and say, \"Do ya feel lucky, punk?\"\n");
	say(wrap(TPN+" holds "+POSS+" gun to "+targ->query("cap_name")+
	    "'s head and says, \"Do ya feel lucky, punk?\""), ({ targ }) );
    }
    return 1;
}
