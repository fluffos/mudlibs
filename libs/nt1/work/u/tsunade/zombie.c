#include <ansi.h>

inherit KNOWER;



void create()
{
	set_name("僵尸", ({ "zombie" }) );
	set("age", 99);
	set("gender", "男性");
	set("long", "这是一具被人用符咒控制的僵尸，从它苍白的脸上看不出任何喜怒哀乐。\n");
	set("attitude", "peaceful");
       set("owner", "tsunade");
       set_weight(500000000);

	set("str", 1234);
       set("int", 1000);
       set("con", 1000);
	set("dex", 1234);

        set("combat_exp", 80000000);
        set("max_neili", 9000000);
        set("neili", 900000000);
        set("max_jing", 3000000);
        set("jing", 3000000);
        set("max_qi", 5000000);
        set("qi", 5000000);
        set("jingli", 18000000);
        set("jiali", 800000);
        set("max_jingli", 18000000);


set_skill("force", 3000);
set_skill("freezing-force", 3000);
set_skill("strike", 3000);
set_skill("dodge", 1000);
set_skill("parry", 1000);
set_skill("lingbo-weibu", 1000);
set_skill("qiankun-danuoyi", 1000);
set_skill("bingcan-duzhang", 3000);
set_skill("martial-cognize", 3000);

map_skill("strike", "bingcan-duzhang");

map_skill("force", "freezing-force");
map_skill("dodge", "lingbo-weibu");
map_skill("parry", "qiankun-danuoyi");


prepare_skill("strike", "bingcan-duzhang");




	setup();
	carry_object("/clone/cloth/dao-cloth")->wear();
}



void init()
{
	add_action("do_attack", "gokill");
}



int do_attack(string arg)
{
	object obj, owner;

	if( (string)this_player()->query("id") != (string)this_object()->query("owner") )
		return notify_fail("僵尸口中呜呜两声，好像不愿理你！\n");

	if( !arg || !objectp(obj=present(arg,environment(this_player()))))
           return notify_fail("你想让僵尸去攻击谁？\n");

	if( !obj->is_character() )
                return notify_fail("看清楚一点，那并不是生物。\n");


	message_vision("$N附耳对$n说了些什么。\n", this_player(), this_object());
        message_vision("$N对$n喊道：去死吧！\n", this_object(), obj);

	command("kill "+obj->query("id"));
	return 1;
}

void die()
{
	message_vision("僵尸慢慢地倒了下去，化为一滩血水。\n", this_object());
	destruct(this_object());
}

void unconcious()
{
	message_vision("僵尸慢慢地倒了下去，化为一滩血水。\n", this_object());
        destruct(this_object());
}


void receive_damage(string type, int n)
{
        return;
}

void receive_wound(string type, int n)
{
        return;
}
