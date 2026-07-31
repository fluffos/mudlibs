// go.c
#include <ansi.h>
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
	string dest, mout, min, dir, blk, gud, skill, face, thing_msg;
string sbuffer,file,path,wild;
	object env, obj, blocker, thing;
	mapping block;
	mixed old_target;
	int result;
	int sen_cost;
	mapping exit;
	object *f_obs, *ob;
        object user;
        object *users;
//for 太挤
	int i, my_dex, count = 0;

	if( !arg ) return notify_fail("你要往哪个方向走？\n");

        if( (int)me->query_encumbrance() > (int)me->query_max_encumbrance() ) 
		return notify_fail("你的负荷过重，动弹不得。\n");

	if( me->over_encumbranced() )
		return notify_fail("你的负荷过重，动弹不得。\n");

        if ( me->query_temp("biguan") )
                return notify_fail("你现在正在坐关。\n");

	if (me->query("water") == 0 && me->query("food") == 0 && userp(me))
		    me->add("jing", -(1+random(2)));
	if ( me->query("jing") <= 8 )
		return notify_fail("你已经没有力气再走路了，休息一下吧。\n");

	if( me->is_busy() )
		return notify_fail("你的动作还没有完成，不能移动。\n");

	env = environment(me);
	if(!env) return notify_fail("你哪里也去不了。\n");



	if (!me->is_fighting() && random(88)==0 && !me->is_busy()) {
    if(environment(me)->query("short")==BLU"山洞"NOR
       ||environment(me)->query("short")==WHT"钟乳石洞"NOR
       ||environment(me)->query("short")==YEL"岩洞"NOR
       ||environment(me)->query("short")==RED"熔岩洞"NOR
       ||environment(me)->query("short")==CYN"石洞"NOR 
       ||environment(me)->query("magicset")==1
       ||environment(me)->query("maze")
       )
{
			me->start_busy(2);
			return notify_fail("附近全是道路，让你心神一乱。\n");
}
}

	if (me->is_fighting()) {
		f_obs = me->query_enemy();
		if (objectp(f_obs[0]))
		if (5 + random((int)me->query("dex")) <= 
			random((int)f_obs[0]->query("dex"))) {
			me->start_busy(1);
                        message_vision("$N见势不好，转身要走，被$n一把拦在面前。想走？可没那么容易！\n", me, f_obs[0]);
			return notify_fail("你逃跑失败。\n");
		}
    if(environment(me)->query("short")==BLU"山洞"NOR
       ||environment(me)->query("short")==WHT"钟乳石洞"NOR
       ||environment(me)->query("short")==YEL"岩洞"NOR
       ||environment(me)->query("short")==RED"熔岩洞"NOR
       ||environment(me)->query("short")==CYN"石洞"NOR 
       ||environment(me)->query("magicset")==1
       ||environment(me)->query("maze")
       )
{
//if ( random(3)==0)
//{
			me->start_busy(2);
                        message_vision("$N见势不好，转身要走，被$n一把拦在面前。想走？可没那么容易！\n", me, f_obs[0]);
			return notify_fail("附近全是路 你逃跑失败。\n");
//}
}

if( environment(me)->query("magicroom") ||environment(me)->query("maze"))
{
//if (random(3)==0)
//{
			me->start_busy(2);
//                        message_vision("$N见势不好，转身要走，被$n一把拦在面前。想走？可没那么容易！\n", me, f_obs[0]);
			return notify_fail("附近全是路 你逃跑失败。\n");
//}
}

if (me->query_condition("huaxunshan") || me->query_condition("shaolin_song")|| me->query_condition("lingjiu_song")
&& userp(me)) {
            message_vision("$N你正在做任务不能乱跑,身上负有重责！\n", me);
			return notify_fail("你逃跑失败。\n");
		}
            if (present("letter", me)||present("biao",me)||present("prize",me)){
            message_vision("$N你身上有重要的任务物品,不能乱逃！\n", me);
			return notify_fail("你逃跑失败。\n");
		}
	}

// 守卫的问题
file=base_name(env) + ".c";
if (file)
{
        sbuffer=read_file(file);
} else sbuffer=" ";
if (!userp(me) && sbuffer && !me->query_leader()
)
{                            
// && strsrch(sbuffer, "::valid_leave") >= 0        
// && strsrch(sbuffer, "int") >= 0
        if (strsrch(sbuffer, "move") >= 0
        && strsrch(sbuffer, "中央广场") <= 0)
	return notify_fail("这个ROOM有特殊作用！\n");
        if (strsrch(sbuffer, "destruct") >= 0
        && strsrch(sbuffer, "中央广场") <= 0)
	return notify_fail("这个ROOM有特殊作用！\n");
}

	result = env->valid_leave(me, arg);
	
	if(env->query("hxsdmigong"))
