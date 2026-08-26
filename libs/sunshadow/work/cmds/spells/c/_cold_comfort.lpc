#include <std.h>
#include <spell.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

void effect(int direction)
{
    if(direction > 0)
    {
        caster->set_property("castspellresist",1);
    }
    else
    {
        caster->remove_property("castspellresist");
    }
    
    caster->set_resistance("fire", 20 * direction);
    caster->set_resistance("cold", 20 * direction);

    return;
}

void create()
{
    ::create();
    
    set_author("tlaloc");
    set_spell_name("cold comfort");
    set_spell_level( ([ "warlock" : 1 ]) );
    set_spell_sphere("alteration");
    set_syntax("cast CLASS cold comfort");
    set_damage_desc("+20 to fire and cold resistance.");
    set_description("With this invocation, the warlock gains enhanced protection from extreme heat and cold.");
    set_helpful_spell(1);
    set_feats_required(([ "warlock" : "tome of ancient secrets"]));
}

int preSpell()
{
   if(caster->query_property("castspellresist") || caster->query_property("fiery body"))
   {
      tell_object(caster,"You already have protection of this nature!");
      return 0;
   }
   
   return 1;
}


string query_cast_string()
{
    return "%^RESET%^%^CRST%^%^C038%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C038%^ calls upon "+caster->query_possessive()+" %^C030%^a%^C036%^n%^C045%^c%^C051%^i%^C045%^e%^C036%^n%^C030%^t %^RESET%^%^C038%^and %^C030%^f%^C036%^o%^C045%^r%^C051%^b%^C087%^i%^C051%^d%^C045%^d%^C036%^e%^C030%^n %^RESET%^%^C038%^knowledge.%^CRST%^";
}

void spell_effect(int prof)
{
    string myname, yourname;
    int mylevel;
    
    myname = caster->QCN;
  
    tell_object(caster, "%^RESET%^%^CRST%^%^C038%^You place a hand upon yourself, enhancing your body with %^C030%^p%^C036%^r%^C045%^o%^C051%^t%^C087%^ec%^C051%^t%^C045%^i%^C036%^o%^C030%^n %^RESET%^%^C038%^against %^C124%^heat %^C038%^and %^C087%^cold%^C038%^.%^CRST%^");
    tell_room(place, "%^RESET%^%^CRST%^%^C038%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C038%^ focuses on enhancing their body with %^C030%^p%^C036%^r%^C045%^o%^C051%^t%^C087%^ec%^C051%^t%^C045%^i%^C036%^o%^C030%^n%^RESET%^%^C038%^!%^CRST%^", caster);

    effect(1);
    spell_successful();
    addSpellToCaster();
}

void dest_effect()
{
    tell_object(caster, "%^RESET%^%^CRST%^%^C038%^Your protection from the elements seems to %^C087%^d%^C051%^is%^C045%^si%^C036%^pa%^C030%^te%^C038%^.%^CRST%^");
    effect(-1);
    ::dest_effect();
    if(objectp(this_object()))
        this_object()->remove();
}
