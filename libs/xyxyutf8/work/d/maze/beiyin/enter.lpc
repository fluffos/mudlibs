inherit ROOM; 
void create() 
{ 
        set("short", "白虎大街"); 
        set("long", @LONG 
这里已是白虎大街的西段，北面小巷里隐约看到一座大的草堂，
堂外挂一蓝布幌子，上写一个“卦”字。南面巷中一行歪柳，处处民
宅，几个小同在巷中玩耍。有不少求师学艺者在这袁氏草堂门前。

LONG
); 
        set("virtual_room", 1); 
        set("no_magic",1);
        set("exits", ([
                "south" : __DIR__"maze/entry", 
        ])); 
        set("objects",([
        	"/d/maze/beiyin/npc/liyu" : 1,
        ]));	
        setup();
} 

int valid_leave(object who,string dir)
{
	if( !who->query_temp("maze/beiyin") )
        	return notify_fail("你是怎么混进来的？！\n");
        return ::valid_leave(who,dir);
}			  		 
