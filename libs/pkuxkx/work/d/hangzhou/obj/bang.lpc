#include <ansi.h>
#include <title.h>
inherit ITEM;
int walk_msg(object me,int no);
void create()
{
        set_name(WHT"石碑"NOR,({ "shi bei","bei"}) );
        set_weight(4000000);
        set("unit", "座");
        set("value", 10);
        set("material", "stone");
        set("long", "这是今上勒石为碑，记载武林中的高手，以激励后进，抗击异族入侵。\n共分五榜，分别是天榜、地榜、风云榜、龙虎榜以及六合榜。\n");                
        set("no_drop",1);
        set("no_get",1);
		
        setup();
}

void init()
{
	add_action("do_guan",({"guan","watch"}));
	add_action("do_selfrank",({"selfrank",}));
	add_action("do_selftitle",({"selftitle",}));
	add_action("do_hide","hide");
	add_action("do_unhide","unhide");
	add_action("do_lookup","lookup");
	add_action("do_show","show");
	add_action("do_selectWalkMsg","SelectMsg");
}
int do_lookup(string id)
{
	object me=this_player();
	string msg;
	if (time()-query("LastQuery")<5)
	{
		write("现在正有人在查榜呢，等等吧。\n");
		return 1;
	}
	if (!id)
	{
		write("你要在榜单上查谁(id)？\n");
		return 1;
	}
	if (strwidth(id)<3||strwidth(id)>12)
	{
		write(id+"不是一个合法id。\n");
		return 1;
	}
	if (member_array(id,STATISTIC_D->hide_list())!=-1&&id!=me->query("id"))
	{
		write(id+"已经隐姓埋名了。\n");
		return 1;
	}
	set("LastQuery",time());
	msg=STATISTIC_D->lookup(id);
	if (id==me->query("id"))
	{
		if (msg=="")
		write("你没有能上榜。\n");
		else
		{	
			msg=replace_string(msg,id,"你");
			write(msg);
		}
	}
	else
	{
		if (msg=="")
		write(id+"没有能上榜。\n");
		else
		write(msg);
	}
	return 1;
}
int do_hide()
{
	object me=this_player();
	if (time()-query("LastQuery")<10)
	{
		write("现在正有人在查榜呢，等等吧。\n");
		return 1;
	}
	else if (STATISTIC_D->lookup(me->query("id"))=="")
	{
		write("你根本没有上榜，就不必隐藏了。\n");
	}
	else
	{
		message_vision(HIG"$N悄悄将榜单上自己的名字涂上污迹。\n"NOR,me);
		STATISTIC_D->access_me(me->query("id"),0);
		set("LastQuery",time());
	}
	return 1;
}
int do_unhide()
{
	object me=this_player();
	if (time()-query("LastQuery")<10)
	{
		write("现在正有人在查榜呢，等等吧。\n");
		return 1;
	}
	else if (STATISTIC_D->lookup(me->query("id"))=="")
	{
		write("你根本没有上榜！\n");
	}
	else
	{
		message_vision(HIG"$N将榜单上自己的名字上的污迹除去。\n"NOR,me);
		STATISTIC_D->access_me(me->query("id"),1);
		set("LastQuery",time());
	}
	return 1;
}
int do_selftitle(string arg)
{
	int mark=0;
	object me=this_player();
	mapping *list=STATISTIC_D->ret_list(4);
	for (int i=0;i<sizeof(list);i++)
		if (me->query("id")==list[i]["id"])
			mark=1;
	if (!mark) return 0;
	if (me->query("user_title"))
	{
		write ("你已经设定过天榜头衔了。\n");
		return 1;
	}
	if (!me->query_temp("user_title"))
	{
		write("天榜中人专属头衔，可以自定义设定，支持颜色，比如$HIG$混天龙。\n");
		write(RED+"所选头衔必须符合武侠意境，否则将被取消头衔殊荣并受到一定惩罚。\n"+NOR);
		write("你现在可以用selftitle 命令设定了。\n");
		me->set_temp("user_title",1);
		return 1;
	}
	if (!arg) 
	{
		write("你要设定什么天榜头衔？\n");
		return 1;
	}
	if (strwidth(arg)>40)
	{
		write("你设定的天榜头衔太长了，短一些吧。\n");
		return 1;
	}
	arg = F_NAME->replace_color(arg);
	me->set_title(TITLE_USER,arg);
	me->set("user_title",1);
	me->set("title",me->get_title(TITLE_USER));
	CHANNEL_D->do_channel(this_object(), "jh", HBWHT+HIR+"天榜中人"+me->query("name")+HBWHT+HIR+"("+capitalize(me->query("id"))+")被江湖尊称"+arg+HBWHT+HIR+"。\n"NOR, -1);
	return 1;
}
int do_selfrank(string arg)
{
	object ob=this_player();
	if (STATISTIC_D->ret_top5()&&arrayp(STATISTIC_D->ret_top5())&&member_array(ob->query("id"),STATISTIC_D->ret_top5())!=-1)
	{
		if (ob->query("TOP5/rank_name"))
		{
			write("你已经设定过五绝尊号了。\n");
			return 1;
		}
		if (!arg) 
		{
			write("你要自称什么尊号？\n");
			return 1;
		}
		if (strwidth(arg)!=2)
		{
			write("尊号只能选择一个汉字。\n");
			return 1;
		}
		if (!CHINESE_D->is_chinese_character(arg))
		{
			write("尊号只能选择一个汉字。\n");
			return 1;
		}
		if (member_array(arg,STATISTIC_D->top5rank())!=-1)
		{
			write("这个字已经被人选过了。\n");
			return 1;
		}
		ob->set("TOP5/rank_name",arg);
		STATISTIC_D->save_rankword(arg);
		write("恭喜！你在江湖中被尊为五绝之一，"+RANK_D->query_rank(ob)+"。\n");
		return 1;
	}
	return 0;
}
string display_it(string id,int i,int wiz,int hide)
{
	string msg,*colors=({HBMAG+HIY,HBRED+HIW,HBGRN+HIC}),color="",space="",mycolor;
	object pl;
	if (i<=2)
	{
		space=sprintf("%3s"," ");
		color=colors[i];
	}
	if (pl=find_player(id))
	{
		mycolor=COLOR_D->get_color(pl->query("name"));
		if (wiz&&hide)
		msg=sprintf("%-8s",color+"第"+(i+1)+"名")+NOR+space+" "+sprintf("%-56s",HIG+sprintf("%-8s",pl->query("family/family_name")?pl->query("family/family_name"):"")+NOR+"  "+COLOR_D->uncolor(pl->query("name"))+"("+capitalize(pl->query("id"))+")[隐]"+NOR);
		else
		msg=sprintf("%-8s",color+"第"+(i+1)+"名")+NOR+space+" "+sprintf("%-56s",HIG+sprintf("%-8s",pl->query("family/family_name")?pl->query("family/family_name"):"")+NOR+"  "+COLOR_D->uncolor(pl->query("name"))+"("+capitalize(pl->query("id"))+")"+NOR);
		msg=replace_string(msg,COLOR_D->uncolor(pl->query("name")),mycolor+pl->query("name")+NOR);
	}
	else
	{
		if (!hide)
		msg=sprintf("%-8s",color+"第"+(i+1)+"名")+NOR+space+" "+sprintf("%-56s",NOR+""+HIW+capitalize(id)+NOR);
		if (wiz&&hide)
		msg=sprintf("%-8s",color+"第"+(i+1)+"名")+NOR+space+" "+sprintf("%-56s",NOR+""+HIW+capitalize(id)+"[隐]"+NOR);
	}
	if (!wiz&&hide)
		msg=sprintf("%-8s",color+"第"+(i+1)+"名")+NOR+space+" "+sprintf("%-56s",NOR+""+HIC+"隐姓埋名"+NOR);
	return msg;
}
string deco_it(object me,mapping *list,int i)
{
	string msg;
	if (member_array(list[i]["id"],STATISTIC_D->hide_list())!=-1)
	{
		if (wizardp(me))
		msg=display_it(list[i]["id"],i,1,1);
		else
		msg=display_it(list[i]["id"],i,0,1);
	}
	else if (find_player(list[i]["id"]))
		msg=display_it(list[i]["id"],i,0,0);
	else
		msg=display_it(list[i]["id"],i,0,0);
	return msg;
}
int do_guan(string flag)
{
	string msg;
	string *querys=({"_10_50","_50_100","_100_400","_400_800","_800"});
	string *bang_names=({"六合","龙虎","风云","地","天"});
	string *bang_colors=({HIG,CYN,HIC,HIY,HIW});
	mapping *list;
	int no,order=random(2);
	if (!flag)
	{
		write(RED"共分五榜，分别是天榜、地榜、风云榜、龙虎榜以及六合榜。你要观看哪一榜？\n"NOR);
		return 1;
	}
	flag=replace_string(flag,"榜","");
	no=member_array(flag,bang_names);
	if (no==-1)
	{
		write(RED"共分五榜，分别是天榜、地榜、风云榜、龙虎榜以及六合榜。你要观看哪一榜？\n"NOR);
		return 1;
	}
	msg=sprintf("%|86s","『"+bang_colors[no]+bang_names[no]+"榜高手』"+NOR);
	msg+="\n"+sprintf("%-90s","--------------------------------------------------------------------------------\n");
	list=STATISTIC_D->ret_list(no);
	for (int i=0;i<sizeof(list);i++)
	{
		msg+=deco_it(this_player(),list,i);
		if (i%2==1) msg+="\n";
	}
	write(msg+"\n");
	return 1;
}
string *come_msgs=({HIC+"$N"+HIC+"不紧不慢地踱着步子走了过来。\n"+NOR,CYN+"$N"+CYN+"疾步走了过来，众人感到渊渟岳峙般的气势。\n"+NOR,
	HIG+"$N"+HIG+"不疾不徐地走了过来。\n"+NOR,RED+"$N"+RED+"走过来扫了在场各人一眼，一股凛冽的杀意油然而生。\n"+NOR,
	HIY+"一道身影出现在场间，你定睛一看，却是$N"+HIY+"。\n"+NOR,YEL+"$N"+YEL+"一步一顿走了过来，身后坚实的地面上留下了一串脚印。\n"+NOR,
	HIM+"你闻到一丝淡淡的香气，紧接着$N"+HIM+"走了过来。\n"+NOR,MAG+"$N"+MAG+"目不斜视地走了过来。\n"+NOR,
	HIW+"$N"+HIW+"如离弦之箭一般冲了过来。\n"+NOR,WHT+"$N"+WHT+"走了过来，众人直觉得一股清凉之意沁入心扉。\n"+NOR,
	HIB+"一道人影轻轻地飘了过来。\n"+NOR,BLU+"一道淡淡的人影飘了过来。\n"+NOR,HIR+"杀气！一人带着浓烈的杀气走了过来。\n"+NOR});

