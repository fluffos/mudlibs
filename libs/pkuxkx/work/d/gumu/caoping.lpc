// Room: caoping.c
#include <ansi.h>
#include "/d/gumu/bonus.h"
inherit ROOM;


void create()
{
    set("short", "草坪");
    set("outdoors","gumu");
    set("long", @LONG
    这是一终南山山后中的一片草坪，地上长着绿油油
的小草，走在上面感到很舒服，草间夹杂着许多野花，不时
散发出阵阵幽香.草上面有许多麻雀，唧唧咂砸地叫着。你可
以试试看能不能只用双手就把麻雀都网(wang)在你面前，让
它们不能乱飞。

LONG
        );

	    set("exits", ([  
        "east" : __DIR__"caodi2",
 
 
]));
        set("no_clean_up", 0);
        set("objects",([__DIR__"npc/maque":6,]));
	
	    setup();
}


void init()
{
    object me=this_player();
    int i,count=0;
    object maque;
    object *all=all_inventory(this_object());
    add_action("do_wang", "wang");
    for (i=0;i<sizeof(all);i++)
    {
        if (all[i]->query("is_maque"))
        {
            count=count+1;
        }
    }
    if (userp(me)&&me->query_temp("gmnewbiejob/maque"))
    {
        for (i=0;i<3-count;i++)
        {
            maque=new(__DIR__"npc/maque1");
            maque->move(this_object());
        }
    }
}

int do_wang(string arg)
{
    object me=this_player();
    int exp,pot,rep;
    if ( !arg || ( arg != "maque" ) )
    {write("你要网什麽？\n",me);return 1;}
    if (me->is_busy()||me->is_fighting())
    {write("你正忙着呢。\n",me);return 1;}
    if ( (int)me->query_skill("yunu-xinfa", 1) < 20)
	{write( "你玉女心法等级不够，无法通过天罗地网式来涨轻功。\n",me);return 1;}
	if ( (int)me->query_skill("xianyun", 1) < 20)
    {write( "你用双手网了半天，没网到一只麻雀。\n",me);return 1;}
    if((int)me->query_skill("xianyun",1)>101)
    {write("这对你来说太简单了！\n",me);return 1;}
    if (time()-(int)me->query_temp("gmnewbiejob/maquetime")<120)
    {
        me->add_busy(5+random(2));
        if (me->query("combat_exp")<20000)
        {
            exp=4;
        }
        else if (me->query("combat_exp")<40000)
        {
            exp=7;
        }
        else if (me->query("combat_exp")<60000)
        {
            exp=10;
        }
        else if (me->query("combat_exp")<80000)
        {
            exp=12;
        }
        else
        {
            exp=14;
        }
        exp=exp*2;
        pot=1+random(exp*2);
        rep=1+random(exp);
        bonus(me,5,exp,pot,rep,HIW"在捕捉麻雀过程中，你增加了经验EXP点，潜能POT点！\n"NOR);
    }
    if( (int)me->query("qi") > 30 )
    {
        me->add("qi", -10);
        message_vision("$N的双手天罗地网般地网向麻雀，麻雀扑扑通通地飞，但都没飞出你的手掌所能够的范围。\n",me);
        if((int)me->query_skill("xianyun",1)*(int)me->query_skill("xianyun",1)*(int)me->query_skill("xianyun",1)/10 > me->query("combat_exp"))
        {write( "你用双手网了半天，没网到一只麻雀。\n",me);return 1;}
        else
        {me->improve_skill("xianyun", 30);write("你网了半天，似乎觉的轻功有所提高。\n");return 1;}
    }
    else
    {
        write("你现在过于疲倦，无法专心下来网麻雀。\n",me);return 1;
    }
} 






