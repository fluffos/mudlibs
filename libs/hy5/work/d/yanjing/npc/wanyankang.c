#include <ansi.h>
inherit NPC;
void create()
{
   set_name("完颜康",({"wanyan kang"}));
   set("gender","男性");
set("title",HIY"小王爷"NOR);
   set("long","王府小王爷!\n");
set("mingwang",-4000);
   set("combat_exp",160000);
   
set("age",19);
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
   
   setup();
   add_money("silver",4);
carry_object(__DIR__"obj/jinpao")->wear();
carry_object(__DIR__"obj/changjian")->wield();
}

void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;

who->set_temp("book524",1);
	call_out("leavet",1);
}


void leavet()
{
        object ob = this_object();
 message_vision("$N飞身向外逃去！\n" NOR,this_object());
        destruct(this_object());
}