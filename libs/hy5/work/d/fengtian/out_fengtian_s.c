// Room: /d/fengtian/out_fengtian_s.c

inherit ROOM;

void create()
{
	set("short", "盛京府南门外");
	set("long", @LONG
走到这里就到了盛京了。北面是盛京府的南门，几个官军在
盘查着过往的行人。往南看去是一条笔直的青石官道。
LONG
	);

	set("exits", ([ /* sizeof() == 2 */
	"north" : __DIR__"s_gate",
  "south" : "/d/yanjing/to_yj3",
]));
        set("objects",([
        	__DIR__"npc/jinbing" :3,        	
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
	&& (dir == "north") )
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
