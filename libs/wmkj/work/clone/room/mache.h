// File:/clone/room/mache.h
//本文件只需要在需要作为驿站的房间里增加#include就可以，同时应该注意函数不能重复定义！
//write by JackyBoy for SNOW 1999/11/5
#include <ansi.h>

#define YIZHAN_INI "/clone/room/mache.ini"
#define TIME1 10
#define TIME2 15
//注意mache在leave和arrive过程中可能被reset或者clean_up的情况发生造成变量丢失！

//输入qu 后，如果没有任何人存在则，直接call_out leave，同时call_out超时马车上的控制函数go_back
//如果已经有人，并且马车未走则直接move进车
void init()
{
	add_action("do_gu", "gu");
	add_action("do_qu", "qu");
}

int check_trigger(object me)
{
	object room, where;
	string *sites,*site,file;
	int i;
	where = environment(me);
	if( !(room = find_object("/clone/room/mache")) )
	room = load_object("/clone/room/mache");
	file = read_file(YIZHAN_INI);
	if(!file)
		return notify_fail("对不起，驿站现在没有分站，暂时无法营业！\n");
	else
		sites=explode(file,"\n");
	if( room = find_object("/clone/room/mache") )
	{
		if((int)room->query("che_trigger")==0)
		{
			message_vision("小二高叫一声：“来喽！”声音未落，小二已经牵着一辆两匹马的乌篷车转了出来。\n", me);
			message_vision("小二笑着说：您真是好运气，本驿站刚刚开张，免费大酬宾。\n"+
				"\t您说去哪就行了(type qu XXX)。\n", me);
			message_vision("小二说：现在我们在以下地方设有分站，您可以雇车去那里：\n",me);
			for(i=0;i<sizeof(sites);i++)
			{
				site=explode(sites[i],";");
				message_vision(site[0]+"("+site[1]+")\t",me);
				if((i+1)%3 == 0 )
					message_vision("\n",me);
			}
			message_vision("\n",me);
			me->set_temp("guche", 1);
		}        
		else 
			message_vision("小二满脸歉意地说：“这位客官，现在车都出去了,您等会好吗?”\n", me);
	}
	else
		return notify_fail("对不起，马车有问题了！\n");
}

int do_gu(string arg)
{
	object me;
	me = this_player();
	if(!arg || (arg != "che" && arg !="马车" && arg !="车"))
		return notify_fail("你要雇什么？这里只有马车(che)可以雇。\n");
	message_vision("$N拍拍门板，叫道：喂，有人吗？雇车！！！\n", me);
	check_trigger(me);
	return 1;
}

int do_qu(string arg, int num)
{
	object room, me,where;
	string dest;int i;
	string *sites,*site,file;
	me=this_player(1);
	where = environment(me);
	if( !(room = find_object("/clone/room/mache")) )
		room = load_object("/clone/room/mache");
	if(!objectp(room))
		return notify_fail("呀，没有马车了，跟巫师报告一下吧。\n");
	file = read_file(YIZHAN_INI);
	//这里file值应该不为空了！
	sites=explode(file,"\n");
	me = this_player();
	where = environment(me);
	if (!me->query_temp("guche"))
		return notify_fail("根本没有人理你，你觉得自己真傻。\n");
	if (!arg)
		return notify_fail("你倒是说去哪呀！\n");
	dest="";
	for(i=sizeof(sites);i>0;i--)
	{
		site=explode(sites[i-1],";");
		if(site[1]==arg||site[0]==arg)//允许输入汉字或者英文，但是后面一律靠中文来判断！
		{
			//在配置文件中寻找玩家想去的地方是否存在，如果在则设置arg为该地方的中文名
			arg=site[0];
			//记录符合条件的记录在sites里的下标值
			//获取目标地方的文件名
			dest=site[2];
		}
	}
	if(dest=="")
		return notify_fail("对不起，"+arg+"那里没有分站！\n");
	if(dest==(base_name(this_object())) )
		return notify_fail("你已经在这里了啦！你到底想去哪里啊？！\n");
	if( room->query("che_trigger"))
	{
		message_vision("小二对$N满脸歉意地说：“这位客官，现在车都出去了,您等会好吗?”\n", me);
		return 1;
	}
	else
	{
		message_vision("$N坐进了马车，对马夫说：“去"+HIW+arg+NOR+"。”\n\n", me);
		//如果已经有人在坐，则判断是否同路！否则就直接上路
		if(!room->query_temp("mached"))
		{
			message_vision("马夫笑着说道：“好的客官，马上就上路。”\n\n", me);
			room->set_temp("mached",arg);
			me->set_temp("mache_start",base_name(this_object()));
			call_out("leave", TIME1, me,room,dest);
			me->move("/clone/room/mache");
			return 1;
		}
		else
		{
			if(arg == (string)room->query_temp("mached") )
			{
				message_vision("马夫笑着说道：“正好车里的客官也要去那里，你们就一道走吧，我马上就上路。”\n\n", me);
				me->set_temp("mache_start",base_name(this_object()));
				me->move("/clone/room/mache");
				room->set_temp("mached",arg);
				//call_out("leave", TIME1, me,room);
				message("vision",me->name() + "坐进了马车，对马夫说：“去" + site[0] + "。”\n\n", environment(me),({me}));
				message("vision","马夫笑着说道：“正好车里的客官也要去那里，你们就一道走吧，我马上就上路。”\n\n", environment(me),({me}));
				return 1;
			}
			else
			{
				message_vision("马夫对$N歉意地说：“对不起，这位客官，车里的客官不去" + arg + "那里,就请您等一等吧。”\n\n",me);
				return 1;
			}
		}
	}
}

//显示出发的信息，并延时调用到达函数
int leave(object me,object room,string dest)
{
	message("vision","车夫利索的上了车，一扬鞭子：走喽，去"+room->query_temp("mached")+"喽！\n\n",environment(me));
	message("vision","不一会，车就消失在了门外。\n\n",environment(me));
	call_out("arrived",TIME2,me,room,dest);
	//设置行进中的标志
	room->set("che_trigger", 1);
	room->delete_temp("mached");
	return 1;
}

int arrived(object me,object room,string dest)
{
	int i;
	object *inv;
	inv = all_inventory(room);
	message_vision("\n马车渐渐停了下来，车夫高叫一声：到了！\n\n", me);
	if(room!=environment(me))
		write("不对呀，你明明是在马车里的呀，怎么跑这里来了？\n"+
			"一定是时空错位，赶快报告巫师吧！\n");
	for(i=sizeof(inv);i>0;i--)
	{
		if(!inv[i-1]->move(dest))
			write("你要去的地方有点问题，快报告巫师！\n");
		message_vision("$N从马车走了下来。\n\n",inv[i-1]);
		message("vision",inv[i-1]->name()+"走下马车去了。\n",room);
	}
	room->delete("che_trigger");
	room->delete("back_flag");
	me->delete_temp("guche");
	return 1;
}
