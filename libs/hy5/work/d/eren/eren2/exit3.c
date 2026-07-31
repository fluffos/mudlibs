 inherit ROOM;
void create()
{
        set("short", "泥道");
        set("long", @LONG
再往上，道路愈加泥泞，已需手脚并用，洞顶上滴滴答答地往下淌水，
竟如下起了小雨，耳边隐隐有隆隆之声，如雷鸣，又如千军万马在高处奔
腾。亮光越来越强，顽强地拨开水雾。
LONG
        );
        set("exits", ([ 
                "southdown" : __DIR__"exit2",
                "southup" : __DIR__"exit",
                        ]));
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
} 
int valid_leave(object obj, string dir){
        int i;
        object *inv;
        if(dir == "southup" && !obj->query("wizard")){
                inv = all_inventory(this_object());
                for (i=0;i<sizeof(inv);i++){
                        if (userp(inv[i]) ||!inv[i]->is_character()
                                ||inv[i]->is_corpse()) 
                                        continue;
                        if (inv[i]->query("dungeon_npc")=="eren2")
                                return notify_fail(inv[i]->name()+"举手挡住了你的路。\n");
                }
        }       
        return 1;
}
