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
  if (ob->QueryAlreadyIncreased(DT_PSYCHO) &&
      ob->QueryAlreadyIncreased(ST_INFLUENCE))
  {
    write("You cannot further increase your magic protection.\n");
    return CAST_FAIL_NOMSG;
  }
  sta=this_player()->QueryAttr("Sta")+4;
  
  if (!ob->QueryAlreadyIncreased(DT_PSYCHO))
  {
    def=50;
    res=50;
    ob->SetIncrease(DT_PSYCHO,this_player(),def,res,100*sta,
           "magic protection against mental attacks");
  }
  if (!ob->QueryAlreadyIncreased(ST_INFLUENCE))
  {
    def=0;
    res=50;
    ob->SetIncrease(ST_INFLUENCE,this_player(),def,res,100*sta,
        "magic protection against mental influences");
  }
  return CAST_SUCCESS;
}

int MyFail()
{
int dam;
   if (Repulse(this_player(), this_player(),ST_PSYCHO)) return CAST_REPULSE;
   Message( ({"You are hit by ma magic missile.\n",
       this_player()->QueryName() + 
       " is hit by a magic missile.\n"}) );
   dam=20+random(50);
   dam=this_player()->Defend(ModifyMagic(dam),DT_PSYCHO,0);
   Message(QueryCastDamage(dam));
   return CAST_SUCCESS;
}

create()
 {
 ::create();
 AddSpell("rpsycho",ST_PROTECT,70,#'MyCast,"resist psycho",60);
 SetSpellDesc(
"This spell creates an invisible aura that protects you against\n"+
"mental influences and attacks.\n"+
"It depends on your stamina how long this spell will last.\n");
 SetSpellUsage("cast rpsycho\n");
 SetMemoLevel(GC_SORCERER,16);
 SetMemoLevel(GC_ARCHMAGE,16);
 
 SetFailFn(#'MyFail);
 
 NoMemorize();
}

