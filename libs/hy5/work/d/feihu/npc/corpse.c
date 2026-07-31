// tufeitou.c

inherit NPC;

void create()
{
	set_name("毒僵尸", ({ "flash corpse","corpse leader" }) );
	set("gender", "男性");
	set("age", 45+random(10));
            set("str",99);
            set("per", 10);
	set("long",
		"这家伙整个脸都烂了，太可怕了，令人望而生畏。\n");
	set("combat_exp", 280000+random(900000));

        set("shen_type", -1);
	set("attitude", "aggressive");

set("str", 65);
	set("int", 60);
	set("con", 68);
	set("dex", 68);
	set("per", 68);
		set("qi", 88000);
	set("jing", 88000);
		set("eff_qi", 88000);
	set("eff_jing", 88000);
	set("neili", 84000);
	set("max_qi", 88000);
	set("max_jing", 88000);
	set("neili", 84000);
	set("max_neili", 84000);
	set("max_neili", 84000);
	set("jiali", 100);
	set("combat_exp", 9500000);
	set("score", 400000);
        set("vendetta/authority",1);
	set_skill("unarmed", 550);
	set_skill("force", 550);
	set_skill("huagong-dafa", 580);
	set_skill("throwing", 550);
	set_skill("feixing-shu", 580);
	set_skill("dodge", 550);
	set_skill("zhaixinggong", 380);
	set_skill("strike", 550);
	set_skill("chousui-zhang", 580);
	set_skill("claw", 550);
	set_skill("sanyin-wugongzhao", 580);
	set_skill("parry", 500);
	set_skill("staff", 500);
	set_skill("poison", 580);
	set_skill("tianshan-zhang", 380);
	set_skill("chanhun-suo", 380);
	set_skill("whip", 380);
	set_skill("literate", 150);
set_skill("blade", 250);
set_skill("xuantian-strike", 380);
set_skill("bingpo-blade", 380);

	map_skill("whip", "chanhun-suo");
	map_skill("force", "huagong-dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("strike", "chousui-zhang");
	map_skill("claw", "sanyin-wugongzhao");
	map_skill("parry", "chousui-zhang");
	map_skill("unarmed", "chousui-zhang");
	map_skill("staff", "tianshan-zhang");
	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-wugongzhao");
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "strike.zhaohuo" :),
                (: perform_action, "strike.biyan" :),
                (: perform_action, "strike.fushidu" :),
                (: perform_action, "strike.sandu" :),
                (: perform_action, "strike.huoqiang" :),
                (: perform_action, "strike.throw" :),
                (: perform_action, "strike.yinhuo" :),
                (: perform_action, "strike.zhaohuo" :),
                (: perform_action, "strike.huoqiu" :),

         }) );
        set_temp("apply/attack", 100+random(200));
        set_temp("apply/defense", 100+random(200));
        set_temp("apply/armor", 200+random(300));
        set_temp("apply/damage", 100+random(200));

	set("chat_chance", 5);
	set("chat_msg", ({
		"活僵尸嘿嘿地怪叫着: 放下宝藏!\n",
	}) );



	setup();
//       carry_object("d/city/npc/obj/gangjian")->wield();
       carry_object("/clone/misc/cloth")->wear();
	add_money("coin", 1);
}
void init( )
{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
        ob->start_busy(1);
        call_out("hunting",0);
        }

}

void hunting()
{
	int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
        if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
        if(ob[i]->query("vendetta/authority")) continue;
        if(!userp(ob[i])) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
}             