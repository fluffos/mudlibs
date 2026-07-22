// seng-ren.c 僧人
// Lklv modify at 2001.10.21

#include <ansi.h>
inherit NPC;

string ask_me();
string ask_me1();
string ask_me2();

void create()
{
        set_name("游方和尚", ({"seng ren","seng"}));
        set("long", "他是一位中年游方和尚，身上的袈裟打满了补丁。\n");
        set("gender", "男性");
        set("attitude", "friendly");
        set("class", "bonze");

        set("age", 65);
        set("shen_type", 1);
        set("str", 20);
        set("int", 30);
        set("con", 25);
        set("dex", 23);
        set("max_qi", 280);
        set("max_jing", 300);
        set("neili", 800);
        set("max_neili", 800);
        set("jiali", 150);
        set("combat_exp", 10000);
        set("shen_type", 0);
        set("chat_chance", 30);

        set_skill("force", 40);
        set_skill("unarmed", 40);
        set_skill("dodge", 40);
        set_skill("parry", 40);
	set("jing_count", 1);
	setup();
	carry_object("/d/shaolin/obj/cloth")->wear();
	set("inquiry", ([
		"name" : (: ask_me :),
		"here" : ( : ask_me1 :),
		"禅理" : (: ask_me2 :),
		"金刚经" : "那石坪上所刻既是金刚经,书中所论具是禅宗修为的精髓之道.\n",
	]));
	setup();
}

void init()
{
        add_action("do_say", "say");
}

string ask_me()
{
	object me = this_player();

	if (me->query_temp("sl_wm1")){
		command("look "+me->query("id"));
		me->delete_temp("sl_wm1");
		me->set_temp("sl_wm2",1);
		return "老衲法号早已忘记了.\n";
	}
	return "老衲云游四方,法号早已忘记了.\n";
}

string ask_me1()
{
	object me = this_player();

	if (me->query_temp("sl_wm2")){
		command("look "+(string)me->query("id"));
		me->delete_temp("sl_wm2");
		me->set_temp("sl_wm3",1);
		return HIW"此地是石经峪，前朝有位能工巧匠，偶然得到一本焚文金刚经，读过之后
顿时大彻大悟，后来呕心呖血将经书用篆体刻于此坪之上，用以感悟世人，石坪完工之时，
他也坐化于此。老衲常在此默诵石碑，感悟禅理。\n"NOR;
	}

	return "此地是石经峪，前朝有位能工巧匠，偶然得到一本焚文金刚经，
读过之后顿时大彻大悟，后来其呕心呖血将经书用篆体刻于此坪之上，用以感悟世人，
石坪完工之时，他也坐化于此。\n";
}

string ask_me2()
{
	object me = this_player();

	if (me->query_temp("sl_wm3")){
		me->delete_temp("sl_wm3");
		me->set_temp("sl_wm4",1);
		return RANK_D->query_respect(this_player())+"可以在此默读金刚经,或许能悟彻禅宗之意.";
	}
	if (me->query_temp("sl_findjing")){
		command(":) "+(string)me->query("id"));
		me->set_temp("sl_wm5",1);
		me->delete_temp("sl_findjing");
		return HIW"从前有个老婆婆，卧在树下休息，忽有大熊要来吃她。老婆婆绕树奔逃
大熊伸掌至树后抓拿，老婆婆乘机把大熊两只前掌捺在树干之上，熊就不能动了，但老婆
婆也不敢放手。后来有一人经过，老婆婆请他帮忙，一同杀熊分肉。那人信了，按住熊掌
。老婆婆脱身远逃，那人反而为熊所困，无法脱身。你可知此寓意？\n"NOR;
	}

	return RANK_D->query_respect(this_player())+"可知道此地的由来?";
}

int do_say(string arg)
{
	object me = this_player();

	if ((arg=="救人危难，奋不顾身，虽受牵累，终无所悔。"
	 ||arg=="救人危难,奋不顾身,虽受牵累,终无所悔."
	 ||arg=="救人危难，奋不顾身，虽受牵累，终无所悔.")
	 && me->query_temp("sl_wm5")){
		if (query("jing_count") >= 1){
			me->delete_temp("sl_wm5");
			me->set_temp("sl_bookget",1);
			message_vision(HIW"$N挺胸大声说道：“救人危难，奋不顾身，虽受牵累，终无所悔。”\n"NOR,me);
			message_vision(HIW"老僧袍袖似乎动了一下，然后微微一笑说道,"+ RANK_D->query_respect(this_player())+"既来过，为何不走？\n"NOR,me);
			new(__DIR__"obj/f_jing")->move(me);
			add("jing_count", -1);
			return 1;
		}
		me->delete_temp("sl_wm5");
		message_vision("老僧然后微微一笑说道，本有一物相赠"
		+ RANK_D->query_respect(this_player())+"，但已经被人取走，下次如果天缘巧合，请再来此讲论佛法。\n",me);
		return 1;
	}
}

void kill_ob(object ob)
{
       ob->remove_killer(this_object());
       remove_killer(ob);
       message_vision("$N发现游方僧淡淡一笑,丝毫没有畏惧,不禁心中一颤。\n", ob);
}
