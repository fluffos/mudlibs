inherit F_CLEAN_UP;
mapping lista = ([//1级帮
	"/clone/weapon/unarmed/jinbi" : 50,
	"/clone/weapon/unarmed/longya" : 60,
	"/clone/weapon/unarmed/moya" : 100,
	"/clone/weapon/sword/qingfeng" : 50,
	"/clone/weapon/sword/rouqing" : 80,
	"/clone/weapon/sword/leihen" : 100,
	"/clone/weapon/blade/zijin" : 50,
	"/clone/weapon/blade/wenrou" : 100,
	"/clone/weapon/blade/wuqing" : 120,
	"/clone/armor/qingtian" : 50,
	"/clone/cloth/changpao" : 50,
	"/clone/armor/suozi" : 80,
	"/clone/armor/jinbeixin" : 100,
]);
mapping listb = ([//2级帮
	"/clone/weapon/unarmed/shihun" : 300,
	"/clone/weapon/sword/youlong" : 300,
	"/clone/weapon/blade/qisha" : 300,
	"/clone/armor/yuxue" : 300,
]);
mapping listc = ([//3级帮
	"/clone/weapon/unarmed/longshuang" : 800,
	"/clone/weapon/sword/chengying" : 800,
	"/clone/weapon/blade/canshang" : 800,
	"/clone/cloth/wucan" : 800,
]);
mapping listd = ([//4级帮
	"/clone/vip/njshi" : 1000,
	"/clone/vip/hufajuan" : 2000,
	"/clone/vip/xunrenjuan" : 200,
]);
int main(object me, string arg)
{
 int all,page,i,j;
 object *t,obj,env;
 string str,short,text,*list,*list2,*mb,*mb1,add,*zhudi;
 mapping bhinfo,user;

	env = environment(me);

	if (me->is_busy())
		return notify_fail(ZJOBLONG"你现在正忙着呢。\n");

	if( !arg )
	{
		if(!(short=me->query("banghui/name")))
		{
			str = ZJOBLONG"你目前还没有帮会！你可以集结好友组队创建一个，或者选择加入一个别人创建的帮会。\n";
			page = 1;
			list2 = BANGHUI_D->query_names();
			list = ({});
			if(!sizeof(list2))
			{
				write(ZJOBLONG"目前游戏中尚无帮会组织！\n");
				return 1;
			}
			for(i=0;i<sizeof(list2);i++)
			{
				list += ({ list2[i]+":banghui cha "+list2[i] });
			}
			str += ZJOBACTS2+ZJMENUF(2,2,9,30);
			all = sizeof(list)/10;
			if(sizeof(list)%10) all += 1;
			if(page<1) page = 1;
			if(page>all) page = all;
			j = (page-1)*10;
			i = page*10;
			if (i >= sizeof(list)) i = sizeof(list);
			i--;
			if(all>1)
				str += "上一页:banghui ls "+(page-1)+ZJSEP"下一页:banghui ls "+(page+1)+ZJSEP;
			str += implode(list[j..i], ZJSEP);
			write(str+"\n");
		}
		else
		{
			text = ZJOBLONG"名称："+short+"　　　";
			text += "帮主："+TOP_D->get_name(BANGHUI_D->query_banghui(short+"/bangzhu"));
//			text += ZJBR"一一一一一一一一一一一一一一一一一一一一一一一";
			text += ZJBR"等级："+BANGHUI_D->query_banghui(short+"/level")+
					"【"+BANGHUI_D->query_banghui(short+"/exp")+"/"+BANGHUI_D->query_banghui(short+"/level")*BANGHUI_D->query_banghui(short+"/level")*BANGHUI_D->query_banghui(short+"/level")*10000+"】";
			text += "　　储备："+BANGHUI_D->query_banghui(short+"/chubei");
			if(zhudi=BANGHUI_D->query_banghui(short+"/zhudi"))
				text += ZJBR"驻地："+implode(zhudi,",");
			else
				text += ZJBR"驻地：无";
			text += ZJBR"一一一一一一一一一一一一一一一一一一一一一一一"ZJBR"公告：";
			if(BANGHUI_D->query_banghui(short+"/txt"))
				text += BANGHUI_D->query_banghui(short+"/txt");
			else
				text += "暂无公告！";
			text += ZJBR"一一一一一一一一一一一一一一一一一一一一一一一";
			text += ZJBR"副帮主：";
			if(zhudi=BANGHUI_D->query_banghui(short+"/fubang"))
			{
				for(i=0;i<sizeof(zhudi);i++)
				text += TOP_D->get_name(zhudi[i])+"，";
			}
			else
				text += "无";
			text += ZJBR"成员数："+CHINESE_D->chinese_number(sizeof(BANGHUI_D->query_banghui(short+"/member")))+"位";
			text += "\n"ZJOBACTS2+ZJMENUF(3,3,10,30);
			text += "帮会列表:banghui ls 1";
			text += ZJSEP"成员列表:banghui mb 1";
			text += ZJSEP"退出帮会:banghui quit";
			if(me->query("banghui/zhiwei")=="帮主")
			{
				text += ZJSEP"编辑公告:banghui txt";
				text += ZJSEP"查看申请:banghui add 1";
				text += ZJSEP"解散帮会:banghui jiesan";
//				text += ZJSEP"升级帮会:banghui lvup";
			}
			else if(me->query("banghui/zhiwei")=="副帮主")
			{
				text += ZJSEP"查看申请:banghui add 1";
				text += ZJSEP"编辑公告:banghui txt";
			}
			//if (me->query("id") == "luoyuna") 
			{
//				text += ZJSEP"帮派贡献:banghui gx";
//				text += ZJSEP"兑换物品:banghui dhlist";
			}
			write(text+"\n");
		}
	} 
	else if( sscanf(arg,"attack %s",text)==1 )
	{
		if(!(short=me->query("banghui/name")))
			return notify_fail(ZJOBLONG"你没有帮会怎么发起帮会战！\n");
		if(me->query("banghui/zhiwei")!="帮主"&&me->query("banghui/zhiwei")!="副帮主")
			return notify_fail(ZJOBLONG"你没有发起帮会战的权限！\n");
		if(!BANGHUI_D->query_banghui(text))
			return notify_fail(ZJOBLONG"没有这个帮会！\n");
		if(!BANGHUI_D->query_banghui(text+"/zhudi"))
			return notify_fail(ZJOBLONG"对方连驻地都没有你要攻打他啥？\n");
		if(BANGHUI_D->query_banghui(short+"/chubei")<10000)
			return notify_fail(ZJOBLONG"帮会储备不足10000，请有足够实力再发起帮会战！\n");
		if(!BANGHUI_D->query_banghui(short+"/attackby"))
			BANGHUI_D->set_banghui(text+"/attackby",({short}));
		else
			BANGHUI_D->set_banghui(text+"/attackby",BANGHUI_D->query_banghui(short+"/attackby")+({short}));
	}
	else if( sscanf(arg,"txt %s",text)==1 )
	{
		if(!(short=me->query("banghui/name")))
			return notify_fail(ZJOBLONG"你没有帮会发什么公告！\n");
		if(me->query("banghui/zhiwei")!="帮主"&&me->query("banghui/zhiwei")!="副帮主")
			return notify_fail(ZJOBLONG"你没有发公告的权限！\n");
		BANGHUI_D->set_banghui(short+"/txt",text);
		write(ZJFORCECMD("banghui"));
	}
	else if( sscanf(arg,"ls %d",page)==1 )
	{
		str = ZJOBLONG"目前游戏中有以下帮会：\n";
		list2 = BANGHUI_D->query_names();
		list = ({});
		if(!sizeof(list2))
		{
			write(ZJOBLONG"目前游戏中尚无帮会组织！\n");
			return 1;
		}
		for(i=0;i<sizeof(list2);i++)
		{
			list += ({ list2[i]+":banghui cha "+list2[i] });
		}
		str += ZJOBACTS2+ZJMENUF(2,2,9,30);
		all = sizeof(list)/10;
		if(sizeof(list)%10) all += 1;
		if(page<1) page = 1;
		if(page>all) page = all;
		j = (page-1)*10;
		i = page*10;
		if (i >= sizeof(list)) i = sizeof(list);
		i--;
		if(all>1)
			str += "上一页:banghui ls "+(page-1)+ZJSEP"下一页:banghui ls "+(page+1)+ZJSEP;
		str += implode(list[j..i], ZJSEP);
		write(str+"\n");
	}
	else if( sscanf(arg,"add %d",page)==1 )
	{
		if(!(short=me->query("banghui/name")))
			return notify_fail(ZJOBLONG"你还没有帮会呢！\n");
		mb = BANGHUI_D->query_banghui(short+"/shenqing");
		if(!pointerp(mb)||mb==({}))
		{
			return notify_fail(ZJOBLONG"没有人申请入帮！\n");
		}
		list = ({});
		mb1 = ({});
		for(i=0;i<sizeof(mb);i++)
		{
			user = TOP_D->query_user(mb[i]);
			if (!user)
				continue;
			if(find_player(mb[i]))
				list += ({sprintf(HIG"%s　　在线"NOR":banghui look2 %s",user["name"],mb[i])});
			else
				mb1 += ({sprintf(HIG"%s　　离线"NOR":banghui look2 %s",user["name"],mb[i])});
		}
		list += mb1;
		str = ZJOBLONG+short+"帮会入帮申请列表：\n";
		str += ZJOBACTS2+ZJMENUF(2,2,9,30);
		all = sizeof(list)/10;
		if(sizeof(list)%10) all += 1;
		if(page<1) page = 1;
		if(page>all) page = all;
		j = (page-1)*10;
		i = page*10;
		if (i >= sizeof(list)) i = sizeof(list);
		i--;
		if(all>1)
			str += "上一页:banghui add "+(page-1)+ZJSEP"下一页:banghui add "+(page+1)+ZJSEP;
		str += implode(list[j..i], ZJSEP);
		write(str+"\n");
	}
	else if( sscanf(arg,"addyes %s",add)==1 )
	{
		if(!(short=me->query("banghui/name")))
			return notify_fail(ZJOBLONG"你还没有帮会呢！\n");
		mb1 = BANGHUI_D->query_banghui(short+"/fubang");
		if(!mb1) mb1 = ({});
		if((BANGHUI_D->query_banghui(short+"/bangzhu")!=me->query("id"))&&(member_array(me->query("id"),mb1)==-1))
			return notify_fail(ZJOBLONG"你没有收人的权利！\n");
		list = BANGHUI_D->query_banghui(short+"/shenqing");
		mb = BANGHUI_D->query_banghui(short+"/member");

		if(sizeof(mb)>=(BANGHUI_D->query_banghui(short+"/level")*5+10))
			return notify_fail(ZJOBLONG"帮会人数已达到等级上限！\n");
		if(!pointerp(list)||(member_array(add,list)==-1))
			return notify_fail(ZJOBLONG"此人没有申请入帮！\n");
		if(member_array(add,mb)!=-1)
			return notify_fail(ZJOBLONG"此人已在帮会了！\n");
		user = TOP_D->query_user(add);
		if(!user)
			return notify_fail(ZJOBLONG"没有这个人！\n");
		if(!(obj=UPDATE_D->global_find_player(add)))
			return notify_fail(ZJOBLONG"没有这个人！\n");

		if(obj->query("banghui"))
		{
			BANGHUI_D->set_banghui(short+"/shenqing",list-({add}));
			return notify_fail(ZJOBLONG"收人失败，此人已经有帮派了！\n");
		}
		obj->set("banghui/name",short);
		obj->set("banghui/zhiwei","帮众");
		obj->save();
		CHANNEL_D->do_channel( me,"party",sprintf("%s加入本帮会，大家欢迎！", obj->query("name")) );

		list -= ({add});
		BANGHUI_D->set_banghui(short+"/shenqing",list);
		BANGHUI_D->set_banghui(short+"/member",mb+({add}));

		if(list!=({}))
			write(ZJFORCECMD("banghui add 1"));
		else
			write(ZJFORCECMD("banghui mb 1"));
	}
	else if( sscanf(arg,"addno %s",add)==1 )
	{
		if(!(short=me->query("banghui/name")))
			return notify_fail(ZJOBLONG"你还没有帮会呢！\n");
		list = BANGHUI_D->query_banghui(short+"/shenqing");
		if(!pointerp(list)||(member_array(add,list)==-1))
			return notify_fail(ZJOBLONG"此人没有申请入帮！\n");
		mb1 = BANGHUI_D->query_banghui(short+"/fubang");
		if(!mb1) mb1 = ({});
		if((BANGHUI_D->query_banghui(short+"/bangzhu")!=me->query("id"))&&(member_array(me->query("id"),mb1)==-1))
			return notify_fail(ZJOBLONG"你没有拒绝人的权利！\n");
		list -= ({add});
		BANGHUI_D->set_banghui(short+"/shenqing",list);
		if(list!=({}))
			write(ZJFORCECMD("banghui add 1"));
		else
			write(ZJFORCECMD("banghui mb 1"));
	}
	else if( sscanf(arg,"cha %s",short)==1 )
	{
		if(!BANGHUI_D->query_banghui(short))
		return notify_fail(ZJOBLONG"无此帮会！\n");

		text = ZJOBLONG"名称："+short+"　　　";
		text += "帮主："+TOP_D->get_name(BANGHUI_D->query_banghui(short+"/bangzhu"));
//		text += ZJBR"一一一一一一一一一一一一一一一一一一一一一一一";
		text += ZJBR"等级："+BANGHUI_D->query_banghui(short+"/level")+"【"+BANGHUI_D->query_banghui(short+"/exp")+"/"+BANGHUI_D->query_banghui (short+"/level")*BANGHUI_D->query_banghui(short+"/level")*BANGHUI_D->query_banghui(short+"/level")*10000+"】";
		if(zhudi=BANGHUI_D->query_banghui(short+"/zhudi"))
			text += ZJBR"驻地："+implode(zhudi,",");
		else
			text += ZJBR"驻地：无";
		text += ZJBR"一一一一一一一一一一一一一一一一一一一一一一一"ZJBR"公告：";
		if(BANGHUI_D->query_banghui(short+"/txt"))
			text += BANGHUI_D->query_banghui(short+"/txt");
		else
			text += "暂无公告！";
		text += ZJBR"一一一一一一一一一一一一一一一一一一一一一一一";
		text += ZJBR"副帮主：";
		if(zhudi=BANGHUI_D->query_banghui(short+"/fubang"))
		{
			for(i=0;i<sizeof(zhudi);i++)
			text += TOP_D->get_name(zhudi[i])+"，";
		}
		else
			text += "无";
		text += ZJBR"成员数："+CHINESE_D->chinese_number(sizeof(BANGHUI_D->query_banghui(short+"/member")))+"位";
		text += "\n"ZJOBACTS2+ZJMENUF(3,3,10,30);
		text += "申请加入:banghui join "+short;
		text += ZJSEP"返回列表:banghui ls 1";
		write(text+"\n");
	}
/*
	else if( sscanf(arg,"gx %d",page)== 1 )
	{
		if(!(short=me->query("banghui/name")))
			return notify_fail(ZJOBLONG"你还没有帮会呢！\n");
		
		if (page < 10)
			return notify_fail(ZJOBLONG"最少10两黄金起捐！\n");
		if (page > 10000)
			return notify_fail(ZJOBLONG"最多10000两黄金！\n");
		
		if (me->query("balance") < page * 10000)
			return notify_fail(ZJOBLONG"钱庄存款不够"+MONEY_D->money_str(page*10000)+"！\n");
		
		BANGHUI_D->set_banghui(short+"/gongxian/"+me->query("name"), BANGHUI_D->query_banghui (short+"/gongxian/"+me->query("name"))+page);
		BANGHUI_D->set_banghui(short+"/exp", BANGHUI_D->query_banghui(short+"/exp")+page);
		me->add("balance", -(page * 10000));
		write("你为帮派捐献了"+MONEY_D->money_str(page*10000)+NOR"。\n");
	}
	else if( sscanf(arg,"dhlist %s", add)==1 ) 
	{
		if(!(short=me->query("banghui/name")))
			return notify_fail(ZJOBLONG"你还没有帮会呢！\n");
		
		max_list += lista;
		if (BANGHUI_D->query_banghui(short+"/level") > 1)
			max_list += listb;
		if (BANGHUI_D->query_banghui(short+"/level") > 2)
			max_list += listc;
		if (BANGHUI_D->query_banghui(short+"/level") > 3)
			max_list += listd;
		
		if (!max_list[add])
			return notify_fail(ZJOBLONG"你无法兑换该物品！\n");
		
		if(!BANGHUI_D->query_banghui (short+"/gongxian/"+me->query("name"))
			||BANGHUI_D->query_banghui (short+"/gongxian/"+me->query("name")) < max_list[add])
			return notify_fail(ZJOBLONG"你的贡献度不足！\n");

		obj = new(add);
		if (obj->move(me)) {
			BANGHUI_D->set_banghui(short+"/gongxian/"+me->query("name"), BANGHUI_D->query_banghui (short+"/gongxian/"+me->query("name"))-max_list[add]);
			return notify_fail("你用"+max_list[add]+"点贡献度兑换了一"+obj->query("unit")+obj->query("name")+"。\n");
		} else
			return notify_fail("兑换失败，请检查包裹空间。\n");
	}
	else
	if (arg == "dhlist")
	{
		if(!(short=me->query("banghui/name")))
			return notify_fail(ZJOBLONG"你还没有帮会呢！\n");
		
		str = ZJOBLONG"你目前可用的贡献还有"+
						BANGHUI_D->query_banghui (short+"/gongxian/"+me->query("name"))
										+"点，请选择兑换物品：\n"ZJOBACTS2+ZJMENUF(2,2,9,30);
		max_list = lista;
		if (BANGHUI_D->query_banghui(short+"/level") > 1)
			max_list += listb;
		
		items = keys(max_list);
		
		for(i=0;i<sizeof(items);i++)
		{
			str += items[i]->query("name")+ZJBR"贡献度："+max_list[items[i]]+":banghui dhlist "+items[i]+ZJSEP;
		}
		tell_object(me, str+"\n");
	} else
	if (arg == "lvup")
	{
		if(!(short=me->query("banghui/name")))
			return notify_fail(ZJOBLONG"你还没有帮会呢！\n");

		if(me->query("banghui/zhiwei")!="帮主")
			return notify_fail(ZJOBLONG"只有帮主才能提升帮会的等级！\n");
		
		if (BANGHUI_D->query_banghui(short+"/level") >= 4)
			return notify_fail(ZJOBLONG"目前帮会等级最高只能升到四级！\n");
		
		if (BANGHUI_D->query_banghui(short+"/exp") < BANGHUI_D->query_banghui(short+"/level")*BANGHUI_D->query_banghui(short+"/level")*BANGHUI_D->query_banghui(short+"/level")*10000)
			return notify_fail(ZJOBLONG"帮会贡献度不够！\n");
		
		if(!objectp(obj = present("kuojian ling", me)))
			return notify_fail(ZJOBLONG"你身上没有扩建令！\n");
		
		index = BANGHUI_D->query_banghui(short+"/level") * 2;
		if (obj->query_amount() < index)
			return notify_fail(ZJOBLONG"你身上的扩建令不够"+index+"块！\n");
		
		obj->add_amount(-index);
		BANGHUI_D->set_banghui(short+"/level", BANGHUI_D->query_banghui(short+"/level") + 1);
		CHANNEL_D->do_channel( me,"party",sprintf("%s把本帮会等级提升了一级！", me->name()) );
	}
*/
	else if( arg=="quityes" )
	{
		if(!(short=me->query("banghui/name")))
			return notify_fail(ZJOBLONG"你没有帮会不用脱离！\n");
		if(me->query("banghui/zhiwei")=="帮主")
			return notify_fail(ZJOBLONG"帮主不能脱离帮会！\n");
		mb = BANGHUI_D->query_banghui(short+"/member");
		BANGHUI_D->set_banghui(short+"/member",mb-({me->query("id")}));
		me->delete("banghui");
		write(ZJOBLONG"你脱离了帮会 "+short+"。\n");
	}
/*
	else if (arg == "gx")
	{
		if(!(short=me->query("banghui/name")))
			return notify_fail(ZJOBLONG"你没有帮会！\n");
		return notify_fail(INPUTTXT("请输入要捐献的黄金数量("HIY"黄金/两"NOR")：","banghui gx $txt#")+"\n");
	}
*/
	else if( arg=="quit" )
	{
		if(!(short=me->query("banghui/name")))
			return notify_fail(ZJOBLONG"你没有帮会不用脱离！\n");
		if(me->query("banghui/zhiwei")=="帮主")
			return notify_fail(ZJOBLONG"帮主不能脱离帮会！\n");
		write(ZJOBLONG"你确定要脱离帮会吗？\n"ZJOBACTS2+ZJMENUF(3,3,10,30)+"确定:banghui quityes\n");
	}
	else if( arg=="jiesan" )
	{
		if(!(short=me->query("banghui/name")))
			return notify_fail(ZJOBLONG"你没有帮会解散什么？\n");
		if(me->query("banghui/zhiwei")!="帮主")
			return notify_fail(ZJOBLONG"只有帮主才能解散帮会！\n");
		write(ZJOBLONG"你确定要解散帮会吗？\n"ZJOBACTS2+ZJMENUF(3,3,10,30)+"确定:banghui jiesanyes\n");
	}
	else if( arg=="jiesanyes" )
	{
		if(!(short=me->query("banghui/name")))
			return notify_fail(ZJOBLONG"你没有帮会解散什么？\n");
		if(me->query("banghui/zhiwei")!="帮主")
			return notify_fail(ZJOBLONG"只有帮主才能解散帮会！\n");
		mb = BANGHUI_D->query_banghui(short+"/member");
		if(sizeof(mb)>1)
			return notify_fail(ZJOBLONG"帮会中尚有成员在，不能解散帮会！\n");
		BANGHUI_D->delete_banghui(short);
		me->delete("banghui");
		CHANNEL_D->do_channel(me,"chat","今日众兄弟金盆洗手归隐山林，解散【"+short+"】！");
		write(ZJOBLONG"你解散了帮会 "+short+"。\n");
	}
	else if( sscanf(arg,"join %s",short)==1 )
	{
		if(!BANGHUI_D->query_banghui(short))
			return notify_fail(ZJOBLONG"无此帮会！\n");
		if(me->query("banghui"))
			return notify_fail(ZJOBLONG"你已经有帮会了！\n");
		list = BANGHUI_D->query_banghui(short+"/shenqing");
		mb = BANGHUI_D->query_banghui(short+"/member");
		if(member_array(me->query("id"),mb)!=-1)
			return notify_fail(ZJOBLONG"你已是此帮会的人了！\n");
		if(pointerp(list)&&(member_array(me->query("id"),list)!=-1))
			return notify_fail(ZJOBLONG"你已经申请过加入此帮会了，请联系帮会管理员等待回应！\n");
		if(!pointerp(list))
			BANGHUI_D->set_banghui(short+"/shenqing",({me->query("id")}));
		else
			BANGHUI_D->set_banghui(short+"/shenqing",list+({me->query("id")}));
		write(ZJOBLONG"已发出入帮申请，请等待管理员审核！\n");
	}
	else if( sscanf(arg,"look1 %s",add)==1 )
	{
		if(!(short=me->query("banghui/name")))
			return notify_fail(ZJOBLONG"你还没有帮会呢！\n");
		list = BANGHUI_D->query_banghui(short+"/member");
		if(!pointerp(list)) list = ({});
		if(member_array(add,list)==-1)
			return notify_fail(ZJOBLONG"你的帮会成员中没有此人！\n");
		user = TOP_D->query_user(add);
		if(!user)
			return notify_fail(ZJOBLONG"没有这个人！\n");
		str = ZJOBLONG+user["name"]+ZJBR;
		str += "一一一一一一一一一一一一一一一一一一一一一一一"ZJBR;
		str += "修为："+user["combat_exp"];
		str += "    杀气："+user["PKS"];
		str += "\n"ZJOBACTS2+ZJMENUF(3,3,10,30);
		str += "返回列表:banghui mb 1";
		if(me->query("banghui/zhiwei")=="帮主")
		{
			str += ZJSEP"帮会任命:banghui renming "+add;
			str += ZJSEP"踢出帮会:banghui tiren "+add;
		}
		write(str+"\n");
	}
	else if( sscanf(arg,"look2 %s",add)==1 )
	{
		if(!(short=me->query("banghui/name")))
			return notify_fail(ZJOBLONG"你还没有帮会呢！\n");
		list2 = BANGHUI_D->query_banghui(short+"/shenqing");
		if(!pointerp(list2)) list2 = ({});
		if(member_array(add,list2)==-1)
			return notify_fail(ZJOBLONG"你的帮会申请列表中没有此人！\n");
		user = TOP_D->query_user(add);
		if(!user)
			return notify_fail(ZJOBLONG"没有这个人！\n");
		str = ZJOBLONG+user["name"]+ZJBR;
		str += "一一一一一一一一一一一一一一一一一一一一一一一"ZJBR;
		str += "修为："+user["combat_exp"];
		str += "    杀气："+user["PKS"];
		str += "\n"ZJOBACTS2+ZJMENUF(3,3,10,30);
		str += "返回列表:banghui add 1";
		if(me->query("banghui/zhiwei")=="帮主"||me->query("banghui/zhiwei")=="副帮主")
		{
			str += ZJSEP"同意申请:banghui addyes "+add;
			str += ZJSEP"拒绝申请:banghui addno "+add;
		}
		write(str+"\n");
	}
	else if( sscanf(arg,"tiren %s",add)==1 )
	{
		if(!(short=me->query("banghui/name")))
			return notify_fail(ZJOBLONG"你还没有帮会呢！\n");
		list = BANGHUI_D->query_banghui(short+"/member");
		if(!pointerp(list)||(member_array(add,list)==-1))
			return notify_fail(ZJOBLONG"你的帮会没有此人！\n");
		if(BANGHUI_D->query_banghui(short+"/bangzhu")!=me->query("id"))
			return notify_fail(ZJOBLONG"你没有踢人的权利！\n");
		if(me->query("id")==add)
			return notify_fail(ZJOBLONG"你要踢自己的屁股？\n");
		user = TOP_D->query_user(add);
		if(!user)
			return notify_fail(ZJOBLONG"没有这个人！\n");
		if(!(obj=UPDATE_D->global_find_player(add)))
			return notify_fail(ZJOBLONG"没有这个人！\n");
		obj->delete("banghui");
		obj->save();
		CHANNEL_D->do_channel( me,"party",sprintf("%s被开出帮会！", obj->query("name")) );

		if(!obj->query_temp("temp_loaded"))
			tell_object(obj,ZJOBLONG"你被开出帮会了！\n");

		BANGHUI_D->set_banghui(short+"/member",list-({add}));
		if((mb=BANGHUI_D->query_banghui(short+"/fubang"))&&member_array(add,mb)!=-1)
			BANGHUI_D->set_banghui(short+"/fubang",mb-({add}));
		write(ZJFORCECMD("banghui mb 1"));
	}
	else if( sscanf(arg,"renming %s",add)==1 )
	{
		if(!(short=me->query("banghui/name")))
			return notify_fail(ZJOBLONG"你还没有帮会呢！\n");

		if( sscanf(add,"%s %s",add,text)!=2 )
		{
			return notify_fail(INPUTTXT("你要任命"+TOP_D->get_name(add)+"为什么？","banghui "+arg+" $txt#")+"\n");
		}
		list = BANGHUI_D->query_banghui(short+"/member");
		if(!mb = BANGHUI_D->query_banghui(short+"/fubang")) mb = ({});
		if(!pointerp(list)||(member_array(add,list)==-1))
			return notify_fail(ZJOBLONG"你的帮会没有此人！\n");
		if(BANGHUI_D->query_banghui(short+"/bangzhu")!=me->query("id"))
			return notify_fail(ZJOBLONG"你没有任命的权利！\n");
		if(me->query("id")==add)
			return notify_fail(ZJOBLONG"你要任命自己？\n");
		if(pointerp(mb)&&(member_array(add,mb)!=-1)) mb -= ({add});
		if(text=="帮主")
		{
			me->set("banghui/zhiwei","长老");
			BANGHUI_D->set_banghui(short+"/bangzhu",add);
		}
		else if(text=="副帮主")
		{
			if(mb&&sizeof(mb)>=2)
				return notify_fail(ZJOBLONG"副帮主人数已满！\n");
			else
			{
				mb += ({add});
			}
		}
		BANGHUI_D->set_banghui(short+"/fubang",mb);
		user = TOP_D->query_user(add);
		if(!user)
			return notify_fail(ZJOBLONG"没有这个人！\n");
		if(!(obj=UPDATE_D->global_find_player(add)))
			return notify_fail(ZJOBLONG"没有这个人！\n");
		obj->set("banghui/zhiwei",text);
		obj->save();
		CHANNEL_D->do_channel( me,"party",sprintf("%s被任命为【%s】！", obj->query("name"),text) );

		tell_object(me,ZJOBLONG"任命成功！\n");
	}
	else if( sscanf(arg,"mb %d",page)==1 )
	{
		if(!(short=me->query("banghui/name")))
		{
			tell_object(me,ZJOBLONG"你目前还没有帮会！你可以集结好友组队创建一个，或者选择加入一个别人创建的帮会。\n");
			page = 1;
			list = BANGHUI_D->query_names();
			str = ZJOBLONG+MUD_NAME+"帮会列表：\n";
			str += ZJOBACTS2+ZJMENUF(2,2,9,30);
			all = sizeof(list)/10;
			if(sizeof(list)%10) all += 1;
			if(page<1) page = 1;
			if(page>all) page = all;
			j = (page-1)*10;
			i = page*10;
			if (i >= sizeof(list)) i = sizeof(list);
			i--;
			if(all>1)
				str += "上一页:banghui mb "+(page-1)+ZJSEP"下一页:banghui mb "+(page+1)+ZJSEP;
			str += implode(list[j..i], ZJSEP);
			write(str+"\n");
		}
		else
		{
			mb = BANGHUI_D->query_banghui(short+"/member");
			list = ({});
			mb1 = ({});
			for(i=0;i<sizeof(mb);i++)
			{
				user = TOP_D->query_user(mb[i]);

				if (!user)
					continue;
				if(find_player(mb[i]))
					list += ({sprintf(HIG"%s　　在线"NOR+ZJBR+HIY"贡献：%d"NOR":banghui look1 %s",user["name"],BANGHUI_D->query_banghui (short+"/gongxian/"+mb[i]),mb[i])});
				else
					mb1 += ({sprintf(HIG"%s　　离线"NOR+ZJBR+HIY"贡献：%d"NOR":banghui look1 %s",user["name"],BANGHUI_D->query_banghui (short+"/gongxian/"+mb[i]),mb[i])});
			}

			list += mb1;
			str = ZJOBLONG+short+"帮会成员：\n";
			str += ZJOBACTS2+ZJMENUF(2,2,9,30);
			all = sizeof(list)/10;
			if(sizeof(list)%10) all += 1;
			if(page<1) page = 1;
			if(page>all) page = all;
			j = (page-1)*10;
			i = page*10;
			if (i >= sizeof(list)) i = sizeof(list);
			i--;
			if(all>1)
				str += "上一页:banghui mb "+(page-1)+ZJSEP"下一页:banghui mb "+(page+1)+ZJSEP;
			str += implode(list[j..i], ZJSEP);
			write(str+"\n");
		}
	}
	else if( arg == "txt" )
	{
		if(!(short=me->query("banghui/name")))
			return notify_fail(ZJOBLONG"你还没有帮会呢！\n");
		return notify_fail(INPUTTXT("请输入帮会公告：","banghui txt $txt#")+"\n");
	}
	else if( arg == "create" )
	{
		if(base_name(env)!="/d/city/banghui")
			return notify_fail(ZJOBLONG"请到帮会管理处申请帮会！\n");
		return notify_fail(INPUTTXT("请输入帮会名字("HIY"建立帮会需要200元宝"NOR")：","banghui create $txt#")+"\n");
	}
	else if( sscanf(arg,"create %s",short)==1 )
	{
		if(base_name(env)!="/d/city/banghui")
			return notify_fail(ZJOBLONG"请到帮会管理处申请帮会！\n");

		if(me->query("banghui"))
			return notify_fail(ZJOBLONG"请先脱离现在的帮会！\n");
		if( !pointerp(t = me->query_team()) || sizeof(t)<2)
			return notify_fail(ZJOBLONG"你必须和至少1名队友组队一起才能创建帮会！\n");
		if(BANGHUI_D->query_banghui(short))
			return notify_fail(ZJOBLONG"帮会名称已存在！\n");
		for(i=0;i<sizeof(t);i++)
		{
			if (environment(t[i]) != env)
				return notify_fail(ZJOBLONG"现在你队伍中有人还没有到场呢。\n");	
			if(t[i]->query("banghui"))
				return notify_fail(ZJOBLONG"请确认队友目前都没有参加帮会！\n");
		}
		if( !me->is_team_leader() )
			return notify_fail(ZJOBLONG"队长才能确认创建帮会！\n");
		if(!LOGIN_D->check_legal_name(short,10))
			return notify_fail("帮会名字不符合要求，建立失败！\n");

		if( me->query("yuanbao")<200 )
			return notify_fail(ZJOBLONG"创建帮会需要"HIY"200元宝"NOR"！\n");

		me->add("yuanbao",-200);
		bhinfo = ([]);
		bhinfo["level"] = 1;
		bhinfo["id"] = me->query("id")+"-"+sprintf("%d",time());
		bhinfo["member"] = t->query("id");
		t->set("banghui/name",short);
		t->set("banghui/zhiwei","元老");
		me->set("banghui/zhiwei","帮主");
		bhinfo["bangzhu"] = me->query("id");
		BANGHUI_D->add_banghui(short,bhinfo);
		CHANNEL_D->do_channel(me,"chat","今日众兄弟歃血为盟，建立【"+short+"】！");
		tell_object(me,ZJOBLONG"恭喜，帮会建立成功！\n");
		me->save();
	}
	return 1;
}