// sanpo7.c
// 山崖
inherit ROOM;
void create()
{
	set("short","山崖");
	set("long",@long
这里的草木稀疏，仅有的一些也没精打采，发黄枯萎，空气中则隐隐
约约地有股腥臭味，似乎是从崖底飘上来的，让人闻了感到很不舒服，此
处决非久留之地，还是赶快离开为妙。
long);
	set("exits",([
	   "westdown" : __DIR__"treen2",
]));
	set("outdoors", "神龙岛");
        setup();
	//replace_program(ROOM);
}
	    	
void init()
{        
     add_action("do_kan","kan");
     add_action("do_climb","climb");
}

int do_kan(string arg)
{
    object me=this_player();

    if(arg=="山崖" || arg=="崖底" || arg=="mountain")
    {
        if(me->query_kar()>random(50))
        {
            tell_object(me,"崖底笼罩在迷雾中，有一条山藤似乎挺光滑，看来常有人(climb)下去。\n");
            me->set_temp("mark/climbvine",1);
        }
        else 
           tell_object(me,"崖底笼罩在迷雾中，什么也看不清。\n");
        return 1;
    }
    return 0;
}

int do_climb(string arg)
{
    object me=this_player();
    object ob;

    if(arg=="山藤" || arg="vine")
    {
        if(me->query_temp("mark/climbvine",1)==1)
        {
            me->delete_temp("mark/climbvine");
            message_vision("$N抓着山藤，慢慢地向下爬去！\n",me);
            ob = load_object(__DIR__"sheku");
            me->move(ob);
            message_vision("$N轻轻一纵，两脚落地！\n",me);
            return 1;
        }
        else
            return 0;
    }
    return 0;
}

int valid_leave(object me, string dir)
{
    if(this_player()->query_temp("mark/climbvine",1)==1)    
        this_player()->delete_temp("mark/climbvine");
    return 1;
}
