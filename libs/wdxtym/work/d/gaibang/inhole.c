// Room: /d/gaibang/inhole.c
inherit ROOM;

int do_say(string arg);

void create()
{
	set("short", "树洞内部");
	set("long", @LONG
这是杨州城中央广场的老榕树内部，也是丐帮秘密的地下通道的总交
汇处。树洞里丢满了各种垃圾，弭漫着一股臭哄哄的味道。树洞壁上钉着
一块非常醒目的木牌。
LONG );
	set("exits", ([
		"north" : "d/gaibang/jingji/enter",
		"out" : "d/city/guangchang"
	]));
	set("item_desc",([
		"【木牌】"	: "富人地狱，穷人天堂。\n"
		ZJOBACTS2"暗号:say 天堂有路你不走呀\n",
	]));
	set("objects",([
		CLASS_D("gaibang") + "/zuo-qu" : 1,
	]));
	setup();
}

void init()
{
	add_action("do_say", "say");
}

int do_say(string arg)
{
	if(query("exits/down")) 
	{
		write("门已经是开着的了，直接进吧。\n");
		return 1;
	}
	else if( arg=="天堂有路你不走呀" ||  arg=="地狱无门你进来啊") 
	{
		write("只听里面有人说了声：是本帮兄弟吧？请进来吧。\n");
		message("vision", "树洞边上一堵墙缓缓移了开来，原来是道小木门。\n", this_player());
		set("exits/down", __DIR__"undertre");
		remove_call_out("close");
		call_out("close", 10, this_object());
		return 1;
	}
	else if(!arg)
		write(INPUTTXT("请说出暗号：","say $txt#")+"\n");
	return 0;
}
void close(object room)
{
	message("vision","只见小木门乒地关上了。\n", room);
	room->delete("exits/down");
}	
