// TIE@FY3
#include <ansi.h>
#include <login.h>
#define MAX_EXP 5000
inherit NPC;
string *death_msg = ({
	HIW "判官那锐利的目光象把刀一样在你身上扫来扫去。\n\n" NOR,
	HIW "判官翻了翻勾魂簿，叹道：又一个夭折的短命鬼。\n\n" NOR,
	HIW "判官合上簿子说道：阳寿未尽？罢了罢了，你走吧。\n\n" NOR,
	HIW "一股阴冷的浓雾突然出现，很快地包围了你。\n\n" NOR,
});
string *revive_loc= ({
        "/d/city/wumiao",
        "/d/city/wumiao",
});

void create()
{
	set_name("朱笔判官", ({ "panguan", "ghost judge" }) );
	set("long",
		"阎王身边的朱笔判官，专勾画天下人的生死。\n");
	set("attitude", "peaceful");
	set("chat_chance", 5);
	set("chat_msg", ({
		(: random_move :),
		"判官喝道：牛头，马面何在？\n"
	}) );
	set("age", 217);
	set("combat_exp", 20000);
	set("str",100);
	set("max_qi", 900);
	set("max_jing", 900);
	set("neili", 3000);
	set("max_neili", 3000);
	set("combat_exp", 1999999);
	set("score", 90000);
           set_skill("dodge", 40);
	set_skill("unarmed", 40);
	setup();
}

void init()
{
	::init();
	if( !previous_object()
	||	!userp(previous_object())
	||	wizardp(previous_object()) ) return;
	call_out( "death_stage", 3, previous_object(), 0 );
}

void death_stage(object ob, int stage)
{
	if( !ob || !present(ob) || (int)ob->query("combat_exp") > MAX_EXP) return;

	tell_object(ob, death_msg[stage]);
	if( ++stage < sizeof(death_msg) ) {
		call_out( "death_stage", 3, ob, stage );
		return;
	} else
		if(ob->is_ghost())
		ob->reincarnate();

	ob->move(revive_loc[random(sizeof(revive_loc))]);
	ob->set("startroom", base_name(environment(ob)));
	message("vision",
		"你忽然发现前面多了一个人影，不过那人影又好像已经在那里\n"
		"很久了，只是你一直没发觉。\n", environment(ob), ob);
}


