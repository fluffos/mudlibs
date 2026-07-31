//by enter xiaoya

inherit ROOM;

void create()
{
        set("short", "青石大道");
        set("long", @LONG
    这是条通向成都的大道。由于此外靠近成都城，所以来往行
人不绝。游玩的客人、卖力的青年、叫卖的小贩。人声嘈杂、喧
闹不已。道路两旁的柳树随风摇摆不定。南面就是成都的北门。
LONG
        );

        set("exits", ([
                "north" : __DIR__"dadao6",
                "south" : __DIR__"northchengmen",
        ]));

        set("outdoors", "chengdu");
        setup();
        replace_program(ROOM);
}


