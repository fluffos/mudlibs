// This is a room made by wsl.
inherit ROOM;
void create()
{
    set("short", "长安城大街");
    set("long",@LONG
这里一样热闹非凡，往西是一条小巷，看来行人稀少。东面不时
传来阵阵打铁的声音，原来是间打铁铺。
LONG
);
        set("outdoors","changan");
        set("exits", ([
         "west" :__DIR__"garments",
         "east" :__DIR__"ca8",
         "southwest" :__DIR__"taibaitang",
         "south" :__DIR__"ca",
         "north" :__DIR__"ca9",
]));
    setup();
    replace_program(ROOM);
}
