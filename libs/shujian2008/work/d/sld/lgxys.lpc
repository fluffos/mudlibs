// lgxys.c
// 陆高轩家药室
inherit ROOM;
void create()
{
	set("short","药室");
	set("long",@long
一走进这间屋子，就闻到很浓的草药味，只见这里靠墙是一个药柜，从上
到下，从左到右，一格格地分成许多格，墙上，地下，也到处都是药草，这里
是陆高轩制药的地方。
long);
	set("exits",([
	    "west" : __DIR__"lgxroom",
]));
set("objects",([
__DIR__"npc/obj/yaogui" : 1,
]));
	//set("yaozhong",15);
	set("coor/x",500);
  set("coor/y",410);
   set("coor/z",10);
   setup();
}
	
void reset()
{
        object 		*inv;
        object 		con, item;
	 int		i;	

        ::reset();
	//set("yaozhong",15);
        con = present("yaogui", this_object());
        inv = all_inventory(con);
        if( sizeof(inv) < 5) {
	     for(i=4-sizeof(inv); i>=0; i--)
            {
        	item = new(__DIR__"npc/obj/sheyao");
        	item->move(con);
            }
        }
}    	

void init()
{    
     add_action("do_search", "search");
}

int do_search(string arg)
{
	object me=this_player();
	object ym;
	string* type5=({"土","金","水","木","火"});

	if(!me->query_temp("yaozhong",1))
	{
		tell_object(me,"突然冲进来几个神龙教的护教弟子，对你大喝到：你在干什么？！竞敢来偷东西！然后一阵乱棒把你打昏！...\n");
		me->move("/d/sld/kongdi");
		me->unconcious();
		return 1; 
	}
	if((arg!="角落") && (arg!="corner") && (arg!="墙角") && (arg!="屋角"))
		return 0;
	if(me->query("jingli")<50)
		return notify_fail("你现在太累了，先休息一下吧。\n");
	else
		me->add("jingli",-50);
	/*if(!query("yaozhong"))
		return notify_fail("你找了半天，什么东西都没有找到。\n");*/
	if((time()-me->query("yztime"))>1200)
	{
		me->set("yztime",time());
		me->set("findyz",0);
	}
	if(me->query("findyz")>8)
		return notify_fail("你找了半天，什么东西都没有找到。\n");
        if(random(10)>7)
	{
		ym=new("/d/sld/npc/obj/yaozhong");
		if(!ym)
			return notify_fail("你找了半天，什么东西都没有找到。\n");
		ym->set("5type",type5[random(sizeof(type5))]);
		if(!ym->move(me))
			ym->move(this_object());
		message_vision("$N找了半天，找到一枚药种。\n",me);
		//add("yaozhong",-1);
		if(!me->query("findyz"))
			me->set("findyz",1);
		else
			me->add("findyz",1);
		return 1;
	}
	return notify_fail("你找了半天，什么东西都没有找到。\n");
}
