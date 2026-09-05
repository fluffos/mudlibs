inherit NPC;
#include <ansi.h>
#include "/d/shenlongdao/npc/slsnake.h"
void create()
{
        set_name(HIC"锦蛇"NOR, ({ "jin she", "she", "snake" }) );
        set("race", "蛇类");
        set("age", 5);
        set("long", "这是一条锦蛇，它看上去威风凛凛。\n"+"它的背面灰色或黄褐色，枕部有一黑色横纹，头侧有三条辐射状黑线纹，体前半段或2／3有4条黑色纵纹，上面一对比较宽，腹面淡褐色。\n");
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
