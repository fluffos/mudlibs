 // Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
void create()
{
        set("short", "中道西门");
        set("long", @LONG
北面就是天庭，从天庭射下来的光渗透到这里，把这里照得
很明亮。这里的地势比北边低，洞底下的暗河在这里更加汹涌，
似乎可以听到波涛拍打脚底岩石的声音。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"tzdx",
  "east" : __DIR__"zx",
]));
//        set("objects", ([
     //   __DIR__"npc/fishseller": 1,
//      __DIR__"npc/fishbuyer": 1,
//                        ]) );
        set("item_desc", ([
                "暗河": "暗河汹涌地流着，赤色的河水仿佛地狱中的血池。\n",
                "river": "暗河汹涌地流着，赤色的河水仿佛地狱中的血池。\n",
        ]) );
        set("resource/water",1);
        set("liquid/name","赤水");
        set("liquid/type", "water"); 
        set("indoors", "cave");
        set("coor/x",-50);
        set("coor/y",-30);
        set("coor/z",-20);
        setup();
        replace_program(ROOM);
}       
