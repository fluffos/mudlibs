//by junhyun@SK
// /d/qujing/jz/river.c

inherit ROOM;

void create ()
{
  set ("short", "封神路");
  set("long", @LONG

弯弯曲曲的一条山路，据说顶端就是封神台。
LONG);
        set("exits",([
                "eastdown": __DIR__"fsl2",
                "northup": __DIR__"fsl4",

                ]));
        set("outdoors","jz");
 setup();

}

