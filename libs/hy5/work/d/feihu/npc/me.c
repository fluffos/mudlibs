//me,hoho
#include <ansi.h>
inherit NPC;
void greeting(object ob);
int accept_object(object who, object ob);
void create()
{
	seteuid(getuid());
        set_name("陈萧然", ({ "chen xiaoran", "chen", "yafeng" }));
	set("long", "他一身飘逸的白色长衫，双眼中似乎蕴含了无穷智慧。\n");
	set("nickname", HIM "剑胆琴心" NOR);
	set("gender", "男性");
	set("age", 22);
	set("attitude", "friendly");
	
	set("str", 25);
	set("int", 24);
	set("con", 25);
	set("dex", 26);

	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 800);
	set("max_jing", 800);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 10);

	set("combat_exp", 200000);
        set("no_kill",1);
        set("no_fight",1);
        set_temp("no_kill",1);
         set("no_get",1);	
	set_skill("unarmed", 100);
	set_skill("hand", 100);
	set_skill("dodge", 120);
	set_skill("parry", 100);
	set_skill("force", 100);
	set("chat_chance", 10);
	set("chat_msg", ({
		"陈萧然吟道: 晚来天欲雪，能饮一杯无？"+RANK_D->query_respect(this_player())+"喝一杯吧。\n",
		"前几天捡到一把"+HIW"破冰斧"NOR+"谁丢的呢？\n"
		}) );
         setup();
	carry_object("/d/baituo/obj/baipao")->wear();
	
}

void init()
{
	object ob;

	::init();

	if( interactive(ob = this_player()) ) 
       {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}
void greeting(object ob)
{
	
           say(HIY"陈萧然笑了笑，说：这位"+RANK_D->query_respect(ob)+
               ",欢迎到我这里来。\n"NOR);
	return;
}

int accept_object(object who, object ob)
{
	object axe;
	if (ob->query("money_id") && ob->value() >= 1000000) 
	{
		tell_object(who, "陈萧然叹了口气，说：又拿人钱财，唉....\n");
                axe=new("/d/feihu/obj/snow_axe");
                axe->set_amount(1);
                axe->move(this_player());
                tell_object(who, HIW"\n陈萧然给你一把破冰斧。\n"NOR);
		return 1;
	}
       return 0;
}

