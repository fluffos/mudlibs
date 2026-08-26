//ilz

#include <magic.h>
#include <m_spells.h>
#include <mudlib.h>

#define COST 12
#define SYNTAX "Syntax: invoke silence at target\n" 

inherit SPELL;

int invoke_silence (string str) {
  object target, shield;
int flag, x;
 
 seteuid(getuid());

   if (!str) str = "NONE";
   if (str=="NONE") target = TP->query_current_attacker();
   if (!target) target = present(str, environment(TP));
   if (!target) {
      write(SYNTAX);
      return 0;
   }

   if (!check_valid_targ(TP, target)) return 0;
  
     if (!living(target)) {
        write("The target must be alive.\n");
        return 1;
      }
    
  if (present("#SILENCE_OB#", target)) {
     write("They are already affected by silence!\n");
     return 0;
  }

  if (!TP->invoke_spell(COST)) {
    write(NOT_ENOUGH_SP);
    return 0;
  }
 
    if (!check_magic_resist((TP->query_level()),target,COST,0)) return;
 
 
  write ("You begin casting silence upon "+target->query("cap_name")+".\n");
 say(TPN+" begins casting silence upon "+target->query("cap_name")+".\n");
   x = target->save_throw(x);

      if (x) {
      write(target->query("cap_name")+" resists the spell.\n");
 say(target->query("cap_name")+" resists the spell.\n");
 target->kill_ob(TP);
     return 1;
     }
    write(target->query("cap_name")+" is silenced.\n");
    shield = clone_object("/d/class/priest/obj/silence_ob");
 
  if (!shield) {
    write("Your spell fizzles.  Contact ILZ.\n");
    say(TPN+"'s spell fizzles...\n");
    return 0;
  }

  shield->move(target);
  shield->begin_spell(target, (TP->query_level()));
  target->kill_ob(TP);
  return 1;
}

string spellcraft() {
    return (@EndSpellcraft
Silence (Priest - Level II - Guardian)

Duration: 2 sec/lvl 		Area of Effect: 1 Target
Cost: 12 TP

	This spell robs the target of speech for a
time.
EndSpellcraft
    );
}
