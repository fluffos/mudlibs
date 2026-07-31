// This is a room made by wsl.

inherit ROOM;

void create()
{
    set("short", "城墙");
    set("long", @LONG
以城墙为主体，包括护城河、吊桥、闸楼、箭楼、正楼、角楼、
女儿墙垛口、城门等一系列军事设施，构成长安城严密完整的防御体
系。
LONG
);
        set("outdoors","changan");
    set("exits", ([
       "down":__DIR__"dongmen",
]));
    setup();
    replace_program(ROOM);
}
