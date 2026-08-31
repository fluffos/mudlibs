//  Guild System 4.2.3
//  Whit
//  Guild Daemon

#include <daemons.h>
#include <std.h>
#include <guild.h>
#include <security.h>

inherit DAEMON;
int lock;
string *member, *council, *leader, *squire, reason;
mapping master, names, positions;

int remove_player(string name,string guild);
string query_guild(string name);
string query_position(string name);
string query_actual_position(string str);
int valid_master(string name);
string query_position_name(string guild, string pos);

void clear_var() {
    squire=0;
    member=0;
    council=0;
    leader=0;
    positions=0;
}

void check_var() {
    if(!squire) squire=({});
    if(!member) member=({});
    if(!council) council=({});
    if(!leader) leader=({});
    if(!positions) positions=([]);
    master=0;
    names=0;
    lock=0;
    reason=0;
}

int check_rights(string name, string guild, string *pos) {
    string blah;
    if(valid_master(name)) return 1;
    if(guild == "dw") guild = "dw";
    if(!file_exists(SAVE+guild+".o")) return 0;
    restore_object(SAVE+guild);
    blah = query_actual_position(name);
    pos += ({ "main" });
    if(member_array(blah, pos) == -1) return 0;
    return 1;
}

string query_position(string name) {
    string guild;

    if(valid_master(name)) return "master";
    guild=query_guild(name); if(!guild) return 0;
    restore_object(SAVE+guild);
    if(!squire && !member && !council && !leader) return "Invalid Guild";
    name = lower_case(name);
    if(member_array(name, MAIN) != -1) return query_position_name(guild, "leader");
    if(member_array(name, squire) != -1) return query_position_name(guild, "squire");
    if(member_array(name, member) != -1) return query_position_name(guild, "member");
    if(member_array(name, council) != -1) return query_position_name(guild, "council");
    if(member_array(name, leader) != -1) return query_position_name(guild, "leader");
    return "none";
}

string query_actual_position(string str) {
    string name;
    string guild;

    if(valid_master(str)) return "master";
    guild=query_guild(str); if(!guild) return 0;
    restore_object(SAVE+guild);
    if(!squire && !member && !council && !leader) return "Invalid Guild";
    name = lower_case(str);
    if(member_array(name, MAIN) != -1) return "main";
    if(member_array(name, squire) != -1) return "squire";
    if(member_array(name, member) != -1) return "member";
    if(member_array(name, council) != -1) return "council";
    if(member_array(name, leader) != -1) return "leader";
    return "none";
}

string *post_able(string guild) {
    string *post;
    if(!file_exists(SAVE+guild+".o")) return MASTER;
    restore_object(SAVE+guild);
    post = leader;
    post += MASTER;
    restore_object(SAVE+guild);
    return post;
}

int valid_master(string who) {
    if(lower_case(who) == "whit") return 1;
    if(lower_case(who) == "nesoo") return 1;
    if(member_array(who, MASTER) == -1) return 0;
    return 1;
}

int add_player(string name, string guild) {
    if(!guild || guild == "") {
	if(query_guild(name)) remove_player(name, query_guild(name));
	return 0;
    }
    if(query_guild(name)) remove_player(name, query_guild(name));
    if(member_array(guild, VALID_GUILDS)==-1) return 0;
    restore_object(SAVE+guild);
    check_var();
    if(!valid_master(name))
	squire += ({ name });
    save_object(SAVE+guild);
    clear_var();
    restore_object(SAVE+"master");
    if(!master) master=([]);
    master[name]=guild;
    save_object(SAVE+"master");
    return 1;
}

int remove_player(string name, string guild) {
    if(!guild || guild == "") return 0;
    if(member_array(guild, VALID_GUILDS)!=-1) {
      restore_object(SAVE+guild);
      check_var();
      squire -= ({ name });
      member -= ({ name });
      council -= ({ name });
      leader -= ({ name });
      save_object(SAVE+guild);
    }
    restore_object(SAVE+"master");
    clear_var();
    if(!master) master=([]);
    map_delete(master, name);
    save_object(SAVE+"master");
    return 1;
}

string *query_players(string guild) {
  string *ret;
  if (!guild || guild == "") return ({});
  if (member_array(guild, VALID_GUILDS) != -1) {
    restore_object(SAVE+guild);
    check_var();
    ret = squire | member | council | leader;
    clear_var();
    restore_object(SAVE+"master");
    if (!master) master=([]);
  }
  return ret || ({});
}

int promote(string name, string pos) {
    string guild;

    guild=query_guild(name);
    master=0;
    clear_var();
    restore_object(SAVE+guild);
    squire -= ({ name });
    member -= ({ name });
    council -= ({ name });
    leader -= ({ name });
    switch(pos) {
    case "squire": squire += ({ name }); break;
    case "member": member += ({ name }); break;
    case "council": council += ({ name }); break;
    case "leader": leader += ({ name }); break;
    default: 
	write("Unknown Problem: Name: "+name+" Position: "+pos+" Old Postion: "+
	  query_actual_position(name));
	break;
    }
    save_object(SAVE+guild);
    return 1;
}

string query_guild(string name) {
    string guild;
    restore_object(SAVE+"master");
    if(!master) master=([]);
    guild = master[name];
    if (guild && member_array(guild, VALID_GUILDS) == -1)
      remove_player(name, guild);
    return guild;
}

void set_short_name(string guild, string long) { 
    clear_var();
    restore_object(SAVE+"master");
    if(!names) names=([]);
    names[guild]=long; 
    save_object(SAVE+"master");
}

string query_short_name(string guild) {
    clear_var();
    restore_object(SAVE+"master");
    if(!names) names=([]);
    if(!names[guild]) return guild;
    return names[guild];
}

void set_position_name(string guild, string pos, string name) {
    clear_var();
    restore_object(SAVE+guild);

    if(!positions) positions=([]);
    positions[pos]=name;
    save_object(SAVE+guild);
}

string query_position_name(string guild, string pos) {
    if(member_array(pos, VALID_POSITIONS)==-1) return "Invalid Position.";
    clear_var();
    restore_object(SAVE+guild);

    if(!positions) positions=([]);
    if(!positions[pos]) return capitalize(pos);
    return positions[pos];
}

int lock_guilds() {
    clear_var();
    restore_object(SAVE+"master");
    if(!master) master=([]);
    lock=1;
    save_object(SAVE+"master");
    return 1;
}

int unlock_guilds() {
    clear_var();
    restore_object(SAVE+"master");
    if(!master) master=([]);
    lock=0;
    save_object(SAVE+"master");
    return 1;
}

int query_locked() { 
    clear_var();
    restore_object(SAVE+"master");
    return lock;
}

int set_lock_reason(string str) {
    clear_var();
    restore_object(SAVE+"master");
    if(!master) master=([]);
    reason=str;
    save_object(SAVE+"master");
    return 1;
}

string query_lock_reason() { 
    if(!reason || reason == "") return "The Guild System is currently in lock mode.\n";
   return reason+"\nDuring this time, all commands, and guild halls will be inaccesible.  Sorry for the inconvience.";
}

