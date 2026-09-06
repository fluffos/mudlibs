#include <living_defs.h>
#include <sound.h>
#include <attack.h>
#include <conditions.h>
#include <invis_levels.h>

status wear_me(object who) {
    object *armour_set;
    int count = 1;

    if (authentic) {
	armour_set = allocate(12);

	armour_set[0] = present("#windweaver amulet#", who);
	armour_set[1] = present("#windweaver belt#", who);
	armour_set[2] = present("#windweaver boots#", who);
	armour_set[3] = present("#windweaver bracers#", who);
	armour_set[4] = present("#windweaver cloak#", who);
	armour_set[5] = present("#windweaver gauntlets#", who);
	armour_set[6] = present("#windweaver helmet#", who);
	armour_set[7] = present("#windweaver leggings#", who);
	armour_set[8] = present("#windweaver mask#", who);
	armour_set[9] = present("#windweaver full plate#", who);
	armour_set[10] = present("#windweaver ring#", who);
	armour_set[11] = present("#windweaver shield#", who);

	foreach (object armour : armour_set) {
	    if (objectp(armour) && armour != this_object()
	      && armour->query_worn()) {
		count++;
	    }
	}

	if (!who->query(LIV_IS_NPC)) {
	    switch (count) {
	    case 11:
		set_heart_beat(1);
		environment(who)->tell_here("You hear the whistle of wind!");
		who->sound(SD_SOUND_WIND, SD_VOLUME_LOW);
		break;
	    case 10:
		if (!who->query_invis()) {
		    who->tell_me("You turn invisible in a puff of smoke!");
		    who->invis();
		}
		break;
	    case 9:
		if (!who->query_condition(RESISTANCE(C_POISONED))) {
		    who->set_condition(RESISTANCE(C_POISONED), -1, this_object());
		    who->tell_me("You feel more resistant to poison!");
		}
		break;
	    case 8:
		if (!who->query_condition(RESISTANCE(C_UNCONSCIOUS))) {
		    who->set_condition(RESISTANCE(C_UNCONSCIOUS), -1, this_object());
		    who->tell_me("You feel more resistant to unconsciousness!");
		}
		break;
	    case 7:
		if (!who->query_condition(RESISTANCE(C_STUNNED))) {
		    who->set_condition(RESISTANCE(C_STUNNED), -1, this_object());
		    who->tell_me("You feel more resistant to stunning!");
		}
		break;
	    case 6:
		if (!who->query_condition(RESISTANCE(C_BLIND))) {
		    who->set_condition(RESISTANCE(C_BLIND), -1, this_object());
		    who->tell_me("You feel more resistant to blindness!");
		}
		break;
	    }
	}
    }
    return ::wear_me(who);
}

status unwear_me(object who) {
    object *armour_set;
    int count = 1;

    if (authentic) {
	armour_set = allocate(12);

	armour_set[0] = present("#windweaver amulet#", who);
	armour_set[1] = present("#windweaver belt#", who);
	armour_set[2] = present("#windweaver boots#", who);
	armour_set[3] = present("#windweaver bracers#", who);
	armour_set[4] = present("#windweaver cloak#", who);
	armour_set[5] = present("#windweaver gauntlets#", who);
	armour_set[6] = present("#windweaver helmet#", who);
	armour_set[7] = present("#windweaver leggings#", who);
	armour_set[8] = present("#windweaver mask#", who);
	armour_set[9] = present("#windweaver full plate#", who);
	armour_set[10] = present("#windweaver ring#", who);
	armour_set[11] = present("#windweaver shield#", who);

	foreach (object armour : armour_set) {
	    if (objectp(armour) && armour != this_object()
	      && armour->query_worn()) {
		count++;
	    }
	}

	if (!who->query(LIV_IS_NPC)) {
	    if (count < 11) {
		set_heart_beat(0);
	    }

	    switch (count) {
	    case 11:
		who->tell_me("The wind dies down.");
		break;
	    case 10:
		if (who->query_invis()) {
		    who->tell_me("You turn visible in a puff of smoke!");
		    who->vis();
		}
		break;
	    case 9:
		if (who->query_condition(RESISTANCE(C_POISONED))) {
		    foreach (object armour : ARMOUR_SET_D->query_armour_set("windweaver")) {
			who->set_condition(RESISTANCE(C_POISONED), 0, armour);
		    }

		    who->tell_me("You feel less resistant to poison!");
		}
		break;
	    case 8:
		if (who->query_condition(RESISTANCE(C_UNCONSCIOUS))) {
		    foreach (object armour : ARMOUR_SET_D->query_armour_set("windweaver")) {
			who->set_condition(RESISTANCE(C_UNCONSCIOUS), 0, armour);
		    }

		    who->tell_me("You feel less resistant to unconsciousness!");
		}
		break;
	    case 7:
		if (who->query_condition(RESISTANCE(C_STUNNED))) {
		    foreach (object armour : ARMOUR_SET_D->query_armour_set("windweaver")) {
			who->set_condition(RESISTANCE(C_STUNNED), 0, armour);
		    }

		    who->tell_me("You feel less resistant to stunning!");
		}
		break;
	    case 6:
		if (who->query_condition(RESISTANCE(C_BLIND))) {
		    foreach (object armour : ARMOUR_SET_D->query_armour_set("windweaver")) {
			who->set_condition(RESISTANCE(C_BLIND), 0, armour);
		    }

		    who->tell_me("You feel less resistant to blindness!");
		}
		break;
	    }
	}
    }

    return ::unwear_me(who);
}

