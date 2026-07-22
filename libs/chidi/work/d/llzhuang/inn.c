inherit ROOM;
void create()
{
        set("short", "枫林小栈");
        set("long", @LONG
这是枫林渡口旁边的一个小酒家，破烂的酒旗在北风中飞舞。北面的路通往
  曾经声名显赫一时的火云山庄。自从绿柳山庄的凶讯传扬开去之后，这里就变得
  非常冷清了。只有要去火云山庄探明究竟的人才会在这里喝点酒，壮一壮胆，攒
足精神。
LONG
        );

        set("exits", ([ /* sizeof() == 2 */
          "north" : __DIR__"dukou",
          "southeast" : __DIR__"road2",
        ]));
        set("objects", ([
           "/d/city/npc/xiaoer2" : 1,
        ]));
        setup();
}

