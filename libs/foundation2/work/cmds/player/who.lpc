#include <lib.h>
#include <config.h>

inherit LIB_DAEMON;

mixed cmd(string args) {
    string *lines;
    object *avatars, *hms, *norms, *newbies, *adms, *cres, *obs;
    int i, x, screen;

    x = sizeof(obs=filter(users(), (: !((int)$1->GetInvis(this_player())) :)));
    obs = obs - (avatars = filter(obs, (: avatarp :)));
    obs = obs - (hms = filter(obs, (: high_mortalp :)));
    obs = obs - (adms = filter(obs, (: archp :)));
    obs = obs - (cres = filter(obs, (: creatorp :)));
    newbies = obs - 
      (norms = filter(obs, (: (int)$1->GetLevel() > MAX_NEWBIE_LEVEL :)));
    screen = ((int *)this_player()->GetScreen())[0];
    lines = ({ center(mud_name(), screen),
		 center("There are " + x + " members of our reality!", screen),
		 ""  });
    if( i = sizeof(avatars) ) {
	lines += ({ capitalize(consolidate(i, "avatar")) + ":" });
	while(i--) lines += ({ "\t" + (string)avatars[i]->GetShort() });
	lines += ({ "" });
    }
    if( i = sizeof(hms) ) {
	lines += ({ capitalize(consolidate(i, "high mortal")) + ":" });
	while(i--) lines += ({ "\t" + (string)hms[i]->GetShort() });
	lines += ({ "" });
    }
    if( i = sizeof(norms) ) {
	lines += ({ capitalize(consolidate(i, "mortal")) + ":" });
	while(i--) lines += ({ "\t" + (string)norms[i]->GetShort() });
	lines += ({ "" });
    }
    if( i = sizeof(newbies) ) {
	lines += ({ capitalize(consolidate(i, "newbie")) + ":" });
	while(i--) lines += ({ "\t" + (string)newbies[i]->GetShort() });
	lines += ({ "" });
    }
    if( i = sizeof(cres) ) {
	lines += ({ capitalize(consolidate(i, "creator")) + ":" });
	while(i--) lines += ({ "\t" + (string)cres[i]->GetShort() });
	lines += ({ "" });
    }
    if( i = sizeof(adms) ) {
	lines += ({ capitalize(consolidate(i, "arch")) + ":" });
	while(i--) lines += ({ "\t" + (string)adms[i]->GetShort() });
	lines += ({ "" });
    }
    this_player()->more(lines, "system");
    return 1;
}

