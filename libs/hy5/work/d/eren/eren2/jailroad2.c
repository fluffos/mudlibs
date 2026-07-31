 inherit ROOM;
void create()
{
        set("short", "地道");
        set("long", @LONG
这儿已不能说是道路，只是一条又湿又滑的地道，洞顶很低，需弯腰
才能通过。两侧有许多岩洞，黑咕隆咚地不知深浅，没有一盏灯，没有一
点声响，脚下悉悉簌簌不断有小动物窜过，偶尔踩到，便是吱的一声尖叫。
LONG
        );
        set("exits", ([ 
                "south" : __DIR__"jailroad1",
                "north" : __DIR__"jailroad3",
                "east" : __DIR__"jail2",
        ]));
        set("objects", ([
                __DIR__"npc/star_pig" : 1,
                __DIR__"npc/star_dog" : 1,
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}  
int valid_leave(object obj, string dir){
        int i;
        object *inv;
        if(dir == "north" || dir=="east"){
                inv = all_inventory(this_object());
                for (i=0;i<sizeof(inv);i++){
                        if (userp(inv[i]) ||!inv[i]->is_character()
                                ||inv[i]->is_corpse()) 
                                        continue;
                        if (inv[i]->query("dungeon_npc")=="eren2")
                                return notify_fail(inv[i]->name()+"觉得你又在做梦了。\n");
                }
        }       
        return 1;
}
