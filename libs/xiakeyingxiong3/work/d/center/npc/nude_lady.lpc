// luonu.c - 裸体女人
// 编程：中山大学  张三丰（Micro）----Micro_Liang@Hotmail.Com           1997.6

#include <ansi.h>

inherit NPC;

#define SET_SKILL       40                      // 定义基本武功的值（随机），自动生成经验
#define SET_SEN         0                       // 定义正气的值

void create()
{
        int n;

        set_name("裸体女人", ({ "nude lady", "lady" }) );

        set("long", @LONG
她是一位裸体的青年女子。
LONG
        );

        set("attitude", "friendly");
        set("gender", "女性" );
        set("age", 20);

        // set("str", 30);                      // 膂力         
        // set("cps", 30);                      // 定力
        // set("cor", 30);                      // 胆识         
        set("per", 28);                         // 容貌
        // set("con", 30);                      // 根骨

        set("combat_exp", SET_SKILL * SET_SKILL * SET_SKILL / 10 * ( 10 + random( 10 ) ) / 10);
        set("SEN", SET_SEN);

        set("env/wimpy", 30);                   //

        n = SET_SKILL + random(10) - 5;         set_skill("unarmed", (n <= 0) ? 1 : n); 
        n = SET_SKILL + random(10) - 5;         set_skill("parry",   (n <= 0) ? 1 : n);
        n = SET_SKILL + random(10) - 5;         set_skill("dodge",   (n <= 0) ? 1 : n);

        setup();
}
