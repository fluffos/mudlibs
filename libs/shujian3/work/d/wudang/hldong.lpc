// /area/jiangbei/wudang/hldong.c 黄龙洞
// By River@SJ

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIY"黄龙洞"NOR);
        set("long", @LONG
黄龙洞在武当古神道通往金顶的路上，位于紫盖峰悬崖之中。洞内空气干
而不燥，润而不湿，四季清幽凉爽，是历代修练之士向往之地。黄龙实际上是
一个天然的岩屋，经历代修练之士的修建增补，这里有了黄龙殿、真武阁、药
王殿、神泉亭等建筑，使之更具有神秘和深幽的色彩。
LONG
        );

        set("exits", ([
                "westdown" : __DIR__"gsdao6",
                "southup" : __DIR__"taihe",
        ]));

        set("no_clean_up", 0);

        set("objects",([
                __DIR__"npc/youke" : 1,
        ]));

        set("outdoors", "武当");

        setup();
}
