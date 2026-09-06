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
  if (ob->QueryAlreadyIncreased(DT_FIRE))
  {
    write("You cannot further increase your magic protection.\n");
    return CAST_FAIL_NOMSG;
  }
  sta=this_player()->QueryAttr("Sta")+6;
  def=40+random(15);
  res=40+random(15);
  ob->SetIncrease(DT_FIRE,this_player(),def,res,80*sta,"magic protection against heat");
  return CAST_SUCCESS;
}

int MyFail()
{
int dam;
   if (Repulse(this_player(), this_player(),ST_FIRE)) return CAST_REPULSE;
   Message( ({"Your hands start to burn.\n",
       add_gen(this_player()->QueryName()) + 
       " hands start to burn.\n"}) );
   dam=10+random(10);
   dam=this_player()->Defend(ModifyMagic(dam),DT_FIRE,0);
   Message(QueryCastDamage(dam));
   return CAST_SUCCESS;
}

create()
 {
 ::create();
 AddSpell("heat",ST_PROTECT,50,#'MyCast,"resist heat",30);
 SetSpellDesc(
"This spell creates an invisible aura that protects you against heat.\n"+
"It depends on your stamina how long this spell will last.\n");
 SetSpellUsage("cast heat\n");
 SetMemoLevel("allmage",8);
 SetFailFn(#'MyFail);
}

