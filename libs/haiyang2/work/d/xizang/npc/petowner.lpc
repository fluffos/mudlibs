#include <ansi.h>
inherit NPC;

void create()
{
        set_name("潇江", ({ "xiaojiang" }) );
        set("gender", "女性" );
        set("age", 22);
        set("long","潇江姓顾，后嫁给一小土财主，财主过世后就开使每天背一个小筐卖（ｙａｎｇ）宠物\n");
        set("combat_exp", 5);
        set("chat_chance", 15);
        set("chat_msg", ({
                (: random_move :)
        }) );
        set("attitude", "friendly");
        setup();
        carry_object("/clone/misc/cloth")->wear(); 
} 
