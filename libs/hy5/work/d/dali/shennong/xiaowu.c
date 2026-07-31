// 小屋内 /d/menpai/shennong/xiaowu.c

inherit ROOM;



void create()
{   
    set("short",    "小屋内");
    set("long", @LONG
你站在小屋内，从天窗射进来太阳柔和的光芒，把小屋照的很亮。屋里放着
张木桌子和几条板凳，上面放着几只茶碗和一些食物。看来是专门用来给路人歇
脚准备的。墙角有一张茅草铺成的床铺使你一进来就有一种回到家的感觉。
LONG
    );
    set("exits",    ([
            "out"   :   __DIR__"wuqian"   
    ]) );
    set("sleep_room", 1);
    set("objects",  ([
        "/d/city/npc/obj/baozi" : 5,
		"/d/city/npc/obj/jitui" : 2,
		"/d/city/npc/obj/jiudai" : 2,

    ]) );
    setup();
}

