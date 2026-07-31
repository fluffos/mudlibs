#include <ansi.h>;
inherit NPC;

int dajiu();
string *heros = ({
	"一层人质",
	"二层人质",
	"三层人质",
	"四层人质",
	"五层人质",
	"六层人质",
	"七层人质",
	"八层人质",
	"九层人质",
	"十层人质",
	"十一层人质",
	"十二层人质",
	"十三层人质",
});

void create()
{
	set_name("被救人", ({"helper man"}));
	set("gender", "男性");
	set("age", 45);
	set("long","他是被困在万安寺中的六大门派中人。\n");
	set("attitude", "peaceful");
 	set("no_death", 1);

	set("str", 38);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 250000);
	set("eff_qi", 250000);
	set("qi", 250000);

	set("neili", 19999);
	set("max_neili", 19999);
	
	set("combat_exp", 600000);

	set_temp("apply/damage", 666);
	set_temp("apply/armor", 300);
	set_temp("apply/speed", 300);

	set("chat_chance", 2);
	set("chat_msg", ({
		 "你听到身边有人叫道：“这位英雄赶紧来救救我啊……”\n",
	}));

	set("inquiry", ([
		"搭救" : (: dajiu :),
	]));

	setup();
}

void init()
{
	set("name", heros[environment()->query("sllv")-1]);
}

int dajiu()
{
	if(present("sl dizi",environment()))
	{
		say("贼兵大叫到：怎么？不把我放在眼里？\n");
		return 1;
	}
	say("太好了，终于有人闯上来了，六大门派有希望了！\n");
	if(environment()->query("sllv")>=13)
	{
		say("你将所有的人质都救了出来。。。\n");
	}
	else
	{
		say("你将"+query("name")+"送出万安寺继续向下一层闯去。。。\n");
		environment()->nextlv(3);
	}
	destruct(this_object());
	return 1;
}
