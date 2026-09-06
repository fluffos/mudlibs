#include "../priest.h"

#define HERE environment(who)

status
sample_cmd(object who, object sym, string str) {
    object corpse, sbottle;
    string o_name, o_race;
    int o_level;

    if(!who) return 0;
    if(!present("s_scalpel", who))
	return notify_fail("You can't take samples without a scalpel!\n"),0;
    if(!str)
	return notify_fail("Sample what?\n"), 0;
    corpse = present(str, HERE);
    if(!corpse)
	return notify_fail("But that's not here.\n"),0;

    if(!corpse->query_real_corpse())
	return notify_fail("You can't do that!\n"),0;

    if(corpse->query_decay() < 5)
	return notify_fail("That's too rotten for your purposes.\n"),0;

    if(!(sbottle = present("sample_bottle", who)))
	return notify_fail("You don't have a sample bottle!\n"),0;
    if(sbottle->query_max_full() > 1)
	return notify_fail("That bottle is too large to be used as a sample bottle.\n"),0;

    o_race = corpse->query_orig_race();
    o_name = corpse->query_orig_name();
    o_level = corpse->query_orig_level();
    if(!o_race)
	return notify_fail("It's blood is not suitable for your purposes.\n"),0;

    who->tell_me(sprintf("You take the scalpel into your hand and make a \
clean cut on the corpse. You fill the sample bottle with %s's blood. \
", o_race));

    HERE->tell_here(":%<me.capname>% makes a small incission in %<1>%'s \
corpse and fills a small bottle with the blood that seeps from this \
incission.",0,({0,o_name}),who,who,0,0);
    corpse->set_decay(4);

    sbottle->fill_with_blood(o_race, o_level);
    return 1;
}
