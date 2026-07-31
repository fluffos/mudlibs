// by dubei

#include <ansi.h>
#include <room.h>

inherit ROOM;

string zhuo(object);
string mu(object);
string bi(object);
string tai(object);

void create()
{
    set("short", BLU "山洞"NOR);
    set("long", @LONG
这洞其实甚浅，行不到三丈，已抵尽头，洞中除了一张石桌、一张
石凳之外更无别物。洞角有一堆乱石高起，极似一个坟墓，洞壁上似乎
写得有字，只是尘封苔蔽，黑暗中瞧不清楚。
LONG
    );

    set("exits", ([
        "out":__DIR__"dongkou",
    ]));
    set("huoshi_count", 2);
    set("item_desc", ([
//        "huoshi" : "互击产生的小火星可以点燃枯树枝。\n",
        "zhuo" : (: zhuo :),
        "den" : "普通的石凳。\n",
        "mu" : (: mu :),
        "tai" : (: tai :),
        "bi" : (: bi :),
    ]));

    setup();
}

string zhuo(object me)
{
    me = this_player();
    me->set_temp("temp/looked_zhuo", 1);
    return  "普通的石桌，桌上放有一对火石。\n";
}

string tai(object me)
{
    object where = environment(me);

    if((int)where->query_temp("temp/light") < 100)
        return  "洞里面黑黝黝的，你什么也看不清楚。\n";

    if((int)me->query_skill("force", 1) < 100)
        return  "壁上满是青苔和灰尘。\n";

    if((int)where->query_temp("temp/qingtai") < 1)
        return  "壁上满是青苔和灰尘，青苔下面似乎刻着一些小字。\n";
       else
//       me->set_temp("temp/qingtai",1);
        return  "抹去青苔的壁上刻着一些小字。\n";
}

string bi(object me)
{
    object where = environment(me);

    if((int)where->query_temp("temp/light") < 100)
        return  "洞里面黑黝黝的，你什么也看不清楚。\n";

    if((int)me->query_skill("force", 1) < 100)
        return  "壁上满是青苔和灰尘。\n";

    if((int)where->query_temp("temp/qingtai") < 1)
        return  "壁上满是青苔和灰尘，青苔下面似乎刻着一些小字。\n";

    me->set_temp("temp/looked_bi", 1);

    return
    "抹去青苔的壁上现出三行字来，字迹笔划甚细，入石却是极深，显是用\n"
    "极锋利的兵刃划成。  看那三行字道：                            \n\n"
    "纵横江湖三十馀载，杀尽仇寇，败尽英雄，天下更无抗手，无可柰何，\n"
    "惟隐居深谷，以雕为友。呜呼，生平求一敌手而不可得，诚寂寥难堪也。\n\n"
    "                                                剑魔独孤求败  \n";
}
string mu(object me)
{
    object where = environment(me);

    if((int)where->query_temp("temp/light") < 100)
        return  "洞里面黑黝黝的，你什么也看不清楚。\n";

    if((int)me->query_temp("temp/looked_bi") < 1)
        return  "你终究看不出来这是谁的坟墓。\n";
    else
    {
        me->set_temp("temp/looked_mu", 1);
        me->delete_temp("temp/looked_bi");
        return
        "那个石堆的坟墓上也无其他标记，料是这位独孤求拜死後，是神雕衔石\n"
        "堆在他尸身之上。\n";
    }
}

void init()
{
    add_action("do_use", "use");
    add_action("do_ca", "ca");
    add_action("do_guibai", "guibai");
    add_action("do_move", "move");
    add_action("do_guibai", "kneel");
       add_action("do_na","na");
       add_action("do_zuan","zuan");
}

int do_use(string arg)
{
    object me=this_player(), ob;
    object where = environment(me);

    if((!arg) || (arg != "huoshi"))
        return notify_fail("你要使用什么？\n");
    if( !(ob=present("ku shuzhi", me)) )
        return notify_fail("你没有引火之物！\n");

    message_vision("$N点燃了枯树枝，周围马上亮了起来！\n", me);
    where->add_temp("temp/light", 100);
    destruct(ob);
    return 1;
}
int do_na(string arg)
{
      object me;
      me = this_player();

    if(!me->query_temp("temp/looked_zhuo"))
    return notify_fail("你想做什麽？\n");

     if((!arg) || (arg != "huoshi"))
     return notify_fail("你要拿什么？\n");
     
     if (query("huoshi_count") > 0) 
     {
         message_vision("$N从石桌上拿起一个火石。\n", me);
         add("huoshi_count", -1);
         new(__DIR__"obj/fire")->move(me);
         me->delete_temp("temp/looked_zhuo");
     }
     else
     message_vision("$N伸手摸了摸，什麽也没找到。\n", me);
     me->delete_temp("temp/looked_zhuo");
     
    
    return 1;
}
int do_ca(string arg)
{
    object me = this_player();
    object where = environment(me);

    if((!arg) || (arg != "qingtai"))
        return notify_fail("你要抹去什么？\n");

    if((int)where->query_temp("temp/light") < 100)
        return notify_fail("你摸了一手湿乎乎的青苔。\n");

    if( ((int)me->query_skill("force", 1)<100) ||
        ((int)me->query_skill("dodge", 1)<100) )
    {
        message_vision("$N用力一抹青苔，哪知手上打滑，一个趔趄差点摔倒在地！\n", me);
        return 0;
    }

    where->set_temp("temp/qingtai", 100);
    message_vision("$N抹去了壁上的青苔，露出了下面刻的小字。\n", me);

    return 1;
}

int do_guibai(string arg)
{
    object me = this_player();
    object where = environment(me);

    if((!arg) || (arg != "mu"))
        return notify_fail("不要随便下跪嘛！\n");

    if((int)me->query_temp("temp/looked_mu") < 1)
        return notify_fail("不要随便下跪嘛！\n");

    message_vision("$N出了一会神，不自禁的在石墓之前跪拜，拜了四拜。\n", me);
    write("你忽然发现山洞北面似乎有个出口，一块一人来高的石头似乎把出口封住了。\n");
    me->set_temp("temp/kneel", 1);
    me->delete_temp("temp/looked_mu");

    return 1;
}
int do_move(string arg)
{
     object me = this_player();

   if(!me->query_temp("temp/kneel"))
    return 0;

       if((!arg) || (arg != "stone"))
   return notify_fail("你要做什麽？\n");

    if((int)me->query_str()<30)
   return notify_fail("你用力推了推巨石，但如同蜻蜓撼树一样。\n");


    message_vision("$N力惯双壁，用力将巨石推开一条小缝。\n", me);
    me->delete_temp("temp/kneel");
    me->set_temp("make/xmove",1);
    return 1;
}
int do_zuan(string arg)
{
     object me = this_player();

   if(!me->query_temp("make/xmove"))
    return 0;

    if((!arg) || (arg != "shifeng"))
   return notify_fail("你要做什麽？\n");
 
    me->set_delete("make/xmove");
    me->move(__DIR__"donghou");
    message_vision("$N深吸口气，从石缝中钻了出来。\n", me);
 
  
    return 1;
}

int valid_leave(object me, string dir)
{
    if((me->query_temp("make/xmove")) && dir=="north")
    {
        me->move(__DIR__"donghou");
        return 1;
    }
	return ::valid_leave(me, dir);
}
