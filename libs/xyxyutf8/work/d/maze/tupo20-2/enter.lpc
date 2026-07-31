inherit ROOM; 
void create() 
{ 
        set("short", "山洞"); 
        set("long", @LONG 
眼前是一个山洞，虽然幽深，但是石壁之上皆镶了宝石，倒也照得如同白昼。

LONG
); 
        set("no_magic",1);
        set("no_fight",1);
        set("exits", ([
                "down" : __DIR__"maze/entry", 
        ])); 
        set("objects",([
        	"/d/maze/tupo20-2/obj/bag" : 1,
        ]));	
        set("channel_id","引气入体");
        setup();
} 

int valid_leave(object who,string dir)
{
	if( !who->query_temp("maze/tupo20-2") )
        	return notify_fail("你是怎么混进来的？！\n");
        return ::valid_leave(who,dir);
}
