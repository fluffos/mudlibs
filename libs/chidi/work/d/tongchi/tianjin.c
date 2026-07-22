inherit ROOM;
void create()
{
          set("short", "天井");
        set("long", @LONG
这里是通吃帮的练武场。由无数块巨大的花岗岩石板铺就。
上千年的踩踏已使得这些石板如同镜子般平整光滑。练武场中间
竖立着不少木人。十来个弟子正在练习武艺。南边是议事厅。
LONG
        );
        set("exits", ([
                "north" : __DIR__"xiefj",
                "south" : __DIR__"yishi",
                  "west" : __DIR__"sleep_room",
                  "east" : __DIR__"weapon_room",
        ]));
        set("objects", ([
     "/d/shaolin/npc/mu-ren" : 10,
        ]));
        set("outdoors", "city");
        setup();
        replace_program(ROOM);
}
