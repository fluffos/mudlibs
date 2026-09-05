// taolin1.c
// By Pingpang 

inherit ROOM;

void create()
{
    set("short", "桃花林");
    set("long", @LONG
这片桃林里有一棵与众不同的桃树(taoshu)，上面长满了水蜜桃.
你在此可以闻到一股扑鼻的桃花的香气。
LONG
    );
     set("exits", ([
 	"west" : __DIR__"taolin",
	"east" : __DIR__"jiashan",
    "southwest" : __DIR__"hualin",
    "northwest" : __DIR__"hualin2",
	  ]));
     set("item_desc",(["taoshu":"你可以爬(climb)上树去.\n",]));                                
		set("no_newbie_task",1);
    setup();
}
void init()
{	
	add_action("do_climb","climb");
}
int do_climb(string arg)
{
	object me;
	me=this_player();
	if(!arg||arg!="taoshu")
        return 0;
	if(arg=="taoshu")
	{	
		if(me->query_skill("dodge",1)<20)
            {tell_object(me,"你由于轻功欠佳，爬不上那么高的桃树.\n");
			 return 0;
			}
		else
         		{message("vision",me->name()+"灵活而轻便地爬上了桃树。\n",environment(me),me);
	 		me->move(__DIR__"taoshu");
	 		message("vision",me->name()+"也爬上了桃树,出现在你的身旁.\n",environment(me),({me}));
	 		return 1;
			}
	}
}
	
	
