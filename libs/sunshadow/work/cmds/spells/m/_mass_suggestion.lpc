#include <magic.h>
#include <domination.h>

inherit SPELL;

void create()
{
    ::create();
    set_spell_name("mass suggestion");
    set_spell_level(([ "psion" : 5,  ]));
    set_spell_sphere("telepathy");
    set_discipline("telepath");
    set_syntax("cast CLASS mass suggestion on COMMAND");
    set_description("You manifest a suggestion instills itself into the minds of all living beings present. They must make a will saving throw or immediately perform the planted command.");
    set_save("will");
    mental_spell(1);
    set_verbal_comp();
    set_somatic_comp();
    splash_spell(3);
    set_arg_needed(1);
}

void spell_effect()
{
    object *foes;
    string my_name, *inputs;

    if(!stringp(arg))
        return;
    
    foes = target_selector();
    
    if(!sizeof(foes))
    {
        tell_object(caster, "There is no one here.");
        return;
    }

    inputs = explode(arg, " ");
    if(member_array(inputs[0], NO_FORCE) >= 0)
    {
        tell_object(caster, "That is not a valid command.");
        dest_effect();
        return;
    }
    
    spell_successful();
    my_name = caster->query_cap_name();

    tell_object(caster,"%^MAGENTA%^BOLD%^You manifest and implant a suggestion to %^WHITE%^" + arg + "%^MAGENTA%^ into those around you.%^RESET%^");
    tell_room(place,"%^BOLD%^%^MAGENTA%^" + my_name + " lets loose a wave of psychic energy%^RESET%^!", ({ caster }));
    
    foreach(object foe in foes)
    {
        if(do_save(foe, 0) || mind_immunity_damage(foe))
        {
            tell_object(caster, foe->query_cap_name() + " shrugs off your suggestion attempt.");
            tell_object(foe, "You shrug off the attempt at suggestion.");
            if(!userp(foe))
                spell_kill(foe, caster);
            return;
        }
        
        foe->set_property("dominated", 1);
        foe->force_me(arg);
        foe->remove_property("dominated");
    }
    
    dest_effect();
    return;
}