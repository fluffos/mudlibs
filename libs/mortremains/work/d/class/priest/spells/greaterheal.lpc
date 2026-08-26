

#include <mudlib.h>
#include <m_spells.h>



int invoke_greaterheal (string str) {
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
  
COST = 60 ;
 

  if (!TP->invoke_spell(COST)) {
    write("You cannot muster the energies to cast that spell.\n");
    return 1;
  }

//Heal the target

ob = present("#FEEBLEMIND#", target);
if(ob) ob->remove();
ob = present("#WOUND_OB#", target);
if(ob) ob->remove();
target->receive_healing(2500);

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
