//山洞

#include "ansi.h"
inherit ROOM;
int storm(object me);

void create()
{
	set("short", "雪洞");
	set("long", @LONG
	这是雪山中的一个洞,洞内风雪虽然小了点,但是奇寒无比,看来没
有什么生命可以在这里生存。洞的西南是一块巨大的冰壁(bingbi)。
LONG
	);

	set("exits", ([
                "south" : __DIR__"hole9",
                "north":__DIR__"hole"+(random(10)+1),
                "west":__DIR__"hole"+(random(10)+1),
                "northeast":__DIR__"hole"+(random(10)+1),
                  ]));
        set("item_desc",([
             "bingbi":"从壁后隐隐看到有些透明，跟别的地方不一样。\n"
             ]) );
	setup();
}
void init()
{
	int i, flag = 0;
	object ob, *inv;
	if( interactive( ob = this_player()))
	{
        	storm(ob);
        	if(!mapp(query("luding_maze")))
        	set("luding_maze",
        	(["period" : 10,
        	  "delay" : -20,
        	  "max_amount" : 3,
        	  "odds" : 60,])
        	);

        	if(!query("luding_npc"))
        	set("luding_npc", ({__DIR__"npc/whitebear", __DIR__"npc/wolf"}));

        	//产生新的怪物的代码
        	inv = all_inventory(this_object());
                for(i = 0; i < sizeof(inv); i++)
                {
                	if(inv[i]->is_character() && !interactive(inv[i]))
                	flag = 1;
                }
        	if(!flag)
        	NPCGEN_D->npc_gen(query("luding_maze"), query("luding_npc"), this_object());
	}
       add_action("do_break", "break");
       add_action("do_break", "pi");
}
int do_break(string arg)
{
      int n;
      object ob,axe;
      ob=this_player();
     if(arg != "bingbi")
      {
       write("不要随便砸东西，万一砸到人怎么办，就是砸不到人\n"+
"砸到花花草草的也不好嘛！\n");
       return 1;
      }

      if( !objectp(axe = ob->query_temp("weapon")) || axe->query("id")!="snow axe" )
      if( !objectp(axe = ob->query_temp("secondary_weapon")) || axe->query("id")!="snow axe" )
     {
      write("没有合适的工具怎么干活？\n");
      return 1;
     }

    message_vision(YEL"$N走到冰壁前，举起破冰斧，运足内力砸了过去！\n"NOR,ob);
    n=(int)ob->query("neili");
    if (n >= 1000)
	{
        message_vision(
        "$N只听一声轰响，冰壁被你的神力砸了个大洞！破冰斧也被你给砸坏了。\n", this_player());
        set("exits/southwest", __DIR__"bearhole");
        this_player()->set("neili", n - 1000);
        //dest axe
        axe->uneuip();
        destruct(axe);
        remove_call_out("close");
        call_out("close", 30, this_object());
     }
     else
	{
		message_vision(
		RED"结果只听一声闷哼，$N被冰壁的反弹力震得眼前一黑....\n"NOR, this_player());
		this_player()->set("neili",0);
		this_player()->unconcious();
    }

    return 1;
}
void close(object room)
{
    message("vision",HIR"洞顶忽然掉下来一块大冰块，将洞口封了个严严实实。\n"NOR, room);
    room->delete("exits/southwest");
}
int storm(object me)
{
	int i, flag;
	object *inv;
        int qi = me->query("qi");

        inv = all_inventory(me);
        for(i = 0; i < sizeof(inv); i++)
        {
        	if(inv[i]->query("id") == "pi qiu" && inv[i]->query("equipped"))
        	flag = 1;
        }

	if( environment(me) == this_object())
	{
                 if( !flag )
                 {
                         tell_object(me, HIR"\n一股刺骨的寒风吹过，你只觉得浑身的血液都快被冻住了！\n"NOR);
                         write("看来不穿一件保暖的外衣，一定会被冻死的！\n");

                         me->start_busy(1);
                         me->receive_damage("qi", 10 + random(50), "冻");
                         me->receive_wound("qi", 10 + random(20), "冻");
         		if( environment(me) == this_object())
         		call_out("storm", 5 + random(5) , me);
                 }
                 else
                 tell_object(me, HIC"\n一股刺骨的寒风吹过，你将皮裘裹得更加严实了！\n"NOR);
	}
        return 1;
}
int valid_leave(object me, string dir)
{
	int i;
	object *inv;
	inv = all_inventory(this_object());
	for(i = 0; i < sizeof(inv); i++)
	{
		if(inv[i]->query("luding_monster"))//或者其他什么标记
		return notify_fail("你看见形势不妙转身想逃，却被"+ inv[i]->name() + "飞身拦住。\n");
	}
       return ::valid_leave(me, dir);
}