//     /bin/user/_whirl.c
//     A rogue/fighter physical attack
//     Written by Forlock for the Nightmare lib.
 
#include <std.h>
int abil();
inherit DAEMON;
 
int cmd_whirl (string str) {
   
   int attack, total;
   object ob;

    if (!abil())
      {
       write("What?\n");
        return 1;
    }
    if(!sizeof((object *)this_player()->query_wielded())) {
        notify_fail("You need a weapon to whirl with!\n");
        return 0;
    }
    if(!str)
      ob = (object)this_player()->query_current_attacker();
    else {
       ob = present(str, environment(this_player()));
       if(!ob) ob = parse_objects(environment(this_player()), str);
    }
   if(!ob || !living(ob)) {
        notify_fail("That is not here as such.\n");
      return 0;
   }
   if(ob == this_player())
      return notify_fail("Why would you want to do a thing like that?\n");

   if(this_player()->query_ghost()) {
      notify_fail("Your voice is hollow.\n");
      return 0;
   }
   if (this_player()->query_disable())
     {
      write("You are not balanced enough to whirl.");
      return 1;
     }
 
   if(this_player()->query_casting()) return 1;
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
   if(environment(this_player())->query_property("no attack")) {
      notify_fail("A magic force prevents you from doing your attack.\n");
      return 0;
   }
    if((int)this_player()->query_sp() < 20) {
        notify_fail("You are too tired.\n");
        return 0;
    }
    this_player()->set_disable();
    this_player()->set_casting();
    
      write("You whirl at "+ob->query_cap_name()+"!\n");
      attack = (this_player()->query_skill("attack")/3);
      attack += (this_player()->query_stats("strength")/2);
      attack -= (ob->query_skill("defense")/3);
      attack -= (ob->query_stats("dexterity")/3);
      if (attack < 5)
        return notify_fail("You miss your whirl attempt!\n");
      tell_room(environment(this_player()), this_player()->query_cap_name()+ " whirls at "+(string)ob->query_cap_name() + "\n", ({ob, this_player()}));
      tell_object(ob, this_player()->query_cap_name()+" whirls at you.\n");
      total = (attack*3/2);
      this_player()->add_skill_points("attack", total);
      this_player()->add_sp(-(total/8));
      ob->damage(total + random(this_player()->querry_level()/2));
      return 1;
   }

int abil() {
 if (this_player()->query_level() < 2) return 0;
 if (this_player()->query_class()=="fighter") return 1; }

void help() {
   write("Syntax: <whirl [(living)]>\n\n"
      "A fighter attack command that causes you to whirl at the object named.\n");
}

