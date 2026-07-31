#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short", "三清宫大院");
        set("long", @LONG
用石板铺成的地面上，被打扫得干干净净。左面是厢房，
道士们起居的地方。右面是厨房，从那里飘出阵阵饭香。正面
是一座大殿，金色的大匾上写着＂三清殿＂。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                "north" : __DIR__"da_dian",
                "east" : __DIR__"kitchen",
                "west" : __DIR__"xiang_fang",
]));
        set("outdoors", "taoguan");
        set("coor/x",-20);
        set("coor/y",2100);
        set("coor/z",80);
        setup();
} 
void init()
{
        if(query("exits/south")) {
        set("item_desc", ([
                "door": "铜钉的大门，门是开着的。\n",
                "门": "铜钉的大门，门是开着的。\n",
        ]) );
        add_action("do_pull", "pull");
        }
        else {
        set("item_desc", ([
                "door": "铜钉的大门，门是关着的，你可以拉(pull)门。\n",
                "门": "铜钉的大门，门是关着的，你可以拉(pull)门。\n",
        ]) );
        add_action("do_pull", "pull");
        }
} 
int do_pull(string arg)
{
        object room, me; 
        if( arg=="door" || arg == "门") {
                me = this_player();
                if(query("exits/south")) {
                        write("门是开着的！\n");
                }
                else {
                set("exits/south", __DIR__"taoguan");
                set("item_desc", ([
                 "door": "铜钉的大门，门是开着的。\n",
                 "门": "铜钉的大门，门是开着的。\n",
                 ]) );
                message_vision("$N打开大门。\n", me);
                if( room = find_object(__DIR__"taoguan") ) {
                        message("vision", "大门从里面打了开来。\n", room);
                        room->set("exits/north", __FILE__);
                        call_out("closedoor", 5, room);
                }
                }
        }
        else {
                 write("你要开什么？\n");
        }
        return 1;
} 
int closedoor(object room)
{
        message("vision", "大门又被关上了。\n", room);
        message("vision", "大门又被关上了。\n", this_object());
        set("item_desc", ([
                "door": "铜钉的大门，门是关着的，你可以拉(pull)门。\n",
                "门": "铜钉的大门，门是关着的，你可以拉(pull)门。\n",
        ]) );
        room->delete("exits/north");
        delete("exits/south");
}    
