// 乱石迷宫 /d/menpai/shennong/luanshi5.c

inherit ROOM;

string *exit = ({
"north",        "south",        "east",         "west", 
"eastup",       "eastdown",     "westup",       "westdown",
"northup",      "northdown",    "southup",      "southdown",
"northeast",    "northwest",    "southeast",    "southwest", 
});



void create()
{   
    set("short",    "乱石堆");
    set("long", @LONG
这里到处都是一堆一堆的乱石，乱石间是齐腰高的荒草，看起来是人迹罕至。
但是如果仔细寻找的话，在荒草乱石只见似乎有条羊肠小道蜿蜒延伸，不知道通
向哪里。
LONG
    );
    set("exits",    ([
        "southwest"                 :   __DIR__"luanshi_hou",
        exit[random(sizeof(exit))]  :   __DIR__"luanshi" + random(6),
        exit[random(sizeof(exit))]  :   __DIR__"luanshi" + random(6),
        exit[random(sizeof(exit))]  :   __DIR__"luanshi" + random(6),
        exit[random(sizeof(exit))]  :   __DIR__"luanshi" + random(6),
    ]) );
    set("outdoors", "wuliang");
    setup();
}

