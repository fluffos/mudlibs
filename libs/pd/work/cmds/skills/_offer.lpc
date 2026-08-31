//      /bin/users/_offer.c
//      from the Nightmare mudlib
//      Kattan ability
//      created by Gregon@nightmare
 
 
#include <move.h>
#include <std.h> 
inherit DAEMON;
int spell();

string type() { return "faith"; }
 
int cmd_offer(string str) {
    int amount, ammount, i, b;
    object ob, *all, mon;
    string Class, *curr;
 
   if (!spell()) {
      return notify_fail("What?\n");
   }
    if(str!="corpse") {
        notify_fail("Offer what?\n");
        return 0;
    }
    if(!ob = present("remains", environment(this_player()))) {
        notify_fail("No corpse here!\n");
        return 0;
    }
    if(this_player()->query_current_attacker()) {
        notify_fail("You cannot do that in battle!");
        return 0;
    }
    Class = (string)this_player()->query_subclass();
    if(Class != "kataan") {
        notify_fail("The demons of the underworld laugh at you.\n");
        return 0;
    }
    write("You offer this soul to the demons of the underworld.");
    say(this_player()->query_cap_name()+" pleases the demons with a fresh "
        "soul.", this_player());
    amount = random((int)this_player()->query_skill("faith")/7 + 6);
    this_player()->heal(amount);
    this_player()->add_alignment(-(4+random(3)));
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
    return 1;

}
 
void help() { 
    write("Syntax: <offer corpse>\n\n"+
        "Allows a kataan to gain strength through offering the souls of "+
        "the dead to the demons of the underworld.\n");
}

int spell() { if (this_player()->query_subclass() == "kataan") return 1; }
