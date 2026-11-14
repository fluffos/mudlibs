/* Written by Softbyte 1995 */
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
  if (ob->QueryAlreadyIncreased(DT_ACID))
  {
    write("You cannot further increase your magic protection.\n");
    return CAST_FAIL_NOMSG;
  }
  sta=this_player()->QueryAttr("Sta");
  def=30+random(30);
  res=25+random(30);
  ob->SetIncrease(DT_ACID,this_player(),def,res,100*sta,"magic protection against acid");
  return CAST_SUCCESS;
}

int MyFail()
{
int dam;
   if (Repulse(this_player(), this_player(),ST_ACID)) return CAST_REPULSE;
   Message( ({"You are burned by acid.\n",
       this_player()->QueryName() + 
       " s burned by bubbling acid.\n"}) );
   dam=20+random(20);
   dam=this_player()->Defend(ModifyMagic(dam),DT_ACID,0);
   Message(QueryCastDamage(dam));
   return CAST_SUCCESS;
}

create()
 {
 ::create();
 AddSpell("racid",ST_PROTECT,50,#'MyCast,"resist acid",60);
 SetSpellDesc(
"This spell creates an invisible aura that protects you against acid.\n"+
"It depends on your stamina how long this spell will last.\n");
 SetSpellUsage("cast racid\n");
 SetMemoLevel(GC_CONJURER,15);
 SetMemoLevel(GC_ARCHMAGE,15);
 
 SetFailFn(#'MyFail);

 NoMemorize();
}

