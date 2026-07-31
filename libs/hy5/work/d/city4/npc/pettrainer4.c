#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIY"金鹰"NOR, ({ "hawk" }) );
        set("no_get",1);
        set("gender", "男性" );
	 set("title",HIY"大漠飞鹰"NOR);
        set("age", 22);
        set("long","一个身形高大的汉子,熟悉如何提高(trainpet)野兽的能力。\n");
        set("combat_exp", 500000);
        set("attitude", "friendly");
        set("chat_chance", 5);
        set("chat_msg", ({
                (: random_move :)
        }) );
        setup();
        carry_object("/clone/cloth/cloth")->wear();

}

void init()
{	
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_train", "trainpet");

}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(5) ) {
                case 0:
                        say( "金鹰说道：这位" + RANK_D->query_respect(ob)
                                + "，我可以帮你训练野兽（trainpet），你付金子？\n");
                        break;
                case 1:
                        say( "金鹰笑道：这位" + RANK_D->query_respect(ob)
                                + "，放心！打不伤的！\n");

                        break;
        }
}

int do_train(string arg)
{
	object me,pet,gold;
	int cost;
        me = this_player();
        if(me->is_busy())
        return notify_fail("你上一个动作还没有完成。\n");
	if(!arg) return notify_fail("金鹰道：＂你要什么呀？＂\n");
	pet = present(arg,environment());
	if(!objectp(pet)) return notify_fail("金鹰道：＂你要什么呀？＂\n");
	if(pet->query("possessed") != me )
	return notify_fail("金鹰道：＂那好象不是你的吧？＂\n");
//okey we identified the target, now the cost:
	cost = to_int(sqrt(to_float((int)pet->query("combat_exp"))))/5;
	gold = present("gold_money", me);
        if(!gold) return notify_fail("你身上没有金子。\n");
        if((int) gold->query_amount() < cost/3)
        return notify_fail("你身上没有"+chinese_number(cost)+"两金子。\n");
	if((int)me->query("score") < cost/8)
	return notify_fail("你的江湖阅历不够"+chinese_number(cost/8)+"点。\n");
	pet->add("combat_exp",cost*50);
	pet->save();
	gold->add_amount(-cost/3);
	me->add("score",-cost/8);
	command("say 好了！下次再打！\n");
	return 1;
}
void unconcious()
{
    die();
}
