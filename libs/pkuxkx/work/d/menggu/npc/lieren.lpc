// alucar，感谢alucar完成最为复杂的蒙古地图，特设立quest一项以资感谢
// create by zine 2012
#include <ansi.h>

inherit NPC;
#include "/d/menggu/shediao_bonus.h"
int ask_job();
void create()
{
	set_name("猎人", ({"lie ren","hunter","ren"}));
	set("long", 
            HIR"他就是漠北最著名的猎手，最近似乎在捕猎一只火狐狸。\n"NOR);
	set("gender", "男性");
	set("age", 40);
    set("combat_exp", 50000);
    set_skill("unarmed", 35);
    set_skill("force", 35);
    set_skill("dodge", 40);
    set_temp("apply/attack", 30);
    set_temp("apply/defense", 40);
	set("shen_type", 1);
	set("inquiry", ([
			"打猎" : (: ask_job :),
            "hunter" : (: ask_job :),
            
       	]) );
	setup();
	carry_object(__DIR__"items/pixue")->wear();
	carry_object(__DIR__"items/cloth4")->wear();
	
    
}
	
int ask_job()
{
	object me=this_player();
	object ob=this_object(),fox,caoyuan,where;
	if (me->query("mengguquest/hunter_finish"))
	{
		command("thumb "+me->query("id"));
		return 1;
	}
	if (time()-ob->query_temp("mengguquest/hunter/start")<500)
	{
		command("say 现在有人去逮它了，这畜生精得很，人多反而坏事。");
		return 1;
	}
	if (me->query_temp("mengguquest/hunter/start"))
	{
		if (time()-me->query_temp("mengguquest/hunter/start")>=500)
		{
			command("sigh");
			command("say 这畜生跑掉了。");
			me->delete_temp("mengguquest/hunter");
			return 1;
		}
		command("say 快去吧，这畜生精得很，迟了恐怕就跑了。");
		return 1;
	}
	caoyuan=load_object("/d/menggu/caoyuan3");
	if (!caoyuan->query("fully_generated")&&!caoyuan->query("generating"))
        {
            caoyuan->start();
			command("say 这畜生暂时毫无踪影，迟些再说吧。");
			return 1;
        }
	where=load_object(caoyuan->query("gene_rooms/"+random(sizeof(caoyuan->query("gene_rooms")))));
	if (!objectp(where)||!where->isroom())
	{
		command("say 这畜生暂时毫无踪影，迟些再说吧。");
		return 1;
	}
	fox=new(__DIR__"fox");
	fox->move(where);
	ob->set_temp("mengguquest/hunter/start",time());
	me->set_temp("mengguquest/hunter/start",time());
	command("say 在斡难河草原里有一只火狐狸，我一直想要它的皮，可惜它精得很，寻常不能近身，你能帮我吗？\n");
	tell_object(me,HIR+"你心中暗想，估计只有用弓箭才能猎到这只狐狸了。\n"+NOR);
	return 1;
}

int dest(object ob)
{
	if (ob)
	{
		destruct(ob);
	}
	return 1;
}

int accept_object(object me,object ob)
{
	int e_reward;
	if (me->query("mengguquest/hunter_finish")==2)
	{
		return notify_fail(this_object()->name()+"道：“上次可是多亏了你啦。”\n");
	}
	if (!me->query_temp("mengguquest/hunter/start"))
	{
		return notify_fail(this_object()->name()+"道：“这么贵重的东西，我可不敢收。”\n");
	}
	if (!ob->query("is_fox_fur"))
	{
		return notify_fail(this_object()->name()+"道：“不要。”\n");
	}
	if (!me->query("mengguquest/hunter_finish"))
	{
		return notify_fail(this_object()->name()+"道：“这是赃物吧？”\n");
	}
	if (ob->query("owner")!=me->query("id"))
	{
		return notify_fail(this_object()->name()+"道：“这是赃物吧？”\n");
	}
	if (me->query_temp("mengguquest/hunter/start")&&me->query("mengguquest/hunter_finish")==1)
	{
		me->set("mengguquest/hunter_finish",2);
		e_reward=bonus(me,1600);
		me->add("potential",e_reward);
		user_record(me,e_reward,"fox_2");
		me->add_busy(1);
		call_out("dest",1,ob);
		me->delete_temp("mengguquest/hunter");
		tell_object(me,HIW"完成蒙古支线任务【火狐狸】续章【拾金不昧】，你被奖励了"+chinese_number(e_reward)+"点潜能！\n"NOR);
		return 1;
	}
	return notify_fail(this_object()->name()+"道：“不要。”\n");
}
