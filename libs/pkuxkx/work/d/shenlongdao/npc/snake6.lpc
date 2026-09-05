inherit NPC;
#include <ansi.h>
#include "/d/shenlongdao/npc/slsnake.h"
void create()
{
        set_name(YEL"尖吻蝮蛇"NOR, ({ "jianwenfu she", "she", "snake" }) );
        set("race", "蛇类");
        set("age", 5);
        set("long", "这是一条眼镜蛇，它看上去威风凛凛。\n"
        +"他的头部呈明显三角形，吻端尖，向前上方翅起。体躯粗短，尾短而尖，尾尖最后一枚鳞片侧扁尖长，俗称“佛指甲”。\n");
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
