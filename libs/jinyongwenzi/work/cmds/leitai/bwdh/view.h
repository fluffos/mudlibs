// view.h

#define LONG "这是比武大会的观看场所,人山人海，如火如荼的比武大会正\n在紧张的举行着。前面有一个很大的眺望台,可以一直看到比武现\n场。被指定为控制员的玩家可以自由切换所要观看的场地。\n"
void init()
{
	object me = this_player();

         if (userp(me) && !wizardp(me))  me->start_busy(10);
        add_action("do_kan",({"kan"}));
        if (!wiz_level(me) || wiz_level(me) < 3) return;
        add_action("do_control",({"control"}));
}

int do_kan(string arg)
{
        object me = this_player();
        object ob;

        if (!wizardp(this_player()) && this_player()->query("id") != query("controller"))
		return notify_fail("你又不是控制员,怎么调换频道?!\n");
        if (!arg)
                return notify_fail("请用kan xxxx换台。\n");
	if (arg != "snooper1"
	 && arg != "snooper2"
         && arg != "snooper3"
         && arg != "snooper4"
         && arg != "snooper5"
         && arg != "snooper6")
        	return notify_fail("请用kan xxxx换台。选项有：snooper1,snooper2,snooper3,snooper4,snooper5,snooper6。\n");
        if (!query("start"))
                return notify_fail("比武还没开始呢，别乱动！\n");
        if (!query(arg))  return notify_fail("目前这个频道还没有什么好看的！\n");
        set_temp("b4",query_temp("view"));
        set_temp("view",arg);
        message_vision(HIW"\n$N将频道换到了"+arg+"上。\n"NOR,me);
//        if (!objectp(ob = find_object("/cmds/leitai/bwdh/obj/"+arg+".lpc")))  return notify_fail("监视器丢失，严重错误，请向巫师报告！\n");
        if (query(arg) == "die") {
                tell_room(this_object(),HIY"【屏幕】 本频道已经结束。\n          现在将自动跳转到"+ob->query_temp("b4")+"频道。\n");
                set_temp("view",query_temp("b4"));
                return 1;
        }
        tell_room(this_object(),HIY"\n【屏幕】本频道现在正在全程直播"+find_player(query(arg))->name(1)+"("+query(arg)+")的比赛，欢迎收看。\n"NOR);
        return 1;
}

int do_control(string arg)
{
	object me = this_player();

	if (!arg)
        return notify_fail("指令格式: control <ID|none>。\n");
        if (arg == "none") {
                tell_object(me,"你收回了所有大厅的控制权。\n");
                load_object("/cmds/leitai/bwdh/view1")->delete("controller");
                load_object("/cmds/leitai/bwdh/view2")->delete("controller");
                load_object("/cmds/leitai/bwdh/view3")->delete("controller");
                load_object("/cmds/leitai/bwdh/view4")->delete("controller");
                load_object("/cmds/leitai/bwdh/view5")->delete("controller");
                load_object("/cmds/leitai/bwdh/view6")->delete("controller");
                return 1;
        }
	if (!query("controller"))
		message_vision(HIR"\n$N将控制权交给了"+arg+"。\n",me);
	else
		message_vision(HIR"\n$N将控制权由"+query("controller")+"交给了"+arg+"。\n",me);
	set("controller",arg);
	return 1;
}
