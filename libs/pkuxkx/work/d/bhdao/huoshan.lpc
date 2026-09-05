
#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "火山边缘");
	set("long", @LONG

   前面不远处就是一座火山，黑烟滚滚，隐隐见烟中夹有火光。
只听得隆隆声响，地面摇动，却是火山又在喷火。但见身旁已无
一株树木花草，只余光秃秃、黄焦焦的岩石。   
LONG
	);
	set("exits", ([ 
		"south" : __DIR__"shulin1",
]));
set("outdoors","bhdao");
	setup();
}

void init()
{	object ob;
	if( interactive( ob = this_player()))
	remove_call_out("fireball");
	call_out("fireball", random(5), ob);
	add_action("do_pao","pao");
}

int fireball(object ob)

{
	int damage;
	if(ob)
    if( environment(ob) == this_object())
	{
		message_vision(HIR"炽热的炎浆滚滚喷射而出，虽隔里许，已使人口干舌燥，遍身大汗\n", ob);
		message_vision("$N被蒸得金星乱冒，头脑中嗡嗡作声。\n"NOR, ob);
	 	damage = random(50)+50;
	    ob->receive_damage("qi", damage, "被炎浆蒸");
		ob->receive_wound("qi", 40, "被炎浆蒸");
		if( environment(ob) == this_object())
		call_out("fireball",5, ob);	
	}

	return 1;
}
int do_pao(string arg)
{       
	object ju,sheng;
        if( !arg || arg != "rope" )
        {
                write("你要抛什么? \n");
                return 1;
        }
     	if (!(sheng = present("long rope", this_player())))
	    return notify_fail("你没有绳子，抛什么？\n");
        message_vision(HIG"$N从地下捡起一块石子，缚在长绳一端，提气向前奔出数丈，喝一声：“去！”使力掷了出去。\n"NOR, this_player());
        if ((int)this_player()->query("neili") >= 600)
        {
         message_vision(HIY"$N用力一抖长绳，只见火光闪动，你取到火种啦！\n"NOR, this_player());
         this_player()->add("qi", -50);
         this_player()->add("neili",-50);
         ju = new(__DIR__"obj/huoju");
         ju->move(this_player());
         destruct(sheng);
        }
        else
        {
         message_vision(HIR"你内力不够，长绳不能及远，还是算了吧。\n"NOR, this_player());
         this_player()->add("qi",-10);
         this_player()->add("neili",-50);
         
         }
        return 1;
}
        

