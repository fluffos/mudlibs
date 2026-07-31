// 冰路2
// by steel 

inherit ROOM;

void create()
{
	set("short", "冰原");
	set("long", @LONG
	这里更冷了,终年不化积雪都结成了坚冰,已经没有了路,只是白茫
茫的一片,看不到任何鸟兽的痕迹,只有北风在呼啸着。前进一步似乎都变得
不可能。    
LONG
	);
	

	set("exits", ([
		"northeast" : __DIR__"iceroad3",
		"south" : __DIR__"iceroad1",
	]));
	setup();
}

int valid_leave(object me,string dir)
{
        if(dir=="northeast")
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
