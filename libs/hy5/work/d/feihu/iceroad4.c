// 冰路
// by steel 

inherit ROOM;

void create()
{
	set("short", "冰原");
	set("long", @LONG
	这里更冷了,终年不化积雪都结成了坚冰,已经没有了路,只是白茫
茫的一片,看不到任何鸟兽的痕迹,只有北风在呼啸着。    
LONG
	);
        set("no_clean_up",0);
        set("out_doors","feihu");
	set("exits", ([
		"east" : __DIR__"iceroad5",
		"west" : __DIR__"hill",
	]));
	setup();
}

int valid_leave(object me,string dir)
{
        if(dir=="east")
        {
         if((int)me->query_skill("dodge",1)<=70)
          {
         me->add("jing",-50);
         me->add("qi",-50);
          }
          else{
          me->add("jing",-30);
          me->add("qi",-30);
        }
        }
     return 1;     
}   
