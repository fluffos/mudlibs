//      /bin/users/_feed.c
//      from the Nightmare mudlib
//      Mage ability
//      created by Descartes of Borg
//      made autosac, autobag, etc by Nightshade

#include <std.h>
#include <move.h>
inherit DAEMON;
int spell();

int cmd_feed(string str) {
    int amount, ammount, i, b;
    string clas, *curr;
    object ob, *all, mon;

   if (!spell()) {
      notify_fail("What?\n");
      return 0;
   }
    if(!str) {
        notify_fail("Feed on what?\n");
        return 0;
    }
    if(sscanf(str, "on %s", str) != 1 && str != "corpse") {
        notify_fail("You can only feed on corpses.\n");
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
    clas = (string)this_player()->query_class();
    if(clas != "mage") {
        notify_fail("Yuck!\n");
        return 0;
    }
 if(this_player()->query_ghost())
  {
   write("You have no body to feed with!");
   return 1;
  }
    write("You feed on the soul of the recently deceased.\n");
    say(this_player()->query_cap_name()+" feeds on the soul of the recently deceased.\n", this_player());
    amount = random((int)this_player()->query_skill("conjuring")/7 + 6);
    this_player()->heal(amount);
 ob = present("remains", environment(this_player()));
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
 ob->remove();
 if(ob)
     destruct(ob);
    return 1;
}

void help() { 
    write("Syntax: <feed on corpse>\n\n"+
        "Allows the magic user to gain strength through feeding on the souls\n"+
        "of the recently deceased.\n");
}

int spell() {
   if (this_player()->query_class() != "mage") return 0;
   if (this_player()->query_skill("conjuring") <1) return 0;
   return 1;
}
