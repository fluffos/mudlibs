// jinshesword 金蛇剑

#include <weapon.h>
#include <ansi.h>

inherit SWORD;
inherit F_UNIQUE;

void create()
{
              set_name(HIY"金蛇剑"NOR,({ "jinshe sword", "sword","jinshe" }) );
        set_weight(23000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 1);
                set("rigidity", 2);
                set("sharpness", 2);
                set("material", "steel");
                set("weapon_prop/dodge", 2);
                set("weapon_prop/parry", 3);
                set("treasure",1);
                set("wield_neili", 500);
                set("wield_maxneili", 1200);
                set("wield_str", 24);
                set("long", "这把剑犹如一条盘蛇，剑光灿灿，甚为沉重 。\n剑身上一道血痕，发出碧油油的暗光，极是诡异。\n");                
                set("unwield_msg", HIY "$N随手一挥，手中金蛇剑已不见踪影。姿态潇洒无比。\n" NOR);
                set("wield_msg", HIY"$N微一舞动，一道耀眼的金光绕着$N全身上下游走，光芒顿住，$N手中
已多了柄弯弯曲曲的奇形宝剑。剑身的寒光映照出$N脸上浮现出诡异神情。\n"NOR);
        }
     init_sword(105);
        setup();
}
