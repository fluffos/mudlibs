// Room: /d/chengdu/shudao1
// netkill /98/8/16/


inherit ROOM;

void create()
{
        set("short", "青石路" );
        set("long", @LONG
一条青石铺成的路，平坦宽阔，路的两面。绿树成荫，来往的人
累了都到树下去乘乘凉，歇歇脚，一些小贩也乘机在这里买点吃喝的
东西。
LONG
        );
        set("exits", ([
  "east" : "/d/jingzhou/jzximen",
  "west" : __DIR__"shudao2",
   ]));

        set("no_clean_up", 0);
        set("outdoors", "chengdu");

        setup();
        replace_program(ROOM);
}

