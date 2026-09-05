// /d/xingxiu/house1.c
// Jay 3/26/96

inherit ROOM;

void create()
{
        set("short", "巴依家客厅");
        set("long", @LONG
这是巴依家的客厅。地上铺着波斯地毯，木架上摆这中原的瓷器。看得出
这家的主人一定很有钱。巴依千里迢迢从西方搬迁过来，凭着精明以及一毛不
拔，又成了这个小镇的首富。
LONG
        );
//        set("no_fight", 1);
        set("exits", ([ 
        "west" : __DIR__"house",
]));
        set("objects", ([
                __DIR__"npc/afanti": 1 ]) );
        set("no_clean_up", 0);
//        set("outdoors", "xingxiuhai")

        setup();
        replace_program(ROOM);
}


