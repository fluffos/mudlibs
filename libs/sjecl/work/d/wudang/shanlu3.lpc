// xiaolu1.c 林间小径
#include <ansi.h>

inherit ROOM;
int do_jiao(string arg);

void create()
{
	set("short", YEL"灌木丛"NOR);
	set("long", @LONG
你走在一条偏僻的山路上，四周灌木丛丛，遍地奇花异草，其中一株长生
果树(guoshu)就为珍贵。这里人迹罕至，路径几不可寻，只有采药的人才敢进
入深山。
LONG
        );
	set("outdoors", "武当");

	set("exits", ([
		"west" : __DIR__"shanlu2",
	]));

	set("item_desc", ([
		"guoshu" : "这是株仙果树苗，因为长于凡间而失去灵气。枝叶萎靡，不能开花结果！\n"
	]));

	set("jiao_count", 3);
	set("guo_count", 1);
 
	setup();
}

void init()
{
	add_action("do_jiao", "jiao");
}

int do_jiao(string arg)
{
	object me;
	object obguo;
	me = this_player();

	if ( !arg || arg != "guoshu" )
		return notify_fail("你要浇什么?\n");

	if (! present("xiang cha", me))
		return notify_fail("你拿什么来浇?!\n");
     
	message_vision(HIG"$N细心地把茶杯里的女儿香浇在长生果树上。\n"NOR, me);

	if (present("xiang cha", me))
		destruct(present("xiang cha",me));

	add("jiao_count", -1);
	if (query("jiao_count") > 0) {
		message_vision(HIG"香茶被果树吸收，枝叶长得更翠绿了。\n"NOR, me);
		return 1;
	}

	obguo = unew(MEDICINE_D("rsg"));

	if(query("guo_count") >= 1 ){
		if( !clonep(obguo)){
			set("jiao_count", 3);
			message_vision(HIG"由于营养不良，长生果树只能开出一朵美丽的小花。\n"NOR, me);
			return 1;
		}
		if( clonep(obguo) && obguo->violate_unique()){
			set("jiao_count", 3);
			message_vision(HIG"由于营养不良，长生果树只能开出一朵美丽的小花。\n"NOR, me);
			destruct(obguo);
			return 1;
		}
		write(HIM"突然果树中间长出一个花蕾，随即开花，马上就结成一个令人唾咽欲滴的长生果!\n"NOR);
		message_vision("$N小心翼翼地摘下长生果，满脸高兴地揣入怀中。\n",me);
		obguo->move(me);
		set("jiao_count", 3);
		return 1;
	}
	else {
		set("jiao_count", 3);
		message_vision(HIG"由于营养不良，长生果树只能开出一朵美丽的小花。\n"NOR, me);
	}
	return 1;
}

int count = 20;
void reset()
{
	if (--count == 0) {
		count = 20; 
		set("guo_count", 1); 
		::reset();
	}
}

int clean_up()
{
	return 0;
}
