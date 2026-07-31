// wanyanhonglie.c
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("完颜洪烈", ({"wanyan honglie", "honglie", "wanyan"}));
        set("gender", "男性");
        set("title", HIR"大金国赵王爷"NOR);
        set("age", 48);
        set("class", "officer");
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 26);
        set("per", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 26);

          set("qi",51780);
   set("max_qi",51780);
set("food",250);
set("water",250);
   set("neili",55000);
   set("max_neili",55000);
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

        set_skill("force", 300);
        set_skill("xiantian-qigong", 350);    //先天气功
        set_skill("sword", 300);
set_skill("qixing-jian",380);
set_skill("qixing-shou",380);
set_skill("qixing-array",380);
        set_skill("quanzhen-jian",380);  //全真剑
        set_skill("dodge", 350);
        set_skill("jinyan-gong", 380);   //金雁功
        set_skill("parry", 300);
        set_skill("haotian-zhang", 350);    //昊天掌
        set_skill("literate",300);
        set_skill("strike",300);
        set_skill("taoism",350);
set_skill("hand", 350);

        map_skill("force", "xiantian-qigong");
        map_skill("sword", "quanzhen-jian");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "quanzhen-jian");
        map_skill("strike", "haotian-zhang");
        prepare_skill("strike", "haotian-zhang");
	set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 2200);
        set_temp("apply/damage", 2250);
        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/male1-cloth")->wear();
}

void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;
 		who->set_temp("book564",1);
		


	::die();
}


void leavet()
{
        object ob = this_object();
 message_vision("$N离开了这里！\n" NOR,this_object());
        destruct(this_object());
}