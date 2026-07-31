// Room: /d/dali/wuqidian.c
// Data: 哈迪斯(hades)
// Time: 公元：1999年4月21日，北京时间：17时36分59秒。

inherit ROOM;

void create()
{
        set("short", "打铁铺");
        set("long", @LONG
大理老少都喜欢在这里打造称手的铁器，从火炉中冒出的火光将
墙壁头映得通红，屋子的角落里堆满了各式铁器的完成品或未完成品
，像是锄、铁锤、铲子、长剑等，叮叮当当的声音敲得满屋子响。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"dbdajie2",
]));
        set("objects", ([
                 "/d/city/npc/smith": 1,
]));

        setup();
}

