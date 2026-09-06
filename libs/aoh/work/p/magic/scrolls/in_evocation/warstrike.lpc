/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
#include <combat.h>
inherit "/obj/scroll";
#define TP this_player()
#define HIM this_player()->QueryObjective()
#define HE this_player()->QueryPronoun()
#define HIS this_player()->QueryPossessive()

void DoAttack(object wolf) 
{
int dam;
  if (wolf && living(wolf) && wolf->QueryIsNPC()) 
  {
    if (Repulse(wolf, this_player())) return;
    dam=random(230)+20;

    Message( ({
    "Rays of frozen white fire coil and twist as they shoot at "+
      wolf->QueryName()+".\n",
    "Rays of frozen white fire coil and twist as they shoot at "+
      wolf->QueryName()+".\n"}) );
    dam=wolf->Defend(ModifyMagic(dam), DT_FIRE, 0);
    if (wolf) Message(QueryCastDamage(dam,wolf));
  }
}

int MyCast(string str)
{
  if (str)
  {
    if (str==this_player()->QueryName()) return CAST_FAIL_NOMSG;
    write("You cannot use an argument with this "+QuerySpellNoun()+".\n");
    return CAST_FAIL_NOMSG;
  }
  Message( ({
  "You throw your hands upwards and begin chanting the spell.\n"+
  "Lightnings shoot out from your glowing fingers and connect with\n"+
  "the sky above. With a deafening bang you release the energy.\n",
  TP->QueryName()+
  " throws "+HIS+" hands upwards and begins chanting strange words.\n"+
  "Lightnings shoot out from "+HIS+" glowing fingers and connect with\n"+
  "the sky above. With a deafening bang "+HE+" releases the energy.\n"}) );

  filter(all_inventory(environment(this_player())),#'DoAttack);
  return CAST_SUCCESS;
}

int MyFail() 
{
int dam;
  if (Repulse(this_player(),this_player())) return CAST_REPULSE;
  Message( ({
  "You throw your hands upwards and begin chanting the spell. Suddenly\n"+
  "lightnings coil around you like giant snakes lifting your body up\n"+
  "into the air. You squeal as they pierce your body. A tornado of\n"+
  "immense energy whirls into the sky and your crippled body falls down\n"+
  "in one heap of disfigured steaming flesh.\n",
  TP->QueryName()+
  " throws "+HIS+" hands upwards and begins chanting strange words.\n"+
  "Suddenly, lightnings coil around "+HIM+" like giant snakes lifting\n"+
  HIS+" body up into the air. You hear screams of pain as they pierce\n"+
  HIS+" body. A tornado of immense energy whirls "+TP->QueryName()+
  " into the air.\n"+
  "After some painful seconds the crippled body falls down in one heap\n"+
  "of disfigured steaming flesh.\n"}) );
  dam=50+random(50);
  dam=this_player()->Defend(ModifyMagic(dam), DT_FIRE, 0);
  Message(QueryCastDamage(dam));
  return CAST_SUCCESS;
}
void create() 
{
 ::create();
 AddSpell("warstrike",ST_FIRE,130,#'MyCast,"warstrike",50);
 SetSpellDesc(
"This spell will shoot rays of frozen fire at all monsters present.\n\
It makes fire damage up to 250 HP.\n"); 
 SetSpellUsage("cast warstrike\n");
 SetMemoLevel(GC_SORCERER,18);
 SetMemoLevel(GC_ARCHMAGE,18);
 SetCastLevel("all",8);    /* Too dangerous otherwise!!! */ 
 SetFailFn(#'MyFail);
}

