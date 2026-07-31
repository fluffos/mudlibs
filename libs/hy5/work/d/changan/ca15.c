
// This is a room made by wsl.
inherit ROOM;
void create()
{
    set("short", "长安乐坊分店");
    set("long", @LONG
这里是长安城一家有名的娱乐场所。当夜幕降临后，这里就格外
热闹。进进出出的客人有达官贵人，南来北往的商旅，浪迹天涯的游
子，三五成群的兵士，有时也能看见一些作俗客打扮的僧人或道士。
LONG);
    set("exits", ([
       "west" :__DIR__"ca12",
//       "up" :__DIR__"yuefang",
]));
        set("objects", ([
          __DIR__"npc/yuezi" : 1,
]));
    setup();
    replace_program(ROOM);
}
