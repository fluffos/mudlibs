//D:\xkx\d\liuxiu-shanzhuang\npc\ashu.c阿姝
#include <ansi.h>
inherit NPC;
#include "../newbie_village.h"

int do_follow(string);
void command_me(string);
void mees1(object);
void mees2();
void mees3();
void mees4();
void check_player(object,object);

void create()
{
	set_name("阿姝", ({ "a shu", "ashu", "shu"}));
	set("title","柳秀山庄丫鬟");
	set("gender", "女性");
	set("age", 18);
	set("long", "生得仪容不俗，眉目清明，虽无十分姿色，却亦有动人之处。\n");

	set("combat_exp", 3000);
	set_temp("apply/attack",  10);
	set_temp("apply/defense", 10);
    
	set_skill("dodge", 20);
	set_skill("taiyi-you", 20);
	set_skill("taiyi-zhang", 20);
	set_skill("parry", 20);
	set_skill("strike", 20);

	map_skill("dodge", "taiyi-you");
	map_skill("strike", "taiyi-zhang");
	map_skill("parry", "taiyi-zhang");

	prepare_skill("strike", "taiyi-zhang");
    
	set("shen_type", 1);
	setup();

	carry_object("/d/city/obj/qun")->wear();

}

void init()
{
	add_action("do_follow","follow");
	
}

int do_follow(string arg)
{
	object who,ob;
	who=this_player();
	ob=this_object();
	
    if (id(arg))
    {
        if (1==check_questindex( who, "使用follow a shu命令跟随丫鬟阿姝，然后她会带你熟悉一下山庄") && 0==ob->query("player"))
        {
            ob->set("player",who);
            call_out("mess1", 1, who);
            call_out("command_me",2,"go north");
            call_out("mess2",3);
            call_out("check_player",3,ob,who);
            call_out("command_me",7,"go south");
            if ("男性"==who->query("gender"))
            {
                call_out("command_me",8,"go west");
                call_out("mess3",9);
            }
            else
            {
                call_out("command_me",8,"go east");
                call_out("mess4",9);
            }
            call_out("check_player",9,ob,who);
            call_out("command_me",14,"go north");
            call_out("check_player",15,ob,who);
            
        }
        else if (1==check_questindex( who, "使用follow a shu命令跟随丫鬟阿姝，然后她会带你熟悉一下山庄") && who!=ob->query("player"))
        {
            command("say "+who->query("name")+"，我现在正带着其他人熟悉山庄,你稍后再来找我吧。\n");
            who->set_leader(0);
            return 1;
        }
    }
    return 0;
}

void command_me(string arg)
{
	command(arg);
}

void mess1(object me)
{
	command("say "+me->query("name")+RANK_D->query_respect(me)+"，那我们现在就开始参观吧，我先带你去正厅的北面看下。\n");
}
void mess2()
{
	command("say 这里是尚武堂，用于习武和切磋的地方，你以后有机会的话可以找这里的武师求教。\n再北面是山庄的藏书阁，藏书阁要有庄主的许可才可以进去，这次就不带你进去了。\n");
}
void mess3()
{
	command("say 这里是招待男客休息的地方，你需要恢复体力的时候可以在这里睡觉(sleep)。\n");
}
void mess4()
{
	command("say 这里是招待女客休息的地方，你需要恢复体力的时候可以在这里睡觉(sleep)。\n");
}


void check_player(object ob,object who)
{
	object room,here;
	here=environment(ob);
    
    if(!( room = find_object(__DOMAIN_DIR__"zhengting")) )
        room = load_object(__DOMAIN_DIR__"zhengting");

	if (!objectp(who)) 
	{
		ob->set("player",0);
		ob->move(room);
	}
		
	if (!present(who,here))
	{
        remove_call_out("mess1");
		remove_call_out("mess2");
		remove_call_out("mess3");
		remove_call_out("mess4");
		remove_call_out("command_me");
        remove_call_out("command_me");
        remove_call_out("command_me");
        remove_call_out("command_me");
		remove_call_out("check_player");
		remove_call_out("check_player");
		ob->set("player",0);
		ob->move(room);
		command("tell "+who->query("id")+" 你怎么乱跑没跟着我呢，我先回正厅去了，你过来重新跟随我吧！\n"NOR);
        return;
	}

	if (file_name(here)==__DOMAIN_DIR__"nanyushi" || file_name(here)==__DOMAIN_DIR__"nvyushi")
    {
        command("say 你先在这里洗个澡(bath)，然后来见我们庄主吧，我就先回去了。\n");
        command("say 记得不要再跟随我了。(follow none)\n");
		ob->set("player",0);
		ob->move(room);
        
        set_nextquest(who,"使用follow a shu命令跟随丫鬟阿姝，然后她会带你熟悉一下山庄","请把衣服脱了,好好在这里洗个澡吧。", 20, 100);
    }
    else if (file_name(here)!=__DOMAIN_DIR__"shangwutang" && file_name(here)!=__DOMAIN_DIR__"wxiangfang" && file_name(here)!=__DOMAIN_DIR__"exiangfang")
    {
        remove_call_out("mess1");
		remove_call_out("mess2");
		remove_call_out("mess3");
		remove_call_out("mess4");
		remove_call_out("command_me");
        remove_call_out("command_me");
        remove_call_out("command_me");
        remove_call_out("command_me");
		remove_call_out("check_player");
		remove_call_out("check_player");
		ob->set("player",0);
		ob->move(room);
		command("tell "+who->query("id")+" 我有些急事要回正厅先处理下，你到正厅重新来跟随我吧！\n"NOR);   
    }
    return;
 }
 
 void unconcious()
{
    this_object()->set("player",0);
    ::unconcious();
}