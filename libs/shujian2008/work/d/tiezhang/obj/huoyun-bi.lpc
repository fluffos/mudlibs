#include <weapon.h>
#include <ansi.h>

inherit BRUSH;
void create()
{
        set_name(HIR"火云笔"NOR,({ "huoyun bi", "bi","brush" }) );
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
        else {

                set("unit", "把");
                set("value", 10000000);
                set("unique", 1);
                set("rigidity", 1);
                set("sharpness", 1);    
                set("material", "steal");
		set("treasure",1);
                 set("wield_maxneili", 1000);
                set("wield_str", 30);
		set("long", HIR"这是一把长二尺三寸的铜笔，通体泛红，如一团火红的云朵，爆射出火红的光芒。"NOR);
                set("wield_msg",HIR"只见红光一闪，$N已经将火云笔抄在了手中。\n"NOR);             
                set("unwield_msg", HIR "$N双手轻拢，红光一隐，将火云笔收入袖中，动作飘逸之至。\n"NOR);               
        }
        init_brush(120);
        setup();
}

int do_wield(string arg)
{
       
        object me = this_player();
        if (!id(arg))
                return 0;      
        if((int)me->query_skill("guiyuan-tunafa", 1) < 120)
                return notify_fail("你无法装备火云笔。\n");
        if((int)me->query_skill("yingou-bifa", 1) < 120)
                return notify_fail("你无法装备火云笔。\n");

}
