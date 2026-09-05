//炸弹人游戏头文件2 by Vast@pkuxkx 2009.2

void all_map(object room);
int check_total();

void init()
{
		all_map(this_object());
		add_action("do_set", "setbomb");
		add_action("do_kan", "kan");
		add_action("do_none", "follow");
		add_action("do_none", "goto");
    add_action("do_none", "perform");
    add_action("do_none", "yun");
    add_action("do_none", "study");
    add_action("do_none", "du");
    add_action("do_none", "lian");
    add_action("do_none", "practice");
    add_action("do_none", "dazuo");
    add_action("do_none", "exercise");
    add_action("do_none", "tuna");
    add_action("do_none", "respirate");
    add_action("do_none", "read");
    add_action("do_none", "dz");
    add_action("do_none", "hitall");
    add_action("do_none", "killall");
    add_action("do_none", "kill");
    add_action("do_none", "exert");
    add_action("do_none", "attack");
    add_action("do_none", "qiecuo");
    add_action("do_none", "hit");
    add_action("do_none", "xiulian");
}

int do_kan()
{
//		check_total();
		all_map(this_object());
		return 1;		
}

int do_none()
{
		write("什么？\n");
		return 1;		
}

int do_set()
{
		object bomb, me;
		
		me = this_player();
		
		//busy的时候不能安放炸弹
		if(me->is_busy())
			return notify_fail("你现在太忙了，无暇引燃炸药。\n");
		
		if(objectp(bomb = present("zha dan", this_object())))
			return notify_fail("你已经引燃了炸药，赶快逃命吧！\n");
			
//		this_object()->set("bomb", 0);
						
		bomb = new(__DIR__"obj/bomb.lpc");
		
		if(!objectp(bomb)) return notify_fail(HIR"出现系统错误，炸弹安放失败，请通知wiz。\n"NOR);
			
		bomb->move(this_object());
		
		message_vision( HIG"$N点燃了$n的引信，然后悄悄地扔在了一个不为人注意的角落。\n"NOR, me, bomb );
		
		//炸弹10秒后爆炸
		remove_call_out("explode");
		call_out("explode", 10, this_object());
		return 1;
}

void explode(object room)
{
		int i, m, total;
		object *player, bomb, victim, shenji;
		string *dir;
		mapping exits = room->query("exits");
		
		dir = values(exits);
		
	//1.本房间内有活人，全部炸死，然后判断一次胜负(延迟2秒判断)；
			player = all_inventory(room);
			for(m = 0; m < sizeof(player); m++)
			{
				if(living(player[m]))
					{
						tell_object(player[m], HIR"只听一声巨响，一股巨大的冲击波向你袭来，你被炸得粉身碎骨……\n"NOR);
						//player[m]->unconcious();
						player[m]->set("last_damage_from", "被炸药炸");
						
						if(userp(player[m]))
							{
								player[m]->move(A);//出局
								
								call_out("end_game", 10);
								
								CHANNEL_D->do_channel(player[m], "sys", 	sprintf("%s被炸死了！", player[m]->name()) );
//								destruct(bb);
							}
						else 
							{
//								bb->move(B); 
//								tell_object(winner, "你走出了火药库!\n");								
								CHANNEL_D->do_channel(player[m], "sys", 	sprintf("%s被炸死了！", player[m]->name()) );
								player[m]->move("/adm/room/quitroom.lpc");
								call_out("des_npc", 5 , player[m]);
								//destruct(player[m]);
							}
							
//						shenji = find_object(__DIR__"shenjiying.lpc");
//						shenji->set("playing", 0);

						//发一条消息通知所有人
//						message( "channel:" + "chat", HIY + "【情报】" + player[m]->name() + "被" + bb->name() + "炸死了！\n"NOR,users());
					}
			}
		
		remove_call_out("check_winner");
		call_out("check_winner", 2);
				
	//2.本房间内有炸弹，则触发周围相连房间爆炸,同时dest炸弹；
			if(bomb = present("zha dan", this_object()))
				{
					bomb->move("/adm/room/quitroom.lpc");
					call_out("des_npc", 5 , bomb);
					
					//每个方向的房间
					for(i = 0; i < sizeof(dir); i++)
					{
						victim = find_object(dir[i]);
						tell_room(victim, HIR"隔壁房间的炸药爆炸了！\n"NOR);
						victim->remove_call_out("explode");	
						victim->explode(victim);
					}
				}
}

