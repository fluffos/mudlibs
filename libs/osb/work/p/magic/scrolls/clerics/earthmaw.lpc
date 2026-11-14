#include <magic.h>
#include <guild.h>
#include <moving.h>
#include <combat.h>
inherit "/obj/scroll";


int MyCast(string str) 
{
object *enem;
int i;
  if (str) 
  {
    if (str==this_player()->QueryName()) return CAST_FAIL_NOMSG;
    write("You cannot give an argument to this spell.\n");
    return CAST_FAIL_NOMSG;
  } 
  enem=this_player()->QueryEnemies()||({});
  if (0==sizeof(enem))
  {
    write("You have no enemies.\n");
    return CAST_FAIL_NOMSG;
  }
  for (i=0;i<sizeof(enem);i++)
  {
    if (enem[i]->QueryIsNPC() &&
       environment(enem[i])==environment(this_player()) )
    {
      if (!Repulse(enem[i], this_player())) 
      {
        if (ME_OK==enem[i]->move("/d/woodland/common/lake/earthmaw", M_SILENT))
          Message( ({enem[i]->QueryName()+" disappears in a hole.\n",
	      "The earth swallows "+enem[i]->QueryName()+".\n"}) );
        else Message(enem[i]->QueryName()+" is resistant against that spell.\n");
      } 
    }
    else write(capitalize((enem[i]||"someone"))+" cannot be attacked.\n");
  }/* next i */
  return CAST_SUCCESS;
}

int MyFail() 
{
int dam;
   if (Repulse(this_player(),this_player())) return CAST_REPULSE;
   this_player()->SetSmell(this_player()->QueryName()+
       " smells of burned hair. "+this_player()->QueryPronoun()+
       " got hit by a magic missile.\n");
   Message( ({"You get hit by a magic missile!\n",
        this_player()->QueryName()+" get hit by a magic missile!\n"}) );
   dam=50;
   dam=this_player()->Defend(ModifyMagic(dam), DT_PSYCHO, 0);
   Message(QueryCastDamage(dam));
   return CAST_SUCCESS;
}
create() 
{
 ::create();
 AddSpell("maw",ST_ZAP,150,#'MyCast,"earth maw",66);
 SetSpellDesc(
"This spell let the earth swallow every monster that attackes you.\n");
 SetSpellUsage("cast maw\n");
 SetMemoLevel(GC_SORCERER,18);
 SetMemoLevel(GC_ARCHMAGE,18);
 SetFailFn(#'MyFail);

 NoMemorize();
}
