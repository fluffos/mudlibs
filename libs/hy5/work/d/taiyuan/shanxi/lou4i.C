inherit ROOM;
#include <ansi.h>
#include <room.h>
void create() 
{ 
    set("short", HIG"走为上计"NOR); 
    set("long", @long
人不自害，受害必真；假真真假，间以得行。童蒙之吉，顺以巽也。
将多兵众，不可以敌，使其自累，以杀其势。在师中吉，承天宠也。全师
避敌。左次无咎，未失常也。面前有乾、兑、离、震、巽、坎、艮、坤，
共八道门，看来要碰碰运气了(open)。
long 
    ); 
    set("exits", ([ 
    	//"up" : __DIR__"lou4a", 
    	"north" : __DIR__"lou4h",
    	//"west" : __DIR__"midao",
    	//"out" : __DIR__"alou4",
        ])); 
                set("objects", ([
                __DIR__"npc/xuekeke": 1,
                
        ]));
        
        set("no_magic",1);
        
        set("indoors","shanxi"); 
        set("coor/x",-400);
        set("coor/y",-200);
        set("coor/z",102);
        setup(); 
                //create_door("out", "石门", "enter", DOOR_CLOSED); 

} 
void init()
{
        add_action("do_open", "open");
}
void close_path()
{
        if( !query("exits/north") ) return;

        message("vision",
               "忽然阵法一变，八门换位，眼前一片迷糊。\n",
                this_object() );
                delete("exits/outdown");
}  
int do_open(string arg)
{
        object me,room;
        me = this_player();
        if( !arg || arg=="" ) return 0; 
        if( arg=="乾" || arg =="兑" || arg=="离"|| arg =="震" || arg =="巽" || arg =="坎" || arg =="艮" || arg =="坤" ) 
        {
                message_vision(HIB "\n$N长长地、重重地吐了口气，伸手推门。\n\n" NOR, me);
        if( random(2)== 1 )
                {
                message_vision(HIB "门应声而开。$N发现外面的阳光是那么灿烂！！！\n\n" NOR, me);
                //if( !query("exits/outdown") ) {
                me->move(__DIR__"alou");
                me->start_busy(3);
                //call_out("close_path", 5);
                                                //}
                return 1;       
                }
                else
                message_vision(HIB "忽然阵法一变，八门换位，$N眼前一片迷糊......\n\n" NOR, me);
                message_vision(HIB "门后竟然不着力，$N“扑通”一声往门后跌去！！！\n" NOR, me);
                me->unconcious();
                me->move(__DIR__"lou3i");
                room = find_object(__DIR__"lou3i");
                message("vision","$N不知道从哪里被人扔了下来。\n",room);
                return 1;
        }
                write("你要打开啥？\n");
                return 1;
} 
