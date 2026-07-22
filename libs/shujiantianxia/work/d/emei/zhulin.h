// zhulin.h
// 竹林


int valid_leave(object me, string dir)
{
	object room;
       if (dir == "north")
          me->add_temp("mark/go",1);
       if (dir == "south")
          me->add_temp("mark/go1",1); 
       if (dir == "east")
          me->add_temp("mark/go",-1); 
       if (dir == "west")
          me->add_temp("mark/go1",-1); 
       if (me->query_temp("mark/go1") == -5 && me->query_temp("mark/go") == 6)
         {
	if(!(room = find_object(__DIR__"lengshanlin")))
            room = load_object(__DIR__"lengshanlin");
	    delete("exits/west");
	    delete("exits/east");
	    delete("exits/north");
	    delete("exits/south");
	    set("exits/north", __DIR__"lengshanlin"); 
            set("exits/west", __DIR__"zhulin"); 
	    set("exits/south", __DIR__"zhulin"); 
	    set("exits/east", __DIR__"zhulin"); 
            me->delete_temp("mark/go1");
            me->delete_temp("mark/go");
	   call_out("do_back", 2 , room);
         }       
       if (me->query_temp("mark/go1") == 5 && me->query_temp("mark/go") == 6)
	{
	if(!(room = find_object(__DIR__"dongkou")))
            room = load_object(__DIR__"dongkou");
	    delete("exits/west");
	    delete("exits/east");
	    delete("exits/north");
	    delete("exits/south");
	    set("exits/south", __DIR__"dongkou"); 
            set("exits/west", __DIR__"zhulin"); 	  
	    set("exits/east", __DIR__"zhulin"); 
	    set("exits/north", __DIR__"zhulin"); 
	    me->delete_temp("mark/go1");
            me->delete_temp("mark/go");
	   call_out("do_back", 2 , room);
         }
       if (me->query_temp("mark/go1") == -5 && me->query_temp("mark/go") == -6)
         {
            
        if(!(room = find_object(__DIR__"wanfoding")))
            room = load_object(__DIR__"wanfoding");
	    delete("exits/west");
	    delete("exits/east");
	    delete("exits/north");
	    delete("exits/south");
	    set("exits/east", __DIR__"wanfoding"); 
	    set("exits/west", __DIR__"zhulin"); 
	    set("exits/south", __DIR__"zhulin"); 	   
	    set("exits/north", __DIR__"zhulin"); 
            me->delete_temp("mark/go1");
            me->delete_temp("mark/go");
	   call_out("do_back", 2 , room);
         }
       if (me->query_temp("mark/go1") == 5 && me->query_temp("mark/go") == -6)
         {
        if(!(room = find_object(__DIR__"basipan3")))
            room = load_object(__DIR__"basipan3");
	    delete("exits/west");
	    delete("exits/east");
	    delete("exits/north");
	    delete("exits/south");
	    set("exits/west", __DIR__"basipan3");            
	    set("exits/south", __DIR__"zhulin"); 
	    set("exits/east", __DIR__"zhulin"); 
	    set("exits/north", __DIR__"zhulin");  
            me->delete_temp("mark/go1");
            me->delete_temp("mark/go");
	   call_out("do_back", 2 , room);
         }
        return ::valid_leave(me, dir);
}

void init()
{
       object me, *ob;
       int i;
       me = this_player();
       ob = all_inventory(environment(me));
       if (random((int)me->query("kar") + 1) <= 3 ) {
		message_vision(YEL"突然一股奇异的香气扑鼻而来，你只觉得一阵头晕目眩......\n\n"NOR, me);              
		for(i=0; i<sizeof(ob); i++) {
       			tell_object(ob[i], HIR"你觉得自己已经沉迷于香气之中，渐渐的手脚已经不听使唤了……\n"NOR);      
			ob[i]->unconcious();
			if (ob[i]) {
	ob[i]->move(__DIR__"lengshanlin1");    
       ob[i]->delete_temp("mark/go1");
       ob[i]->delete_temp("mark/go");           
	}
       }        
    }      
	add_action("do_save", "save");
	add_action("do_quit", "quit");
}

void do_back(object room)
{
	    delete("exits/west");
	    delete("exits/east");
	    delete("exits/north");
	    delete("exits/south");
	set("exits/west", __DIR__"zhulin"); 
	set("exits/south", __DIR__"zhulin"); 
	set("exits/east", __DIR__"zhulin"); 
	set("exits/north", __DIR__"zhulin"); 
}

int do_save()
{
	write("这里不准存盘！\n");
	return 1;
}

int do_quit()
{
	write("这里不准退出！\n");
	return 1;
}
