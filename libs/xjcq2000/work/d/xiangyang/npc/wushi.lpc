#include <ansi.h>
inherit NPC;

void create()
{
        set_name("蒙古武士", ({ "wushi","fighter" }) );
        set("gender", "男性" );
        set("age", 35+random(10));
        set("attitude", "friendly");
        set("str", 40+random(5));
        set("con", 35+random(5));
        set("int", 20+random(10));
        set("dex", 30+random(10));
 

        set("max_qi", 6500+random(500));
        set("max_jing", 6500+random(500));
        set("neili", 5000+random(1000));
        set("eff_jingli", 6500+random(500));
        set("max_neili", 5000+random(500));
        set("jiali", 150);
         
        set("combat_exp", 1250000);

        set_skill("force", 200); 
        set_skill("cuff", 200);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("taizu-quan", 200);
        set_skill("jinyan-gong", 200);
        set_skill("xiantian-gong",200);
        set_skill("spear", 200);
        set_skill("bawang-qiang", 200);

        map_skill("force", "xiantian-gong");
        map_skill("dodge", "jinyan-gong");
        map_skill("cuff", "taizu-quan");
        map_skill("parry", "bawang-qiang");
        map_skill("spear", "bawang-qiang");

        prepare_skill("cuff", "taizu-quan");

        setup();
        carry_object("/d/xiangyang/obj/spear.c")->wield();
        carry_object(ARMOR_D("armor"))->wear();
}

void init()
{
        object ob;
        call_out("dest",500, ob);
}

void dest()
{
       object me = this_object();
       message_vision(HIY"$N说道：“老子可要回去报到了。”\n"NOR,me);
       destruct(me);
}

void die()
{
    int i;
    object me = this_object();
    object  where, *fighters;
    where = environment(me);
    fighters = all_inventory(where);
    for(i = 0; i < sizeof(fighters); i++) {
       if (userp(fighters[i])) {
          if (fighters[i]->query_temp("xy/job")>1 && fighters[i]->is_fighting())
             fighters[i]->add_temp("xy/job", random(2)+1); }
    }
    remove_call_out("dest");
    message_vision(HIY"$N叫道：“老子回去找援兵，你们撑住啊！”\n"NOR,me);
    destruct(me);
}

