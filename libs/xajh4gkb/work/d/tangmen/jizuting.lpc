// Room: /d/tangmen/jizhuting.c
//by hem
inherit ROOM;

void create()
{
	set("short", "祭祖厅");
	set("long", @LONG
	这里是唐门供奉先人的大厅，厅内挂满了历代唐门先祖的画像。正中是一个
很大的供桌，有一些果品、香烛。供桌顶上有一块匾(bian)。
LONG
	);
	

	set("exits", ([
		
		"west" : __DIR__"huayuan12",
		"north" : __DIR__"changlang9",
		"south" : __DIR__"changlang10",
	]));
	set("item_desc", ([
		"bian" : "匾上是大大的几个字：万古流芳。再仔细看，匾后露出一个角，好象有什么东西。\n",
	]) );

	setup();
}

void init()
{
	add_action("do_jump", "jump");
}

int do_jump(string arg)
{
    int n;
	object me = this_player();

    if( !arg || arg!="bian" )
	{
        write("这里是祭祖厅，你乱蹦乱跳干什么！\n");
        return 1;
    }
message_vision(
    "$N运起轻功，想跳到匾上。\n", this_player());

    n = (int)me->query("dex");
    if (n >= 18)
	{
        message_vision(
        "$N纵身一跃，轻飘飘落到了匾上！\n", this_player());
        me->move("/d/tangmen/mubian");
        }
    else
	{
	message_vision(
	"结果一不小心碰到了供桌，摔了个仰八叉。\n", this_player());
	this_player()->unconcious();
         }

    return 1;
}
