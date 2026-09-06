/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
#include <combat.h>
inherit "/obj/scroll";

int MyCast(string str) {
object wolf,wolf2;
string race;
  if (!str)
  {
    write("Cast it on what?\n");
    return CAST_FAIL_NOMSG;
  }
  if (str=="remove")
  {
    wolf=present("spellbook",this_player());
    if (!wolf) {write("You have no spellbook!\n");return CAST_FAIL_NOMSG;}
    wolf->RemoveFamiliar();
    write("You loose your familiar.\n");
    return CAST_SUCCESS;
  }
  wolf=present(str, environment(this_player()));
  if (!wolf) wolf=present(str,this_player());
  if (!wolf) { write("That's not here.\n");  return CAST_FAIL_NOMSG; }
  if (!present("spellbook",this_player())) {
      write("You can't cast that spell.\n");
      return CAST_FAIL_NOMSG;
  }
  if ((wolf->QueryIsNPC()==0) && (!wolf->id("familiar"))) {
     write("That is no possible familiar!\n");
     return CAST_FAIL_NOMSG;
  }
  if (wolf->id("wolf")) {
     write("The wolf refuses to be your familiar.\n");
     return CAST_FAIL_NOMSG;
  }
  Message(({"You make it your familiar.\n",
      this_player()->QueryName()+" has a new familiar now.\n"}) );
  race=wolf->QueryRace();
  wolf->own();
  wolf2=present("spellbook",this_player());
  if (wolf2) wolf2->SetFamiliar(race);
  if (wolf2) wolf2->SetFamObj(wolf);
  return CAST_SUCCESS;
}

int MyFail() 
{
int dam;
  if (Repulse(this_player(),this_player(),ST_ZAP)) return CAST_REPULSE;
  Message( ({"A giant fist hits you!\n",
      "A giant fist hits "+this_player()->QueryName()}) );
  dam=10+random(20);
  dam=this_player()->Defend(ModifyMagic(dam), DT_ZAP, 0);
  Message(QueryCastDamage(dam));
  return CAST_SUCCESS;
}

create() 
{
 ::create();
// cause of constant destruction of familiars casting cost lowered
// from 105sp to 60sp
// taurus 21.1.96
 AddSpell("familiar",ST_SUMMON,60,#'MyCast,"make familiar",10);    
 SetSpellDesc(
"This will make a small animal your familiar.\n"+
"Only spell-casters can have a familiar for a familiar makes their\n"+
"spell-points restore faster.\n"+
"If a familiar dies, you will have to find a new one.\n"+
"You can give your familiar a name with 'name familiar <name>'.\n");
 SetSpellUsage("cast familiar <target> or cast familiar remove\n");
 SetMemoLevel("allmage",2);
 SetFailFn(#'MyFail);
}

