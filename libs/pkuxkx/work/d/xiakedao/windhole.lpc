#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "风穴");
        set("long", @LONG

   山窟外雾色朦胧，鬼气森森。山窟内更是阴暗，几乎是伸手难见五指.
洞内寒风如刀，呼啸不绝。深呼一口气，只觉的空气中充满了血腥，一种
不详的感觉涌上了心头。
LONG
        );
        set("exits", ([ 
		"southdown" : __DIR__"realhole",
		"west" : __DIR__"firehole",
]));
        set("objects", ([

                        ]) );

        setup();

}

void init()
{	object ob;
	if( interactive( ob = this_player()))
	remove_call_out("blowing");
	call_out("blowing", random(5), ob);
}

int blowing(object ob)

{
	int damage;
	if(ob)
    if( environment(ob) == this_object())
	{
		message_vision(HIB"一阵狂风向$N席卷而出！！\n", ob);
		message_vision("$N被风吹得左右摇摆，难以站立！\n"NOR, ob);
	 	damage = random(50)+50	;
	    ob->receive_damage("qi", damage, "被风穴的狂风吹");
		ob->receive_wound("qi", 40, "被风穴的狂风吹");
		if( environment(ob) == this_object())
		call_out("blowing",5, ob);	
	}

	return 1;
}

