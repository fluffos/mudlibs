// yuanbing for emei job

#include <ansi.h>

inherit NPC;

void create()
{
        set_name("元兵", ({ "yuan bing", "yuanbing", "bing" }) );
        set("gender", "男性");
        set("long",
                "这家伙膀大腰圆，气势汹汹，令人望而生畏。\n");
        set("shen", -15000);
        set("age", random(10)+25);
        set("str", 30);
        set("int", 30);  
        set("con", 30);     
        set("dex", 30);
        set("combat_exp", 9999999);
        set("shen_type", -1);
        set("attitude", "peaceful");
        set("max_jing",2000);
        set("eff_jing",2000);
        set("jing",2000);
        set("eff_jingli", 3000);
        set("jingli", 3000);
        set("jiali", 99);
        set("max_neili",9999);
        set("score", 10000);
        
        set_skill("force", 300);
        set_skill("dodge", 300);
        set_skill("parry", 300);
        set_skill("cuff", 300);
        set_skill("taizu-quan", 300);
        set_skill("jinyan-gong", 300);
        set_skill("xiantian-gong", 300);
        map_skill("force", "xiantian-gong");
        map_skill("dodge", "jinyan-gong");
        map_skill("parry", "taizu-quan");
        map_skill("cuff", "taizu-quan");
        prepare_skill("cuff", "taizu-quan");
        setup();
        carry_object(ARMOR_D("armor/cloth"))->wear();
}

void dest()
{
       object me = this_object();
       write(me->query("name")+"道：这帮臭尼姑，还很难对付。好汉不吃眼前亏，老子先撤了。\n",me);  
       write(me->query("name")+"仓忙逃离。\n",me);  
       destruct(me);
}

void unconcious()
{
    object me = this_object();
    object ob, gold, here=environment(me);
    if(!random(3)) { gold = new("/clone/money/gold");
    gold->move(me);}
    ::unconcious();
    if( objectp(me->query_temp("last_damage_from")) ) {
        ob = me->query_temp("last_damage_from");
        if (ob->query_temp("em_job1/bing1") != me
         && ob->query_temp("em_job1/bing2") != me
         && ob->query_temp("em_job1/bing3") != me
         && ob->query_temp("em_job1/bing4") != me
         && ob->query_temp("em_job1/bing5") != me)
            tell_room(here, "元兵晕倒前气愤地大叫：“我们捉拿峨嵋反贼干别人屁事！”\n");
    }
}

void die()
{
    object me = this_object();
    object ob;
    remove_call_out("dest");
    if( objectp(me->query_temp("last_damage_from"))) {
        ob = me->query_temp("last_damage_from");
        if (ob->query_temp("em_job1/killing") ) {
            if (ob->query_temp("em_job1/bing1") == me ) {
                ob->add_temp("em_job1/killed", 1);
                ob->set_temp("em_job1/bing1", ob);
            }
            else if (ob->query_temp("em_job1/bing2") == me ) {
                ob->add_temp("em_job1/killed", 1);
                ob->set_temp("em_job1/bing2", ob);
            }
            else if (ob->query_temp("em_job1/bing3") == me ) {
                ob->add_temp("em_job1/killed", 1);
                ob->set_temp("em_job1/bing3", ob);
            }
            else if (ob->query_temp("em_job1/bing4") == me ) {
                ob->add_temp("em_job1/killed", 1);
                ob->set_temp("em_job1/bing4", ob);
            }
            else if (ob->query_temp("em_job1/bing5") == me ) {
                ob->add_temp("em_job1/killed", 1);
                ob->set_temp("em_job1/bing5", ob);
            }
        }
    }
    ::die();
}

void setskill(object player, object bing)
{
    int i = random( player->query("combat_exp") / 50000 );
    bing->set("qi", player->query("max_qi") + random(100));
    bing->set("max_qi", player->query("max_qi") + random(100));
    bing->set("eff_qi", player->query("max_qi") + random(100));
    bing->set("neili", player->query("neili")+ random(10));
    bing->set("max_neili", player->query("max_neili")+ random(10));
    bing->set("combat_exp", player->query("combat_exp")+ random(1000));
    bing->set_skill("force", player->query_skill("force", 1)+ i);
    bing->set_skill("dodge", player->query_skill("dodge", 1)+ i);
    bing->set_skill("parry", player->query_skill("parry", 1)+ i);
    bing->set_skill("cuff", player->query("max_pot") - 100 + i);
    bing->set_skill("taizu-quan", player->query("max_pot") - 100 + i);
    bing->set_skill("jinyan-gong", player->query_skill("anying-fuxiang", 1)+ i);
    bing->set_skill("xiantian-gong", player->query_skill("linji-zhuang", 1)+ i);
    bing->set("jiali", player->query("jiali") + random(100));
}


