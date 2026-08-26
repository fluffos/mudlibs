// Ilz did this.
// Cyanide fixed is, 14 July 2000

#define COST 8 
#define SYNTAX "Syntax: invoke fear at target\n"  

#include <mudlib.h>

// Prototypes:
void do_lightning (object);

int lvl;
object room, caster, last_hit, *targs;

inherit SPELL;

varargs int invoke_fear (string str) {   
    object target;
    int x;
    if (!str) str = "NONE";
    if (str=="NONE") target = TP->query_current_attacker();
    if (!target) target = present(str, environment(TP));
    if (!target) {
	write(SYNTAX);
	return 0;
    }     

    if (!check_valid_targ(TP, target)) return 0;

    if (!invoke_spell(TP, COST)) return 0;

    lvl = TP->query_level("priest");
    write("You begin invoking Fear...\n");
    say(TPN+" begins invoking the might of the gods...\n");

    target->kill_ob(TP);
    target->set("last_attacker", TP);
    room = environment(target);

    if ((wizardp(target) && target->query("invisible")) || (!living(target)) ||
      (target->query("no_attack")) || target->query("undead") ){
	write ("I dont think they are very scared of you.\n");
	return 1;
    }  

    if (!check_magic_resist(lvl,target,COST,0)) return;
    //    x = query_save_mod(caster,target, ({"charm"}) );
    x = target->save_throw(x);
    if (x) {
	tell_room(room, target->query("cap_name")+" appears unaffected.\n",
	  target);
	tell_object(target, "You shake off the spell's fearful effect.\n");
    }else{
	target->run_away();
    }
    return 1;
}

string spellcraft() {
    return (@EndSpellcraft
Fear (Priest - Level I - Charm)

Duration: Instant 		Area of Effect: 1 Target
Cost: 8 TP

	This spell causes the target to run away.
EndSpellcraft
    );
}
