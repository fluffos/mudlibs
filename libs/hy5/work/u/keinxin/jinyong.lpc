// jinyong.c Yu Jue 98/7/28

#include <ansi.h>

inherit NPC;

string ask_age()
{
	object me = this_player();
    object *ob = filter_array(objects(), (: userp($1) && !wiz_level($1) :));
	int no;

	ob = filter_array(ob,
		(: $2->query("age")*12+$2->query("month")
			< $1->query("age")*12+$1->query("month") :), me);
	no = sizeof(ob) + 1;
	return me->name()+RANK_D->query_respect(me)+"的年龄在目前江湖人士中排名第"
		+chinese_number(no)+"。";
}

string ask_beauty()
{
	object me = this_player();
    object *ob = filter_array(objects(), (: userp($1) && !wiz_level($1) :));
	int no;

	ob = filter_array(ob,
		(: $2->query("per")	< $1->query("per") :), me);
	no = sizeof(ob) + 1;
	return me->name()+RANK_D->query_respect(me)+"的容貌在目前江湖人士中排名第"
		+chinese_number(no)+"。";
}

int ask_exp()
{
	object me = this_player();
    object *ob = filter_array(objects(), (: userp($1) && !wiz_level($1) :));
	int no;

	ob = filter_array(ob,
		(: $2->query("combat_exp")	< $1->query("combat_exp") :), me);
	no = sizeof(ob) + 1;

	command("say "+me->name()+RANK_D->query_respect(me)+"的经验在目前江湖人士中排名第"
		+chinese_number(no)+"。");
	message_vision(CYN "$N指着$n赞叹道：“"+me->name()+"是武林第"
		+chinese_number(no)+"高手！”\n" NOR, this_object(), me);
	return 1;
}

void create()
{
	set_name("金庸",({"jin yong","jin"}));
	set("gender","男性");
	set("age",60);
    set("per", 25);
    set("dex", 30);
	set("long", @LONG
他就是一代武学宗师，功夫深不可测，不过已经退出江湖了。
但是如果你要打听一些江湖上的事情，他会很热心地告诉你。
打听年龄用 ask jin about age
打听容貌用 ask jin about beauty
打听经验用 ask jin about exp
LONG);
	set("combat_exp", 10000000);
	set("attitude", "friendly");
	set("inquiry",([
		"age": (: ask_age :),
		"beauty": (: ask_beauty :),
		"exp": (: ask_exp :),
	]) );
	set_skill("dodge",350);
	set_skill("parry",350);
	set_skill("unarmed",350);
	setup();
	carry_object("/clone/misc/cloth")->wear();
}
