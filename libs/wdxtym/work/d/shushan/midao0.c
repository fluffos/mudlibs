//shushan by yushu 2000.11
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","蜀山御天宫");
  set ("long", @LONG

蜀山御天宫是蜀山剑派开山祖师静虚老祖修炼的地方,
里是蜀山派最秘密地方，一般蜀山派弟子，没有很好练功
资质是不知道这里的,而且蜀山剑圣教徒地极为严格。
老祖身旁有一个纯金打造的金盒子(BOX)。
LONG);

  set("exits", ([
   "west" : __DIR__"sleeproom",
   "south" : __DIR__"midao",
  ]));
  set("objects", ([ 
      CLASS_D("shushan/laozu") : 1,       
  ]));
set("item_desc", ([
"BOX" : HIY"\t\看来这盒子里面肯定有什么宝贝,不过你最好不要随便乱打开(dakai),看起来老祖非常宝贵里面的东西。\n"NOR
]) );
  setup();
}

void init()
{
	add_action("do_dakai", "dakai");
}

int do_dakai(string arg)
{
	object me,obj,killer;
	me = this_player();
	if( !arg && arg!="box" && arg!="盒子")
		return notify_fail("你要打开什么? \n");
	if ( query("havezhu") )  {
	message_vision("$N从金盒子里拿出来一颗水灵珠。\n",this_player() );
	obj=new("/d/shushan/zhenyaota/obj/shuizhu");
	obj->move(me);
	set("havezhu", 0);
	}
	if(killer=present("master jingxu", environment(me)))
	{
       message_vision("\n静虚老祖对$N喝道：敢动我的东西！我看你是活的不耐烦了!\n", me);
	 killer->kill_ob(me);
	}
	me->start_busy(15);
	return 1;
}

void reset()
{
	::reset();
	set("havezhu", 1);
}