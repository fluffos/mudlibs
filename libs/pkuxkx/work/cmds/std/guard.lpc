// By Kuer@XKX (12/11/97)
//
// Modified by pretty (09/15/98)

mapping guards;

int main(object me, string arg)
{              
        object room;
        object obj,oldobj; 
        int i;
	if( environment(me)->query("no_fight") )
		return notify_fail("这里禁止战斗。\n");
        if ( !arg )
        {                                                     
                write("你现在的守护状态：\n");
                if(!mapp(guards=me->query_temp("guards")) || sizeof(guards)==0 )
                {
                        write("你现在没有守护任何东西！\n"); 
                        return 1; 
                }
                if(objectp(guards["object"]))
                        write("你正在守着"+ guards["object"]->name() +"。\n");
                if(objectp(guards["living"]))
                        write("你正在保护"+ guards["living"]->name() +"。\n");
                if(!undefinedp(guards["exit"]))
                        write("你正在看守"+ guards["exit"] +"方向。\n");  
                return 1;
        }
        else if (arg=="none" )
        {  
                if(!mapp(guards=me->query_temp("guards")) || guards==([]) )
                {
                        write("你现在没有守护任何东西！\n"); 
                        return 1; 
                }
                if(objectp(guards["object"]))
                        message_vision("$N解除对$n的看守。\n", me, guards["object"]);
                if(objectp(guards["living"]))
                        message_vision("$N解除对$n的保护。\n", me, guards["living"]);
                if(!undefinedp(guards["exit"]))
                        message_vision("$N解除对"+guards["exit"]+"方向的守卫。\n",me);  
                me->delete_temp("guards");
                write("解除所有守护完毕。\n");
                return 1;
        }  
        else if (arg==me->query("id"))
                return notify_fail("自己怎么保护自己啊？\n");
	else if (me->is_fighting()) 
                return notify_fail("你还在战斗中，还是先顾自己吧。\n");
	else if (me->is_busy()) 
		return notify_fail("你现在正忙着呢。\n");
        else if (!room=environment(me))
                return notify_fail("你还不知自己身在何方呢。\n");
        else if (obj=present(arg,room))
                if(obj->is_character())
                { 
                        if(mapp(guards=me->query_temp("guards")) && guards["living"]==obj)
                        {
                                message_vision("$N解除对$n的保护。\n", me,obj);
                                map_delete(guards,"living");
                                me->set_temp("guards",guards);
                                return 1; 
                        }   
                        else if(mapp(guards=me->query_temp("guards")) && objectp(guards["living"]))
                                message_vision("$N解除对$n的保护。\n", me, guards["living"]);
                        if(!mapp(guards=me->query_temp("guards")))
                                guards=([]);  
                        guards["living"] = obj;
                        me->set_temp("guards",guards);
                        message_vision("$N开始保护$n不受伤害。\n", me, obj);
                        return 1;
                }                         
                else
                { 
                        if(mapp(guards=me->query_temp("guards")) && guards["object"] == obj)
                        {
                                message_vision("$N解除对$n的看守。\n", me, obj);
                                map_delete(guards,"object");
                                me->set_temp("guards",guards);
                                return 1; 
                        }   
                        else if(mapp(guards=me->query_temp("guards")) && objectp(guards["object"]))
                                message_vision("$N解除对$n的看守。\n", me, guards["object"]);  
                        if(!mapp(guards=me->query_temp("guards")))
                                guards=([]);  
                        guards["object"]=obj;
                        me->set_temp("guards",guards);
                        message_vision("$N开始看守$n不被别人拿走。\n", me, obj);
                        return 1;                 
                }
        else if (room->query("exits/"+arg)) 
        {
                if(room->query("no_fight"))
                        return notify_fail("这里禁止战斗！\n");
                if(mapp(guards=me->query_temp("guards")) && guards["exit"]==arg)
                {
                        message_vision("$N解除对"+arg+"方向的看守。\n", me);
                        map_delete(guards,"exit");
                        me->set_temp("guards",guards);
                        return 1; 
                }   
                else if(mapp(guards=me->query_temp("guards"))&&(!undefinedp(guards["exit"]))) 
                        message_vision("$N解除对"+guards["exit"]+"方向的看守。\n", me);  
                if(!mapp(guards=me->query_temp("guards")))
                        guards=([]);     
                guards["exit"]=arg;
                me->set_temp("guards",guards);
                message_vision("$N开始看守"+arg+"方向，不让别人通过。\n", me);
                return 1;                 
        }
        else
                return notify_fail("这里没有你要保护的对象！\n");
}
 
int help(object me)
{
        write(@HELP
指令格式: guard [<物件>|<人物>|<方向>|none]
 
这个指令可以让你看守物件，保护某人，看守某个方向。
 
可以用guard none解除以上操作。
 
用guard查看当前状态。
 
HELP
        );
        return 1;
}
