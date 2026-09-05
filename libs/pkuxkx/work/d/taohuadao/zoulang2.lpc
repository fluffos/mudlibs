// taohuadao/zoulang 走廊

inherit ROOM;

void create()
{
         set("short", "走廊");
        set("long", @LONG
这是一条长廊。
LONG);
         set("exits", ([ /* sizeof() == 3*/
         "west" : __DIR__"lianxishi2",
         "east" : __DIR__"lianxishi1",
         "south" : __DIR__"lianxishi3",
         "north" : __DIR__"zoulang",
         ]));
	setup();
}

int valid_leave(object me,string dir)
{
	object env,item;
	mapping exits=query("exits");
	
	if ( dir=="north" )
	  return ::valid_leave(me, dir);

	if(!(env=find_object(exits[dir])))
 		env=load_object(exits[dir]);
  	
 	foreach(item in deep_inventory(env))
 	{
 		if( userp(item) && item->query("family/family_name")=="桃花岛" )
 			return notify_fail("房间中已经有人在研习乐谱，请等对方使用完毕该房间以后再进去。\n");
 		
 		if( userp(item) && item->query("family/family_name")!="桃花岛" )
 		{
  		item->move(this_object());
  		message_vision("$N将$n赶出了练习室。\n", me, item);
  	}
  }
  
  return ::valid_leave(me, dir);
}
