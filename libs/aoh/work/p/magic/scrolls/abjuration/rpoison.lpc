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
  if (ob->QueryAlreadyIncreased(DT_GAS) &&
      ob->QueryAlreadyIncreased(DT_POISON))
  {
    write("You cannot further increase your magic protection.\n");
    return CAST_FAIL_NOMSG;
  }
  sta=this_player()->QueryAttr("Sta")+4;
  
  if (!ob->QueryAlreadyIncreased(DT_GAS))
  {
    def=random(90)+1;
    res=random(90)+1;
    ob->SetIncrease(DT_GAS,this_player(),def,res,80*sta,"magic protection against gas");
  }
  if (!ob->QueryAlreadyIncreased(DT_POISON))
  {
    def=random(90)+1;
    res=random(90)+1;
    ob->SetIncrease(DT_POISON,this_player(),def,res,80*sta,"magic protection against poison");
  }
  return CAST_SUCCESS;
}

int MyFail()
{
int dam;
   if (Repulse(this_player(), this_player(),ST_POISON)) return CAST_REPULSE;
   Message( ({"You are poisoned.\n",
       this_player()->QueryName() + 
       " is poisoned.\n"}) );
   dam=10+random(50);
   this_player()->AddPoison(ModifyMagic(dam));
   return CAST_SUCCESS;
}

create()
 {
 ::create();
 AddSpell("poison",ST_PROTECT,100,#'MyCast,"resist poison",60);
 SetSpellDesc(
"This spell creates an invisible aura that protects you against gas\n"+
"and  poison.\n"+
"It depends on your stamina how long this spell will last.\n");
 SetSpellUsage("cast poison\n");
 SetMemoLevel("allmage",14);
 SetFailFn(#'MyFail);
 
 NoMemorize();
}

