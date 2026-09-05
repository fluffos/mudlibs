//master.c 练习拜师、学习武功的临时师傅
//by zoom
//2003.4.6

#include <ansi.h>
inherit NPC;
#include <title.h>
int do_bai();
int do_skills();
void do_check();
void greeting(object);
void create()
{
        set_name("武师", ({ "wushi", "shi" }) );
	set("title","[1;37m新手学堂[1;31m开山祖师[0m");
        set("gender", "男性" );
        set("age", 24);
        set("long","这是新手学堂的开山祖师，真个新手学堂就是他创建的。
他的武功并不高，平时也只是指点新手一点武功。\n");
        set("attitude", "peaceful");
        set("con", 25);
//容易产生bug,加一个no_get,by advent
        set("str", 100);
        set("no_get", 1);
        set("int", 25);
        set("dex", 25);
	set("per",300);
        set("max_qi", 1500);
        set("max_jing", 100);
        set("neili", 1200);
        set("max_neili", 1200);
        set("jiali", 110);
        set("shen_type", 0);
        set("combat_exp", 50000);
        set_skill("force", 100);
        set_skill("strike", 100);
        set_skill("sword", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
	set_skill("taiyi-shengong",100);
	set_skill("taiyi-zhang",100);
	set_skill("taiyi-jian",100);
	set_skill("taiyi-you",100);
	map_skill("force", "taiyi-shengong");
	map_skill("strike", "taiyi-zhang");
	map_skill("sword", "taiyi-jian");
	map_skill("dodge", "taiyi-you");
	map_skill("parry", "taiyi-zhang");
	prepare_skill("strike", "taiyi-zhang");
        set("shen_type",-1);
set("score",500);
setup();
}

void init()
{
        object me = this_player();        
        ::init();

        add_action("do_skills", "skills wushi", 1);
        add_action("do_skills", "skills shi", 1);
        add_action("do_bai", "apprentice wushi", 1);
        add_action("do_bai", "apprentice shi", 1);
        add_action("do_bai", "bai wushi", 1);
        add_action("do_bai", "bai shi", 1);

        if( interactive(me) )
        {
                remove_call_out("do_check");
                call_out("greeting", 1, me);
        	call_out("do_check", 1);
        }
}

void greeting(object me)
{
	if(!me->query_temp("newbie/bai"))
		{	command("hi " + me->query("id"));
                        command("tell " + me->query("id")+" "+"
    欢迎来到这里，我是新手学堂的武师，你可以在这里练习一些拜师的指令。
也可以跟我学一些粗浅的功夫，当然这些都只是做练习用的。
现在我们开始练习，首先请输入id here，查看当前房间人物的id，你看到的
武师                 = wushi, shi
就是我的id了，这样你就可以用bai <id>来拜师，wushi 和 shi 都是有效的id，
如输入bai wushi。");
	}
}

void do_check()
{
	object me = this_player();
	if(me->query_temp("newbie/bai")==1) 
	{
		tell_object(me, HIG"恩，不错，你现在可以用title指令看看自己的头衔。
你已经拜过师傅了，现在你可以用skills <师傅id>来查看你师傅的武功。
用learn <师傅id> <武功名称> <次数>来学习师傅的武功。skills可以查看自己的功夫。
好了，先练习一下吧。需要注意的是跟师傅学习是要消耗潜能的，也就是你学习的能力，
用hp命令和score(sc)命令可以查看自己的一些参数。\n"NOR );
		me->set_temp("newbie/bai",2);
                remove_call_out("do_check");		
		call_out("do_check",15);
	}
	else if(me->query_temp("newbie/bai")==2)
	{
		tell_object(me, HIG"跟师傅学习了特殊武功之后，要激发这种武功才能使用，
使用指令enable <基本武功> <特殊武功> 来激发武功，当然要对应的功夫才可以。可以
用verify <功夫名称>来查看这种武功的用途。\n"NOR );
		me->set_temp("newbie/bai",3);
                remove_call_out("do_check");		
		call_out("do_check",15);
	}
	else if(me->query_temp("newbie/bai")==3)
	{
		tell_object(me, HIG"武功除了和师傅学习，还可以自己练习，当然一般的内功是不能通过练习来提高的。练习
时，要先激发你要练习的武功，例如轻功，就可以用practice dodge来练习了\n"NOR );
		me->set_temp("newbie/bai",4);
                remove_call_out("do_check");		
		call_out("do_check",15);
	}
	else if(me->query_temp("newbie/bai")==4)
	{
		tell_object(me, HIG"好了，你自己可以练习一下这些指令的使用，下一站会教你如何使用这些功夫来打架。
如果对我的武功感兴趣，可以学一些，但是除了基本武功之外的这些都是我自己一时兴起，创出来的，
不能用来闯荡江湖，如果出去之后觉得没用的话，可以放弃这些功夫(abandon <功夫名称>)。\n"NOR );
		me->set_temp("newbie/bai",5);
	}
	else
		call_out("do_check",2);
return;
}

int do_bai()
{
	object me = this_player();
      if (me->query("combat_exp")>10000)
      return notify_fail ("武士斜眼看着你说：阁下还是请回吧，我只教新手功夫的！\n");;
	if(me->query_temp("newbie/bai")>0)
		message_vision("你恭恭敬敬地向武师磕头请安，叫道：「师父！」\n",me);
	else
	{
		command("say 好吧,那我就收下你了!\n");
		message_vision("$N想要拜武师为师。\n",me);
		message_vision("武师说道：好吧,那我就收下你了!\n",me);
		message_vision("武师决定收$N为弟子。\n",me);
		message_vision("$N跪了下来向武师恭恭敬敬地磕了四个响头，叫道：「师父！」\n",me);
		tell_object(me,"恭喜您成为新手学堂学员。\n");
	  me->set("title",HIW"新手学堂"NOR+HIR"学员"NOR);
//title系统记录玩家title by seagate@pkuxkx
	  me->set_title(TITLE_RANK, HIW"新手学堂"NOR+HIR"学员"NOR);
		me->set_temp("newbie/bai",1);
	}
return 1;
}

int recognize_apprentice(object ob)
{
	return 1;
}

int do_skills()
{
write( "[44;1m[1;33m 武师目前所学过的技能：（共九项技能）\n\n[37;0m");
printf("┌[42m[37m    五项基本功夫    [37;0m──────────────────────┐");
message_vision("
│  基本轻功 (dodge)                         - [36m半生不熟[37;0m 100/     0│
│  基本内功 (force)                         - [36m半生不熟[37;0m 100/     0│
│  基本招架 (parry)                         - [36m半生不熟[37;0m 100/     0│
│  基本掌法 (strike)                        - [36m半生不熟[37;0m 100/     0│
│  基本剑法 (sword)                         - [36m半生不熟[37;0m 100/     0│
└────────────────────────────────┘
\n",this_object());
printf("┌[42m[37m    四项特殊功夫    [37;0m──────────────────────┐");
message_vision("
│[1;32m□[37;0m太乙神剑 (taiyi-jian)                    - [36m半生不熟[37;0m 100/     0│
│[1;32m□[37;0m太乙神功 (taiyi-shengong)                - [1;32m第四重楼[37;0m 100/     0│
│[1;32m□[37;0m太乙神游 (taiyi-you)                     - [36m半生不熟[37;0m 100/     0│
│[1;32m□[37;0m太乙神掌 (taiyi-zhang)                   - [36m半生不熟[37;0m 100/     0│
└────────────────────────────────┘
\n",this_object());
       return 1;
}
