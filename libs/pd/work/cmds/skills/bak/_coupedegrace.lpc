//Coupe De Grace by Nightshade
#include <daemons.h>
inherit DAEMON;
int abil();
string type() { return "attack"; }
int cmd_coupedegrace(string str)
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
    if(this_player()->query_ghost())
      return notify_fail("You cannot attack without a body.\n");
    if(sizeof(this_player()->query_wielded()) == 0) return notify_fail("You cannot coupe anyone with your bare hands.\n");
 if (this_player()->query_sp() < 50) 
   {
    write("You are too tired to preform such a task.");
    return 1;
   }
   if(this_player()->query_disable()) return 1;
   this_player()->set_disable();
   dmg = BALANCE_D->get_damage( this_player(), ob, 3, ({ "attack", this_player()->query_wielded()[0]->query_type() }),
                                   ({ "strength", "dexterity" }), ({ "dexterity" }) );
if((ob->query_max_hp()/3) < ob->query_hp())
    {
       write("You try to execute a finishing blow, but fail!\nYou are thrown
terribly off balance from your misjudgement!");
       say(this_player()->query_cap_name()+" tries to execute a Coupe De Grace
on "+ob->query_cap_name()+" and fails, making "+objective(this_player())+"
loose "+possessive(this_player())+" balance.", ob);
       message("info",this_player()->query_cap_name()+" tries to execute a Coup
De Grace on you, b
t falls off balance!", ob);
       this_player()->set_paralyzed(2+random(2), "You have yet to regain your
balance after your attempt to finish off "+ob->query_cap_name()+"!");
        this_player()->add_sp(-dmg/7);
    }
//    dmg = dmg + dmg/4;
//   this part ignores the amount defense would reduce, so reduced checked damage here.
   else if( dmg < ob->query_hp()) {
       write("You try to execute a finishing blow, but fail!\nYou are thrown terribly off balance from your misjudgement!");
       say(this_player()->query_cap_name()+" tries to execute a Coupe De Grace on "+ob->query_cap_name()+" and fails, making "+objective(this_player())+" loose "+possessive(this_player())+" balance.", ob);
       message("info",this_player()->query_cap_name()+" tries to execute a Coup De Grace on you, but falls off balance!", ob);
       ob->damage(dmg/10);
       this_player()->set_paralyzed(2+random(2), "You have yet to regain your balance after your attempt to finish off "+ob->query_cap_name()+"!");
   }
   else {
       write("%^BOLD%^%^RED%^In a spray of blood, you finish off "+ob->query_cap_name()+".%^RESET%^");
       say("%^BOLD%^%^RED%^"+this_player()->query_cap_name()+" finishes off "+ob->query_cap_name()+" in a spray of blood.%^RESET%^", ob);
       message("info", "%^BOLD%^%^RED%^"+this_player()->query_cap_name()+" cleaves through you, mortally wounding you.%^RESET%^", ob);
        ob->damage(dmg*3);
   }
   this_player()->add_sp(-dmg/7);
   return 1;
}
int abil() {
   if(this_player()->query_level() < 40) return 0;
   if(this_player()->query_subclass() == "paladin") return 0;
   if(this_player()->query_subclass() == "berserker") return 0;
   if (this_player()->query_class() == "fighter" ||
       this_player()->query_subclass() == "swashbuckler") return 1;
   return 0;
}
void help() {
   write("Syntax: <coupedegrace>\n\n"
      "Powerful fighters are able to execute a Coupe De Grace, delivering a finishing blow to their enemy.  If miscalculated, it throws the fighter off balance.\n"); }
