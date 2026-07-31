 inherit ROOM;
void create()
{
        set("short", "彩石路");
        set("long", @LONG
行路至此，一下子宽敞起来，洞顶极高，黑漆漆的，离地三丈处似乎
还有个岩洞，可惜被青苔遮住了。不几步处又是一个分岔口，彩石路继续
向东边延伸，左边多了条石路，看样子是向上去的。
LONG
        );
        set("exits", ([ 
                "westup" : __DIR__"exit1",
                "eastdown" : __DIR__"court2",
                "southeast" : __DIR__"yongdao7",
                        ]));
        set("item_desc", ([
        "青苔" : "暗色的青苔布满了洞壁。\n",
        "moss" : "暗色的青苔布满了洞壁。\n",
        "岩洞" : "岩洞很高，从这儿爬上去是不可能的。\n",
        "cave" : "岩洞很高，从这儿爬上去是不可能的。\n",
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
        if((dir == "westup" || dir == "eastdown" )&& !obj->query("wizard")){
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
