//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "塘沽口");
	set("long", @LONG
这里就是大海之滨，浪花拍打着礁石，发出阵阵响声，海面上一群群
海鸥『欧欧..』地叫着，不时有鱼儿跃出海面，溅起层层的浪花。边上有
艘大船(chuan)，船上坐着几个渔夫打扮的人， 乘船可渡过大海到达海的
另一端。西面过天津城就是北京了，东面是一望无际的大海。
LONG );
	set("exits", ([
		"west" : __DIR__"road10",
	]));
	set("item_desc", ([
		"chuan" : "一艘大帆船，造得很结实，看来可以出远海的。\n",
	]));
	set("objects", ([
		__DIR__"npc/flowerg":2,
		"/d/shenlong/npc/chuanfu" :1,
	]));

	set("outdoors", "city2");
	setup();
	replace_program(ROOM);
}

