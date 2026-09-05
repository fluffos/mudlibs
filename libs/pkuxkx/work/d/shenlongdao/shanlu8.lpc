// Room: /shenlongjiao/shanlu8.c
// kiden 06/08/25

inherit ROOM;

void create()
{
        set("short", "山道");
        set("long", @LONG
沿着狭窄的山道继续攀行，你不觉气喘吁吁。你抬头看去，峰顶就在前方，你不禁加快了脚步。

LONG
        );
        set("outdoors", "shenlongdao");

        set("exits", ([
                "eastdown" : __DIR__"shanlu7",        
                "northup" : __DIR__"fengding",                 
        ]));

   set("objects", ([
//         __DIR__"npc/liumang":1,
//        __DIR__"npc/rascal":1,
       ]));
        setup();
        replace_program(ROOM);
}

