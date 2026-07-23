void init()
{ 
        add_action("do_zhuyao","zhuyao");
        add_action("do_fangdan","fangyao");
        add_action("do_liandan","liandan"); 
}

int do_zhuyao(string arg)
{
    object obj;
    object me = this_player();

    if(!arg) return notify_fail("你要拿什么东西当主药？\n");

    if( !objectp(obj = present(arg, me)) )
    return notify_fail("你身上并没有这样东西!\n");

	if(me->is_busy())
	return notify_fail("您现在正忙,等一下再说吧!\n");

    return do_yao(me, obj);
}

//检查主药是否放置成功
int do_yao(object me,object obj)
{
    object ob;
    string arg=obj->short(1);
    me = this_player();
 
    if (me->query_temp("zhuyao"))
    return notify_fail("对不起你已经拿"+me->query_temp("zhuyaoname")+"做主药了!\n");

    foreach ( ob in all_inventory(me)){
    if (ob->short(1)!=arg) continue;
    if (!ob->query("zhuyao")) {
    write("这样东西并不能做主药!\n");
      return 1;
    }
    write(HIR"你拿"+ob->name()+HIR"做主药!\n"NOR);
    me->set_temp("zhuyao",ob->query("zhuyao"));
    me->set_temp("zhuyaoname",""+ob->name()+"");
    destruct(ob);
    return 1;
    }
}

//检查副药是否放置成功
int do_fangdan(string arg)
{
    object obj;
    object me = this_player();

    if(!arg) return notify_fail("你要放什么药进去？\n");

    if( !me->query_temp("zhuyao"))
    return notify_fail("练丹要先放主药,要不然练不出好丹!\n");

    if( !objectp(obj = present(arg, me)) )
    return notify_fail("你身上并没有这样东西!\n");

    return do_dan(me, obj);

}

// 设置炼药的是否成功的一些参数，重点是zjb_dan
int do_dan(object me,object obj)
{
    object ob;
    string arg=obj->short(1);
  
    foreach ( ob in all_inventory(me)){
		if (ob->short(1)!=arg) continue;
		if (!ob->query("yao")) {
			write("这样东西并不能拿来练药!\n");
			return 1;
		}

		if (me->query_temp("danname/"+ob->query("id")+""))
		return notify_fail("你已经把"+ob->name()+"放进练丹炉了!\n");

		if (ob->query("random"))
		me->add_temp("liandan/random",ob->query("random"));

		me->set_temp("danname/"+ob->query("id")+"",1);

		///////////////////////////////////////////////////////
		me->add_temp("zjb_dan",1);  //控制炼药成功的核心值，大于4,小于20则可以容易练成
		////////////////////////////////////////////////////////
		
		write(HIR"你把"+ob->name()+HIR"放进了炼丹炉!\n"NOR);
		destruct(ob);
		return 1;
    }
}

