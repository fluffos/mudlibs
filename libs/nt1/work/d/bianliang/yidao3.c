inherit ROOM;
#include <ansi.h>;

void create()
{
        set("short", "城外驿道");
        set("long",
"这里是通往大宋京城的驿道，由于连年来战火不止，显得格外地荒凉\n"
"，不时有来往的马匹飞奔而过，溅起一土尘烟，沿途不时有土匪大盗出现，\n"
"还是少作停留的好。\n"
);
        set("outdoors", "xiangyang");
        set("no_fly",1);

        set("exits", ([
                "east"  : __DIR__"yidao2", 
                "north"  : __DIR__"chengmen",
        ]));

        setup();
}

