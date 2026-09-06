/* Rewritten by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
#include <combat.h>
#include <properties.h>
#include <moving.h>
inherit "/obj/scroll";

object owner;

gillaway()
{
int oldprop;
  if (!owner) return;
  oldprop=owner->Query( P_WATERBREATHING);
  /* in case of not properly coded items */
  if (oldprop<=0)
     owner->Set(P_WATERBREATHING,0);
  else
  {
    if (oldprop==1) tell_object(owner,"Your gills vanish.\n");
    owner->Set(P_WATERBREATHING,oldprop-1);
  }
}

remove()
{
 gillaway(); 
 return ::remove();
}
int MyCast(string str)
{
object ob;
int oldprop;
int power;
  if (str)
  {
   if (str!=this_player()->QueryName())
      write("You cannot use an argument with this spell.\n");
    return CAST_FAIL_NOMSG;
  }
  oldprop=this_player()->Query( P_WATERBREATHING);
  /* in case of not properly coded items */
  if (oldprop<0)
  { 
     oldprop=0;
     this_player()->Set(P_WATERBREATHING,0);
  }
  if (oldprop)
  {
      write("Seems you can already breath under water.\n");
    return CAST_FAIL_NOMSG;
  }
  if (present("_xbreath",this_player()))
  {
    write("The spell is still active.\n");
    return CAST_FAIL_NOMSG;
  }
  /* We are no longer a scroll  ! */
  SetIds( ({"_xbreath"}) );

  power=this_player()->QueryAttr("Sta")+3;
  power=power*80;
  this_player()->Set(P_WATERBREATHING,oldprop+1);
  Message(({ "You begin to develop gill. Seems you can breath under water now.\n",
  this_player()->QueryName()+" has gills now.\n"}) );
  call_out("remove",power);
  SetWeight(0);
  SetShort(0);
  ForbidCast();
  move(this_player(),M_NOCHECK);
  SetNoDrop();
  return CAST_SUCCESS;
}

int MyFail()
{
int dam;
   if (Repulse(this_player(), this_player(),DT_NOAIR)) return CAST_REPULSE;
   Message( ({"Suddenly there is some salty water in your lung. You start to choke.\n",
       this_player()->QueryName() + " starts to choke.\n"}) );
   dam=10+random(60);
   dam=this_player()->Defend(ModifyMagic(dam),DT_NOAIR,0);
   Message(QueryCastDamage(dam));
   return CAST_SUCCESS;
}

create()
 {
 ::create();
 AddSpell("resist",ST_PROTECT,50,#'MyCast,"breath under water",30);
 SetSpellDesc(
"This spell allow you to breathe under water.\n"+
"It depends on your stamina how long this spell will last.\n");
 SetSpellUsage("cast resist\n");
 SetMemoLevel(GC_CONJURER,13);
 SetMemoLevel(GC_ARCHMAGE,13);
 
 SetFailFn(#'MyFail);

 NoMemorize();
 NoDestruct();
 owner=0;
}

