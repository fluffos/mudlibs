//quqiao.c 曲桥

#include <ansi.h>
#include <room.h>

inherit ROOM;
void create()
{
        set("short",HIY"曲桥"NOR);
        set("long", @LONG
一座小巧精制的曲桥横跨在池塘上，池塘就这样被一分为二。池塘里的水
碧绿清澈，上面浮着些盛开的睡莲，透过睡莲的缝隙隐约可见几尾红色金鲤在
水中悠闲地缓缓游动。远处靠墙窗下的一丛芭蕉，火红的花朵开的正热闹，给
这宁静的池塘带来无限生机。
LONG
        );
        set("objects",([
             __DIR__"npc/npc"+random(15) : 1,
        ]));

        set("exits", ([
        "south" : __DIR__"zoulang1",
        "southwest" : __DIR__"caodi1",
        "southeast" : __DIR__"caodi2",
        "north" : __DIR__"jiashan",
        "northwest" : __DIR__"quqiao1",
        "northeast" : __DIR__"quqiao3",
        ]));
        
        set("no_death",1);set("bwdhpk",1);
        set("outdoors", "试剑山庄");

        setup();
}

