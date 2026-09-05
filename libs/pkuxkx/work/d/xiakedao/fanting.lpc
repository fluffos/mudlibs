// fanting
// by aiai

inherit ROOM;
string* names = ({
        "/d/shaolin/obj/mala-doufu",
        "/d/shaolin/obj/bocai-fentiao",
        "/d/shaolin/obj/shanhu-baicai",
        "/d/shaolin/obj/liuli-qiezi",
});
void create()
{
        set("short", "饭厅");
        set("long", @LONG

    这里是就餐的地方。饭厅不大，放了几张桌椅。
灶上锅内的反饭菜发出诱人的香味，丝丝白气从锅
内的缝中飘出，令人垂涎欲滴。
LONG
        );
        set("exits", ([
                "east" : __DIR__"backyard",
        ]));
        set("resource/water", 1);
        set("objects",([
                "/d/shaolin/obj/qingshui-hulu" : 1,
                names[random(sizeof(names))]: 2,
                names[random(sizeof(names))]: 2,
        ]));
        setup();
        replace_program(ROOM);
}

