// Room: /city/damen.c
// YZC 1998/3/22
// --by kuer--
inherit ROOM;

string look_bian();

void create()
{
	set("short", "正气山庄的大门");
	set("long", @LONG
这是正气山庄的大门，大门的正上方悬挂着一块巨匾(bian)，上面刻着「正
气山庄」四个楷书大字，门口站着几个家丁，神态甚为威武雄壮，你不由想到奴
仆尚且如此，主人可想而知了。
LONG);

	set("exits", ([
		"south" : __DIR__"shanzhuang",
		"north" : __DIR__"dongmen",
	]));

	set("item_desc",([
		"bian" : (: look_bian :),
	]));

	set("objects", ([
		__DIR__"npc/jiading1" : 4,
	]));

	setup();
}

string look_bian()
{
	return "\n                            正气山庄\n";
}