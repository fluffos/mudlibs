 inherit NPC;
#include <ansi.h>
inherit F_MASTER;
int time_period(int timep, object me);
//int give_hint();
string sysmsg;
void create()
{
        set_name(HIG"天孙"NOR, ({ "tian sun", "tiansun" }) ); 
        set("gender", "男性");
        set("age", 40);
        set("long",
 "\n天孙是当今江湖中最神秘的组织〖天宗〗的头领，他掌握着很多人的命运。\n");
        set("attitude", "peaceful");
        set("reward_npc", 1);
        set("difficulty", 10);
        set("str", 2000);
        set("cor", 30);
        set("int", 40);
        set("cps", 30);
        set("chat_chance", 1);
        set("chat_msg", ({
//                "连城璧向你拱了拱手道：＂这位英雄，今朝相遇，我连某深感荣幸！＂\n",
        }) );
        set("inquiry", ([
//                "天宗" : (: give_hint:),
//                "tianzong" : (: give_hint:) 
        ]));
	set("neili", 22400);
	set("max_neili", 22400);
	set("max_qi", 22000);
	set("max_jing", 21200);
	set("combat_exp", 8000000);
	set("shen_type", 1);

	set_skill("strike", 150);
	set_skill("kuaihuo-strike", 310);
	set_skill("sword", 350);
	set_skill("taishan-sword", 320);
	set_skill("shiba-pan", 320);
	set_skill("force", 150);
	set_skill("panshi-shengong", 350);
	set_skill("parry", 150);
	set_skill("dodge", 150);
	set_skill("fengshenjue", 310);
	set_skill("dramaturgy", 380);
	set_skill("horticulture", 380);
	map_skill("sword", "taishan-sword");
	map_skill("parry", "taishan-sword");
	map_skill("dodge", "fengshenjue");
	map_skill("force", "panshi-shengong");
	map_skill("strike", "kuaihuo-strike");
	prepare_skill("strike", "kuaihuo-strike");
	set("no_get",1);
	set("chat_chance_combat", 90);
	set("chat_msg_combat", ({
		(: perform_action, "sword.heru" :),
		(: perform_action, "sword.ruhe" :),
		(: perform_action, "sword.wuyue" :),
		(: perform_action, "sword.18pan" :),
		(: perform_action, "strike.zhouyu" :),
		(: exert_function, "powerup" :),
		(: exert_function, "regenerate" :),
		(: exert_function, "recover" :),
	}) );        set_temp("apply/attack",100);
        set_temp("apply/dodge", 200);
        set_temp("apply/parry", 200);
        set_temp("apply/damage",100); 
        set("title", "无垢山庄 少庄主");
        set("nickname", HIR"侠义无双"NOR);
        setup(); 
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/mask")->wear();
        //create_organization("天宗",1,"邪");
}
int accept_fight(object me)
{
        command("say 哼！我没有这等闲功夫");
        return 0;
}
  