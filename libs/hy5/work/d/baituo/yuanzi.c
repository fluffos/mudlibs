// yuanzi.c

inherit ROOM;

void init();
string look_gate();
int do_open(string);
int do_lock(string);

void create()
{
        set("short", "院子");
        set("long",
             "这是一个大院子，打扫得一尘不染。四周装点着青青翠竹，错落\n"
         "有致。西边是武器库。东边有一间储藏室，房门(door)关闭着。北边\n"
         "是『白驼山庄』的大厅。南边就是大门了。\n"
         "这里还有一个的花园，中间一堆假山，一条小溪。旁边种满了各类花草，\n"
         "芳香宜人。北面有一道锁着的铁门(tiemen)，可以通往另一个院子。\n"
        );
        set("exits", ([
                "northup" : __DIR__"dating",
                "west" : __DIR__"wuqiku",
                "south" : __DIR__"damen",
        ]));
        set("objects",([
             __DIR__"npc/shiwei" : 1,
             __DIR__"obj/shezhang" : 1,
        ]));
        set("outdoors", "baituo");
        set("no_clean_up", 0);

        set("item_desc", ([
            "door" : (: look_gate :),
                "tiemen": "\n这道铁门极其沉重，看来没有几百斤臂力推它不动。真是奇怪为
何会有如此铁门在此，就连一般人都可以翻越(climb)旁边的矮墙。\n",
        ]));

        set_temp("lock",1);

        setup();
//        replace_program(ROOM);
}

void init()
{
	add_action("do_open", "open");
	add_action("do_lock", "lock");
        add_action("do_fan", "fan");
        add_action("do_fan", "pa");
        add_action("do_fan", "climb");
        add_action("do_push", "push");
        add_action("do_push", "tui");
        add_action("do_push", "strike");
        add_action("do_wen", "wen");
        add_action("do_wen", "smell");                  

}

string look_gate()
{
	if (query_temp("lock") == 0)
		return "门上的铁锁被打开了。\n";
	return "这扇门被铁锁牢牢锁住。\n";
}

