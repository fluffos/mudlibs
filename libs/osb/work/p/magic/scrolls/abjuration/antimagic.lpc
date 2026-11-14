/* Rewritten by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
#include <moving.h>
inherit "/obj/scroll";

int MyCast(string str)
{
object ob;
int sta;
  if (str)
  {
   if (str!=this_player()->QueryName())
      write("You cannot use an argument with this spell.\n");
    return CAST_FAIL_NOMSG;
  }
  seteuid(getuid(this_object()));
  ob=present(INCREASER,this_player());
  if (!ob)
  {
     ob=clone_object(MAGIC_OBJ_DIR+"increaser");
     if ( !ob || ME_OK!=ob->move(this_player(),M_SILENT))
     {
       write("Error: Cannot clone protection.\n");
       return CAST_FAIL_NOMSG;
     }
  }
  if (ob->QueryAlreadyIncreased("MagicDefence"))
  {
    write("You cannot further increase your magic protection.\n");
    return CAST_FAIL_NOMSG;
  }
  sta=this_player()->QueryAttr("Sta");
  ob->SetIncrease("MagicDefence",this_player(),50,90,50*sta,"magic defence");
  return CAST_SUCCESS;
}

int MyFail()
{
int dam;
   if (Repulse(this_player(), this_player()),ST_COLD) return CAST_REPULSE;
   Message( ({"You suddenly get a bad cold.\n",
       this_player()->QueryName() + 
       " suddenly gets a bad cold.\n"}) );
   dam=20+random(20);
   dam=this_player()->Defend(ModifyMagic(dam),DT_COLD,0);
   return CAST_SUCCESS;
}
create()
{
 ::create();
 AddSpell("anti",ST_PROTECT,70,#'MyCast,"anti magic",60);
 SetSpellDesc(
"This spell creates an invisible aura that protects you against all magic.\n"+
"It depends on your stamina how long this spell will last.\n");
 SetSpellUsage("cast anti\n");
 SetMemoLevel("allmage",13);
 SetFailFn(#'MyFail);
}

