/*
** File: /d/class/std/daemons/learn.c (Learn Daemon v2.1)
** Purpose: The spell-learning daemon for all wizards.
** Notes: This is a very ugly bit of code to write and possibly debug, 
**   thus it is HEAVILY commented for the sake of the sanity of anybody
**   else besides its creator who may have to read it.
** Credits:
**   18 Aug 97   Cyanide wrote Learn v2.0
**   25 Sep 97   Cyanide added a few functions and enhanced generally.
**   28 Nov 97   Cyanide changed all the two-D string arrays to mappings
**               of ([ "spell" : lvl ]); they are simpler, less buggy, 
**               more robust, and self-checking (to an extent).
*/

inherit DAEMON;

// Prototypes
mapping get_spell_list (object);
void begin_learn (object);
string tell_options(object, mapping);
string input_string (string, object, mapping);
int get_max_spell_level (object);
mapping filter_mapping (mapping, int);

/*
#define LOG_FILE "/open/learn.debug"
#include "/u/c/cyanide/fdebug.h"
#define DEBUG(x) flog(LOG_FILE, x);
*/

#include <m_spells.h>

// This is the normal maximum of spell a caster may be given to choose 
// from for any given spell level. It may be added to by the 
// "thaumaturgy" proficiency and specialization.
#define BASE_MAX 3

// This is the upper limit on spell power.  Eventually, 10th level magic
// may be added, but 9 is the standard.
#define MAX_SPELL_LEVEL 10

/*
** Function: get_spell_list()
** Purpose: Determines the list of spell a player may choose according to
**    their level, their previous spell, their specialization, their 
**    proficiencies, and luck.
** Receives: object player (the spell caster in question)
** Returns: mapping (the list of spells the player may choose from)
** Variables:
**    int 
**       x, loopLvl         Loop counters
**       max_lvl            The caster's maximum learnable spell level
**       MAXES              The players max # of spells offered at each 
**                          spell level. We pretend it's a constant.
**       flag               A flag variable for the primary loop
**    string
**       specialization     player's school of specialization
**       skool              The school of magic we're working with @ the
**                          moment.
**       *known_spells      (array) List of spells a player knows.
**       *oppositions       (array) The player's opposition schools.
**    mapping
**       tmpBySchool        A temporary of all spells of current working
**                          school.
**       tmp_list           A temporary spell list.
**       spells             The main spells list that will be returned.
*/

