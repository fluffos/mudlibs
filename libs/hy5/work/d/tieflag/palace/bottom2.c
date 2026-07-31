 inherit ROOM;
void create()
{
        set("short", "湖底");
        set("long", @LONG
这里实在很美，很静。泉水清澈冰凉，各式各样的鱼虾在你的面前悠
闲的游来游去，看著水草在砂石间娥娜起舞，这种感觉不是未曾经历此境
的人所能领略得到的。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"bottom",
  "north" : __DIR__"bottom3",
  "up" : __DIR__"smalllake",
  "south" : __DIR__"bao",
])); 
        set("coor/x",200);
        set("coor/y",-20);
        set("coor/z",10);
        setup();
} 
int valid_leave(object me, string dir)
{
        object *inv, ob;
        int i; 
        if( dir == "up" ) return 1;
        if( userp(me)) {
                inv = all_inventory(me);
                for(i=0; i<sizeof(inv); i++) 
                        if((string)inv[i]->name() == "芦苇")  return 1;
        }
        return notify_fail("\n你觉得胸口发闷，还是赶快上岸的好！\n");
}     
