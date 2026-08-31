//      /bin/users/_eat.c
//      from the Nightmare mudlib
//      based off the feed command
//      by Descartes of Borg
//      made by Nightshade
//      coin bug fixed and autobag done by NS

#include <std.h>
#include <move.h>

inherit DAEMON;
int abil();

string type() { return "other"; }

int cmd_eat(string str) {
    object ob, *all, mon;
    string *curr;
    int i, ammount, b;

    if (!abil())
        return 0;
    if(!str) {
        notify_fail("Eat what?\n");
        return 0;
    }
    if(str != "corpse") {
        notify_fail("You can only eat corpses.\n");
        return 0;
    }
    if(!present("remains", environment(this_player()))) {
        notify_fail("No corpse here!\n");
        return 0;
    }
    if(this_player()->query_current_attacker()) {
        notify_fail("You cannot do that in battle!\n");
        return 0;
    }
 if(this_player()->query_ghost())
  {
   write("You have no body to sacrifice with!");
   return 1;
  }
    write("You eat the remains of your prey.\n");
    say(this_player()->query_cap_name()+" eats the remains of their prey.", this_player());
    ob = present("remains", environment(this_player()));
    ob->loot(this_player());
    /*
    all = all_inventory(ob);
    i = sizeof(all);
 while(i--)
 {
   if(all[i]->is_money_pile()) {
       mon = all[i];
       b = sizeof( curr = mon->query_currencies() );
       while(b--) {
           write("You find "+(ammount=mon->query_money(curr[b]))+" "+curr[b]+" "+
              (ammount>1?"coins":"coin")+" on the body.");
           this_player()->add_money(curr[b], ammount);
       }
       mon->remove();
       if(mon)
           destruct(mon);
   }
   else {
     if(all[i]->move(this_player()) == MOVE_NO_ROOM)
       write("You are too overburdened to take "+all[i]->query_short()+"%^RESET%^.");
     else {
       write("You get "+all[i]->query_short()+" from the corpse.");
       if(this_player()->query_property("autobag"))
         this_player()->force_me("put "+all[i]->query_id()[0]+" in "+this_player()->query_property("autobag"));
     }
   }
 }
  */
 ob->remove();
 if(ob)
     destruct(ob);
    this_player()->add_hp(random(15));
    this_player()->add_sp(random(60));
    this_player()->add_mp(random(10));
    return 1;
}

void help() { 
    write("Syntax: <eat corpse>\n\n"+
        "Dragons and some animals will commonly eat the prey that they
have just recently killed, giving them sustinance.\n");
}

int abil() {
   if (this_player()->query_class() != "dragon" && !this_player()->query("bear") && !this_player()->query("lion") && !this_player()->query("wolf")) return 0;
   return 1;
}
