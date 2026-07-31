//written by lnwm on 97/07/08
//shan2.c

#include <ansi.h>

inherit ROOM;

int do_jiefei( object ppl );

void create()
{
    set("short","青城山脉");
    set("long",@LONG
这里已远离青城后山，位于青藏高原以东，四川盆地西北的重山峻岭之中，这
里山峦起伏，地势十分险要。据传有很多世外的高人就隐居在这片浩瀚的群山之中
由于地势复杂，许多朝廷的钦犯或江洋大盗也喜欢隐藏在这片群山之中。你放眼望
去，四周全是山，几乎不可辨清道路。
LONG);
    set("exits",([
        "east"   	:		__DIR__ "shan1",
	"west"		:		__DIR__ "shan3",
    ]));
    setup();
}

void init()
{
    if (userp(this_player()))
    {
        do_jiefei(this_player());
    }
}

int valid_leave(object me, string arg)
{
	if ( objectp( present("jie fei",environment(me))))
	{
		return notify_fail(RED"劫匪拦住了你的去路\n"NOR);
	}
	return 1;
}

int do_jiefei( object ppl )
{
	object jiefei;
	int i;	

	tell_object(ppl,CYN"\n\n你忽然感觉周围的草丛有些异样，不禁停下了脚步。\n"NOR);
	tell_object(ppl,RED"\n\n突然从草丛中跳出几个劫匪。\n"NOR);

    //修补地上留下一堆尸体，造成当机的bug.
    foreach( object ob in all_inventory(this_object()) )
    {
        if ( !ob->is_character() || ob->is_corpse() )
            destruct(ob);
    }
	
	if(  (int) ppl->query("combat_exp") <= 100000 )
	{
		tell_object(ppl,RED"\n劫匪几下将你砍翻在地。\n"NOR);
		tell_object(ppl,CYN"\n劫匪轻蔑地对你说：就凭你这点闯江湖的道行也来青城山撒野？\n"NOR);
		ppl->unconcious();
        ppl->move( __DIR__ "shan1" );

        foreach( object ob in all_inventory(this_object()))
        {
            if (!userp(ob))
            {
                ob->move(__DIR__"jiefei_wo");
            }
        }
	}	
	else
	{
		if ( present ("jie fei") ) 
            return 1;
		for( i = 0; i < 5; i++ )
		{
			jiefei = new(__DIR__ "npc/jiefei");
			jiefei->move(this_object());
		}	
	}
	return 1;
}
