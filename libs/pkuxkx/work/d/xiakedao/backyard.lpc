// backyard
// by aiai
// Modified by iszt@pkuxkx, 2007-04-02

#include <room.h>

inherit ROOM;

void create()
{
	set("short", "庭院");
	set("long", @LONG
松软的黄土铺满庭院，显然是用来练习武功的。院中零星地立着几根一尺粗
细的木桩，其中一根被斜削为两截，切口儿古怪。又一根被一剑洞穿，一柄青穗
剑尚未拔出。
LONG);
	set("exits", ([ /* sizeof() == 4 */
		"west" : __DIR__"fanting",
		"east" : __DIR__"chaifang",
		"south":__DIR__"guanyuege",
		"north":__DIR__"dating",
	]));
	set("outdoors","xiakedao");
	set("item_desc", ([
		"切口儿": "这切口儿一看就是高手所削．．．\n",
		"青穗剑": "这青穗剑已经锈死在木桩里，再也拔不出了．．\n",
	]) );
	create_door("north", "黄金门", "south", DOOR_CLOSED);
	setup();
}
void init()
{
	add_action("do_pull","pull");
}
int do_pull(string arg)
{
	object blood;
	if(!arg || arg != "青穗剑") return 0;
	write("你用尽全身力量，用力一拉！！\n");
	write("你的内力不够．．．累得狂喷鲜血．．．\n");
	this_player()->receive_damage("qi",50);
	blood= new(__DIR__"obj/blood");
	blood->move(this_object());
	return 1;
}