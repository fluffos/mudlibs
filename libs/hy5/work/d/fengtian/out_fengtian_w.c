
/*此段代码由 PLAYERHOME_D 自动生成,切勿改变其中任何内容!!*/
#include <room.h>
/*代码自动生成完毕.*/
// Room: /d/fengtian/out_fengtian_w.c

inherit ROOM;

void create()
{
	set("short", "盛京府西门外");
	set("long", @LONG
走到这里就到了盛京了。东面是盛京府的西门，几个官军在
盘查着过往的行人。往西看去是一条笔直的青石官道。
LONG
	);

	set("exits", ([
	"east" : __DIR__"w_gate",
  "west" : "/d/menggu/caoyuan4",
]));

	set("outdoors","fengtian");
	setup();


}

int valid_leave(object ob,string dir)
{
	object *inv;

	if(!ob || !stringp(dir))
		return 1;

	if( userp(ob)
	&& !wizardp(ob)
	&& (dir == "east") )
	{
		inv = filter_array(deep_inventory(ob),
			(: $1->is_character()
			&& ( $1->query("attitude") == "killer"
			|| $1->query("attitude") == "aggressive" ) :));

		if(sizeof(inv))
			return notify_fail(sprintf("突然从边上跳出两个卫士说道：敢带%s进城害人，活的不耐烦啦！\n",
				inv[0]->query("name")));
	}
	return ::valid_leave(ob,dir);
}