int do_liandan(string arg)
{
    int shoubi,tui,all,zhuyao,all2,zjb,liandan;
    object dan;
    object me = this_player();
    shoubi = me->query_temp("liandan/shoubi");
    tui = me->query_temp("liandan/tui");
    all = me->query_temp("liandan/all");
    all2 = me->query_temp("liandan/random");
    zhuyao = me->query_temp("zhuyao");
    zjb = me->query_temp("zjb_dan");
    liandan = me->query_skill("liandan-shu",1);
	
//	if (!wizardp(me)) return notify_fail("因长安炼丹房涉嫌违规，暂时被巫师查封了！\n");
	
    if (!arg) return notify_fail("你要练哪个种类的丹？\n");

    if (!me->query_temp("liandan"))
    return notify_fail("你没放药,练个屁的丹!\n");


	// By zjb@ty 以下是随机炼丹的程序!    
    if (arg == "random") 
	{
		me->delete_temp("zhuyaoname");
		me->delete_temp("danname");
		
		// By zjb@ty 炼丹的额外奖励!
		me->improve_skill("liandan-shu", me->query("int",1)*me->query("int",1)*2+100);
		me->add("combat_exp",zjb*10000+10000);
		me->add("potential",zjb*1000+1000);
		me->start_busy(5);
		write(HIR"你在炼丹的时候不知不觉经验也随着上去了!\n"NOR);

		//////////////////////////////////////////////////////////////////////////////////////////
		
		// 炼丹术 > 1500 炼成的丹
		if ( liandan > 1500 && zjb > 14) 
		{
			if ( zjb < 20 && zjb > 14 && all2 < 250 && all2 > 150 && zhuyao >= 20 && zhuyao < 25 && random(50)==1) 
			{
				me->delete_temp("liandan");
				me->delete_temp("zhuyao");
				me->delete_temp("zjb_dan");
				dan = new("/d/liandan/xdan/dan11");
				dan->set("zhuren",""+me->query("id")+"");
				dan->move(me);
				message("party",HIC"〖"HIR"天炉神丹"HIC"〗"NOR+":"+HIG" 听说"HIM+me->name(1)+NOR HIG"在长安药店练成了一颗神丹（还魂丹）！\n"NOR,users());
				return notify_fail(BLINK HIR"你竟然练出了可以使人重生的还魂丹!!!\n"NOR);
			}
		}

		// 炼丹术 > 1200 炼成的丹
		if ( liandan > 1200 && zjb > 11) 
		{
			if ( zjb < 15 && zjb > 11 && all2 < 200 && all2 > 100 && zhuyao >= 20 && zhuyao < 25 && random(50)==2) 
			{
				me->delete_temp("liandan");
				me->delete_temp("zhuyao");
				me->delete_temp("zjb_dan");
				dan = new("/d/liandan/xdan/dan19");
				dan->set("zhuren",""+me->query("id")+"");
				dan->move(me);
				message("party",HIC"〖"HIR"天炉神丹"HIC"〗"NOR+":"+HIG" 听说"HIM+me->name(1)+NOR HIG"在长安药店练成了一颗神丹（技能丹）！\n"NOR,users());
				return notify_fail(HIC"你练出了可以增加全部武功的技能丹!!!\n"NOR);
			}
			if ( zjb < 15 && zjb > 11 && all2 < 200 && all2 > 100 && zhuyao >= 20 && zhuyao < 25 && random(50)==3) 
			{
				me->delete_temp("liandan");
				me->delete_temp("zhuyao");
				me->delete_temp("zjb_dan");
				dan = new("/d/liandan/xdan/dan12");
				dan->set("zhuren",""+me->query("id")+"");
				dan->move(me);
				message("party",HIC"〖"HIR"天炉神丹"HIC"〗"NOR+":"+HIG" 听说"HIM+me->name(1)+NOR HIG"在长安药店练成了一颗神丹（还童丹）！\n"NOR,users());
				return notify_fail(HIB"你练出了可以使人返老还童的仙丹!!!\n"NOR);
			}
			if ( zjb < 15 && zjb > 11 && all2 < 200 && all2 > 100 && zhuyao >= 20 && zhuyao < 25 && random(50)==4) 
			{
				me->delete_temp("liandan");
				me->delete_temp("zhuyao");
				me->delete_temp("zjb_dan");
				dan = new("/d/liandan/xdan/dan6");
				dan->set("zhuren",""+me->query("id")+"");
				dan->move(me);
				message("party",HIC"〖"HIR"天炉神丹"HIC"〗"NOR+":"+HIG" 听说"HIM+me->name(1)+NOR HIG"在长安药店练成了一颗神丹（臂力丹）！\n"NOR,users());
				return notify_fail(HIR"你练出了可以增加先天臂力的臂力丹!!!\n"NOR);
			}
			if ( zjb < 15 && zjb > 11 && all2 < 200 && all2 > 100 && zhuyao >= 20 && zhuyao < 25 && random(50)==5) 
			{
				me->delete_temp("liandan");
				me->delete_temp("zhuyao");
				me->delete_temp("zjb_dan");
				dan = new("/d/liandan/xdan/dan7");
				dan->set("zhuren",""+me->query("id")+"");
				dan->move(me);
				message("party",HIC"〖"HIR"天炉神丹"HIC"〗"NOR+":"+HIG" 听说"HIM+me->name(1)+NOR HIG"在长安药店练成了一颗神丹（身法丹）！\n"NOR,users());
				return notify_fail(HIR"你练出了可以增加先天身法的身法丹!!!\n"NOR);
			}
			if ( zjb < 15 && zjb > 11 && all2 < 200 && all2 > 100 && zhuyao >= 20 && zhuyao < 25 && random(50)==6) 
			{
				me->delete_temp("liandan");
				me->delete_temp("zhuyao");
				me->delete_temp("zjb_dan");
				dan = new("/d/liandan/xdan/dan8");
				dan->set("zhuren",""+me->query("id")+"");
				dan->move(me);
				message("party",HIC"〖"HIR"天炉神丹"HIC"〗"NOR+":"+HIG" 听说"HIM+me->name(1)+NOR HIG"在长安药店练成了一颗神丹（根骨丹）！\n"NOR,users());
				return notify_fail(HIR"你练出了可以增加先天根骨的根骨丹!!!\n"NOR);
			}
			if ( zjb < 15 && zjb > 11 && all2 < 200 && all2 > 100 && zhuyao >= 20 && zhuyao < 25 && random(50)==7) 
			{
				me->delete_temp("liandan");
				me->delete_temp("zhuyao");
				me->delete_temp("zjb_dan");
				dan = new("/d/liandan/xdan/dan9");
				dan->set("zhuren",""+me->query("id")+"");
				dan->move(me);
				message("party",HIC"〖"HIR"天炉神丹"HIC"〗"NOR+":"+HIG" 听说"HIM+me->name(1)+NOR HIG"在长安药店练成了一颗神丹（悟性丹）！\n"NOR,users());
				return notify_fail(HIR"你练出了可以增加先天悟性的悟性丹!!!\n"NOR);
			}
			if ( zjb < 15 && zjb > 11 && all2 < 200 && all2 > 100 && zhuyao >= 20 && zhuyao < 25 && random(50)==8) 
			{
				me->delete_temp("liandan");
				me->delete_temp("zhuyao");
				me->delete_temp("zjb_dan");
				dan = new("/d/liandan/xdan/dan10");
				dan->set("zhuren",""+me->query("id")+"");
				dan->move(me);
				message("party",HIC"〖"HIR"天炉神丹"HIC"〗"NOR+":"+HIG" 听说"HIM+me->name(1)+NOR HIG"在长安药店练成了一颗神丹（养颜丹）！\n"NOR,users());
				return notify_fail(HIR"你练出了可以增加先天容貌的养颜丹!!\n"NOR);
			}
		}


		// 炼丹术 > 900炼成的丹
		if ( liandan > 900 && zjb > 8) 
		{
			if ( zjb < 12 && zjb > 8 && all2 < 150 && all2 > 30 && zhuyao >= 10 && zhuyao < 25 && random(50)==9) 
			{
				me->delete_temp("liandan");
				me->delete_temp("zhuyao");
				me->delete_temp("zjb_dan");
				dan = new("/d/liandan/xdan/dan20");
				dan->set("zhuren",""+me->query("id")+"");
				dan->move(me);
				message("party",HIC"〖"HIR"天炉神丹"HIC"〗"NOR+":"+HIG" 听说"HIM+me->name(1)+NOR HIG"在长安药店练成了一颗神丹（惊风丸）！\n"NOR,users());
				return notify_fail(HIR"你练出了可增加基本轻功的惊风丸!!!\n"NOR);
			}
			if ( zjb < 12 && zjb > 8 && all2 < 150 && all2 > 30 && zhuyao >= 10 && zhuyao < 25 && random(50)==10) 
			{
				me->delete_temp("liandan");
				me->delete_temp("zhuyao");
				me->delete_temp("zjb_dan");
				dan = new("/d/liandan/xdan/dan21");
				dan->set("zhuren",""+me->query("id")+"");
				dan->move(me);
				message("party",HIC"〖"HIR"天炉神丹"HIC"〗"NOR+":"+HIG" 听说"HIM+me->name(1)+NOR HIG"在长安药店练成了一颗神丹（神力丸）！\n"NOR,users());
				return notify_fail(HIR"你练出了可增加基本拳脚的神力丸!!!\n"NOR);
			}
			if ( zjb < 12 && zjb > 8 && all2 < 150 && all2 > 50 && zhuyao >= 10 && zhuyao < 25 && random(50)==11) 
			{
				me->delete_temp("liandan");
				me->delete_temp("zhuyao");
				me->delete_temp("zjb_dan");
				dan = new("/d/liandan/xdan/dan22");
				dan->set("zhuren",""+me->query("id")+"");
				dan->move(me);
				message("party",HIC"〖"HIR"天炉神丹"HIC"〗"NOR+":"+HIG" 听说"HIM+me->name(1)+NOR HIG"在长安药店练成了一颗神丹（智力丸）！\n"NOR,users());
				return notify_fail(HIR"你练出了可增加读书写字的智力丸!!!\n"NOR);
			}
			if ( zjb < 12 && zjb > 8 && all2 < 150 && all2 > 30 && zhuyao >= 10 && zhuyao < 25 && random(50)==12) 
			{
				me->delete_temp("liandan");
				me->delete_temp("zhuyao");
				me->delete_temp("zjb_dan");
				dan = new("/d/liandan/xdan/dan17");
				dan->set("zhuren",""+me->query("id")+"");
				dan->move(me);
				message("party",HIC"〖"HIR"天炉神丹"HIC"〗"NOR+":"+HIG" 听说"HIM+me->name(1)+NOR HIG"在长安药店练成了一颗神丹（太极丹）！\n"NOR,users());
				return notify_fail(HIR"你练出了可增加基本内功的太级丹!!!\n"NOR);
			}

		}
		
		// 炼丹术 > 600炼成的丹
		if ( liandan > 600 && zjb > 5) 
		{
			if ( zjb < 9 && zjb > 5 && all2 < 100 && all2 > 10 && zhuyao >= 1 && zhuyao < 25 && random(25)==13) 
			{
				me->delete_temp("liandan");
				me->delete_temp("zhuyao");
				me->delete_temp("zjb_dan");
				dan = new("/d/liandan/xdan/dan13");
				dan->set("zhuren",""+me->query("id")+"");
				dan->move(me);
				message("party",HIC"〖"HIR"天炉神丹"HIC"〗"NOR+":"+HIG" 听说"HIM+me->name(1)+NOR HIG"在长安药店练成了一颗神丹（解毒丸）！\n"NOR,users());
				return notify_fail(HIG"你练出了可解百毒的解毒丸!!!\n"NOR);
			}
			if ( zjb < 9 && zjb > 5 && all2 < 100 && all2 > 10 && zhuyao >= 1 && zhuyao < 25 && random(25)==14) 
			{
				me->delete_temp("liandan");
				me->delete_temp("zhuyao");
				me->delete_temp("zjb_dan");
				dan = new("/d/liandan/xdan/dan14");
				dan->set("zhuren",""+me->query("id")+"");
				dan->move(me);
				message("party",HIC"〖"HIR"天炉神丹"HIC"〗"NOR+":"+HIG" 听说"HIM+me->name(1)+NOR HIG"在长安药店练成了一颗神丹（战神丸）！\n"NOR,users());
				return notify_fail(HIG"你练出了可增加攻击力的战神丸!!!\n"NOR);
			}
			if ( zjb < 9 && zjb > 5 && all2 < 100 && all2 > 10 && zhuyao >= 1 && zhuyao < 25 && random(25)==15) 
			{
				me->delete_temp("liandan");
				me->delete_temp("zhuyao");
				me->delete_temp("zjb_dan");
				dan = new("/d/liandan/xdan/dan16");
				dan->set("zhuren",""+me->query("id")+"");
				dan->move(me);
				message("party",HIC"〖"HIR"天炉神丹"HIC"〗"NOR+":"+HIG" 听说"HIM+me->name(1)+NOR HIG"在长安药店练成了一颗神丹（正气丸）！\n"NOR,users());
				return notify_fail(HIB"你练出了可增加正气的正气丸!!!\n"NOR);
			}
			if ( zjb < 9 && zjb > 5 && all2 < 150 && all2 > 10 && zhuyao >= 1 && zhuyao < 25 && random(25)==16) 
			{
				me->delete_temp("liandan");
				me->delete_temp("zhuyao");
				me->delete_temp("zjb_dan");
				dan = new("/d/liandan/xdan/dan18");
				dan->set("zhuren",""+me->query("id")+"");
				dan->move(me);
				message("party",HIC"〖"HIR"天炉神丹"HIC"〗"NOR+":"+HIG" 听说"HIM+me->name(1)+NOR HIG"在长安药店练成了一颗神丹（邪神丸）！\n"NOR,users());
				return notify_fail(HIR"你练出了可增加基本负神的邪神丸!!!\n"NOR);
			}

		}

		// 炼丹术 > 300炼成的丹
		if ( liandan > 300 && zjb > 2) 
		{
			if ( zjb < 6 && zjb > 2 && all2 < 100 && all2 > 30 && zhuyao >= 1 && zhuyao < 25 && random(25)==17) 
			{
				me->delete_temp("liandan");
				me->delete_temp("zhuyao");
				me->delete_temp("zjb_dan");
				dan = new("/d/liandan/xdan/dan1");
				dan->set("zhuren",""+me->query("id")+"");
				dan->move(me);
				message("party",HIC"〖"HIR"天炉神丹"HIC"〗"NOR+":"+HIG" 听说"HIM+me->name(1)+NOR HIG"在长安药店练成了一颗神丹（血气丹）！\n"NOR,users());
				return notify_fail(HIR"你练出了可使自己状态恢复满的血气丹!\n"NOR);
			}
			if ( zjb < 6 && zjb > 2 && all2 < 100 && all2 > 30 && zhuyao >= 1 && zhuyao < 5 && random(25)==18) 
			{
				me->delete_temp("liandan");
				me->delete_temp("zhuyao");
				me->delete_temp("zjb_dan");
				dan = new("/d/liandan/xdan/dan2");
				dan->set("zhuren",""+me->query("id")+"");
				dan->move(me);
				message("party",HIC"〖"HIR"天炉神丹"HIC"〗"NOR+":"+HIG" 听说"HIM+me->name(1)+NOR HIG"在长安药店练成了一颗神丹（疾风丹）！\n"NOR,users());
				return notify_fail(HIG"你练出了可使自己使自己脱离busy的疾风丹\n"NOR);
			}
			if ( zjb < 6 && zjb > 2 && all2 < 100 && all2 > 30 && zhuyao >= 1 && zhuyao < 15 && random(25)==19) 
			{
				me->delete_temp("liandan");
				me->delete_temp("zhuyao");
				me->delete_temp("zjb_dan");
				dan = new("/d/liandan/xdan/dan4");
				dan->set("zhuren",""+me->query("id")+"");
				dan->move(me);
				message("party",HIC"〖"HIR"天炉神丹"HIC"〗"NOR+":"+HIG" 听说"HIM+me->name(1)+NOR HIG"在长安药店练成了一颗神丹（大还丸）！\n"NOR,users());
				return notify_fail(HIW"你练出了少林圣药大还丹!\n"NOR);
			}
			if ( zjb < 6 && zjb > 2 && all2 < 100 && all2 > 20 && zhuyao >= 1 && zhuyao < 25 && random(25)==20) 
			{
				me->delete_temp("liandan");
				me->delete_temp("zhuyao");
				me->delete_temp("zjb_dan");
				dan = new("/d/liandan/xdan/dan5");
				dan->set("zhuren",""+me->query("id")+"");
				dan->move(me);
				message("party",HIC"〖"HIR"天炉神丹"HIC"〗"NOR+":"+HIG" 听说"HIM+me->name(1)+NOR HIG"在长安药店练成了一颗神丹（肾宝）！\n"NOR,users());
				return notify_fail(HIW"你练出了补精圣药,肾宝!!!\n"NOR);
			}

		}

		// 炼丹术 > 1炼成的丹
		if ( liandan > 1) 
		{
			if ( zjb < 3 && zjb > 1 && all2 < 100 && all2 > 20 && zhuyao >= 1 && zhuyao < 25 && random(10)==1) 
			{
				me->delete_temp("liandan");
				me->delete_temp("zhuyao");
				me->delete_temp("zjb_dan");
				dan = new("/d/liandan/xdan/dan3");
				dan->set("zhuren",""+me->query("id")+"");
				dan->move(me);
				message("party",HIC"〖"HIR"天炉神丹"HIC"〗"NOR+":"+HIG" 听说"HIM+me->name(1)+NOR HIG"在长安药店练成了一颗神丹（菩提子）！\n"NOR,users());
				return notify_fail(HIW"你练出了少林圣药菩提子!\n"NOR);
			}
			if ( zjb < 3 && all2 < 100  && all2 > 1 && random(4)==1) 
			{
				me->delete_temp("liandan");
				me->delete_temp("zhuyao");
				me->delete_temp("zjb_dan");
				dan = new("/d/liandan/obj/jinchuang");
				dan->set("zhuren",""+me->query("id")+"");
				dan->move(me);
				message("party",HIC"〖"HIR"天炉神丹"HIC"〗"NOR+":"+HIG" 听说"HIM+me->name(1)+NOR HIG"在长安药店练成了一颗神丹（金疮药）！\n"NOR,users());
				return notify_fail(HIY"你练出了疗伤用的强效金创药!\n"NOR);				
			}
			if ( zjb < 3 && all2 < 100 && all2 > 1 && random(4)==2) 
			{
				me->delete_temp("liandan");
				me->delete_temp("zhuyao");
				me->delete_temp("zjb_dan");
				dan = new("/d/liandan/obj/yangjing");
				dan->set("zhuren",""+me->query("id")+"");
				dan->move(me);
				message("party",HIC"〖"HIR"天炉神丹"HIC"〗"NOR+":"+HIG" 听说"HIM+me->name(1)+NOR HIG"在长安药店练成了一颗神丹（养精丹）！\n"NOR,users());
				return notify_fail(HIY"你练出了疗精用的强效养精丹!\n"NOR);
			}

		}

		//////////////////////////////////////////////////////////////////////////////////////////

		me->delete_temp("liandan");
		me->delete_temp("zhuyao");
		me->delete_temp("zjb_dan");
		dan = new("/d/liandan/obj/chayao");
		dan->set("zhuren",""+me->query("id")+"");
		dan->move(me);

		return notify_fail(HIW"你此次炼丹失败,练出一个无名药品!\n"NOR);
	}
}