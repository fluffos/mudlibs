// Room: fanting.c
// Date: by yuer
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
这里是明教弟子就餐的地方。饭厅不大，放了几张桌椅。
几个明教弟子正在布菜。
LONG
        );
        set("exits", ([
                "east" : __DIR__"zoulang1",
        ]));
        set("objects",([
                "/d/shaolin/obj/qingshui-hulu" : 1,
                names[random(sizeof(names))]: 1,
                names[random(sizeof(names))]: 1,
        ]));
        setup();
        replace_program(ROOM);
}

