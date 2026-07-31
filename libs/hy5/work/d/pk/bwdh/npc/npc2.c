// /kungfu/class/xueshan/xuedao.c  血刀老祖
// by secret

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string ask_for_quit();
void create()
{
        set_name("小血刀老祖", ({ "xuedao laozu", "xue dao", "laozu" }));
        set("long",@LONG
这喇嘛身着黄袍，年纪极老，尖头削耳，脸上都是皱纹。他就是血刀门第四代掌门。
LONG
        );
        set("title",HIR"血刀门第四代掌门"NOR);
        set("gender", "男性");
        set("age", 85);
        set("attitude", "peaceful");
        set("shen_type", -1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 5000);
        set("max_jing", 2000);
        set("neili", 12000);
        set("max_neili", 12000);
        set("jiali", 50);
        set("combat_exp", 2500000);
        set("score", 180000);

        set_skill("lamaism", 150);
        set_skill("literate", 80);
        set_skill("force", 180);
        set_skill("parry", 180);
        set_skill("blade", 250);
        set_skill("sword", 120);
        set_skill("dodge", 180);
        set_skill("longxiang", 300);
        set_skill("shenkong-xing", 300);
        set_skill("hand", 280);
        set_skill("dashou-yin", 300);
        set_skill("mingwang-jian", 200);
        set_skill("xue-dao", 300);

        map_skill("force", "longxiang");
        map_skill("dodge", "shenkong-xing");
        map_skill("hand", "dashou-yin");
        map_skill("parry", "xue-dao");
        map_skill("blade", "xue-dao");
        map_skill("sword", "mingwang-jian");
	set("chat_chance_combat", 90);  
	set("chat_msg_combat", ({
                (: perform_action, "blade.kuangdao" :),
                (: perform_action, "blade.shendao" :),
                (: perform_action, "blade.kuangdao" :),
                (: perform_action, "blade.shendao" :),
                (: perform_action, "dodge.tianmaxingkong" :),
                (: exert_function, "fumozhou" :),                
                (: exert_function, "fumozhou" :),                
                (: exert_function, "fanchang" :),                
	}) );
        set("inquiry",([
                "还俗"  :  (: ask_for_quit :),
        ]));

        set_temp("apply/attack", 300);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 250);

        create_family("雪山寺", 4, "弟子");
        set("class", "bonze");

        setup();
        carry_object("/d/xueshan/obj/y-jiasha")->wear();
        carry_object("/d/xueshan/obj/xblade")->wield();
        carry_object(__DIR__"obj/jinchuang");
        carry_object(__DIR__"obj/jinchuang");
        carry_object(__DIR__"obj/jinchuang");

        add_money("gold",2);
}


