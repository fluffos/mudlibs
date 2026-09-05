//guider.c 新手学堂向导
//by zoom
//2004.4.4

#include <ansi.h>
inherit NPC;

void do_leave();
void greeting(object);
void create()
{
        set_name("弟子", ({ "di zi","zi" }));
	set("long", "他是新手学堂中负责接引的弟子。\n");
	set("title",HIG"[侠客行引路使]"NOR);
	set("gender", "男性");
	set("age", 24);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 20);
	set("int", 30);
	set("con", 30);
	set("dex", 20);
	set("race", "人类");	
	set("max_qi", 400);
	set("eff_qi", 400);
	set("qi", 400);
	set("max_jing", 400);
	set("eff_jing", 400);
	set("jing", 400);
	set("max_neili", 400);
	set("eff_neili", 400);
	set("neili", 400);
	set("max_jingli", 400);
	set("eff_jingli", 400);
	set("jingli", 400);
	set("combat_exp", 5000);
	set("score", 1000);
	setup();
        carry_object("/clone/misc/cloth")->wear();
        call_out("do_leave",300);
	call_out("do_check",1);
}
void init()
{

}
void do_check()
{
	object me = query_leader();
        if(!me)
        {
            remove_call_out("do_leave");
            do_leave();
        }
        if( me && !mapp( me->query("family") ))
	{
		call_out("do_check",3);
	}
	else
	{
		tell_object(me, HIG"你已经拜过师傅了，现在你可以用skills <师傅id>来查看你师傅的武功。
用learn <师傅id> <武功名称> <次数>来学习师傅的武功。skills可以查看自己的功夫。
好了，先练习一下吧。需要注意的是跟师傅学习是要消耗潜能的，也就是你学习的能力，
用hp命令和score(sc)命令可以查看自己的一些参数。\n"NOR );
		call_out("tell_quest",10);
	}
return;
}
void tell_quest()
{
	object me = query_leader();
	if (!me) return;
	tell_object(me, HIR"好了，现在我们来熟悉一下其他的东西。\n"+
HIG"一般来说，每个门派都有自己的休息室和厨房，累了去休息室睡觉(sleep)，
饿了就去厨房找找看有没有吃的，有的时候厨房的东西被别人拿走了，就要等一会儿。\n"NOR );
	tell_object(me, HIG"熟悉了吃喝休息，就来看看如何增长经验，一般是通过做任务来获得经验和潜能，具体
看请help tasks。新手常见问题请参阅help pkuxkx-faq。如果对这里不是很熟悉的
话，最好仔细的看看help，更多内容请到www.pkuxkx.net。\n"+
HIW"新手请到download.pkuxkx.net下载pzmud462，内含这里的常用路径，非常方便。\n"NOR );
	call_out("do_finish",3);
return;
}
void do_finish()
{	
	object me;
	me = query_leader();
	if(me)
	{
		tell_object(me, "[1;32m弟子说道：“我的任务完成了，该回去复命了。”[37;0m\n" );
		command("bye "+me->query("id"));
	}
	if (this_player());
		message_vision("$N转身走了。\n",this_player());
    destruct(this_object());
    return;
}
void do_leave()
{	
	object me;
	me = query_leader();
	if(me)
	{
		tell_object(me, "[1;32m弟子说道：“我该回去了，有什么需要的话请再来新手学堂。”[37;0m\n" );
		command("bye "+me->query("id"));
	}
	if (this_player())
         message_vision("弟子转身走了。\n",this_player());
	destruct(this_object());
    return;
}
void unconcious()
{
//不晕
}
