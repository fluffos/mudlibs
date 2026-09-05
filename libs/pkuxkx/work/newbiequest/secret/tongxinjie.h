//tongxin.h 同心结公共函数

void get_user_list()
{
	string *users;
	users=explode(read_file(__DIR__"allow_list"),"#");
	set("allowlist", users);
}

void init()
{
	add_action("do_password",   "anhao");
  add_action("do_summon",     "tongxin");
}

//先设置好暗号，并且第一次使用设置初始使用次数五次
int do_password(string arg)
{
	object me,op;
	
	me=this_player();
	if(me!=environment()||!query("equipped"))
		return notify_fail("同心结只有带在身上才有效果！\n");
	else if(!me->query("marry/lover"))
		return notify_fail("同心结只针对已婚人士！\n");
	else if(member_array(me->query("id"),query("allowlist"))==-1&&!wizardp(me))
		return notify_fail("你不能使用这个同心结！\n");
	else if(!(op=present(me->query("marry/lover"),environment(me))))
		return notify_fail("同心结只有双方都在场的时候才能发挥作用！\n");
	else if(!arg)
		return notify_fail("你没有输入你想要设置的口令！\n");
	
	if(!me->query("tongxinjie/times")) {
		me->set("tongxinjie/times",5);
		me->set("tongxinjie/password", arg);
		tell_object(me, "你第一次设置同心结的口令，目前同心结还可以使用五次"+HIR"“永结同心”"NOR+"。\n");
	}
	else {
		me->set("tongxinjie/password", arg);
		tell_object(me, "你重新设置了同心结的口令，目前同心结还可以使用"+chinese_number(me->query("tongxinjie/times"))+"次"+HIR"“永结同心”"NOR+"。\n");
	}
	return 1;
}

//永结同心
int do_summon(string arg)
{
	object me,op,env,tobj;
	string *allow_locate=
	({"baituo","beijing","changbai","city","dali",
		"dalicheng","dalunsi","emei","gaibang","guiyunzhuang",
		"gumu","hangzhou","huashan","huijiang","lingjiu",
		"lingxiao","lingzhou","luoyang","mingjiao","murong",
		"pingxiwangfu","pker","quanzhou","quanzhen","riyuejiao",
		"ruyang-wangfu","shaolin", "shenlongdao", "suzhou", "taishan",
		"taohuadao", "tianlong", "village", "wudang", "wuliang",
		"xiangyang", "xingxiu", "yashan"});
	string *mepath,*oppath;

  me=this_player();
	if(me!=environment()||!query("equipped"))
		return notify_fail("同心结只有带在身上才有效果！\n");
	else if(!me->query("marry/lover"))
		return notify_fail("同心结只针对已婚人士！\n");
	else if(member_array(me->query("id"),query("allowlist"))==-1&&!wizardp(me))
		return notify_fail("你不能使用这个同心结！\n");
	else if(!arg)
		return notify_fail("你没有输入对方的暗号！\n");
 
  foreach(tobj in users())
  	if(tobj->query("id")==me->query("marry/lover")) {
  		op=tobj;
  		break;
  	}

  if(!op)
		return notify_fail("同心结只有双方同时在线的时候才能发挥作用！\n");
	else if(!(env=environment(op))||!env->isroom())
		return notify_fail(op->query("name")+"处于未知空间，无法执行"+HIR"“永结同心”"NOR+"。\n");

//进行房间检查，如果房间不是位于/d下面的列表内区域则无法进行本操作。	
	mepath=explode(file_name(environment(me)),"/");
	oppath=explode(file_name(env),"/");
	if(mepath[0]!="d"||member_array(mepath[1],allow_locate)==-1)
		return notify_fail("你所在的房间无法进行"+HIR"“永结同心”"NOR+"操作。\n");
	else if(oppath[0]!="d"||member_array(oppath[1],allow_locate)==-1)
		return notify_fail(op->query("name")+"所在的房间无法进行"+HIR"“永结同心”"NOR+"操作。\n");
	
	if(!me->query("tongxinjie/password")||!op->query("tongxinjie/password"))
		return notify_fail("你们中有人没有设置暗号（anhao），无法进行"+HIR"“永结同心”"NOR+"操作！\n");
	else if(me->query("tongxinjie/times")<=0||op->query("tongxinjie/times")<=0)
		return notify_fail("你们已经无法再使用"+HIR"“永结同心”"NOR+"了！\n");
  else if(arg!=op->query("tongxinjie/password"))
  	return notify_fail("你们两个还没有达到心心相印的地步，无法进行"+HIR"“永结同心”"NOR+"操作！\n");
  
  tell_object(me, "你拿着"+query("name")+"心理默念着："+HIR"“永结同心”"NOR+"，对方似乎感应到你的想法！");
  tell_object(op, "你心理突然察觉到远方传来一个熟悉的声音："+HIR"“永结同心”"NOR+"，在一阵亮光中"+me->query("name")+"走了过来！\n");
  me->add("tongxinjie/times",-1);
  op->add("tongxinjie/times",-1);
  me->move(env);
  return 1;
}