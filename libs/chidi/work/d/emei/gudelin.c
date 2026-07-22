// Room: /d/emei/gudelin.c 峨嵋派 古德林


#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", "古德林");
	set("long", @LONG
这里楠木参天，林荫夹道，株株秀挺俊拔，枝叶分披上捧，如两手拥佛，
传为古时一高僧按《法华经》口诵一字，植树一株，共植六万九千七百七十
七株，时称古德林。要是不熟悉地形很容易迷路。林中有一片空地，几只楠
木桩(muzhuang)排成梅花模样。
LONG
	);

	set("exits", ([
		"east" : __DIR__"bailongdong",
                "west" : __DIR__"gudelin2"
	]));

          set("objects", ([
              "/d/shaolin/npc/mu-ren" : 2,
        ]));
	set("outdoors", "emei");

	setup();
}

void init()
{
        add_action("do_jump", "jump");
}

int do_jump(string arg)
{

        mapping myfam;
        object me = this_player();
	int dex= this_player()->query_dex();
	object ob;

    if (arg != "muzhuang")  return command("jump "+arg);

    if (me->is_busy())
        return notify_fail("你现在正忙着呢。\n");

    if ( me->query("qi") <  15 )
         return notify_fail("你的体力太差了，需要休息一下了。\n");

         message_vision("$N跳上了楠木桩。\n", me);

    me->add("qi", -10+random(5));
    if ((!(myfam = me->query("family")) || myfam["family_name"] != "峨嵋派") )
        {
        message_vision("$N绕着木桩走了一圈，结果累的气喘吁吁。\n",me);
        return 1;
        }        
    if ((dex <= 15)&&(random(3)<2) || (dex > 15)&&(dex <= 18)&&random(2) )
     {
        message_vision("$N摇摇晃晃的站在木桩上，结果一个不稳，＂啪＂地一声摔了下来，结结实实摔在了地上。\n",me);
        me->receive_damage("qi", 20, me);
        me->receive_wound("qi", 10, me);
        return 1;
     }

    else if ( dex <= 26) 
     {
   
        message_vision("$N身行飘逸的在木桩走了一圈。\n",me);  
        me->improve_skill("dodge", random(me->query_int()));
        write(HIR"你似乎对轻功有了一些新的领悟，你的基本轻功进步了。\n"NOR);
        return 1;
      }
    else 
    {
    	message_vision("$N绕着木桩走了一圈。\n",me); 
        write(HIR"结果你感觉一无所获。\n"NOR);
        return 1;
    }
    
    return 1;
}
