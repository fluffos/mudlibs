// boluoxing.c 波罗星
// by iceland

#include <ansi.h>
inherit NPC;

string ask_xueputi();

void create()
{
	set_name("波罗星", ({ "boluo xing", "boluoxing" ,"boluo","xing"}));
	set("long",@LONG
他长得身材矮小，满脸风霜之色，颔下留着红色的短须，打着卷卷。他是个西域胡人，
因为仰慕大轮寺的佛法和武功，所以和师兄来此修行。
LONG
	);
	set("title", HIY "大轮寺第十二代弟子" NOR);
	set("gender", "男性");
	set("age", 29);
	set("attitude", "heroism");
	set("shen_type", -1);

	set("str", 25);
	set("int", 15);
	set("con", 25);
	set("dex", 30);

	set("max_qi", 1000);
	set("eff_jing", 400);
	set("max_jing", 400);
	set("neili", 1000);
	set("max_neili", 1000);
	set("jiali", 40);
	set("combat_exp", 250000);
	set("score", 3500);

	set_skill("huanxi-chan", 80);
	set_skill("literate", 60);
	set_skill("force", 80);
	set_skill("longxiang-boruo", 80);
	set_skill("dodge", 80);
	set_skill("yuxue-dunxing", 80);
	set_skill("hand", 70);
	set_skill("dashou-yin", 70);
	set_skill("claw", 70);
	set_skill("tianwang-zhua", 70);
	set_skill("parry", 80 );
	set("unique", 1);

	map_skill("force", "longxiang-boruo");
	map_skill("dodge", "yuxue-dunxing");
	map_skill("hand", "dashou-yin");
	map_skill("parry", "tianwang-zhua");
	map_skill("claw", "tianwang-zhua");

	prepare_skill("hand","dashou-yin");
	prepare_skill("claw","tianwang-zhua");

	create_family("大轮寺", 13, "弟子");
	set("class", "huanxi");

	set("inquiry", ([
//		"血菩提" : (: ask_xueputi :),
	]));
	set("puti_count", 1 + random(4));

	setup();
	carry_object(__DIR__"obj/gongde-jiasha")->wear();
	add_money("gold",1);
}
/*
string ask_xueputi()
{
	mapping fam; 
	object ob;
        
	if (!(fam = this_player()->query("family")) || fam["family_name"] !="大轮寺")
		return RANK_D->query_respect(this_player())+ "不是本派弟子，怎么对本派灵药也垂涎三尺呀？";

	if ( (int)this_player()->query_condition("neili_drug" ) > 0 )
		return RANK_D->query_respect(this_player()) + "面红耳赤，气血充溢，是不是刚刚吃过？灵药炼制不易，多吃也是浪费，一会再来吧。";

	if (  present("xue puti", this_player()) )
		return RANK_D->query_respect(this_player())+ "现在身上不是有颗药丸吗，怎麽又来要了？真是贪得无厌！";

	if ( (int)this_player()->query("max_neili") < 200 )
		return RANK_D->query_respect(this_player())+ "功力不够，血菩提对你有害无益。";

	if (query("puti_count") < 1) 
		return RANK_D->query_respect(this_player()) + "来得不巧，现在我这里也没有了。";

	ob = new( MEDICINE_D("xueputi") );
	ob->move(this_player());
	add("puti_count", -1);

	message_vision("$N获得一颗血菩提。\n",this_player());
	return "好吧，记住，此药炼制实在不易，万万不要浪费了。";
}
*/
