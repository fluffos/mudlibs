
// mei_po.c
#include <ansi.h>

inherit NPC;

string marry();
string unmarry();

void create()
{
        set_name("媒婆", ({ "mei_po" }) );
        set("title", "红娘庄");
        set("gender", "女性" );
        set("age", 43);
        set("long",
                "一位精明能干的老媒婆\n");
        set("combat_exp", 10000);
        set("attitude", "friendly");
        set("inquiry", ([
                "婚约" : "是啊... 这里就可以缔结和解除婚约",
        ]) );
        set_skill("literate", 70);
        set_skill("dodge", 500);
        set_skill("unarmed", 300);
        setup();
       // add_money("gold", 1);
        carry_object("/clone/misc/cloth");
}
