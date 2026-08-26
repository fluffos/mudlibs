#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create();
    set("short", "Priss the technician");
    set("long", @Endtext
She is a spunky girl who grew up tinkering and fixing things.  Now,
her job is to repair damaged machines for profit.  If you require
her services, type <repair [#hp/all]> and she'll fix you up nicely.
Repair cost: 3 gold coins per 1 hp restored.
Endtext
    );
    set("id", ({ "priss", "technician" }) );
    set_name("priss");
    set_living_name("priss");
    enable_commands();
    set("no_attack", 1);
    set("prevent_summon", 1);
    set("race", "human");
    set("gender", "female");
    set("inquiry", ([
      "repair" :
      "I can fix everything, including machines that are totally destroyed.\n",
    ]) ) ;
}

void init() {
    add_action("repair_player", "repair");
}

int repair_player(string str) {
    int hpmax, hpnow, cost;
    hpmax = this_player()->query("max_hp");
    hpnow = this_player()->query("hit_points");

    if(this_player()->query("race") != "machine") return 0;
    if(!str) return notify_fail("Syntax: <repair [#hp]> or <repair all>\n");
    if(str == "all") {
	cost = (hpmax-hpnow)*3;
    } else {
	sscanf(str, "%d", cost);
	if(hpnow + cost > hpmax) return
	    notify_fail("Priss says: You do not need that much repairing.\n");
	cost = cost*3;
    }
    if(this_player()->query("wealth/gold") < cost) return
	notify_fail("Priss says: You don't have enough gold to pay me.\n");
    this_player()->set("wealth/gold",
      this_player()->query("wealth/gold") - cost);
    this_player()->receive_healing(cost/3);
    write("Priss says: It costed you "+ cost +" gold to be repaired.\n");
    return 1;
}
