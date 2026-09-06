/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <combat.h>
#include <guild.h>
inherit "/obj/scroll";

/* Return the cost in SP for casting this spell: Set by Addspell */
int QueryCost()
{
  return(5+this_player()->QueryLevel());
}

/* Main cast function, set by AddSpell, return values depend on succcess */
/* "str" is the argument the caster gave. "spname" is the castname of    */
/* the spell to allow collecting similar spells in one function.         */
/* "backfire" is a flag (0,1) indicating whether the spell got backfired */
/* (1). The action of this function should then be redirected against the*/
/* caster.                                                               */
/* The return values CAST_XXXX are defined in magic.h and should be      */
/* obeyed to allow proper handling of the spell.                         */
int MyCast(string str,string spname,int backfired)
{
string name;
object wolf;
int dam;
/* GetEnemy(void|object) returns a random NPC in the environment of */
/* the caster.                                                      */
  if (backfired) wolf=TP;
  else if (!str) wolf=GetEnemy(this_player()); /* draw random enemy */
  else wolf=present(str, environment(this_player()));

  if (!wolf)
  {
     write("That's not here.\n"); 
     return CAST_FAIL_NOMSG;
  }
  name=wolf->QueryName();
  if (!wolf->QueryIsNPC() && !wolf->QueryIsPlayer()) {
     write("You can't cast it on that!\n"); return CAST_FAIL_NOMSG; }

/* LogCast(caster, target) logs an aggression in an logfile               */
/* if target==caster the use will not be logged...                        */
  if (wolf->QueryIsPlayer()) LogCast(this_player(),wolf); /* Aggressor    */

/* It is important to call Repulse(target,caster,[optinal args]) to check */
/* whether the target is resistant against that type of spell. if it is so*/
/* automatic backfire handling will take place and fire the spell back at */
/* the caster with half its intensity.                                    */
  if (Repulse(wolf, this_player())) return CAST_REPULSE;  /* was resistant*/

/* One need not use Message(...). It simply collects a couple of writes   */
/* and says in one function call. For a exact description refer to the    */
/* manpage about "caster".                                                */
  Message(({"A burst of arcanic fires shoots at "+wolf->QueryName()+".\n",
            "From "+add_gen(this_player()->QueryName())+
            " hands shoots a burst of fire at "+wolf->QueryName()+".\n"}) );

  dam = random(4) * this_player()->QueryLevel()+5;

/* To do damage one should us the /obj/living function Defend(...) to    */
/* take the targets natural defences into account. The damage should also*/
/* be processed by int ModifyMagic(int). It will usually not change the  */
/* parameter, but halves it e.g. in the case of backfiring automatically */
  dam=wolf->Defend(ModifyMagic(dam), DT_FIRE, 0);

/* QueryCastDamage(int damage,object target,[optional args]) returns    */
/* a MESSAGE structure containing a message depending on the damage done*/
/* and the type of the damage (fire, water,...).                        */
  if (wolf) Message(QueryCastDamage(dam,wolf));  /* write damage string */
  return CAST_SUCCESS;
}

/* Spell failed due to lack of Wisdom. Function of obj/scroll */
int MyFail() {
int dam;
  if (Repulse(this_player(), this_player())) return CAST_REPULSE;
  Message(({"A burst of arcanic fires hits you.\n",
            "A burst of arcanic fires hits "+
               this_player()->QueryName()+".\n"}) );
  dam = (1+random(3)) * this_player()->QueryLevel();
  dam=this_player()->Defend(ModifyMagic(dam), DT_FIRE, 0);
  Message(QueryCastDamage(dam));  /* write damage string */
  return CAST_SUCCESS;
}
void create() {
 ::create();

/* Main function call to add a spell: "fire" is the short name     */
/* used for casting. ST_FIRE is the type of the spell as found in  */
/* magic.h. #'QueryCost is a function or integer number giving the */
/* cost in SP when casting the spell. #'MyCast is the function     */
/* which is called when the cast is successful. Most checks have   */
/* been done until then. "arcanic fire" is the long/real name of   */
/* the spell as used in the descriptions. 25 is the failchance of  */
/* the spell in percent. This is related to the WISDOM             */
/* The (last argument) the backfire chance will be calculated      */
/* automatically by /obj/scroll.c                                  */
  AddSpell("fire",ST_FIRE,#'QueryCost,#'MyCast,"arcanic fire",25);

/* Optional function to set the description of the scroll. One gets*/
/* it with "read scroll" or if the description mode is enabled     */
/* (default: disabled), with "describe scroll"                     */
  SetSpellDesc(
  "This spell will produce an fiery burst of fire doing a damage of up\n"+
  "to 3*level HP fire damage.\n"+
  "The cost of this spell is 5 SP plus your level.\n");

/* Optional: writes the given line and in addition some data about */
/* the scroll, i.e. failchange, memorizable, castable, ...         */
/* if you don't want this, just add text to the SpellDesc() which  */
/* gets output without changes                                     */
 SetSpellUsage("cast fire <target>\n");

/* The following functions allow or forbid the casting and memorizing */
/* of this scroll. Casting and memorizing are allowed from the given  */
/* Level onwards. The memorizing stuff has to be handled by a guildobj*/
/* which can query 'CanMemo()'                                        */
  /* Default is: ForbidMemo("all") and SetCastLevel("all",1) */
  SetMemoLevel(GC_SORCERER,1);
  SetMemoLevel(GC_ARCHMAGE,1);
  /* equiv. to SetMemoLevel ( ([GC_SORCERER:1,GC_ARCHMAGE:1)] );

/* This function is called if the caster fails to cast the spell */
/* due to lack of WISDOM                                         */
/* it is an extension of NotifySpellFail                         */
  SetFailFn(#'MyFail);
}

