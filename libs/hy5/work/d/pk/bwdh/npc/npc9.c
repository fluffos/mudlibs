// /kungfu/class/xueshan/fawang.c  金轮法王
// by secret

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("小金轮法王", ({ "jinlun fawang", "fawang", "fawang" }));
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
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 5000);
        set("max_jing", 5000);
        set("neili", 14500);
        set("max_neili", 14500);
        set("jiali", 100);
        set("combat_exp", 2500000);
        set("score", 200000);

        set_skill("necromancy", 100);
        set_skill("force", 200);
        set_skill("longxiang", 300);
        set_skill("dodge", 200);
        set_skill("shenkong-xing", 300);
        set_skill("unarmed", 200);
        set_skill("yujiamu-quan", 300);
        set_skill("parry", 220);
        set_skill("cuff", 200);
        set_skill("sword", 100);
        set_skill("mingwang-jian", 250);
        set_skill("lamaism", 250);
        set_skill("literate", 200);
        set_skill("hammer", 200);
        set_skill("riyue-lun", 300);

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
	set("chat_chance_combat", 90);  
	set("chat_msg_combat", ({
                (: perform_action, "hammer.wulundafa" :),
                (: perform_action, "hammer.wulundafa" :),
                (: perform_action, "dodge.tianmaxingkong" :),
                (: perform_action, "dodge.tianmaxingkong" :),
	}) );

        create_family("雪山寺", 2, "护教法王");
        set("class", "bonze");

        setup();
        carry_object("/d/xueshan/obj/jinlun")->wield();
        carry_object("/d/xueshan/obj/p-jiasha")->wear();
        carry_object("/d/xueshan/obj/sengmao")->wear();
        carry_object(__DIR__"/obj/rsg");
        carry_object(__DIR__"/obj/rsg");        

        add_money("gold",1);
}

 
