#include <combat.h>
inherit NPC;
 
void create()
{
	mapping names = NAME_D->random_name("gui");
        set_name(names["name"],names["id"]);
        set("look_msg",names["long"]);
        set("gender", "男性" );
        set_level(35);
        set("age",40);
        set("class", "ghost");
        set("attitude", "heroism");
        set("combat_exp", 200000);
        set("force_factor", 180);
        set("mana_factor", 40);
        set_skill("unarmed",120);
        set_skill("dodge",120);
        set_skill("parry",120);
	set_skill("jinghun-zhang", 120);
	map_skill("unarmed", "jinghun-zhang"); 
	set("HellZhen", 1);
        setup();
}

void invocation(object who)
{
	int i,level;
	mapping skill;
	string *skills;
	object me=this_object();
	if( !who )
		return;
	level = this_object()->query_level();
	skill = me->query_skills();
	skills = keys(skill);
	for(i=0;i<sizeof(skills);i++)
		set_skill(skills[i],level*10);		
	set("daoxing", level*5000);
	COMBAT_D->do_attack(me, who, query_temp("weapon"),TYPE_PERFORM);
	destruct(me);
}