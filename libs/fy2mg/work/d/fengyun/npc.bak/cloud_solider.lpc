
#include <ansi.h>

inherit NPC;

void create()
{
        set_name("云卒", ({ "fengyun garrison", "garrison" }) );
        set("long",
"这是个正在执行守城任务的云卒，虽然和许多武林人物比起来，云卒们的武功\n"
"实在平常，但他们是有组织、有纪律的战士，谁也不轻易地招惹他们。\n"
"[31m你最好也不要招惹他们。 [37m\n");
        set("attitude", "heroism");
        set("vendetta_mark", "authority");
        set("str", 27);
        set("cor", 26);
        set("cps", 25);
        set("combat_exp", 100000+random(1000000));
        set("chat_chance_combat", 15);
        set("chat_msg_combat", ({
                "云卒喝道：还不快放下武器束手就缚？\n",
                "云卒喝道：大胆刁民竟敢拒捕？反了！反了！\n"
        }) );
        set_skill("unarmed", 70+random(100));
        set_skill("dagger", 70+random(100));
        set_skill("parry", 70+random(100));
        set_skill("dodge", 70+random(100));
        set_skill("move", 100+random(100));

        set_temp("apply/attack", 70);
        set_temp("apply/defense", 70);
        set_temp("apply/armor", 70);
        set_temp("apply/damage", 30+random(200));
        set_temp("apply/move", 100);

        setup();

        carry_object(__DIR__"obj/kiujia")->wear();
        carry_object(__DIR__"obj/longdagger")->wield();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
	switch( random(10)){
				case 0:
say("云卒上上下下地打量你一番，又和墙上帖的官府通谍对了对，低声嘀咕道：好象就是了．\n");
					break;
				case 1:
say("云卒看了你一眼，低声嘀咕道：唉，又是一个江湖人物．\n");
					break;
				case 2:
say("云卒向你喝道：站住！把脸给我抬起来！\n");
					break;
				}
}

