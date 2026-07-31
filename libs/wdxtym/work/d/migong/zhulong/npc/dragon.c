// This program is a part of NT MudLIB

#include <ansi.h>

inherit NPC;
int ask_job();
int ask_job1();
int ask_job2();
void create()
{
        set_name(HIW "龙族守陵人" NOR, ({ "dragon guardian"}) );
        set("long", HIY "这是一位身着麻衣白发苍苍的老人。你看不清他的面目。\n" NOR);
	set("gender", "男性");
	set("age", 2000);
	set("nokill", 1);
	set("no_kill", 1);
	set("shen_type", 1);
	set("str", 80);
	set("int", 80);
	set("con", 80);
	set("dex", 80);
	set("vendetta/authority",1);
	set("qi", 1000000);
	set("max_qi", 1000000);
	set("jing", 50000000);
	set("max_jing", 50000000);
	set("neili", 50000000);
	set("max_neili", 50000000);
	set("jiali", 300);
	set("combat_exp", 100000000);
	set("score", 600000);
	set("shen", 200000);
	set("inquiry", ([
        	"祖龙的遗物" : (: ask_job :),
			"线索" : (: ask_job1 :),
			"交付" : (: ask_job2 :),
            ]));
	setup();
}

int ask_job()
{
	object me;
	int i,size;
	me = this_player();

	tell_object(me, HIW"祖龙的遗物？那是我族始祖遗留的宝物，凝聚了我龙族五大祖龙的最强力量，可惜已经在上古之战时被打碎了，碎片就埋藏在我身后山丘深处的龙穴里，你若有机缘寻到，老夫必有重谢，进去一探究竟吧，年轻人。\n"NOR);

	return 1;
}
int ask_job1()
{
	object me;
	int i,size;
	me = this_player();

	tell_object(me, HIW"眠龙洞的最深处，沉睡的千年火龙，五彩的祖龙之鳞。我只能告诉你这么多了。\n"NOR);

	return 1;
}
int ask_job2()
{
	object me;
	int i,size;
	me = this_player();
	//tell_object(me, HIW"龙陵守卫：没想到你将我龙族遗物寻回来了，把五彩祖龙鳞和千年火龙甲、千年火龙丹交给我吧，让我重新赋予它们光彩！。\n"NOR);
	//龙陵守卫轻抚手中的五彩祖龙鳞和千年火龙甲，默念级几句你听不懂的咒语，将千年火龙丹一口吞下，龙陵守卫口中喷出一团火焰燃烧在手中的五彩祖龙鳞和千年火龙甲之上，一阵刺眼的光华闪耀过后......你缓缓睁开眼睛。
	//龙陵守卫将 祖龙印 交给你 龙陵守卫：我相信你，年轻人，只有你才能振兴我们龙族，我老了。去吧！带着祖龙印，这天地间谁还能阻挡你的脚步！

	tell_object(me, HIW"暂未开放。\n"NOR);

	return 1;
}
void unconcious()
{
	reincarnate();
	set("eff_qi", query("max_qi"));
	set("qi", query("max_qi"));
	set("eff_jing", query("max_jing"));
	set("jing", query("max_jing"));
	set("jingli", query("eff_jingli"));
        this_object()->clear_condition();
}

void die()
{
	unconcious();
}