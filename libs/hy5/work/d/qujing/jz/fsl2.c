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
                "northdown": __DIR__"fsl1",
                "westup": __DIR__"fsl3",

                ]));
        set("outdoors","jz");
 setup();

}

