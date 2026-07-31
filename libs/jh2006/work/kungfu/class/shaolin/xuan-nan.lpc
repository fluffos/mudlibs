// Npc: /kungfu/class/shaolin/xuan-nan.c
// Date: YZC 96/01/19

inherit NPC;
inherit F_MASTER;

string ask_me();

void create()
{
        object ob;
        set_name("玄难大师", ({
                "xuannan dashi",
                "xuannan",
                "dashi",
        }));
        set("long",
                "他是一位白须白眉的老僧，身穿一袭银丝棕黄袈裟。他身材极瘦，\n"
                "两手更象鸡爪一样。他双目微闭，一副没精打采的模样。\n"
        );


        set("nickname", "般若堂首座");
        set("gender", "男性");
        set("attitude", "friendly");
        set("class", "bonze");

        set("age", 70);
        set("shen_type", 1);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 1800);
        set("max_jing", 1000);
        set("neili", 2000);
        set("max_neili", 2000);
        set("jiali", 150);
        set("combat_exp", 1000000);
        set("score", 500000);

        set_skill("force", 150);
        set_skill("yijin-jing", 150);
        set_skill("dodge", 150);
        set_skill("shaolin-shenfa", 150);
        set_skill("parry", 150);
        set_skill("cuff", 150);
        set_skill("club", 150);
        set_skill("finger", 150);
        set_skill("strike", 150);
        set_skill("jingang-quan", 150);
        set_skill("zui-gun", 150);
        set_skill("yizhi-chan", 150);
        set_skill("banruo-zhang", 150);
        set_skill("buddhism", 150);
        set_skill("literate", 150);

        map_skill("force", "yijin-jing");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("cuff", "jingang-quan");
        map_skill("finger", "yizhi-chan");
        map_skill("strike", "banruo-zhang");
        map_skill("club", "zui-gun");
        map_skill("parry", "wuchang-zhang");

        prepare_skill("finger", "yizhi-chan");
        prepare_skill("strike", "banruo-zhang");

        create_family("少林派", 36, "弟子");

        set("inquiry", ([
                "十八罗汉阵"       : (: ask_me :),
                "罗汉大阵"         : (: ask_me :)
        ]));

        setup();
        if (clonep()) {                
                ob = unew(BINGQI_D("banzhu-gun"));               
                if (!ob) ob = unew("/d/shaolin/obj/qimeigun");
                ob->move(this_object());
                ob->wield();
                carry_object("/d/shaolin/obj/xuan-cloth")->wear();
        } 
}


#include "/kungfu/class/shaolin/xuan-nan.h"

