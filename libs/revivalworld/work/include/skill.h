/* This program is a part of RW mudlib
 * See /doc/help/copyright for more info
 -----------------------------------------
 * File   : /include/skilldata.h
 * Author : Clode@RevivalWorld
 * Date   : 
 * Note   : INCLUDE file
 * Update :
 *  o 2000-00-00  
 *
 -----------------------------------------
 */
#define SKILL_MAX_EXP		10000000.
#define SKILL_MAX_LV		100

#define SKILL_ROOT		"/std/module/skill/"
#define SKILL(skill)		SKILL_ROOT+(string)skill+".lpc"

#define SKILL_KEY(skill)	"skills/"+(string)skill
#define SKILL_LV(skill)		SKILL_KEY(skill)+"/level"
#define SKILL_EXP(skill)	SKILL_KEY(skill)+"/exp"

#define PLAYER_SKILL		(1<<0)
#define NPC_SKILL		(1<<1)

varargs string query_id(int raw);
varargs string query_name(int raw);
varargs string query_idname(int raw);
string query_file();

