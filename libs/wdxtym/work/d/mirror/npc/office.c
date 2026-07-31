//edit by rock
//2008.10.16

#include <ansi.h>
inherit NPC;

#define MIRROR_SYS "/d/mirror/sys/mirror_sys"

int ask_job();

void create()
{

        set_name("扬州暴乱", ({ "team fuben"}));

        set("gender", "男性");
        set("age", 26);
		set_temp("no_kill",1);
	set("qi",   99999);
	set("jing", 99999);
	set("eff_qi",   99999);
	set("eff_jing", 99999);
	set("max_qi",   99999);
	set("max_jing", 99999);
	set("neili", 4500);
	set("max_neili", 4500);
	set("jiali", 0);
	set("combat_exp", 25000000);
	set("score", 50000);
        set_skill("strike",200);
        set_skill("unarmed",200);
        set_skill("dodge",200);
        set_skill("force", 200);
	set_skill("parry", 210);
	set_skill("literate", 200);
	set_skill("canzhi-duanhun",300);
        map_skill("unarmed", "canzhi-duanhun");
        map_skill("parry", "canzhi-duanhun");
	set("inquiry", ([
        	"除暴(组队)" : (: ask_job :),
            ]));

        setup();
      //  carry_object("/clone/misc/changpao")->wear();
}

int ask_job()
{
	object me;
	object *team,memory;
	int i,size;
	me = this_player();

	if(!me->is_team_leader())
	{
		tell_object(me,"你不是领队。\n");
		return 1;
	}
	team = me->query_team();
	size = sizeof(team);
	if(!pointerp(team) || sizeof(team) < 2)
	{
		tell_object(me,"你的人手不够。\n");
		return 1;
	}
	if(sizeof(team) > 10)
	{
		tell_object(me,"超过10人无法进入。\n");
		return 1;
	}
	for(i = 0;i<size;i++)
	{
		if(!team[i]) continue;
        	if (team[i]->query("combat_exp") <= 800000)
                {
                	tell_object(me, HIG"呵呵～,你们队伍里面还有没到80万的，以后再来吧！\n"NOR);
                 	return 1;
                }
        	if (team[i]->query("fubentd") >= 2)
                {
                	tell_object(me, HIG"呵呵～,你们队伍里面有副本次数用完的，以后再来吧！\n"NOR);
                 	return 1;
                }
                if (team[i]->is_ghost())
                {
                	tell_object(me, HIY"呵呵～,你的队伍里还有个死人!!!!!!\n"NOR);
                 	return 1;
                }
    }

	//删除旧的副本
	memory = me->query_temp("mirror/mirror_memory");
	if(objectp(memory))
	{
		memory->delete("user_id");
	}
	//创建新的副本
	MIRROR_SYS->mirror(team,me);
	for(i = 0;i<size;i++)
	{
   team[i]->add("fubentd",1);
    }
}