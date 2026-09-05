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
        set("short", "厨房");
        set("long", @LONG
这里是古墓弟子做饭就餐的地方。这里不大，放了几张桌椅。
几个丫鬟正在布菜。这饭菜可是孙婆婆做的耶！
LONG
        );
        set("exits", ([
                "east" : __DIR__"zoudao1",
        ]));
        set("objects",([
            "/d/shaolin/obj/qingshui-hulu" : 5,
                  names[random(sizeof(names))]: 9,
                names[random(sizeof(names))]: 1,
                names[random(sizeof(names))]: 1,
        names[random(sizeof(names))]: 8,
        ]));
        setup();
        replace_program(ROOM);
}
