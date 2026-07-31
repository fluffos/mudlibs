//keshang.c.客商
//date:1997.8.24
//by dan

#include <ansi.h>
inherit NPC;

void create()
{
    set_name(MAG"客商"NOR, ({ "ke shang" }));
    set( "age", 28 + random( 5 ) );
    set("title","大食");
    set("gender", "男性");
    set("long", "他是一名大食客商，从事宋汴京和大食之间的丝绸买卖，刚刚被马鹞军搜查过. \n");
    set("str",40);
    set("per", 25);
    set("combat_exp", 5000);
    set("max_jing",300);
    set("max_qi",700);
        set_skill("unarmed", 80+random(180));
        set_skill("sword", 80+random(180));
        set_skill("parry", 80+random(180));
        set_skill("dodge", 180+random(180));
        set_skill("kuang-jian", 80+random(380));
        
        map_skill("sword", "kuang-jian");
        map_skill("parry", "kuang-jian");
        set_temp("apply/attack", 20);
        set_temp("apply/defense",50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 20);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.leitingpili" :),
                (: perform_action, "sword.kuang" :),
        }) );


    set("chat_chance",5);
    set("chat_msg",({
        (:random_move:),
    }) );

    setup(); 
    carry_object(__DIR__"obj/cloth3")->wear();
    carry_object(__DIR__"obj/zao_sitao")->wear();
    carry_object(__DIR__"obj/pixue")->wear(); 
}

