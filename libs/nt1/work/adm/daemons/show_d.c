//本程序中部分预定义在globals.h里实现，而TMI的定义如下：
//#define TMI(x) (""+x+"")   //(char[25]+x+char[26])

string welmsg = TMI("alert 你好，欢迎光临TOMUD文字MUD扩展协议演示站点\n下面将演示如何让你的MUD支持TOMUD文字MUD客户端的种种功能"
		"\n请按照指示输入命令，如果要退出，请输入quit命令。\n"
		"本演示只是简单演示，如果有任何疑问和建议，请访问http://bbs.tomud.com/\n询问TOMUD小组成员。\n"
		"                                                      TOMUD 小组 2002\n");	
string byemsg = TMI("alert 再见，欢迎光临http://www.tomud.com，感谢对TOMUD中文MUD通用客户端的关心和支持！");
/*
演示内容：
1、ALERT窗口
2、演示房间列表添加
3、携带物品列表添加
（然后还有两个列表的删除）
//4、演示右键菜单
5、演示QQ信息
6、演示状态条信息
*/
mapping sw=([
	"0":
	([
		"info":"如何弹出一个窗口显示一些信息",
		"code":"write(TMI(\"alert 你好，这是alert命令（弹出信息）演示\"))",
		"out" :TMI("alert 你好，这是alert命令演示"),
		"desc":"要让TOMUD实现各种功能，最关键就是要以指定的格式向TOMUD客户端输出命令字符串！",
	]),
	"1":           
	([
		"info":"如何添加房间列表信息",
		"code":"write(TMI(\"lbadd0 玩家A(playera)01173;\")+TMI(\"lbadd0 玩家B(playerb)昵称01174;\")+TMI(\"lbadd0 物品A(objectA)00961;\"))",
		"out" :TMI("lbadd0 玩家A(playera)01173;")+TMI("lbadd0 玩家B(playerb)昵称01174;")+TMI("lbadd0 物品A(objectA)00961;"),
		"desc":"这个命令的目的是在房间列表里增加指定的一个列表项，即使该列表框未显示，\n也应该输出这个以维持列表数据同步。",
	]),             
	"2":           
	([
		"info":"如何添加物品列表信息",
		"code":"write(TMI(\"lbadd1 物品A(objecta)00961;\")+TMI(\"lbadd1 物品B(objectb)昵称00961;\")+TMI(\"lbadd1 物品C(objectC)00961;\"))",
		"out" :TMI("lbadd1 物品A(objecta)00961;")+TMI("lbadd1 物品B(objectb)昵称00961;")+TMI("lbadd1 物品C(objectC)00961;"),
		"desc":"这个命令的目的是在玩家物品列表里增加一个列表项，即使该列表框未显示，\n也应该输出这个以维持列表数据同步。",
	]),  
	"3":           
	([
		"info":"如何添加WHO列表信息，可以通过按右下命令面板上的WHO按钮来测试",
		"code":"write(TMI(\"lbadd2 玩家A(playera)01173;\")+TMI(\"lbadd2 玩家B(playerb)昵称01174;\")+TMI(\"lbadd2 玩家C(playerC)00961;\"))",
		"out" :TMI("lbadd2 玩家A(playera)01173;")+TMI("lbadd2 玩家B(playerb)昵称01174;")+TMI("lbadd2 玩家C(playerC)00961;"),
		"desc":"按Who按钮后，会给服务器端发出([who 我爱笑傲江湖])取全体列表，之后再按也不会发出该命令\n"
			"但是lbadd2命令应该在每个用户上线时广播，同时在离线时广播从列表删除的命令信息。\n这样who列表就可以即时获取在线情况。",
	]),
	"4":           
	([
		"info":"如何从列表里删除列表数据",
		"code":"write(TMI(\"lbrem0 玩家A(playera)01173;\")+TMI(\"lbrem1 物品B(objectb)昵称00901;\")+TMI(\"lbrem2 玩家C(playerC)00961;\"))",
		"out" :TMI("lbrem0 玩家A(playera)01173;")+TMI("lbrem1 物品B(objectb)昵称00901;")+TMI("lbrem2 玩家C(playerC)00961;"),
		"desc":"删除跟添加很类似，只需要把命令里的add更改为rem就可以了",
	]),
	"5":           
	([
		"info":"如何以QQ窗口方式弹出私聊窗口",
		"code":"write(TMI(\"ctell name=泥巴;ID=myid;icon=01173;;talk=这是我要对你私聊的话\"))",
		"out" :TMI("ctell name=泥巴;ID=myid;icon=01173;;talk=这是我要对你私聊的话"),
		"desc":"显示QQ对话框是很容易的，不过TOMUD并未将其替换了以前系统里的tell命令，而是用ctell来替换\n"
			"TOMUD显示控制是输出ctell命令，而TOMUD在将用户输入回复的时候也是发送ctell命令，所以需要\n"
			"你的服务器添加该命令（可以将tell命令复制过来然后修改一下输出部分即可）",
	]),
	"6":           
	([
		"info":"如何在状态条里显示状态数据",
		"code":"write(TMI(\"statu 气11精22精力33内力44食55水66潜能77经验88\"))",
		"out" :TMI("statu 气11精22精力33内力44食55水66潜能77经验88"),
		"desc":"你只需要修改/feature/message.c，增加对应的prompt处理就可以实现状态条即时更新了",
	]),
]);

int swtotal=0;  

void logon(object ob)
{
	write(welmsg);
	swtotal=sizeof(sw);
	write(ALERT("请输入go命令继续演示！共有演示"+swtotal+"项！"));
	input_to("start_show",ob,0);
	return ;
}

void start_show(string arg,object ob,int step)
{
	mapping m;
	string tmp;
	arg=lower_case(arg);
	if(arg=="who 我爱笑傲江湖")
	{
		write(sw["3"]["out"]);
		input_to("start_show",ob,step);
		return ;
	}
	if(arg=="quit" ||arg=="exit" || step==swtotal)
	{
		write(byemsg);
		destruct(ob);
		return ;
	}
	if(sscanf(arg,"actionavailable%*s"))
	{
		string win;
		if( sscanf(arg, "%s,%s", arg, win)!=2)
		{
			write("出错！");
		}
		if(win=="0")
			write(TMI("mbegin 选定房间对象;id")+TMI("mitem 观察$U;")+TMI("mitem 继续演示;go")+TMI("mendd"));
		else
			write(TMI("mbegin 选定携带对象;id")+TMI("mitem 观察$U;")+TMI("mitem 继续演示;go")+TMI("mendd"));
		input_to("start_show",ob,step);
		return ;
	}
	if(arg!="go")
	{
		write(ALERT("请输入go命令继续演示！"));
		input_to("start_show",ob,step);
		return;
	}
	m=sw[""+step];
	if(step<swtotal-1 && step > -1)
	{
		tmp="下一个go命令将演示："+sw[""+(step+1)]["info"];
		write(m["info"]+"\n目的："+m["desc"]+"\n示例代码：\n"+m["code"]+"\n\n效果已经输出！\n\n"+tmp+"\n"+m["out"]);
		input_to("start_show",ob,step+1);
	}
	else 
	{
		tmp="输入任意命令结束演示！";
		write(m["info"]+"\n目的："+m["desc"]+"\n示例代码：\n"+m["code"]+"\n\n效果已经输出！\n\n"+tmp+"\n"+m["out"]);
		write(byemsg);
		destruct(ob);
		return;
	}
}
