// Room: /d/diaoyudao/guolin.c 野果林
// hongdou 98.09.20

inherit ROOM;

void create()
{
	set("short", "野果林");
	set("long", @LONG
你来到一小片树林边，这里生长着各种树木，树上零星的
结着些野果(guo)，看起来新鲜诱人，你盯着果子，不禁垂涎
欲滴。从这里往东就是钓鱼岛的东海岸。
LONG
	);
	
	set("exits", ([
         "east" : __DIR__"dhaian1",
		 "northwest" : __DIR__"caodi4",
         "southwest" : __DIR__"caodi3",
	]));
	set("item_desc",([
	      "guo":"树上结着各种野果，有红色的、黄色的、紫色的，看起来一定很好吃。\n",
	]));

	set("outdoors", "diaoyudao");
	setup();
}

void init()
{
 add_action("do_zhai","zhai");
}

int do_zhai(string arg)
{
    object me=this_player();
    object red,yellow,blue;
    	
    if(!arg||arg=="") return notify_fail("你要摘什么?\n");

    if(arg!="guo") return notify_fail("这儿可没有你要的东西!\n");

    if(arg=="guo") 
    {
	if (me->query_temp("摘")>=3) return notify_fail("别摘了，给别人留点吧!!!\n");
	call_out("guo",1,me);
	me->add("jing",-20);
	me->add_temp("摘",1);
	return 1;
    }
} 

void guo(object me)
{
    object ob,obj;
    switch(random(9))
    {           
	case 0: message_vision("$N摘下一个烂果子，随手扔到了地上。\n",me);
          	break;        
	case 1: message_vision("$N摘下了一枚红果，放在身上。\n",me);
        	ob=new(__DIR__"npc/obj/redguo");
          	ob->move(me);
          	break;
	case 3: message_vision("$N摘下一个烂果子，随手扔到了地上。\n",me);
          	break;
	case 4: message_vision("$N摘下一个烂果子，随手扔到了地上。\n",me);
          	break;      
 	case 5: message_vision("$N摘下了一枚红果，放在身上。\n",me);
		ob=new(__DIR__"npc/obj/redguo");
          	ob->move(me);
          	break;  
 	case 7: ob=new(__DIR__"npc/obj/yelguo");
          	ob->move(me);
          	message_vision("$N摘下了一枚黄果，放在身上。\n",me);
          	break;         
 	default:message_vision("$N摘下一紫果，放在身上。\n",me);
		ob=new(__DIR__"npc/obj/blueguo");
          	ob->move(me);
          	break;
    }
}     
