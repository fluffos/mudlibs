// xjroom2.c
// 牢房
inherit ROOM;
void create()
{
	set("short","牢房");
	set("long",@long
这里是一间神龙教的牢房，里面阴暗潮湿、腥臭扑鼻，黑暗中不时地有什
么东西从你脚边、脚上爬过。此处四面都是用巨石砌成的石墙，只有头顶有个
洞盖着石板(flag)。
long);
      setup();
}

void init()
{        
     add_action("do_push","push");
}

int do_push(string arg)
{
    object me=this_player();
    object room;
    int qi;
    
    if(!arg)
        return 0;
    if(arg=="flag")
    {
        me->receive_damage("jing", 100);
        qi=(int)me->query_skill("dodge",1);
        qi=qi*me->query_kar()*me->query_dex()/900;
        if(qi>random(200))
        {
	    me->apply_condition("snake_poison",0);
            message_vision("$N试着推了推顶上的石板，居然给$N推开了，$N立刻爬了上去。\n",me);
	    room=find_object(me->query("uproom"));
	    if(!objectp(room))
		me->move("/d/sld/dukou");
	    else
            	me->move(room);
            tell_room(environment(me), "突然地板被人推起一块，"+me->name() + "从下面爬了上来。 \n");
            tell_object(me, "你纵身一跃，爬出了牢房。\n");
            /*ob->set_temp("number",(int)ob->query_temp("number",1)-1);
            if((int)ob->query_temp("number",1)==0)
                destruct(ob);*/
            //return 1;
        }
        else
        {
            message_vision("$N试着推了推头顶上的石板，但是没推动。\n",me);
	      //me->receive_damage("qi", 100);
            //return 1;
        }
    }
    else
        return 0;
    return 1;
}
	    	
