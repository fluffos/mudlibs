// wujiang.c 武将
#include <ansi.h>
#include "/d/beijing/beijing_defs.h"
inherit NPC;
string ask_enter();
void create()
{
        set_name("城门守卫", ({ "chengmen shouwei", "shouwei", "wei" }));
        set("gender", "男性");
        set("age", 20 + random(20));
        set("str", 25+random(30));
        set("dex", 20+random(20));
        set("long", "北京城的一个老卒，从战场上刚退下来，准备好好享几年福。\n如果要进城看来要先征求他的同意。\n");
        set("combat_exp", 1000000 + random(5000000));
//        set("shen_type", 1);
        set("attitude", "friendly");
	set("max_qi", 3000);
	set("eff_qi", 3000);
	set("qi", 3000);

	set("max_jing", 2000);
	set("eff_jing", 2000);
	set("jing", 2000);

	set("jingli", 2000);
	set("max_jingli", 2000);

	set("neili", 4000);
	set("max_neili", 4000);

	set_temp("sum_power", 1);//用于雷霆斧的绝招

	set("jiali", 50);
	set_skill("force", 160 + random(300));
	set_skill("dodge", 160 + random(300));
	set_skill("cuff", 160 + random(300));
	set_skill("strike",160 + random(300));
	set_skill("hand",160 + random(300));
	set_skill("parry", 160 + random(300));
	set_skill("blade",160 + random(300));
	set_skill("sword",160 + random(300));
	set_skill("staff",160 + random(300));
	set_skill("whip",160 + random(300));
	set_skill("axe",160 + random(300));
	set_skill("halberd",160 + random(300));
	set_skill("spear",160 + random(300));
	set_skill("claw",160 + random(300));

    	set_skill("bixue-xinfa", 160 + random(300));
    	set_skill("longfeng-xiang", 160 + random(300));
    	set_skill("qingmang-jian", 160 + random(300));
    	set_skill("juemen-gun", 160 + random(300));
    	set_skill("fenglei-dao", 160 + random(300));
    	set_skill("taizu-quan", 160 + random(300));
    	set_skill("kuangfeng-dao", 160 + random(300));
    	set_skill("kuangfeng-jian", 160 + random(300));
    	set_skill("lujia-ji", 160 + random(300));
    	set_skill("bainiao-qiangfa", 160 + random(300));
    	set_skill("huzhua-shou", 160 + random(300));
    	set_skill("juehu-zhang", 160 + random(300));
    	set_skill("kuihua-zhua", 160 + random(300));
    	set_skill("duanyun-bian", 160 + random(300));
    	set_skill("leiting-axe", 160 + random(300));

    	map_skill("force", "bixue-xinfa");
    	map_skill("sword", "qingmang-jian");
    	map_skill("blade", "fenglei-dao");
    	map_skill("dodge", "longfeng-xiang");
    	map_skill("strike", "juehu-zhang");
    	map_skill("parry", "huzhua-shou");
    	map_skill("hand", "huzhua-shou");
    	map_skill("whip", "duanyun-bian");
    	map_skill("halberd", "lujia-ji");
    	map_skill("axe", "leiting-axe");
    	map_skill("claw", "kuihua-zhua");
    	map_skill("staff", "juemen-gun");
    	map_skill("spear", "bainiao-qiangfa");
    	map_skill("cuff", "taizu-quan");

    	prepare_skill("strike", "juehu-zhang");
    	prepare_skill("hand", "huzhua-shou");

        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/armor", 280);
        set_temp("apply/damage", 80+random(100));

    	set("inquiry", ([
			"出城" : (: ask_enter :),
    	]));

        setup();

        carry_object("/d/city/obj/tiejia")->wear();
        switch (random(8))
        {
        	case 0:
        	carry_object("/d/city/obj/gangjian")->wield();
        	break;
        	case 1:
        	carry_object(__DIR__"obj/axe")->wield();
        	break;
        	case 2:
        	carry_object("/clone/weapon/fangtianji")->wield();
        	break;
        	case 3:
        	carry_object("/clone/weapon/changqiang")->wield();
        	break;
        	case 4:
        	carry_object("/clone/weapon/gangdao")->wield();
        	break;
        	case 5:
        	carry_object("/clone/weapon/changbian")->wield();
        	break;
        	case 6:
        	carry_object("/clone/weapon/gangzhang")->wield();
        	break;
        	case 7:
        	carry_object("/clone/story/obj/yitianjian")->wield();
        	break;
        }
}

void init()
{
/*
        object player = this_player();
        ::init();
    if (interactive(player) &&
        (player->query_condition("bjkiller") ))
    {
	remove_call_out("kill_ob");
	call_out("kill_ob", 1, player);
 	return;
    }

*/
}
int accept_fight(object player)
{
	object me=this_object();
        if(living(me))
        {
        command("say 大爷我正想找人杀呐，今天算你倒霉。\n");
        player->apply_condition("bjkiller", 100 + player->apply_condition("bjkiller"));
        me->kill_ob(player);
	}
        return 1;
}

int accept_kill(object player)
{
	object me=this_object();
        if(living(me))
        {
        command("say 大爷我正想找人杀呐，今天算你倒霉。\n");
        player->apply_condition("bjkiller", 100 + player->apply_condition("bjkiller"));
        me->kill_ob(player);
	}
        return 1;
}
string ask_enter()
{
	object room, *inv, ob, me = this_player();
	int i;
	ob = this_object();
	room = environment(ob);
	if(!room || base_name(room) != "/d/beijing/caishikou")
	{
		return "大胆刁民，竟敢欺骗本大爷！\n";
	}
	if (!room->query("night"))
	return "门不是开着吗？\n";
        if(me->query("repute") < 10000)
		return "你在江湖上不过是个无名小卒，靠边站去吧。\n";
	if(!me->query("in_dart"))
		return "没有正当理由夜间不得出城。\n";
    if( me->is_busy() )
        return "你现在正忙着哩。\n";
    if ( me->is_fighting())
        return "你还是先把对手解决了再说吧！\n";
    inv = all_inventory(environment(me));

    for(i=0; i<sizeof(inv); i++) {
        if ( (inv[i]->query("uni_target") == me) && (inv[i]->query("id") == "cart robber") )
        return HIR"有劫匪！先保命吧你！\n"NOR;
         }

        room->set("exits/west", "/d/beijing/guanganmen");
        room->delete("night");
		message_vision("守卫上前将城门打开，$N可以通行了。\n", me);
        remove_call_out("close_gate");
        call_out("close_gate", 3, room);
		return "既然" + RANK_D->query_respect(me) + "有要事在身，那就请进吧。\n";
}
void close_gate(object room)
{
	if(HELPER->is_dark_time())
{
        say("官兵上前将城门关上了。\n");
                room->set("night", 1);
		room->delete("exits/west");
}
	return;
}
