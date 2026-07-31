// Room: /d/taishan/.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "南天门");
	set("long", @LONG
走完了十八盘，这里便是泰山顶的入口处。从这里附视山下，群山如龟伏
地，河流如蚓缠绕，天地空阔，无可名状。从这里往东北走可到一个市集，往
西走便是月观峰，往北走则是到玉皇顶之路。
LONG
	);

	set("exits", ([
//		"eastup" : __DIR__"tianjie",
		"northup" : __DIR__"yuhuang",
//		"west" : __DIR__"yueguan",
		"southdown" : __DIR__"shengxian",
	]));

	set("objects",([
                __DIR__"npc/qinbing" : 1,
		__DIR__"npc/qinbing1" : 2,
	]));

	set("outdoors", "泰山");
	setup();
}

int valid_leave(object me, string dir)
{

	if(dir == "northup"
		&& present("qinbing", environment(me))
		&& me->query("combat_exp") < 100000 ) {
                return notify_fail(HIY "亲兵队长勃然大怒，喝道：大胆鼠辈, 竟敢骚扰盟主？！我跟你拼了！\n");
	}
       	if(dir == "northup"
               && present("qinbing duizhang", environment(me))
               && me->query("combat_exp") >= 100000) 
                      message_vision("亲兵队长道：这位英雄上面请。\n", me);
	return ::valid_leave(me, dir);
}
