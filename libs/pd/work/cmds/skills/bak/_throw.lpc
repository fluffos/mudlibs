#include <daemons.h>
inherit DAEMON;
int abil();
string type() { return "attack"; }
int cmd_throw(string str)
{
  int dmg;
  string what, who;
 object ob, thing;
   if (!abil()) {
      return 0;
   }
 if (!str || str=="")
   {
    write("Syntax: <throw [weapon] (at [living])>");
    return 1;
  }
   if (environment(this_player())->query_property("no attack"))
     {
      write("Greater powers prevent your malice.");
      return 1;
     }
   if(this_player()->query_ghost())
     return notify_fail("You cannot pick up anything to throw while dead.\n");
   if(sscanf(str, "%s at %s", what, who) != 2)
        what = str;
   if(this_player()->query_rest_type()) {
        notify_fail("You cannot throw anything while resting.");
        return 0;
   }
   if(who)
     ob = present(who, environment(this_player()));
   else
     ob = this_player()->query_current_attacker();
   if (!ob)
       {
        write("Throw "+what+" at what?");
        return 1;
       }
     if (ob==this_player())
      {
       write("Something must be wrong with you.");
       return 1;
      }
   thing = present(what, this_player());
   if(!thing)
       return notify_fail("You do not have "+a_or_an(what)+" "+what+".\n");
   if(!thing->is_weapon())
       return notify_fail("A weapon would do more damage.\n");
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
   if(!living(ob)) {
      write("Now is not the time for target practice.");
      return 1;
    }
    
 if (this_player()->query_sp() < 50) 
   {
    write("You are too tired to throw anything.");
    return 1;
   }
   if(this_player()->query_disable()) return 1;
    this_player()->set_disable();
   dmg = BALANCE_D->get_damage( this_player(), ob, 2, ({ "attack" }),
                                   ({ "strength", "dexterity" }) );
     dmg = dmg/2 + (thing->query_wc()*this_player()->query_level()/2);
  if(dmg < 10) {
    write("You throw your "+thing->query_short()+"%^RESET%^ at "+ob->query_cap_name()+", but miss "+objective(ob)+".");
    say(this_player()->query_cap_name()+" throws a "+thing->query_short()+"%^RESET%^ at you, but misses!");
    message("info", this_player()->query_cap_name()+" throws a "+thing->query_short()+"%^RESET%^ at "+ob->query_cap_name()+", but misses "+objective(ob)+".", environment(this_player()), ({ this_player(), ob }));
    thing->move(environment(this_player()));
  }
  else {
    write("You throw your "+thing->query_short()+"%^RESET%^ at "+ob->query_cap_name()+", striking "+objective(ob)+" badly!");
    say(this_player()->query_cap_name()+" throws a "+thing->query_short()+"%^RESET%^ at you, striking you badly!");
    message("info", this_player()->query_cap_name()+" throws a "+thing->query_short()+"%^RESET%^ at "+ob->query_cap_name()+", striking "+objective(ob)+" badly.", environment(this_player()), ({ this_player(), ob }));
    thing->move(ob);
    ob->damage(dmg);
  }
  this_player()->add_sp(-dmg/7 - thing->query_weight());
 return 1;
}
int abil() {
   object o;
   o = this_player();
   if (this_player()->query_class() != "rogue" &&
       this_player()->query_class() != "wanderer" &&
       this_player()->query_class() != "fighter") return 0;
   if(o->query_level() < 10) return 0;
   return 1;
}
void help() {
   write("Syntax: <throw [weapon] (at [living])>\n\n"
      "Allows you to throw your weapon at a specified target.\n"); }
