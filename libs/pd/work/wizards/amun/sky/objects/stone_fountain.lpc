#include <std.h> 
#include <amun.h>
inherit OBJECT;
void create() {
    ::create();
    set_id(({ "fountain" }));
    set_name("fountain");
    set_long("%^BOLD%^%^WHITE%^This fountain was made by the Angels and it offers the healing powers they possess. It stands 15 feet in the air, with a small circular mirror set between a large pair of stone angel wings. The mirror looks quite interesting, the glass seems to be flowing as if there is a current towards the center of it, creating circular waves.%^RESET%^");
    set_short("%^BOLD%^%^WHITE%^St%^RESET%^o%^BOLD%^%^WHITE%^n%^RESET%^e %^BOLD%^%^WHITE%^F%^RESET%^ou%^BOLD%^%^WHITE%^nt%^RESET%^ai%^BOLD%^%^WHITE%^n%^RESET%^");
    set_weight(100000);
    set("value", 0);
    set_prevent_get( "The fountain is way too big!" );
}
int goDrink(string str) {
    if (str != "fount" && str != "fountain" && str != "from fount" && str !=
      "from fountain") {
	notify_fail("Drink from what?\n");
	return 0;
    }
    if (!this_player()->add_quenched(15)) {
	write("You are too full to drink right now.");
	return 1;
    }
    if (this_player()->query_disable()) {
	write("You cannot drink with water already in your mouth!");
	return 1;
    }
    this_player()->set_disable();
    this_player()->heal(50);
    write("The water flows through your body, quenching your thirst.");
    return 1;
}
int findPlayer(string str) {
    object ob;
    object *inv;
    string desc;

    if(!str) {
	notify_fail("Find who?\n");
	return 0;
    }

    if(this_player()->query_money("platinum")<50)
    {
	notify_fail("A platinum coin with a 50 in the center is shown in the mirror.\n");
	return 0;
    }
    else
    {
	this_player()->add_money("platinum", -50);
	message("room", this_player()->query_cap_name()+" throws a coin into the mirror, and the water glass begins to swirl."
	  ,environment(this_player()),this_player());
	message("tp", "You throw 50 platinum coins into the watery glass.",this_player());
    }

    ob = find_living(str);
    if(!ob || !ob->is_player()) {
	message("failed", "The glass glows black unable to find the player in the shadows.", this_player());
	return 0;
    }
    if(environment(ob)->query_property("no scry") || 
      environment(ob)->query_property("no teleport"))
	return notify_fail("The glass glows black unable to find the player in the shadows.\n");
    if(wizardp(ob)) 
    {
	notify_fail("The glass glows black unable to find the player in the shadows.\n");
	return 0;
    }

    ob = environment(ob);
    if(!ob) write("The glass glows black unable to find the player in the shadows.\n");
    else {
	desc = (string)ob->query_long()+"\n";
	inv = all_inventory(ob);
	for(int i=0; i<sizeof(inv); i++) {
	    if(inv[i]->query_invis()) continue;
	    desc += (string)inv[i]->query_short()+"\n";
	}
	write("The glass swirls wildly as it locates the person in question.\n"+desc);
    }

    return 1;

}
void init() {
    ::init();
    add_action("findPlayer", "find");
    add_action("goDrink", "drink");
}
