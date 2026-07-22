 // /u/beyond/mr/shuxie.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIW"听香水榭"NOR);
         set("long",@long
这间房舍小巧玲珑, 颇为精雅。小舍匾额上写着"听香水榭"四个大字, 笔
致颇为潇洒。东边是一条小路，不知是通往哪里的。再往前走，就到了“燕子
坞”。南边是水榭的后院。
long);
	set("exits",([
		"north" : __DIR__"anbian2",
		"west" : __DIR__"anbian4",
		"south" : __DIR__"houyuan1",
	]));
	set("objects",([
		__DIR__"../npc/azhu" : 1,
	]));
	setup(); 
}

void init()
{
        add_action("do_zuan", "zuan");        
}

int do_zuan(string arg)
{
	object me = this_player();
	mapping myfam;
	
	myfam = (mapping)me->query("family");
	
	if (!arg || arg != "didao" || me->is_busy())
		return notify_fail("你要往哪里钻？\n");       

        if (myfam && myfam["family_name"] != "姑苏慕容")
		return 0;
            
	message_vision("$N一转身，忽然一下子钻到地下不见了。\n",me);
	me->move("/d/mr/didao");
	message("vision",me->name() + "从水池边跃了上来。\n",environment(me), ({me}) );
        return 1;
}
