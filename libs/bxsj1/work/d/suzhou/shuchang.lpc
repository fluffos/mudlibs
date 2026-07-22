#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "书场");
	set("long",@long
这里是个热闹的书场，场子里坐满了来听书的闲人。场子前面的桌子后面
有一位说书先生，他看上去四五十岁，手中拿着一块响板，正在聚精会神地说
着评书--《杨家将》。场中的人们不时的发出惊叹和喝彩声，时不时将铜板抛
了上去。
long);
	set("item_desc", ([
		"door" : "这是一扇通往后堂的小木门。\n"
	]));
	set("objects",([
		__DIR__"npc/gongzige" : 1,
	]));
	set("exits",([
		"enter" : __DIR__"houtang",
		"south" : __DIR__"xidajie2",
	]));

	create_door("enter", "小门", "out", DOOR_CLOSED);
	set("incity",1);
	setup();
}
