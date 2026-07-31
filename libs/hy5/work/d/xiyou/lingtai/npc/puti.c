//puti.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
        set_name("菩提祖师", ({"master puti","puti", "master"}));
        set("long", "大觉金仙没垢姿，西方妙相祖菩提\n");
        set("title", HIC"斜月三星"NOR);
        set("gender", "男性");
        set("age", 100);
        set("color", HIW);
        set("class", "taoist");
        set("attitude", "friendly");
        set("shen_type", 1);
        set("rank_info/respect", "老师祖");
        set("per", 26);
        set("looking", "玉面多光润，苍髯颌下飘，金睛飞火焰，长目过眉梢。");
        set("int", 30);
        set("max_kee", 5000);
        set("max_gin", 1000);
        set("max_sen", 5000);
        set("force", 5000);
        set("max_force", 2500);
        set("force_factor", 150);
      

        create_family("方寸山三星洞", 1, "蓝");
        setup();

        carry_object("/d/xiyou/lingtai/obj/pao")->wear();
        carry_object("/d/xiyou/lingtai/obj/shoe")->wear();
        carry_object("/d/xiyou/lingtai/obj/putibang")->wield();
}



