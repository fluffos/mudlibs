/*
 * guild.c
 * Guild variables and queries for use in player.c
 * Rumplemintz
 */
#pragma strong_types

/* Existing and allowed guilds */
#include "/sys/guilds.h"

/* Existing variables */
string guild_name;        /* Guild name */
string guild_file;        /* Filename for guild object */
int    guild_rank;        /* Guild rank */
int    guild_exp;         /* Guild experience */

/* New stuff! */
string *guild;            /* Guilds player is a member of */
string guilds;            /* Single string... */
mapping guild_level;      /* Guild levels for said guilds... */
mapping guild_info;       /* Set any kind of info for guilds... */


void set_guild_name(string str) { 
  if( str ) {
  }
  guild_name = str; 
}
string query_guild_name() { return guild_name; }

void set_guild_file(string str) {
  if( str ) {
  }
  guild_file = str; 
}
string query_guild_file() { return guild_file; }

void set_guild_rank(int i) {
  if (i < 0)
    return;
  guild_rank = i;
}

void add_guild_rank(int i) {
  if ((guild_rank + i) < 0)
    return;
  guild_rank += i;
}

int query_guild_rank() { return guild_rank; }

void set_guild_exp(int i) {
  if (i < 0)
    return;
  guild_exp = i;
}

void add_guild_exp(int i) {
  if ((guild_exp + i) < 0)
    return;
  guild_exp += i;
}

int query_guild_exp() { return guild_exp; }

/* New Functions */
mixed query_guild(string g) {
  if (g)
#ifdef __LDMUD__
    return (member(guild, g) >= 0);
#else
    return (member_array(g, guild) >= 0);
#endif
  return guild;
}

void set_guilds(string str) { guilds = str; }
string query_guilds() { return guilds; }

status set_guild_level(string g, int lvl) {
  if (!query_guild(g))
    return 0;
  guild_level[g] = lvl;
  return 1;
}

int query_guild_level(string g) {
  if (!query_guild(g))
    return 0;
  return guild_level[g];
}

status set_guild(string g) {
  if (!GUILDS[g])
    return 0;
  if (sizeof(guild))
    return 0;
  guild -= ({g});
  guild += ({g});
  return 1;
}

void remove_guild(string g) {
  guild -= ({g});
}

void set_guild_info(string what, mixed info) {
  if (!guild_info)
    guild_info = ([]);
  guild_info[what] = info;
}

mixed query_guild_info(string what) {
  if (!guild_info)
    guild_info = ([]);
  return guild_info[what];
}

void remove_guild_info(string what) {
  if (!guild_info)
    guild_info = ([]);
  guild_info = m_delete(guild_info, what);
}

string query_guild_short(string g) {
  return GUILDS[g][GUILD_SHORT] || "nothin";
}

string query_guild_long(string g) {
  return GUILDS[g][GUILD_LONG] || "nothin";
}