mapping get_spell_list (object player) {
    int x, loopLvl, max_lvl = 0, flag = 1, MAXES = BASE_MAX;
    string specialization = "none", *known_spells, skool, *oppositions;
    mapping spells = ([]), tmp_list = ([]), tmpBySchool, mapLocal = ([]);
    string foo = "";   // For debug purposes.

    known_spells = player->query("mage_spells");        // If string *
  //known_spells = keys(player->query("mage_spells"));  // If mapping
    if (!known_spells) known_spells = ({});

    max_lvl = get_max_spell_level(player);
#ifdef DEBUG
    flog(LOG_FILE, "Max lvl: "+max_lvl+"\n");
#endif

    oppositions = ({});
    if (player->query("opposition_schools"))
	oppositions = player->query("opposition_schools");

    if (player->query("specialization"))
	specialization = player->query("specialization");

    // If a player is a specialist, they get a bonus spell.
    if (!(!specialization || specialization=="none")) MAXES++;
    if (player->query_skill("Thaumaturgy")) MAXES++;

#ifdef DEBUG
    DEBUG("Max #spells: "+MAXES+"\n");
#endif

    flag = 1;   // Just in case - this is important.
    while (flag) {
	switch (flag) {
	case 1 : tmpBySchool = UNIVERSAL; skool = "universal"; break;
	case 2 : tmpBySchool = ABJURATION; skool = "abjuration"; break;
	case 3 : tmpBySchool = ALTERATION; skool = "alteration"; break;
	case 4 : tmpBySchool = CONJURATION; skool = "conjuration"; break;
	case 5 : tmpBySchool = DIVINATION; skool = "divination"; break;
	case 6 : tmpBySchool = ENCHANTMENT; skool = "enchantment"; break;
	case 7 : tmpBySchool = ILLUSION; skool = "illusion"; break;
	case 8 : tmpBySchool = INVOCATION; skool = "invocation"; break;
	default : tmpBySchool = NECROMANCY; skool = "necromancy"; 
	    flag = -1;  // At the end of the "while", this becomes 0,
	    // thereby becoming false and endling the loop
	    break;
	}

	// You may want to stop at this point and get a Tylenol.
	// (25 Nov 97) Cyanide did.

	// If the school isn't an opposition school:
	if (member_array(skool, oppositions)==-1) {

#ifdef DEBUG
	    DEBUG("\nSchool: "+skool+".\n");
#endif

	    // This loops check each individual spell for validity and either
	    // ignores it or adds it to the refined "tmp_list" mapping.
	    for (x=sizeof(keys(tmpBySchool))-1; x>=0; x--) {
		int to_keep = 1, spLevel;
		string spName;

		spName = (keys(tmpBySchool))[x];
		spLevel = (values(tmpBySchool))[x];       

#ifdef DEBUG
		DEBUG("  "+spName+" ("+spLevel+") ");
#endif

		// If they know the spell, remove from tmpBySchool:
		if (member_array((keys(tmpBySchool))[x], known_spells) != -1)
		    to_keep = 0;
		if ((values(tmpBySchool))[x] > max_lvl) to_keep = 0;
		if (spLevel<1) to_keep = 0;
		if (to_keep) tmp_list[spName] = spLevel;
#ifdef DEBUG
		if (to_keep) {
		    DEBUG("\n");
		} else {
		    DEBUG(" (REJECTED)\n");
		}
#endif
	    }

#ifdef DEBUG
	    foo = "Spell Kept: ("+sizeof(tmp_list)+" spells) ";
	    for(x=0;x<sizeof(keys(tmp_list));x++) {
		foo += (keys(tmp_list))[x]+" ";
	    }         
	    DEBUG(iwrap(foo));
#endif

	    tmpBySchool = tmp_list;
	    tmp_list = ([]);

	    // This loops goes through the remaining spells and determines
	    // whether or not to add them to the main "spell" list.
	    for (x = sizeof(keys(tmpBySchool))-1; x>=0; x--) {
		int spLevel;
		string spName;

		spName = (keys(tmpBySchool))[x];
		spLevel = (values(tmpBySchool))[x];

		//  Removed until we get more spells.  Cyanide - 29 Jan 98
		//          if ((skool==specialization||skool=="universal")||random(2)) {
		//             tmp_list += ([ spName : spLevel ]);
		//          }
#ifdef DEBUG
		DEBUG("   "+spName+" added.  (x="+x+")\n");  
#endif

		tmp_list += ([ spName : spLevel ]);
	    }
#ifdef DEBUG
	    DEBUG("\n");
#endif
	    spells += tmp_list;
	} else {
#ifdef DEBUG
	    DEBUG("Opposed to "+skool+"\n");
#endif
	}

	tmp_list = ([]);
	flag++;
    }

    // This makes sure the numbers of offered spells per spell
    // level don't exceed the maximum.
    for (loopLvl=1; loopLvl<=max_lvl; loopLvl++) {

	for (x=0; x<sizeof(keys(spells)); x++) {
	    string spName = (keys(spells))[x];
	    int spLevel = (values(spells))[x];
	    if (spLevel==loopLvl) {
		mapLocal += ([ spName : spLevel ]);
	    }
	}

#ifdef DEBUG
	for (x=0; x<sizeof(keys(mapLocal)); x++) {
	    DEBUG("  "+x+"- "+(keys(mapLocal))[x]+"\n");
	}
#endif

	// If the "x"-th level spell are too many, we drop a random one.
	while (sizeof(keys(mapLocal)) > MAXES) { 
	    int intSize = sizeof(keys(mapLocal));
	    mapLocal = filter_mapping( mapLocal, random(intSize) );
	}
	tmp_list += mapLocal;
	mapLocal = ([]);

    } 
    spells = tmp_list;
    tmp_list = ([]);     // Reinitialization.

#ifdef DEBUG
    DEBUG("Total # spells: "+sizeof(keys(spells))+"\n");
#endif

    return spells;
}  /* End get_spell_list() */


/*
** Function: begin_learn()
** Purpose: The first function called to begin everything else.
**    Essentially, the driver.
** Receives: 
**    object player		The player to learn spells.
** Returns:
**    void
** Variables:
**    mapping spell_list	The list of choosable spells
**    int timesChosen       The number of times a player obtained a 
** 							from this daemon.
*/

void begin_learn(object player) {
    mapping spell_list = ([]);
    string strList;
    int plvl;
    int timesChosen = player->query("spells_chosen");

    if (player->query("race")=="dragon") 
	plvl = player->query_level("dragon");
    else
	plvl = player->query_level("wizard");


    if (!plvl) {
	tell_object(player, "You're not a spellcaster!\n"+
	  "Get out of here!\n");
	return;
    }

    if (plvl <= timesChosen) {
	tell_object(player,
	  "You have learned the most you can from here.\n"+
	  "Try again next level.\n");
	return;
    }

    if (player->query("next_spell_list") &&
      sizeof(keys((mapping)player->query("next_spell_list"))) ) {
	spell_list = player->query("next_spell_list");
    } else {
	spell_list = get_spell_list(player);
	player->set("next_spell_list", spell_list);
    }
    strList = tell_options(player, spell_list);
    if (strlen(strList)) {
	tell_object(player, strList);
	input_to("input_string", player, spell_list);
    }
    return;
}  /* End begin_learn() */


