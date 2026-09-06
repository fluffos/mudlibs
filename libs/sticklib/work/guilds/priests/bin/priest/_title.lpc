#include "../../priest.h"
#include <gender.h>

string *male_titles, *fem_titles;

create() {
    male_titles = ({
      "a Child of Boccob", "a New Son of Boccob",
      "a Friar of Shadow", "a Friar of Darkness",
      "a Friar of Light", "a Friar of Boccob",
      "a Priest of Shadow", "a Priest of Darkness",
      "a Priest of Light", "a Priest of Boccob",
      "a Master Priest of Shadow", "a Master Priest of Darkness",
      "a Master Priest of Light", "a Master Priest of Boccob",
      "an Arch-Priest of Shadow", "an Arch-Priest of Darkness",
      "an Arch-Priest of Light", "an Arch-Priest of Boccob",
      "an Holy Messenger of Boccob", "a Holy Lord of Boccob",
      "a Lord Priest of Boccob", "a Lord Arch-Priest of Boccob",
      "an Abbott of Darkness", "an Abbott of Light",
      "a Lord Abbott of Boccob", "a Prior of Darkness",
      "a Prior of Light", "a Lord Prior of Boccob",
      "a Monsigneur of Darkness", "a Monsigneur of Light",
      "a Lord Monsigneur of Boccob", "a Bishop of Darkness",
      "a Bishop of Light", "a Lord Bishop of Boccob",
      "an Archbishop of Darkness", "an Archbishop of Light",
      "a Lord Archbishop of Boccob", "a Cardinal of Darkness",
      "a Cardinal of Light", "a Lord Cardinal of Boccob",
      "a Pontiff of Darkness", "a Pontiff of Light",
      "a Lord Pontiff of Boccob", "a Prophet of Darkness",
      "a Prophet of Light", "a Lord Prophet of Boccob",
      "a Saint of Boccob", "a Cherubim of Boccob",
      "a Seraphim of Boccob", "an Angel of Darkness",
      "an Angel of Light", "an Arch-Angel of Darkness",
      "an Arch-Angel of Light", "a Demigod of Boccob",
    });

    fem_titles = ({
      "a Child of Boccob", "a New Daughter of Boccob",
      "a Devout Sister of Shadow", "a Devout Sister of Darkness",
      "a Devout Sister of Light", "a Devout Sister of Boccob",
      "a Priestess of Shadow", "a Priestess of Darkness",
      "a Priestess of Light", "a Priestess of Boccob",
      "a Master Priestess of Shadow", "a Master Priestess of Darkness",
      "a Master Priestess of Light", "a Master Priestess of Boccob",
      "an Arch-Priestess of Shadow", "an Arch-Priestess of Darkness",
      "an Arch-Priestess of Light", "an Arch-Priestess of Boccob",
      "an Holy Messenger of Boccob", "a Holy Lady of Boccob",
      "a Lady Priestess of Boccob", "a Lady Arch-Priestess of Boccob",
      "an Abbottess of Darkness", "an Abbottess of Light",
      "a Lady Abbottess of Boccob", "a Prioress of Darkness",
      "a Prioress of Light", "a Lady Prioress of Boccob",
      "a Monsigneura of Darkness", "a Monsigneura of Light",
      "a Lady Monsigneura of Boccob", "a Bishop of Darkness",
      "a Bishop of Light", "a Lady Bishop of Boccob",
      "an Archbishop of Darkness", "an Archbishop of Light",
      "a Lady Archbishop of Boccob", "a Cardinal of Darkness",
      "a Cardinal of Light", "a Lady Cardinal of Boccob",
      "a Pontiffa of Darkness", "a Pontiffa of Light",
      "a Lady Pontiffa of Boccob", "a Prophetess of Darkness",
      "a Prophetess of Light", "a Lady Prophetess of Boccob",
      "a Saint of Boccob", "a Cherubim of Boccob",
      "a Seraphim of Boccob", "an Angel of Darkness",
      "an Angel of Light", "an Arch-Angel of Darkness",
      "an Arch-Angel of Light", "a Demigoddess of Boccob",
    });
}

string
get_title(int lvl, int gender) {    
    if(lvl > sizeof(male_titles)) lvl = sizeof(male_titles);
    switch(gender) {
    case G_MALE:
	return male_titles[lvl-1];
    case G_FEMALE:
	return fem_titles[lvl-1];
    default:
	return "Eunuch of Boccob"; // *grin*
    }
}

status
title_cmd(object who, object sym, string s) {
    int gend, lvl;
    string gend_str, tmp;

    notify_fail("Usage: priest title [-list f/m]\n");
    if(!s) {
	gend = who->query_gender();
	lvl = who->query_level();
	who->set_title(get_title(lvl, gend));
	who->tell_me("Your title is now changed to something more suitable \
for a follower of Boccob.\n");
	return 1;
    }

    if(sscanf(s, "-list %s", gend_str) != 1)
	return 0;
    switch(gend_str) {
    case "f":
	who->more(fem_titles);
	break;
    case "m":
	who->more(male_titles);
	break;
    default:
	return 0;
    }
    return 1;
}

int
clean_up(int arg) {
    destruct(this_object());
    return 0;
}