void heart_beat() {
    object wearer, target;

    // This was random(11), which was not bad, however there are too few
    // players on the mud, and too few reboots, so the same people are
    // getting and keeping this eq set for so long and racking up too high
    // of an exprate, so something must be done (per Tron's request)
    // -Tamarindo 04/2006
    if (!random(50)) {
	if (!(wearer = query_worn_by()) || !interactive(wearer)) {
	    return;
	}

	if (wearer->query_ghost() || wearer->query_dead()) {
	    return;
	}

	if ((target = wearer->query_attack()) && present(target, environment(wearer))) {
	    environment(wearer)->tell_here(":%<me.capname>% spin%<me.ending_s>% at \
magnificient speed creating a gathering wind whose howl hurts your ears.  \
%<cap(me.pronoun)>% reach%<me.ending_es>% maximum velocity and %<me.possessive>% surrounding tornado \
tears up large chunks of debris.  The whirlwind completely demolishes %<him.name>%!",
	      0, 0, 0, wearer, target, 0);
	    environment(wearer)->sound(SD_SOUND_TORNADO);

	    wearer->attacked_by(target, 1);
	    // Tamarindo 04/2006
	    //target->hit_player(target->query_max_hp() / 4, DT_EARTH, 7, wearer);
	    target->hit_player(target->query_max_hp() / 8, DT_EARTH, 7, wearer);

	    if (target && !target->query_ghost() && !target->query_dead()) {
		// Tamarindo 04/2006
		//target->hit_player(target->query_max_hp() / 6, DT_AIR, 7, wearer);
		target->hit_player(target->query_max_hp() / 12, DT_AIR, 7, wearer);
	    }

	    foreach (object attacker : wearer->query_attackers()) {
		if (!attacker || attacker == target) {
		    continue;
		}

		if (present(attacker, environment(wearer))) {
		    environment(wearer)->tell_here(":%<him.capname>% get%<him.ending_s>% caught up in \
the whirlwind!",
		      0, 0, 0, wearer, attacker, 0);

		    wearer->attacked_by(attacker, 1);
		    // Tamarindo 04/2006
		    //attacker->hit_player(attacker->query_max_hp() / 6, DT_EARTH, 4, wearer);
		    attacker->hit_player(attacker->query_max_hp() / 12, DT_EARTH, 4, wearer);

		    if (attacker && !attacker->query_ghost() && !attacker->query_dead()) {
			// Tamarindo 04/2006
			//attacker->hit_player(attacker->query_max_hp() / 8, DT_AIR, 4, wearer);
			attacker->hit_player(attacker->query_max_hp() / 16, DT_AIR, 4, wearer);
		    }
		}
	    }
	} else {
	    if (random(10)) {
		environment(wearer)->tell_here("You hear the whistle of wind!");
		environment(wearer)->sound(SD_SOUND_WIND);
	    }
	}
    }

    return;
}
