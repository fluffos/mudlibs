// 密林
// edit: by zine Aug 21 2010

inherit __DIR__"skfroom1";
#include <ansi.h>
void create()
{
	set("short", "密林边缘");
	set("long", @LONG
这里已经是密林的边缘，南边是一片草地。
LONG
	);
	set("exits", ([ 
		"southdown" : __DIR__"grass-2",	
		"north" : __DIR__"milin4-2",	
	]));
	set("no_task",1);
    set("juemen",1);
    set("xianjing",0);
    set("jianzhu",0);
    set("outdoors", "city");
	setup();
}

void init()
{
    object me=this_player();
	set("no_die",1);
    this_player()->listen_to_die(this_object());
    add_action("do_xianjing", ({ "dig", "wa"}));
    add_action("do_mai",({ "mai","anzhi"}));
    add_action("do_none","killall");
    add_action("do_none","hitall");
    if (!wizardp(me)&&userp(me) && time()-me->query_temp("skf/qingstart")>600)
    {
        tell_object(me,"多尔衮已经不耐烦了，你还是赶紧回去吧！\n");
        me->move(__DIR__"qingjunying");
        return;
    }
	::init();
}

int do_none()
{
    object me=this_player();
    if (present("da xia",this_object()))
    {
        tell_object(me,"护送难民的大侠还在，不允许你大规模屠杀难民。\n");
        return 1;
    }
}
int refugeecome(object me)
{
    object refugee;
	if (!me)
	return 1;
    me->add_temp("skf/refugeecome",1);
    tell_room(this_object(),HIW"大批难民涌入了"+this_object()->query("short")+"！\n"NOR);
    //message("baowei",HIM"【谣言】某人："+"大批难民涌入了"+this_object()->query("short")+"！\n"+NOR,users());
    if (me->query_temp("skf/refugeecome")<20 && me->query_temp("skf/killnumber")<100)
    {
        for (int i=0;i<10;i++)
        {
            refugee=new(__DIR__"npc/refugee-2");
            refugee->set("skfleader",me->query("id"));
            refugee->copy(me);
            refugee->move(this_object());
		}
        remove_call_out("refugeecome");
        call_out("refugeecome",15,me);
    }
    else
    {
        tell_object(me,BLINK+HIM"难民好像全部四散逃开，再也不往这里来了。\n"NOR);
        tell_object(me,"你还是回多尔衮处复命吧。\n");
        me->move("/d/city/qingjunying");
    }
	return 1;
}


int start3(object me)
{
    int i;
    object hero=new(__DIR__"npc/hero");
    object refugee;
	if (!me)
	return 1;
    tell_room(this_object(),HIW+"扬州城撤退的难民队伍终于出现了！\n"+NOR);
    hero->set("skfleader",me->query("id"));
    hero->copy(me);
    hero->move(this_object());
    for (i=0;i<10;i++)
    {
        refugee=new(__DIR__"npc/refugee-2");
        refugee->set("skfleader",me->query("id"));
        refugee->copy(me);
        refugee->move(this_object());
    }
    remove_call_out("refugeecome");
    call_out("refugeecome",15,me);
    return 1;
}

int start2(object me)
{
	if (!me)
	return 1;
    tell_object(me,HIW"你听见密林里传来战斗的声音，应该是双方开始交战了。\n"NOR);
    tell_object(me,"还是早做准备，看看有什么可以利用的地形。比如在密林边缘挖个陷阱<dig 陷阱>什么呢。\n");
    remove_call_out("start3");
    call_out("start3",60,me);
    return 1;
}

int fight_start(object me)
{
	if (!me)
	return 1;
    tell_object(me,HIW"远处密林里飞鸟不断惊起，很明显有人要过来了。\n"NOR);
    remove_call_out("start2");
    call_out("start2",3,me);
    return 1;
}

int threesec(object me)
{
    this_object()->set("xianjing",1);
	if (!me)
	return 1;
    tell_object(me,HIG"你看着挖好的陷阱，满意地撇了撇嘴。\n"NOR);
    if (random(100)>49)
    tell_object(me,"你突然觉得也许埋下一点尖锐的东西，比如削尖的竹子也许效果会更好。\n");
    return 1;
}

int do_mai()
{
	object me=this_player();
	object ob=this_object();
	object zhu;
	object *sharpbamboo;
	if(me->is_busy()||me->is_fighting())
	return notify_fail("你正忙着呢。\n");
	if (!ob->query("xianjing"))
	return notify_fail("这里都没有陷阱，你怎么埋削尖的竹子？\n");
	if (ob->query("jianzhu")>3)
	return notify_fail("这里的陷阱已经布满削尖的竹子，不能再安放了。\n");
	sharpbamboo=all_inventory(me);
	for (int i=0;i<sizeof(sharpbamboo);i++)
	{
		if (sharpbamboo[i]->query("sharpbamboo"))
		{
			zhu=sharpbamboo[i];
			break;
        }
	}
	if (zhu)
	{
		tell_object(me,"你将一根"+zhu->query("name")+"埋进陷阱里。\n");
		destruct(zhu);
		ob->add("jianzhu",1);
	}
	else
	{
		tell_object(me,"你得找些削尖的竹子才能布置陷阱。\n");
	}
	return 1;
}

int do_xianjing(string arg)
{
	object me=this_player();
	object ob=this_object();
	if (!arg||(arg!="陷阱" && arg!="xianjing" && arg!="xian jing" && arg!="jing"))
	return notify_fail("你要挖什么？\n");
	if(me->is_busy()||me->is_fighting())
	return notify_fail("你正忙着呢。\n");
	if (ob->query("xianjing"))
	return notify_fail("这里已经有一个挖好的陷阱了。\n");
	if(!present("gang fu", this_player()))
	return notify_fail("你需要一件铁锹或者钢斧之类东西才能挖动陷阱。\n");
	me->add_busy(3);
	message_vision("$N开始吃力地挖着陷阱……\n",me);
	remove_call_out("threesec");
	call_out("threesec",3,me);
	return 1;
}