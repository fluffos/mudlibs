#include <ansi.h>

inherit NPC;

void create()
{
        set_name("蒙古武士", ({ "wushi","solider" }) );
        set("gender", "男性" );
        set("age", 35+random(10));
        set("attitude", "friendly");
        set("str", 20+random(10));
        set("con", 20+random(10));
        set("int", 20+random(10));
        set("dex", 20+random(10));
 
        set("max_qi", 3500+random(500));
        set("max_jing", 2500+random(500));
        set("neili", 3000+random(1000));
        set("eff_jingli", 2500+random(500));
        set("max_neili", 2500+random(500));
        set("jiali", 10);
         
        set("combat_exp", 1000000);

        set_skill("force", 100); 
        set_skill("cuff", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("taizu-quan", 100);
        set_skill("jinyan-gong", 100);
        set_skill("xiantian-gong",100);

        map_skill("force", "xiantian-gong");
        map_skill("dodge", "jinyan-gong");
        map_skill("cuff", "taizu-quan");
        map_skill("parry", "taizu-quan");

        prepare_skill("cuff", "taizu-quan");

        setup();
}

void init()
{
        call_out("dest",60);
}

void dest()
{
       object me = this_object();
       message_vision(HIY"$N说道：“不错嘛，今天就放过你了。”\n"NOR,me);
       destruct(me);
}
