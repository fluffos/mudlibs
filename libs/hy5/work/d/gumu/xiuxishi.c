// xiuxishi.c 休息室
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "休息室");
        set("long", @LONG
这是间很大的房间，光线非常昏暗。房里没有什么别的东西，只
有中间放着一张收拾得舒舒服服的大床，床上的被褥也整理得整整洁
洁，看着就让人想睡觉。
LONG
        );

        set("exits", ([
                "southeast" : __DIR__"xiaowu1",
                "south" : __DIR__"liangong",
                "east" : __DIR__"qianting",
        ]));

        set("sleep_room",1);
        set("no_fight",1);
        set("no_steal",1);

        setup();
}
