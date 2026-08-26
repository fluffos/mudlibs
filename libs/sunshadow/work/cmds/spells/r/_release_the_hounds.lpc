// Chernobog (10/25/22)
// Release the Hounds

#include <std.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

object *mons = ({ });

void create(){
    ::create();
    set_spell_name("release the hounds");
    set_spell_level(([ "inquisitor" : 2 ]));
    set_spell_sphere("conjuration_summoning");
    set_syntax("cast CLASS release the hounds (on spirits)");
    set_description("With a word, the inquisitor can summon several faithful hounds from the kennels of his temple to his side, aiding in his duty to root out heresy. The types kept by the various faiths can take different forms, as some take pride in breeding and training their hounds, while others use more divine approaches.");
    set_verbal_comp();
    set_somatic_comp();
	set_helpful_spell(1);
    set_arg_needed(1);
    set_feats_required(([ "inquisitor" : "chains of justice"]));
}

string query_casting_string(){
    tell_object(caster, "%^RESET%^%^CRST%^%^C101%^You let out a %^C144%^sharp%^C101%^, %^C058%^m%^C100%^u%^C101%^l%^C144%^t%^C058%^i%^C100%^-%^C101%^t%^C144%^o%^C058%^n%^C100%^e%^C101%^d %^RESET%^%^C144%^whistle%^C101%^.%^CRST%^");
    tell_room(place, "%^RESET%^%^CRST%^%^C101%^"+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C101%^ lets out a %^C144%^sharp%^C101%^, %^C058%^m%^C100%^u%^C101%^l%^C144%^t%^C058%^i%^C100%^-%^C101%^t%^C144%^o%^C058%^n%^C100%^e%^C101%^d %^RESET%^%^C144%^whistle%^C101%^.%^CRST%^");
    return "display";
}

int preSpell(){
    if(present(caster->query_name()+"_hound", place)) {
        tell_object(caster, "%^RESET%^%^CRST%^%^C100%^Your hounds are already here.%^CRST%^");
        return 0;
    }
    return 1;
}

void spell_effect(){
    object hound;
    string hounds;
    int i;
    
    for(i = 0; i < 4; i++){
        hound = new("/d/magic/mon/inq_hound");
        hound->set_property("spelled", ({ this_object() }) );
        hound->set_property("spell_creature", this_object());
        hound->set_property("spell", this_object());
        hound->set_property("minion", caster);
        hound->set_max_hp(clevel * 10 + 30);
        hound->set_hp(hound->query_max_hp());
        hound->set_overall_ac(-clevel);
        hound->set_exp(0);
        hound->add_id(caster->query_name()+"_hound");
        hound->set_resistance_percent("negative energy", 100);
        hound->set_resistance_percent("positive energy", 100);
        mons += ({ hound });
        
        switch(arg){
            case "spirits":
                hound->set_short("%^RESET%^%^CRST%^%^C051%^g%^C045%^h%^C039%^o%^C033%^st%^C045%^l%^C051%^y s%^C045%^p%^C039%^ir%^C045%^i%^C051%^t h%^C045%^o%^C039%^u%^C045%^n%^C051%^d%^CRST%^");
                hound->set_long("%^RESET%^%^CRST%^%^C033%^This %^C051%^g%^C045%^h%^C039%^o%^C033%^st%^C045%^l%^C051%^y h%^C045%^o%^C039%^u%^C045%^n%^C051%^d %^RESET%^%^C033%^is the spirit of a loyal servant, granted leave to continue its service even after death.%^CRST%^");
                hounds = "%^C051%^h%^C045%^o%^C039%^un%^C045%^d%^C051%^s";
                break;
            default:
                hound->set_short("%^RESET%^%^CRST%^%^C058%^large %^C130%^h%^C136%^o%^C130%^u%^C136%^n%^C130%^d%^CRST%^");
                hound->set_long("%^RESET%^%^CRST%^%^C058%^This large %^C130%^h%^C136%^o%^C130%^u%^C136%^n%^C130%^d %^RESET%^%^C058%^is a loyal servant, eager to serve its master. A large %^C244%^metal collar %^C058%^wraps protectively about its neck.%^CRST%^");
                hounds = "%^C130%^h%^C136%^o%^C130%^u%^C136%^n%^C130%^d%^C136%^s";
        }
        
        hound->move(place);
        caster->add_follower(hound);
        caster->add_protector(hound);
    }
    tell_room(place, "%^RESET%^%^CRST%^%^C144%^Four large "+hounds+" %^RESET%^%^C144%^step into being, flanking "+caster->query_cap_name()+"%^RESET%^%^CRST%^%^C144%^.");
    
    addSpellToCaster();
    spell_duration = (clevel + roll_dice(1, 20)) * ROUND_LENGTH * 3;
    set_end_time();
    call_out("dest_effect", spell_duration);
}

void dest_effect(){
    int i;
    for(i=0; i<sizeof(mons); i++){
        if(objectp(mons[i])){
            if(objectp(caster)) caster->remove_protector(mons[i]);
            mons[i]->die();
        }
    }
    removeSpellFromCaster();
    ::dest_effect();
    if(objectp(this_object())){
        this_object()->move("/d/shadowgate/void");
        this_object()->remove();
    }
}

