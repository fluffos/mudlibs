// zhujiangong.c
// pian


inherit ROOM;
void create()
{
        set("short", "铸剑宫");
        set("long", @LONG
这里是雪亭的铸剑宫，一只巨大的融铁炉架在中央，两个大汉
一左一右，推着一只一人多高的风箱。炉中的火苗随着风箱的节奏
飞舞着。这里人来人往，都梦想着打造一把绝世好剑，也好一圆武
林至尊的江湖梦。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                "east" : __DIR__"sstreet1",
]));
//        set("objects", ([
//                __DIR__"npc/foreman": 1,
//                __DIR__"npc/obj/crate": 3,
//        ]));
        set("no_fight", 1);
        setup();
        replace_program(ROOM);
}
