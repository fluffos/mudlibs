// Room: hill.c 小山坡
// created by Zine 30 Aug 2010

inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIG"小山坡"NOR);
	set("long", @LONG
这里是一处小山坡，附近三十里内只有这里的草是绿的。这里有一处小溪(valley)。
LONG
	);

	set("exits", ([
		"west" : __DIR__"grass3",
	]));
	set("item_desc",
    ([
        "valley":"这里是一条清澈的小溪，溪水甘甜，让人忍不住想喝(drink)一口。\n",
        ]));
	set("outdoors", "menggu_e");
	setup();
}

void init()
{
	add_action("do_guancha","guancha");
	add_action("do_drink","drink");
}
int do_drink()
{
        int current_water;
        int max_water;
        object me;
        me = this_player();
        current_water = me->query("water");
        max_water = (int)me->max_water_capacity();
        if (current_water<max_water) {
                me->set("water", max_water);
                message("vision", me->name()+"趴在溪边，捧起溪水一阵豪饮。\n",
                        environment(me), ({me}) );
                write("你趴在小溪边，尽情地畅饮溪中清水。\n");
        }
        else write("你已经不渴了，还是别撑破肚皮了。\n");

        return 1;
}

int bonus2(object me)
{
    int exp,pot;
	if (((int)me->query("combat_exp"))<500000)
		{
            exp=25+random(25);
            pot=random(exp);
			me->add("combat_exp",exp);
            me->add("potential",pot);
            tell_object(me,HIC"你被奖励了"+chinese_number(exp)+"点经验，"+chinese_number(pot)+"点潜能。\n"NOR);
		}
	else 
		{
			if (((int)me->query("combat_exp"))<5000000 )
				{
					exp=15+random(15);
                    pot=random(exp);
                    me->add("combat_exp",exp);
                    me->add("potential",pot);
                    tell_object(me,HIC"你被奖励了"+chinese_number(exp)+"点经验，"+chinese_number(pot)+"点潜能。\n"NOR);
				}
			else
				{
					exp=5+random(5);
                    pot=random(exp);
                    me->add("combat_exp",exp);
                    me->add("potential",pot);
                    tell_object(me,HIC"你被奖励了"+chinese_number(exp)+"点经验，"+chinese_number(pot)+"点潜能。\n"NOR);
				}
		}
}

int do_guancha()
{
	object me = this_player();
	if (me->query_temp("lpjob/step2"))
		{
			if (((int)me->query_temp("lpjob/muyangtimes"))<10) 
				{	
					if(me->is_busy() || me->is_fighting())
						{return notify_fail("你正忙着，等会再放羊。\n");}
					else 
						{
							message_vision("羊儿惬意的吃着青草，$N看着笑得合不拢嘴。\n",me);
							me->add_temp("lpjob/muyangtimes",1);
							if ((int)me->query("combat_exp")<500000 && random(50)>45 &&!me->query("shediaoquest/dmfy"))
								{
									tell_object(me,HIR"中午时分，空中忽然飞来一头黑雕，向羊群猛扑下来，一头小羊受惊，向东疾奔而去。\n"NOR);
								    call_out("guanzhan", 2, me);
								}
							else if ((int)me->query("combat_exp")>5000000 && random(2) && !me->query("shediaoquest/dmfy"))
								{
									tell_object(me,HIR"中午时分，空中忽然飞来一头黑雕，向羊群猛扑下来，一头小羊受惊，向东疾奔而去。\n"NOR);
									call_out("guanzhan", 2, me);
								}
						    else if ((int)me->query("combat_exp")<=5000000&&(int)me->query("combat_exp")>=500000
                                && !me->query("shediaoquest/dmfy")&&random(50)>30)
                                {
                                    tell_object(me,HIR"中午时分，空中忽然飞来一头黑雕，向羊群猛扑下来，一头小羊受惊，向东疾奔而去。\n"NOR);
									call_out("guanzhan", 2, me);
                                }
							else			
                                {
									
								}
						}
					}
				
			else 
				{
					tell_object(me,"羊儿已经吃饱了，你可以回去把羊交给李萍了。\n");
					tell_object(me,"你牵着小羊抄近道回到了郭靖家，你把羊交给了李萍。\n");
					tell_object(me,"李萍笑呵呵地对你表示感谢。\n");
					me->delete_temp("lpjob");
					me->move(__DIR__"guojingjia");
					bonus2(me);
					tell_object(me,"你回想刚才放羊的经历，似乎若有所悟。\n");
					
				}
			return 1;
		}
	else
		{
			tell_object(me,"你有把羊赶到这里吗？\n");
            return 1;  
		} 
}

int guanzhan(object me)
{	
	me->set_temp("lpjob/enterallow",1);
	message_vision(YEL"$N忙骑上小马追去，直追了七八里路，突然间前面传来一阵阵隐隐的轰隆之声。\n"NOR, me);
    set("exits/eastup", __DIR__"guanzhan"); 
	remove_call_out("close_door");
	call_out("close_door",10,me); 
	return 1;
}

int close_door(object me)
{
	me->delete_temp("lpjob/enterallow");
	delete("exits/eastup",);
	return 1;
}

int valid_leave(object me, string dir)
{  
	if ( dir == "eastup"  && (!(me->query_temp("lpjob/enterallow"))) )
	return notify_fail("你的羊又没跑，你去那边凑什么热闹？”\n");
	return ::valid_leave(me, dir);
}

