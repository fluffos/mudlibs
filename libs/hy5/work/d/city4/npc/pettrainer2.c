#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIC"木鹰"NOR, ({ "hawk" }) );
        set("no_get",1);
        set("gender", "男性" );
	set("title",HIC"大漠飞鹰"NOR);
        set("age", 32);
        set("long","他对改善动物的体质别有妙技(trainpet)。\n");
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
               
                case 1:
                        say( "木鹰笑道：这不，有生意来了！\n");
                        break;
        }
}

int do_train(string arg)
{
	object me,pet,gold;
	int cost;
	string which;
        me = this_player();
        if(me->is_busy())
        return notify_fail("你上一个动作还没有完成。\n");
	if(!arg) return notify_fail("木鹰道：＂你要什么呀？＂\n");
	pet = present(arg,environment());
	if(!objectp(pet)) return notify_fail("木鹰道：＂你要什么呀？＂\n");
	if(pet->query("possessed") != me )
	return notify_fail("木鹰道：＂那好象不是你的吧？＂\n");
	switch (random(2)){
	case 0: which = "max_jing"; break;
	case 1: which = "max_qi"; break;
				}	
//okey we identified the target, now the cost:
	cost = (int) pet->query(which) / 10;
	cost *= cost;
	gold = present("gold_money", me);
        if(!gold) return notify_fail("你身上没有金子。\n");
        if((int) gold->query_amount() < cost/2)
        return notify_fail("你身上没有"+chinese_number(cost)+"两金子。\n");
	if((int)me->query("score") < cost/8)
	return notify_fail("你的江湖阅历不够"+chinese_number(cost/8)+"点。\n");
	pet->add(which,10);
	pet->save();
	gold->add_amount(-cost/2);
	me->add("score",-cost/8);
	command("say 这就得了！\n");
	return 1;
}
void unconcious()
{
    die();
}
