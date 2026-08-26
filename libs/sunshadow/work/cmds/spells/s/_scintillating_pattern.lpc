#include <std.h>
#include <daemons.h>
#include <spell.h>
#include <magic.h>


inherit SPELL;

void create()
{
    ::create();
    set_spell_name("scintillating pattern");
    set_spell_level(([ "mage" : 8, "cleric" : 8 ]));
    set_spell_sphere("illusion");
    set_domains(({ "hedonism", "illusion" }));
    set_save("will");
    set_syntax("cast CLASS scintillating pattern");
    set_damage_desc("mass confusion, or staggered on save");
    set_description("This casting summons forward illusionary patterns that attempt to confuse all targets in the area. If they make a successful will save, they are instead staggered for one round.");
    splash_spell(3);
}

void spell_effect(int prof)
{
    object* attackers;
    int i, admg;
    
    attackers = target_selector();

    tell_room(place, "%^MAGENTA%^%^BOLD%^Spirals of scintillating patterns appear in the air!%^RESET%^");
    
    if (!sizeof(attackers))
    {
        tell_object(caster, "There is no one here.");
        dest_effect();
        return;
    }
    
    foreach(object ob in attackers)
    {
        if(!objectp(ob))
            continue;
        
        if((ob->query_level() < (caster->query_level() - 10) || !do_save(ob, 0)) && !mind_immunity_damage(ob))
        {
            tell_room(place, "%^MAGENTA%^The patterns captivate " + ob->query_cap_name() + "!", ob);
            tell_object(ob, "%^MAGENTA%^You are captivated by the scintillating pattern, and lash out!%^RESET%^");
            "/std/effect/status/confused"->apply_effect(ob, clevel / 5 + 1, caster);
            continue;
        }
        else
        {
            tell_room(place, "%^BOLD%^" + ob->query_cap_name() + " is shocked by the patterns!%^RESET%^", target);
            tell_object(ob, "%^BOLD%^You are shocked by the scintillating patterns!%^RESET%^");
            "/std/effect/status/staggered"->apply_effect(ob, 1, caster);
            if(!userp(ob))
                spell_kill(ob, caster);
            continue;
        }
    }
    spell_successful();
}
