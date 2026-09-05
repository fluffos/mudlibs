// Room: /d/shaolin/fanting.c
// Date: YZC 96/01/19
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
这里是华山弟子就餐的地方。饭厅不大，放了几张桌椅。
几个华山弟子正在布菜。
LONG
        );
        set("exits", ([
                "north" : __DIR__"houhuayuan1",
        ]));
        set("objects",([
                "/d/shaolin/obj/qingshui-hulu" : 1,
                names[random(sizeof(names))]: 1,
                names[random(sizeof(names))]: 1,
        ]));
        setup();
        replace_program(ROOM);
}
