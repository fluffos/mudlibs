/*
** File:  light.c
** Purpose: 1st-level alteration spell.
** Duration About 1.5 minutes per level.
** Cost:  9 SP
** Credits:
**   21 Jun 96   Chronos@Against the Fall of Darkness wrote the file.
**   23 Jul 97   Cyanide@Nightfall's Keep borrowed and improved the spell
**                from a now-defunct mud.
*/

#include <mudlib.h>
#include <m_spells.h>

#define COST 9

int invoke_light (string str) {
  object target, light;
  int flag = 0;

  seteuid(getuid());

  if (!str||str=="me"||str==(string)TP->query("name")) {
    target = TP;
  } else {
    if (str == "here") {
      target = environment(TP);
      flag = 1;
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
      flag = 2;
    }
  }

  if (present("#LIGHT_OBJECT#", target)) {
    if (flag==2) write("That person already has a light effect.\n");
    if (flag==1) write("There is already a light spell in the room.\n");
    if (!flag && present("#LIGHT_OBJECT#", TP)) 
      write("You already have a light spell upon you.\n");
    return 1;
  }

  if (!TP->invoke_spell(COST)) {
    write("You cannot muster the energies to cast that spell.\n");
    return 1;
  }

// Clone the light object.
  light = clone_object(M_OBJ(light_ob));  
  if (!light) {
    write("Your spell fizzles. Notify Cyanide.\n");
    return 1;
  }

// Tell the room and caster what happens...
  switch (flag) {
    case 1 :
      write("You cast light upon the room.\n");
      say(TPN+" utters a strange incantation.\n");
      tell_room(environment(TP), "The room suddenly gets brighter.\n");
      break;
    case 2 : 
      tell_object(target, TPN +
        " gestures at you and utters a strange incantation.\n"+
        "An aura of light springs up around you!\n");
      write ("You cast light upon "+target->query("cap_name")+".\n");
      message("spell", 
        TPN+" gestures at "+target->query("cap_name")+
        " and utters a strange incantation.\n", environment(TP),
        ({ TP, target }) );
      break;
    default :
      write("You cast a light spell upon yourself.\n"+
        "An aura of light springs up around you.\n");
      say(TPN+" utters a strange incantation.\nAn aura of light springs "+
        "up around "+objective(TP->query("gender"))+".\n");
      break;
  }

// Is there a darkness spell in the area of effect?
  switch (flag) {
    case 1  :
      light = present("#DARKNESS_OBJECT#", environment(TP));
      if (light) {
        tell_room(environment(TP),
          "The light dispels the darkness clouding the room.\n");
        light->remove();
        return 1;
      }
      break;
    default :
      if (!target) target = TP;
      light = present("#DARKNESS_OBJECT#", target);
      if (light) {
        tell_object(environment(target), 
          "The light erupts through the cloud of darkness, destroying"+
          " both!\n");
        light->remove();
        return 1;
      }
    break;
  }

  light = clone_object(M_OBJ(light_ob));

  if (flag) {
    flag--;
    if (flag)
      if (present("#LIGHT_OBJECT#", target)) flag--;
    light->move(target);
    light->start_spell(TP, flag); 
  } else {
      if (!present("#LIGHT_OBJECT#", TP))
      flag = 1;
    else
      flag = 0;
    light->move(TP);
    light->start_spell(TP, flag);
  }
  
  return 1;
}
