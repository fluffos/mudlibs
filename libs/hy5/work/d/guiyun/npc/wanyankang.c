// wanyankang.c
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("完颜康", ({"wanyan kang", "kang", "wanyan"}));
        set("gender", "男性");
        set("title", HIR"大金国小王爷"NOR);
        set("age", 24);
        set("class", "fighter");
        set("long",
                "他本名杨康。随母包惜弱嫁完颜洪烈后，成了小王子，
贪图富贵，至死不改。\n");
        set("attitude", "friendly");
        set("shen_type",1);
        set("str", 26);
        set("per", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 26);
   set("qi",21780);
   set("max_qi",21780);
set("food",250);
set("water",250);
   set("neili",25000);
   set("max_neili",25000);
   set("force_factor",50);

 set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: exert_function, "recover" :),
                (: exert_function, "recover" :),
                (: perform_action, "strike.ju" :),
                (: perform_action, "sword.ding" :),
                (: perform_action, "sword.jianqi" :),
                (: perform_action, "sword.qixing" :),
                (: perform_action, "sword.qixinggongyue" :),
                (: perform_action, "sword.sanqing" :),

        }));


        set("jiali", 100);

        set("combat_exp", 6500000);
        set("score", 300000);

        set_skill("force", 200);
        set_skill("xiantian-qigong", 350);    //先天气功
        set_skill("sword", 200);
set_skill("qixing-jian",280);
set_skill("qixing-shou",280);
set_skill("qixing-array",280);
        set_skill("quanzhen-jian",250);  //全真剑
        set_skill("dodge", 250);
        set_skill("jinyan-gong", 300);   //金雁功
        set_skill("parry", 200);
        set_skill("haotian-zhang", 250);    //昊天掌
        set_skill("literate",200);
        set_skill("strike",200);
        set_skill("taoism",250);
set_skill("hand", 250);

        map_skill("force", "xiantian-qigong");
        map_skill("sword", "quanzhen-jian");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "quanzhen-jian");
        map_skill("strike", "haotian-zhang");
        prepare_skill("strike", "haotian-zhang");
	set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 200);
        set_temp("apply/damage", 250);

        create_family("全真教", 3, "弟子");

        set("inquiry", ([
                "全真教" :  "我全真教是天下道家玄门正宗。\n",
        ]) );

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/male1-cloth")->wear();

}

void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;
 		who->set_temp("book563",1);
		


	::die();
}


void leavet()
{
        object ob = this_object();
 message_vision("$N离开了这里！\n" NOR,this_object());
        destruct(this_object());
}