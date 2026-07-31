// qqren.c 裘千仞

inherit NPC;
int ask_qiubai();
inherit F_MASTER;
#include "tz_job1.c"

void create()
{
    set_name("裘千仞", ({ "qiu qianren", "qiu", "qianren", "ren"}));
    set("nickname", "铁掌水上漂");
	set("long", 
        "他就是威震川湘的铁掌帮的帮主-铁掌水上漂裘千仞。\n"
        "他是一个白须老头，身穿黄葛短衫，右手挥着一把大蒲扇。\n");
	set("gender", "男性");
	set("age", 60);
    set("attitude", "peaceful");
	set("shen_type", -1);
        set("str", 55);
	set("int", 50);
	set("con", 58);
        set("dex", 55);
	
	set("max_qi", 34000);
	set("max_jing", 33000);
	set("neili", 64000);
	set("max_neili", 64000);
	set("jiali", 200);
	set("combat_exp", 9800000);
	set("score", 400000);
	set_skill("unarmed",300);
	set_skill("hammer",380);
	set_skill("tiexue-hammer",320);
	set_skill("force", 260);
	set_skill("guiyuan-tunafa", 320);
	set_skill("dodge", 260);
	set_skill("shuishangpiao", 320);
	set_skill("strike", 280);
	set_skill("tiezhang-zhangfa", 350);
	set_skill("parry", 250);
	set_skill("literate", 150);
	set_skill("axe", 380);
	set_skill("duanyun-fu", 350);
	map_skill("hammer", "tiexue-hammer");
	set_skill("duanyun-fu", 350);
	set_skill("tongbi-zhang", 350);
	map_skill("force", "guiyuan-tunafa");
	map_skill("dodge", "shuishangpiao");
	map_skill("unarmed", "tiezhang-zhangfa");
	map_skill("strike", "tongbi-zhang");
	map_skill("parry", "tiezhang-zhangfa");
	prepare_skill("strike", "tiezhang-zhangfa");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "strike.chu" :),
                (: perform_action, "strike.juesha" :),
                (: perform_action, "strike.tui" :),
                (: perform_action, "strike.zhui" :),
                (: perform_action, "hammer.fanzhuan" :),
                (: perform_action, "unarmed.dao" :),
                (: perform_action, "unarmed.ying" :),
                (: perform_action, "unarmed.yin" :),
                (: perform_action, "unarmed.tianlei" :),
                (: perform_action, "unarmed.tiezhangxianglong" :),
                  (: perform_action, "unarmed.zhangdao" :),
		(: command("unwield bighammer") :),
		(: command("wield bighammer") :),
        }) );
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 200);
        set_temp("apply/attack", 200);

    create_family("铁掌帮", 14, "帮主");

    set("inquiry", ([
"name" : "老夫便是“铁掌水上漂”裘千仞，你问老夫姓名有什么事么？\n",
"here" : "这里就是铁掌帮的总坛所在，你如没事，不要四处乱走，免招杀身之祸！！！\n",
"上官剑南" : (: ask_qiubai :),
                       "工作" : (: ask_job1 :),
                       "工具" : "你去工具房找要吧！", 
                       "job" : (: ask_job1 :),
                       "work" : (: ask_job1 :),
                       "tools" : "你去工具房找要吧！", 

    ]));

	setup();
//	carry_object(__DIR__"obj/black-cloth")->wear();
carry_object(__DIR__"obj/hammer");
	carry_object(__DIR__"obj/black-cloth")->wear();
}
void init()
{
        object me, ob;
        ::init();
        ob = this_player();
        me = this_object();
 
       add_action("do_task","task"); 
     
}
void attempt_apprentice(object me)
{
        if ((int)me->query("shen") > -10000) {
                command("hehe");
                command("say 我裘千仞可不收心慈手软的人做徒弟。");
                return;
        }
                command("say 好吧，我就收下你了。希望你苦练铁掌神功，将之发扬光大。");
                command("recruit " + me->query("id"));
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                add("apprentice_available", -1);
}
int ask_qiubai()
{
say("他是我师父。我在十三岁那年曾救过他，之后他感恩图报，将全\n"
    "身武功倾囊相受。可惜十年前，他在湖北遭人围攻而死！唉！\n");
return 1;
}


void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;
 		who->set_temp("book581",1);
		


	::die();
}