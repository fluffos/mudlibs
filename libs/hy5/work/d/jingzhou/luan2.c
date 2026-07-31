// Room: luan2
// congw 980830 

inherit ROOM;

void create()
{
	set("short", "乱坟岗");
	set("long", @LONG
这里是一处乱坟岗，到处长满了过人高的长草，听说经常闹鬼，所以没人敢来。哎哟
。。。。一阵冷风刮来，吓的你根根体毛竖起。咦。。！好像有一座新坟！坟上立有
一块碑(tablet)。
LONG
	);

	set("exits", ([
		"west" : __DIR__"luan",
			]));

	set("item_desc", ([
		"tablet" : "只见上面写着：“爱女凌霜华之墓” \n",
	]));

	setup();
}

void init()
{
        add_action("do_push", "push");
	UPDATE_D->check_user(this_player());
}

int do_push(string arg)
{
	object me;
	me = this_player();

        if( !arg || arg=="" ) return 0;

        if( arg=="bei" ) 
	{
		message("vision",
			me->name() + "人影一闪，不见了踪影。\n",
			environment(me), ({me}) );
                me->move("/d/jingzhou/tomb");
                 set("exits/east", __DIR__"tomb");
                message("vision",
			me->name() + "走了进来。\n",
                	environment(me), ({me}) );
		return 1;
	}
}	
