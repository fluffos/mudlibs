#include <std.h>
#include <daemons.h>
#include <magic.h>

inherit SPELL;

#include <langs.h>

int theProf;

void create() {
    ::create();
    set_spell_name("beast speech");
    set_spell_level(([ "warlock" : 1 ]));
    set_spell_sphere("divination");
    set_syntax("cast CLASS beast speech [on TARGET]");
    set_description("Calling upon the knowledge of their patron, the warlock is granted the ability to speak and understand the sylvan language.");
    set_verbal_comp();
	set_helpful_spell(1);
}

string query_cast_string() {
   return caster->QCN+" starts to mouth out syllables.\n";
}

void spell_effect(int prof) {
    int i;
    string what, arg;
    object ob;

    if (!objectp(target)) {
        target = caster;
    }

    theProf = prof;
    tell_object(caster,"%^RESET%^%^CRST%^%^C033%^Your patron graces your %^C039%^m%^C045%^i%^C039%^n%^C045%^d %^C033%^with %^C051%^hidden knowledge%^RESET%^%^C033%^...%^CRST%^");
    spell_successful();

    for (i =0;i<sizeof(ANIMAL_LANGS);i++) {
      if(member_array(ANIMAL_LANGS[i],OLD_LANGS) == -1) target->add_lang_overload(ANIMAL_LANGS[i],prof);
    }
    addSpellToCaster();
    spell_successful();
    caster->set_property("spelled",({TO}));
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 12;
    set_end_time();
    call_out("dest_effect",spell_duration);
}

void dest_effect() {
    int i;
    if (objectp(target)) {
      for (i =0;i<sizeof(ANIMAL_LANGS);i++) {
        if(member_array(ANIMAL_LANGS[i],OLD_LANGS) == -1) target->subtract_lang_overload(ANIMAL_LANGS[i],theProf);
      }
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}

void do_spell_blowup(int prof){ MAGIC_D->fizzile(TO); }
