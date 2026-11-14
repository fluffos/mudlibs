/* Rewritten by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
#include <combat.h>
#include <moving.h>
inherit "/obj/scroll";

int MyCast(string str)
{
object ob;
int sta;
int def,res;
  if (str)
  {
   if (str!=this_player()->QueryName())
      write("You cannot use an argument with this spell.\n");
    return CAST_FAIL_NOMSG;
  }
  seteuid(getuid(this_object()));
  ob=present(DEFENDER,this_player());
  if (!ob)
  {
     ob=clone_object(MAGIC_OBJ_DIR+"defender");
     if ( !ob || ME_OK!=ob->move(this_player(),M_SILENT))
     {
       write("Error: Cannot clone protection.\n");
       return CAST_FAIL_NOMSG;
     }
  }
  if (ob->QueryAlreadyIncreased(DT_COLD))
  {
    write("You cannot further increase your magic protection.\n");
    return CAST_FAIL_NOMSG;
  }
  sta=this_player()->QueryAttr("Sta");
  def=30+random(30);
  res=25+random(30);
  ob->SetIncrease(DT_COLD,this_player(),def,res,100*sta,"magic protection against cold");
  return CAST_SUCCESS;
}

int MyFail()
{
int dam;
   if (Repulse(this_player(), this_player(),ST_COLD)) return CAST_REPULSE;
   Message( ({"You suddenly get a bad cold.\n",
       this_player()->QueryName() + 
       " suddenly gets a bad cold.\n"}) );
   dam=20+random(20);
   dam=this_player()->Defend(ModifyMagic(dam),DT_COLD,0);
   Message(QueryCastDamage(dam));
   return CAST_SUCCESS;
}

create()
 {
 ::create();
 AddSpell("cold",ST_PROTECT,50,#'MyCast,"resist cold",40);
 SetSpellDesc(
"This spell creates an invisible aura that protects you against cold.\n"+
"It depends on your stamina how long this spell will last.\n");
 SetSpellUsage("cast cold\n");
 SetMemoLevel("allmage",12);
 SetFailFn(#'MyFail);
}

