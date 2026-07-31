// yuzu.c     
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("狱卒", ({ "yu zu", "zu", "yu" }));
        set("long", 
"一个明教的狱卒，身材很瘦，长得其貌不扬。");
        set("gender", "男性");
        set("age", 36);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 23);
        set("int", 23);
        set("con", 24);
        set("dex", 28);
        
        set("max_qi", 600);
        set("max_jing", 300);
        set("neili", 500);
        set("max_neili", 300);
        set("jiali", 10);
        set("combat_exp", 8000);
        set("score", 50);


        set_skill("sword", 40); 
        set_skill("parry", 40);
        set_skill("dodge", 40);
        set_skill("unarmed", 40);
        set_skill("force",40);

        create_family("明教", 36, "弟子");

        setup();
        carry_object("/clone/misc/cloth")->wear();
}

