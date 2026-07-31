 // Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
string door();
void create()
{
        set("short", "南天西路");
        set("long", @LONG
洞顶很低，几乎使人站都站不直。洞顶还一直滴滴哒哒地往下在滴水，水质浑
浊发粘。脚下的暗河发出隆隆的声音，似乎在这里转弯。路尽头是间石屋，隐约可
见昏暗的灯光从门缝中透出。
LONG
        );
    set("exits", ([ /* sizeof() == 4 */
                "north" : __DIR__"tzdx",
//              "south" : __DIR__"ntxm",
        ])); 
        set("item_desc", ([
                "door" : (: door :),
                "门" : (: door :),
                "门缝" : (: door :),
        ]));
        set("objects", ([
        __DIR__"npc/guard2": 1,
                        ]) );
    set("indoors", "cave");
    set("coor/x",-60);
    set("coor/y",-40);
    set("coor/z",-20);
        setup();
} 
string door(){
        object me;
        me = this_player();
        
        tell_object(me, "铁门被一把大铁锁紧紧锁着，门上布满了黄褐色的铁锈。\n");
        return "";
}        
