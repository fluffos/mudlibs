#ifndef __SAURON_DEFS_H__

#define __SAURON_DEFS_H__

#pragma strict_types
#pragma save_types

#include <lw.h>

#define PATH		"/players/sauron/"
#define AREA		PATH+"area/"
#define BIN             PATH+"bin/"		// Secure
#define CLONE		PATH+"clone/"
#define DATA		PATH+"data/"
#define ETC		PATH+"etc/"
#define INCLUDE		PATH+"include/"
#define INHERIT		PATH+"inherit/"
#define ROOMS		PATH+"room/"
#define SEC		PATH+"secure/"		// Secure
#define   LOG		SEC+"log/"
#define   SYS		SEC+"sys/"
#define   WR		SEC+"workroom/"
#define     WRBIN	WR+"bin/"

#define WROOM           "/players/sauron/workroom"
#define ROOMINFO	"/room/roominfo"

#define WRITE(x)	writelw(x)
#define NWRITE(x)	writelwnl(x)
#define PRINTF(x)	writelw(sprintf(x))
#define SAY(x)		say(lw(x))
#define OTHERS(x,o)	say(lw(x),o)
#define TELLO(o,x)	tell_object(o,lw(x))
#define TELLR(o,x)	tell_room(o,lw(x))

#define NF(x)		notify_fail(lw(x))
#define STD_FAIL	notify_fail(capitalize(query_verb()+" what?\n"))
#define WIZINFO(x)	if(TP->query_immortal())\
			  writelwnl("WizInfo: "+x)
#define MEINFO(x)	if((string)TP->query_real_name()=="sauron")\
			  writelwnl("Info: "+x)

#define TP		this_player()
#define TO		this_object()
#define PO		previous_object()

#define MOVE		move_object
#define TR		transfer
#define MOVEP		move_player
#define MP(o,x)		o->move_player(x)
#define FO		find_object
#define CO		clone_object
#define DE		destruct
#define ENV		environment
#define RPR		replace_program("/room/room")
#define RP		replace_program
#define CAP		capitalize
#define LOW		lower_case
#define VERB		query_verb()
#define ALL		all_inventory

#define NAME(o)		(string)o->query_name()
#define CNAME(o)        (string)o->query_name()

#define RNAME(o)	(string)o->query_real_name()
#define CRNAME(o)       (string)o->query_real_name(1)

#define SNAME(o)	(string)o->query_short_name()
#define SHORT(o)	(string)o->query_short()
#define LONG(o)		(string)o->query_long()

#define RACE(o)		o->query_race()

#define MAXHP(o)	(int)o->query_max_hp()
#define HP(o)		(int)o->query_hp()
#define MAXSP(o)	(int)o->query_max_sp()
#define SP(o)		(int)o->query_sp()
#define ADDHP(o,x)	o->reduce_hit_point(-x)
#define REDHP(o,x)	o->reduce_hit_point(x)
#define HITP(o,x)	o->hit_player(x)
#define ADDSP(o,x)	o->restore_spell_points(x)
#define REDSP(o,x)	o->restore_spell_points(-x)

#define STR(o)		(int)o->query_str()
#define RSTR(o)		(int)o->query_r_stats(0)
#define DEX(o)		(int)o->query_dex()
#define RDEX(o)		(int)o->query_r_stats(1)
#define CON(o)		(int)o->query_con()
#define RCON(o)		(int)o->query_r_stats(2)
#define INT(o)		(int)o->query_int()
#define RINT(o)		(int)o->query_r_stats(3)
#define WIS(o)		(int)o->query_wis()
#define RWIS(o)		(int)o->query_r_stats(4)
#define CHR(o)		(int)o->query_chr()
#define RCHR(o)		(int)o->query_r_stats(5)

#define LEVEL(o)	(int)o->query_level()
#define LEGLVL(o)	(int)o->query_legend_level()
#define TESTP(o)	(string)o->query_testchar()
#define APPR(o)		(int)o->query_immortal()
#define NEW(o)		(int)o->query_newwiz()
#define WIZ(o)		(int)o->query_wizard()
#define SENR(o)		(int)o->query_senior()
#define LORD(o)		(int)o->query_lord()
#define ARCH(o)		(int)o->query_archwiz()

#define INVIS(o)	(int)o->query_invis()

#define BUSY(o)		(int)o->query_earmuff_level()

#define GUILD(o)	o->query_guild()

#define GHOST(o)	(int)o->query_ghost()

#define SIZE(o)		(int)o->query_size()

#define WEIGHT(o)	(int)o->query_weight()

#define NPC(o)		(int)o->query_npc()

#define ALIGN(o)	(int)o->query_alignment()
#define ALSTR(o)	(string)o->query_al_string()

#define RELGN(o)	(string)o->query_religion()

#define SEX(o)		(int)o->query_gender()
#define HE(o)		(string)o->query_pronoun()
#define CHE(o)          (string)o->query_pronoun(1)
#define HIM(o)		(string)o->query_objective()
#define CHIM(o)         (string)o->query_objective(1)
#define HIS(o)		(string)o->query_possessive()
#define CHIS(o)         (string)o->query_possessive(1)
#define HIMSELF(o)	(string)o->query_objective()+"self"
#define CHIMSELF(o)     (string)o->query_objective(1)+"self"

#define MONEY(o)	(int)o->query_money()
#define ADDMONEY(o,x)	o->add_money(x)

#define POISONED(o)	(int)o->query_poisoned()
#define ADDPSN		add_poison

#define XP(o)		(int)o->query_exp()
#define QXP		query_exp
#define ADDXP		add_exp
#define NEEDEDXP(o)	(int)o->query_exp_next_level()

#define ATTACK(o)	o->query_attack()
#define AGGR(o)		o->query_aggressive()
#define ATTOK(o,p)	o->allowed_attack(p)
#define CALM(o)		o->stop_fight()
#define HUNTER(o)	o->query_hunter()
#define HNAME(o)	o->is_hunted_by()
#define STOP(o)		o->stop_hunter(1)
#define SWAPATT(o,p)	o->change_attacker(p)
#define RUN		run_away()

#define WEAPON(o)	o->query_weapon()
#define WIELDED(o)	o->query_wielded()
#define QINFO(o)	o->query_info()
#define WC(o)		(int)o->query_wc()
#define AC(o)		(int)o->query_ac()
#define 2HANDER(o)	o->query_two_handed()
#define VALUE(o)	o->query_value()

#define MAX_LOG_SIZE	50000

#endif // __SAURON_DEFS_H__
