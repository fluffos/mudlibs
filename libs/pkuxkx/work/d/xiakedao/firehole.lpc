
#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "火洞");
	set("long", @LONG

   才入洞口，就觉的一阵热气扑面而来。入洞越深，四周空气越热，
渐渐热如火窟。你不禁汗如雨下，转目四望，只见四面山壁，竞以变
作了暗赤之色，仿佛随时会有火炎涌出。
LONG
	);
	set("exits", ([ 
		"west" : __DIR__"yongdao5",
		"east" : __DIR__"windhole",
]));

        set("objects", ([
               __DIR__"npc/kylin" : 1,
]));
	setup();
}

void init()
{	object ob;
	if( interactive( ob = this_player()))
	remove_call_out("fireball");
	call_out("fireball", random(5), ob);
}

int fireball(object ob)
{
	int damage;
	if(ob)
    if( environment(ob) == this_object())
	{
		message_vision(HIR"一股炽热的熔炎形成一个大火球向$N激射而出！！\n", ob);
		message_vision("$N被炽热的熔炎喷得焦偷烂额，奄奄一息！\n"NOR, ob);
	 	damage = random(50)+50	;
	    ob->receive_damage("qi", damage, "被熔炎喷出的大火球烧");
		ob->receive_wound("qi", 40, "被熔炎喷出的大火球烧");
		if( environment(ob) == this_object())
		call_out("fireball",5, ob);	
	}

	return 1;
}


int valid_leave(object me, string dir)
{
        if (dir == "east" && objectp(present("fire kylin", environment(me))))
           return notify_fail(HIR"火麒麟"HIW"～呼～"HIY"的一下向你扑来，似乎不让你进入。\n"NOR);
        call_out("clean_up",3);
        return ::valid_leave(me, dir);
}