string *leave_msgs=({HIC+"$N"+HIC+"不紧不慢地踱着步子离开了。\n"+NOR,CYN+"$N"+CYN+"快步离开，如山的气势也随之而散。\n"+NOR,
	HIG+"$N"+HIG+"不疾不徐地离开了。\n"+NOR,RED+"杀意随着$N"+RED+"也离开了这里。\n"+NOR,
	HIY+"$N"+HIY+"身形略动，已经离开了这里。\n"+NOR,YEL+"$N"+YEL+"慢慢地离开。\n"+NOR,
	HIM+"$N"+HIM+"似慢实快，一转眼已经离开了这里。\n"+NOR,MAG+"$N"+MAG+"气定神闲地离开。\n"+NOR,
	HIW+"一转眼，场间早已没有了$N"+HIW+"的身影。\n"+NOR,WHT+"$N"+WHT+"轻轻地离开了。\n"+NOR,
	HIB+"不经意间，只是人影一闪。\n"+NOR,BLU+"一道淡淡的人影一闪就消失不见了。\n"+NOR,HIR+"杀气随之而散。\n"+NOR});
int do_show(string arg)
{
	object me=this_player();
	int num;
	for (int i=0;i<13;i++)
	{
		if (STATISTIC_D->query("WalkMsg/"+i)&&arrayp(STATISTIC_D->query("WalkMsg/"+i))) num=sizeof(STATISTIC_D->query("WalkMsg/"+i));
		else num=0;
		write(sprintf("%4s","["+i+"]")+" "+num+"人选择。\n"+"【来】"+replace_string(come_msgs[i],"$N",me->query("name"))+"【去】"+replace_string(leave_msgs[i],"$N",me->query("name"))+"\n");
	}
	me->set_temp("ShowWalkMsg",1);
	return 1;
}

