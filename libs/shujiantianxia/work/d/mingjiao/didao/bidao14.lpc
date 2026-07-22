// /d/mingjiao/bidao14.c
// Jay 4/3/97 -qingyun
// Modify By River@SJ 99.06
#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{ 
	set("short","秘室");
	set("long", @LONG
这是一个较大的秘室。是明教历代教主练功的地方，秘室内用器样样具全，
东边有一张大石床，床上躺着一具已干枯的的男性骸骨(haigu），只有毛发和
衣服尚没腐烂，床延伏着一具较为瘦小的骸骨(haigu），衣着为女性衣服，骸
骨上插着一把短剑，想是当年自尽而忙。秘室四周皆为石壁(wall)，没有任何
的出路通何外面。
LONG);
	set("objects",([
		__DIR__"../npc/haigu1"  : 1,
		__DIR__"../npc/haigu2"  : 1,
	]));
	set("no_save", 1);
	set("item_desc", ([
		"wall" : "石壁上布满灰尘，但仔细一看，发觉有几处脱落。\n"
	]));                         
	setup();
}

void init()
{
	add_action("do_gua","gua");
	add_action("do_push","push");
}

void check_trigger()
{
	object me;
	me=this_player();
	if( (int)query("push_trigger")==1){
		message("vision", "石门慢慢的应声而开了。\n", this_object() );
		set("exits/east", __DIR__"bidao15");
		delete("push_trigger");
		me->delete_temp("marks/削1");
		remove_call_out("close_passage");
		call_out("close_passage", 10);
	}
}

void close_passage()
{
	if( !query("exits/east") ) return;
	message("vision", "石门“咔咔”几声又自动合上了。\n", this_object() );
	delete("exits/east");
}

int do_gua(string arg)
{
	object me;
	object weapon;
	me = this_player();
	if (!arg || arg!="wall") return 0;
	if (!objectp(weapon = me->query_temp("weapon")))
		return notify_fail("你要用什么兵器？\n");
	if((string)weapon->query("skill_type")=="axe" ) {
		write("你用大斧在西北角的“无妄”上，用大斧将石的沙土刮去。\n\n"+
			"    只见一道由天然生成的大岩石做成的石门，岩底下装了一个\n"+
			"大铁球作成的门枢。想当年明教建造这地道之时，动用了无数人\n"+
			"力穷年累月，不知花了多少功夫，多少心血。\n");
		me->set_temp("marks/削1", 1);    
		return 1;
	}
}

int do_push(string arg)
{
	object me;
	me=this_player();
	if (! arg || arg !="men") return 0;
	if (me->query_skill("qiankun-danuoyi",1) < 50)
		return notify_fail("你大口吸了口气，运起内力向石门推去，但是石门一动不动。\n");
	if ( arg=="men" 
	 && me->query_skill("qiankun-danuoyi",1) >= 50
	 && me->query_temp("marks/削1")){
		message_vision(YEL"\n$N默念乾坤大挪移习法，一个挪移乾坤，石门发出“吱吱”的声音，\n"
				"一扇用大岩石做成的大石门应声而开！！！\n\n"NOR,me);
		add("push_trigger", 1);
		me->start_busy(2);
		check_trigger();
		return 1;
	}
	else {
		write("你要干什么？\n");
		return 1;
	}
}
