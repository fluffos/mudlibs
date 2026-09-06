/* Blind Monster written by Softbyte 4/6/95 */
/* Adapted and improved by Softbyte 1995 */

#include <magic.h>
#include <guild.h>
inherit "/obj/scroll";

int MyCast(string str) 
{
object whom;
int dura;
  if (!str) whom=GetEnemy(this_player());
  else whom=present(str,environment(this_player()));
  if (!whom)
  {write("I can't see that monster here!\n"); return CAST_FAIL_NOMSG; }
  if (Repulse(whom,this_player())) return CAST_REPULSE;

  dura=random(this_player()->QueryDex()+3*this_player()->QueryInt());
  dura=12+dura;
  if (dura>45) dura=45;
  dura=ModifyMagic(dura);
  whom->SetCombatDelay(dura, "You are blinded.\n");  
  Message( ({"You have blinded "+whom->QueryShort()+".\n",
      this_player()->QueryName()+" has blinded "+whom->QueryShort()+".\n"}) );
  return CAST_SUCCESS;
}
int MyFail() 
{
     if (Repulse(this_player(),this_player())) return CAST_REPULSE;
     Message( ({"You blinded yourself!\n",
         this_player()->QueryName()+" is blinded.\n"}));
     this_player()->SetCombatDelay(6,"You are blinded.\n");  
     return CAST_SUCCESS;
}
create()
{
 ::create();
 AddSpell("blind",ST_INFLUENCE,40,#'MyCast,"blind monster",30); 
 SetSpellDesc(
"This spell will blind monster for a while. How long the monster cannot\n"+
"attack you depends on your Int and Dex.\n"+
"You have to specify which monster should be attacked.\n");
 SetSpellUsage("cast blind <monster>\n");
 SetMemoLevel("allmage",11);
 SetFailFn(#'MyFail);
}

