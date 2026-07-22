// Room: /u/jpei/thd/shore.c
// 加入转换师傅的代码 Modified by Numa
// YUJ 2001-10-29

#include <ansi.h>
inherit ROOM;
int prevent_get();
void create()
{
	set("short", "岸边");
	set("long", @LONG
你疑惑地看着四周，这里就是桃花岛么？四周除了凌乱的礁石外，什么都
没有。往北面看，一座小山耸立在那里,可以通过攀爬岩壁到达山顶。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
		"northup" : __DIR__"hill",
	]) );
	set("outdoors","桃花岛");

	setup();
}

void init()
{
	object me = this_player();

	if (me->query("family/family_name")=="桃花岛")
	{
		if ((int)me->query("family/generation")==2)
		{
			if ((int)me->query_skill("bihai-chaosheng",1) < 130 && me->query_skill("bihai-chaosheng",1) >= 80)
			{
				me->set("family/master_id","lu chengfeng");
				me->set("family/master_name","陆乘风");
				me->set("family/generation",3);
				me->set("title","桃花岛第三代弟子");
				write( HIY "由于您的碧海潮生等级小于一百三十级，系统已将您转换为桃花岛第三代弟子。\n" NOR);
				return;
			}
			else if ((int)me->query_skill("bihai-chaosheng",1) < 80)
			{
				me->set("family/master_id","lu guanying");
				me->set("family/master_name","陆冠英");
				me->set("family/generation",4);
				me->set("title","桃花岛第四代弟子");
				write( HIY "由于您的碧海潮生等级小于八十级，系统已将您转换为桃花岛第四代弟子。\n" NOR);
				return;
			}
		}
		else if ((int)me->query("family/generation")==3)
		{
			if ((int)me->query_skill("bihai-chaosheng",1) < 80)
			{
				me->set("family/master_id","lu guanying");
				me->set("family/master_name","陆冠英");
				me->set("family/generation",4);
				me->set("title","桃花岛第四代弟子");
				write( HIY "由于您的碧海潮生等级小于八十级，系统已将您转换为桃花岛第四代弟子。\n" NOR);
				return;
			}
		}
	}
}
