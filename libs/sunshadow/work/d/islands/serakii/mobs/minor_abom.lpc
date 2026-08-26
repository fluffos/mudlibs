// monstrous abomination from the other - minor - loki

#include "../serakii.h"

inherit MONSTER;

void create()
{
    ::create();
    set_name("monstrous abomination");
    set_id(({ "abomination", "monstrous abomination", "demon", "Abomination" }));
    set_short("%^C066%^mo%^C056%^n%^C066%^st%^C054%^r%^C066%^ous ab%^C054%^o%^C066%^m%^C056%^i%^C066%^nati%^C055%^o%^C066%^n%^CRST%^");
    set_long("All %^C056%^flailing limbs%^CRST%^ "+
	"and %^C062%^wings%^CRST%^, this beast "+
	"%^C059%^shambles %^CRST%^along the "+
	"%^C058%^ground %^CRST%^with irregular "+
	"movements and in what looks like obvious "+
	"%^C088%^pain%^CRST%^. It looks to be a "+
	"combination of several different %^C054%^demons "+
	"%^CRST%^that have %^C091%^melted%^CRST%^ together "+
	"into an %^C243%^ungodly %^CRST%^mixture. The "+
	"sounds it makes from %^C203%^several "+
	"mouths%^CRST%^ is mere jibberish now.\n");
    set_race("demon");
    set_body_type("arachnid");
    set_property("swarm", 1);
    set_overall_ac(-44);
    set_hd(48);
    set_size(4);
    set_wielding_limbs(({ "left front claw", "right rear claw" }));
    set_attacks_num(6);
    set_attack_limbs(({ "left wing", "right wing", "tail",
                        "left rear claw", "right rear claw", "left front claw",
                        "right front claw", "head" }));
    set_base_damage_type("bludgeoning");
    set_damage(4, 20);
    set_moving(1);
    set_speed(20);
    set_max_hp(2000 + random(1000));
    set_hp(query_max_hp());
    set_mob_magic_resistance("average");

    switch (random(4)) {
    case 0:
        set_all_stats(({ 30, 30, 30, 12, 12, 12 }));
        set_class("fighter", 48);
        set_funcs(({ "stuns", "slashes" }));
        set_func_chance(35);
        break;

    case 1:
        set_all_stats(({ 20, 20, 30, 30, 12, 12 }));
        set_class("mage", 48);
        set_spells(({
            "magic missile",
            "fireball",
            "lightning bolt",
            "hideous laughter",
            "cone of cold",
            "meteor swarm",
        }));

        set_spell_chance(110);
        break;

    case 2:
        set_all_stats(({ 20, 20, 30, 12, 12, 30 }));
        set_class("sorcerer", 48);
        set_spells(({
            "horrid wilting",
            "weird",
            "wail of the banshee",
            "shadow nova",
        }));
        set_spell_chance(45);
        set_funcs(({ "obliterate" }));
        set_func_chance(45);
        break;

    case 3:
        set_all_stats(({ 30, 30, 30, 12, 12, 12 }));
        set_class("barbarian", 48);
        set_funcs(({ "stuns", "slashes" }));
        set_func_chance(110);
        break;
    }
    set("aggressive", 100);
    set_alignment(9);

    set_new_exp(48, "high");

    set_funcs(({ "stuns" }));
    set_func_chance(50);

    add_money("gold", 500 + random(10000));
}

void stuns(object targ)
{
    string me;
    int mod;
    if (!objectp(TO) || !objectp(targ)) {
        return;
    }
    me = TO->query_short();
    if (!intp(mod = TO->query("damage mod")) || mod < 1) {
        mod = 1;
    }
    if(!load_object("/daemon/saving_throw_d")->do_save(targ, 75, "will") &&
        !targ->query_property("no paralyze")) {
        tell_room(ETO, me + " " + targ->query_cap_name() + "!", targ);

        tell_object(targ, me + " !");
        targ->do_damage("torso", (roll_dice(1, 100) * mod));
        targ->set_paralyzed(roll_dice(3, 2),
                            "%^RESET%^%^RED%^You are entranced by the gurgles!");
        return;
    }else {
        tell_object(targ, me + " gurgles but you ignore it!");
    }
}

void slashes(object targ)
{
    string me, * alimbs, limb;
    int mod, dam, x;
    object* ats;
    if (!objectp(TO) || !objectp(targ)) {
        return;
    }
    me = TO->query_short();
    if (!intp(mod = TO->query("damage mod")) || mod < 1) {
        mod = 1;
    }
    alimbs = TO->query_attack_limbs();
    for (x = 0; x < sizeof(alimbs); x++) {
        if (!objectp(TO)) {
            return;
        }
        if (!objectp(targ)) {
            if (!sizeof(ats = TO->query_attackers())) {
                return;
            }
            targ = ats[random(sizeof(ats))];
            if (!objectp(targ)) {
                return;
            }
        }
        limb = targ->return_target_limb();
        tell_object(targ, me + "%^BOLD%^%^BLACK%^ slams into your " + limb + " with its " + alimbs[x] + "!%^RESET%^");

        tell_room(TO, me + "%^BOLD%^%^BLACK%^ slams into " + targ->QCN + "%^BOLD%^%^BLACK%^'s " +
                  limb + " with its " + alimbs[x] + "!%^RESET%^", targ);

        targ->do_damage(limb, roll_dice(8, 4) * mod);
        continue;
    }
    return;
}

void obliterate(object targ)
{
    string me, mySpells = ({ "/cmds/spells/f/_fireball", "/cmds/spells/p/_powerword_stun", "/cmds/spells/p/_powerword_kill" });
    string* myPhrases = ({ "Give in!", "Join us!", "You will die!",
                           "This will be ours!", "You will fall!", "Succumb!",
                           "Give us the book!", "Cracks will form!" });
    string mySpell, myPhrase;
    int mod, x;
    object* ats;
    if (!objectp(TO) || !objectp(targ)) {
        return;
    }
    me = TO->query_short();
    if (!intp(mod = TO->query("damage mod")) || mod < 1) {
        mod = 1;
    }
    for (x = 0; x < sizeof(mySpells); x++) {
        if (!objectp(TO)) {
            return;
        }
        if (!objectp(targ)) {
            if (!sizeof(ats = TO->query_attackers())) {
                return;
            }
            targ = ats[random(sizeof(ats))];
            if (!objectp(targ)) {
                return;
            }
        }
        mySpell = mySpells[x];
        myPhrase = myPhrases[random(sizeof(myPhrases))];

        tell_object(targ, me + "%^BOLD%^%^WHITE%^ turns to you and growls: \n%^BOLD%^%^BLACK%^%^FLASH%^" + myPhrase + "\n%^RESET%^");

        tell_room(ETO, me + "%^BOLD%^%^WHITE%^ faces " + targ->QCN + "%^BOLD%^%^WHITE%^ and growls: \n%^BOLD%^%^BLACK%^%^FLASH%^" +
                  myPhrase + "\n%^RESET%^", targ);

        new(mySpell)->use_spell(TO, targ, (10 + random(TO->query_highest_level() * mod)), 100, "mage");
        continue;
    }
    return;
}

