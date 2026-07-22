#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short",HIG"心禅坪"NOR);
	set("long", @LONG
这里是一片林间空地，三面环绕着千年古衫，生长的郁郁葱葱好不茂盛。
地面是一块正方大青石，与寺内石径颇为不类，疑是寺外移来。不知前辈僧
人劳心劳力，运来此物何用。石坪清扫的颇为洁净，只是在林边有一块小尖
石，颇为醒目。北面有一座石坊，上书心禅堂三个大字。一位老僧斜倚着石
坊，似乎半梦半醒。
LONG
     );
	set("exits", ([
		"north" : __DIR__"xctang",
		"west"  : "/d/shaolin/fatang",
	]));
	set("outdoors", "少林");
	set("objects",([
		__DIR__"npc/huu" : 1,
	]));
	setup();
}
void init()
{
	add_action("do_huadi", "huadi");
}
int do_huadi()
{
	object me=this_player();

	if (((int)me->query("max_neili",1)>1000)&&((int)me->query("neili",1)>500)) {
		message("vision","\n只见 " + me->query("name")+"弯腰在路旁捡起一块尖石,\n"
		" 在青石地上划了起来,不多时便画成了一个纵横十九道的大围棋盘,但见\n"
		"横平竖直,端的是神乎其技。\n",
			environment(me), ({me}) );
	write("你在青石地上划出了一个大棋盘\n");
	me->receive_damage("neili",500);
	me->set_temp("huadi",1);
	}
	else {
		message("vision", me->query("name")+ "趴在地上划的手都酸了,但石质坚硬,连一道纹都没有。\n",
			environment(me), ({me}) );
		write("你划了半天终因内力不够，无法留下任何印记。\n");
	}
	return 1;
}

int valid_leave(object me, string dir)
{
	if (( me->query("family/family_name") != "少林派" || (me->query("family/generation") >35 && me->query("pass_xin")==0))
	&& dir == "north"
	&& !wizardp(me) )
		return notify_fail("职事僧伸手栏住你，心禅堂不可妄入。\n");
	return ::valid_leave(me, dir);
}
