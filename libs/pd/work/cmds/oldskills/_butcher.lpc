//      /bin/users/_butcher.c
//      by Nightshade
//      Small fixed by Whit
//      update for coin bug and autobag by Nightshade

#include <std.h>
#include <move.h>
inherit DAEMON;
int abil();

int cmd_butcher(string str) {
    object ob, *all, mon;
    string *curr;
    int i, ammount, b;

    if (!abil()) {
        notify_fail("What?\n");
        return 0;
    }
    if(!str) {
        notify_fail("Butcher what?\n");
        return 0;
    }
    if(this_player()->query_current_attacker()) {
        notify_fail("You have more pressing matters to attend to.\n");
        return 0;
    }
    if(this_player()->query_ghost())
    {
        write("You have no body to sacrifice with!");
        return 1;
    }
    if(str != "corpse") {
        notify_fail("You can only butcher corpses.\n");
        return 0;
    }
    if(!present("remains", environment(this_player()))) {
        notify_fail("No corpse here!\n");
        return 0;
    }
    write("You slice up the meat for food.");
    say(this_player()->query_cap_name()+" slices up the corpse for food.");
    ob = new(FOOD);
    if(!present("remains", environment(this_player()))->query_old_race()) {
        ob->set_short("A bit of unknown meat");
        ob->set_long("This slice of unknown meat would be good for eating.");
        ob->set_name("unknown meat");
    } else {
        ob->set_name(present("remains", 
            environment(this_player()))->query_old_race()+" meat");
        ob->set_short("A bit of "+present("remains",
            environment(this_player()))->query_old_race()+" meat");
        ob->set_long("This slice of "+present("remains",
            environment(this_player()))->query_old_race()+" meat would be good "
          "for eating.");
    }
    ob->set_id(({"meat","bit of meat", "food"}));
    ob->set_weight(2);
    ob->set_dis(1);
    ob->set_my_mess("You eat the slice of meat.");
    ob->set_your_mess("eats a slice of meat.");
    ob->set_strength(random(10)+10);
    ob->move(this_player());
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
    this_player()->set_disable();
    return 1;
}

void help() { 
    write("Syntax: <butcher corpse>\n\n"+
      "Those with strong enough stomachs can cut up the corpse\n"+
      "for food.\n");
}

int abil() {
    if (this_player()->query_class() != "fighter") return 0;
    return 1;
}
