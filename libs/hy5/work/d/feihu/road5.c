// 雪路
// by steel 

inherit ROOM;
void create()
{
	set("short", "雪洞前");
	set("long", @LONG
	路到了这里就消失了,西北是一个小山丘,隐约望去,似乎有个山洞。   
LONG
	);
	
        set("exits", ([
		"southeast" : __DIR__"road2",
		"northwest" : __DIR__"hole1",
	]));
set("no_npc",1);
	setup();
     //   replace_program(ROOM);
}

int valid_leave(object me, string dir)
{

       if(dir=="northwest")
      {	
       if( (int)me->query("combat_exp")<50000)
         {
         tell_object(me,"你还是别去送死吧!\n");
         return 0;
          }
       }
        return ::valid_leave(me, dir);
}
