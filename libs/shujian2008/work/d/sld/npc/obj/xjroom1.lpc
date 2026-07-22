// xjroom1.c
// 陷阱1
inherit ROOM;
void create()
{
	set("short","陷阱");
	set("long",@long
这是一个神龙教专门用来对付外人的陷阱，这里阴暗潮湿、腥臭扑鼻，
黑暗中不时地还有什么东西从你脚边、脚上爬过。这里的两壁都非常光滑，
没有什么可以搭手的地方，看来要出去并非易事，你可以(climb)试试。
long);
      setup();
}

void init()
{        
     add_action("do_climb","climb");
}

int do_climb(string arg)
{
    object me=this_player();
    object room;
    int qi;
    
    if(!arg)
        return 0;
    if(arg=="up")
    {
        qi=(int)me->query_skill("dodge",1);
        qi=qi*me->query_kar()*me->query_dex()/900;
        if(qi>random(100))
        {
            me->apply_condition("snake_poison",0);
            message_vision("$N试着慢慢地向上爬去。\n",me);
	    room=find_object(me->query("uproom"));
	    if(!objectp(room))
		me->move("/d/sld/dukou");
	    else
            	me->move(room);
           
            message_vision("$N慢慢地从陷阱里爬了上来! \n",me);
            /*ob->set_temp("number",(int)ob->query_temp("number",1)-1);
            if((int)ob->query_temp("number",1)==0)
                destruct(ob);*/
            //return 1;
        }
        else
        {
            message_vision("$N试着慢慢地向上爬去，不好！$N一失手掉了下去。\n",me);
            me->receive_wound("qi", 50);
	      me->receive_damage("qi", 50);
            //return 1;
        }
    }
    else
        return notify_fail("你想往哪里爬？\n");
    return 1;
}
	    	
