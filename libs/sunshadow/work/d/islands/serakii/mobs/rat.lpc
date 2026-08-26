#include <std.h>
#include <daemons.h>
#include "../serakii.h"

inherit WEAPONLESS;

int rat_level;

void create()
{
    object ob;
    ::create();
    set_name("infected rat");
    set_body_type("quadruped");
    set_gender("neuter");
    set_property("full attacks",1);
    set("aggressive","sicem");
    set_alignment(9);
    set_race("rat");
    set_short("%^C094%^i%^C059%^n%^C166%^f%^C094%^ect%^C059%^e%^C094%^d %^C172%^r%^C060%^a%^C094%^t%^CRST%^");
    set_id(({"rat","infected rat","rous"}));
    set_long("%^C094%^This rat has managed to grow into %^C095%^four times larger%^C094%^ than any of its natural cousins. Its body is rippling with %^C088%^muscles%^C094%^ and its tail is at least %^C095%^five feet%^C094%^ long. In its %^C160%^gaping mouth%^C094%^ a set of %^C252%^wicked teeth%^C094%^ are ready to tear into anything. From its mouth leaks a steady stream of %^C035%^d%^C022%^r%^C035%^ipping t%^C022%^o%^C035%^xin%^C094%^ and its eyes glow with a %^C126%^fe%^C162%^l%^C126%^l lig%^C161%^h%^C126%^t%^C094%^.%^CRST%^\n");
	rat_level=(38 + random(6));
   set_hd(rat_level, 10);
   set_class("fighter");
   set_mlevel("fighter",rat_level);
	
    add_money("gold", random(500));
    add_money("platinum", random(50));
    set_damage_bonus(8);
    set_overall_ac(-30);
    add_attack_bonus(roll_dice(3,6));
    set_monster_feats(({
        "rush",
		"unarmed combat",
    }));
    set_func_chance(20);
    set_funcs(({ "rushit" }));
    set_new_exp(rat_level,"very high");
       set_max_hp(20 * rat_level);
    set_hp(query_max_hp());
    set_property("swarm",1);
    set_mob_magic_resistance("average");
    set_damage(2,10);
    set_attacks_num(7);
    set_attack_limbs(({"mouth","right claw","left claw"}));
    set_func_chance(30);
    set_stats("strength",25);

}

void rushit(object targ)
{
    if (!objectp(targ)) {
        return;
    }
    if (!objectp(TO)) {
        return;
    }

	tell_object(targ,"%^C093%^The rat charges at you and covers you in a cloud of fell liquid.%^CRST%^");
			tell_room(ETO,"%^C093%^"+targ->query_cap_name()+" %^C093%^screams in"+
			" pain as the rat covers "+targ->query_objective()+"%^C093%^with poisonous liquid.%^CRST%^",targ);
	if(!PLAYER_D->immunity_check(targ, "poison")) targ->add_poisoning(50);
    TO->force_me("rush " + targ->query_name());
}

void sicem()
{
    command("sic "+TP->query_true_name());
    command("kill "+TP->query_true_name());
    set("aggressive",100);
}
