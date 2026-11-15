//by 微笑 luoyun's ednpc tools.
// shenxun.c


inherit ROOM;

void create()
{
	set("short","申述室");
	set("long","这里是申述室，你可以向管理员发送申述材料。");
	set("exits", ([
		"north" : __DIR__"block",
	]));
	set("objects", ([
	]));
	setup();
}
void init()
{
	if (!wizardp(this_player()))
	{
		this_player()->set("startroom", "/d/death/block");
		add_action("discmds",({"use","eat","fly","research","yanjiu","jiqu","derive","suicide","jobto","myshop","study","inventory","sleep","kill","fight","hit","conjure","expell","perform","prcatice","fly","exercise","respirate"}));
	}
}
int discmds()
{
	tell_object(this_player(),"还是老实呆着吧！！！\n");
	return 1;
}
