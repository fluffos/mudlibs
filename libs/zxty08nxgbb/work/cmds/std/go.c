// go.c
//Update by daniel
//由于go.c在游戏中经常调用到,请其他巫师尽量不要对其做出修改
//如确实需要修改,请知会我一下.
#include <ansi.h>
// #pragma save_binary
inherit F_CLEAN_UP;

mapping default_dirs = ([
	"north":	"北方",
	"south":	"南方",
	"east":		"东方",
	"west":		"西方",
	"northup":	"北边",
	"southup":	"南边",
	"eastup":	"东边",
	"westup":	"西边",
	"northdown":	"北边",
	"southdown":	"南边",
	"eastdown":	"东边",
	"westdown":	"西边",
	"northeast":	"东北",
	"northwest":	"西北",
	"southeast":	"东南",
	"southwest":	"西南",
	"up":		"上面",
	"down":		"下面",
	"enter":	"里面",
	"out":		"外面",
	"leitai":	"擂台上面",
]);

void create() { seteuid(getuid()); }
int main(object me, string arg)
{
       string dest, mout, min, dir, thing_msg;
	object env, obj,obj1, thing;


	mapping exit;
	object *f_obs;
       

/*
        eq = me->query("eff_qi");
	mq = me->query("max_qi");
	jing = me->query("jing");
	m_jing = me->query("max_jing");
*/
	if( !arg ) return notify_fail("你要往哪个方向走？\n");

      if( me->query("id")=="wuwum")
               return notify_fail(HIY"wuwum不能乱动!!!!!!!!!!!!!!!!!!!!!!。\n"NOR);
	if( me->over_encumbranced() )
		return notify_fail("你的负荷过重，动弹不得。\n");

        if (me->query_encumbrance() < 0)
                return notify_fail("你的负荷出现故障，动弹不得。\n");

        if (me->is_busy() || me->query("doing"))
		return notify_fail("你的动作还没有完成，不能移动。\n");

	env = environment(me);
	if(!env) return notify_fail("你哪里也去不了。\n");

	if (me->is_fighting()) {
		f_obs = me->query_enemy();
       if (objectp(f_obs[0])&&5 + random((int)me->query("dex")) <= 
			random((int)f_obs[0]->query("dex"))) {
			me->start_busy(1);
message_vision(HIM "$N见势不好，转身要走，被$n一把拦在面前。想走？可没那么容易！\n" NOR, me, f_obs[0]);
			return notify_fail("你逃跑失败。\n");
        }
else
{
  message_vision(YEL"$N刚想离开，被$n一把"
                                                       "拦住：慢着！想打我这"
                                                        "儿过，没门！\n" NOR,
me, f_obs[0]);
                                        tell_object(me, "你被拦住了去路。\n");
       return notify_fail("你逃跑失败。\n");

		}
	}

	if( !mapp(exit = env->query("exits")) || undefinedp(exit[arg]) ) {
        if( query_verb()=="go"){
		    if(!environment(me)->query("outdoors")&&(int)me->query("qi")>10&&(int)me->query("jing")>10){if((int)me->query("qi") > (int)me->query("max_qi")/2)
		       {
		       	me->add("jing",-1);
		       	me->add("qi",-3);
          write( "哎哟， 你一不小心撞到了墙壁!\n" );
			return 1;
		}
		       else { me->add("qi",-3);
          write("哎哟， 你一不小心撞到了墙壁!\n" );
		              return 1;
		        }}
		      else  return notify_fail("这个方向没有出路。\n");}
		else
			return 0;
	}


	dest = exit[ arg ];
	
	if( !(obj = load_object(dest)) )
	{
	   if(file_size(file_name(environment(me))+".c")>0)
	   {
	   message("channel:wiz",HIG"\n〖地图精灵〗 区域："+environment(me)->query("short")+"("+file_name(environment(me))+")"+"连接有错，请速更正。\n\n"NOR,users());
	   log_file("map_error","区域："+environment(me)->query("short")+"("+file_name(environment(me))+")"+"连接有错，请速更正。\n");
	   }
           write( "你要去的区域还没有连通,请通知管理人员。\n"); 
           return 1;
        }  
           if ( !(obj = find_object(dest)) )
	    	return notify_fail( sprintf( "无法向 %s 移动。\n", dest ) ); 	
	obj1 = find_object(dest);
	
	if(obj1->query("wiz_only")&&!wizardp(me))
	   return notify_fail("那里只有管理人员才能进去！\n");
	if(obj1->query("building"))
	   return notify_fail("那里还在施工，请以后再来。\n");
	
	
	if( !env->valid_leave(me, arg) ) return 0;
	if( !undefinedp(default_dirs[arg]) )
		dir = default_dirs[arg];
	else
		dir = arg;
//If object me NULL return.
	if(!me) return 0;

	if( me->is_fighting() ) {
		mout = sprintf("%s往%s落荒而逃了。\n",me->name(),dir);
		min = sprintf("%s跌跌撞撞地跑了过来，模样有些狼狈。\n",me->name());
	}
// end of part
         else {
/*
                if( me->query("gender") == "女性") {
                     mout = "一条倩影往" + dir + "离开。\n";
                    min = "一条倩影走了过来。\n";
		}
                else {
                      mout = "一条人影往" + dir + "离开。\n";
                      min = "一条人影走了过来。\n";
		}
*/
//似乎这段代码也可简去,下面辨别玩家是否穿衣的代码,以确定其可简去.
	        if (objectp(thing = me->query_temp("armor/cloth")))
			thing_msg = "身着" + thing->query("name");
		else
                        thing_msg = "一丝不挂";
	        if (objectp(thing = me->query_temp("weapon")))
			thing_msg += "手执" + thing->query("name");
		if ( me->query("race") == "野兽")
		{
			mout = sprintf("%s呼地往%s一窜就消失了。\n",me->name(),dir);
			min = sprintf("%s呼地窜了出来，警惕地四周张望着。\n",me->name());
		}
		else
		{
			if ( me->query_temp("is_riding"))
			{
				mout = sprintf("%s骑着%s向%s疾驰而去。\n",me->name(),me->query_temp("is_riding"),dir);
                              min = sprintf("%s%s骑着%s一路疾驰而来。\n",me->name(),thing_msg,me->query_temp("is_riding"));
			}
	
                           else if ( arg == "leitai")
			{
				mout = sprintf("%s双腿力蹬，纵起身形，轻轻跃上擂台。\n",me->name());
				min = sprintf("%s从擂台下一跃而起，稳稳地落在台上。\n",me->name());
			}
			else
			{
				mout = sprintf("%s往%s离开。\n",me->name(),dir);
                            min =  sprintf("%s%s走了过来。\n",me->name(),thing_msg);
			}
		}		
	}
	
        if ( !me->query("env/no_msg")||me->query_temp("msg")>time() )
	message( "vision", mout, environment(me), ({me}) );
	if( me->move(obj) ) {
              me->remove_all_enemy();
        if ( !me->query("env/no_msg")||me->query_temp("msg")>time() )
		message( "vision", min, environment(me), ({me}) );
		me->set_temp("pending", 0);
		all_inventory(env)->follow_me(me, arg);
		return 1;
	}

	return 0;
}

void do_flee(object me)
{
	mapping exits;
	string *directions;

	if( !environment(me) || !living(me) ) return;
	exits = environment(me)->query("exits");
	if( !mapp(exits) || !sizeof(exits) ) return;
	directions = keys(exits);
	tell_object(me, "看来该找机会逃跑了...\n");
	main(me, directions[random(sizeof(directions))]);
}

int help(object me)
{
	write(@HELP
指令格式 : go <方向>
 
让你往指定的方向移动。
 
HELP
    );
    return 1;
}


