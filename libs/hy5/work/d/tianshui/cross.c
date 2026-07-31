// Room: /d/tianshui/cross.c

#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "小镇广场");
	set("long", @LONG
这里是小镇的正中央，一个较宽阔的广场，用青石铺着地面。
人来人往，非常热闹。一对父女俩正在这里卖艺，两个石柱相隔
几丈，中间一根细麻绳(rope)凌空相连，卖艺小女孩一纵身跃上
麻绳，轻盈地在绳子上来回走动，围观的人们发出一阵阵的叫好
声。东南方向有一颗大柏树，据说已经已经生长了两百多年，正
是这个小镇历史的见证。
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"wroad1",
  "north" : __DIR__"nroad1",
  "south" : __DIR__"sroad1",
  "east" : __DIR__"eroad1",
]));

	set("item_desc",([
	"rope" : "你也可以上去走走(zou)试试。\n",
	"麻绳" : "你也可以上去走走(zou)试试。\n",
]));

	set("objects",([
	__DIR__"npc/yiren" : 1,
	__DIR__"npc/yi_girl" : 1,
	__DIR__"npc/cleaner" : 1,
]));
	set("outdoors","tianshui");
	setup();
}

void init()
{
	add_action("do_zou",({ "zou","jump"}));
}

int do_zou(string arg)
{
	object me,m_obj;
	int level;
	me = this_player();
	if(!arg) return 0;
	if( arg != "麻绳" && arg != "rope" && arg != "绳子")
	{
		write("你要走什么？\n");
		return 1;
	}
	if(me->is_busy())
		return notify_fail("你正在忙！");
	if( me->query_temp("on_rided") )
	{
		write("骑马走绳！！？？\n");
		return 1;
	}
	if(me->query("qi") < 20) {
		message_vision("$N晃晃悠悠的踩上绳子，结果“扑通”一下掉了下来，观众们爆发出一阵大笑。\n",me);
		me->unconcious();
		return 1;
	}
	me->receive_damage("qi",20);
	me->start_busy(1);
	if( !me->query_skill("dodge", 1) )
	me->set_skill("dodge", 0);
	level = me->query_skill("dodge",1);

	if( level < 20) {
		if(random(10) < 4){
		message_vision("$N小心地踩上绳子，慢慢的走着，一个没注意掉了下来，观众里一阵“嘘...”声。\n",me);
		return 1;
		}
		me->improve_skill("dodge",(int)me->query("int")/6+level/2);
		message_vision("$N踩上绳子，小心地走了一趟，由另一端跳了下来。\n",me);
		message_vision("观众里响起几声叫好，几枚铜钱向场子里扔来。\n",me);
		m_obj = new(COIN_OB);
		m_obj->set_amount(10);
		m_obj->move(this_object());
		return 1;
	}

	if( level < 50) {
		if(random(10) < 3){
		message_vision("$N一纵身跳上石柱，沿着绳子走了过去，一阵小风吹过$N掉了下来，观众里一阵“嘘...”声。\n",me);
		return 1;
		}
		me->improve_skill("dodge",(int)me->query("int")/6+level/2);
		message_vision("$N一纵身跳上石柱，沿着绳子轻松地走了一趟，由另一端跳了下来。\n",me);
		message_vision("观众里响起一阵叫好，钱如雨点般向场子里扔来。\n",me);
		m_obj = new(COIN_OB);
		m_obj->set_amount(20);
		m_obj->move(this_object());
		return 1;
	}

	message_vision(HIC "$N一个妙曼的姿势纵上石柱，轻盈地在绳子上走了一趟。\n" NOR,me);
	message_vision(HIC "观众们一起向$N鼓掌喝彩！！。\n" NOR,me);
	me->receive_damage("qi",50);
	return 1;
}