#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{ 
         set("short",CYN"断崖坪"NOR);
       set("long", @LONG
出得屋来，对面便是危崖一片。左面是一座孤峰刺天，右面是绝壑无地。
只中央一片平地。对崖看去去险峻已极，难以攀援。且壁间遍生青苔，其滑如
油，竟似无路可上。
LONG
     );
        set("exits", ([
              "south"  : __DIR__"xctang",
        ]));
       set("coor/x",60);
  set("coor/y",430);
   set("coor/z",130);
   setup();
}

void init()
{
        add_action("do_pa", ({ "climb", "pa" }));
        add_action("do_da", ({ "da", "gou" }));
        add_action("do_shuai", ({ "shuai" }));
} 

int do_da(string arg)
{
	object me=this_player();

	if( !present("nao gou",me) )
		return 0;
	if( arg!="naogou" && arg!="gou" && arg!="nao gou" )
		return notify_fail("你要搭什么？\n");
	message_vision("$N把手中的挠钩搭住了一块突出的岩石。\n",me);
	me->set_temp("duanya/gou",1);
	return 1;
}

int do_shuai(string arg)
{
	object me=this_player();

	if( !present("tao suo",me) )
		return 0;
	if( arg!="taosuo" && arg!="suo" && arg!="tao suo" )
		return notify_fail("你要甩什么？\n");
	message_vision("$N用力把手中的绳子甩上去，缠住了一棵小松树。\n",me);
	me->set_temp("duanya/suo",1);
	return 1;
}

int do_pa(string arg)
{
       object me;
       me = this_player(); 

       if ( !arg ) return 0;
       if (arg != "ya" && arg!="up") 
          return notify_fail("你要往那里爬？\n");
	   if(!me->query_temp("duanya/gou"))
		   return notify_fail("你发现岩石光滑，根本爬不上去，看来要借助挠钩之类的工具才行。\n");
	   if(!me->query_temp("duanya/suo"))
		   return notify_fail("你发现岩石太高，根本爬不上去，看来要借助套索之类的工具才行。\n");

       if (!living(me)) return 0;
       if ((int)me->query_encumbrance() * 100 / (int)me->query_max_encumbrance() >= 20
		   || me->query("wxz/quest")<4 
		   || me->query("family/family_name")!="少林派" ) {
                message_vision("$N气喘嘘嘘，感到无法爬上去，摔了下来！\n", me);
                me->unconcious();
                return 1;
        } 

        message_vision("$N借助手中的挠钩套索，施展轻功爬了上去。\n", me);
        me->move(__DIR__"yading");
        tell_room(environment(me), me->name() + "从下面爬了上来。\n", ({ me }));
		me->delete_temp("duanya");
        return 1;
}
