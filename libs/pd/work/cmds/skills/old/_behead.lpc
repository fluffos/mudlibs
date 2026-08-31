// a dungeonware.net production
// coded 22-Oct-00 by stormbringer
#include <daemons.h>
inherit DAEMON;
int abil();
int cmd_behead(string str)
{
 int a,b, i, clear;
  string blah, target_thing;
 object ob;
 object *wield;
   if (!abil()) {
      write("You would hurt yourself.");
      return 1;
   }
 if ((!str || str=="") && !this_player()->query_current_attacker())
   {
    write("Behead what?");
    return 1;
  }
   if (environment(this_player())->query_property("no attack"))
     {
      write("Greater powers prevent your malice.");
      return 1;
     }
   if(!b=sizeof(wield=(object *)this_player()->query_wielded())) {
        notify_fail("You need a weapon to behead with!\n");
        return 0;
    } 
   i = sizeof(wield);
   clear = 0;
   while (i--) {
     if (wield[i]->query_type() == "blade" || wield[i]->query_type() == "knife"
      || wield[i]->query_type() == "axe")
      clear = 1;
     if(wield[i]->query_type() == "blunt") return notify_fail("You can't slash with a blunt weapon wielded!\n");
     if(wield[i]->query_type() == "projectile") return notify_fail("You can't slash with a projectile weapon wielded!\n");
     if(wield[i]->query_type() == "flail") return notify_fail("You can't slash with a flail weapon wielded!\n");
   }
  if (!clear) return notify_fail("You need a bladed weapon to behead with!\n");
  
  if (this_player()->query_current_attacker()) 
    ob = this_player()->query_current_attacker();
   else {
     ob = present(str, environment(this_player()));
     if (!ob)
       {
        write("You dont see that.");
        return 1;
       }
     if (ob==this_player())
      {
       write("Something must be wrong with you.");
       return 1;
      }
    }
 if (this_player()->query_sp() < 50) 
   {
    write("You don't have the energy for this.");
    return 1;
   }
   if(this_player()->query_disable()) return 1;
   if(!this_player()->kill_ob(ob)) return 1;
    this_player()->set_disable();
if (b > 1)
  if (this_player()->query_skill("attack") < random(80))
    b = 1;
while(b--) {
 
 a = this_player()->query_skill("attack")*3/2 -
     ob->query_skill("defense")*2/5 +
     this_player()->query_stats("strength")*3/2 +
     this_player()->query_stats("dexterity")/4 -
     ob->query_stats("dexterity")*2/3 + wield[b]->query_wc()*6
     - ob->query_skill("defense")/6; 
    if (a < 0)
      {
        write("You miss your beheading attempt.");
        say( this_player()->query_cap_name()+" misses "+this_player()->query_subjective()+" attempt to behead "+ob->query_cap_name()+"!");
        return 1;
   }
    
    write("You attempt to behead "+ob->query_cap_name()+" with your "+wield[b]->query_cap_name()+"!");
    message("info", this_player()->query_cap_name()+" attempts to behead "+ob->query_cap_name()+"!", environment(this_player()), ({ this_player(), ob }));        
    message("info", this_player()->query_cap_name()+" attempts to behead you!", ob);
  ob->set_target_limb(lower_case("head"));
  target_thing = (string)ob->return_target_limb();
  ob->do_damage(target_thing, a*2/5);
  ob->check_on_limb(target_thing);
                            
  this_player()->add_sp(-(a/7));
}
 return 1;
}
int abil() {
   object o;
   o = this_player();
   if (!o) return 0;
   if (o->query_class() != "fighter") return 0;
   if (o->query_level() < 50) return 0;
   if (o->query_skill("blade") < 175) return 0;
   return 1;
}
void help() {
   write("Syntax: <behead [(living)]>\n\n"
      "A fighter command which enables you to use your bladed weapon(s) to attempt to cut your opponents head off. If you are wielding more that one sword you have the ability to make the attempt more than once.\n"); }
