#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIB"迷宫寻路符"NOR, ({ "migong fu" }) );
    set_weight(1);
            set("no_put", 1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
	       
            set("no_put", 1);
            set("no_steal", 1);
            set("no_get", 1);
            set("no_beg", 1);
            set("value", 100000);
            set("unit", "张");
            set("material", "paper");
            set("long", "你可以用(xunlu)来寻找boss的位置\n");
          }

    setup();
}
void init()
{
	add_action("do_eat", "xunlu");

}



int do_eat(string arg)
{
string msg;
	object *inv;
	int sizeinv;
        object me = this_player();
        string tarset;
 	if (!id(arg))
	return notify_fail("你要用什么？\n");
		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("你不能背着人用!\n");
       		
		}

    if (me->is_fighting()) 
        return notify_fail("你正打的热闹着呢!\n");
    if (me->is_busy()) 
        return notify_fail("你正热闹着呢!\n");
    if (me->query("neili")<100)
	return notify_fail("你的内力不足!\n");

    if(environment(me)->query("short")!=BLU"山洞"NOR
       &&environment(me)->query("short")!=WHT"钟乳石洞"NOR
       && environment(me)->query("short")!=YEL"岩洞"NOR
       && environment(me)->query("short")!=RED"熔岩洞"NOR
       && environment(me)->query("short")!=CYN"石洞"NOR
       && !environment(me)->query("magicroom"))
return notify_fail("这里不能使用!\n");

    if(environment(me)->query("short")==BLU"山洞"NOR
       ||environment(me)->query("short")==WHT"钟乳石洞"NOR
       ||environment(me)->query("short")==YEL"岩洞"NOR
       ||environment(me)->query("short")==RED"熔岩洞"NOR
       ||environment(me)->query("short")==CYN"石洞"NOR
       ||environment(me)->query("magicroom"))
{

      tarset=me->query("jobtarget");
msg=(string)file_name(environment(me));

if (strsrch(msg,"lev9")>1)
{
tarset="/d/migong/lev9/dong100";
}
if (strsrch(msg,"lev8")>1)
{
tarset="/d/migong/lev8/dong100";
}
if (strsrch(msg,"lev7")>1)
{
tarset="/d/migong/lev7/dong100";
}
if (strsrch(msg,"lev6")>1)
{
tarset="/d/migong/lev6/dong100";
}
if (strsrch(msg,"lev5")>1)
{
tarset="/d/migong/lev5/dong100";
}
if (strsrch(msg,"lev4")>1)
{
tarset="/d/migong/lev4/dong99";
}
if (strsrch(msg,"lev3")>1)
{
tarset="/d/migong/lev3/dong99";
}
if (strsrch(msg,"lev2")>1)
{
tarset="/d/migong/lev2/dong99";
}

if (strsrch(msg,"lev1")>1
)
{
tarset="/d/migong/lev1/dong99";
}
if (strsrch(msg,"lev21")>1
)
{
tarset="/d/migong/lev21/dong100";
}
if (strsrch(msg,"lev20")>1
)
{
tarset="/d/migong/lev20/dong100";
}

if (strsrch(msg,"lev19")>1
)
{
tarset="/d/migong/lev19/dong100";
}
if (strsrch(msg,"lev18")>1
)
{
tarset="/d/migong/lev18/dong100";
}
if (strsrch(msg,"lev17")>1
)
{
tarset="/d/migong/lev17/dong100";
}
if (strsrch(msg,"lev16")>1
)
{
tarset="/d/migong/lev16/dong100";
}
if (strsrch(msg,"lev15")>1)
{
tarset="/d/migong/lev15/dong3";
}

if (strsrch(msg,"lev14")>1)
{
tarset="/d/migong/lev14/dong100";
}
if (strsrch(msg,"lev13")>1)
{
tarset="/d/migong/lev13/dong100";
}
if (strsrch(msg,"lev12")>1)
{
tarset="/d/migong/lev12/dong100";
}
if (strsrch(msg,"lev11")>1)
{
tarset="/d/migong/lev11/dong100";
}
if (strsrch(msg,"lev10")>1)
{
tarset="/d/migong/lev10/dong100";
}

      me->move(tarset);

      message_vision(HIG "$N吃把迷宫符拿出，一阵光辉笼罩了你!\n" NOR, me);

        me->start_busy(1);
       // message_vision(HIG "$N吃把迷宫符拿出，一阵光辉笼罩了你!\n" NOR, me);
        
	destruct(this_object());
}	
else 
{
        message_vision(HIG "$N这里不能使用!\n" NOR, me);
//return 1;
}
        destruct(this_object());
	return 1;
}

