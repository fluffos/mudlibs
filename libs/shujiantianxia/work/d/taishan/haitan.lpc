//Yanqi 08/11/2k

#include <ansi.h>
inherit ROOM;

string* escapename = ({
"/d/city/xidajie1",	"/d/suzhou/yzyunhe",	"/d/city/zahuopu",
"/d/city/xjs",		"/d/city/dhq",		"/d/city/lxs",
"/d/city/beidajie1",	"/d/city/qianzhuang",	"/d/city/eroad2",
"/d/city/guangchangnan","/d/city/guangchang",	"/d/city/guangchangbei",
"/d/city/guangchangxi",	"/d/city/jiangbei",	"/d/city/guangchangdong",
"/d/city/ximen",	"/d/city/chemahang",	"/d/city/pinqiting",
"/d/city/jiashan",	"/d/city/damingsi",	"/d/city/shangang"
});

void create()
{
	set("short", "海滩");
	set("long", @LONG
这里是东海之滨的一个小海滩。放眼望去，一片无际的的茫茫大海，远处
海天一线，你隐隐看到几只海鸥在海上飞翔。
LONG
);

	set("exits", ([
		"west" : __DIR__"daizong",
	]));

	set("outdoors", "泰山");
	setup();
}

void init()
{
	object ob,me,name1;
	string where;
        
	me=this_player();
	if( ! (present("qiang fei", environment(me)) ) 
	&& me->query_temp("newbiejob2/start") 
	&& ! (me->query_temp("newbiejob2/middle"))) {
		message_vision(HIM "不大功夫，一条小舢板从远处的海面开了过来，一个艄公从里面走了出来。\n"NOR,me);
		if (random(50) > 1) {
			message_vision(HIM "艄公从船舱里面取出一包盐巴，正要递给$N。\n" NOR,me);
			ob=new("/d/sld/npc/qiangfei");
			where = escapename[random(sizeof(escapename))];
			name1 = me->query("id");
			ob->set_temp("name1",name1);
			new("/d/sld/obj/yanba")->move(ob);
			ob->move(where);
			me->set_temp("newbiejob2/middle", 1);
			message_vision(HIW "突然窜出一个抢匪，一把从艄公手里抢过盐巴，向扬州城的"HIR+where->query("short")+HIW"方向逃去！\n"NOR,me); 
		}
		else {
			message_vision(HIM "艄公从船舱里面取出一包盐巴，递给了$N。\n" NOR,me);
			new("/d/sld/obj/yanba")->move(me);
			me->set_temp("newbiejob2/middle",1);
			me->set_temp("newbiejob2/over",1);
			message_vision(HIM "$N接过盐巴，赶紧揣在了怀里。\n"NOR , me);
		}
	}
}
