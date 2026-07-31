// mg-indoor.c 迷宫大门
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short", CYN "高昌迷宫" NOR);
        set("long", "突然之间，眼前豁然开朗，出现一大片空地，尽头处又有两扇
"HIM"铁门"NOR"(tiemen)，嵌在大山岩中。几到亮光从门缝中射出来。\n");
        set("exits", ([
              "east" : __DIR__"mg3",
              "west" : __DIR__"mg4",           
        ]));        
        set("no_sleep_room", 1);
        set("item_desc",([           
         "tiemen" : "铁门依稀裂开了一条缝，从里面透出了一丝光亮。你应该可以打开(open)它。\n", 
	  ]));
        setup(); 
}
void init()
{
        add_action("do_move","open");
}

int do_move(string arg)
{
        object room;
        if( !arg || arg!="tiemen" ) return 0;
        if(!(room = find_object(__DIR__"tianjin")))
        room = load_object(__DIR__"tianjin");
        if(!room->query("exits")){
         message("vision","突然从铁门里传出一阵打声，看来还是不要打开铁门为好。\n", this_object() );
         return 1;
         }       
        message("vision","铁门忽然发出轧轧的声音，向一侧缓缓移开，露出一个光亮的出口。\n", this_object() );
        set("exits/northup", __DIR__"tianjin");
        room->set("exits/southdown", __FILE__);
        message("vision", "铁门忽然发出轧轧的声音，露出一个出口。\n",room );  
        remove_call_out("close_door");
        call_out("close_door", 5);
        return 1;
}

void close_door()
{
        object room;
        if( !query("exits/northup") ) return;
        message("vision","忽然一阵轧轧的声音，铁门又缓缓地合上了。\n", this_object() );
        if( room = load_object(__DIR__"tianjin") ) {
                room->delete("exits/southdown");
                message("vision", "铁门忽然发出轧轧的声音，缓缓地移回原处，将出口遮住了。\n", room );
                  }
        delete("exits/northup");
}