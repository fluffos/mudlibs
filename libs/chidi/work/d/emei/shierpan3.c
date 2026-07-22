// Room: /d/emei/shierpan3.c 峨嵋派 十二盘3

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", "十二盘");
	set("long", @LONG
这里石阶陡折多弯，号称「十二盘」。你见路边有个八音池，有人正在
向池中击掌(clap)。由此西上可达华严顶，东下则到万年庵。
LONG
	);

	set("exits", ([
                "westdown": __DIR__"shierpan2",
                "eastup":  __DIR__"shierpan4",
	]));

	set("outdoors", "shaolin");
	setup();	
}
void init()
{
       object me = this_player();
       object room;
       room= load_object(__DIR__"xuanya");
       if(random((int)me->query_kar()) <= 10) 
	{
		message_vision(HIR"一阵腥风袭来，悬崖上突然出现了一条巨蟒，把$N卷了起来！\n"NOR, me);
		me->move(room);
                return ;
       }
        add_action("do_clap", "clap");
}

int do_clap()
{

        mapping myfam;
	object me = this_player();
	int kar= this_player()->query_kar();

   if (me->is_busy())
	return notify_fail("你现在正忙着呢。\n");

    message_vision("$N举起手掌轻轻的拍了几下。\n", me);

    if ( me->query("jing") < 30)
       return notify_fail("你已经累的气喘吁吁！\n");

    if ((!(myfam = me->query("family")) || myfam["family_name"] != "峨嵋派") )
        write("四周一片寂静，只听的池中几声蛙鸣。\n");

    me->add("jing",-10+random(5)); 

    if (( random(kar) <= 5 ) && (random(3)<2) )  
    {
         write("四周一片寂静，只听的池中几声蛙鸣。\n");
     } else if (random(kar) <= 18 )
    {

        write("从八音池中传来阵阵击掌之声，随声恍若数人同时相和。\n");  
        me->improve_skill("strike", random(me->query_int()));
        write(HIR"你似乎对掌法有了一些新的领悟，你的基本掌法进步了。\n"NOR);
    
    } else if (me->query("qi") < me->query("max_qi"))
    {
    	write("清风吹动池中的荷叶哗然作响，使你顿觉神清气爽。\n"); 
        me->add("qi",30);
    }
     return 1;
}
