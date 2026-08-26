#include <daemons.h>
#include <spell.h>
#include <magic.h>

inherit SPELL;

void create() {
    ::create();
    set_spell_name("diabolic grasp");
    set_spell_level(([ "warlock" : 2 ]));
    set_heritage("abyssal");
    set_spell_sphere("enchantment_charm");
    set_syntax("cast CLASS diabolic grasp on TARGET");
    set_description("Using their blood as a focus, the warlock is able to ensnare a monster in place with sanguine bonds. Their victim can still hear, but will be unable to look or fight while the binding is in place.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("fort");
}

string query_cast_string() {
    string cast;

    cast = "%^RESET%^%^CRST%^%^C100%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C100%^ grits their %^C144%^teeth%^C100%^, digging their nails into their %^C196%^pa%^C124%^l%^C196%^m%^C124%^s%^RESET%^%^C100%^.%^CRST%^";
    return cast;
}

void spell_effect(int prof) {
    int change=-2;
    int duration,level;

    //if (clevel >20) clevel = 20;
    if (target->query_body_type())
        if (member_array((string)target->query_body_type(),VALID_BACKS) == -1) {
            tell_object(caster, "%^RESET%^%^CRST%^%^C100%^Your spell is harmlessly dispersed.%^CRST%^");
            TO->remove();
            return;
        }
    if (!present(target,environment(caster))) {
        tell_object(caster,"%^RESET%^%^CRST%^%^C100%^Your target is not in this area.\n%^CRST%^");
        TO->remove();
        return;
    }
    if (target->query_property("no hold") || target->query_property("no paralyze")) {
       tell_object(caster,"%^RESET%^%^CRST%^%^C100%^Your spell disperses futilely around "+target->query_cap_name()+"%^RESET%^%^CRST%^%^C100%^.\n%^CRST%^");
      TO->remove();
      return;
   }

    if (target->query_size()<2) {
        tell_object(caster,"%^RESET%^%^CRST%^%^C100%^You feel your spell waver against "+target->query_cap_name()+"%^RESET%^%^CRST%^%^C100%^ the power dispersing ineffectively.\n%^CRST%^");
        tell_object(target,"%^RESET%^%^CRST%^%^C100%^You feel a strange power struggle against you before dispersing.\n%^CRST%^");
        spell_kill(target,caster);
        TO->remove();
        return;
    }
    if(do_save(target,0)) {
        tell_object(caster,"%^RESET%^%^CRST%^%^C100%^You feel your spell waver against "+target->query_cap_name()+"%^RESET%^%^CRST%^%^C100%^ the power dispersing ineffectively.\n%^CRST%^");
        tell_object(target,"%^RESET%^%^CRST%^%^C100%^You feel a strange power struggle against you before dispersing.\n%^CRST%^");
        spell_kill(target,caster);
        TO->remove();
        return;
    }
	duration = clevel/3 + 2;
	if(duration > 10) { duration = 10; }
	duration = duration * (ROUND_LENGTH * 2);
    target->set_paralyzed(duration,"%^RESET%^%^CRST%^%^C100%^The %^C196%^b%^C124%^lo%^C196%^od%^C124%^y %^C196%^s%^C124%^i%^C196%^ne%^C124%^w%^C196%^s %^RESET%^%^C100%^hold you fast!%^CRST%^");
    tell_room(environment(caster),"%^RESET%^%^CRST%^%^C100%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C100%^ flicks their hands, spraying droplets around "+target->query_cap_name()+"%^RESET%^%^CRST%^%^C100%^. %^C196%^B%^C124%^lo%^C196%^od%^C124%^y %^C196%^s%^C124%^i%^C196%^ne%^C124%^w%^C196%^s %^RESET%^%^C100%^launch from each %^C124%^ruddy stain%^C100%^, wrapping about and holding "+target->query_objective()+"%^RESET%^%^CRST%^%^C100%^ fast.%^CRST%^", ({caster,target}));
    tell_object(caster,"%^RESET%^%^CRST%^%^C100%^You flick your hands, spraying droplets around "+target->query_cap_name()+"%^RESET%^%^CRST%^%^C100%^. %^C196%^B%^C124%^lo%^C196%^od%^C124%^y %^C196%^s%^C124%^i%^C196%^ne%^C124%^w%^C196%^s %^RESET%^%^C100%^launch from each %^C124%^ruddy stain%^C100%^, wrapping about and holding "+target->query_objective()+"%^RESET%^%^CRST%^%^C100%^ fast.\n%^CRST%^");
    tell_object(target,"%^RESET%^%^CRST%^%^C100%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C100%^ flicks their hands, spraying droplets around you. %^C196%^B%^C124%^lo%^C196%^od%^C124%^y %^C196%^s%^C124%^i%^C196%^ne%^C124%^w%^C196%^s %^RESET%^%^C100%^launch from each %^C124%^ruddy stain%^C100%^, wrapping about and holding you fast.\n%^CRST%^");
    TO->remove();
}

