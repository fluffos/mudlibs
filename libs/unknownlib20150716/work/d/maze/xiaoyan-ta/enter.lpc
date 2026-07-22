inherit ROOM; 
void create() 
{ 
        set("short", "小雁塔下"); 
        set("long", @LONG 
小雁塔是一座通高几十丈的砖塔，庄严而玲珑，塔身檐角密布，一共有
十五层之高。
    却不想塔下另有玄机，只见四面纵横十余丈，其中错牙交错的甬道
连接四方，两名的石壁上画满佛符，闪烁着微弱的金光。

LONG
); 
        set("virtual_room", 1); 
        set("no_magic",1);
        set("exits", ([
                "south" : __DIR__"maze/entry", 
                "up": "/d/eastway/xyt",
        ])); 
        set("objects",([
        	"/d/maze/xiaoyan-ta/npc/monk" : 1,
        ]));	
        setup();
} 

int valid_leave(object who,string dir)
{
	if( !who->query_temp("maze/xiaoyan") )
        	return notify_fail("你是怎么混进来的？！\n");
        return ::valid_leave(who,dir);
}			  		 