int do_open(string arg)
{
	object me=this_player(), room;

	if(!arg || arg!="door")
		return notify_fail("你要开什么？\n");

	if( query_temp("lock") == 1 && !present("key", me) )
		return notify_fail("钥匙都没有，怎么开门？\n");

	if(!( room = find_object(__DIR__"storeroom")) )
		room = load_object(__DIR__"storeroom");

	if(!objectp(room))
		return notify_fail("ERROR:not found 'storeroom.c' \n");

	if(query_temp("lock") == 1 && present("key", me))
	{
		set_temp("lock", 0);
		message_vision("$N把钥匙插进锁孔，只听见‘卡嗒’一声，锁开了。\n", me);
		message("vision", "外面传来一阵开锁的声音，只听见‘卡嗒’一声，锁开了。
  \n",room);
}
   message_vision("$N轻轻推开门，走了进去，随手把门掩了起来。\n",me);
   message("vision", "有人走了进来，随手把门掩上了。\n",room);
   me->move(room);
   return 1;
}

int do_lock(string arg)
{
	object me=this_player();
	object room;

	if(!arg ||  arg!="door")
		return notify_fail("你要锁什么？\n");
	if( !present("key",me))
		return notify_fail("钥匙都没有，怎么锁门？\n");
	if(!( room = find_object(__DIR__"storeroom")) )
		room = load_object(__DIR__"storeroom");
	if(!objectp(room))
		return notify_fail("ERROR:not found 'storeroom.c' \n");

	if(query_temp("lock") == 1)
		return notify_fail("门已经锁好了。\n");
	set_temp("lock",1);
	message_vision("$N把钥匙插进锁孔，只听见‘卡嗒’一声，锁被锁上。\n",me);
	message("vision", "外面传来一阵锁铁锁的声音，只听见‘卡嗒’一声，锁被锁上了。
  \n",room);

	return 1;
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");
        me->delete_temp("baituo_climb");
        if ((!myfam || myfam["family_name"] != "白驼山派") && dir == "west")
           return notify_fail("此处乃本派禁地，请止步。\n");

        return ::valid_leave(me, dir);
}
int do_fan(string arg)
{
        int dex, i = 0;
        object me = this_player();    
            
        dex = me->query_dex();     
        
        if( (int)me->is_busy() || me->is_fighting()) 
        	return notify_fail("你正忙着呢。\n");
        	
       	if( (int)me->query("hamagong") ) 
        	return notify_fail("你正想翻过墙去，突然有了一股想推开铁门的冲动。\n");
       	if (dex < 18 )
        	return notify_fail("这矮墙虽矮，你却怎么也翻不过去。\n");
       	
       	if (dex > 17 && dex < 25){  
           	message_vision("$N双手在矮墙上一按，一翻身便纵了过去。\n", me);
           	i = 1;
        	}
        
       	if (dex > 24 && dex < 36){  
           	message_vision("$N运功提气轻轻一纵，便跃了过去。\n", me);
           	i = 2;
        	}
        
       	if (dex > 35){  
           	message_vision("$N脚尖轻轻一点，高高跃起，飘了进去。\n", me);
           	i = 3;
        }    
        me->set_temp("baituo_climb", i);
        me->move(__DIR__"shetan");
        me->start_busy(2);
        return 1;   	    
}

int do_push(string arg)
{
        int str;
        object me = this_player();
        
        str = me->query_str();

        if( (int)me->is_busy() || me->is_fighting()) 
        	return notify_fail("你正忙着呢。\n");
        	
        if( !arg || arg=="" ) return 0;
        
       	if (arg == "tiemen" ){
        	if( (int)me->query_skill("hamagong", 1)){
           		message_vision("$N蹲下身子，咕咕叫了两声，双掌平伸推向铁门。\n", me);
           		message_vision("铁门突然打开，$N一没留神滚了进去。铁门却又合上了。\n", me);
//           		me->receive_damage("neili", 100);
           		me->receive_damage("jing", 50);
           		me->move(__DIR__"yuanzi1");
           		message("vision", "只听啪的一声，一个人影从铁门出滚了过来！\n",environment(me), ({me}));
           		return 1;
           		}
       		if (str < 21 )
               		return notify_fail("你使出了吃奶的力气，可就是推不动这铁门。\n");
               		
       		if (str > 20 && str < 38){  
       			if(str < 30)
           			message_vision("$N使出全身力气推向铁门，可铁门只轻轻动了一下。\n", me);
           		else message_vision("$N运功提气猛地推向铁门，铁门发出了轰轰的震动声，看来马上就可以推开了。可这时$N的力气刚好使完，只得作罢。\n", me);
//           		me->receive_damage("neili", 400);
           		me->receive_damage("jing", 200);
           		return 1;
           		}

       		if (str > 37){  
           		message_vision("$N内劲运转，双掌平伸推向铁门。\n", me);
           		message_vision("铁门突然打开，$N一没留神滚了进去。铁门却又合上了。\n", me);
//           		me->receive_damage("neili", 400);
           		me->receive_damage("jing", 200);
           		me->move(__DIR__"yuanzi1");
           		message("vision", "只听啪的一声，一个人影从铁门出滚了过来！\n",environment(me), ({me}));
           		return 1;
           		} 
       		}
       	else return 0;        
}

int do_wen(string arg)
{
        int con = this_player()->query_con();

      	if ( con > 29 && con < 37)
         	write("你轻轻吸了吸气，突然感觉到花香中隐隐带有股腥味。但闻不出是从哪儿来的。\n");      
      	if ( con > 36 )
         	write("你轻轻吸了吸气，突然感觉到花香中隐隐带有股腥味。好象是从铁门那边的院子飘来的。\n");       
      	if ( con < 30 )
         	write("你轻轻吸了吸气，全是芬芳的花香，你都快醉了。\n");                     
       	return 1;        
}

