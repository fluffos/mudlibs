#include <std.h>
inherit WEAPONLESS;

create()
{
    ::create();
    set_name("iron patrol construct");
    set_id(({ "construct", "iron patrol construct", "patrol" }));
   set_short("%^C244%^ir%^C248%^o%^C244%^n pa%^C248%^t%^C244%^rol "+
   "c%^C247%^o%^C244%^nstru%^C247%^c%^C244%^t%^CRST%^");
    set_long("%^C246%^This %^C061%^magical %^C246%^iron "+
	"%^C242%^construct %^C246%^has been manufactured with four "+
	"legs, and from a distance might be confused with a %^C094%^"+
	"large dog%^C246%^ or %^C059%^small horse%^C246%^. Its "+
	"%^C242%^iron body%^C246%^ is covered in %^C062%^gnomish "+
	"runes%^C246%^ that glow in a %^C033%^soft light%^C246%^. It "+
	"has a head that is nothing more than a %^C241%^large jaw%^C246%^, "+
	"though even without eyes you are sure that it can perceive "+
	"everything around it. While not silent, its movements "+
	"are fluid and graceful as it moves around.%^CRST%^\n");
    set_race("construct");
    set_body_type("quadruped");
    set_property("swarm", 1);
    set_property("full attacks", 1);
   set_hd(25,12);
    set_overall_ac(-8);
    set_size(1);
    set_moving(1);
    set_property("no rush", 1);
    set_speed(40);
    set_stats("strength", 19);
    set_stats("intelligence", 6);
    set_stats("dexterity", 19);
    set_stats("charisma", 6);
    set_stats("wisdom", 5);
    set_class("fighter");
    set_guild_level("fighter",30);
    set_mlevel("fighter",30);
    set("aggressive", 6);
    set_alignment(4);
    set_property("no random treasure", 1);
    set_hp(300);
    set_exp(12500);
    set_funcs(({ "bite" }));
    set_func_chance(20);
    set_attack_limbs(({"mouth","right claw","left claw"}));


         set_monster_feats(({
         "dodge",
         "mobility",
         "scramble",
         "spring attack",
         "defensive roll",
         "resistance",
         "increased resistance",
         "damage resistance",
         "improved damage resistance",
         "toughness",
        }));

}

void bite(object targ)
{
    if (!targ) {
        return 0;
    }
    if (random(40) > targ->query_stats("dexterity")) {
        tell_room(environment(targ), "%^C253%^The construct scrambles towards " +
targ->query_cap_name() + "%^C253%^ and grabs them in its iron jaw!%^CRST%^", targ);
        tell_object(targ, "%^C253%^The construct scrambles towards you and grabs you in its
iron jaw!%^CRST%^");
        targ->set_paralyzed(random(10) + 5, "%^C253%^You are trapped in the jaw!%^CRST%^");
        return 1;
    } else {
        tell_object(targ, "%^C253%^The construct scrambles towards at you but you dodge its
attack!%^CRST%^");
        tell_room(environment(targ), "%^C253%^The construct scrambles towards " +
targ->query_cap_name() + "%^C253%^ but they dodge out of the way%^CRST%^", targ);
    }
}
