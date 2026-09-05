#include <ansi.h>
// daotong.c 道童
inherit NPC;

string *name=({"静", "无", "悟", "虚", "少", 
	             "阳", "乾", "坤", "日", "月", 
	             "天", "地", "极", "一", "元",
	             "始", "正", "寐", "苦", "渌",
	             "仴", "丹", "聃", "岚", "斓"});

void create()
{
        set_name("清"+name[random(1000)%sizeof(name)], ({ "daotong", "dao", "tong" }));
        set("long",
                "他是武当山的小道童。\n");
        set("title",RED "武当派" NOR + GRN "小道士" NOR);
        set("gender", "男性");
        set("age", 16);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 20);
        set("int", 20);
        set("con", 22);
        set("dex", 25);
        set("max_qi", 150);
        set("max_jing", 100);
        set("neili", 150);
        set("max_neili", 150);
        set("combat_exp", 2000);
        set("score", 1000);
        set_skill("force", 30);
        set_skill("dodge", 20);
        set_skill("unarmed", 20);
        set_skill("parry", 20);
        set_temp("apply/attack", 15);
        set_temp("apply/defense", 15);
        set_temp("apply/damage", 5);
        create_family("武当派", 5, "弟子");
        setup();
        carry_object("/d/wudang/obj/greyrobe")->wear();
}

#include "/newbiequest/wudang/quest_zhenfa.h";