return 1;
	
	if ( result < 0 ) return 1;
	else if ( !result ) return 0;



	if( !mapp(exit = env->query("exits")) || undefinedp(exit[arg]) ) {
		if( query_verb()=="go" && env->query("hxsdmigong"))
			return 1;
		else if( query_verb()=="go")
			return notify_fail("这个方向没有出路。\n");
		else
			return 0;
	}
/*
	if ( mapp(block = env->query("blocks")) && ( blk = block[arg] ) )
	{
		if ( objectp(blocker = present(blk, env)) &&  living(blocker) )	
		{
			if ( !env->query("block_msg") )
				return notify_fail("你正打算移动，却被"
				+ blocker->name() + "挡住了去路 。\n");	
		return notify_fail( env->query("block_msg") );             
		}
	}

	if ( old_target = me->query_temp("guardfor") )
	{
		if(objectp(old_target))
		{
			if( living(old_target) )
			tell_object(me,"你放弃保护"+old_target->name()+"。\n");
			else
        		tell_object(me,"你不再理会"+old_target->name()+"，径直走了。\n");
		}
		else 
		tell_object( me, "你不再守住这里往"+default_dirs[old_target]+"的方向，离开了这里。\n" );
		me->delete_temp("guardfor");
	}
*/
	dest = exit[ arg ];


 	if ( !(obj = find_object(dest)) )
{

 /*dest=replace_string(dest,"/entry","");
dest=replace_string(dest,"/exit","");
 if ( (obj = find_object(dest)))
{
//seteuid(getuid());
destruct(obj);
load_object(dest);
//log_file("log", MUD_NAME + "处理迷宫出错：" + base_name(environment(me)) +"\n", 1);
}
*/
 if (!load_object(dest))
{
log_file("log", MUD_NAME + "错误文件：" + base_name(environment(me)) +"\n", 1);
log_file("log", MUD_NAME + "错误路径：" + dest +"\n", 1);
 return notify_fail( sprintf( "无法向 %s 移动。\n", dest ) );
}


dest = exit[ arg ];
}


	if ( !(obj = find_object(dest)) )
	    	call_other( dest, "???" );
	if ( !(obj = find_object(dest)) )
	    	return notify_fail( sprintf( "无法向 %s 移动。\n", dest ) );
        //if (!me) return notify_fail( sprintf( "无法向 %s 移动。\n", dest ) );


        if (!me) return notify_fail( sprintf( "无法向 %s 移动。\n", dest ) );
	if ( me && me->query_temp("is_riding") &&
	    (arg=="up" || arg=="down" || arg=="leitai" || arg=="enter" || arg=="out"))
		return notify_fail("这个方向没法骑在座骑上过去。\n");

// 移动前方是否太挤? 擂台上不超出2人
	if ( arg == "leitai")
	{
                return notify_fail("只有wiz发令你才能上擂台。\n");
		ob = all_inventory(obj);
		for(i=0; i<sizeof(ob); i++)
//			if( living(ob[i]) && ob[i] != me )
				count++;
	if (count>2)
		return notify_fail("擂台上人太多了，你上去找扁去？\n");
/*
	my_dex = (int)me->query_dex();
	if (!wizardp(me) &&
	    (((my_dex < 15) && (count > 6)) ||
	    ((my_dex < 20) && (count > 8)) ||
	    ((my_dex < 30) && (count > 10)) ||
	    ((my_dex < 40) && (count > 12))))
		return notify_fail("前面人太多了，你怎么挤也挤不过去。\n");
*/
	}
file=base_name(obj) + ".c";
if (file)
{
        sbuffer=read_file(file);
} else sbuffer=" ";
if (!userp(me) && sbuffer && !me->query_leader()
)
{
        if (strsrch(sbuffer, "move") >= 0
                && strsrch(sbuffer, "中央广场") <= 0)
	return notify_fail("这个ROOM有特殊作用！\n");
        if (strsrch(sbuffer, "destruct") >= 0
                && strsrch(sbuffer, "中央广场") <= 0)
	return notify_fail("这个ROOM有特殊作用！\n");
}

	if( !env->valid_leave(me, arg) ) return 0;
        if (!userp(me) && environment(me)==obj
        && !me->query_leader())
	return notify_fail("NPC不能去那个地方。\n");
        if (!userp(me) && obj->query("no_npc")&& !me->query_leader()
        )
	return notify_fail("NPC不能去那个地方。\n");


        if (!userp(me) && obj->query("no_fight") && !me->query_leader() && me->query("taskid")
        )
	return notify_fail("NPC不能去那个地方。\n");



        if (!userp(me) && arg == "leitai")
	return notify_fail("NPC不能去那个地方。\n");

        dir = obj->query("short");
        if (!undefinedp(default_dirs[arg]))
                dir = default_dirs[arg] + "的" + dir;

