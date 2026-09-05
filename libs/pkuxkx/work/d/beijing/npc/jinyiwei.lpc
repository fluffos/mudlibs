// shiwei.c 锦衣卫

inherit NPC;
#include <ansi.h>
#include "/d/beijing/autok.h"
void create()
{
        set_name("锦衣卫", ({ "jin yiwei", "jin", "wei" }));
        set("gender", "男性");
        set("age", random(20) + 30);
        set("str", 25);
        set("dex", 16);
        set("long", "这些人在京城侍卫中小有名气，武功也十分了得\n");
        set("combat_exp", 575000);
        set("shen_type", 1);
        set("attitude", "peaceful");

        set_skill("force", 140);
        set_skill("xuantian-wuji", 140);
        set_skill("dodge", 140);
        set_skill("kunlun-shenfa", 140);
        set_skill("strike", 140);
        set_skill("sword", 140);
        set_skill("parry", 140);
        set_skill("qingmang-jian", 140);
        set_skill("kunlun-zhang", 140);

        map_skill("force", "xuantian-wuji");
        map_skill("sword", "qingmang-jian");
        map_skill("dodge", "kunlun-shenfa");
        map_skill("strike", "kunlun-zhang");
        map_skill("parry", "kunlun-zhang");
        prepare_skill("strike", "kunlun-zhang");

        set("neili", 3400);
        set("max_neili", 3400);
        set("eff_jingli", 2200);
        set("max_jingli", 2200);
        set("jingli", 2200);

        setup();
        carry_object("/d/city/obj/gangjian")->wield();
        carry_object(__DIR__"obj/shiweifu")->wear();
}

void init()
{
    auto_kill(this_player());
}

void kill_ob(object me)
{
   object ob;
   if(!this_object()->is_killing(me->query("id")))
   {
    ::kill_ob(me);
    if(objectp(ob = present("jin yiwei 2", environment(this_object())))
       && !ob->is_killing(me->query("id"))){
         if(!ob->is_killing(me->query("id"))) ob->kill_ob(me);
         }
    if(objectp(ob = present("jin yiwei 3", environment(this_object())))
       && !ob->is_killing(me->query("id"))){
         if(!ob->is_killing(me->query("id"))) ob->kill_ob(me);
         }
    if(objectp(ob = present("jin yiwei 4", environment(this_object())))
       && !ob->is_killing(me->query("id"))){
         if(!ob->is_killing(me->query("id"))) ob->kill_ob(me);
         }
    if(objectp(ob = present("jin yiwei", environment(this_object())))
       && !ob->is_killing(me->query("id"))){
         if(!ob->is_killing(me->query("id"))) ob->kill_ob(me);
         }
    }
}






