// gdcheng.c
// Modify By River 98/12 
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
        set_name("古笃诚", ({ "gu ducheng", "gu", "ducheng" }));
        set("title", "大理国镇南王府家将");
        set("gender", "男性");
        set("age", 33);
        set("str", 27);
        set("dex", 26);
        set("per", 20);
        set("long", "这人身穿军服，手持两柄板斧，威风凛凛。\n");
        set("combat_exp", 400000);
        set("shen_type", 1);
        set("attitude", "friendly");
        create_family("大理", 3 , "弟子");
        set_skill("cuff", 90);
        set_skill("qiantian-yiyang", 100);
        set_skill("tianlong-xiang", 100);
//      set_skill("pangen-cuojie", 130);
        set_skill("duanjia-quan", 80);
        set_skill("force", 90);
        set_skill("axe", 120);
        set_skill("dodge", 90);
        set_skill("parry", 90);
        set_temp("apply/attack", 70);
        set_temp("apply/defense", 70);
        set_temp("apply/armor", 70);
        set_temp("apply/damage", 20);
        map_skill("force", "qiantian-yiyang");
        map_skill("cuff", "duanjia-quan");
        map_skill("dodge", "tianlong-xiang");
        map_skill("parry", "qingyan-zhang");
//      map_skill("axe", "pangen-cuojie");
        prepare_skill("cuff","duanjia-quan");

        set("max_qi", 1000);
        set("neili", 1000); 
        set("max_neili", 1000);
        set("jing", 600);
        set("max_jing", 600);
        set("eff_jingli", 600);
        set("jiali", 50);

        setup();
        carry_object(__DIR__"obj/banfu")->wield();
        carry_object("/d/dali/npc/obj/zipao")->wear();
}
