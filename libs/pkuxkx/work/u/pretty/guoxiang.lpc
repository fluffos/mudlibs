// guoxiang.c
//
// created by pretty

#include <ansi.h>

inherit NPC;

int ask_longnu();
int ask_yangguo();

void create()
{
	set_name( "郭襄", ({ "guo xiang", "guo", "xiang" }) );
	set( "nickname", HIM "小东邪" NOR );
	set( "long", @LONG
这少女十八九岁年纪，身穿淡黄衣衫，腰悬短剑。脸上颇有风尘之色，显是
远游已久；韶华如花，正当喜乐无忧之年，可是容色间却隐隐有懊闷意，似
是愁思袭人，眉间心上，无计回避。
LONG
	);
	set( "gender", "女性" );
	set( "age", 18 );

	set( "per", 40 );
	set( "int", 50 );
	set( "str", 30 );
	set( "dex", 40 );

	set( "shen_type", 1 );
	set( "shen", 200000 );
	set( "attitude", "peaceful" );

	set("combat_exp", 1000000);
	set("max_qi", 3000);
	set("max_jing", 800);
	set("neili", 2000);
	set("max_neili", 2000);
	set("jiali", 100);

	set_skill("force", 200);
	set_skill("jiuyin-shengong", 180);
	set_skill("dodge", 200);
	set_skill("luoying-shenfa", 200);
	set_skill("hand", 180);
	set_skill("fuxue-shou", 200);
	set_skill("sword",180);
	set_skill("yuxiao-jian",200);
	set_skill("parry", 200);
	set_skill("mahayana", 150);
	set_skill("literate", 100);
	map_skill("force", "jiuyin-shengong");
	map_skill("dodge", "luoying-shenfa");
	map_skill("parry", "yuxiao-jian");
	map_skill("sword", "yuxiao-jian");
	map_skill("hand", "fuxue-shou");
	prepare_skill("hand", "fuxue-shou");

	set( "chat_chance_combat", 10 );
	set( "chat_msg_combat", ({
		MAG "\n郭襄眉头微蹙，似乎很不高兴的样子。\n" NOR,
		MAG "\n郭襄轻轻叹道：若是我大哥哥在此，哪容你如此欺我。\n" NOR,
	}) );

	set( "inquiry", ([
		"小龙女" : (: ask_longnu :),
		"杨过"   : (: ask_yangguo :),
	]) );

	setup();

	carry_object(__DIR__"obj/yel_cloth")->wear();
	carry_object(__DIR__"obj/short_sword")->wield();
}

void init()
{
	object me, ob;

	::init();
	me = this_object();
	ob = this_player();
	if ( userp(ob) && !(me->is_fighting()) )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, me);
	}
}

void greeting(object me)
{
	if ( random(100) % 2 )
		message_vision("$N低声吟道：“欢乐趣，离别苦，就中更有痴儿女。君应有语，渺万里层\n"
			"云，千山暮雪，只影向谁去？”\n", me);
	else
		message_vision("$N轻轻地叹了口气，似乎胸中有无数心事。\n", me);
}

int ask_longnu()
{
	message_vision("$N叹道：“也只有龙姊姊这样的人物，才配得上他。”\n", this_object());
	return 1;
}

int ask_yangguo()
{
	message_vision("$N脸上突然现出一抹晕红，说道：“他…他是我的大哥哥呀！\n”", this_object());
	return 1;
}

void die()
{
	object me, killer;

	me = this_object();
	message_vision("$N轻叹一声：“大哥哥一定会为我报仇的！”\n\n"
		"话毕，化做一缕清风而去。\n", me);
	destruct(me);
}
