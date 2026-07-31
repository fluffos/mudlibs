// junzi jian 君子剑

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name( BLU"君子剑"NOR,({ "junzi jian", "junzi" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 25000);
                set("material", "steel");
                set("long", BLU"此剑乌黑的剑身，没半点光泽，就似一段黑木。刻着君子二字。与淑女剑一般
长短，全无二致。双剑齐出，寒气大至。只是此剑既无尖头，又无剑锋，圆头
钝边，倒有七分似一条薄薄的木鞭。\n"NOR);
                set("wield_msg", HIY "$N缓缓抽出君子剑，只觉轻飘飘无甚份量，到是一阵凉意凛然逼人，令人
莫可忽视。$N举剑虚刺，但觉轻重合手，极是灵便。\n"NOR);
                set("unwield_msg", BLU "$N作个剑势，将君子剑缓缓插回剑鞘，当真气度非凡。\n" NOR);
                set("unequip_msg", BLU "$N手腕上扬，一道黑光跃入空中，你身形未动，长袖飘飘，待黑光消失，
宝剑已然入鞘。\n" NOR);
        }
        init_sword(450);
        setup();
}
