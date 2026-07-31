// /kungfu/class/xueshan/shanyong.c  善勇
// by secret

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("善勇", ({ "shan yong", "shan", "yong" }));
        set("long",@LONG
一个胖胖的西藏僧人，面带笑容，却常干笑里藏刀的事。
LONG
        );
        set("title",HIR"血刀门第五代弟子"NOR);
        set("gender", "男性");
        set("age", 35);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
  set("max_qi", 18000);
        set("max_jing", 18000);
        set("neili", 54500);
        set("max_neili", 54500);
        set("jiali", 100);
        set("combat_exp", 9500000);
        set("score", 200000);

        set_skill("necromancy", 380);
        set_skill("xiaowuxiang", 380);
        set_skill("force", 280);
        set_skill("longxiang", 380);
        set_skill("dodge", 200);
        set_skill("shenkong-xing", 380);
        set_skill("unarmed", 200);
        set_skill("yujiamu-quan", 380);
        set_skill("parry", 220);
        set_skill("cuff", 200);
        set_skill("sword", 100);
        set_skill("mingwang-jian", 380);
        set_skill("lamaism", 250);
        set_skill("literate", 200);
        set_skill("hammer", 380);
        set_skill("riyue-lun", 380);
	set_skill("dashou-yin", 380);
        set_skill("staff", 380);
        set_skill("xiangmo-chu", 380);
        set_skill("magic", 380);
        //set_skill("kwan-yin-spells", 380);
//map_skill("magic", "kwan-yin-spells");
map_skill("cuff", "yujiamu-quan");
map_skill("hand", "dashou-yin");
        map_skill("force", "longxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("unarmed", "yujiamu-quan");
        map_skill("parry", "riyue-lun");
        map_skill("sword", "mingwang-jian");
        map_skill("hammer", "riyue-lun");
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 250);
if (random(3)==0)
{
map_skill("unarmed", "longxiang");
map_skill("parry", "longxiang");
	set("chat_chance_combat", 99);  
	set("chat_msg_combat", ({
                (: perform_action, "hammer.wulundafa" :),
                (: perform_action, "hammer.wushuai" :),
                (: perform_action, "hammer.riyue" :),
                (: perform_action, "hammer.lian" :),
                (: perform_action, "hammer.yuan" :),
                (: perform_action, "unarmed.die" :),
                (: perform_action, "unarmed.ji" :),
                (: perform_action, "unarmed.tun" :),
                (: perform_action, "unarmed.zhen" :),
                (: perform_action, "dodge.tianmaxingkong" :),
	}) );

}	
else
{
prepare_skill("cuff", "yujiamu-quan");
prepare_skill("hand", "dashou-yin");

	set("chat_chance_combat", 99);  
	set("chat_msg_combat", ({
                (: perform_action, "hammer.wulundafa" :),
                (: perform_action, "hammer.wushuai" :),
                (: perform_action, "hammer.riyue" :),
                (: perform_action, "hammer.lian" :),
                (: perform_action, "hammer.yuan" :),
                (: perform_action, "cuff.chen" :),
                (: perform_action, "cuff.jiang" :),
                (: perform_action, "hand.dashouyin" :),
                (: perform_action, "hand.jingang" :),
                (: perform_action, "hand.yin" :),
                (: perform_action, "magic.ni" :),
                (: perform_action, "magic.hong" :),
                (: perform_action, "magic.ba" :),
                (: perform_action, "magic.an" :), 
                (: perform_action, "dodge.tianmaxingkong" :),
	}) );
}

        //create_family("雪山寺", 5, "弟子");
        set("class", "bonze");

        setup();
        carry_object("/d/xueshan/obj/y-jiasha")->wear();
        carry_object("/d/xueshan/obj/jinlun")->wield();
}

void unconcious()
{
    die();
}
void die()
{
        object ob, me, corpse;
        
        ob = this_object();
        me = query_temp("last_damage_from");
if (!me) return;
              //me->add("score",1);        
        message_vision(RED"$N一声怒吼，浑身鲜血直流，逃了出去!\n"NOR,ob,me);
        


        me->set_temp("killxs2",1);


               destruct(ob);
        return;
}
