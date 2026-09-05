
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "麟德殿");
        set("long", @LONG
这里作为举办宴会，观乐赏戏之用，也常用来接见中外使节，
西南面是西内苑，东南面是内朝紫宸殿，东北面是美丽的太液池
畔，西北面皇帝近臣办公场所翰林院。
LONG        );
        
        set("exits", ([
                "southeast" : __DIR__"zichendian",
                "southwest" : __DIR__"yintaimen-2",
                "northeast" : __DIR__"taiye-1",
                "northwest" : __DIR__"hanlinyuan"
        ]));
        
        set("locate_level",3);
        set("changan", 3); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙        
        setup();
}