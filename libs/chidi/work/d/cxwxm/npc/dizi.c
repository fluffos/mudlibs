// dizi.c 
// marry 8.13

inherit BHNPC;
#include <ansi.h>

void create()
{
        set_name("守门弟子", ({ "di zi", "di" }));
        set("long", 
                "一个面带微笑，和蔼可亲的人\n");
        set("gender", "男性");
        set("jihao", 1);
        set("age", 18);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);
        
        set("max_qi", 5000);
        set("max_jing", 200);
        set("neili", 3000);
        set("max_neili", 3000);
        set("jiali", 0);
        set("combat_exp", 100000);

        set_skill("force", 300);
        set_skill("dodge", 250);
        set_skill("wangran-xinfa", 300);
        set_skill("cxwx-quan", 250);
        set_skill("axe", 350);
        set_skill("parry", 300);
        set_skill("wangxiang-fufa", 300);
        set_skill("shuiyue", 300);
        set_skill("unarmed", 300);

        map_skill("force", "wangran-xinfa");
        map_skill("axe", "wangxiang-fufa");
        map_skill("parry", "wangxiang-fufa");
        map_skill("dodge", "shuiyue");
        map_skill("unarmed", "cxwx-quan");
       
        create_family("痴心妄想门", 3,"弟子");
        setup();
        carry_object("/d/cxwxm/obj/cloth")->wear();
        carry_object("/d/cxwxm/obj/axe")->wield();
      
      
}

