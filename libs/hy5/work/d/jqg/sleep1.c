// Room: sleeproom1.c

inherit ROOM;

void create()
{
        set("short", "休息室");
        set("long", @LONG
这是间整洁的厢房，因门窗常闭着，光线很昏暗。这是男弟子休息室，房
里别无他物，只有中间放着几张收拾得舒舒服服的大床，床上还有一些棉被，
看着就让人想睡觉。
LONG
        );

        set("sleep_room", 1);
        set("no_fight", 1);
        set("exits", ([
                "south" : __DIR__"lang4",
        ]));         
        setup();
}
