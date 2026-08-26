#include <std.h>
inherit WEAPONLESS;

create()
{
    ::create();
    set_name("vicious attack dog");
    set_id(({ "dog", "attack dog", "vicious attack dog" }));
   set_short("%^C124%^vi%^C243%^"+
   "c%^C124%^ious att%^C244%^a"+
   "%^C124%^ck d%^C094%^"+
   "o%^C124%^g%^CRST%^");
    set_long("%^C243%^Lean and %^C124%^vicious%^C243%^"+
	", this canine has been bred for an obvious "+
	"purpose, the %^C055%^death %^C243%^of anyone "+
	"it's handlers deem worthy of %^C055%^"+
	"death%^C243%^. Its fur is %^C246%^sleek "+
	"%^C243%^and %^C246%^clean %^C243%^meaning "+
	"the dog has been well cared for, but is "+
    "also obviously been %^C124%^starved "+
	"%^C243%^to the point of being a dangerous "+
	"animal.\n%^CRST%^");
    set_gender("male");
    set_race("dog");
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
        tell_room(environment(targ), "The attack dog leaps at " +
targ->query_cap_name() + " and grabs them in its jaws!", targ);
        tell_object(targ, "The attack dog leaps at you and grabs you in its jaws!");
        targ->set_paralyzed(random(10) + 5, "%^C253%^You are trapped in the jaw!%^CRST%^");
        return 1;
    } else {
        tell_object(targ, "The attack dog leaps at you but you dodge its attack!");
        tell_room(environment(targ), "The attack dog leaps at " + targ->query_cap_name() + " but they dodge out of the way", targ);
    }
}
