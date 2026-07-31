// Room:wg1.c
//write by lysh
inherit ROOM;

void create()
{
	set("short", "练武厅");
	set("long", @LONG
这里是精武武馆在泉州的练武厅，武馆的馆主是少林
俗家弟子，所以这里有从少林购入的最先进的健身器
------少林木人。

LONG
	);
       set("exits", ([                                
           "south" : __DIR__"wgm1",                                                                                                                       
	 ]));
       	set("objects", ([
		"/d/shaolin/npc/mu-ren": 20,
	]) );
                                  

          setup();
}



int valid_leave(object me,string dir)    
{
 
 present("wang er ma",find_object(__DIR__"wgm1"))->set_temp("有人/mark",0);

 return ::valid_leave(me, dir);   
}
