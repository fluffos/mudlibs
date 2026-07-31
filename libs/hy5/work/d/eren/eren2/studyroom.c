 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "书房");
        set("long", @LONG
除了没有窗子，这实在是一间最标准的书房，就和世上大多数读书人
读书的地方完全一样。书房的左右两壁，是排满了书的书橱书架，中间是
一张精雅的大理石书桌，桌上整齐地排列着文房四宝。
LONG
        );
        set("exits", ([ 
                "up" : __DIR__"yard2",
                "south" : __DIR__"innerroom",
                        ]));                    
        set("objects", ([
                __DIR__"npc/yulang" : 1,
                __DIR__"obj/shelf" : 1,
        ]) );
        set("item_desc", ([
                "书桌": "一张精雅的大理石书桌，桌上整齐地排列着文房四宝。\n",
                "desk": "一张精雅的大理石书桌，桌上整齐地排列着文房四宝。\n",
             
        ]) );
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
} 
int valid_leave(object obj, string dir){
        int i;
        object son;
        if(dir == "south"){
                if (son=present("jiang yulang",this_object()))
                if (!userp(son))
                        return notify_fail("江玉郎说：家父正在歇息，暂不会客。\n");
        }       
        return 1;
}  
void reset()
{
   object *inv;
   object item1, item2, table;
   ::reset(); 
   table = present("shelf", this_object());
   inv = all_inventory(table);
   if( !sizeof(inv)) {
      item1 = new(__DIR__"obj/paper");
      item1->move(table);
      item2 = new(__DIR__"obj/paper1");
      item2->move(table);
   }
}    
