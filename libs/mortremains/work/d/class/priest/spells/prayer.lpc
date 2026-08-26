//ilz

#include <magic.h>
#include <m_spells.h>
#include <mudlib.h>

#define COST 22

string help();

int invoke_prayer (string str) {
  object target, shield;
int flag;
 
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
  if (present("#PRAYER_SPELL#", target)) {
    if (flag) write("They have a prayer spell active!\n");
    if (!flag) write("You have a prayer spell active!\n");
    
    return 0;
  }

  if (!TP->invoke_spell(COST)) {
    write(NOT_ENOUGH_SP);
    return 0;
  }

  write ("You begin casting prayer.\n");
if (flag) say(TPN+" utters a prayer for "+target->query("cap_name")+".\n");
 
  shield = clone_object("/d/class/priest/obj/prayer_ob");
  
  
  if (!shield) {
    write("Your spell fizzles.  Contact Cyanide.\n");
    say(TPN+"'s spell fizzles...\n");
    return 0;
  }

  shield->move(target);
  shield->begin_spell(TP, target);
  return 1;
}

string spellcraft() {
    return (@EndSpellcraft
Prayer (Priest - Level III - All)

Duration: 50 sec/lvl 		Area of Effect: Caster
Cost: 22 TP

	This is an improved version of the bless spell,
granting double it's protection to the caster.
EndSpellcraft
    );
}
