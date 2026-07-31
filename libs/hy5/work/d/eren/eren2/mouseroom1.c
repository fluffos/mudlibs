 inherit ROOM;
void create()
{
        set("short", "石室");
        set("long", @LONG
通道很短，没几步就到了一间石室。屋内只有一张很大很大的石椅，
是用一整块石头虽塑成的，虽然是石头，但比玉质更晶莹，连一丝杂色
都看不到，这洞中阴寒之气砭人肌肓，但只要坐在这石椅上，立刻觉得
温暖如春。像这样的石椅，普天之下，只怕再也找不出第二只了，但现
在这石椅却已被一剑劈成两半！
LONG
        );
        set("exits", ([ 
                "northeast" : __DIR__"mouseroom2",
                ]));
        set("objects", ([
                __DIR__"npc/star_horse" : 1,
                __DIR__"npc/star_tiger" : 1,
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
        if(dir == "northeast"){
                inv = all_inventory(this_object());
                for (i=0;i<sizeof(inv);i++){
                        if (userp(inv[i]) ||!inv[i]->is_character()
                                ||inv[i]->is_corpse()) 
                                        continue;
                        if (inv[i]->query("dungeon_npc")=="eren2")
                                return notify_fail(inv[i]->name()+"说：这事儿咱夫妻已经包了。\n");
                }
        }       
        return 1;
} 
