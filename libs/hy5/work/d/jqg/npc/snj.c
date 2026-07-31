//shunu jian

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
        set_name( RED"淑女剑"NOR,({ "shunu sword", "shunu" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 25000);
                set("material", "steel");
                set("long", BLU"此剑乌黑的剑身，没半点光泽，就似一段黑木。刻着淑女二字。与君子剑一般
长短，全无二致。双剑齐出，寒气大至。只是此剑既无尖头，又无剑锋，圆头钝边，倒有七分似一条薄薄的木鞭。\n"NOR);
                set("wield_msg", RED "$N合手作个揖，缓缓抽出淑女剑，只觉轻飘飘无甚份量，到是一阵凉意
凛然逼人，另人莫可忽视。$N举剑虚刺，但觉轻重合手，极是灵便。\n"NOR);
                set("unwield_msg", RED "$N画个剑势，将淑女剑缓缓插回剑鞘，风姿嫣然。\n" NOR);
                set("unequip_msg", BLU "$N手腕上扬，一道黑光跃入空中，你身形未动，长袖飘飘，待黑光消失，
宝剑已然入鞘。\n" NOR);
        }
        init_sword(450);
        setup();
}
