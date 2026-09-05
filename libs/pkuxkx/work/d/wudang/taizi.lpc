// taizi.c 太子岩
// by Arnzh

inherit ROOM;

void create()
{
	set("short", "太子岩");
	set("long", 
"这是一块广场般大小的大石，上面又平又光，显然不是人\n"
"力搬来，也不是人力制成。路边有一块大石(stone)，石后面\n"
"仿佛是一个山洞，里面黑乎乎的不知有什么东西。\n"

	);
        set("outdoors", "wudang");
	set("item_desc",([
		"stone" : "一块不小的石头，好象可以(push)推开。\n",
		] ));
	set("exits", ([
		"southdown" : __DIR__"wulao",
		"eastup"  : __DIR__"panshen",
		]));

	setup();
}
void init()
{add_action("do_push","push");}

int do_push(string arg)
{
	object me=this_player();
	if(!arg || arg!="stone")
	return notify_fail("什么？\n");
	if((int)me->query("neili")>200)
     {	me->add("neili",-200);
	message_vision("$N气运双臂，轻哼一声，将石头推倒了一边。\n",me);
	set("exits/enter", __DIR__"yandong");
	return 1;
     }
	else return notify_fail("你用尽吃奶的力气一推，而石头仿佛生了根一般，纹丝不动。\n");
}
