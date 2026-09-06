
#include <treasure.h>
#define TP this_player()
#define POISON_D "/guilds/thieves/poison_d"

void
create_treasure()
{
    set_name("eraser");
    set_short("A magical eraser");
    set_long("A magical eraser!  You can use it to remove \
poison from items.  You might find some other uses as well!\n\
To user: 'rub <object>'");
    set_id(({ "eraser", "magical eraser" }));
    set_weight(0);
    set_value(30);
}
query_thief_item() { return 1; }
void
init_treasure()
{
    add_action("wipe_cmd","rub");
}

status
wipe_cmd(string arg)
{
    string ob_short,rl_short,dummy;
    object ob;
    if (!arg) return notify_fail("Rub what?\n"),0;
    ob = first_inventory(TP);
    while (ob && !ob->id(arg))
	ob = next_inventory(ob);
    if (!ob) return notify_fail("You don't have a " + arg +
	  " that you can rub!\n"),0;
    ob_short = ob->query_short();
    if (!ob_short) return notify_fail("Oops something went " +
	  "wrong, report this to colt someday.\n"),0;
    if (sscanf(ob_short,"%s covered in a strange substance",rl_short) != 1)
	if (sscanf(ob_short,"%s #HOB#",rl_short) != 1)
	    return notify_fail("There's nothing worth rubbing " +
	      "on " + arg + ".\n"),0;
    POISON_D->remove_poisoned_thing(ob);
    TP->tell_me("You rub the magical eraser over the " + arg +
      ".  Your hand tingles briefly, then nothing.");
    environment(TP)->tell_here(TP->query_name() + "rubs the " + arg +
      " with the magical eraser.",TP);
    ob->set_short(rl_short);
    return 1;
}
