#include <spell.h>
#include <magic.h>
inherit SPELL;

int num;

void create()
{
    ::create();
    set_spell_name("nightmare maw");
    set_spell_level(([ "innate" : 8 ]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS nightmare maw on TARGET");
    set_damage_desc("slashing");
    set_description("This spell summons a Nightmare Maw, one of mindless demons from the seas of Shadow Plane. It will bite into target, continuously tearing their being apart.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_save("fort");
}

string query_cast_string()
{
    return "%^RESET%^%^C244%^As "+caster->QCN+" %^RESET%^%^C105%^c%^C111%^h%^C117%^a%^C153%^n%^C147%^t%^C141%^s%^RESET%^%^C244%^, a %^RESET%^%^C240%^giant black maw %^RESET%^%^C244%^forms behind"+caster->QS+"%^RESET%^%^C244%^.%^CRST%^";
}

spell_effect(int prof)
{
    spell_successful();

    tell_room(place,"%^RESET%^%^C244%^As "+caster->QCN+" %^RESET%^%^C244%^completes the %^RESET%^%^C105%^c%^C111%^h%^C117%^a%^C153%^n%^C147%^t%^RESET%^%^C244%^, a %^RESET%^%^C240%^giant maw %^RESET%^%^C244%^floats towards "+target->QCN+" %^RESET%^%^C244%^and plunges its %^RESET%^%^C240%^t%^C241%^e%^C242%^e%^C241%^t%^C240%^h %^RESET%^%^C244%^into them.%^CRST%^",target);
    tell_object(target,"%^RESET%^%^C244%^As "+caster->QCN+" %^RESET%^%^C244%^completes the %^RESET%^%^C105%^c%^C111%^h%^C117%^a%^C153%^n%^C147%^t%^RESET%^%^C244%^, a %^RESET%^%^C240%^giant maw %^RESET%^%^C244%^floats towards you and plunges its %^RESET%^%^C240%^t%^C241%^e%^C242%^e%^C241%^t%^C240%^h %^RESET%^%^C244%^into them.%^CRST%^",target);
    damage_targ(target, target->return_target_limb(), sdamage,"slashing");
    num = clevel / 8 + 1;
    if(do_save(target,0))
        num/=2;
    call_out("bite_again",ROUND_LENGTH);
}

void bite_again()
{

    if(!objectp(target))
    {
        dest_effect();
        return;
    }

    if(target->query_hp()<0)
    {
        dest_effect();
        return;
    }

    define_base_damage(0);
    tell_room(ENV(target),"%^RESET%^%^C244%^The %^RESET%^%^C240%^maw %^RESET%^%^C244%^continues to %^RESET%^%^C088%^r%^C124%^i%^C088%^p %^RESET%^%^C244%^and %^RESET%^%^C124%^t%^C160%^e%^C196%^a%^C124%^r %^RESET%^%^C244%^into "+target->QCN+"%^RESET%^%^C244%^!%^CRST%^",target);
    tell_object(target,"%^RESET%^%^C244%^The %^RESET%^%^C240%^maw %^RESET%^%^C244%^continues to %^RESET%^%^C088%^r%^C124%^i%^C088%^p %^RESET%^%^C244%^and %^RESET%^%^C124%^t%^C160%^e%^C196%^a%^C124%^r %^RESET%^%^C244%^into you!%^RESET%^");
    damage_targ(target, target->return_target_limb(), sdamage/6,"slashing");

    if(num-- < 0)
    {
        dest_effect();
        return;
    }
    else
    {
        call_out("bite_again",ROUND_LENGTH);
    }
}

dest_effect()
{
    if(find_call_out("bite_again") != -1)
        remove_call_out("bite_again");

    if(objectp(target))
    {
        tell_room(ENV(target),"%^RESET%^%^C244%^Finally, the %^RESET%^%^C088%^v%^C124%^i%^C160%^c%^C196%^i%^C160%^o%^C124%^u%^C088%^s %^RESET%^%^C240%^maw %^RESET%^%^C244%^attacking "+target->QCN+" %^RESET%^%^C240%^d%^C241%^i%^C242%^s%^C243%^s%^C244%^i%^C245%^p%^C246%^a%^C247%^t%^C248%^e%^C249%^s %^RESET%^%^C244%^in a wisp of %^RESET%^%^C240%^darkness%^C244%^.%^CRST%^",target);
        tell_object(target,"%^RESET%^%^C244%^The %^RESET%^%^C088%^v%^C124%^i%^C160%^c%^C196%^i%^C160%^o%^C124%^u%^C088%^s %^RESET%^%^C240%^maw %^RESET%^%^C240%^d%^C241%^i%^C242%^s%^C243%^s%^C244%^i%^C245%^p%^C246%^a%^C247%^t%^C248%^e%^C249%^s %^RESET%^%^C244%^in a wisp of %^RESET%^%^C240%^darkness%^RESET%^C244%^!%^CRST%^");
    }

    ::dest_effect();
    if(objectp(TO))
        TO->remove();
}
