/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
inherit "/obj/scroll";

int MyCast(string str) 
{
object cloak;
  if (str)
  {
   if (str!=this_player()->QueryName())
      write("You cannot use an argument with this spell.\n");
    return CAST_FAIL_NOMSG;
  }
  Message( ({"You materialize a cap.\n",
     this_player()->QueryName()+" materializes a cap out of thin air.\n"}) );
  seteuid(getuid(this_object()));
  cloak=clone_object(MAGIC_OBJ_DIR "wizcap");
  cloak->move(this_player());
  this_player()->command_me("wear cap");
  return CAST_SUCCESS;
}

int MyFail() 
{
int dam;
   if (Repulse(this_player(),this_player(),ST_ZAP)) return CAST_REPULSE;
   Message( ({"A big club appears and hits you hard!\n",
       "A big club appears and hits "+this_player()->QueryName()+
   " hard.\n"}) );
   dam=10+random(20);
   dam=this_player()->Defend(ModifyMagic(dam),DT_ZAP,0);
   Message(QueryCastDamage(dam));
   return CAST_SUCCESS;
}
void create() 
{
 ::create();
 AddSpell("wizcap",ST_CREATE,30,#'MyCast,"wizard's cap",10);
 SetSpellDesc(
"This spell creates a wizard's cap for you.\n"+
"It depends on your stamina how long this spell will last.\n");
 SetSpellUsage("cast wizcap\n");
 SetMemoLevel(GC_CONJURER,2);
 SetMemoLevel(GC_ARCHMAGE,2);
 SetFailFn(#'MyFail);
}

