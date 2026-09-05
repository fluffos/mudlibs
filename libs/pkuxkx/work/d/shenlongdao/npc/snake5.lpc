inherit NPC;
#include <ansi.h>
#include "/d/shenlongdao/npc/slsnake.h"
void create()
{
        set_name(CYN"眼镜蛇"NOR, ({ "yanjing she", "she", "snake" }) );
        set("race", "蛇类");
        set("age", 5);
        set("long", "这是一条眼镜蛇，它看上去威风凛凛。\n"
        +"他的体背暗褐色或棕褐色，常有均匀相间的白色细横纹，颈部有一对白色眼睛状环纹，当激怒时，前半身竖起，颈部扁平膨大，并发出“呼呼”声，有时可喷出毒液。\n");
        set("attitude", "peaceful");
        set("str", 30);
        set("dex", 30);
        set("limbs", ({ "头部", "身体", "七寸", "尾巴" }) );
        set("verbs", ({ "bite" }) );
        set("combat_exp", 5000+random(50000));
        set("chat_chance",50);
        set("chat_msg", ({
        }) );
        set_temp("apply/attack", 25+random(100));
        set_temp("apply/damage", 20+random(100));
        set_temp("apply/armor", 18+random(100));
        set_temp("apply/defence",20+random(100));
        set("shen_type",-1);
set("score",200);
setup();
}
