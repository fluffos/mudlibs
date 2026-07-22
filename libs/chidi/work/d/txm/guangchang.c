inherit ROOM;

void create()
{
        set("short", "广场");
        set("long", @LONG
这里是一大片用青砖拼成的广场，是铁血盟大多数弟子聚集的地
方。广场中央竖着块布告木板，一边的地上则有块石碑(shibei)，上
面刻着铁血盟盟旨及盟规等。广场的西面是休息室和厨房，东面则是
演武厅和兵器室。北面是碧血铁胆堂前厅，南面就是出去的大门。
LONG );
        set("item_desc", ([ /* sizeof() == 1 */
                "shibei": "
                   ★侠★义★行★天★下★

                           \n",
        ]));
    //    set("no_fight",1);
        set("exits", ([ /* sizeof() == 2 */
                "north"    : __DIR__"damen",
                "south" : __DIR__"juxieting",
        ]));
        set("objects", ([ /* sizeof() == 1 */
 //               __DIR__"npc/xuncha" : 1,
                __DIR__"npc/npcdoga" : 1,
        ]));
        set("no_clean_up", 0);
        set("outdoors", "txm");


        setup();
        call_other("/d/board/txm_b","???");
        replace_program(ROOM);
}

