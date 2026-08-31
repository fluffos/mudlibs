//      /bin/user/_iwho.c

#include <std.h>
#include <daemons.h>

/*the number of groups with different idle times that the list will be
  split into*/
#define NUMGROUPS (8)
//#define DEBUG

/* the formula that will be used to segregate users into the different groups.
   each group will have an idle time frame twice as large as the previos one.
   For example, if the segregation standard is 2.5 minutes, the first group 
   will be those with idle times 2.5 and below, the second will be those with
   idle times 5.0 and below, the third will be those with idle times 10.0 and
   below, and so on. */
#define SEG_STANDARD_IN_MINS (2.5)
#define SEGREGATION_STANDARD (SEG_STANDARD_IN_MINS * 60)

inherit DAEMON;

int cmd_iwho(string str) {
    object *allPlayers = users();
    /*a two-dimensional player array, the players will be sorted into these
     *groups based off their idle times and the group's thresholds*/
    mixed *idleGroups = ({});
    /*counts the number of players that the player will be told is online*/
    int visPlayers = 0;
    /*The idle groups thresholds. In order to be placed into this idle group,
     *a player cannot have an idle time larger than the associated threshold*/
    int *groupThreshold = ({});
    /*each player will be stored into one of these four groups based off their
     *position (admin/imm/player/etc), so that they can be evaluated in order
     *and will show up on the who list in that order*/
    mixed *playerPositions = ({ ({}), ({}), ({}), ({}) });

    //sort each player into one of the four position groups
    foreach (object p in users()) {
	if (admp(p)) playerPositions[0] += ({ p });
	else if (archp(p)) playerPositions[1] += ({ p });
	else if (wizardp(p)) playerPositions[2] += ({ p });
	else playerPositions[3] += ({ p });
    }

    //initialize group data - create empty groups and set group thresholds
    for (int i=0; i<NUMGROUPS; i++) {
	idleGroups += ({ ({}) });
	groupThreshold += ({ to_int(SEGREGATION_STANDARD * pow(2,(i))) });
    }  

    // sort each player into their specific group identity based off idle time
    for(int playerGroup = 0; playerGroup < 4; playerGroup++) {
	/*sort players into idle groups by their position, so that admins show up
	 *at the top of the list, then arches, imms, and players. */
	foreach (object p in playerPositions[playerGroup]) {

#ifdef DEBUG
	    write("DEBUG: placing player "+p->query_name()+" into an idle group. (idle time "+query_idle(p)+")");
#endif

	    /* iterate through the group identitities until the player's idle time
	     * is less than the max idle time for that specific group, or until the
	     * max number of groups is reached. Once either has happened, break the
	     * loop and enter the player into the group with the current group
	     * identity */
	    if(p->isVisible() || wizardp(this_player())) {

		for(int i = 0; i < NUMGROUPS; i++) {
#ifdef DEBUG
		    write("DEBUG: comparing idle time to group "+i+": threshold "+groupThreshold[i]);
#endif
		    if(query_idle(p) < groupThreshold[i] || i == NUMGROUPS - 1) {
#ifdef DEBUG
			write("DEBUG: player matched to group");
#endif
			visPlayers++;
			idleGroups[i] += ({ p });
			break;
		    }
		}
	    }  
	}
    }  

    /* players organized into their respective groups. Insert data here to
     * micro-organize each group into smaller groups if desired */

    // print idle information

    write("%^RESET%^%^BLUE%^"
      +"+=+=+=+=+=+=+=+=+=+=+=+=+=+=+%^BOLD%^( %^WHITE%^Primal Darkness"
      +" %^BLUE%^)%^RESET%^%^BLUE%^=+=+=+=+=+=+=+=+=+=+=+=+=+=+=");

    for(int i = 0; i < NUMGROUPS; i++) {
	string line;
	if(sizeof(idleGroups[i]) <= 0)
	    continue;

	/*print idle time message group divider */
	if(i == 0) {
	    line = "%^BOLD%^%^WHITE%^Active Players%^RESET%^";
	}
	else {
	    line = "%^BOLD%^%^BLACK%^" +"Idle time: ";
	    //doesn't convert to a float correctly without multiplying by 1.0
	    line += sprintf("%.1f", (groupThreshold[i-1]*1.0 / 60));
	    line += ((i==(NUMGROUPS-1))?"+":"") + " minutes." + "%^RESET%^";
	}
	write(line);

	for(int x = 0; x < sizeof(idleGroups[i]); x++) {

	    /* Paste all of the specific user's data into string variable 'line'
	     * before writing it to the requesting user. */
	    if(admp(idleGroups[i][x])) {
		line = "%^BLUE%^[%^BOLD%^Admin %^RESET%^%^BLUE%^]%^BOLD%^ ";
	    }
	    else if(archp(idleGroups[i][x])) {
		line = "%^ORANGE%^[%^BOLD%^Arch  %^RESET%^%^ORANGE%^]%^BOLD%^ ";
	    }  
	    else if(wizardp(idleGroups[i][x])) {
		line = "%^MAGENTA%^[%^BOLD%^Immrtl%^RESET%^%^MAGENTA%^] ";
	    }  
	    else {
		line = "%^CYAN%^[%^BOLD%^Player%^RESET%^%^CYAN%^] ";
	    }
	    if(idleGroups[i][x]->query_invis())
		//line += sprintf("%-45s ", capitalize(idleGroups[i][x]->query_name()));
		line += "("+ capitalize(idleGroups[i][x]->query_name()) +")";
	    else
		//line += sprintf("%-45s ", idleGroups[i][x]->query_title());
		line += idleGroups[i][x]->query_title();

	    line = arrange_string(line, 55);

	    line += "%^RESET%^%^WHITE%^";
	    if(wizardp(idleGroups[i][x])) {
		if(archp(idleGroups[i][x]))
		    line += "%^BOLD%^";
		line += sprintf("%-20s", idleGroups[i][x]->query_position());
	    }  
	    else {
		line += sprintf("%%^BOLD%%^%-10s %%^CYAN%%^%-10s",
		  capitalize(idleGroups[i][x]->query_race()),
		  capitalize(idleGroups[i][x]->query_class()));
	    }  

	    write(line);
	}  
    }

    write("%^RESET%^%^BLUE%^=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+"
      +"=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=");
    write("%^WHITE%^%^BOLD%^"+visPlayers+" player"+ (visPlayers!=1 ? "s":"")
      +" online.\n");

    return 1;
}

void help() {
    write("Syntax: <idlewho>\n\n"
      "Like the /who command, organized instead by idle time"
      "\n\nSee also: who, finger"
    );
}
