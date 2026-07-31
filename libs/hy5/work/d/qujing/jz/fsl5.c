//by junhyun@SK

inherit ROOM;

void create ()
{
  set ("short", "封神路");
  set("long", @LONG

弯弯曲曲的一条山路，据说顶端就是封神台。
LONG);
        set("exits",([
                "westdown": __DIR__"fsl4",
                "northup": __DIR__"fsl6",

                ]));
        set("outdoors","jz");
 setup();

}

