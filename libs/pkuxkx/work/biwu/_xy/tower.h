#include <ansi.h>
int do_push()
{
	object me = this_player();
	
	if(this_object()->query_temp("open"))
		{ 
			return notify_fail("门已经推开了，你还想推什么？\n");
		}
    if( me->query_temp("xiangyang/pushed") ) 
		{ 
			return notify_fail("你你刚刚推过门，一时半会再也推不动了。\n");
		}
    else 
		{      
			message_vision("$N使出吃奶的劲，向铁门推去。\n", me);
            check(me);    
        }
    return 1; 
}

int do_lan()
{
	object qic,qie,qiw,qin,qis;
	qic= load_object(__DIR__"cityhall");
	qie= load_object(__DIR__"shizilou");
	qiw= load_object(__DIR__"kuixinglou");
	qin= load_object(__DIR__"linhanlou");
	qis= load_object(__DIR__"zhongxuanlou");
	message_vision("$N从城楼向下望去，襄阳城内形势尽收眼底。\n", this_player());
	if(qic->query("flag_owner"))
		{
			tell_object(this_player(),HIC"府衙帅旗被"+(qic->query("flag_owner"))+"夺得。\n"NOR);
		}
	else
		{
			tell_object(this_player(),HIC"现在暂时未有门派控制帅旗。\n"NOR);
		}
    if(qie->query("flag_owner"))
		{
			tell_object(this_player(),CYN"狮子楼苍龙旗被"+(qie->query("flag_owner"))+"夺得。\n"NOR);
		}
	else
		{
			tell_object(this_player(),CYN"现在暂时未有门派控制苍龙旗。\n"NOR);
		}
	if(qiw->query("flag_owner"))
		{
			tell_object(this_player(),HIW"魁星楼白虎旗被"+(qiw->query("flag_owner"))+"夺得。\n"NOR);
		}
	else
		{
			tell_object(this_player(),HIW"现在暂时未有门派控制白虎旗。\n"NOR);
		}
	if(qin->query("flag_owner"))
		{
			tell_object(this_player(),WHT"临汉楼玄武旗被"+(qin->query("flag_owner"))+"夺得。\n"NOR);
		}
	else
		{
			tell_object(this_player(),WHT"现在暂时未有门派控制玄武旗。\n"NOR);
		}
	if(qis->query("flag_owner"))
		{
			tell_object(this_player(),HIR"仲宣楼朱雀旗被"+(qis->query("flag_owner"))+"夺得。\n"NOR);
		}
	else
		{
			tell_object(this_player(),HIR"现在暂时未有门派控制朱雀旗。\n"NOR);
		}
	return 1;
}
