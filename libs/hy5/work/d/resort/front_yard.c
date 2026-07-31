 inherit ROOM;
void create()
{
        set("short", "山庄前院");
        set("long", @LONG
这里的装饰古朴而幽雅。院子的四周斑斑点点的种着黄色的枚瑰。
院子的左角长着颗精心修剪过的梅花树，每当天寒地冻之时，雪白而
又透着粉红的梅花竞项开放。
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"gate",
  "north" : __DIR__"bamboo_hall",
]));
        set("outdoors", "resort"); 
        set("coor/x",-1230);
        set("coor/y",50);
        set("coor/z",-10);
        setup();
        replace_program(ROOM);
}   
