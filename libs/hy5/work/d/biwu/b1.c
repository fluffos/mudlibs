inherit ROOM;
void create()
{
	set("short", "风雨楼");
	set("long", @LONG
这是一个纠集了江湖上十大正派高手的楼，共有十层之高。
LONG );
       set("no_sleep_room",1);
       set("no_clean_up", 0);
	set("exits", ([
		"northdown" : "/d/city/guangchang",
		"up":__DIR__"b2",
	]));
		set("objects", ([
			__DIR__"miejue": 1,
		]));
setup();
}

void init()
{
add_action("do_dazuo","dazuo");
add_action("do_dazuo","exercise");
add_action("do_dazuo","steal");
add_action("do_dazuo","beg");
add_action("do_dazuo","fight");
add_action("do_dazuo","ansuan");
add_action("do_dazuo","hit");
add_action("do_dazuo","get");
if(userp(this_player()) && (!this_player()->query_temp("for_okok")))
{call_out("awayaway",1800);
message_vision("你只有三十分钟的时间来击败所有正派高手。无论成功与否，一刻钟后你将自动被送回广场中央。\n",this_player());
this_player()->set_temp("for_okok",1);
}
}

int awayaway()
{
object me;
if (!me) return notify_fail("你已经不在了！\n");
me= this_player();
message_vision("已过了一刻钟的时间，$N将被送到广场中央。\n",me);
me->move("/d/city/guangchang");
message_vision("$N的身形突然出现在广场中央。\n",me);
this_player()->set_temp("for_okok",0);
return 1;
}

int do_dazuo()
{
   object me;
   me = this_player();
   tell_object(me,"这里不能用这个指令。\n");
return 1;
}
int valid_leave(object me, string dir)
{
        object ob;
if( userp(me) &&
dir=="up" && ob=present("miejue shitai", this_object()))
return notify_fail( 
"你想硬闯？！\n");
if (me->query("shen")<0&&dir=="up")
return notify_fail("这里不欢迎邪派人事！\n");

return 1;
}
