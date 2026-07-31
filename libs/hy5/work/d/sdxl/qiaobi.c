// by dubei

#include <ansi.h>
#include <room.h>

inherit ROOM;

string shitai(object);

void create()
{
    set("short", BLU "峭壁"NOR);
    set("long", @LONG
那峭壁便如一座极大的屏风，冲天而起，峭壁中部离地约二十馀丈
处，生著一块三四丈见方的大石，便似一个平台，石上隐隐刻得有字。
走近峭壁，但见石壁草木不生，光秃秃的实无可容手足之处，不知当年
那人如何攀援上去刻下字来。
LONG
    );

    set("outdoors", "xiangyang");
    set("item_desc", ([
        "shitai" : (: shitai :),
        "zi" : HIW "剑  冢" NOR,
    ]));

    set("exits", ([
        "south" : __DIR__"donghou",
    ]));

    setup();
}

string shitai(object me)
{

    me->add_temp("temp/kan3", 1);

    if(me->query_temp("temp/kan3")<5)
    {
        return
"你瞧了半天，越看越是神往，心想他亦是人，怎能爬到这般的高处，想\n"
"来必定另有妙法，倘若真的凭藉武功硬爬上去，那直是匪夷所思了。\n";
    }

    me->set_temp("temp/pa", 1);
    me->delete_temp("temp/kan3");
    return
"你凝神瞧了一阵，突见峭壁上每隔数尺便生著一丛青苔，数十丛笔直排列\n"
"而上。你心念一动，纵身跃起，探手到最底一丛青苔中摸去，抓出一把黑\n"
"泥，果然是个小小洞穴，料来是独孤求败当年以利器所挖凿，年深日久，\n"
"洞中积泥，因此生了青苔。\n";

}

void init()
{
        add_action("do_climb", "climb");
//        add_action("do_pa", "pa");
}

int do_climb(string arg)
{
    object me = this_player();
    int dex = me->query("dex");
    int str = me->query("str");

    if((!arg) || (arg != "shitai"))
        return notify_fail("你要爬到哪里去？\n");

    if(me->query_temp("temp/pa")<1)
        return notify_fail("这般的高处，你若真能硬爬上去，那直是匪夷所思了。\n");

    message_vision(GRN"$N略一提气，借助石壁上的洞穴腾身往洞平台上爬去。\n", me);

    if( (dex < 27) && (str < 27) && (random(2)) )
    {
        message_vision(HIR"$N爬了一会，便手足乏力，只得翻身跃下。\n"NOR, me);
        return 0;
    }

    if( (dex > 27) && (str < 27) && (random(3)) )
    {
        message_vision(HIY"$N身形上扬，眼看快到尽头，突然手一松，掉了下来，看来臂力还是不够。\n"NOR, me);
	return 0;
    }

    if ( (dex < 27) && (str > 27) && (random(2)) )
    {
        message_vision(HIY"$N身形上扬，眼看快到尽头，突然脚下一软，骨碌碌滚下山，受了一点伤。\n", me);
        me->receive_wound("qi", 30, me);
        me->receive_damage("qi", 40, me);
        return 0;
    }

    message_vision(GRN"$N身形上扬，转眼就到了峭壁的尽头，纵身一跃，已到了平台边沿。\n", me);
    me->move(__DIR__"pingtai");
    message("vision", me->name() + "从峭壁下爬了上来。\n", environment(me), ({me}) );
    return 1;
}
