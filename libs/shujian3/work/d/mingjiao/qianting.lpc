// qianting.c  总坛前厅
// Modify By River@SJ 99.06
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIY"总坛前厅"NOR);
	set("long",@LONG
这里是明教总坛的前厅，虽谓之为前厅，但极似大殿。厅前有两条大石狮，
大石狮之间是十余级的斜斜而上的石阶，石阶被一大岩石做成的石碑中间隔开，
石碑平行于石阶镶于地上。石碑上雕着一飞腾而上的火焰，极是雄伟壮观，石
碑中有一些用小楷雕刻而成的文字，记载着明教上千年的历史，还有历代明教
教主的名字。整个大厅由几条巨木支撑而起，巨上雕刻着巨龙含着火焰飞腾之
像。由此而上就是光明顶了。
LONG);
	set("exits",([
		"southdown" : __DIR__"ljroad3",
		"north" : __DIR__"tingtang",
	]));
	set("objects",([
		__DIR__"npc/m-dizi" : 2,
		CLASS_D("mingjiao") + "/yin2" : 1,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	if ( me->query("id") == "jiao zhong" &&  dir == "southdown" ) return 0;
	if ( me->query("id")=="leng qian" && dir =="southdown") return 0;
	if ( me->query_condition("mj_shouwei") && dir =="southdown")
		return notify_fail("你还在守卫，不能离开。\n");
	if ( me->query_condition("mj_shouwei") && dir =="north")
		return notify_fail("你还在守卫，不能离开。\n");
	me->delete_temp("warned");
	return ::valid_leave(me, dir);
}
