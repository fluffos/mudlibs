// Room: /d/yandang/luoyan15.c

inherit ROOM;

void create()
{
	set("short", "静室");
	set("long", @LONG
这是庄主日常打坐修炼的地方,室中空空如也,仅在室顶上阴刻了一
头大雁,翎羽生姿,静室正中的石地上,微微下凹,是长年类月炼功所形成
的,室中十分干净,一尘不染.
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"luoyan13",
]));
	set("no_clean_up", 0);
	//set("no_fight", 1);
	//set("no_magic", 1);

	setup();
}
void init()
{
	if(interactive(this_player()))
	{
		remove_call_out("fastleave");
		call_out("fastleave",random(10)+10,this_player());
	}
}

int fastleave(object me)
{
	object leaf;
	if(me)
	if(environment(me) == this_object())
	{
		tell_object(me,"你看着室顶的大雁,眼中一阵迷糊,猛的醒过来,发现.....\n");
		me->move("/d/yandang/shanxia.c");	
	}
}
