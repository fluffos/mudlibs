inherit ROOM;

void create()
{
        set("short", "西寄园");
        set("long", @LONG
这里是长安有名的西寄园,现独孤阀的人住在这里,
西寄园里有口水井!好象有点古怪!

LONG    );

        set("exits", ([
               "west" : "/d/changan/zao",
                          ]));

        setup();
        replace_program(ROOM);
}

