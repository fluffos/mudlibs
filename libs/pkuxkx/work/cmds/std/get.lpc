  // get.c

#include <ansi.h>

inherit F_CLEAN_UP;

int do_get(object me, object ob);

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
        string from, item,msg;
        object obj, *inv, env, obj2 ,obj3 ,obj4;
        int i, amount, found;  
        mapping guarding;

        if( !arg ) return notify_fail("你要捡起什么东西？\n");
        if( me->is_busy() )
                return notify_fail("你上一个动作还没有完成！\n");
				
//				if(time() - me->query_temp("last_get_time") < 1)
//			    return notify_fail("你的腰还没直起来，又捡？\n");

//				me->set_temp("last_get_time",time());

        // Check if a container is specified.
        if( sscanf(arg, "%s from %s", arg, from)==2 ) 
        {
             env = present(from, me);
             if(!env) env = present(from, environment(me));
             if(!env) return notify_fail("你找不到 " + from + " 这样东西。\n");
        } 
        else 
        	 env = environment(me);
        if(!env->query_max_encumbrance()) return notify_fail("你确认有东西在这里面？\n");

        if(living(env) && (!wizardp(me) || wiz_level(me) <= wiz_level(env)))
             return notify_fail("你的巫师等级必须比对方高，才能搜身。\n");
        if (wiz_level(me)<SECURITY_D->get_wiz_level("(immortal)") && env->query("no_get_from"))
             return notify_fail("光天化日的想抢劫啊？\n");
		

        // Check if a certain amount is specified.   
        
        if(sscanf(arg, "%d %s", amount, item)==2) {
                if( !objectp(obj = present(item, env)) )
                {
/*                		found = 0;
                		inv = all_inventory(env);
                		for (i=sizeof(inv)-1;i>=0;i--)
                			if (COLOR_D->uncolor(inv[i]->query("name")) == item)
                			{
                				obj = inv[i];
                				found = 1;
                			}
                		if (!found)*/
										//以上代码在东西多的时候消耗资源太多了。present还可以接受，可能会有hash算法。
//										log_file("getnoexist.log",me->query("id")+" get "+item+" at "+ctime(time())+"\n");
                        return notify_fail("这里没有这样东西。\n");
                }
                if( !obj->query_amount() )
                        return notify_fail( obj->name() + "不能被分开拿走。\n");
                if( amount < 1 )
                        return notify_fail("东西的个数至少是一个。\n");
                if( amount > obj->query_amount() )
                        return notify_fail("这里没有那么多的" + obj->name() + "。\n");
                else if( amount == (int)obj->query_amount() ) {
                        return do_get(me, obj);
                                    
                } else {
                        // Counting precise amount costs more time.
                        if( me->is_fighting() ) me->start_busy(3);
                        obj2 = new(base_name(obj));
                        obj2->set_amount((int)obj->query_amount() - amount);
                        obj->set_amount(amount);
                        do_get(me, obj);
                        //如果obj2先move到env，则会和obj合并，导致get后余下数量的combined item消失
                        obj2->move(env);                        // For containers.
                        return 1;
                }
        }

        // Check if we are makeing a quick get.
        if(arg=="all") {
                        if  (time() - me->query_temp("last_dropgetall_cmd_time") < 30)
                                return notify_fail("你刚刚整理过太多东西，休息一会儿吧！\n");
                if( me->is_fighting() ) return notify_fail("你还在战斗中！只能一次拿一样。\n");

                inv = all_inventory(env);
                if( !sizeof(inv) )
                        return notify_fail("那里面没有任何东西。\n");
                if (sizeof(inv) > 200 && userp(me))
                	return notify_fail("那里面东西太多了，你没法一下全拿走，一样一样拿吧！\n");
				        me->start_busy(1);
                for(i=0; i<sizeof(inv); i++) {
                        if( inv[i]->is_character() || inv[i]->query("no_get") ) continue;
						//看不到的东西不能拿走
						if( !me->visible(inv[i])) continue;
                        do_get(me, inv[i]);
                }
                if (sizeof(inv) > 30)
                                me->set_temp("last_dropgetall_cmd_time",time());
                                           
                write("Ok。\n");
                return 1;
        }

        if( !objectp(obj = present(arg, env)) )
    	{
/*                		found = 0;
                		inv = all_inventory(env);
                		for (i=sizeof(inv)-1;i>=0;i--)
                			if (COLOR_D->uncolor(inv[i]->query("name")) == arg)
                			{
                				obj = inv[i];
                				found = 1;
                			}
                		if (!found)*/
//										log_file("getnoexist.log",me->query("id")+" get "+arg+" at "+ctime(time())+"\n");
	                        return notify_fail("你附近没有这样东西。\n");
        }
        if( obj->query("disable")&& obj->query("disable_type") !=" <昏迷不醒>")
                return notify_fail("你附近没有这样东西。\n");  

        if( obj->query("no_get") && (!obj->query("auto_load") || !obj->query("owner")==me->query("id")) )
        {
            if (!stringp(obj->query("no_get")))
            {
                return notify_fail("这个东西拿不起来。\n");
            }
            else
            {
                msg=obj->query("no_get");
                return notify_fail(msg+"\n");
            }
        }
		if (obj->query("no_fullme_no_get")&&me->query("antirobot/deactivity"))
		{
			if (!stringp(obj->query("no_fullme_no_get")))
            {
                return notify_fail("此物当有德者居之，有能者获之。\n");
            }
            else
            {
                msg=obj->query("no_fullme_no_get");
                return notify_fail(msg+"\n");
            }
		}
        return do_get(me, obj);
}
        
