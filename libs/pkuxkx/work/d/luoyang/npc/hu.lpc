inherit NPC;
inherit BANKER;

#include <ansi.h>
void create()
{
        set_name("胡雪源", ({"hu xueyuan", "hu", "xueyuan"}));
        set("title", HIW"巨贾"NOR);      
        set("nickname", HIR"红顶商人"NOR);
        set("gender", "男性");
        set("age", 44);
        set("str", 22);
        set("int", 24);
        set("dex", 18);
        set("con", 18);
        set("qi", 500);
        set("max_qi", 500);
        set("jing", 100);
        set("max_jing", 100);
        set("shen", 0);

        set("combat_exp", 50000);
        set("shen_type", 1);
        set("attitude", "friendly");
        set("env/wimpy", 50);
        set("chat_chance", 2);
        set("chat_msg", ({
        "胡雪源骄傲的说道：本银号已经有上百年的历史，在江南可以说是第一家。\n",
        "胡雪源笑着说道：在本店存钱无利息，取钱收百分之十手续费，客官您看着办吧。\n"
        }));
        set("inquiry", ([
            "name" : "本人就是胡雪岩。",
			
            
       	]) );
        set_skill("unarmed", 50);
        set_skill("dodge", 50);
        set_temp("apply/attack", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 40);
        set("shen_type",1);set("score",1000);setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        npc::init();
        banker::init();
}

