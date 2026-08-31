// - seeker rules, inferno is a moron!!! -
// nein -> remodified by "moron"

#include <std.h>
inherit OBJECT;

string dest;

void set_destination(string str)
{
 dest = str;
}
void create() {
 ::create();
   set_id( ({"portal", "rift", "wormhole"}) );
   set_name("portal");
   set_short("a wormhole to another place");
   set_long("A breach in reality, unstablely shimmering; about to collapse.");
   set_prevent_get("Your hand disappears as you reach towards the wormhole.");
}

int rmPortal()
{
 message("info","The wormhole collapses into nothingness.",
	 environment(this_object()));
 this_object()->remove();
 if (this_object()) destruct(this_object());
 return 1;
}
int init()
{
 ::init();
 add_action("enter", "enter");
// call_out("rmPortal", 10);
}
int enter(string str)
{
 object thp;
 if (!str)
   {
     write("Enter what?");
     return 1;
   }
 write("You enter the portal and land in a place totally different than before.");
 this_player()->move_player(dest, "hyperspace");
// this_player()->force_me("look");
// rmPortal();
 thp = present("portal", environment(this_player()));
 if (thp) thp->rmPortal();
 rmPortal();
 return 1;
}
//int get() { return 0; }
