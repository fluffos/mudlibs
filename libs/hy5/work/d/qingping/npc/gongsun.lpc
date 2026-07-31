 // XXder@fy3
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("公孙不智" , ({ "buzhi", "gongsun buzhi", "gongsun" }) );
        set("long", "此人身形瘦小，最善于攻心计。\n");
        set("attitude", "friendly");
/*      set("max_gin", 500);
        set("max_kee", 500);
        set("max_sen", 500);  */
        set("age", 30);
        set("gender", "男性" );
/*      set("str", 35);
        set("cor", 30);
        set("cps", 25); */
        create_family("清平山庄", 1, "三弟子");
        set("combat_exp", 20000+random(50000));
        set_skill("dodge", 50+random(50));
        set_skill("unarmed", 80);
        set_skill("sword", 365);

        set_skill("force", 60);

        setup();
        carry_object(__DIR__"obj/cloth")->wear();
        carry_object("/clone/weapon/gangjian")->wield();
}  
