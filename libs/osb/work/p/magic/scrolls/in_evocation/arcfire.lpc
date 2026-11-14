/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
#include <combat.h>
inherit "/obj/scroll";
#define TP this_player()
#define HIM this_player()->QueryObjective()
#define HE this_player()->QueryPronoun()
#define HIS this_player()->QueryPossessive()

/* Return the cost in SP for casting this spell: Set by Addspell */
int QueryCost()
{
  return(5+this_player()->QueryLevel());
}

/* Main cast function, set by AddSpell, return values depend on succcess */
int MyCast(string str)
{
string name;
object wolf;
int dam;
  if (!str) wolf=GetEnemy(this_player()); /* draw random enemy */
  else wolf=present(str, environment(this_player()));
  if (!wolf)
  {
     write("That's not here.\n"); 
     return CAST_FAIL_NOMSG;
  }
  name=wolf->QueryName();
  if (!wolf->QueryIsNPC() && !wolf->QueryIsPlayer()) {
     write("You can't cast it on that!\n"); return CAST_FAIL_NOMSG; }
  if (wolf->QueryIsPlayer()) LogCast(this_player(),wolf); /* Aggressor */
  if (Repulse(wolf, this_player())) return CAST_REPULSE;  /* enemy is resistant */
  Message( ({
  "You sweep the air with your hand. A blazing clot of arcanic fire starts\n"+
  "crackling on your open palm. You hurl the burning substance at "+wolf->QueryName()+".\n"+
  "With a trace of black oily smoke it hits, engulfing "+wolf->QueryName()+" in\n"+
  "turbulent golden flames.\n",
  TP->QueryName()+" sweeps the air with "+HIS+" hand. A blazing clot of arcanic\n"+
  "fire starts crackling on "+HIS+" open palm and "+HE+" hurls the burning substance\n"+
  "at "+wolf->QueryName()+". With a trace of black oily smoke it hits, engulfing\n"+
  wolf->Name()+" in turbulent golden flames.\n"}) );
  dam = random(4) * this_player()->QueryLevel()+5;
  dam=wolf->Defend(ModifyMagic(dam), DT_FIRE, 0);
  if (wolf) Message(QueryCastDamage(dam,wolf));  /* write damage string */
  return CAST_SUCCESS;
}

/* Spell failed due to lack of Wisdom. Function of obj/scroll */
int MyFail() {
int dam;
  if (Repulse(this_player(), this_player())) return CAST_REPULSE;
  Message( ({
  "You sweep the air with your hand. A blazing clot of arcanic fire starts\n"+
  "crackling on your open palm....ARRRGH.....Flames begin to engulf you,\n"+
  "turning you into a live bonfire. You scream in agony as fire scorches your\n"+
  "skin and roars all around you. The pain is unbearable. You sink to your knees\n"+
  "and then finally collapse.\n",
  TP->QueryName()+" sweeps the air with "+HIS+" hand. A blazing clot of arcanic\n"+
  "fire starts crackling on "+HIS+" open palm...Then "+HE+" barely cries: ARRRGH...\n"+
  "before flames begin to engulf "+HIM+", turning "+HIM+" into a live bonfire.\n"
  "You hear the screams of agony as fire scorches "+TP->QueryName()+".\n"+
  TP->QueryName()+" finally sinks to "+HIS+" knees and collapses.\n"}) );
  dam = (1+random(3)) * this_player()->QueryLevel();
  dam=this_player()->Defend(ModifyMagic(dam), DT_FIRE, 0);
  Message(QueryCastDamage(dam));  /* write damage string */
  return CAST_SUCCESS;
}
void create() {
 ::create();
 AddSpell("fire",ST_FIRE,#'QueryCost,#'MyCast,"arcanic fire",25);
 SetSpellDesc(
"This spell will produce an fiery burst of fire doing a damage of up\n\
to 3*level HP fire damage.\n\
The cost of this spell is 5 SP plus your level.\n");
 SetSpellUsage("cast fire <target>\n");
 SetMemoLevel(GC_SORCERER,1);
 SetMemoLevel(GC_ARCHMAGE,1);
 SetFailFn(#'MyFail);
}

