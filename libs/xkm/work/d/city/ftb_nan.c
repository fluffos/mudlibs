//write by bright
// ftb girl sleep_room

inherit ROOM;

void create()
{
        set("short","男休息室");

        set("long",@LONG
这ㄦ是斧头帮专门为男子建的休息室,地方虽小,但却十分整洁,里面
有一张桌子和几张床，床上的被子折的整整齐齐。
LONG);
                       
        set("exits",([ 
        "east" : __DIR__"ft_datang",
        "south" : __DIR__"nan_lg",             
        ]));
        set("cost",0);
        set("sleep_room", 1);
        set("no_fight", 1);
        setup();
}

int valid_leave(object me, string dir)
{
        object *inv;
        int i;


        inv = all_inventory(me);

        if ( dir == "east" || dir == "south" ) {
                for (i=0; i<sizeof(inv); i++) {
                        if (inv[i]->is_character())
                        return notify_fail("你不能带着其他玩家离开休息室。\n");
                }
        }

        return ::valid_leave(me, dir);
}
