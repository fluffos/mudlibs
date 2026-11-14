/* Increase Stats of a player written by Softbyte 4/6/95         */
/* You only need to change STAT and LONGSTAT to change the spell */

#include <magic.h>
#include <guild.h>
#include <combat.h>
#include <moving.h>
#include <secure/wizlevels.h>
inherit "/obj/scroll";

#define STAT "Con"
#define LONGSTAT "constitution"

#define MIN_POWER  70    /* EP needed for this spell */

int MyCast(string str,string spname,int backfire) 
{
object whom;
object ob;
int dura;
int power;
  if (backfire) return CAST_FAIL_NOMSG;
  if (!str) { write("Spell used in a wrong way!\n"); return CAST_FAIL_NOMSG; }
  whom=present(str,environment(this_player()));
  if (!whom) {write("I can't see "+str+" here!\n"); return CAST_FAIL_NOMSG; }
  if ( (whom==this_player())&&(!IS_WIZARD(this_player())) )
  {
    write("You cannot apply this spell on yourself.\n");
    return CAST_FAIL_NOMSG;
  }
  seteuid(getuid(this_object()));
  ob=present(INCREASER,whom);
  if (!ob)
  {
     ob=clone_object(MAGIC_OBJ_DIR+"increaser");
     if ( !ob || ME_OK!=ob->move(whom,M_SILENT))
     {
       write("Error: Cannot clone protection.\n");
       return CAST_FAIL_NOMSG;
     }
  }
  if (ob->QueryAlreadyIncreased(STAT))
  {
    write("You cannot further increase "+
        add_gen(whom->QueryName())+" "+LONGSTAT+".\n");
    return CAST_FAIL_NOMSG;
  }
  power=this_player()->QueryAttr("EP");
  if (power<MIN_POWER) 
  {
    write("You have not enough endurance points for this spell.\n");
    return CAST_FAIL_NOMSG;
  }
  /* It is intended to use a fixed amount of EP ! */
  this_player()->SetAttr("EP",power-MIN_POWER);  
  /* NO repulse */

  dura=750+40*this_player()->QueryAttr("Wis");   /* It lasts dura sec */
  ob->SetIncrease(STAT,whom,1,3,dura,LONGSTAT);
  Message("You increase the "+LONGSTAT+" of "+whom->QueryName()+".\n");
  return CAST_SUCCESS;

}
int MyFail() 
{
int dam;
     if (Repulse(this_player(),this_player(),ST_PSYCHO)) return 1;
     Message(({"You hurt yourself!\n",
         this_player()->QueryName()+" cries in panic.\n"}));
     dam=ModifyMagic(35);
     dam=this_player()->Defend(dam,DT_PSYCHO,0);
     return CAST_SUCCESS;
}
create()
{
 ::create();
 AddSpell("inc"+lower_case(STAT),ST_CHANGE,70,#'MyCast,"increase "+LONGSTAT,60);
 SetSpellDesc(
"This spell will temporarily increase the "+LONGSTAT+" of someone.\n"+
"It cannot be casted on yourself.\n");
 SetSpellUsage("cast inc"+lower_case(STAT)+" <player>\n");
 SetMemoLevel(GC_CONJURER,18);
 SetMemoLevel(GC_SORCERER,18);
 SetMemoLevel(GC_ARCHMAGE,18);
 
 SetFailFn(#'MyFail);
}