int do_get(object me, object obj)
{
        object old_env, *enemy;
        int equipped;  
        object *inv;
        int i;
        object room,where;

       
        if( !obj ) return 0;
        old_env = environment(obj);

        if(userp(me) && userp(old_env) && !me->is_realuser() && !wizardp(me))
        {
            write("你不能对玩家搜身！\n");
            return 1;
        }
         
        inv = all_inventory(old_env);  
        for(i=0;i<sizeof(inv);i++)
           { 
            if( !living(inv[i]) ) continue;
            else if(inv[i]!=me && inv[i]->query_temp("guards/object")==obj )
                return notify_fail(inv[i]->query("name")+"正在看守"+obj->query("name")+"，你无法拿走！\n");  
           }                     
        if(me->query_temp("guards/object")==obj)
            me->delete_temp("guards/object");
        if(userp(me) && obj->query("is_yuxi") && obj->query_temp("owner/id")!=me->query("id"))
                return notify_fail("不属于自己的东西不要乱动。\n");
        if(userp(me) && obj->query("is_map") && obj->query("owner")!=me->query("id"))
                return notify_fail("不属于自己的东西不要乱动。\n");          
        if( obj->is_character() ) 
        {
                if( living(obj) && ( obj != me->query_temp("created_pet") ) ) return 0;
                //      if( !userp(obj) && !obj->is_corpse() )
                //              return notify_fail("你只能背负其他玩家的身体。\n");
                // If we try to save someone from combat, take the risk :P
        } else 
        {
                if( obj->query("no_get") )
                  if (!obj->query("auto_load") || !obj->query("owner")==me->query("id")) 
                    return 0;
        }

        if( obj->query("equipped") ) equipped = 1;
         if ( obj == me->query_temp("created_pet") )
         {
                 seteuid(getuid());
	room=new("/adm/single/temproom");
	inv=all_inventory(obj);
	for(i=0;i<sizeof(inv);i++)
		inv[i]->move(room);
	obj->set_temp("block_msg/all", 1);
	where = environment(obj);
	obj->move("/clone/misc/tmp_void",1);		
	obj->disable_player("<>");
	obj->move(where);//jason add this lines to avoid add_action crash

	inv=all_inventory(room);
	for(i=0;i<sizeof(inv);i++)
		inv[i]->move(obj);
	destruct(room);
         }
        if( obj->move(me) ) {
                if( me->is_fighting() ) me->start_busy(1);
                if( obj->is_character() ) {
                        if( obj == me->query_temp("created_pet") )
                         {
                                message_vision( "$N伸手将$n抱了起来，搂在怀里。\n", me, obj );
                         }
                        else
                                message_vision( "$N将$n扶了起来背在背上。\n", me, obj );
                }
                else
                        message_vision( sprintf("$N%s一%s$n。\n", 
                                old_env==environment(me)? "捡起":
                                        (old_env->is_character() ?
                                                "从" + old_env->name() + "身上" + (equipped? "除下" : "搜出"):
                                                "从" + old_env->name() + "中拿出"),
                                obj->query("unit")), me, obj );
                if (random(2)&&!wizardp(me)&&userp(old_env)&&(time()-me->query_temp("last_rumor")>=3))
                {
                me->set_temp("last_rumor",time());
                CHANNEL_D->do_channel(obj,"rumor","听说"+me->query("name")+ "(" +me->query("id")+ ")" +"这个臭不要脸的搜" 
                + old_env->name() + "身的时候被路边小乞丐抓住啦！\n");
                }
                return 1;
        }
        else return 0;
}

int help(object me)
{
        write(@HELP
指令格式 : get <物品id或中文名> [from <容器名>]
 
这个指令可以让你捡起地上或容器内的某样物品.
 
HELP
    );
    return 1;
}
