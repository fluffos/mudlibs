/*
** File:  dark.c
** Purpose: 1st-level alteration spell.
** Duration About .5 minutes per level.
** Cost:  12 SP
** Credits:
**   21 Jun 96   Chronos@Against the Fall of Darkness wrote the file.
**   23 Jul 97   Cyanide@Nightfall's Keep borrowed and improved the spell
**                from a now-defunct mud.
**   20 Jan 98   Cyanide@NK converted to a parallel darkness spell.
*/

#include <mudlib.h>
#include <m_spells.h>

#define COST 12

inherit SPELL;

int cast_dark (string str, int obj) {
  object target, dark;
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

  // The target makes its saving throw against the darkness spell.
  if (target!=TP && living(target) && target->query_save()) {
    target = environment(TP);
    flag = 1;
  }

  if (present("#DARKNESS_OBJECT#", target)) {
    if (flag==2) write("That person already has a darkness effect.\n");
    if (flag==1) write("There is already a darkness spell in the room.\n");
    if (!flag && present("#DARKNESS_OBJECT#", TP)) 
      write("You already have a darkness spell upon you.\n");
    return 1;
  }

  if (living(target))
    if (!check_magic_resist(TP, target, COST, 0)) return 0;

  if (!obj) {
    if (!cast_spell(TP, COST)) return 1;
  } else {
    obj = query_caster_level(TP, "wizard");
  }

// Clone the dark object.
  dark = clone_object(M_OBJ(dark_ob));  
  if (!dark) {
    write("Your spell fizzles. Notify Cyanide.\n");
    return 1;
  }

// Tell the room and caster what happens...
  switch (flag) {
    case 1 :
      write("You cast darkness upon the room.\n");
      say(TPN+" utters a strange incantation.\n");
      tell_room(environment(TP), "The room suddenly gets dark!\n");
      break;
    case 2 : 
      tell_object(target, TPN +
        " gestures at you and utters a strange incantation.\n"+
        "An aura of darkness springs up around you!\n");
      write ("You cast darkness upon "+target->query("cap_name")+".\n");
      message("spell", 
        TPN+" gestures at "+target->query("cap_name")+
        " and utters a strange incantation.\n", environment(TP),
        ({ TP, target }) );
      break;
    default :
      write("You cast a dark spell upon yourself.\n"+
        "An aura of darkness springs up around you.\n");
      say(TPN+" utters a strange incantation.\nAn aura of darkness "+
        "springs up around "+objective(TP->query("gender"))+".\n");
      break;
  }

// Is there a light spell in the area of effect?
  switch (flag) {
    case 1  :
      dark = present("#LIGHT_OBJECT#", environment(TP));
      if (dark) {
        tell_room(environment(TP),
          "The darkness dispels the light spell brightening the room.\n");
        dark->remove();
        return 1;
      }
      break;
    default :
      if (!target) target = TP;
      dark = present("#DARKNESS_OBJECT#", target);
      if (dark) {
        tell_object(environment(target), 
          "The darkness erupts through the light spell, destroying"+
          " both!\n");
        dark->remove();
        return 1;
      }
    break;
  }

  dark = clone_object(M_OBJ(dark_ob));

  if (flag) {
    flag--;
    if (flag)
      if (present("#DARKNESS_OBJECT#", target)) flag--;
    dark->move(target);
    dark->start_spell(TP, flag); 
  } else {
      if (!present("#DARKNESS_OBJECT#", TP))
      flag = 1;
    else
      flag = 0;
    dark->move(TP);
    dark->start_spell(obj, flag);
  }
  
  return 1;
}

string spellcraft() {
  return (@EndSC
Darkness (Alteration, 2nd Level Mage Spell)
	Duration: 30 seconds/level

	This spell causes total, impenetrable darkness in the area of effect. 
Infravision is useless. Neither normal nor magical light works unless a 
light or continual light spell is used. In the former event, the darkness 
spell is negated by the light spell, and vice versa.
EndSC
  );
}
