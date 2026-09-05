// 碎石路
// edit: by zine Oct 19 2010

inherit __DIR__"xxconfig";
#include <ansi.h>
void create()
{
	set("short", CYN"碎石路"NOR);
	set("long", @LONG
碎石铺就的道路。似乎和某些武功有着联系。地下的脚印(jiaoyin)有些奇怪。
LONG
	);
    set("normaldesc", @LONG
碎石铺就的道路。似乎和某些武功有着联系。地下的脚印(jiaoyin)有些奇怪。
LONG
	);
	set("exits", ([ 
		"northeast" : __DIR__"suishilu1",
        "west" : __DIR__"grass4",
        "southeast" : __DIR__"suishilu2",
        
		
    ]));
    set("outdoors", "xingxiuhai");

    set("item_desc", ([ 
        "jiaoyin" : "这些脚印似乎和轻功有很大联系，你可以试着踩踩(cai)。\n",  
    
   ])); 
	//set("objects", ([(__DIR__"npc/qinjun") : 1,
    //]));
	setup();
	::create();
}

void init()
{
	add_action("do_step", ({ "cai" }));
	::init();
}

int do_step(string arg)    
{  
   object liumang;
   object me=this_player(); 
   if( !arg || (arg != "脚印" && arg !="jiaoyin"))   
   return notify_fail("你要踩什么？\n");    
   if( me->is_fighting() || me->is_busy() )
   return notify_fail("你现在正忙着呢。\n");   
   me->start_busy(random(3));    
   if( me->query("qi") < (int)(me->query("max_qi")/3) ) 
   { 
        return notify_fail("你头昏脑胀，完全地上记不得步法！\n");
   }
   if( (int)me->query_skill("zhaixinggong",1) < 1 && me->query("family/family_name")=="星宿派")
        {
                me->improve_skill("zhaixinggong",1);
        }
   if( (int)me->query_skill("dodge",1) < 120 ) 
   { 
        tell_object(me,"你依次踩过地上的足迹。\n"); 
        me->improve_skill("dodge", 50-me->query("str"));
        if (me->query("combat_exp")<60000)
        {
            me->improve_skill("dodge", random(me->query("con")));
        }
        if (me->query("combat_exp")<30000)
        {
            me->improve_skill("dodge", (30000-me->query("combat_exp"))*me->query("int")/10000);
        }
        tell_object(me, "你领悟出一些基本轻功方面的窍门。\n");    
   } 
   else 
   {  
        message_vision("$N踩来踩去，却发现地上的步法早已熟记于胸。\n", me); 
   }    
   me->receive_damage("qi", (int)me->query("max_qi")*10/100);  
   return 1; 
}  