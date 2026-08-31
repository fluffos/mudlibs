/*
 * sys_defs.h -- reconstructed.
 *
 * The original /sys/include/sys_defs.h (included by secure/simul_efun.c
 * and secure/s_e.c) was not present anywhere in the preserved archive
 * (see sys_arches.h in this same directory for the full explanation of
 * why -- same missing-content situation, confirmed by grepping the
 * entire ~24,000-file tree for a second copy and finding none).
 *
 * Unlike sys_arches.h though, this one isn't a guess: every identifier
 * secure/simul_efun.c actually uses without a local #define (TP, ENV,
 * RNAME, INVIS, LEVEL, etc.) is a real, still-present macro in this same
 * mudlib's /include/defs.h -- the mudlib's OTHER, unrelated-by-name but
 * functionally identical "common macros" header, `#include`d by dozens
 * of live obj/ and room/ files. Reconstructed by copying that verified,
 * in-use content verbatim (distinct include guard to avoid a collision
 * if a file ever pulls in both headers). See NOTES.md.
 */

#ifndef __SYS_DEFS_H__

#define __SYS_DEFS_H__

#undef NEWLEVELSYSTEM

#define TP		this_player()
#define TI		this_interactive()
#define TO		this_object()
#define PO		previous_object()
#define MASTER		master_object()
#define SIMUL		simul_efun_ob()

#define NAME		query_name()
#define RNAME		query_real_name()
#define CRNAME		query_real_name(1)
#define TNAME		query_name_true()
#define SNAME		query_short_name()
#define SHORT		short()
#define POS		query_possessive()
#define PRO		query_pronoun()
#define OBJ		query_objective()
#define IMM		query_immortal()
#define TESTP		query_testchar()
#define CAP		capitalize
#define LOW		lower_case

#define STR		query_str()
#define INT		query_int()
#define WIS		query_wis()
#define DEX		query_dex()
#define CON		query_con()
#define CHA		query_chr()
#define LEVEL		query_level()
#define INVIS		query_invis()
#define ALIGN		TP->query_alignment()
#define HP		query_hp()
#define MAXHP		query_max_hp()
#define SP		query_sp()
#define MAXSP		query_max_sp()
#define ENV		environment
#define ALL		all_inventory

#define TELL		tell_object
#define TELLR		tell_room
#define MOVE		move_object
#define MOVEP		move_player
#define MP		this_player()->move_player

#define ADDHP(x)	reduce_hit_point(-(x))
#define ADDSP(x)	restore_spell_points(x)
#define HIT(x)		hit_player(x)
#define HITP(x, y)	hit_player(x, y)

#define CD		"/sys/chatd"
#define GM		"/guild/master"
#define QR		"/room/quest_room"
#define RM		"/race/master"
#define RLM		"/religion/master"
#define SM		"/obj/skill_master"
#define SPELL_MASTER	"/spells/master"
#define ABILITY_MASTER	"/abilities/master"
#define SOCIAL_MASTER	"/masters/feelings"
#define SKILL_MASTER	"/masters/skills"

#include "/include/lw.h"

#endif // __SYS_DEFS_H__