/*
** Function: string tell_options()
** Purpose: Returns a string of all the spell a player may choose from,
**    arranged by spell level.
** Receives: 
**    object player	    The player to learn spells.
**    mapping s_list    The learnable spell list mapping.
** Returns:
**    string of available spells.
** Variables:
**   int 
**      intLvl, intSpell	Loop counters
**   string
**      options				Nice pretty list of spells (returned)
**      *strList			A temp list of spellnames.
*/

string tell_options (object player, mapping s_list) {
    string options = "You may choose one of the following:\n";
    string *strList = ({});
    int intLvl, intSpell, maxes;

    maxes = get_max_spell_level(player);
    if (!sizeof(keys(s_list))) {
	player->delete("next_spell_list");
	tell_object(player, "Please try again.\n"+
	  "You have no spells to choose.\n");
	return "";
    }

    for (intLvl=1; intLvl<=maxes; intLvl++) {
	int lvl;
	string spell;

	strList = ({});
	options += "Level "+intLvl+": ";

	for (intSpell=0; intSpell<sizeof(keys(s_list)); intSpell++) {
	    lvl = (values(s_list))[intSpell];
	    spell = (keys(s_list))[intSpell];

	    if (lvl!=intLvl) continue;
	    strList += ({ spell });
	}

	if (!sizeof(strList)) options+=" [ No spells of this level ]\n";
	for (intSpell=0; intSpell<sizeof(strList); intSpell++) {
	    options += capitalize(strList[intSpell]);
	    if (intSpell < (sizeof(strList) - 1)) 
		options += ", ";
	    else
		options += "\n";
	}
    }

    options += "\nYour choice?> ";
    return options;
}   /* End tell_options() */


/*
** Function: void input_string(string, object, mapping)
** Purpose: Receives the input from the user of the choice of spell for
**    the character, and handles the choice appropriately.
** Receives: 
**   string want		The spell chosen by the user
**   object player	    The player to learn spells.
**   mapping s_list		The learnable spell list mapping.
** Returns:
**   void
** Variables:
**   string *strList	The list of spells (array)
*/

string input_string(string want, object player, mapping s_list) {
    string *strList;

    strList = keys(s_list);
    want = lower_case(want);

    if (member_array(want, strList)==-1) {
	tell_object(player, "Sorry, that is not a valid choice.\n");
	return;
    }

    if (player->query("next_spell_list"))
	player->delete("next_spell_list");
    player->add("spells_chosen", 1);
    player->add("mage_spells", ({ want }) );
    tell_object(player, wrap("After intense study, you add "+
	capitalize(want)+" to your spell repitoire.\n"));
    return;
} /* End input_string() */


/*
** Function: int get_max_spell_level (object)
** Purpose: Determines the highest level spell available to the player 
**    passed according to level and intelligence.
** Receives: 
**   object player	    The player to learn spells.
** Returns:
**   int of highest spell level available to the player;
** Variables:
**   int lvl			The level determined.
**   int max_by_int		The max spell level according to the player's 
**						base intelligence rating. 
*/

int get_max_spell_level (object player) {
    int lvl;
    int max_by_int;


    if (player->query("race")=="dragon") 
	lvl = player->query_level("dragon");
    else
	lvl = player->query_level("wizard");

    /*
	if (lvl<11)
	    lvl = (lvl+1)/2;
	else
	    lvl /= 2;
    */
    lvl = ((lvl*3)/8) + 1;

    // This is temporary.
    max_by_int = lvl;

    /*
	max_by_int = player->query("base_stat/intelligence");
	if (max_by_int >= 18)
	    max_by_int = 10;
	else
	    max_by_int/=2;

    */
    if (max_by_int > MAX_SPELL_LEVEL) max_by_int = MAX_SPELL_LEVEL;

    if (lvl > max_by_int)
	return max_by_int;
    else
	return lvl;

    return lvl;
}  /* End get_max_spell_level() */


/*
** Function: filter_mapping( mapping map, int Val )
** Purpose: Pulls item of index Val out of mapping map, and returns
**    revised mapping.
** Receives: Mapping to be altered.
** Returns: Revised mapping.
*/

mapping filter_mapping (mapping map, int Val) {
    mapping tmpMap = ([]);
    int c, *tmpValues = ({});
    string *tmpKeys = ({});

    tmpValues = values(map);
    tmpKeys = keys(map);

    for (c = 0; c < sizeof(tmpValues); c++)
	if (Val!=c)
	    tmpMap += ([ tmpKeys[c] : tmpValues[c] ]);
#ifdef DEBUG
else DEBUG("Removing "+tmpKeys[c]+" from list.\n");
#endif

return tmpMap;
}


/* End of File */