//判断胜负(迷宫包含的所有房间是否已经没有幸存者)
int check_winner()
{
		int j, k, n, total;
		object *livep, winner, arbiter, groom;
		int flag;
				
		total = 0;
	
		for(j = 0; j < L; j++)
		{
			for(k = 0; k < L; k++)
			{
				livep = all_inventory(find_object(__DIR__"room" + j + k + ".lpc"));
				for(n = 0; n < sizeof(livep); n++)
				{
					if(livep[n]->is_character())
						{
							winner = livep[n];
							total += 1;
						}
				}
			}
		}

//		tell_object(find_player("vast"), "total= " + total + "\n");

/*		
		if(total != 0)
				message( "channel:" + "chat", HIY + "【情报】炸弹人游戏还剩余" + chinese_number(total) + "名玩家！\n"NOR,users());
*/
		//胜利者
		if(total == 1) 
			{
				if(userp(winner))
					{
						tell_object(winner, HIG"～～～你干掉了敌人～～～\n"NOR);
						winner->move(B); 
						call_out("end_game", 10);
						tell_object(winner, "你走出了火药库!\n");
					}
				else
					destruct(winner);
					
				return 1;
			}
/*			
		if(total == 0)  //所有人都被炸死
			{
				arbiter = find_object(__DIR__"shenjiying.lpc");
				arbiter->set("playing", 0);	
				return 1;
			}
*/
			return 1;
}

int check_total()
{
		int j, k, n, total;
		object *livep, winner, arbiter, groom, troom;
		int flag;
				
		total = 0;
		for(j = 0; j < L; j++)
		{
			for(k = 0; k < L; k++)
			{
				if(!troom = find_object(__DIR__"room" + j + k + ".lpc"))
					troom = load_object(__DIR__"room" + j + k + ".lpc");
				livep = all_inventory(troom);
				for(n = 0; n < sizeof(livep); n++)
				{
					if(livep[n]->is_character())
						{
							winner = livep[n];
							total += 1;
						}
				}
			}
		}
		if(!groom = find_object(__DIR__"room00.lpc"))
			groom = load_object(__DIR__"room00.lpc");
		groom->set("survivor", total);		
		return total;
}

int valid_leave(object me, string dir)
{
		int i;
		object ob, room;
		mapping exits = this_object()->query("exits");;
// 测试成功后再开放		

//	if(wizardp(me))
//		return ::valid_leave(me, dir);

		room = find_object(exits[dir]);
		if(objectp(ob = present("zha dan", room)))
			return notify_fail(HIR"前方有炸弹，无法通行!\n"NOR);
		
		me->start_busy(3);
		
		return ::valid_leave(me, dir);
}

/* 给所有房间发消息，备用
int notice(string str)
{
		int j, k;
		object room;
	
		for(j = 0; j < (L-1); j++)
		{
			for(k = 0; k < (L-1); k++)
			{
				room = find_object(__DIR__"room" + j + k + ".lpc");
				tell_room(room, str);
			}
		}
}
---------------------------------------------------------
频道消息过滤，备用

object *user = filter(users(), choose);
message( "channel:" + "chat", strings ,user);

int choose(object ob)
{
	string file;
	int i;
	
	file = base_name(environment(ob));
	strsrch(file, "/u/vast/bm/room"); //替换为游戏文件的实际所在的目录
	if(i < 0) return 0;
	
	return 1;
}

*/


//文件名的数字即为此房间的坐标，暂时定位长宽相等的方形区域
//房间的出口根据坐标进行计算

