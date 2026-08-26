#include <dieties.h>

inherit SPELL;

#define ALIGNS ({"lawful good","neutral good","chaotic good","lawful neutral","true neutral","chaotic neutral","lawful evil","neutral evil","chaotic evil"})
#define NATURES ({"living","undead"})
#define DEITIES keys(DIETIES) + ({"godless"})

string mask_type, mask_quality;

void create(){
    ::create();
    set_author("yves");
    set_spell_name("false future");
    set_spell_level(([ "bard" : 3, "cleric" : 4, "mage" : 5, ]));
    set_spell_sphere("illusion");
    set_syntax("cast CLASS false future on alignment as ALIGNMENT
        cast CLASS false future on deity as DEITY
        cast CLASS false future on nature as NATURE");
    set_description("
You interfere with attempts to determine your nature and intent by preventing divinations from revealing what you will do and what will befall you while under the spell's effects.

Instead of your true action or nature, divinations resolve as if you will experience some different future you describe as you cast false future.

The choices for alignment are: " + implode(ALIGNS, ", ") + "

The choices for deities are: " + implode(DEITIES, ", ")+ "

The choices for nature are: " + implode(NATURES, ", ") + "
");
    set_somatic_comp();
    set_arg_needed(1);
    set_silent_casting(1);
    set_helpful_spell(1);
}

int preSpell(){


    if (!stringp(arg) || sscanf(arg, "%s as %s", mask_type, mask_quality) != 2) {
        tell_object(caster, "You must provide the the type and quality of the falsehood!");
        return 0;
    }

    switch(mask_type) {
        case "alignment": {
            if((int)caster->query_property("hidden alignment")) {
                tell_object(caster, "You already have an alignment altering affect.");
                return 0;
            }
            if(member_array(mask_quality, ALIGNS) == -1) {
                tell_object(caster, "That is not a valid alignment!");
                return 0;
            }
            switch(mask_quality){
                case "lawful good": mask_quality = 1; break;
                case "neutral good": mask_quality = 4; break;
                case "chaotic good": mask_quality = 7; break;
                case "lawful neutral": mask_quality = 2; break;
                case "true neutral": mask_quality = 5; break;
                case "chaotic neutral": mask_quality = 8; break;
                case "lawful evil": mask_quality = 3; break;
                case "neutral evil": mask_quality = 6; break;
                case "chaotic evil": mask_quality = 9;break;
            }
            break;
        }
        case "deity": {
            if((int)caster->query_property("hidden deity")) {
                tell_object(caster, "You already have a deity altering affect.");
                return 0;
            }
            if(member_array(mask_quality, DEITIES) == -1) {
                tell_object(caster, "That is not a valid deity!");
                return 0;
            }
            break;
        }
        case "nature": {
            if((int)caster->query_property("hidden nature")) {
                tell_object(caster, "You already have a nature altering affect.");
                return 0;
            }
            if(member_array(mask_quality, NATURES) == -1) {
                tell_object(caster, "That is not a valid nature!");
                return 0;
            }
            break;
        }
        default: {
            tell_object(caster, "That is not a valid type of falsehood!");
            return 0;
            break;
        }
    }

    return 1;
}

void spell_effect(int prof){
    tell_object(caster,"%^CRST%^%^C213%^You w%^C219%^e%^C207%^a%^C213%^v%^C219%^e %^C213%^a %^C067%^fal%^C073%^seh%^C067%^ood %^RESET%^%^C213%^around the %^C061%^qu%^C067%^aliti%^C061%^es %^RESET%^%^C213%^of your b%^C219%^e%^C207%^i%^C213%^n%^C219%^g%^C213%^!%^CRST%^");
    caster->set_property("hidden "+mask_type, mask_quality);
    spell_successful();
    addSpellToCaster();
}

void dest_effect(){
    if(objectp(caster)) {
        caster->remove_property("hidden "+mask_type);
    }
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
