//石梁
//by icer
inherit ROOM;
void create()
{
        set("short", "石梁");        set("long", @LONG
延着小路向前走去，行不多时，山路就到了尽头，前面是一条宽约尺许的石梁，
横架在两座山峰之间，云雾笼罩。石梁尽头有一个极长的缺口，看来总在一丈开外，
LONG
);
        set("no_task",1);
set("exits", ([
                "down" :__DIR__"banshan2",
]));
set("outdoors", "taoyuan");
setup();
}

void init()
{
	add_action("do_jump","jump");
}
int do_jump()
{
	if ((int)this_player()->query_skill("dodge",1)>180)
	{
	    if (this_player()->query_temp("marks/读2"))
	    {
		write("你提气一跃，过了那个缺口，在那书生先前坐处稳稳落住。那书生将你引到一处庙内。\n");
		this_player()->move(__DIR__"xiangfang");
		return 1;
	    }
	    else {
			return notify_fail("如要跳过缺口，只能在书生坐的地方落脚。这可如何是好？\n");
		}
	}
	else
	{
		write("一阵山风吹来，你脚下一个不稳，跌进了无底深渊之中......\n");
        this_player()->receive_damage("qi", 0, "跌进无底深渊");
        this_player()->die();

		return 1;
	}
}
