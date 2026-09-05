inherit NPC;
#include <ansi.h>
#include "/d/shenlongdao/npc/slsnake.h"
void create()
{
        set_name(WHT"银环蛇"NOR, ({ "yinhuan she", "she", "snake" }) );
        set("race", "蛇类");
        set("age", 5);
        set("long", "这是一条蝮蛇，它看上去威风凛凛。\n"
        +"它的头部稍椭圆，背鳞通身15行，脊鳞扩大呈六角形，体背具有黑白相间的横纹，黑色横纹较宽，白色横纹较窄，腹部白色，尾较细长，\n");
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
