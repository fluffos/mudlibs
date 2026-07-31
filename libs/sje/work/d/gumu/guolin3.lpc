// guolin3.c By River 98/09
#include <ansi.h>
inherit ROOM;

void create()
{
       set("short",HIG"果林"NOR);
       set("long",@LONG
转过山腰，出现一大片果林。果树高大茂盛，枝叶繁密，累累鲜果，鲜嫩
诱人。清风拂叶，沙沙作响，更令这群果随风招摇起舞，送来阵阵果香。但听
密林深处，杜鹃儿间或轻啼。
LONG );

       set("outdoors","古墓");

       set("exits" ,([
             "east" : __FILE__,
             "south" : __DIR__"guolin4",
             "west" : __FILE__,
             "north" : __FILE__,
       ]));

       setup();
}
