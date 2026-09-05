// laoren.c
inherit NPC;
#include <ansi.h>
string ask_me();
int do_halt();
int do_kill(string arg);
int do_quit();
int do_hit();
int do_fight();
int do_swear();
void create()
{
        set_name("白发老人", ({ "baifa laoren", "laoren" }) );
        set("gender", "男性");
        set("age", 70);
        set("long",
               "一位头发苍白，瘦骨嶙峋的老人，满头白发随风飘散，两只眼窝深凹，直如活鬼一般。\n");
        set("combat_exp",100000);
        set("shen_type", 1);
        set("attitude", "friendly");
        set("apply/attack", 50);
        set("apply/defense", 50);
        set("max_qi", 800);
        set("max_jing", 800);
        set("max_neili", 800);
        set("neili", 800);
        set_skill("force", 80);
        set_skill("unarmed", 80);
        set_skill("sword",80);
        set_skill("parry",80);
        set_skill("dodge", 80);
        set("inquiry", ([
                "绝一生死"       : (: ask_me :),
        ]));
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/d/city/obj/changjian")->wield();
}
void init()
{	object ob=this_player();
        add_action("do_halt", "halt");
	add_action("duijue",  "duijue");
	add_action("do_kill", "kill");
	add_action("do_hit",  "hit");
	add_action("do_fight", "fight");
	add_action("do_swear", "swear");
	add_action("do_quit", "quit");
	::init();
        if( interactive(ob = this_player()) )
	message_vision("白发老人抬起头，用呆滞的目光看了$N一眼，一句话不说，又低下了头。\n",ob);
 }
string ask_me()
{
        object me,ob;
	me=this_player();
	if(me->query_temp("killing") && !me->is_fighting())
	    {	command("heng");
		return("老人轻蔑的撇了你一眼，说道：快动手吧，婆婆妈妈的算什么好汉！");
	    }
	return ("“既然你二人已有必死之心。。。\n"
		"不过两人都得先启个毒誓(swear)才能绝一生死(duijue)。\n");
}

int duijue(string arg)
{       object me,ob;
        me = this_player();
        seteuid(getuid());
        if (!arg || !ob = present(arg, environment(me)))
        return notify_fail("这儿有这个活物吗，睁大眼睛找找？\n");
	if (!me->query_temp("killing"))
	return notify_fail("这不是一般地方，不要轻举妄动。\n");
	if (!ob->query_temp("killing"))
	return notify_fail("你的敌手还没有得到准许，且莫心急。\n");
	command ("chat 唉。。。");
        command ("chat " + me->name() + "与" + ob->name() + "今日在绝义谷底绝一生死! 不死不休！");
        ob->kill_ob(me);
        me->kill_ob(ob);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon") );
        COMBAT_D->do_attack(ob, me, ob->query_temp("weapon") );
        call_out("observe",1,me,ob);
	return 1;
}
int observe(object ob1,object ob2)
{
        object ob;
        if(ob1->is_fighting())
        {
                call_out("observe",1,ob1,ob2);
                return 1;
        }
        if ( !present(ob1, environment()))
        {
                CHANNEL_D->do_channel(this_object(), "jh", ob1->query("name") + "技不如人，被" + ob2->name() + "杀死。");
                ob2->delete_temp("killing");
		return 1;
        }
        if ( !present(ob2, environment()) )
        {
                CHANNEL_D->do_channel(this_object(), "jh", ob2->query("name") + "技不如人，被" + ob1->name() + "杀死。");
         	ob1->delete_temp("killing");
	        return 1;
        }

}
int do_swear()
{	object me=this_player();	
	if(me->query_temp("killing"))
	return notify_fail("启誓不是开玩笑，不能一遍又一遍个没玩！\n");
	message_vision("$N咬牙切齿道：“今日" + me->name() + "愿拼个鱼死网破，不死不休！！！\n",me);
	me->set_temp("killing",1);
	command("sigh");
	return 1;
}
int do_halt()
{
 	object me = this_player();
	tell_object(me,"你二人以性命相搏，岂能说停就停！\n");
	return 1;
}
int do_kill(string arg)
{	object me=this_player();
	if(arg=="laoren" || arg=="baifa laoren")
   {	me->start_busy(3);
   	tell_object(me,"白发老人大怒：鼠辈岂可将性命之搏视为儿戏！\n"
			"老人单指伸出，点向你的胁下，你一时只觉半身酸麻难当。\n");
	return 1;
   }
//	return notify_fail("这是什么地方，岂能随便喊打喊杀？\n");
	return 1;
}
int do_hit()
{	object me=this_player();
	tell_object(me,"这里不是可以打架斗殴的地方！\n");
	return 1;
}
int do_fight()
{	object me=this_player();
	tell_object(me,"这里不是可以打架斗殴的地方！\n");
	return 1;
}
int do_quit()
{
	object me=this_player();
	tell_object(me,"这是以性命相搏的地方，不要视为儿戏。\n");
	return 1;
}
