#include <mudlib.h>

inherit WEAPON;

void create()
{
        set_name("colorful feather", "七彩翎羽");
        add ("id", ({"feather" }) );
        set_short("七彩翎羽");
        set_long(@LONG
一根六尺长的七彩羽毛，翎毛坚硬而且四侧锐利异常；羽毛尾端有段硬翮，刚好可
以用手握住。
LONG);
        set("type", "longblade");
        set("weapon_class",50);
        set("min_damage", 30 );
        set("max_damage", 55);
        set("nosecond",1);
        set("weight", 100);
        set("value", ({ 4500, "silver" }) );
}
