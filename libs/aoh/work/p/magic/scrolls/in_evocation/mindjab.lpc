/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
#include <combat.h>
inherit "/obj/scroll";
#define TP this_player()
#define HIM this_player()->QueryObjective()
#define HE this_player()->QueryPronoun()
#define HIS this_player()->QueryPossessive()

int QueryCost()
{
int res;
  res= 20+2*this_player()->QueryLevel();
  if (res>65) res=65;
  return res;
}
int MyCast(string str) 
{
object wolf;
int dam;
  if (!str) wolf=GetEnemy(this_player());
  else wolf=present(str, environment(this_player()));
  if (!wolf) {
     write("That's not here.\n");
     return CAST_FAIL_NOMSG;
  }
  if ((wolf->QueryIsNPC()==0) && (wolf->QueryIsPlayer()==0)) {
     write("You can't cast it on that!\n"); 
     return CAST_FAIL_NOMSG;
  }
  if (wolf->QueryIsPlayer()) LogCast(this_player(),wolf);
  if (Repulse(wolf, this_player())) return CAST_REPULSE;
  Message( ({
  "You press your fingers against your temples and concentrate. Suddenly your\n"+
  "eyes start pulsating with cold blue light. You look at "+wolf->QueryName()+"\n"+
  "and two bright rays shoot out of your eyes towards "+wolf->QueryObjective()+
  ", penetrating "+wolf->QueryPossessive()+" brain.\n"+
  "Then the glow fades and your vision returns back to normal.\n",
  TP->QueryName()+
  " presses "+HIS+" fingers against "+HIS+" temples and concentrates. Suddenly "+HIS+"\n"+
  "eyes start pulsating with cold blue light. Then "+HE+" look at "+wolf->QueryName()+"\n"+
  "and two bright rays shoot out of "+HIS+" eyes towards "+wolf->QueryName()+
  ", penetrating "+add_gen(wolf->QueryName())+" brain.\n"+
  "Then the glow fades and "+add_gen(TP->QueryName())+" eyes switch back to normal.\n"}) );
  dam = (random(4) + 5) * this_player()->QueryLevel();
  if (dam > 120) dam = 120;
  dam=wolf->Defend(ModifyMagic(dam), DT_PSYCHO, 0);
  if (wolf) Message(QueryCastDamage(dam,wolf));
  return CAST_SUCCESS;
}

int MyFail() 
{
int dam;
  if (Repulse(this_player(),this_player())) return CAST_REPULSE;
  this_player()->SetSmell(this_player()->QueryName()+
        " smells of burned flesh.\n");
  Message( ({
  "You press your fingers against your temples and concentrate. Suddenly your\n"+
  "eyes start pulsating with cold blue light. But as you try to release the\n"+
  "energy you feel cold fire explode in your head, devouring your brain, and\n"+
  "sending violent waves of pain througout your entire body. You sink to your\n"+
  "knees screaming in agony.\n",
  TP->QueryName()+
  " presses "+HIS+" fingers against "+HIS+" temples and concentrates. "+capitalize(HIS)+"\n"+
  "eyes start pulsating with cold blue light. Suddenly a flash of cold light\n"+
  "explodes around "+HIS+" head, sending violent waves of pain througout "+HIS+"\n"+
  "body. "+TP->QueryName()+" sinks to "+HIS+" knees screaming in agony.\n"}) );

  dam=20+(random(4)+2)*this_player()->QueryLevel();
  dam=this_player()->Defend(ModifyMagic(dam), DT_PSYCHO, 0);
  Message(QueryCastDamage(dam));
  return CAST_SUCCESS;
}
void create() 
{
 ::create();
 AddSpell("jab",ST_PSYCHO,#'QueryCost,#'MyCast,"mind jab",35);
 SetSpellDesc(
"This spell will produce an powerful jolt of mental energy that scrambles\n\
the brain of your opponent. It will do a damage of up to 9*level HP mental\n\
damage.\n\
It will cost you 20 plus 2*level spellpoints to cast this spell.\n\
The damage the spell does is limited to a maximum of 120.\n");
 SetSpellUsage("cast jab <target>\n");
 SetMemoLevel(GC_SORCERER,15);
 SetMemoLevel(GC_ARCHMAGE,15);
 
 SetFailFn(#'MyFail);
}

