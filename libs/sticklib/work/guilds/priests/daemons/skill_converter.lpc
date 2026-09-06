// SKILL CONVERTER - converts level & alchemy skills suitable for the
// new guild

#include "../priest.h"
#include "../skills.h"

// from old guild:
#define GET_SKILLS(x) PRIEST_OBJ_DIR "get_skills"->get_skills(x)

#define OLD_PRIESTS ({ "ramlin", "eomer", "venom", "jarman", "spackle", \
    "obsidian", "hanger", "terak", "slade", "bodar" })

#define NEW_PRIESTS ({ "gethsemane", "peewee", "kosonik", "trinsic", \
    "thornwall", "borkan", "moraine", "cloak", "eridar" })

inherit PSKILLS;

create() {
}


int
calc_new_alc_pex(int old_skill) {
    return skill2pex(1400 * old_skill / (500 + old_skill));
}


void
convert_skills(object pl, int version, int *pexes, int order) {
    int base,i,level;
    int *old_skills, old_coef;

    if(member(NEW_PRIESTS, pl->query_real_name()) >= 0)
	return;

    pl->tell_me("Converting your skills....");

    level = pl->query_level();

    // Players higher than 40 level gets a small "punishment",
    // for a level 90 player, this means getting level's 65 skills.
    base = level - level*level*level/30000;

    base = to_int(BASE_COST*base*base/60); // average skill player will get
    if(member(OLD_PRIESTS, pl->query_real_name())>=0)
	base = 115*base/100; // let's give a bonus for very old priests

    old_skills = GET_SKILLS(pl->query_real_name());
    if(pointerp(old_skills)) {
	write("Old alchemy skills found.\n");
	for(i=0;i<7;i++)
	    old_coef += old_skills[i];
	if(old_coef>2500)
	    old_coef = 2500 + (old_coef-2500) / 3;
	base = (100 + old_coef/150) * base / 100;
	// max 20% bonus from old coef
    }

    for(i=0;i<5;i++) // the 5 first skills:
	pexes[i] = (100 + order*ORDER_BONUSES[i]) * base / 100;

    if((version == -1) && pointerp(old_skills)) {
	pexes[SK_ALCHEMY] = calc_new_alc_pex(old_skills[0]);
	pexes[SK_HEAL_MIN] = calc_new_alc_pex(old_skills[1]);
	pexes[SK_HEAL_MAJ] = calc_new_alc_pex(old_skills[2]);
	pexes[SK_LES_RES] = calc_new_alc_pex(old_skills[3]);
	pexes[SK_GRE_RES] = calc_new_alc_pex(old_skills[4]);
	pexes[SK_INVIS] = calc_new_alc_pex(old_skills[5]);
	pexes[SK_INVULN] = calc_new_alc_pex(old_skills[6]);
    }
    // and we are done
    pl->tell_me("Ok.");
}


void
test_converter(int version) {
    object pl, sym;
    int *pexes;

    pl = this_player();
    printf("pl: %O\n", pl);
    sym = pl->query_guild_object();
    pexes = sym->query_pexes();
    convert_skills(pl, version, pexes, 0);
}

int
clean_up(int arg) {
    destruct(this_object());
    return 0;
}
