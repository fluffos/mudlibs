// 一团和气 /d/city/chuzhou/npc/obj/yituanheqi.c
// by lala, 1997-12-16

inherit ITEM;

void create()
{
        set_name( "一团和气", ({"yituan heqi", "heqi", }));
        set_weight(50);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", @LONG
一个泥的胖和事佬儿，如果有人吵嘴了，这件无锡特产倒是不错的礼物。
LONG
    );
                set("unit", "个");
                set("value", 170);
        }
        setup();
}
