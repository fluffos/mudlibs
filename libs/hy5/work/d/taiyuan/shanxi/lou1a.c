inherit ROOM;
#include <ansi.h>
#include <room.h>
void create() 
{ 
    set("short", "瞒天过海"); 
    set("long", @long
备周则意怠；常见则不疑。阴在阳之内，不在阳之对。太阳，
太阴。共敌不如分敌，敌阳不如敌阴。敌已明，友未定，引友杀
敌，不自出力，以《损》推演。
long 
    ); 
    set("exits", ([ 
    	"south" : __DIR__"lou1b", 
        ])); 
        set("objects", ([        
        ]));
        
        set("no_magic",1);
        
        set("indoors","shanxi"); 
	set("coor/x",-400);
        set("coor/y",-200);
        set("coor/z",101);
        setup(); 
} 
int valid_leave(object obj, string dir){
        object another;
        seteuid(getuid());
        
        if(dir == "south" && !obj->query_temp("青衣楼/lou1a")){
                if (present("liu yuhen", this_object()))
                {
                        another = present("liu yuhen", this_object());
                        return notify_fail(another->name()+"冷笑道：不打赢我，休想擅闯青衣楼！\n");
                } else {
                        another = new(__DIR__"npc/liuyuhen");
                        another->move(environment(obj));
                        message_vision(HIR"突然你眼前一花，一条黑影闪现在你面前!\n"NOR, obj);   
                   return notify_fail(another->name()+"冷笑道：你若不要我死，我就要你死！！\n");
                }
        }       
        return 1;
}