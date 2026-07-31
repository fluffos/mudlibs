inherit ROOM;

void create()
{
        set("short", "西寄园");
        set("long", @LONG
这里是附近有名的西寄园,现独孤阀的人住在这里,
西寄园里有口水井!好象有点古怪!

LONG    );

        set("exits", ([
               "north" : "/d/lumaji/pomiao",
                          ]));

        setup();
        replace_program(ROOM);
}

