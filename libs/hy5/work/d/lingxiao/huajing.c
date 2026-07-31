//LUCAS 2000-6-18
// Room: huajing.c

inherit ROOM;
void create()
{
        set("short","花径");
        set("long",@LONG 
这是一条种满了各色梅花的花径。小径两边，梅花飘香，梅
萼生寒。悠然而赏鉴，梅枝蜿蜒，梅干崎岖，古朴飘逸，兼而有
之。梅树枝干以枯残丑拙为贵，梅花梅萼以繁密浓聚为尚，此处
之景，可谓得矣。
LONG);
        set("outdoors", "lingxiao");
        set("exits",([ /* sizeof() == 1 */
            "east"  : __DIR__"qianyuan",
            "up"  : __DIR__"feihua",  
        ]));
        set("objects", ([
               "/d/lingxiao/npc/xuehe" : 1,
               "/d/lingxiao/obj/mei" : 4,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);

}

