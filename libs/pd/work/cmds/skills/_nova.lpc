#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>
inherit DAEMON;
int spell()
{
  if (this_player()->query_subclass()!="pyromancer") return 0;
  if (this_player()->query_level() < 49) return 0;
  if (this_player()->query_skill("pyromancy") < 300) return 0;
  if (this_player()->query_skill("conjuring") < 200) return 0;
  return 1;
}
void help()
{
  write("Syntax: nova\n"
   "A higher level Pyromancer spell that creates a powerful bubble of fire around the caster, and then releases it violently in all directions. The bubble becomes a violent wall of flame that damages everything in the room.");

}
string type() { return "attack"; }
int cmd_nova(string str)
{
  string party;
  int i, x, spUse, j;
  object *per=({}), *mobs=({}), tp;
  tp = this_player();
  if(str) return 0;

  if (!spell()) return 0;

  if (tp->query_mp() < 100)
    return notify_fail("Your spell fails, due to lack of magic.\n");

  if (environment(this_player())->query_property("no attack") 
   || environment(this_player())->query_property("no magic") )
    return notify_fail("Greater powers prevent your malice.");


  if (tp->query_busy()) return notify_fail("You are busy.\n");

  write("%^BOLD%^%^RED%^You clench your fists, and create a %^YELLOW%^sphere of fire%^RED%^ around you.%^RESET%^\n");
  tell_room(environment(tp), "%^BOLD%^%^RED%^"+ tp->query_cap_name() + 
   " creates a large %^YELLOW%^sphere of fire%^RED%^ around "+objective(tp)+"self!%^RESET%^",
   ({ tp }));

  tp->add_mp(-(100+random(25)));

  tp->set_magic_round();

  if (tp->query_party())
    party = tp->query_party();
  else party = "AdkIl898-FL00Jn-neInfe_ron";

  /*
  per = all_inventory(environment(this_player()));
  //this section filters out all the junk that doesn't need to be attacked
  for(x = 0; x < sizeof(per); x++)
  {
    if( per[x]->is_living() && per[x]!= this_player() &&
     per[x]->query_party() != party && !wizardp(per[x]) &&
     !per[x]->query_ghost())
    {
      mobs = mobs + ({ per[x] });
    }
  }
  */

  per = filter(all_inventory(environment(tp)), (: $1->is_living() :) );
  mobs = per - query_allies(tp);

  j = sizeof(mobs);

  tp->set_paralyzed(1, "You are concentrating on keeping the flame alive.");
  //main loop that deals the dmg
  for(x = 0; x < j; x++) 
  {

    if (this_player()->query_mp() < 150) {
      write ("You lose the focus needed to hold the fire in place.");
      break;
    }

    i =  BALANCE3_D->get_damage( this_player(), mobs[x], 4, ({ "pyromancy", "pyromancy", "magic attack" }),
     ({ "intelligence", "intelligence", "wisdom" }), ({"pyromancy", "pyromancy", "magic attack"}) );

    //i = i * (((2.0 / (sizeof(mobs) + 1)) + (1.0 / (x + 1.0))) / 2);
    i = i*5/4;
    i = (i*2/3) + random(i/3);
    if(!tp->kill_ob(mobs[x])) {
      write(mobs[x]->query_cap_name()+" can't be attacked by you yet.");
      return 1;
    }

    if(5 > i) {
      write("The wave of fire passes by "+mobs[x]->query_cap_name()+" doing no damage!");
      say("A wave of fire passes by "+mobs[x]->query_cap_name()+" doing no damage!");
      tell_object(mobs[x], "A wave of fire passes by you doing no harm.");
      continue;
    }

    if (environment(tp) != environment(mobs[x])){
      write(""+mobs[x]->query_cap_name()+" is not here.");
      tell_room(environment(tp), "The wave of fire vanishes.", ({ tp }));
      return 1;
    }
    if (!mobs[x]){
      write(""+mobs[x]->query_cap_name()+" is not here.");
      tell_room(environment(tp), "The wave of fire vanishes.", ({ tp }));
      return 1;
    }
    mobs[x]->do_damage("all", i, DAMAGE_MAGIC | DAMAGE_FIRE, DAMAGE_NO_SEVER, tp);
    tell_object(mobs[x], "%^BOLD%^%^RED%^The sphere of fire %^BLACK%^%^BOLD%^explodes%^RESET%^ into a giant wall of f%^YELLOW%^l%^RED%^a%^YELLOW%^m%^RED%^e and crashes into you!%^RESET%^");
    tell_room(environment(mobs[x]), "%^BOLD%^%^RED%^"+mobs[x]->query_cap_name()+
     " disappears behind a giant wall of %^RED%^f%^YELLOW%^l%^RED%^a%^YELLOW%^m%^RED%^e rushing out from "
     +tp->query_cap_name()+"!%^RESET%^", ({ mobs[x] }));

//    this_player()->add_mp(-(25+random(8)));
    tp->add_mp(-BALANCE3_D->get_cost(i, 4, "mp")/3);

    //-------------------------------------------------------
    if(wizardp(this_player()))
    {
      message("dmg", "dmg = "+i, this_player());
    }
  }

  /*
  this_player()->add_mp(-(this_player()->query_skill("pyromancy")/5 + 
    random(this_player()->query_skill("pyromancy")/3)));
  */

  return 1;
}

