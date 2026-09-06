#define SKILL_DAEMON "/daemon/skill"
#define DIR "/help/skill/"

string disambiguate( string str ) {
	string buf = "SKILLS\nDISAMBIGUATION\nThere are multiple ~CTIT"+str+"~CHLP skills in the game, you will have to be more specific.\n";
	string skill, *skills = SKILL_DAEMON->query_skills();
	foreach( skill : skills ) {
		if( explode(skill,".")[<1] == str )
			buf += "\n * "+skill;
	}
	return buf;
}

void do_write( string file, string buf ) {
	string fname = DIR + file + ".hlp";
	string skill = file;
	int dot;
	rm(fname);
	write_file( fname, buf );
	// check for aliases that need making
	while( (dot = member(file,'.')) != -1 )
		file = file[dot+1..];
	if( file != skill ) {
		string tmp, alias = "!"+DIR+skill;
		fname = DIR + file + ".hlp";
		if( !sizeof(get_dir(fname)) )
			write_file( fname, alias );
		else {
			tmp = read_file(fname);
		    if( tmp && tmp != alias ) {
				rm(fname);
				write_file( fname, disambiguate(file) );
			}
		}
	}
}

void do_index( string *skills ) {
	string buf;
	int x;

	buf = "SKILLS\nINDEX\nThere are currently aproximately half a quintrillion different skills available to players in the game. This file is an index of the entire tree. Enjoy.\n\n";

	for( x = 0; x < sizeof(skills); x++ ) {
		string skill = skills[x];
		int dot = member( skill, '.' );
		if( dot == -1 ) {
			// no dot means root skill
			buf += " ~CBRT+ ~CTIT"+upper_case(skill)+"\n";
		} else {
			while( (dot = member(skill,'.')) != -1 ) {
				buf += "    ";
				skill = skill[dot+1..];
			}
			buf += " ~CDEF- ~CBRT"+skill+"\n";
		}
	}

	buf += "\n~CLABSee also: ~CREFskills, stats, spells";

	do_write( "index", buf );
}

string diff_string( int diff ) {
	if( diff >= 18 )
		return "very difficult";
	if( diff > 15 )
		return "difficult";
	if( diff > 10 )
		return "average";
	if( diff >= 8 )
		return "easy";
	return "very easy";
}

string stat_string( string *stats ) {
	stats = sort_array(stats, #'>);
	if( sizeof(stats) != 3 )
		return "n/a";
	// three cases
	if( stats[0] == stats[1] && stats[1] == stats[2] ) {
		return stats[0];
	} else if( stats[0] == stats[1] || stats[1] == stats[2] ) {
		return stats[0]+", "+stats[2];
	} else {
		return stats[0]+", "+stats[1]+", "+stats[2];
	}
}

void do_generate( string skill ) {
	// TODO: have the thing draw the skill tree and then use Acius' funky
	// printing methods to draw it something like this:
	//
	// CRAFT               Smithing is the act of whacking heated bits of
	//    art              metal with a hammer until it obeys you and turns
	//    butcher          into something useful.
	//    carpentry
	//    cooking          There are several different types of smithing,
	//    farming          and in the production of any given item it is not
	//    leatherworking   unlikely that you might have to use more than
	//    masonry          one.
	//    mining
	//    SMITHING
	//       armour
	//       black
	//       weapons
	//       white
	//    tanning
	
	string buf = "SKILLS\n"+upper_case(skill)+"\n";
	int diff = SKILL_DAEMON->query_skill_difficulty(skill);
	string *stats = SKILL_DAEMON->query_skill_stats(skill);
	string help_desc = SKILL_DAEMON->query_skill_help_description(skill);
	
	buf += " \"~CLAB"+capitalize(SKILL_DAEMON->query_skill_description(skill))+"~CHLP\"\n";
	if( diff )
		buf += " ~CBRTDifficulty: ~CHLP"+diff_string(diff)+"\n";
	else
		buf += " ~CBRTThis is a skill category.\n";
	
	if( sizeof(stats) == 3 )
		buf += " ~CBRTStats Used: ~CHLP"+stat_string(stats)+"\n";
	
	if( help_desc )
		buf += "\n~CHLP"+help_desc+"\n";

	// TODO: detect better see also data, related to skill family as well as
	// a listing of the stats used
	buf += "\n~CLABSee also: ~CREFskills, stats";

	do_write( skill, buf );
}

void do_it() {
	string skill;
	string *skills;

	debug( "Beginning generation of skill help files..." );
	skills = SKILL_DAEMON->query_skills();
	do_index( skills );
	foreach( skill : skills ) {
		do_generate( skill );
	}
	debug( "Skill help files generated for "+sizeof(skills)+" skills plus the index.");
}

int main() {
	debug("Skill help file regeneration called by "+this_player()->query_cap_name());
	limited(#'do_it);
	debug("Generation complete.");
	return 1;
}
