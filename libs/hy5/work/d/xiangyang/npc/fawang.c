// /kungfu/class/xueshan/fawang.c  金轮法王
// by secret

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        object ob;
        set_name("金轮法王", ({ "jinlun fawang", "fawang", "fawang" }));
        set("long",@LONG
他是雪山寺的护教法王。在雪山寺的地位仅次与掌门人鸠摩智。
身穿一件紫红袈裟，头带僧帽。
LONG
        );
        set("title", HIY "法王" NOR);
        set("gender", "男性");
        set("age", 50);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 60);
        set("int", 60);
        set("con", 60);
        set("dex", 60);
        set("max_qi", 88000);
        set("max_jing", 88000);
        set("neili", 84500);
        set("max_neili", 84500);
        set("jiali", 100);
        set("combat_exp", 29500000);
        set("score", 200000);

        set_skill("necromancy", 380);
        set_skill("xiaowuxiang", 380);
        set_skill("force", 580);
        set_skill("longxiang", 590);
        set_skill("dodge", 300);
        set_skill("shenkong-xing", 380);
        set_skill("unarmed", 300);
        set_skill("yujiamu-quan", 380);
        set_skill("parry", 320);
        set_skill("cuff", 300);
        set_skill("sword", 300);
        set_skill("mingwang-jian", 380);
        set_skill("lamaism", 350);
        set_skill("literate", 200);
        set_skill("hammer", 380);
        set_skill("riyue-lun", 380);
	set_skill("dashou-yin", 380);
        set_skill("staff", 380);
        set_skill("xiangmo-chu", 380);
        set_skill("magic", 380);
        set_skill("kwan-yin-spells", 580);
map_skill("magic", "kwan-yin-spells");
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
        set_temp("apply/armor", 3500);
        set_temp("apply/damage", 3250);

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
                (: perform_action, "magic.ni" :),
                (: perform_action, "magic.hong" :),
                (: perform_action, "magic.ba" :),
                (: perform_action, "magic.an" :), 
                (: perform_action, "dodge.tianmaxingkong" :),
	}) );




        create_family("雪山寺", 2, "护教法王");
        set("class", "bonze");

        setup();
        //carry_object("/d/xueshan/obj/jinlun")->wield();
        if (clonep()) {
                if (random(4)==0)
{
                ob = new(__DIR__"13jiasha");
                ob->set("jiasha/neili",13);
                ob->move(this_object());
                ob->wear();
}
}

        carry_object("/d/xueshan/obj/p-jiasha")->wear();
        carry_object("/d/xueshan/obj/sengmao")->wear();
        add_money("gold",1);
}



void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;
  	
	who->set_temp("book10101",1);
	::die();
}  