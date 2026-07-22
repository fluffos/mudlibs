inherit ROOM;

void create()
{
    set("short", "花坛");
    set("long", @LONG
在花坛中养着各种不知名的花卉,香气清新淡雅很是舒适.花坛四周
用青砖铺地,在四个方位各有一个用白汉玉雕刻的瑞物,分别是黄龙,
麒麟，玄龟和松鹤.
LONG);
    set("exits", ([
     "north" : __DIR__"gate",
     "southwest" : __DIR__"hufatang1",
     "southeast" : __DIR__"hufatang2",
    ]));
    setup();
    replace_program(ROOM); 
}
