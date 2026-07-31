///xieyan.c 谢烟客

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
int ask_me();
void create()
{
        set_name("丁不三", ({ "ding busan", "ding" }));
        set("long", "他虽然须发皓然，眉开眼笑，面目慈祥，却是一个杀人不眨眼的大魔头，外号“一日不过三”。\n");
        set("gender", "男性");
        set("age", 50);
        set("shen_type",1);
        set("attitude", "peaceful");

        set("str", 30);
        set("int", 29);
        set("con", 30);
        set("dex", 28);
set("nickname", HIR"一日不过三"NOR);
        set("qi", 38000);
        set("max_qi", 38000);
        set("jing", 38000);
        set("max_jing", 38000);
        set("neili", 51500);
        set("max_neili", 51500);
        set("jiali", 50);
        set_skill("parry", 380);
	set_skill("force", 380);
	set_skill("unarmed", 380);
	set_skill("dodge", 380);
	set_skill("taixuan-gong", 550);
	set_skill("feixian-steps", 580);
	set_skill("shenzhao-jing", 580);
	map_skill("force", "shenzhao-jing");
	map_skill("parry", "taixuan-gong");
	map_skill("unarmed", "shenzhao-jing");
	map_skill("dodge", "feixian-steps");
        set("combat_exp", 3500000);
        set("score", 200000);
set("max_neili",80000);
        set("neili",80000);
        set("max_qi",36800);
        set("max_jing",36800);
        set("jing",36800);
        set("qi",36800);
        set("eff_jingli",38000);
        set("jingli",38000);
        set("jiali",100);
	set("szj/passed", 1);
	set("szj/over200", 1);
	set("book_count", 1);
	set("chat_chance_combat", 90);
       set("chat_msg_combat", ({
                (: perform_action, "unarmed.wu" :),
                (: perform_action, "unarmed.ying" :),
                (: perform_action, "parry.po" :),
                (: perform_action, "parry.jing" :),
                (: perform_action, "parry.xuan" :),
                (: perform_action, "parry.po" :),
                (: perform_action, "parry.taixuan" :),
               
        }) );
        
        set("inquiry", ([

"丁当" : (: ask_me :),
        ]));

        
	set_temp("apply/attack", 200);
	set_temp("apply/defense", 200);
	set_temp("apply/armor", 2000);
	set_temp("apply/damage", 2000);


        setup();
carry_object("/clone/misc/cloth")->wear();
        add_money("gold",1);
}



int ask_me()
{
	int i;
        object ob;
	object who = this_player();
	object where = environment(who);
	


	command("bow " + who->query("id"));
	message_vision("$N对$n说道： 丁当不知道为什么喜欢上那个石破天那个小子。\n",this_object(),who);
	message_vision("$N对$n说道：我一定要杀了石破天，省得日后丢我的面子。\n",this_object(),who);

who->set_temp("book111",1);

	return 1;
}