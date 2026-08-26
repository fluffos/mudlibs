
#include <mudlib.h>
#include "/u/d/dragoon/include/format.h"

inherit WEAPON ;

void create()
{ 
    set ("short", "a slavedriver's whip") ;
    set ("long", format(
	"A black leather whip, approximately two meters long. "
	"This is a standard issue whip for admin's who need to 'encourage' wizards. "
	"If you know what your doing, you might be able to [crack] it."
      )) ;
    set ("id", ({ "whip" })) ;
    set ("mass", 20) ;
    set ("bulk", 4) ;
    set ("value", 20) ;
    set ("size", 6) ;
    set_weapon (5) ;
    set ("damage", ({ 2, 8 })) ;
    set ("type", "bash") ;
    set ("name", "slaver's whip") ;
    set_verbs (({ "crack", "whip", "thwack" }));
    set ("damage_type", "bash") ;
}


void init()
{
    add_action("crack", "crack") ;
}

int crack(string str)
{
    if (str!="whip")
    {
	notify_fail("what do you want to crack?\n") ;
	return 0;
    }
    say (this_player()->query("cap_name") + " cracks the whip! Get to work!\n") ;
    write("You crack the whip, wizards everywhere pretend to work.\n") ;
    return 1 ;
}

