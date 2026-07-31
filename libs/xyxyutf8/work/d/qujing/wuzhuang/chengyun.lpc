//Cracked by Roath
inherit ROOM;

void create ()
{
	set ("short", "乘云阁");
	set ("long", @LONG

乘云阁居观中的最高处，阁上画栋雕梁，丹楹刻柱，显是下了很
大的功夫、周围朱栏曲槛，凭栏四望，远处景致俱在眼前。山下
村房楼舍，山上奇石怪松历历在目。
LONG);

	set("exits", 
	([ //sizeof() == 4
		"down": __DIR__"yanzhen",
	]));
	
	set("objects", 
	([ //sizeof() == 1
		//__DIR__"npc/qingfeng" : 1,
		__DIR__"npc/zhenyuan" : 1,
	]));


	set("outdoors", "wuzhuang");

	setup();
}

void init()
{
   add_action("do_hear","hear");
}

int do_hear()
{
	object me=this_player();
  	if( !query("jiangjing") || (string)me->query("family/family_name")!="五庄观" )
     		return 0;
	if(me->is_busy())
      		return notify_fail("你正忙着呢。\n");
      	if( me->query("kee")<30 || me->query("sen")<30 )
      		return notify_fail("你现在太累了。\n");
	if(me->query("faith")<10 )
		return notify_fail("你的师门贡献不够。\n");
	tell_object(me,"你听着听着似乎若有所悟。\n");
  	me->start_busy(5);
   	me->improve_skill("zhenyuan-force",1+random(me->query_spi()+me->query_int())/2);
   	me->improve_skill("taiyi",1+random(me->query_spi()+me->query_int())/2);
	me->add("faith",-10);
	me->receive_damage("kee",20);
   	me->receive_damage("sen",20);
  	return 1;
}
