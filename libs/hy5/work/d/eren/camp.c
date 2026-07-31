 inherit ROOM;
void create()
{
        set("short", "营帐");
        set("long", @LONG
帐篷约有十丈见方，用破箱子堆起几个桌椅。两三个彪悍的马贼坐在一侧喝酒，
斜着眼打量着你。另一侧端坐着一个头戴蓝巾，身穿蓝衣的毛脸汉子，一手执着酒
杯，一手把玩着三个卵石般大的黑黝黝的铁蛋，眼光扫过，不怒自威。
LONG
        );
        set("exits", ([ 
                "south" : __DIR__"banditcamp1",
                "north" : __DIR__"innercamp",
                        ]));
        set("objects", ([
                __DIR__"npc/banditleader" : 1,
        ])); 
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
} 
int valid_leave(object obj, string dir){
        int i;
        object *inv;
        if(dir == "north"){
                inv = all_inventory(this_object());
                for (i=0;i<sizeof(inv);i++){
                        if (userp(inv[i]) ||!inv[i]->is_character()
                                ||inv[i]->is_corpse()) 
                                        continue;
                        if (inv[i]->query("dungeon_npc")=="eren")
                                return notify_fail(inv[i]->name()+"挡住了你的路。\n");
                }
        }       
        return 1;
}      
