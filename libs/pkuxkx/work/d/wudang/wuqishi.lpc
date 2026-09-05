// wuqishi.c 武器室
inherit ROOM;
void create()
{
       set("short","武器室");
        set("long", @LONG
这里是武器室，旁边架子上整齐地摆放着几把竹剑，武当弟子可以用
来练功。
LONG
        );
        set("exits", ([
           "south" : __DIR__"donglang",
        ]));
        set("objects", ([
                "/d/village/obj/zhujian" : 3]));
        set("no_fight", 1);
        setup();
        replace_program(ROOM);
}
