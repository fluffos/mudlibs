// Room: /wizhome/lanzhou/guangchang.c
// Data: xws 98/10/13

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "中央广场");
        set("long", @LONG
这里是兰州城的中央广场。由于兰州是西北地区的交通要道，不论到西域还
是中原都要经过这里，所以各地的行人来来往往，你不时可以看见一些西域商人
带着驼队匆匆向东走去。
这里是城市的正中心，有一个很宽阔的广场，由于这里风沙很大，所以铺着
青石的地面经常铺着一层黄沙。一些游手好闲的人在这里溜溜达达，经常有一些
西域艺人在这里表演。由于这里是由中原到西域的最后一个大城，各地的旅人都
在这里进行最后的补给。这里人声鼎沸，许多小贩争着向行人兜售着自己的商品，
一派热闹景象。
LONG
        );
        set("no_sleep_room",1);
        set("outdoors", "lanzhou-city");


        set("exits", ([
                "east"   : __DIR__"dongdajie1",
                "south"  : __DIR__"nandajie1",
                "west"   : __DIR__"xidajie1",
                "north"  : __DIR__"beidajie1",
        ]));

        set("objects", ([
        __DIR__"npc/liumang" : 2,
        __DIR__"npc/liumangtou" : 1,    
        __DIR__"npc/xiaofan" : 1,
  	]));

        setup();
}
