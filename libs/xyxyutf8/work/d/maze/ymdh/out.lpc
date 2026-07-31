inherit ROOM; 

void create() 
{ 
        set("short", "副本出口"); 
        set("long", @LONG 
LONG
); 
        set("exits", ([ 
                "east" :__DIR__"maze/exit",
                "out": "/d/meishan/jixian",
        ]));
        set("no_magic",1);
        set("no_fight",1);
        set("no_chuqiao",1);
	set("channel_id","禹王爷(Yu wangye)");
        set("任务",1);
        set("hell",1);
        set("no_huicheng",1);
        set("outdoors","kaifeng");
        setup();
}

int valid_leave(object who,string dir)
{
	if( !who->query_temp("maze/ymdh") )
        	return notify_fail("你是怎么混进来的？！\n");
        return ::valid_leave(who,dir);
}

int is_ymdh(){ return 1;}			  		 
