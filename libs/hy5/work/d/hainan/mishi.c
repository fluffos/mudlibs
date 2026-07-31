// Room: /d/hainan/mishi.c

inherit ROOM;

void create()
{
	set("short", "密室");
	set("long", @LONG
这是一间阴暗的小屋，很潮湿。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"chucang",
]));
	set("no_clean_up", 0);

	setup();
}

void init()
{
        add_action("do_tui","tui");
}
int do_tui(string arg)
{
        object me;
        me = this_player();
        if (arg != "窗户")return 0;
        if (me->query("str") < 25 || me->query("neili") < 200)
                return notify_fail("你使劲推了推窗户，结果没推动。\n");
        message_vision("$N推开了窗户，眼前顿时一亮，原来密室外边别有一番天地。\n",me);
        set("exits/out", __DIR__"taoyuan");
        me->add("force",-200);
        return 1;
}


