 //Created by justdoit at May 2001
//All Rights Reserved ^_^
inherit ROOM;
void create()
{
        set("short", "白龙湫");
        set("long", @LONG
随着潺潺的流水声愈来愈响，眼前峰回路转，岚影山光；飞瀑声声，彩虹横空；
潭水碧蓝，树绿花红；而四面环山中一线白练般的瀑布飞泻而下，但见五丈以上尚
是水，十丈以下全是烟，况复百丈至千丈，水云烟雾难分焉。山涧似玉龙横空，滚
滚而下，倾入一方不大的深潭之中，潭水却不漫溢，但一股寒意却无孔不入，沁人
心髓。
LONG
           );
        set("exits", 
           ([ 
       "north" : __DIR__"qingbi",
       "southwest" : __DIR__"shangu",
        ]));
    set("objects", 
       ([ 
//           __DIR__"obj/sand" : 1, 
        ]));
        set("outdoors", "baiyun");
        set("coor/x",10);
    set("coor/y",-1680);
    set("coor/z",0);
    setup();
    replace_program(ROOM);
}   
