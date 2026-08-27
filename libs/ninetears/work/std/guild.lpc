// Let's reformar esto un poco - Vilat 19.10.2002

inherit "/std/object";
inherit "/std/basic/cute_look";

#include "skills.h"
#include "commands.h"
#include "tune.h"

#define CLASES ({"Guerrero","Hechicero","Sacerdote","Bribon","Multiclase"})

string *guild_commands;
string clase;
int xpcost=DEFAULT_XP_COST;
mixed needed_align;
int heal_loop, level;

int query_dice();
void new_levels(int lvl, object ob);

void create() {
  	guild_commands = ({ });
  	::create();
	}

int query_channel() { return 1; }

string help() { return read_file("/doc/helpdir/guilds"); }

void set_needed_align(mixed al) {
  	needed_align = al;
  	return;
	}

mixed query_needed_align() { return needed_align; }

int query_legal_race(string race) { return 1; }

int query_legal_weapon(string str) { return 1; }

int query_legal_armour(string str) { return 1; }

int add_guild_command(string name, int add_if_player) {
  	if (member_array(name, guild_commands) != -1) return 0;
  	guild_commands += ({ name, ({ add_if_player }) });
  	return 1;
	}

int remove_guild_command(string name) {
  	int i;
  	if ((i = member_array(name, guild_commands)) == -1) return 0;
  	guild_commands = delete(guild_commands, i, 2);
  	return 1;
	}

int do_command(string name, mixed param) {
  	mixed *tmp;

  	if (member_array(name, guild_commands)) return 0;
  	tmp = (mixed *)COMMAND_SERVER->query_command(name);
  	return (int)call_other(tmp[0], tmp[1], param);
	}

string *query_guild_commands() { return guild_commands; }

/* Seems we won't use this one, but check *bits of skills instead */
int query_xp_cost() { return xpcost; }
int query_max_level(string race) { return 300; }

/*  Instead of the titles we've been using so far we might want to just
 * let the guild titles consist of <level> <guild>.  At least this will be
 * the standard.  If that's not acceptable, just mask this function.
 */
string query_title(object player) { return "el "+capitalize(query_short())+" de Nivel "+player->query_level(); }

/*
 * cant think of anything I want to do here at the moment...
 * This is where you would set up any shadows you want on the player
 * object (for instance kits/specializations).  The only thing we'll
 * do here in the inheritable guild is to add known guild_commands and spells
 * for monsters (who'll more often have guild_commands and spells than a guild
 * who'll give it to them.
 */

void start_player(object pl) {
  	int i;

  	level = (int)pl->query_level();
  	if (!pointerp(guild_commands)) guild_commands = ({ });
  	for (i=0;i<sizeof(guild_commands);i+=2) if (guild_commands[i+1][0] || !interactive(pl)) pl->add_known_command(guild_commands[i]);
	}

/* Not something players should be able to do until we add dual class humans.
 * Up until then we leave the function open so that lords can call it
 * instead of set_guild_ob() which they often seem to bungle.
 * We will stop removing spells when dual class is implemented
 */
void leave_guild() { "/global/spells"->reset_spells(); }

/* What happens when you advance in level */
void new_levels(int lvl, object ob) {
  	ob->reset_all();
	}

int query_level(object ob) { return level; }

int query_dual_wield_penalty(object me, object w1, object w2) { return 50; }

void set_xp_cost(int i) { xpcost=i; }

void set_clase(string str) {
	clase=lower_case(str);
	}

string query_clase() { return clase; }