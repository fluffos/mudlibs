///xieyan.c 谢烟客

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
        set_name("谢烟客", ({ "xie yanke", "xie", "yanke" }));
        set("long", "他就是摩天崖的主人。看年纪大约五十多岁，\n"
                   +"年轻时好武成兴，无比骄傲，自认为天下第一。\n");
        set("gender", "男性");
        set("age", 50);
        set("shen_type",1);
        set("str", 300);
        set("int", 29);
        set("con", 30);
        set("dex", 280);

        set("qi", 100000);
        set("max_qi", 100000);
        set("jing", 10000);
        set("max_jing", 10000);
        set("neili", 550000);
        set("max_neili", 15000);
        set("jiali", 500);

        set("combat_exp", 150000000);
        set("score", 200000);
        set_skill("force", 1700);
        set_skill("unarmed", 1000);
        set_skill("dodge", 1500);
        set_skill("parry", 1500);
        set_skill("hamagong", 2000);
        set_skill("chanchu-bufa", 1500);
        set_skill("lingshe-zhangfa", 1500);

        map_skill("force", "hamagong");
        map_skill("dodge", "chanchu-bufa");
        map_skill("unarmed", "shexing-diaoshou");
        map_skill("parry", "lingshe-zhangfa");
     


        setup();
        carry_object("/clone/weapon/gangzhang")->wield();
        add_money("gold",20);
}