void set_exits(object ob)
{
	string *dir = ({"east", "south", "west", "north"});
	string str1, *str = allocate(4), file1, file2;
	mapping exit = ([]);
	int i, j, x, y;
	
	//偷懒一下，从文件名来取x和y轴的坐标,扩展新的房间时，只需要copy这个文件，然后修改文件名即可
	//不过注意L值不能超过9
	
	str1 = base_name(this_object());
	
	i = strsrch(str1, "room");
	
	file1 = str1[0..(i - 1)] + "room";
	
	if(i < 1) error("房间" + str1 + "文件名错误！\n");
	
	x = atoi(str1[(i + 4)..(i + 4)]);
	y = atoi(str1[(i + 5)..(i + 5)]);
	
	if(( (x >= 0) && (x < L)) && ((y >= 0) && (y < L)))
		{
			if((y + 1) < L)
				str[3] = file1 + (string)x + (string)(y + 1);
			else
				str[3] = "";
			if((x - 1) >= 0)
				str[2] = file1 + (string)(x - 1) + (string)y;
			else
				str[2] = "";
			if((y - 1) >= 0 )
				str[1] = file1 + (string)x + (string)(y - 1);
			else
				str[1] = "";
			if((x + 1) < L)
				str[0] = file1 + (string)(x + 1) + (string)y;
			else
				str[0] = "";
		}
	else error("房间" + str1 + "坐标错误！\n");
	
	for(j = 0; j < sizeof(dir); j++)
	{
		if(str[j] !="")
		exit[dir[j]] = str[j];
	}	
	ob->set("exits", exit);

	ob->set("realmap", "\n");
//	ob->set("realmap", COLOR_D->random_jjww() + "\n\n");//呵呵，随手借来用用
}

void all_map(object room)
{
	object room_obj, bomb, *stuff;
	string msg, str1, str2, file1, file2;

	int i, j, x, y, m, n, total, all;

	str1 = base_name(room);
	
	i = strsrch(str1, "room");
	if(i < 1) error("房间" + str1 + "文件名错误！\n");
		
	m = atoi(str1[(i + 4)..(i + 4)]);
	n = atoi(str1[(i + 5)..(i + 5)]);
	
//	tell_room(room, str1 + "\n" + "m= " + m + "\n" + "n= " + n + "\n");			
	file1 = str1[0..(i - 1)] + "room";

	check_total();
	
	total = find_object(__DIR__"room00.lpc")->query("survivor");
			
	msg = HIG"目前局势很不明朗，不过目前这里应该有" + (string)total + "人还活着！\n\n"NOR;
		
	for(y = (L - 1); y >= 0; y--)
	{
		for(x = 0; x < L; x++)
		{
			file2 = file1 + (string)x + (string)y + ".lpc";
			
			if(!room_obj = find_object(file2))
				room_obj = load_object(file2);
				
			str2 = room_obj->query("short");
			bomb = present("zha dan", room_obj);
			stuff = all_inventory(room_obj);
			all = sizeof(stuff);
			
//			if(x == m && y == n )
//					str2 = HIG + str2 + NOR;

			if(x == 0 && y == (L - 1))
				msg = "\n" + msg;
			if(objectp(bomb))
				{
					if(x == m && y == n)
						msg += HIY + str2 + NOR;
					else
						msg += HIR + str2 + NOR;
				}
			else
				{
					if(x == m && y == n)
						msg += HIG + str2 + NOR;
					else
						msg += str2;
				}
				
			if(x < (L - 1))
				msg += "-----";
			else if(x == (L - 1) && y == 0)
				msg += "\n\n";
			else
				msg += "\n";
		}
		if(y > 0)
		for(j = 0; j < L; j++)
		{
			if(j < (L - 1))
				msg += "   |       ";
			else
				msg += "  |\n";
		}
	}
	printf(msg);
	return;
}

void des_npc(object npc)
{
	destruct(npc);
	return;
}

void end_game()
{
	object shenji;
	shenji = find_object(__DIR__"shenjiying.lpc");
	shenji->set("playing", 0);	
	return;
}