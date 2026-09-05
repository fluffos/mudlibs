// zongguan.c
// 导师流派内负责一些日常事务的NPC
// created By zine 2013/1/15
#include <ansi.h>
inherit NPC;
int ask_hire();
int is_steward()
{
	return 1;
}
#define HIRE_COST 150
void create()
{
	string name,*tmp,*pinying;
	name=NAME_D->create_name();
	tmp=explode(name,"@");
	pinying=explode(tmp[1]," ");
	set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
        
	set("long",
	"他曾是一家大户人家的总管，管理大家族得心应手。\n"
         );
	set("title",HIY"大总管"NOR);
	set("gender", "男性");
	
	set("age", 50);
	set("attitude", "peaceful");
	set("shen_type", 1);
   	set("str", 30);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("per", 25);
    set("uni_target",1);
    set("no_get",1);
	set("max_qi", 1000);
    set("qi", 1000);
    set("max_jing", 1000);
    set("jing", 1000);
    set("max_jingli", 1000);
    set("jingli", 1000);
    set("neili", 900);
	set("max_neili", 900);
	set("jiali", 5);
    set_skill("hand", 50);
	set_skill("parry",50);
	set_skill("dodge", 50);
	set_skill("force",50);
	set_skill("literate",200);
	set("combat_exp", 65000);
	
    set("inquiry", ([
			"雇佣" : (: ask_hire :),
            "hire" : (: ask_hire :),
     
       	]) );
	set("no_get","光天化日之下怎么能随意劫持活人呢？\n");
	setup();
	carry_object("clone/cloth/cloth")->wear();
	call_out("disappear",900+random(300));
}
void init()
{
    add_action("do_post", "post");
	add_action("do_list", "list");
	add_action("do_discard", "discard");
}
void disappear()
{
	fullme();
	message_vision(WHT"$N迅速把自己隐藏在黑暗中。\n"NOR,this_object());
	return;
}
void die()
{
	disappear();
}
void unconcious()
{
	die();
}
int hello(object me)
{
	if (!userp(me)) return 1;
	command("whisper "+me->query("id")+" "+COLOR_D->uncolor(me->query("name"))[0..1]+"先生，你有什么吩咐？");
	return 1;
}
int moving(object where)
{
	where->restore();
	where->set("steward/name",query("name"));
	where->set("steward/id",parse_command_id_list());
	where->set("steward/due_date",time()+2592000);
	where->save();
	destruct(this_object());
	return 1;
}
int legal_env()
{
	if (environment(this_object())==this_object()->query("serve_place"))
	return 1;
	return 0;
}
int ask_hire()
{
	object me=this_player(),where;
	if (SECURITY_D->get_status(me->query("id")) != "(guider)")
	{
		command("say 我一般只为大户人家服务，我想你是雇佣不了我的。");
		return 1;
	}
	if (me->query("guider/score")<HIRE_COST)
	{
		command("say 雇佣我需要"+HIRE_COST+"点导师信誉度，目前来说，你还差了点。");
		return 1;
	}
	if (!me->query_temp("wanna_hire_zongguan"))
	{
		me->set_temp("wanna_hire_zongguan",1);
		command("say 雇佣我需要"+HIRE_COST+"点导师信誉度，如果确定了，请再次输入此命令。");
		return 1;
	}
	if (!stringp(me->query("group_title_by")))
	{
		command("say 好像你还没有新手基地吧？你要我去打理哪里呢？");
		tell_object(me,"如果你已经有了一间新手基地，请返回新手同步以后回到这里即可雇佣总管了。(对应最早的获得新手基地的玩家)\n");
		return 1;
	}
	if (!where=load_object(me->query("group_title_by")))
	{
		command("say 你的新手基地好像出错了，请尽快和Zine联系修复。");
		return 1;
	}
	if (where->query("steward"))
	{
		command("say 你的新手基地里已经有一位总管了。");
		return 1;
	}
	if (query("hired"))
	{
		if (query("hired")==me)
		command("say 你不是已经雇佣了我吗？一会新手基地见。");
		else
		command("say 对不起，我已经被雇佣了。");
		return 1;
	}
	set("hired",me);
	command("tell "+me->query("id")+" 既然你给的条件这么优厚，我就跟你走了，记得我的薪酬大约是五百两黄金一个月，你别忘了哦。");
	command("tell "+me->query("id")+" 你可以一次给我很多钱，我会服务到付薪酬的期限，如果没有钱，我会卷铺盖走人的。");
	command("tell "+me->query("id")+" 第一个月作为试用期，我就不要求工资了，我去收拾一下东西，一会新手基地见。");
	command("tell "+me->query("id")+" 我不会打扰你们的生活，只要在大厅招手(wave)我就会过来的。");
	me->add("guider/score",-HIRE_COST);
	tell_object(me,"雇佣下"+query("name")+"，你花费了"+HIRE_COST+"点导师信誉度。\n");
	remove_call_out("moving");
	call_out("moving",30+random(30),where);
	return 1;
}
int do_list()
{
    command("say "+environment(this_object())->do_list());
	return 1;
}

int do_post(string arg)
{
    command("say "+environment(this_object())->do_post(arg));
	return 1;
}

int do_discard(string arg)
{
    //command("say "+environment(this_object())->do_discard(arg));
	command("say 现在不许删除留言了。");
	return 1;
}

int accept_object(object me,object ob)
{
	object env=environment(this_object());
	if (!legal_env())
	{
		command("say 不论你要给我什么，回去再说吧。");
		return 1;
	}
	if (!ob->query("money_id"))
	{
		command("say 除了薪酬之外，我不能接受其他东西。");
		return 1;
	}
	if (!env->owner_access(me)&&!env->valid_access(me)&&!env->old_student(me))
	{
		command("say 只有本宗派的人可以给我酬劳。");
		return 1;
	}
	if (ob->value()>50000000)
	{
		command("say 每次最多给我5000两金薪水。");
		return 1;
	}
	if (ob->value()<1000000)
	{
		command("say 每次最少给我100两金薪水。");
		return 1;
	}
	env->restore();
	env->add("steward/due_date",ob->value()/2);
	env->save();
	command("say 谢谢你的薪水，我将继续为你的宗派服务至"+ctime(env->query("steward/due_date"))+"为止。\n");
	ob->move(VOID_OB);
	destruct(ob);
	return 1;
}

int recognize_apprentice(object ob)
{
	if (ob->query_skill("literate",1)<100)
	return 0;
	if (environment(ob)->get_rank(ob->query("id"))!=6)
	return 0;
	return 1;
}