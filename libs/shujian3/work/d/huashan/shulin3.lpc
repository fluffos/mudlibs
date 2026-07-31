// Room: /d/huashan/shulin2.c
// Date: Look 99/03/25

inherit ROOM;

void create()
{
        set("short", "松树林");
        set("long", @LONG
你眼前骤然一黑，朦胧中，只见左右前后，到处都是铺天盖地的松树林。
几十丈高的大松树簇在一块，密实的枝叶象一蓬蓬巨伞般伸向天空，把阳光遮
得丝毫也无。尺把厚的松针积在地上，一脚踩下去，半天拔不出来。你似乎迷
失了方向，象没头苍蝇般到处乱闯。
LONG);

        set("exits", ([
                "east" : __DIR__"shulin3",
                "south" : __FILE__,
                "west" : __DIR__"shulin1",
                "north" : __FILE__,
        ]));

        set("outdoors", "华山");
        set("coor/x",50);
  set("coor/y",100);
   set("coor/z",0);
   setup();
}

void init()
{
       set("exits/east", __DIR__"shulin"+(1+random(4)));
       set("exits/south", __DIR__"shulin"+(1+random(4)));
       set("exits/north",  __DIR__"shulin"+(1+random(4)));
       set("exits/west",  __DIR__"shulin"+(1+random(4)));
}

