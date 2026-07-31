// huawuque.c
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("花无缺", ({ "hua wuque","hua","wuque"}) );
set("long",
	    "这是个移花宫中唯一的一个男人,\n"+
	    "其实原是移花宫门人的后人，被宫主保来抚养，他竟然\n在这里，他玉树临风，风度翩翩.\n"+
	    "不仔细看还以为是女子.\n");
	set("gender", "男性" );
	set("age", 18);
	set("combat_exp", 8000000);
	set("shen_type",1000);
	set("str", 180);
	set("dex", 180);
	set("con", 180);
	set("int", 180);

            set("qi", 30000);
	set("max_qi", 30000);
	set("jing", 50000);
    set("max_jing", 5000);
    set("neili", 1000000);
    set("max_neili", 20000);
	set("jiali", 500);

	set_skill("force", 370);
	set_skill("dodge", 480);
	set_skill("parry", 370);
	set_skill("sword",400);
	set_skill("unarmed",400);

	set_skill("jueqing-zhang",380);
	set_skill("mingyu-shengong",380);
	set_skill("yihua-jiemu",480);
	set_skill("yifeng-jian",480);
         set_skill("yifeng-dodge",480);

	map_skill("unarmed", "jueqing-zhang");
         map_skill("dodge","yifeng-dodge");
	map_skill("parry", "yihua-jiemu");
	map_skill("sword", "yifeng-jian");

	prepare_skill("sword","yifeng-jian");
	create_family("移花宫",2,"传人");
        set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: perform_action, "sword.yifeng" :),
			}) );
	setup();
    carry_object("/d/yihua/obj/jinlvyi")->wear();
        carry_object("/clone/weapon/changjian")->wield();
	add_money("gold",15);
        set("attitude", "friendly");
	set("chat_chance",20);
	set("chat_msg",({
        "花无缺叹口气说道：我不想杀小鱼儿，有不想违背大姑姑的意思，不知道怎么办！哎\n",
        "花无缺看着你说道：虽然大姑姑不是我的亲娘，可是我一直很尊敬她！\n",
        "花无缺望着天空自言自语道：铁心兰呀!你现在在什么地方呀！\n",
	   }) );
       set("inquiry",([

       "娘" : "我的亲娘是月奴，不过我也把宫主当做我的亲娘\n",
	   "小鱼儿" : "他是我的兄弟，你是怎么知道他的？！\n",
	   ]) );
       setup();
}

void init()
{
	object ob;

	ob = this_player();

	::init();
	if( interactive(ob) && !is_fighting() )
	       {
			remove_call_out("greeting");
			call_out("greeting", 1, ob);
		}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	say("花无缺一见有人进来急忙说：" + RANK_D->query_respect(ob)
	  +"，你是什么人怎么跑到这里来了速速离开!\n");
}
