// hong.c 洪安通

#include <ansi.h>;
inherit NPC;
inherit F_UNIQUE;
inherit F_MASTER;

void create()
{
	set_name("洪安通", ({ "hong antong", "hong" }));
	set("title",  HIY"神龙教"NOR"教主" );
	set("nickname", HIR "永享仙福" NOR);
	set("long", "他就是武功盖世、令江湖人等谈之色变的神龙教教主洪安通。\n");
	set("gender", "男性");
	set("age", 50);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 135);
	set("int", 130);
	set("con", 130);
	set("dex", 138);
	
	set("max_qi", 344000);
	set("eff_qi", 344000);
	set("max_jing", 343000);
	set("eff_jing", 343000);
	set("neili", 352000);
	set("max_neili", 352000);
	set("jiali", 100);
	set("combat_exp", 9500000);
	set("score", 400000);

        set_skill("force", 1000);
	set_skill("shenlong-xinfa", 980);
        set_skill("dodge", 180);
	set_skill("yixingbu", 1300);
        set_skill("hand", 1200);
	set_skill("shenlong-bashi", 980);
        set_skill("strike", 1200);
	set_skill("huagu-mianzhang", 980);
        set_skill("parry", 1150);
        set_skill("staff", 1300);
        set_skill("sword", 1000);
        set_skill("zhaosheshu", 1300);
        set_skill("yangsheshu", 1300);
	set_skill("shedao-qigong", 980);
	set_skill("literate", 990);

	map_skill("force", "shenlong-xinfa");
	map_skill("dodge", "yixingbu");
	map_skill("hand", "shenlong-bashi");
	map_skill("strike", "huagu-mianzhang");
	map_skill("parry", "shedao-bashi");
        map_skill("staff", "shedao-qigong");
	prepare_skill("strike", "huagu-mianzhang");
	prepare_skill("hand", "shenlong-bashi");
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 2500);
        set_temp("apply/damage", 2550);
	create_family("神龙教",1,"教主");

        set("inquiry", ([
		"神龙教" :  "\n一般人是入不了我神龙教的(join shenlongjiao)。\n",
		"入教" :  "\n一般人是入不了我神龙教的(join shenlongjiao)。\n",
		"洪安通" :  "\n你不想活了是不是?\n",
		"教主" :  "\n我就是神龙教教主。\n",
		"口号" : "\n万年不老!永享仙福!寿与天齐!文武仁圣!\n",
       ]) );
	set("chat_chance_combat", 50);  
	set("chat_msg_combat", ({
		(: command("smile") :),
		(: command("haha") :),
		(: command("chat 凭你这" + RANK_D->query_rude(this_player())+",也敢在太岁爷头上动土?\n") :),
		(: command("say 你活得不耐烦了找死啊？\n") :),
                (: perform_action, "staff.chang" :),
                (: perform_action, "staff.chang" :),
                (: perform_action, "staff.chang2" :),
                (: perform_action, "staff.chang2" :),
                (: perform_action, "staff.chang3" :),
                (: perform_action, "staff.chang3" :),
                (: perform_action, "strike.hua" :),
                (: perform_action, "hand.bada" :),
                (: perform_action, "hand.shenlongtuwu" :),
                (: perform_action, "hand.shenlongtuwu" :),
                (: perform_action, "hand.yingxiong" :),                
                (: perform_action, "hand.yingxiong" :),                
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
                      }) );
	setup();
	//carry_object("/clone/weapon/gangzhang")->wield();
	carry_object("/clone/misc/cloth")->wear();
    carry_object("/p/item/ritemtz3/wstaff18")->wield();
    carry_object("/p/item/ritemtz3/ahands29")->wear();
	//add_money("silver", 50);
}


