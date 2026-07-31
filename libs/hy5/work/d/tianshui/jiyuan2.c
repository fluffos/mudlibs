// Room: /u/xiaozhen/jiyuan.c

inherit ROOM;

void create()
{
	set("short", "流香堂");
	set("long", @LONG
这里是流香堂.每隔五步，左右各一门。门上似有记
号，门后似有人声。每隔十步，烛灯一盏，忽明忽暗。
凝神细听，又似乎每户空空。走廊弯弯曲曲，向前伸
展，一眼望不到尽头。门口立着一块牌子(pai)。
LONG
	);
	//set("no_steal",1);
	set("exits", ([ /* sizeof() == 5 */
  "east" : __DIR__"ji4",
  "down" : __DIR__"jiyuan",
  "west" : __DIR__"ji2",
  "north" : __DIR__"ji1",
  "south" : __DIR__"ji3",
]));

	set("item_desc",([
	"pai" : "
每日天黑营业：

普通花酒(putong)   五两金子
银围花酒(yinwei)   十两金子
金围花酒(jinwei) 二十两金子

您可以摆(order)各种花酒\n\n"
]));

	//set("NORIDE",1);
	set("no_clean_up", 0);
	set("objects",([
	__DIR__"npc/gui_nu" :1,
  __DIR__"npc/m_boss" :1
]));
	setup();
}

void init()
{
	add_action("do_accept","accept");
	add_action("do_quit","quit");
}

int do_quit(string arg)
{
	object obj;
	if(this_player()->query_temp("jiyuan")) {
	if(obj = present("m_boss",find_object("/d/tianshui/jiyuan2")))
		obj->delete_temp("have_full");
	return 0;
	}
	return 0;
}

int do_accept(string arg)
{
	object obj,me = this_player();
	if(!me->query_temp("jiyuan/order")) return 0;
	if(!arg) return notify_fail("龟奴说：您要点哪位姑娘？\n");
	if(!obj = present(arg,this_object()))
		return notify_fail("龟奴说：您要点哪位姑娘？\n");
	if(!obj = present(arg,this_object())
	|| obj->query("class") != "jiyuan"
	|| obj->query("gender") != "女性"
	|| obj->query("id") == "m_boss")
		return notify_fail("龟奴说：您要点哪位姑娘？\n");
	me->delete_temp("jiyuan/shangqian");
	me->set_temp("jiyuan/shangqian",obj->name());
	message_vision("$N羞涩的一瞥$n娇滴滴的说：谢爷看得起奴，不过爷能不能赏奴几个再进房间。\n",obj,me);
	return 1;
}


int valid_leave(object me,string dir)
{
	object obj;
if (userp(me))
{
	if(dir == "down" && userp(me))
	{
	if(!me->query_temp("jiyuan/order")) return 1;
	call_out("zou_ren",2);
	me->delete_temp("jiyuan");
	if(obj = present("m_boss",find_object("/d/tianshui/jiyuan2")))
		obj->delete_temp("have_full");
        return ::valid_leave(me,dir);

	}
}
        return ::valid_leave(me,dir);

}

void zou_ren()
{
	object obj;
	if(obj = present("lian yu",this_object())) {
		tell_object(this_object(),obj->name()+"走了。\n");
		destruct(obj);
		}
	if(obj = present("wan xiang",this_object())) {
		tell_object(this_object(),obj->name()+"走了。\n");
		destruct(obj);
		}
	if(obj = present("xiang yu",this_object())) {
		tell_object(this_object(),obj->name()+"走了。\n");
		destruct(obj);
		}
	if(obj = present("hong xiu",this_object())) {
		tell_object(this_object(),obj->name()+"走了。\n");
		destruct(obj);
		}
}
