#include <const.h>

#define FILE "/daemon/party"

mapping parties;

struct Party {
	string leader;
	string *members;	// array of all members
};

//// prototypes ////
void load();
void save();
varargs void create_party(string name, string leader, int quiet);
varargs void disband_party(string name, int quiet);
varargs void add_member(string party, string member, int quiet);
varargs void kick_member(string party, string member, int quiet);
varargs void set_leader(string party, string name, int quiet);
object find_member(string member);
varargs void msg_party(string party, string message, int nobanner);

//// wimpy methods ////
mapping query_party_map() { return parties; }
int query_party_exists(string party) { return member(parties, party); }
string *query_party_names() { return m_indices(parties); }
string *query_party_members(string party) {
	if( query_party_exists(party) )
		return parties[party]->members;
	else
		return ({});
}

string query_party_leader(string party) {
	if( query_party_exists(party) )
		return parties[party]->leader;
	else
		return 0;
}

void create() {
	load();
	debug("daemon is ready for action","party");
}

void destructor() {
	debug("destructor called","party");
	save();
}

/**
 * Send text to an entire party.
 */
varargs void msg_party(string party, string message, int nobanner) {
	string name;
	if( !nobanner )
		message = "~CTIT[Party]~CDEF "+message;
	foreach( name : query_party_members(party) ) {
		object who = find_member(name);
		if( who )
			msg_object(who, message, 8);
	}
}

/**
 * Called whenever players log in and are already in a party
 */
void login(string name) {
	object who = find_member(name);
	string party;
	if( !who ) return;
	if( party = who->query_env_var("party") ) {
		if( query_party_exists(party) ) {
			add_member(party, name, 1);
			msg_party(party, capitalize(name)+" has returned.");
		} else {
			create_party(party, name, 1);
			msg_party(party, "You are the only one in your party online right now.");
		}
	}
}

/**
 * Called whenever party members log out/go ld
 */
void logout(string name) {
	object who = find_member(name);
	string party, pupil;
	if( !who ) return;
	if( party = who->query_env_var("party") ) {
		pupil = who->query_env_var("mentoring");
		msg_party(party, capitalize(name)+" has logged out.");
		kick_member(party, name, 1);
		// silly hack to reset their env vars since kick_member() unsets it
		who->set_env_var("party", party);
		if( pupil )
			who->set_env_var("mentoring", pupil);
	}
}

varargs void create_party(string name, string leader, int quiet) {
	if( !name )
		debug("attempt to create party w/o name","party");
	else if( !leader )
		debug("attempt to create party '"+name+"'w/o leader","party");
	else if( query_party_exists(name) )
		debug("party '"+name+"' already exists","party");
	else {
		debug("creating new party '"+name+"'","party");
		parties[name] = (<Party> members: ({}) );
		// since he'll be the only one in the party, it should make him leader
		add_member(name, leader, quiet);
		save();
	}
}

varargs void disband_party(string name, int quiet) {
	if( !query_party_exists(name) )
		debug("unable to disband nonexistant party '"+name+"'","party");
	else {
		string *members= query_party_members(name);
		string next;
		debug("disbanding party '"+name+"'","party");
		if( !quiet )
			msg_party(name, "Disbanding party.");
		foreach( next : members )
			kick_member(name, next);
		debug("deleting party '"+name+"' completely","party");
		parties -= ([ name ]);
		save();
	}
}

varargs void add_member(string party, string member, int quiet) {
	if( !party )
		debug("can't add members to null party","party");
	else if( !member )
		debug("attempt to add null member to party '"+party+"'","party");
	else if( !query_party_exists(party) )
		debug("can't add members to nonexistant party '"+party+"'","party");
	else if( member(query_party_members(party),member) != -1 )
		debug("attempt to add "+member+" to "+party+" again...","party");
	else {
		debug("adding "+member+" to "+party,"party");
		parties[party]->members += ({ member });
		if( !quiet )
			msg_party(party, capitalize(member)+" has joined the party.");
		if( sizeof(query_party_members(party)) == 1 )
			set_leader(party,member);
		// for external use
		find_member(member)->set_env_var("party",party);
	}
}

varargs void kick_member(string party, string member, int quiet) {
	if( !party )
		debug("can't remove members from null party","party");
	else if( !member )
		debug("attempt to remove null member from party '"+party+"'","party");
	else if( !query_party_exists(party) )
		debug("can't remove members from nonexistant party '"+party+"'","party");
	else if( member(query_party_members(party),member) == -1 )
		debug("attempt to remove nonmember "+member+" from "+party,"party");
	else {
		debug("kicking "+member+" from "+party,"party");
		if( !quiet )
			msg_party(party, capitalize(member)+" has left the party.");
		parties[party]->members -= ({ member });
		if( sizeof(query_party_members(party)) == 0 )
			disband_party(party);
		else if( query_party_leader(party) == member )
			set_leader(party, query_party_members(party)[0]);
		// for external use
		find_member(member)->remove_env_var("party");
		find_member(member)->remove_env_var("mentoring");
	}
}

varargs void set_leader(string party, string leader, int quiet) {
	if( !party )
		debug("can't set leader of null party","party");
	else if( !leader )
		debug("attempt to set null leader of party '"+party+"'","party");
	else if( !query_party_exists(party) )
		debug("can't set leader of nonexistant party '"+party+"'","party");
	else if( member(query_party_members(party),leader) == -1 )
		debug("attempt to set non-member "+leader+" as leader of "+party,"party");
	else {
		debug("setting leader of "+party+" to "+leader,"party");
		if( !quiet )
			msg_party(party, capitalize(leader)+" is the new leader.");
		parties[party]->leader = leader;
		save();
	}
}

object find_member(string member) {
	// right now, only allow for players
	// TODO: expand parties to allow for NPC members
	//       prolly via storing them as "npc:UNIQUE_ID"
	return find_player(member);
}

/// laziness method for finding somebody's mentor
string query_mentor(string member) {
	string party;
	object ob;
	if( !member )
		debug("can't get mentor of null member","party");
	else if( !(ob = find_member(member)) )
		debug("can't find member "+member, "party");
	else if( !(party = ob->query_env_var("party")) )
		debug(member+" is not in a party","party");
	else if( !query_party_exists(party) )
		debug(member+" is in an invalid party "+party, "party");
	else {
		string who;
		foreach( who : query_party_members(party) ) {
			ob = find_member(who);
			if( !ob )
				continue;
			if( ob->query_env_var("mentoring") == member )
				return who;
		}
		return 0;
	}
}

void load() {
	if (restore_object(FILE))
		debug("success loading from "+FILE,"party");
	else {
		debug("failure loading from "+FILE,"party");
		parties = ([]);
		save();
	}
}

void save() {
	if (save_object(FILE) == 0)
		debug("success saving to "+FILE,"party");
	else
		debug("failure saving to "+FILE,"party");
	load();
}
