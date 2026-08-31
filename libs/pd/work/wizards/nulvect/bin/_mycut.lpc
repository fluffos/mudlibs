#include <daemons.h>
inherit DAEMON;
int abil();
int cmd_cut(string str)
{
 int a,b, i, clear;
  string target_thing;
 object ob;
 object *wield;
   if (!abil()) {
      return 0;
   }
 if ((!str || str=="") && !this_player()->query_current_attacker())
   {
    write("Cut what?");
    return 1;
  }
   if (environment(this_player())->query_property("no attack"))
     {
      write("Greater powers prevent your malice.");
      return 1;
     }
   if(!b=sizeof(wield=(object *)this_player()->query_wielded())) {
        notify_fail("You need a weapon to cut with!\n");
        return 0;
    } 
   i = sizeof(wield);
   clear = 0;
   while (i--) {
     if (wield[i]->query_type() == "knife" || wield[i]->query_type() == "blade" || wield[i]->query_type() == "axe")
      clear = 1;
     if(wield[i]->query_type() == "blunt") return notify_fail("You can't cut with a blunt weapon wielded!\n");
     if(wield[i]->query_type() == "projectile") return notify_fail("You can't cut with a projectile weapon wielded!\n");
     if(wield[i]->query_type() == "flail") return notify_fail("You can't cut with a flail weapon wielded!\n");
   }
  if (!clear) return notify_fail("You need a bladed weapon to cut with!\n");
  
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
    write("You are too tired to cut.");
    return 1;
   }
   if(this_player()->query_ghost())
      return notify_fail("You cannot attack without a body.\n");
   if(this_player()->query_disable()) return 1;
    if(!this_player()->kill_ob(ob)) {
        write(ob->query_cap_name()+" can't be attacked by you yet.");
       return 1;
    }
    this_player()->set_disable();
if (b > 1)
   if (this_player()->query_skill("attack") < random(120))

    b = 1;
while(b--) {
 
a = BALANCE_D->get_damage(this_player(), ob, 2, ({ "attack", wield[b]->query_type() }),
                                   ({ "dexterity" }) ) +
            wield[b]->query_wc()*5/4;
       a = a / 2;
        if (a < 10)
      {
        write("You miss your cut.");
        say( this_player()->query_cap_name()+" misses "+this_player()->query_subjective()+" cut.");
        return 1;
      }
    
    write("You cut "+ob->query_cap_name()+" with your "+wield[b]->query_cap_name()+".");
    message("info", this_player()->query_cap_name()+" cuts "+ob->query_cap_name()+".", environment(this_player()), ({ this_player(), ob }));        
    message("info", this_player()->query_cap_name()+" cuts you.", ob);
 target_thing = (string)ob->return_target_limb();
  ob->do_damage(target_thing, a);
  ob->check_on_limb(target_thing);
                            
this_player()->add_sp(-(a/9));
}
 return 1;
}
int abil() {
   object o;
   o = this_player();
   if (!o) return 0;
   if (o->query_class() != "wanderer") return 0;
   if (o->query_level() < 5) return 0;
   if (o->query_skill("knife") < 14) return 0;
   return 1;
}
void help() {
   write("Syntax: <cut [(living)]>\n\n"
      "A wanderer command which enables you to use your bladed to cut your oponent. If you are wielding more that one bladed you have the ability to cut more than once.\n"); }
