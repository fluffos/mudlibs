// alucar，感谢alucar完成最为复杂的蒙古地图，特设立quest一项以资感谢
// create by zine 2012
#include <ansi.h>

inherit NPC;
#include "/d/menggu/shediao_bonus.h"
int ask_job();
void create()
{
	set_name("逍遥", ({"alucar npc","xiao yao"}));
	set("title",HIC+"活地图"+NOR);
	set("long", 
            HIW"他就是北侠的徐霞客，用双脚丈量北侠大地的逍遥了。\n"NOR);
	set("gender", "男性");
	set("age", 30);
    set("combat_exp", 150000);
    set_skill("unarmed", 35);
    set_skill("force", 35);
    set_skill("dodge", 40);
    set_temp("apply/attack", 30);
    set_temp("apply/defense", 40);
	set("shen_type", 1);
	set("inquiry", ([
            "here" : "这里是大漠。",
			"帮助" : (: ask_job :),
            "help" : (: ask_job :),
            
       	]) );
	setup();
	carry_object(__DIR__"items/pixue")->wear();
	carry_object(__DIR__"items/cloth4")->wear();
	
    
}
	
int ask_job()
{
	object me=this_player();
	object ob=this_object();
	object where,marker;
	string desc,word,word2;
	if (me->query("mengguquest/alucar_finish"))
	{
		command("thank "+me->query("id"));
		return 1;
	}
	if (me->query("mengguquest/alucar")>=3)
	{
		command("thank "+me->query("id"));
		return 1;
	}
	if (me->query_temp("mengguquest/alucar"))
	{
		command("say 把图还给我了吗？");
		return 1;
	}
    while (!objectp(where) || 
          !where->isroom()||
          TASK_D->place_belong(where)=="不明区域"||
          base_name(where) == "/adm/daemons/taskd"||
		  !where->query("long"))
        {where=TASK_D->random_room("/d/menggu/");}
	desc=where->query("long");
	marker=new(__DIR__"items/marker");
	marker->move(ob);
	marker->set("desc",COLOR_D->uncolor(where->query("short")));
	word=desc[4..5];
	word2=desc[8..9];
	desc=replace_string(desc,word,"  ",1);
	desc=replace_string(desc,word2,"  ",1);
	me->set_temp("mengguquest/alucar",1);
	command("say 有这样一处地方，它的描述残缺不清，现有的文献记载，它是"+desc+"你去帮我找到这个地方，把它的地名记录(record)在"+marker->query("name")+"上吧。\n");
	command("give "+me->query("id")+" di tu");
	return 1;
}

int dest(object ob,object me)
{
	me->delete_temp("mengguquest/alucar");
	if (ob)
	{
		destruct(ob);
	}
	return 1;
}

int accept_object(object me,object ob)
{
	int e_reward;
	if (me->query("mengguquest/alucar_finish"))
	{
		return notify_fail(this_object()->name()+"对你的行为不置可否。\n");
	}
	if (!me->query_temp("mengguquest/alucar"))
	{
		return notify_fail(this_object()->name()+"对你的行为不置可否。\n");
	}
	if (!ob->query("alucar_map"))
	{
		return notify_fail(this_object()->name()+"对你的行为不置可否。\n");
	}
	if (me->query("mengguquest/alucar")<3)
	{
		call_out("dest",1,ob,me);
		message_vision("$N对着$n笑了笑。",this_object(),me);
		tell_object(me,"似乎逍遥的麻烦还没完全解决。\n");
		return 1;
	}
	if (me->query("mengguquest/alucar")==3)
	{
		call_out("dest",1,ob,me);
		command("haha");
		message_vision("$N道：“太感谢你了，蒙古的全图完成了。\n”",this_object());
		e_reward=bonus(me,2200);
		me->add("potential",e_reward);
		user_record(me,e_reward,"alucar");
		me->set("mengguquest/alucar_finish",1);
		tell_object(me,HIW"完成蒙古支线任务【逍遥的烦恼】，你被奖励了"+chinese_number(e_reward)+"点潜能！\n"NOR);
		return 1;
	}
	return notify_fail(this_object()->name()+"对你的行为不置可否。\n");
}
