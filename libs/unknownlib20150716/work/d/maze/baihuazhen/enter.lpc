inherit ROOM; 
void create() 
{ 
        set("short", "花海"); 
        set("long", @LONG 
放眼望去，但见天地间仿佛已被鲜花充满，但却是无人认得出的花
朵，只觉得这些花无比的鲜艳，无比的美丽。真是令人想不到，荒漠之
中，竟有这样的花海。

LONG
); 
        set("virtual_room", 1); 
        set("no_magic",1);
        set("exits", ([
                "west" : __DIR__"maze/entry", 
        ])); 
        setup();
} 

int valid_leave(object who,string dir)
{
	if( !who->query_temp("maze/baihuazhen") )
        	return notify_fail("你是怎么混进来的？！\n");
        return ::valid_leave(who,dir);
}			  		 
