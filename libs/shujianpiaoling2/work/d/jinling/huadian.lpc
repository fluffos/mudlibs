//jinling  huadian.c
inherit ROOM;

void create()
{
        set("short", "花店");
        set("long", @LONG
这里是金陵城里唯一的一家花店，不仅花色齐全，品种繁多，而且可
以不远千里，为您送货上门。由于这里服务一流加上各类鲜花都是上好的
名品，所以一般价格较高，主要是作为传达情意的名贵礼品。
LONG
        );
        set("exits", ([/* sizeof() == 4 */
           "east":__DIR__"nanjie1",

]));
        set("objects", ([
		__DIR__"npc/roseseller" : 1,
             __DIR__"npc/girl" : 1,
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}