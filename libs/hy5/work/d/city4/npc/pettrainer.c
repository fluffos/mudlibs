#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIB"水鹰"NOR, ({ "hawk" }) );
        set("gender", "女性" );
	 set("title",HIB"大漠飞鹰"NOR);
        set("no_get",1);
        set("age", 20);
        set("long","她是火鹰的妹妹，从小和动物为伴，所以擅长驯兽（trainpet）。\n");
        set("combat_exp", 5000000);
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
                        say( "水鹰说道：这位" + RANK_D->query_respect(ob)
                                + "，我帮你驯兽，你告诉我哪有好玩的地方？\n");
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
	if(!arg) return notify_fail("水鹰道：＂你要驯什么呀？＂\n");
	pet = present(arg,environment());
	if(!objectp(pet)) return notify_fail("水鹰道：＂你要驯什么呀？＂\n");
	if(pet->query("possessed") != me )
	return notify_fail("水鹰道：＂那好象不是你的吧？＂\n");
//okey we identified the target, now the cost:
	cost = (int) pet->query("obedience");
	cost *= cost;
	gold = present("gold_money", me);
        if(!gold) return notify_fail("你身上没有金子。\n");
        if((int) gold->query_amount() < cost/2)
        return notify_fail("你身上没有"+chinese_number(cost/2)+"两金子。\n");
	if((int)me->query("score") < cost/10)
	return notify_fail("你的江湖阅历不够"+chinese_number(cost/10)+"点。\n");
	pet->add("obedience",1);
	pet->save();
	gold->add_amount(-cost/2);
	me->add("score",-cost/10);
	command("say 好了！\n");
	return 1;
}
void unconcious()
{
    die();
}
