//      /bin/users/_skin.c
//      by Nightshade

#include <std.h>
inherit DAEMON;
int abil();

int cmd_skin(string str) {
   object ob, *stuff;
   string *curr;
   int i;

    if (!abil()) {
        notify_fail("What?\n");
        return 0;
    }
    if(!str) {
        notify_fail("Skin what?\n");
        return 0;
    }
    if(str != "corpse") {
        notify_fail("You can only skin corpses.\n");
        return 0;
    }
    if(!present("remains", environment(this_player()))) {
        notify_fail("No corpse here!\n");
        return 0;
    }
    if(this_player()->query_current_attacker()) {
        notify_fail("You cannot take the time to do that now.");
        return 0;
    }
    if(present("remains", environment(this_player()))->id("skinned")) {
        notify_fail("This corpse has already been skinned.\n");
        return 0;
    }
    write("You carefully remove the skin from the corpse.");
    say(this_player()->query_cap_name()+" carefully removes the skin from the corpse.");
    ob = new(OBJECT);
    ob->set_short("A "+present("remains", environment(this_player()))->query_old_race()+" skin");
    ob->set_long("A raw bit of skin taken from a "+present("remains", environment(this_player()))->query_old_race()+".");
    ob->set_id(({"skin",present("remains", environment(this_player()))->query_old_race()+"skin"}));
    ob->set_weight(1);
ob->set_curr_value("silver", 3+random(this_player()->query_skill("nature")/10));
    ob->move(this_player());
    this_player()->set_disable();
    if(random(40)+100 > this_player()->query_skill("nature")) {
        ob = present("remains", environment(this_player()));
        stuff = all_inventory(ob);
        i = sizeof(stuff);
        while(i--) {
            write("You get "+stuff[i]->query_short()+" from the corpse.");
            stuff[i]->move(this_player());
        } 
        curr = ob->query_currencies();
        i = sizeof(curr);
        if (i)
            write("You pick up a pile of coins.");
        while(i--) {
            this_player()->add_money(curr[i], ob->query_money(curr[i]));
        }
        present("remains", environment(this_player()))->remove();
    }
    else
        present("remains", environment(this_player()))->set_id(present("remains", environment(this_player()))->query_id()+({"skinned"}));
    return 1;
}

void help() { 
    write("Syntax: <skin corpse>\n\n"+
        "Rangers can remove the skin from corpses for\n"
        "making armour or selling.\n");
}

int abil() {
   if (this_player()->query_subclass() != "ranger") return 0;
   if (this_player()->query_skill("nature") < 15) return 0;
   return 1;
}
