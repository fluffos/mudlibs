// /d/wudang/shibapan.c 十八盘
// by ydh
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",HIY"十八盘"NOR);
        set("long", @LONG
你正在爬一个很大的斜坡，俗称十八盘，大石阶一级一级笔直而上，颇费
脚力。坡上有几家山民开的小店，游客到此略坐小息再往上爬。向前十里之后
即是武当重地三清殿了。
LONG
        );
        set("exits", ([
                "southup" : __DIR__"fuzhen",
                "northdown" :__DIR__"caihong",
        ]));
        set("outdoors","武当");
        setup();

}
