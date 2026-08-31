// sacrifice corpses to the greater gods.. seeker (05/17/2000)
// Update for coin pile bug and autobag by Nightshade
#include <daemons.h>
#include <move.h>

inherit DAEMON;


int cmd_sacrifice(string str)
{
 object ob, *all, mon;
 string *curr;
 int i, b, ammount;

 if (!str || str=="")
   {
    write("Sacrifice what?");
    return 1;
   }

 if(this_player()->query_current_attacker())
  {
   write("You cannot take the time in battle!");
   return 1;
  }
 if(this_player()->query_ghost())
  {
   write("You have no body to sacrifice with!");
   return 1;
  }

 ob = present(str, environment(this_player()));
 if (!ob)
  {
   write("You dont see that.");
   return 1;
  }

 if (!ob->query_corpse() && !ob->is_limb()) 
   {
    write("The gods reject your sacrifice.");
    return 1;
   }
 if (ob->is_limb())
   {
    write("You sacrifice "+definite_article(strip_color(ob->query_short()))+" to the gods.");
    this_player()->add_hp(2);
    ob->remove();
    return 1;

   }
 write("You sacrifice the corpse to the gods.");
 say(this_player()->query_cap_name()+" sacrifices the corpse to the gods.");
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
     else if (sizeof(all[i]->query_short())) {
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

 this_player()->add_hp(10);
 this_player()->add_sp(10);
 this_player()->add_mp(10);
 return 1;
}

void help()
{
 write("Syntax: Sacrifice [corpse/limb]\n\n"
       "It is used to sacrifice limbs and corpses to the gods and "
       "you will be rewarded with hp/mp/sp.");
}
