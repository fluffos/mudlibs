/* Adapted and improved by Softbyte 1995 */
#include <magic.h>
#include <guild.h>
#include <combat.h>
inherit "/obj/scroll";

int MyCast(string str)
{
object gas, mon;
object *ene;
mixed *defences;
int def,poison;
int i,dam;
  if (str)
  {
   if (str!=this_player()->QueryName())
      write("You cannot use an argument with this spell.\n");
    return CAST_FAIL_NOMSG;
  }
  ene=all_inventory(environment(this_player()));
  for (i=0;i<sizeof(ene);i++)
  {
     mon=ene[i];
     if (living(mon) && mon!=this_player() )
       Message(({mon->QueryName()+" is envelopped in a cloud of poison gas.\n",
	    "A cloud of gas emerges from "+add_gen(this_player()->QueryName())+
	    " fingers and envelopes "+mon->QueryName()+".\n",
            ({mon}),
            ({"You are poisoned by "+this_player()->QueryName()+".\n"}) }));
     if (living(mon) && mon!=this_player() )
     {
       if (random(3)==0) /* poison every 3rd monster */
       {
         poison=50+random(75);
         if (mon->QueryIsPlayer()) poison=25+random(25);
         if (Repulse(mon, this_player())) continue;
         defences=mon->QueryDefences();
         if (defences && sizeof(defences)>=DT_POISON)
           def=defences[DT_POISON];
         else def=0;
         poison-=5*def; 
         if (poison<=0) continue;
         mon->AddPoison(poison);
        }
        if (mon->QueryIsNPC()) /* kill only NPCs */
        {
          dam=10+random(40);
          dam=mon->Defend(ModifyMagic(dam),DT_POISON,0);
          if (mon) Message(QueryCastDamage(dam,mon));
        }
      } /* end if */
  }
  return CAST_SUCCESS;
}

int MyFail() {
   if (Repulse(this_player(),this_player())) return CAST_REPULSE;
   Message( ({"You got poisoned.\n",
           this_player()->QueryName()+" gets poisoned.\n"}) );
   this_player()->AddPoison(50);
   return CAST_SUCCESS;
}
create()
{
 ::create();
 AddSpell("cloud",ST_POISON,130,#'MyCast,"poison gas cloud",40);
 SetSpellDesc(
"This spell will create a cloud of poisonous gas. Everybody except\n"+
"the caster will be poisoned if he/she is not resistant against poison.\n"+
"The spell does up to 50 HP damage plus potential poisoning.\n");
 SetSpellUsage("cast cloud\n");
 SetMemoLevel(GC_CONJURER,18);
 SetMemoLevel(GC_ARCHMAGE,18);
 SetFailFn(#'MyFail);
}

