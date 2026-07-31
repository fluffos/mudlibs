 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "上山路");
        set("long", @LONG
路随山转，景随山变，这儿方圆一里内有近百泉眼，称为“药池沸泉”，据说
不同的泉水都有不同的疗效，当地人把它们分为明目泉、健胃泉、洗脚泉等。远眺，
可见藏羚羊、野牛、鹿、熊、狼、麝等动物劲走攀崖绝技，近处有马鸡、松鸡、黄
鸭轻歌戏水、恬适醉人。
LONG
        );
        set("exits", ([ 
                "southwest" : __DIR__"mugecuo",
                "northeast":  __DIR__"linchang1",
                "westdown":   __DIR__"river",
        ]));
        set("objects", ([
        ]) );
        set("outdoors", "zangbei");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup(); 
} 