int do_selectWalkMsg(string arg)
{
	object me=this_player();
	int times,err=1;
	string posi=STATISTIC_D->lookup(me->query("id")),*desc;
	if (me->query("msg_come")||me->query("msg_leave"))
		return notify_fail("你已经设置过行走描述信息了。\n");
	if (posi==""&&!wizardp(me))
	return 0;
	if (wizardp(me)) err=0;
	else
	{
		posi=replace_string(posi,me->query("id"),"");
		posi=replace_string(posi,"在","");
		posi=replace_string(posi,"榜第","|");
		posi=replace_string(posi,"位。","");
		desc=explode(posi, "|");
		if (desc[0]=="天") err=0;
		if (desc[0]=="地"&&to_int(desc[1])<=16) err=0;
	}
	if (err) return 0;
	if (!arg) return notify_fail("请在0-12间选择你需要的行走描述信息提示。\n");
	if (sscanf(arg, "%d", times) != 1) return notify_fail("请在0-12间选择你需要的行走描述信息提示。\n");
	if (times<0||times>12) return notify_fail("请在0-12间选择你需要的行走描述信息提示。\n");
	if (!me->query_temp("ShowWalkMsg")) return notify_fail(BLINK+RED+"请先用show命令查看仔细后再选择，一旦选定，无法改变。\n"+NOR);
	STATISTIC_D->save_WalkMsg(me,times);
	me->set("msg_come",come_msgs[times]);
	me->set("msg_leave",leave_msgs[times]);
	me->delete_temp("ShowWalkMsg");
	me->save();
	tell_object(me,HIW+"恭喜！设置个性化行走描述信息成功。\n"+NOR);
	return 1;
}