// 发呆房间，嘿嘿
// by Looklove 2001/11/12

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short","休息室");
	set("long",@long
由于您的信箱已经过期，导致您无法正常享受信箱的增值服务，如果您
还想正常的参与游戏，请尽快续费。具体内容可参阅相关新闻。
long);
	set("outdoors", "扬州");
	set("no_update", 1);
	set("no_fight", 1);
	set("no_save", 1);
	set("exits", ([
		"宝昌客栈" : "/d/city/kedian",
		"中央广场" : "/d/city/guangchang",
		"月老亭"   : "/d/city/yuelaoting",
		"城隍庙"   : "/d/city/chmiao",
		"武馆前院" : "/d/wuguan/dayuan",
		"泰山封禅台"   : "/d/taishan/fengchan",
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me)) {
		message_vision("$N向"+query("exits/"+dir)->query("short")+"的方向走去，过了半天，发现自己还在原地。\n", me);
		me->add_busy(1);
		return 0;
	}
	return ::valid_leave(me, dir);
}
