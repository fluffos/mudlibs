#include <ansi.h>
inherit NPC;

void create()
{
        set_name("魔熊", ({ "mo xiong", "xiong" }));
        set("long", 
                "他是兽族的二大护法之一,管理着兽族的日常生活.。\n"
        set("gender", "男性");
        set("age", 20);
        set("attitude", "peaceful");
        set("shen_type", 0);
        set("int", 30);
        set("str", 30);
        set("con", 30);
        set("dex", 30);
        
        set("max_qi", 1500);
        set("max_jing", 500);
        set("neili", 1500);
        set("max_neili", 1500);
        set("jiali", 100);
        set("combat_exp", 100000);
        set("score", 5000);

        set_skill("force", 100);
        set_skill("dodge", 100);
        set_skill("unarmed", 100);
        set_skill("parry", 100);


        set("chat_chance_combat", 90);

        setup();

}
