 inherit ROOM;
void create()
{
        set("short", "甬道");
        set("long", @LONG
坡度至此略微平坦一些，壁上多了几盏油灯。地上数块大石把通道堆得只容一
人可以侧身挤过。大石后站着几个穿黑色衣靠的人，脸隐在阴影之中，只看得见手
里兵刃的闪光。
LONG
        );
        set("exits", ([ 
                "eastdown" : __DIR__"yongdao4",
                "southup" : __DIR__"yongdao2",
                "westup" : __DIR__"yongdao3a",
        ]));
        set("objects", ([
                __DIR__"npc/guarda" : 2,
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
        if(dir == "westup" || dir == "eastdown"){
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
