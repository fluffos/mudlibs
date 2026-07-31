#include <ansi.h>
inherit ROOM;

int valid_leave();
void create()
{
	set("short", WHT"眠龙洞"NOR);
	set("long", @LONG
四周都是茂密的树林，前方的崖壁上有一个阴森森的大洞穴,正是
武林中最凶险的地方[眠龙洞]。传说洞里藏着无数宝物，
		数百年来无数
武林高手葬送于此，但活着出来的人却从没有走到过洞的尽头。
地方有一个闪光点，你好像通过这里移到(yidong)什么地方去。
LONG );
	set("exits", ([
		"east" : __DIR__"migong2",
		//
	"down" : "/d/migong/lev1/dong21",
	//	"east":"/d/migong/12gong/toby1",
                           	]));
		set("item_desc", ([
		"【迷宫】": "从这里可以进入迷宫，如果你已经通关，可以直接从这里传送到你想要到的层数。\n"
			ZJOBACTS2"传送:help yidong\n",
	]) );
        set("objects", ([
             "/d/migong/zhulong/npc/dragon" : 1,

                ]));
                set("no_clean_up", 0);
	setup();
	}
int valid_leave(object me, string dir)
{
	object *inv,kicker;
	int sizeinv,n,tt;

	if (dir =="down")
  {
        if ( me->query("combat_exp") < 50000)
                return notify_fail("就平你这点微末功夫不是去送死吗！\n");
			
			if ( me->query("mgcs") < 1)
                return notify_fail("没有次数就别去了！（签到给一次次数）\n");


		inv=all_inventory(me);
		sizeinv=sizeof(inv);

		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())
     				return notify_fail("你想给里面的怪物送点心去？\n");

		}
		me->set("mgcs",0);

	}

	return ::valid_leave(me, dir);
}

void init()
{
        add_action("do_go","yidong");
}

