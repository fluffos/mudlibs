//by junhyun@SK
// /d/qujing/jz/river.c

inherit ROOM;

void create ()
{
  set ("short", "山路");
  set("long", @LONG

弯弯曲曲的一条山路，路旁尽是些花儿、草儿，你不禁深深的
呼了口气，你的脚下是五彩的鹅卵石。
LONG);
        set("exits",([
                "westup": __DIR__"shanmen",
                "eastdown": __DIR__"shanlu1",
                  "southup": __DIR__"fsl1",

                ]));
        set("outdoors","xy1");
 setup();

}

