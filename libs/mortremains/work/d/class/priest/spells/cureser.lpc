// Ilzarion.  God knows when.

#include <mudlib.h>
#include <m_spells.h>

#define COST 30
#define HEALING random(8)+random(8)+random(8)+random(8)+random(8)+random(8)+12

inherit SPELL;

int invoke_cureser (string str) {
  object target, light;
  int flag = 0;

  seteuid(getuid());

  if (!str||str=="me"||str==(string)TP->query("name")) {
    target = TP;
  } else {
      target = present(str, environment(TP));
      if (!target) {
        write("Couldn't find "+capitalize(str)+" here.\n");
        return 1;
      }
      if (!living(target)) {
        write("The target must be alive.\n");
        return 1;
      }
     flag=1;
    }

  if (invoke_spell(TP, COST)) return 0;

//Heal the target
target->receive_healing(HEALING);

// Tell the room and caster what happens...
  switch(flag){
  case 1 :  tell_object(target, TPN +
        " gestures at you and utters a strange incantation.\n"+
        "You feel a bit better!\n");
      write ("You cast cure serious wounds upon "+target->query("cap_name")+".\n");
      message("spell", 
        TPN+" gestures at "+target->query("cap_name")+
        " and utters a strange incantation.\n", environment(TP),
        ({ TP, target }) );
      break;
    default :
      write("You cast a cure serious wounds spell upon yourself.\n"+
        "You feel a bit better.\n");
      say(TPN+" utters a strange incantation.\n"+
        capitalize(subjective(TP->query("gender")))+
        " is healed for a good amount.\n");
      break;
  }


  return 1;
}
string spellcraft() {
    return (@EndSpellcraft
Cure Serious Wounds (Priest - Level IV - Healing)

Duration: instant 		Area of Effect: 1 Target
Cost: 30 TP

	This spell heals the target.
EndSpellcraft
    );
}
