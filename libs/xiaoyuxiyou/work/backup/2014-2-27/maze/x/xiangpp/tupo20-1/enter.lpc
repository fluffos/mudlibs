inherit ROOM; 
void create() 
{ 
        set("short", "山脚"); 
        set("long", @LONG 
仰望天空，山势压顶，天边的红霞映透了整个山林，呼啸的穿山风刮个不停。你不禁有些惧意。
前方是一条上山小路。

LONG
); 
        set("no_magic",1);
        set("no_fight",1);
        set("exits", ([
                "up" : __DIR__"maze/entry", 
        ])); 
        set("channel_id","引气入体");
        setup();
} 

int valid_leave(object who,string dir)
{
	if( !who->query_temp("maze/tupo20-1") )
        	return notify_fail("你是怎么混进来的？！\n");
        return ::valid_leave(who,dir);
}
