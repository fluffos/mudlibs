// taohuadao/shijianfeng 试剑峰

inherit ROOM;

void create()
{
    set("short", "试剑峰");
    set("long", @LONG
这里是陡峭的山峰，据说每当黄药师在创作新武功时，都要来这演练演练。
地上还有一些石子，黄药师就用这个作为暗器。东边面朝大海，有一块突出
的岩石。
LONG);
    set("exits", ([ /* sizeof() == 1*/
                "eastdown" : __DIR__"yanbi1",
                "eastup" : __DIR__"guanhai",
                ]));

    set("outdoors","taohuadao");
    set("objects", ([
                __DIR__"obj/shizi": 20
                ]));
    setup();
    replace_program(ROOM);
}