//	if( !undefinedp(default_dirs[arg]) )
//		dir = default_dirs[arg];
//	else
//		dir = arg;

	if( me->is_fighting() ) {
		mout = me->name() + "往" + dir + "落荒而逃了。\n";
		min = me->name() + "跌跌撞撞地跑了过来，模样有些狼狈。\n";
	}
	else
	if( wizardp(me) && me->query("env/invisibility") && (wiz_level(me) >= wiz_level(env)))
	{
		mout = "";
		min = "";
	}
	else
	{
		face="的";
		if (me->query("gender")=="女性")
		{
			if (me->query("per") >= 30) face ="娇艳绝伦" + face;
			if ((me->query("per") >= 28) && (me->query("per") < 30)) face= "清丽绝俗" + face;
			if ((me->query("per") >= 26) && (me->query("per") < 28)) face= "风情万种" + face;
			if ((me->query("per") >= 24) && (me->query("per") < 26)) face= "容色秀丽" + face;
			if ((me->query("per") >= 21) && (me->query("per") < 24)) face= "面目姣好" + face;
			if (me->query("str") <= 16) face = "亭亭玉立" + face;
			if ((me->query("str") <= 20) && (me->query("str") > 16)) face= "体态轻盈"+ face;
			if ((me->query("per")<21) && (me->query("str")>20) || !userp(me)) face = "";
		}
		else
		{
			if (me->query("per") >= 30) face= "玉树临风般" + face;
			if ((me->query("per") >= 26) && (me->query("per") < 30)) face="英俊潇洒" + face;
			if ((me->query("per") >= 22) && (me->query("per") < 26)) face="仪表堂堂" + face;
			if (me->query("str") >=23) face = "身材壮硕" + face;
			if ((me->query("str") >= 20) && (me->query("str") < 23)) face= "膀大腰圆"+ face;
			if ((me->query("per")<22) && (me->query("str")<20) || !userp(me)) face = "";
		}
	        if (objectp(thing = me->query_temp("armor/cloth")))
			thing_msg = "身着" + thing->query("name");
		else
			thing_msg = "全身清洁溜溜";
	        if (objectp(thing = me->query_temp("weapon")))
			thing_msg += "手执" + thing->query("name");
		if ( me->query("race") == "野兽")
		{
			mout = me->name() + "呼地往" + dir + "一窜就消失了。\n";
                        min = me->name() + "从" + env->query("short") + "呼地窜了出来，警惕地四周张望着。\n";
		}
		else
		{
			if ( me->query_temp("is_riding"))
			{
				mout = me->name()+"骑着"+me->query_temp("is_riding")+"向" + dir + "疾驰而去。\n";
				min = face + me->name() + thing_msg + "从" + env->query("short") + "骑着"+me->query_temp("is_riding")+"一路疾驰而来。\n";
			}
			else
			if ( arg == "leitai")
			{
				mout = me->name()+"双腿力蹬，纵起身形，轻轻跃上擂台。\n";
				min = me->name()+"从擂台下一跃而起，稳稳地落在台上。\n";
			}
			else
			{
				mout = me->name() + "往" + dir + "离开。\n";
				min = face + me->name() + thing_msg + "从" + env->query("short") + "走了过来。\n";
			}
		}
	}
if (! wizardp(me) )
        {	
users = filter_array(all_inventory(environment(me)), 
                                    (: (userp($1) || $1->want_receive_msg()) &&
                                    ! $1->query("env/no_moutmsg") :)) - ({ me }); 
                if (sizeof(users) > 0)
                        foreach (user in users) 
                                message("tell_object", mout, user); 
}
	//message( "vision", mout, environment(me), ({me}) );
//message( "vision", obj->query("name"), environment(me), ({me}) );


	
	if( me->move(obj) ) {
		me->remove_all_enemy();
		
		
        if (objectp(obj) )
                // message("vision", min, dest, ({ me }));
        {
                users = filter_array(all_inventory(obj), 
                                    (: (userp($1) || $1->want_receive_msg()) &&
                                    ! $1->query("env/no_minmsg") :)) - ({ me }); 
                if (sizeof(users) > 0)
                        foreach (user in users) 
                                message("tell_object", min, user); 
        }
if (env)
	{
ob = all_inventory(obj);
		for(i=0; i<sizeof(ob); i++)
{
if (userp(ob[i]) && ob[i]->query_temp("xmud")  && !obj->query("hxsdmigong")) 
{
	ob[i]->force_me("xkango");
  if  (me==ob[i]) message("tell_object", ob[i]->query("name")+"进入了"+obj->query("short")+"。\n", ob[i]); 
}
}	
if (env)
{
ob = all_inventory(env);
		for(i=0; i<sizeof(ob); i++)
{
if (userp(ob[i]) && ob[i]->query_temp("xmud") && !obj->query("hxsdmigong") ) 
{
	ob[i]->force_me("xkango");
 if  (me==ob[i]) message("tell_object", ob[i]->query("name")+"进入了"+obj->query("short")+"。\n", ob[i]); 
}
}	
}
}
		if (me) me->set_temp("pending", 0);
	if (env)	all_inventory(env)->follow_me(me, arg);
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


