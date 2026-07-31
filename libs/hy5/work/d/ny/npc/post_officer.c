
// post_officer.c

inherit NPC;



void create()
{
	set_name("杜宽", ({ "post officer", "officer" }) );
    set("title", "宁远驿长");
	set("gender", "男性" );
	set("age", 43);
	set("long",
		"杜宽担任宁远驿的驿长已经有十几年了  虽然期间有几次升迁的\n"
        "机会但是他都因为舍不得离开这个小城镇而放弃了去京城任职，宁远城的\n"
		"居民对杜宽的风评相当不错  常常会来到驿站跟他聊天。\n");
	set("combat_exp", 800);
	set("attitude", "friendly");
	set("inquiry", ([
        "驿站" : "是啊... 这里就是宁远驿站你要寄信吗  ",
	]) );
	set_skill("literate", 70);
	set_skill("dodge", 50);
	set_skill("unarmed", 40);
	setup();
	add_money("coin", 70);
}

