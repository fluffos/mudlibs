// Rewrote by iszt@pkuxkx, 2007-02-11

#include <ansi.h>

inherit NPC;

string ask_jia();

void create()
{
	set_name(GRN"翠姑"NOR, ({"cui gu", "cuigu", "gu",}));
	set("long", "这是一个十八九岁的少妇，虽是惊吓过度，衣衫不整，却也颇有几分姿色。\n");
	set("gender", "女性");
	set("attitude", "friendly");
	set("age", 18);
	set("shen_type",1);
	set("str", 13);
	set("int", 30);
	set("con", 17);
	set("dex", 20);
	set("max_qi", 300);
	set("max_jing", 100);
	set("combat_exp", 6400);
	set_skill("dodge", 20);
	set_skill("parry", 20); 
	set_skill("cuff", 40);
	set("inquiry",([
		"回家" : (: ask_jia :),
		"王二愣" : (: ask_jia :),
		"丈夫" : "小女的丈夫就是王二愣。",
                "救人" : "救我回家！",
		"岳飞" : "多亏了岳飞赶来，否则小女早就被土匪蹂躏了……",
	]));
	set("dan_count", 1);

	setup();
}

string ask_jia()
{
	object me, ob;
	me = this_player();
	if(is_fighting())
		return "救命！";
	if(query("dan_count")<1 || me->query_temp("liquan/find_cuigu"))
		return "多谢"+RANK_D->query_respect(me)+"救命之恩。";
	else
	{
		add("dan_count",-1);
		ob = new(__DIR__"obj/dan");
		ob->move(me);
		message_vision("翠姑给了$N一个黑乎乎的不知什么物事。\n", me);
		me->set_temp("liquan/find_cuigu", 1);
		return "多谢"+RANK_D->query_respect(me)+"救命之恩，这是小女子家传的宝物，据说武功高强的人吃了会有好处，聊表寸心。";
	}
}
