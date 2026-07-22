// Room: shanlu3.c

inherit ROOM;

void create()
{
        set("short", "山路");
        set("long", @LONG
一条长长的山路展现在你的面前，好象通向什么地方。你不知所踪地走
着，路上不时有野兔窜出，跳到对面的草丛中，又一下不见了。树上几只鸟
儿欢快得对你歌唱，一切都是那麽得祥和。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"shanlu4",
  "northwest" : __DIR__"hongshuiqi",
]));
        set("no_clean_up", 0);
        set("outdoors", "none");

        setup();
        replace_program(ROOM);
}

