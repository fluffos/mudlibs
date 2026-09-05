//陈萧然, hoho

#include <ansi.h>
inherit NPC;
void greeting(object ob);
int accept_object(object who, object ob);
void create()
{
	seteuid(getuid());
        set_name(HIW"雪山隐者"NOR, ({ "yin zhe", "yinzhe", "yin", "zhe" }));
	set("long", "他一身飘逸的白色长衫，双眼中似乎蕴含了无穷智慧。\n");
	set("nickname", HIM "剑胆琴心" NOR);
	set("gender", "男性");
	set("age", 80);
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

	set("axe", 1);

	set_skill("unarmed", 100);
	set_skill("hand", 100);
	set_skill("dodge", 120);
	set_skill("parry", 100);
	set_skill("force", 100);
	set("chat_chance", 10);
	set("chat_msg", ({
                  "雪山隐者吟道: 晚来天欲雪，能饮一杯无？来喝一杯吧。\n",
		"雪山隐者自言自语道: 前几天捡到一把"+HIW"破冰斧"NOR+"不知道是谁丢的？\n"
		}) );

         set("inquiry",([
        "破冰斧" : "你若能找到"YEL"女娲石"NOR"给老夫,以了却平生的心愿，我就把破冰斧给你。\n",
        "女娲石" : "据说桃花岛能找到此物，不知道传言是真是假。\n",
         ]) );

         set("shen_type",1);set("score",500);setup();

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

           say(HIY"雪山隐者笑了笑，说：这位"+RANK_D->query_respect(ob)+
               ",欢迎到我这里来。\n"NOR);
	return;
}

int accept_object(object who, object ob)
{
	object axe;
	if(query("axe") < 1)
	{
		tell_object(who, HIW"你来晚了，破冰斧已经不在我处。\n"NOR);
		return 0;
	}
	if (ob->query("id") == "nvwa shi" && ob->name() == YEL"女娲石"NOR)
	{
		tell_object(who, "雪山隐者叹了口气，说：今日既已得偿所愿，这把破冰斧就送给你吧。\n");
                axe=new("/d/changbai/obj/snow_axe");
                axe->move(this_player());
                add("axe", -1);
                call_out("des", 1, ob);
                tell_object(who, HIW"\n雪山隐者给你一把破冰斧。\n"NOR);
		return 1;
	}
       return 0;
}

void des(object ob)
{
	destruct(ob);
}
