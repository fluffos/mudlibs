#ifndef _THIEF_H
#define _THIEF_H

#include <guild.h>
#include <invis_levels.h>
#include <daemons.h>
#include <conditions.h>
#include <criminal.h>
#include <skills.h>
#include <gametime.h>
#include <room_defs.h>
#include <attack.h>
#include <living_defs.h>

#include "dirs.h"
#include "ranks.h"

inherit "/guilds/thieves/mark/can_throw";
inherit "/guilds/thieves/mark/is_valid_target";

#define TOP_TEN "/guilds/thieves/top_ten"
#define GUILD "/guilds/thieves/rooms/guild"
#define GM_D "/guilds/thieves/gm_d"
#define ADJ_AMOUNT 39
#define BALANCE BALANCE_D

/* Logs only steals from players */
#define LOG_STEAL

// HIGH_SKILL_DIV, how much > 10000 skills effect.
// The more this is, the less they do.
// Originally 70.
// Graah
// 6-May-97 / Graah: 50 -> 45
// 9-May-97 / Graah: 45 -> 37
// 29-Sep-97 / Graah: 37 -> 36
// 10-Oct-97 / Graah: 36 -> 41, 40 for pk
#define HIGH_SKILL_DIV		(pk ? 41 : 40)

// DMG_DIV, how much we divide damage taken from balance daemon.
// I think other guilds don't divide it at all, even when they have
// high skill bonuses and criticals added _after_ asking from
// balance daemon... /Graah
// Originally 17
// 6-May-97 / Graah: 16 -> 13
// 9-May-97 / Graah: 13 -> 11
// 29-Sep-97 / Graah: 11 -> 9
// 30-Sep-97 / Graah: 9 -> 10 for mk, pk is now 7 (MUST BE WATCHED!)
// 10-Oct-97 / Graah: 8 -> 9 for pk, 10 -> 11 for mk
// 19-Jan-97 / Graah: Lots of PK, it seems. 9 -> 11 for pk.
#define DMG_DIV			(pk ? 11 : 11)

// M_MAX_SK_LVL, How big skill can a player at certain lvl have?
// This uses t_level: hobbits etc. are better than the others.
// With this value, it requires level 35 to get Ultimate skills!
// For lvl 30 limit #define M_MAX_SK_LVL(x)   (2048 + ((x) * 265))
#define M_MAX_SK_LVL(x)	(2048 + ((x) * 227))

#define PEEK_SP_COST      1
#define POSE_SP_COST      8
#define SNEAK_SP_COST     5
#define STEAL_SP_COST     10
#define HIDE_SP_COST     30
#define APPRAISE_SP_COST  5
#define PICK_SP_COST     10
#define THROW_COST        8
#define TLOOK_SP_COST    15
#define STAB_COST 	 10

/* Difficulty levels */
#define DIFF_STAB	8000
#define DIFF_SNEAK	2500
#define DIFF_THROW	9200
#define DIFF_PICK	7200
#define DIFF_STEAL	9400
#define DIFF_APPRAISE	7400
#define DIFF_POISON	8500
#define DIFF_TUMBLING   9999

#define SK_STAB		0
#define SK_SNEAK	1
#define SK_TTH		2
#define SK_PICK		3
#define SK_STEAL	4
#define SK_APPRAISE	5
#define SK_POISON	6
#define SK_TUMBLING	7
#define SK_AVERAGE	8

/* Difficulty divider. This really defines how difficult it is! */
#define THF_DIV  750

/* Undef if we don't want channel to be logged. */
#define LOG_CANT

/* skill files */
#define STAB "/guilds/thieves/skills/_stab"
#define HIDE "/guilds/thieves/skills/_hide"
#define TTH "/guilds/thieves/skills/_tth"
#define SNEAK "/guilds/thieves/skills/_sneak"
#define PICK "/guilds/thieves/skills/_pick"
#define APPRAISE "/guilds/thieves/skills/_appraise"
#define POISON "/guilds/thieves/skills/_poison"
#define STEAL "/guilds/thieves/skills/_steal"
#define COOK "/guilds/thieves/skills/_cook"

#define DELAY_STEAL   2
#define DELAY_STAB   1

#define TO this_object()
#define TP this_player()
#define TPT this_player()->tell_me
#define TM owner->tell_me
#define REALNAME(x) ((string)(x)->query_real_name())
#define MASTER_OB "/secure/master"
#define LOG_FILE MASTER_OB->thief_log
#define Realname(x) capitalize(REALNAME(x))
#endif /* _THIEF_H */

/* ALL Function Protoypes */

int still_thief(int silently);
string do_short(int arg, object who);
string query_guildmaster();
mixed query_ban();
mixed query_adv();
mixed query_last_steal();
mixed query_tth();
string query_tattoo_desc();
nomask string query_pretitle();
int query_tax(int x);
int query_tax_time();
int query_steal_tax();
int query_delay_stab();
int query_advantage();
int query_thief_level();
int query_sneak();
int query_tumbtime();
object query_summoner();
object query_summon_room();
int query_skills(int type);
void set_guildmaster(string x);
void set_last_steal(object x);
void set_ban(mixed x);
void set_tth(mixed x);
void set_tattoo_desc(mixed x);
nomask void set_pretitle(string str);
void set_tax_time(mixed t);
void set_steal_tax(mixed x);
void add_steal_tax(mixed x);
void set_skill(int skill, int amount);
void set_delay_stab(int x);
void set_sneak(int x);
void add_stab_skill();
void set_summoner(object ob, object where, int when);
string query_guild_save();
status guild_prevent_attack();
void initialize_guild(string arg);
void init_arg(string arg);
int valid_desc(string x);
void convert();
void mkskills();
int check_ban(int silently);
void force_check();
status refresh(string arg);
status thief_help(string str);
string skill_adj(int sk);
string EV(int sk);
int thief_skills(string arg);
varargs int advance_skill(int sk, int d, int p);
int stealth();
int moon_light();
status steal_again();
void test_notice(mixed arg, object targ);
status brew_poison();
void stop_sneak();
status stab(string str);
status stab_delay_over();
status stab_cheat_over();
status pick(string str);
string thief_pretitle();
status canttoggle();
varargs status chant(string str);
int thief_dex();
status fix_title(string arg);
void backup_log(string filename);
save_cmd();
void done_mort();
status tth(string arg);
void remove_tth();
status thetth(string arg);
int tits();
int enforcerlist();
int taxes();
status cantread(string arg);
void hit_victim(mixed ar);
void stab_victim(mixed ar);
void delayed_hit(int delay, mixed ar);
void delayed_stab(int delay, mixed ar);
int top(string arg);
status resign(string arg);
status thief_weight();
status end_cook();
status cook_corpse(string what);
status warmup(string arg);
void end_warmup(int sp);
string random_taunt();
status taunt(string str);
status tpose();
status random_pose();
status disguise(string str);
status consider(string str);
status tlook(string arg);
status demon(string arg);
status demonread();
status demontoggle();
status goto(string arg);
status gag_cmd(string who);
int kickout(string arg);
int manage_gm(string arg);
int wrath(string arg);
int showlogs(string arg);
status gmc(string arg);
status gmctoggle();
status gmcread(string arg);
int tax_set(string arg);
int gmeditor(string arg);
void set_loop(string arg);
int tumble_success();
status tumble_stab(object victim);
int query_guild_ac_rate(int dmg, int dtype, int hc, object att);
void guild_mem_quit(object who);
void guild_mem_mortal(object died, object killer);
void guild_mem_died(object died, object killer);
void guild_mem_mort(object mort, object killer);
