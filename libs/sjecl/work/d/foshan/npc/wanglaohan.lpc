//wanglaohan  王老汉

#include <ansi.h>

inherit NPC;
inherit F_VENDOR;

string ask_me(object who);

void create()
{
	set_name("王老汉", ({ "wang laohan", "wang"}));
	set("long", "他是一个头发花白的老头，忙着烤烧饼，头也不抬。\n");
        set("gender", "男性" );
        set("age", 58);
	set("shen", 1000);

	set("str", 35);
        set("int", 15);
        set("con", 15);
        set("dex", 20);

	set("max_qi", 800);
        set("max_jing", 800);
        set("neili", 800);
        set("max_neili", 800);

        set("jingli",800);
        set("eff_jingli",800);
        set("jiali", 1);   
	set("combat_exp", 9000);

	set_skill("force", 30);
        set_skill("dodge", 30);
        set_skill("strike", 30);
        set_skill("parry", 30);

        set("inquiry", ([
                  "吴道通"   : (: ask_me :),
	]) );

        set("vendor_goods", ({
            (["name": FOOD_D("shaobing"),"number" : 20]),
            (["name": FOOD_D("youtiao"),"number" : 30]),
            (["name": FOOD_D("mhbianzi"),"number" : 30]),
        }));

	setup();
	carry_object("/clone/misc/cloth")->wear();
        add_money("silver",5);
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

string ask_me(object who)
{
        int i;
        object *ob;

        if( query("revealed") ) {
                if( is_killing(who) ) return "你既然知道老子的名字，就该对我尊重些！纳命来吧！\n";
                else {
                        kill_ob(who);
                        who->fight_ob(this_object());
                        return "既然如此，老子今天反正豁出去，跟你拼了。\n";
                }
        }

        if( (random(10) < 5) || is_fighting() )
                return "你是谁？？？\n";

        set_temp("apply/attack",  80);
        set_temp("apply/defense", 60);
        set_temp("apply/damage",  30);

        message("vision",
		HIR "吴道通怒声说道，多少年来，我隐姓埋名，今日竟然被你这厮认出了。\n"
		"吴道通大喝一声骂道，只要有我在天下的人，都得死，今天先送你见阎王。\n" 
		"吴道通从背后取出一副判官笔握在手中。\n" NOR,
		environment(), this_object() );
	set_name("吴道通",({ "wu daotong", "wu", "daotong" }));
        set("pursuer", 1);
        set("vendetta/authority", 1);
        set("chat_msg_combat", ({
                (: random_move :)
        }) );
        set("chat_chance", 15);
        set("chat_msg", ({
                (: random_move :)
        }) );

        carry_object("/d/tiezhang/obj/bi")->wield();
        carry_object(FOOD_D("shaobing"));
        carry_object("/clone/medicine/jugeng");
        carry_object("/clone/medicine/jugeng");

        set("bellicosity", 10000);
        set("combat_exp", 600000);
        set("qi", 2600);
        set("max_qi",2600);
        set("max_neili",2800);
        set("eff_jingli",2800);  
        set_skill("force", 150);
        set_skill("guiyuan-tunafa", 150);
        set_skill("dodge", 100);
        set_skill("shuishangpiao", 150);
        set_skill("strike", 150);
        set_skill("tiezhang-zhangfa", 120);
        set_skill("brush", 150);
        set_skill("yingou-bifa", 150);
        map_skill("force", "guiyuan-tunafa");
        map_skill("dodge", "shuishangpiao");
        map_skill("strike", "tiezhang-zhangfa");
        map_skill("parry", "yingou-bifa");
        map_skill("brush", "yingou-bifa");
        ob = all_inventory(environment());
	for(i=sizeof(ob)-1; i>=0; i--) {
		if( !userp(ob[i]) ) continue;
		if((int)ob[i]->query("combat_exp",1)<180000) continue;
		kill_ob(ob[i]);
		ob[i]->fight(this_object());
	}
	add_money("gold", 1);
	set("revealed", 1);
	return "哼！，有我吴道通在的地方，人人都得死。\n";
}
