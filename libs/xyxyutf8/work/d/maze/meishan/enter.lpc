inherit ROOM; 
void create() 
{ 
        set("short", "【梅山七圣】副本入口"); 
        set("long", @LONG 


LONG
); 
        set("no_magic",1);
        set("no_fight",1);
        set("exits", ([
                "enter" : __DIR__"maze/entry", 
        ])); 
        set("no_chuqiao",1);
        set("channel_id","梅山七圣");
        set("alternative_die",1);
        set("任务",1);
        set("hell",1);
        set("no_huicheng",1);
        set("outdoors","meishan");
        setup();
} 

int valid_leave(object who,string dir)
{
	if( !who->query_temp("maze/meishan") )
        	return notify_fail("你是怎么混进来的？！\n");
        if( who->query_level()<110 )
        	return notify_fail("你等级不够，还是算了吧。\n");	
        return ::valid_leave(who,dir);
}			  		 
