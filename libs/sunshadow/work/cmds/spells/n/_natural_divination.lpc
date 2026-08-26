inherit "/cmds/spells/c/_clairvoyance";

int clairvoyance_delay()
{
    return 60;
}

void create()
{
    ::create();
    set_spell_name("natural divination");
    set_spell_level(([ "innate" : 8 ]));
    set_discipline("divination");
    set_mystery("nature");
    set_domains(({}));
    set_syntax("cast CLASS natural divination on TARGET");
    set_description("With this spell, the caster uses a corpse and reads its entrails to gain deeper understanding, scrying the target. This spell requires a corpse to be present and consumes that corpse. This spell is stronger than other scrying effects like clairvoyance or vision.");
    set_silent_casting(1);
}

int preSpell()
{
    object corpse;
    
    ::preSpell();
    
    corpse = present("corpse", environment(caster));
    if(!objectp(corpse))
    {
        tell_object(caster, "You need a corpse to read its entrails.");
        return 0;
    }
    
    tell_object(caster, "%^GREEN%^You slice the corpse open and arrange its entrails. You begin to read them, seeking out your target.");
    return 1;
}