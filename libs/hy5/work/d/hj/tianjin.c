// tianjin.c 天井
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
        set("short", CYN "天井" NOR);
        set("long", "你悄声悄气地走了进来，原来这里是口天井，阳光从顶上的洞口直射
下来。四壁供的都是泥塑木雕的佛像，形态各异。南面有一扇"HIM"铁门"NOR"(tiemen)。\n");
        set("no_sleep_room", 1);
        set("exits", ([
              "north" : __DIR__"mg-room1",            
        ])); 
        set("item_desc",([           
         "tiemen" : "铁门依稀裂开了一条缝，里面没有一丝光亮。你应该可以打开(open)它。\n", 
	  ]));
        set("outdoors", "西域回疆");
        setup(); 
}

void init()
{
   object me, room;
   me = this_player();
   room = this_object();
   if(interactive(me) && (objectp(present("tu juan", me)) || objectp(present("xiang shi", me))
      || objectp(present("kuaixueshiqing tie", me)))){
        message_vision(HIR"只听得前面传来一阵桀桀怪笑，那声音道：「我在这里
已住了一千年，住了一千年。进来的一个个都死。」\n"NOR, me);   
        new(__DIR__"npc/hua")->move(environment(me));        
        room->delete("exits");
        }       
        add_action("do_move","open");
}

int do_move(string arg)
{
        object room, room1;
        room1 = this_object();
        if( !arg || arg!="tiemen" ) return 0;
        if(!room1->query("exits")) return 0;
        message("vision","铁门忽然发出轧轧的声音，向一侧缓缓移开，露出一个出口。\n", this_object() );
        set("exits/southdown", __DIR__"mg-indoor");
        if(room = load_object(__DIR__"mg-indoor")){
           room->set("exits/northup", __FILE__);
           message("vision", "铁门忽然发出轧轧的声音，露出一个光亮的入口。\n",room );
           } 
        remove_call_out("close_door");
        call_out("close_door", 5);
        return 1;
}

void close_door()
{
        object room;
        if( !query("exits/southdown") ) return;
        message("vision","忽然一阵轧轧的声音，铁门又缓缓地合上了。\n", this_object() );
        if(room = load_object(__DIR__"mg-indoor")){
           room->delete("exits/northup");
           message("vision", "铁门忽然发出轧轧的声音，缓缓地移回原处，将出口遮住了。\n", room );
           }
        delete("exits/southdown");
}