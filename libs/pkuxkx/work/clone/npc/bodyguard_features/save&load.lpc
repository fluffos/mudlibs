#include <ansi.h>
#include "/clone/npc/bodyguard_config.h"
string *save_contents=({"title","nickname","gender","potential_ability","ability","combat_exp","age","birth_place","chance","friendship"});
void restore_guard(object me,object ob)
{
	string *skills;
	if (!me->query("MyGuard")||!arrayp(me->query("MyGuard"))) return;
	for (int i=0;i<sizeof(save_contents);i++)
	ob->set(save_contents[i],me->query("MyGuard/"+save_contents[i]));
	ob->set_name(me->query("MyGaurd/name"),me->query("MyGaurd/id"));
	skills=keys(me->query("MyGuard/skills"));
	for (int i=0;i<sizeof(skills);i++)
	ob->set_skill(skills[i],me->query("MyGuard/skills")[skills[i]]);
}
void save_guard(object me,object ob)
{
	me->set("MyGuard/id",ob->parse_command_id_list());
	me->set("MyGaurd/name",ob->query("name"));
	me->set("MyGuard/skills",ob->query_skills());
	for (int i=0;i<sizeof(save_contents);i++)
	me->set("MyGuard/"+save_contents[i],ob->query(save_contents[i]));
}