int do_go(string arg)
{
string msg,mapm,rooms;
int i;
	object *inv;
	int sizeinv;
    object room;
	object me=this_player();
 	if (!arg)
		return notify_fail("你要去第几层迷宫？(lev1-22)\n");
   // if (!me->query("migong"))
	//	return notify_fail("你没有进过迷宫的记录!\n");
	inv=all_inventory(me);
	sizeinv=sizeof(inv);

		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())
     				return notify_fail("你背着人想给里面的怪物送点心去？\n");

		}

    msg=me->query("jobtarget");

	if(arg!="lev1" && arg!="lev2" && arg!="lev3" && arg!="lev4"
	&& arg!="lev5"&& arg!="lev6"&& arg!="lev7"&& arg!="lev8"
	&& arg!="lev9"&& arg!="lev10"&& arg!="lev11"&& arg!="lev12"
	&& arg!="lev13"&& arg!="lev14"&& arg!="lev15"
	&& arg!="lev16" && arg!="lev17" && arg!="lev18" && arg!="lev19"
	&& arg!="lev20"&& arg!="lev21"&& arg!="lev22")
	 	return notify_fail("你要去第几层迷宫？(lev1-22)\n");
    if (me->query("neili")<1000)
		return notify_fail("你的内力不足!\n");
	
	if ( me->query("mgcs") < 1)
                return notify_fail("没有次数就别去了！（签到给一次次数）\n");

  //  if (me->query_condition("migongmove"))
	//	return notify_fail("你刚刚用过移动点，等会再来吧!\n");

	me->apply_condition("migongmove",18);
	me->delete("vendetta/authority");
    me->add("neili",-800);
	if(arg=="lev1") {
        if (me->query("migong/lev1")==1 ||
			me->query("migong/lev2")==1 || me->query("migong/lev3")==1 ||me->query("migong/lev4")==1  ||
			me->query("migong/lev5")==1  ||me->query("migong/lev6")==1  ||me->query("migong/lev7")==1  ||
			me->query("migong/lev8")==1  ||me->query("migong/lev9")==1  ||me->query("migong/lev10") ==1 ||
			me->query("migong/lev11")==1  ||me->query("migong/lev12")==1  ||me->query("migong/lev13") ==1 ||
			me->query("migong/lev14")==1  ||me->query("migong/lev15")==1)
		{
			me->set("mgcs",0);
			message_vision(HIG "一阵光辉笼罩了$N!\n" NOR, me);
			i=(random(5)+1);
			mapm="/d/migong/lev2/dong0"+i;
			if (random(3)==0)
			{
				i=(random(21)+30);
				mapm="/d/migong/lev2/dong"+i;
			}
			if (random(3)==0)
			{
				i=(random(21)+50);
				mapm="/d/migong/lev2/dong"+i;
			}
			me->move(mapm);
		}
		else message_vision(HIG "$N没到过这一层!\n" NOR, me);
	}
	if(arg=="lev2") {
        if (
me->query("migong/lev2")==1  || me->query("migong/lev3")==1  ||me->query("migong/lev4")==1  ||
me->query("migong/lev5")==1  ||me->query("migong/lev6")==1  ||me->query("migong/lev7")==1  ||
me->query("migong/lev8")==1  ||me->query("migong/lev9")==1  ||me->query("migong/lev10")==1  ||
me->query("migong/lev11") ==1 ||me->query("migong/lev12")==1  ||me->query("migong/lev13")==1  ||
me->query("migong/lev14") ==1 ||me->query("migong/lev15")==1
        )
	{
        message_vision(HIG "一阵光辉笼罩了$N!\n" NOR, me);
i=(random(5)+1);
mapm="/d/migong/lev3/dong0"+i;
if (random(3)==0)
{
i=(random(21)+30);
mapm="/d/migong/lev3/dong"+i;
}
if (random(3)==0)
{
i=(random(21)+50);
mapm="/d/migong/lev3/dong"+i;
}

me->move(mapm);
}
else message_vision(HIG "$N没到过这一层!\n" NOR, me);
}
	if(arg=="lev3") {
        if (
me->query("migong/lev3")==1  || me->query("migong/lev4") ==1 ||
me->query("migong/lev5") ==1 ||me->query("migong/lev6") ==1 ||me->query("migong/lev7") ==1 ||
me->query("migong/lev8")==1  ||me->query("migong/lev9")==1  ||me->query("migong/lev10")==1  ||
me->query("migong/lev11")==1  ||me->query("migong/lev12")==1  ||me->query("migong/lev13")==1  ||
me->query("migong/lev14") ==1 ||me->query("migong/lev15") ==1
        )
{
        message_vision(HIG "一阵光辉笼罩了$N!\n" NOR, me);
i=(random(5)+1);
mapm="/d/migong/lev4/dong0"+i;
if (random(3)==0)
{
i=(random(21)+30);
mapm="/d/migong/lev4/dong"+i;
}
if (random(3)==0)
{
i=(random(21)+50);
mapm="/d/migong/lev4/dong"+i;
}

me->move(mapm);
}
else message_vision(HIG "$N没到过这一层!\n" NOR, me);
}
	if(arg=="lev4") {
        if (
me->query("migong/lev4")==1  ||
me->query("migong/lev5") ==1 ||me->query("migong/lev6")==1  ||me->query("migong/lev7")==1  ||
me->query("migong/lev8") ==1 ||me->query("migong/lev9")==1  ||me->query("migong/lev10")==1  ||
me->query("migong/lev11")==1  ||me->query("migong/lev12")==1  ||me->query("migong/lev13")==1  ||
me->query("migong/lev14")==1  ||me->query("migong/lev15")==1
        )
{
        message_vision(HIG "一阵光辉笼罩了$N!\n" NOR, me);
i=(random(5)+1);
mapm="/d/migong/lev5/dong0"+i;
if (random(3)==0)
{
i=(random(21)+30);
mapm="/d/migong/lev5/dong"+i;
}
if (random(3)==0)
{
i=(random(21)+50);
mapm="/d/migong/lev5/dong"+i;
}
me->move(mapm);
}
else message_vision(HIG "$N没到过这一层!\n" NOR, me);
}
	if(arg=="lev5") {
        if (
me->query("migong/lev5")==1  ||me->query("migong/lev6")==1  ||me->query("migong/lev7")==1  ||
me->query("migong/lev8")==1  ||me->query("migong/lev9")==1  ||me->query("migong/lev10")==1  ||
me->query("migong/lev11")==1  ||me->query("migong/lev12")==1  ||me->query("migong/lev13")==1  ||
me->query("migong/lev14")==1  ||me->query("migong/lev15")==1
        )
{
        message_vision(HIG "一阵光辉笼罩了$N!\n" NOR, me);
i=(random(5)+1);
mapm="/d/migong/lev6/dong0"+i;
if (random(3)==0)
{
i=(random(21)+30);
mapm="/d/migong/lev6/dong"+i;
}
if (random(3)==0)
{
i=(random(21)+50);
mapm="/d/migong/lev6/dong"+i;
}

me->move(mapm);
}
else message_vision(HIG "$N没到过这一层!\n" NOR, me);
}
	if(arg=="lev6") {
        if (me->query("migong/lev6")==1  ||me->query("migong/lev7")==1  ||
me->query("migong/lev8")==1  ||me->query("migong/lev9")==1  ||me->query("migong/lev10")==1  ||
me->query("migong/lev11") ==1 ||me->query("migong/lev12")==1  ||me->query("migong/lev13")==1  ||
me->query("migong/lev14")==1  ||me->query("migong/lev15")==1
        )
{
        message_vision(HIG "一阵光辉笼罩了$N!\n" NOR, me);
i=(random(5)+1);
mapm="/d/migong/lev7/dong0"+i;
if (random(3)==0)
{
i=(random(21)+30);
mapm="/d/migong/lev7/dong"+i;
}
if (random(3)==0)
{
i=(random(21)+50);
mapm="/d/migong/lev7/dong"+i;
}
me->move(mapm);
}
else message_vision(HIG "$N没到过这一层!\n" NOR, me);
}
	if(arg=="lev7") {
        if (me->query("migong/lev7") ==1 ||
me->query("migong/lev8")==1  ||me->query("migong/lev9")==1  ||me->query("migong/lev10")==1  ||
me->query("migong/lev11")==1  ||me->query("migong/lev12")==1  ||me->query("migong/lev13")==1  ||
me->query("migong/lev14")==1  ||me->query("migong/lev15")==1
        )
{
        message_vision(HIG "一阵光辉笼罩了$N!\n" NOR, me);
i=(random(5)+1);
mapm="/d/migong/lev8/dong0"+i;
if (random(3)==0)
{
i=(random(21)+30);
mapm="/d/migong/lev8/dong"+i;
}
if (random(3)==0)
{
i=(random(21)+50);
mapm="/d/migong/lev8/dong"+i;
}
me->move(mapm);
}
else message_vision(HIG "$N没到过这一层!\n" NOR, me);
}
	if(arg=="lev8") {
        if (
me->query("migong/lev8")==1  ||me->query("migong/lev9")==1  ||me->query("migong/lev10")==1  ||
me->query("migong/lev11")==1  ||me->query("migong/lev12")==1  ||me->query("migong/lev13")==1  ||
me->query("migong/lev14")==1  ||me->query("migong/lev15")==1
        )
{
        message_vision(HIG "一阵光辉笼罩了$N!\n" NOR, me);
i=(random(5)+1);
mapm="/d/migong/lev9/dong0"+i;
if (random(3)==0)
{
i=(random(21)+30);
mapm="/d/migong/lev9/dong"+i;
}
if (random(3)==0)
{
i=(random(21)+50);
mapm="/d/migong/lev9/dong"+i;
}
me->move(mapm);
}
else message_vision(HIG "$N没到过这一层!\n" NOR, me);
}
	if(arg=="lev9") {
        if (me->query("migong/lev9")==1  ||me->query("migong/lev10")==1  ||
me->query("migong/lev11")==1  ||me->query("migong/lev12")==1  ||me->query("migong/lev13")==1  ||
me->query("migong/lev14")==1  ||me->query("migong/lev15") ==1
        )
{
        message_vision(HIG "一阵光辉笼罩了$N!\n" NOR, me);
i=(random(5)+1);
mapm="/d/migong/lev10/dong0"+i;
if (random(3)==0)
{
i=(random(21)+30);
mapm="/d/migong/lev10/dong"+i;
}
if (random(3)==0)
{
i=(random(21)+50);
mapm="/d/migong/lev10/dong"+i;
}
me->move(mapm);
}
else message_vision(HIG "$N没到过这一层!\n" NOR, me);
}
	if(arg=="lev10") {
        if (me->query("migong/lev10")==1 ||
me->query("migong/lev11") ==1 ||me->query("migong/lev12") ==1 ||me->query("migong/lev13")==1 ||
me->query("migong/lev14") ==1 ||me->query("migong/lev15")==1
        )
{
        message_vision(HIG "一阵光辉笼罩了$N!\n" NOR, me);
i=(random(5)+1);
mapm="/d/migong/lev11/dong0"+i;
if (random(3)==0)
{
i=(random(21)+30);
mapm="/d/migong/lev11/dong"+i;
}
if (random(3)==0)
{
i=(random(21)+50);
mapm="/d/migong/lev11/dong"+i;
}
me->move(mapm);
}
else message_vision(HIG "$N没到过这一层!\n" NOR, me);
}
	if(arg=="lev11") {
        if (
me->query("migong/lev11") ==1 ||me->query("migong/lev12")==1  ||me->query("migong/lev13")==1  ||
me->query("migong/lev14") ==1 ||me->query("migong/lev15") ==1
        )
{
        message_vision(HIG "一阵光辉笼罩了$N!\n" NOR, me);
i=(random(5)+1);
mapm="/d/migong/lev12/dong0"+i;
if (random(3)==0)
{
i=(random(21)+30);
mapm="/d/migong/lev12/dong"+i;
}
if (random(3)==0)
{
i=(random(21)+50);
mapm="/d/migong/lev12/dong"+i;
}

me->move(mapm);
}
else message_vision(HIG "$N没到过这一层!\n" NOR, me);
}
	if(arg=="lev12") {
        if (me->query("migong/lev12")==1 ||me->query("migong/lev13")==1 ||
me->query("migong/lev14")==1 ||me->query("migong/lev15") ==1
        )
{
        message_vision(HIG "一阵光辉笼罩了$N!\n" NOR, me);
i=(random(5)+1);
mapm="/d/migong/lev13/dong0"+i;
if (random(3)==0)
{
i=(random(21)+30);
mapm="/d/migong/lev13/dong"+i;
}
if (random(3)==0)
{
i=(random(21)+50);
mapm="/d/migong/lev13/dong"+i;
}

me->move(mapm);
}
else message_vision(HIG "$N没到过这一层!\n" NOR, me);
}
	if(arg=="lev13") {
        if (me->query("migong/lev13")==1 ||
me->query("migong/lev14") ==1||me->query("migong/lev15") ==1
        )
{
        message_vision(HIG "一阵光辉笼罩了$N!\n" NOR, me);
i=(random(5)+1);
mapm="/d/migong/lev14/dong0"+i;
if (random(3)==0)
{
i=(random(21)+30);
mapm="/d/migong/lev14/dong"+i;
}
if (random(3)==0)
{
i=(random(21)+50);
mapm="/d/migong/lev14/dong"+i;
}

me->move(mapm);
}
else message_vision(HIG "$N没到过这一层!\n" NOR, me);
}
	if(arg=="lev14") {
        if (
me->query("migong/lev14")==1 ||me->query("migong/lev15")==1
        )
{
        message_vision(HIG "一阵光辉笼罩了$N!\n" NOR, me);
i=(random(3)+1);
mapm="/d/migong/lev15/dong"+i;
if (random(3)==0)
{
i=(random(1)+3);
mapm="/d/migong/lev15/dong"+i;
}
if (random(3)==0)
{
i=(random(1)+3);
mapm="/d/migong/lev15/dong"+i;
}

me->move(mapm);
}
else message_vision(HIG "$N没到过这一层!\n" NOR, me);
}
	if(arg=="lev15")
	{
        if (me->query("migong/lev15")==1)
		{
			message_vision(HIG "一阵光辉笼罩了$N!\n" NOR, me);
			mapm="/d/migong/lev16/dong01";
			me->move(mapm);
		}
		else
			message_vision(HIG "$N没到过这一层!\n" NOR, me);
	}
	if(arg=="lev16") {
        if (present("fire hat", me) )
{
        message_vision(HIW "一阵光辉笼罩了$N!\n" NOR, me);
me->move("/d/migong/lev16/dong22");
}
else message_vision(HIR "$N没到去这层的资格\n" NOR, me);
}
	if(arg=="lev17") {
        if (present("water armor", me) )
{
        message_vision(HIW "一阵光辉笼罩了$N!\n" NOR, me);
me->move("/d/migong/lev17/dong22");
}
else message_vision(HIR "$N没到去这层的资格\n" NOR, me);
}
	if(arg=="lev18") {
        if (present("earth shield", me) )
{
        message_vision(HIW "一阵光辉笼罩了$N!\n" NOR, me);
me->move("/d/migong/lev18/dong22");
}
else message_vision(HIR "$N没到去这层的资格\n" NOR, me);
}
	if(arg=="lev19") {
        if (present("air boot", me) )
{
        message_vision(HIW "一阵光辉笼罩了$N!\n" NOR, me);
me->move("/d/migong/lev19/dong22");
}
else message_vision(HIR "$N没到去这层的资格\n" NOR, me);
}
	if(arg=="lev20") {
        if (present("light jian", me) )
{
        message_vision(HIW "一阵光辉笼罩了$N!\n" NOR, me);
me->move("/d/migong/lev20/dong22");
}
else message_vision(HIR "$N没到去这层的资格\n" NOR, me);
}
	if(arg=="lev21") {
        if (present("dark jian", me) )
{
        message_vision(HIW "一阵光辉笼罩了$N!\n" NOR, me);
me->move("/d/migong/lev21/dong22");
}
else message_vision(HIR "$N没到去这层的资格\n" NOR, me);
}
	if(arg=="lev22") {
        if (present("dark jian", me) ||
        present("light jian", me))
{
        message_vision(HIW "一阵光辉笼罩了$N!\n" NOR, me);
me->move("/d/migong/lev22/dong01");
}
else message_vision(HIR "$N没到去这层的资格\n" NOR, me);
}

return 1;
}