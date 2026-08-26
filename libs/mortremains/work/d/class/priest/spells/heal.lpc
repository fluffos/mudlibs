

#include <mudlib.h>
#include <m_spells.h>



int invoke_heal (string str) {
  object target, light, ob;
  int COST, flag = 0;

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
  
COST = (target->query("max_hp") - target->query("hit_points")) ;
  if (COST < 1) {
    write("They are fully healed already!\n");
    return 1;
  }

  if (!TP->invoke_spell(COST)) {
    write("You cannot muster the energies to heal that much damage.\n");
    return 1;
  }

//Heal the target

ob = present("#FEEBLEMIND#", target);
if(ob) ob->remove();
ob = present("#WOUND_OB#", target);
if(ob) ob->remove();
target->receive_healing(COST);

// Tell the room and caster what happens...
  switch(flag){
  case 1 :  tell_object(target, TPN +
        " gestures at you and utters a strange incantation.\n"+
        "You feel a bit better!\n");
      write ("You cast heal upon "+target->query("cap_name")+".\n");
      message("spell", 
        TPN+" gestures at "+target->query("cap_name")+
        " and utters a strange incantation.\n", environment(TP),
        ({ TP, target }) );
      break;
    default :
      write("You cast a heal spell upon yourself.\n"+
        "You feel much better.\n");
      say(TPN+" utters a strange incantation.\n"+
        objective(TP->query("gender"))+" is healed.\n");
      break;
  }


  return 1;
}
string spellcraft() {
    return (@EndSpellcraft
Heal (Priest - Level VI - Healing)

Duration: instant 		Area of Effect: 1 Target
Cost: variable

	This spell heals the target of all damage, 
wounds and infirmaries. The spell will fail if
the physical wounds of the target exceed the priest's
theurgy points.
EndSpellcraft
    );
}
