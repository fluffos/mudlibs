//Coup De Grace by Nightshade
#include <daemons.h>
inherit DAEMON;
int abil();
int cmd_coupdegrace(string str)
{
  int dmg;
  object ob;
   if (!abil()) {
      return 0;
   }
   if (environment(this_player())->query_property("no attack"))
     {
      write("Greater powers prevent your malice.");
      return 1;
     }
   if(this_player()->query_rest_type()) {
        notify_fail("You cannot throw anything while resting.");
        return 0;
   }
     ob = this_player()->query_current_attacker();
   if (!ob)
       {
        write("You are not in combat.");
        return 1;
       }
     if (ob==this_player())
      {
       write("Something must be wrong with you.");
       return 1;
      }
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
    write("You are too tired to preform such a task.");
    return 1;
   }
   if(this_player()->query_disable()) return 1;
   this_player()->set_disable();
   dmg = this_player()->query_skill("attack") -
        ob->query_skill("defense") +
        this_player()->query_stats("strength")*6 +
        this_player()->query_stats("dexterity")*5 -
        ob->query_stats("dexterity")*1/3 -
        ob->query_stats("constitution") +
        this_player()->query_skill("melee")/2;

   if(dmg < ob->query_hp()) {
       write("You try to execute a finishing blow, but fail!\nYou are thrown terribly off balance from your misjudgement!");
       say(this_player()->query_cap_name()+" tries to execute a Coup De Grace on "+ob->query_cap_name()+" and fails, making "+objective(this_player())+" loose "+possessive(this_player())+" balance.", ob);
       message("info",this_player()->query_cap_name()+" tries to execute a Coup De Grace on you, but falls off balance!", ob);
       ob->damage(dmg/10);
       this_player()->set_paralyzed(2+random(2), "You have yet to regain your balance after your attempt to finish off "+ob->query_cap_name()+"!");
   }
   else {
       write("%^BOLD%^%^RED%^In a spray of blood, you finish off "+ob->query_cap_name()+".%^RESET%^");
       say("%^BOLD%^%^RED%^"+this_player()->query_cap_name()+" finishes off "+ob->query_cap_name()+" in a spray of blood.%^RESET%^", ob);
       message("info", "%^BOLD%^%^RED%^"+this_player()->query_cap_name()+" cleaves through you, mortally wounding you.%^RESET%^", ob);
       ob->damage(dmg*2);
   }
   this_player()->add_sp(dmg/5);

   return 1;
}
int abil() {
   object o;
   o = this_player();
   if (this_player()->query_class() != "figher" ||
       this_player()->query_subclass() != "swashbuckler" ||
       this_player()->query_subclass() == "paladin") return 0;
   if(o->query_level() < 40) return 0;
   return 1;
}
void help() {
   write("Syntax: <coupdegrace>\n\n"
      "Powerful fighters are able to execute a Coup De Grace, delivering a finishing blow to their enemy.  If miscalculated, it throws the fighter off balance.\n"); }
