#include <magic.h>
#include <guild.h>
#include <secure/wizlevels.h>
#include <properties.h>
#include <moving.h>
inherit "/obj/scroll";
#define TP this_player()
object last, envi;
int power;

int MyCast(string str) {
  if (str)
  {
    write("You cannot use an argument with this spell.\n");
    return CAST_FAIL_NOMSG;
  }
  if (present("_xinvis",TP))
  {
    write("The spell is still active.\n");
    return CAST_FAIL_NOMSG;
  }
  /* We are no longer a scroll  ! */
  SetIds( ({"_xinvis","_detectinvis","scroll2"}) );
 power=this_player()->QueryAttr("Sta")+6;
 power=power*32; /* 8x4 */

  last=this_player();
  Message("You begin to see sharper now!\n");
  call_out("find", 4);
  SetWeight(0);
  SetShort(0);
  ForbidCast();
  move(this_player(),M_NOCHECK);
  SetNoDrop();
  return CAST_SUCCESS;
}

int MyFail() {
    write("You detect that your shoes are open.\n");
    return CAST_SUCCESS;
}

void find() {
  object inv;
  string name;
  power-=1;
  if (power<=0) {
     write("The Detect Invisibility Spell is now powerless.\n");
     remove_call_out("find");
     remove();
     return; 
  }
  if(!(envi=environment(TP))) return 0;
  if (envi!=last) {
     last=envi;
     inv=first_inventory(envi);
     while (inv) 
     {
	 if (!inv->QueryShort() || inv->QueryInvis() )
         {
           if (living(inv))
           {
	      name=capitalize( (inv->QueryName()||"someone") );
	      if (name=="Someone") name=capitalize(inv->QueryRealName());
	      if (!IS_WIZARD(inv)) write("Invisible here: "+name+".\n");
              if (inv->QueryIsNPC()) inv->SetShort(name);
           }
	   else
           {
              if (inv->QueryName())
              { 
                 inv->SetShort(inv->QueryName());
                 write("Invisible item: "+inv->QueryName()+".\n");
              }
              else if (inv->Query(P_INFO))
                 write("Invisible item: "+inv->Query(P_INFO)+".\n");
           }
	}
	inv=next_inventory(inv);
     }
  }
  call_out("find",4);
}

int query_power() { return power; }

void create() {
 ::create();
 AddSpell("detect",ST_KNOW,20,#'MyCast,"detect invisibility",35);
 SetSpellDesc(
"This spell will allow you to find invisible items for a while.\n\
It depends on your stamina how long this spell will last.\n");
 SetSpellUsage("cast detect\n");
 SetMemoLevel(GC_SORCERER,3);
 SetMemoLevel(GC_ARCHMAGE,3);
 SetFailFn(#'MyFail);

 NoDestruct();
 power=this_player()->QueryAttr("Sta")+6;
 power=power*32; /* 8x4 */
}

