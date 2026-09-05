//trainer.c 指导练武的教头
//by zoom
//2003.4.6

#include <ansi.h>
inherit NPC;

int ask_help();
void do_check();
void greeting(object);
void create()
{
        set_name("教头", ({ "jiao tou", "tou" }) );
        set("gender", "男性" );
        set("age", 24);
        set("long","这是新手学堂的教头，专门负责指导新手。\n");
        set("attitude", "peaceful");
        set("str", 20);
        set("con", 20);
        set("int", 20);
        set("dex", 20);
        set("max_qi", 1500);
        set("max_jing", 100);
        set("neili", 500);
        set("max_neili", 500);
        set("jiali", 10);
        set("shen_type", 0);
        set("combat_exp", 20000);
        set_skill("force", 40);
        set_skill("strike", 40);
        set_skill("sword", 40);
        set_skill("dodge", 40);
        set_skill("parry", 40);
	set_skill("taiyi-shengong",40);
	set_skill("taiyi-zhang",40);
	set_skill("taiyi-jian",40);
	set_skill("taiyi-you",40);
	map_skill("force", "taiyi-shengong");
	map_skill("strike", "taiyi-zhang");
	map_skill("sword", "taiyi-jian");
	map_skill("dodge", "taiyi-you");
	prepare_skill("strike", "taiyi-zhang");
        set("inquiry", ([
	        "here"   :  "这里是新手学堂，是指导新手熟悉环境和有关指令的地方。\n",
	        "help"   :  (: ask_help :),
        ]));
        set("shen_type",-1);
set("score",500);
setup();
}

void init()
{
        object me = this_player();        
        ::init();

//        add_action("do_skills", "skills wushi", 1);

        if( interactive(me) )
        {
                remove_call_out("do_check");
                call_out("greeting", 1, me);
        	call_out("do_check", 1);
        }
}

int ask_help()
{
	object me = this_player();
	me->set_temp("newbie/lian",0);
	call_out("greeting", 1, me);
	return 1;
}

void greeting(object me)
{
	if(!me->query_temp("newbie/lian"))
		{	command("hi " + me->query("id"));
                        command("tell " + me->query("id")+" " +"  
    欢迎来到这里，我是新手学堂的教头，你应该已经学会了一些功夫，现在我就来
教你如何运用它们。
    首先我们来讲内功：学武之人，都要学习内功，它决定了你战斗时能加力的大小，
影响你体力恢复的速度，而且，一些高级的功夫都要内功支持才能学习。所以，内功
是非常重要的。跟师傅学会了某种特殊内功之后，要把它激发 (enable force xxx)，
这样你就可以来练内力了，打坐可以提高你的内力修为，指令有两个，dz 和 dazuo，
它们有一点细微的差别，dz指令不消耗体力，同时可以修炼基本内功，如果内功在三
百级以上的话，还有可能打通任督二脉，但是花的时间比较长，而且如果在打坐过程
中遇到外界干扰，可能会走火入魔。而dazuo指令，是把体力转化为内力，当然要配合
适当的休息才行，指令格式为：dazuo <num>， num为想要转化的体力的数字，就是把
num数量的体力转化为内力。好了，你先自己试着练习一下吧。 要注意的是dazuo指令
是exercise指令的别名，是为了方便玩家设定的，要在alias中使用的话，以后者为准
还有一些类似的指令，可以通过help 指令来查看。\n");
		me->set_temp("newbie/lian",1);
	}
}

void do_check()
{
	object me = this_player();

	if(me->query_temp("newbie/lian")==1&&me->query("max_neili")>20) 
	{
		tell_object(me, HIG"恩，不错，你已经有了一定的内力修为，我们来讲一下内功的高级用途： 所有内功都
具有补精，补气的功能 。不同门派的内功还有自疗，疗人，加力，狮子吼等功能，这
些都可以使用 exert|yun 指令来使用。门派帮助中有本门功夫的具体介绍，也可以用
verify <功夫名称>指令来查询具体的某种内功的作用。
例如：	exert regenerate	恢复自己的精
	exert recover          	恢复自己的气
\n"NOR );
		me->set_temp("newbie/lian",2);
                remove_call_out("do_check");		
		call_out("do_check",15);
	}
	else if(me->query_temp("newbie/lian")==2)
	{
		tell_object(me, HIG"
除了内功一般还要学习几门外功，包括空手功夫和兵器功夫，其中有一些有特殊攻击，
在达到要求后(级别或解谜)，就可以使用perform指令来发招，大部分perform都只能
在战斗中使用，少数没有要求。可以用verify指令来查询外功中有哪些特殊攻击。以
丐帮的降龙十八掌为例，输入 verify 得到 ：外功方面 ( perform + leiting ) ，
这样我们就可以用perform leiting或者perform strike.leiting来使用了。\n"NOR );
		me->set_temp("newbie/lian",3);
	}
	else
		call_out("do_check",2);
return;
}

int accept_fight(object ob)
{
    if((int)ob->query("combat_exp")<10000)
	return notify_fail("教头笑道：你的经验太低了，还是先和木人练习一下吧！\n");
    return 1;
}

void unconcious()
{
        die();
}

void die()
{
        this_object()->set("eff_qi",this_object()->query("max_qi"));
        this_object()->set("qi",this_object()->query("max_qi"));
        this_object()->set("eff_jing",this_object()->query("max_jing"));
        this_object()->set("jing",this_object()->query("max_jing"));
        return;
}
