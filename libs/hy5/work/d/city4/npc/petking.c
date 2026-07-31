#include <ansi.h>
inherit NPC;
void create()
{
        set_name(YEL"鹰王"NOR, ({ "hawkking" }) );
        set("gender", "男性" );
        set("no_get",1);
	 set("title",HIY"百鹰之王"NOR);
        set("age", 62);
        set("long","一个身形高大的高者,熟悉让野兽(uppet)变身成长的能力。\n");
        set("combat_exp", 1500000);
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
        add_action("do_train", "uppet");
        add_action("do_train2", "upbest");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(5) ) {
                case 0:
                        say( "鹰王说道：这位" + RANK_D->query_respect(ob)
                                + "，我可以帮你升级野兽（up），你付金子？\n");
                        break;
                case 1:
                        say( "鹰王笑道：这位" + RANK_D->query_respect(ob)
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
	if(!arg) return notify_fail("鹰王道：＂你要什么呀？＂\n");
	pet = present(arg,environment());
	if(!objectp(pet)) return notify_fail("鹰王道：＂你要什么呀？＂\n");
	if(pet->query("possessed") != me )
	return notify_fail("鹰王道：＂那好象不是你的吧？＂\n");

//okey we identified the target, now the cost:
	cost = to_int(sqrt(to_float((int)pet->query("combat_exp"))))/3;
	gold = present("gold_money", me);
        if(!gold) return notify_fail("你身上没有金子。\n");
        if((int) gold->query_amount() < cost/2)
        return notify_fail("你身上没有"+chinese_number(cost)+"两金子。\n");
	if((int)me->query("score") < cost/4)
	return notify_fail("你的江湖阅历不够"+chinese_number(cost/4)+"点。\n");

//to_int(sqrt(to_float((int)pet->query("combat_exp"))))/5;
	pet = present(arg,environment());
        if( pet->query("up1") >= 1 )
                return notify_fail("你的宏物已经升过级了.\n");

	pet = present(arg,environment());
//	if(pet->query_skill("puyaogedou") < 150)
//	return notify_fail("你的的宏物的扑咬格斗等级不够。\n");
	if(pet->query("combat_exp") < 200000)
	return notify_fail("你的的宏物的经验等级不够。\n");

        if (random(6) == 0)
        {
	pet = present(arg,environment());
	pet->add("combat_exp",cost*50);
        pet->set("up1",1);
        pet->set("pfm6",1);	
        pet->add("con",5);	
        pet->add("max_jing",200);	
        pet->add("max_qi",200);	
        pet->add("max_neili",200);	
        pet->add("neili",200);	

	pet->set("title",HIY"毒龙"NOR);
	}
       else
        if (random(6) == 1)
        {
	pet = present(arg,environment());
	pet->add("combat_exp",cost*50);
        pet->set("up1",1);
        pet->set("pfm1",1);	
        pet->add("con",5);	
        pet->add("max_jing",200);	
        pet->add("max_qi",200);	
        pet->add("max_neili",200);	
        pet->add("neili",200);	

	pet->set("title",HIY"大脚龙"NOR);
	}
       else
        if (random(6) == 2)
        {
	pet = present(arg,environment());
	pet->add("combat_exp",cost*50);
        pet->set("up1",1);
        pet->set("pfm2",1);	
        pet->add("str",5);	
        pet->add("max_jing",200);	
        pet->add("max_qi",200);	
        pet->add("max_neili",200);	
        pet->add("neili",200);	

	pet->set("title",RED"暴暴龙"NOR);
	}
       else
        if (random(6) == 3)
        {
	pet = present(arg,environment());
	pet->add("combat_exp",cost*50);
        pet->set("up1",1);
        pet->set("pfm3",1);	
        pet->add("dex",5);	
        pet->add("max_jing",200);	
        pet->add("max_qi",200);	
        pet->add("max_neili",200);	
        pet->add("neili",200);	

	pet->set("title",HIC"剑齿龙"NOR);
	}
       else
        if (random(6) == 4)
        {
	pet = present(arg,environment());
	pet->add("combat_exp",cost*50);
        pet->set("up1",1);
        pet->set("pfm4",1);	
        pet->add("str",5);	
        pet->add("max_jing",200);	
        pet->add("max_qi",200);	
        pet->add("max_neili",200);	
        pet->add("neili",200);	

	pet->set("title",HIB"狂龙"NOR);
	}
       else
        if (random(6) == 5)
        {
	pet = present(arg,environment());
	pet->add("combat_exp",cost*50);
        pet->set("up1",1);
        pet->set("pfm5",1);	
        pet->add("int",5);	
        pet->add("max_jing",200);	
        pet->add("max_qi",200);	
        pet->add("max_neili",200);	
        pet->add("neili",200);	

	pet->set("title",HIW"土龙"NOR);
	}
       else
{
	pet = present(arg,environment());
	pet->add("combat_exp",cost*50);
        pet->set("up1",1);
        pet->set("pfm1",1);	
        pet->add("con",5);	
        pet->add("max_jing",200);	
        pet->add("max_qi",200);	
        pet->add("max_neili",200);	
        pet->add("neili",200);	

	pet->set("title",HIY"大脚龙"NOR);
}
	pet = present(arg,environment());
	pet->set("ridable",1);
	pet->save();
	gold->add_amount(-cost/2);
	me->add("score",-cost/4);
	command("say 好了！你的宏物已经成长为第二级宏物了\n");
	return 1;
}

int do_train2(string arg)
{
	object me,pet,gold;
	int cost;
        me = this_player();
        if(me->is_busy())
        return notify_fail("你上一个动作还没有完成。\n");
	if(!arg) return notify_fail("鹰王道：＂你要什么呀？＂\n");
	pet = present(arg,environment());
	if(!objectp(pet)) return notify_fail("鹰王道：＂你要什么呀？＂\n");
	if(pet->query("possessed") != me )
	return notify_fail("鹰王道：＂那好象不是你的吧？＂\n");

//okey we identified the target, now the cost:
	cost = to_int(sqrt(to_float((int)pet->query("combat_exp"))))/3;
	gold = present("gold_money", me);
        if(!gold) return notify_fail("你身上没有金子。\n");
        if((int) gold->query_amount() < cost/2)
        return notify_fail("你身上没有"+chinese_number(cost)+"两金子。\n");
	if((int)me->query("score") < cost/4)
	return notify_fail("你的江湖阅历不够"+chinese_number(cost)+"点。\n");

//to_int(sqrt(to_float((int)pet->query("combat_exp"))))/5;
	pet = present(arg,environment());
        if( pet->query("up1") < 1 )
                return notify_fail("你的宏物还没有到第二级.\n");

        if( pet->query("up1") >= 2 )
                return notify_fail("你的宏物已经升过级了.\n");

	pet = present(arg,environment());
//	if((int)pet->query_skill("puyaogedou") < 200)
//	return notify_fail("你的的宏物的扑咬格斗等级不够。\n");
	if((int)pet->query("combat_exp") < 500000)
	return notify_fail("你的的宏物的经验等级不够。\n");

        if (pet->query("title")==HIY"毒龙"NOR)
        {
	pet = present(arg,environment());
	pet->add("combat_exp",cost*50);
        pet->set("up1",2);
        pet->set("canmove",1);	
        pet->add("con",5);	
        pet->add("max_jing",400);	
        pet->add("max_qi",400);	
        pet->add("max_neili",200);	
        pet->add("neili",200);	

	pet->set("title",HIY"毒龙王"NOR);
	}
       else
        if (pet->query("title")==HIY"大脚龙"NOR)
        {
	pet = present(arg,environment());
	pet->add("combat_exp",cost*50);
        pet->set("up1",2);
        pet->set("canmove",1);	
        pet->add("con",5);	
        pet->add("max_jing",400);	
        pet->add("max_qi",400);	
        pet->add("max_neili",200);	
        pet->add("neili",200);	

	pet->set("title",HIY"大脚龙王"NOR);
	}
       else
        if (pet->query("title")==RED"暴暴龙"NOR)
        {
	pet = present(arg,environment());
	pet->add("combat_exp",cost*50);
        pet->set("up1",2);
        pet->set("canmove",1);	
        pet->add("str",5);	
        pet->add("max_jing",400);	
        pet->add("max_qi",400);	
        pet->add("max_neili",200);	
        pet->add("neili",200);	

	pet->set("title",RED"暴暴龙王"NOR);
	}
       else
        if (pet->query("title")==HIC"剑齿龙"NOR)
        {
	pet = present(arg,environment());
	pet->add("combat_exp",cost*50);
        pet->set("up1",2);
        pet->set("canmove",1);	
        pet->add("dex",5);	
        pet->add("max_jing",400);	
        pet->add("max_qi",400);	
        pet->add("max_neili",200);	
        pet->add("neili",200);	

	pet->set("title",HIC"剑齿龙王"NOR);
	}
       else
        if (pet->query("title")==HIB"狂龙"NOR)
        {
	pet = present(arg,environment());
	pet->add("combat_exp",cost*50);
        pet->set("up1",2);
        pet->set("canmove",1);	
        pet->add("str",5);	
        pet->add("max_jing",400);	
        pet->add("max_qi",400);	
        pet->add("max_neili",200);	
        pet->add("neili",200);	

	pet->set("title",HIB"狂龙王"NOR);
	}
       else
        if (pet->query("title")==HIW"土龙"NOR)
        {
	pet = present(arg,environment());
	pet->add("combat_exp",cost*50);
        pet->set("up1",2);
        pet->set("canmove",1);	
        pet->add("int",5);	
        pet->add("max_jing",400);	
        pet->add("max_qi",400);	
        pet->add("max_neili",200);	
        pet->add("neili",200);	

	pet->set("title",HIW"土龙王"NOR);
	}
       else
{
	pet = present(arg,environment());
	pet->add("combat_exp",cost*50);
        pet->set("up1",2);
        pet->set("canmove",1);	
        pet->add("con",5);	
        pet->add("max_jing",400);	
        pet->add("max_qi",400);	
        pet->add("max_neili",200);	
        pet->add("neili",200);	

	pet->set("title",HIY"大脚龙王"NOR);
}
	pet = present(arg,environment());
	pet->set("ridable",1);
	pet->save();
	gold->add_amount(-cost/2);
	me->add("score",-cost/4);
	command("say 好了！你的宏物已经成长为终级宏物了\n");
	return 1;
}
void unconcious()
{
    die();
}
