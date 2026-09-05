inherit NPC;
#include <ansi.h>
#include "/d/shenlongdao/npc/slsnake.h"
void create()
{
        set_name(YEL"金环蛇"NOR, ({ "jinhuan she", "she", "snake" }) );
        set("race", "蛇类");
        set("age", 5);
        set("long", "这是一条金环蛇，它看上去威风凛凛。\n"
        +"他的体较粗大，通身有黑黄相间的环纹，黑环与黄环几乎等宽，宽大的环纹围绕背腹面一周。背脊隆起呈明显的棱脊。尾略呈三棱形，末端扁而圆纯。\n");
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
        switch(random(3))
        {
                case 0:
                        carry_object("/d/shenlongdao/obj/sherou");
                        break;
                case 1:
                        carry_object("/d/shenlongdao/obj/shepi");
                        break;
                case 2:
                        carry_object("/d/shenlongdao/obj/shedan");
                        break;
        }

}
