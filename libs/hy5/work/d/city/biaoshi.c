// Room: /city/beimen.c
// YZC 1995/12/04 

#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
        set("short", "龙门镖局");
        set("long", @LONG
    这里是扬州城的镖局。一座结构宏伟的建筑前，左右石坛上各插着一
根两丈多高的旗杆，杆上青旗飘扬。右首旗子用金线绣着一头张牙舞爪的
狮子。左首旗子上写着“龙门镖局”四个黑字，银钩铁划，刚劲非凡。镖
局老板正打量着你能否为他做点事。
LONG);

        set("exits", ([
                "north" : __DIR__"ximen",
        ]));
       set("no_beg",1);
      set("no_fight", 1);

        set("outdoors", "city");
        setup();
}
