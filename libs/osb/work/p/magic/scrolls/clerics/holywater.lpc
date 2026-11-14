/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
#include <combat.h>
inherit "/obj/scroll";
#define TP this_player()
#define HIM this_player()->QueryObjective()
#define HE this_player()->QueryPronoun()
#define HIS this_player()->QueryPossessive()

int MyCast(string str) 
{
int dam;
object wolf;
  if (!str) wolf=GetEnemy(this_player()); /* draw random enemy */
  else wolf=present(str, environment(this_player()));
  if (!wolf) { write("That's not here.\n"); return CAST_FAIL_NOMSG; }
  if ((wolf->QueryIsNPC()==0) && (wolf->QueryIsPlayer()==0)) {
     write("You can't cast it on that!\n"); return CAST_FAIL_NOMSG; }
  if (wolf->QueryIsPlayer()) LogCast(this_player(),wolf); /* Aggressor */
  if (Repulse(wolf, this_player())) return CAST_REPULSE;
  Message(({
  "Mist gathers around your hands. It whirls faster and faster.\n"+
  "You lift your hands high above your head and then extend them\n"+
  "towards "+wolf->QueryName()+
    " in one forceful motion. Suddenly the mist\n"+
  "turns into a cascade of holy water which hits "+
    wolf->QueryName()+".\n",
  "Mist gathers around "+add_gen(TP->QueryName())+
    " hands. It whirls faster and faster.\n"+
  TP->QueryName()+" lifts "+HIS+" hands high above "+HIS+
    "head and then extend\n"+
  "them towards "+wolf->QueryName()+
    " in one forceful motion. Suddenly the mist\n"+
  "turns into a cascade of holy water which hits "+
    wolf->QueryName()+".\n" }) );

  if (wolf->QueryAlign()<-500) {
     dam = random(40) + 2;
  }
  else if ((wolf->QueryAlign()<0) && (wolf->QueryAlign()>-500)) {
     dam = random(30) + 2;
  }
  else dam = random(20) + 2;
  dam=wolf->Defend(ModifyMagic(dam), DT_WATER, 0);
  if (wolf) Message(QueryCastDamage(dam,wolf));  /* write damage string */
  return CAST_SUCCESS;
}

int MyFail() {
int dam;
  if (Repulse(this_player(),this_player())) return CAST_REPULSE;
  Message( ({
  "Mist gathers around your hands. It whirls faster and faster.\n"+
  "Suddenly you feel that you are losing control over the spell.\n"+
  "The glow around your hands fades and you feel as if your hands\n"+
  "would be boiled in a cauldron with hot water.\n",
  "Mist gathers around "+TP->QueryName()+
    " hands. It whirls faster and faster.\n"+
  "Suddenly "+TP->QueryName()+" looses "+HIS+
    " concentration allowing the mist\n"+
  "to collapse all over "+HIS+" body.\n" }) );

  dam=10;
  dam=this_player()->Defend(ModifyMagic(dam), DT_WATER, 0);
  Message(QueryCastDamage(dam)); 
  return CAST_SUCCESS;
}

void create() {
 ::create();
 AddSpell("water",ST_WATER,18,#'MyCast,"holy water",25);
 SetSpellDesc(
"This spell will splash holy water on your opponent doing a damage of\n\
up to 20 hp water damage if a monster is not evil, 28 hp if a monster is\n\
nasty and 36 hp if a monster is very evil.\n");
 SetSpellUsage("cast water <target>\n");
 SetMemoLevel(GC_SORCERER,4);
 SetMemoLevel(GC_ARCHMAGE,4);
 
 SetFailFn(#'MyFail);
}

