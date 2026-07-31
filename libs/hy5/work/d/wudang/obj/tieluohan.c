// tieluohan.c 铁罗汉

#include <weapon.h>
#include <ansi.h>

inherit HAMMER;

void create()
{
        set_name(HIY"铁罗汉"NOR,({"tie luohan","tieluohan"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "尊");
                set("value", 100);
                set("no_pawn",1);
                set("material", "steel");
                set("long", "这是一尊制做精巧的双人铁罗汉。按动开关，他们就会演练一套罗汉拳!\n");
                set("wield_msg", "$N双手抓起一尊$n，笑嘻嘻地把玩着。\n");
                set("unequip_msg", "$N放下手中的$n。\n");
        }
        init_hammer(5);
        setup();
}                                                   
