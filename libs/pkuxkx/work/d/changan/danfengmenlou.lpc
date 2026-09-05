//春明门 /d/jinyang/chunmingmen
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIR"丹凤门城楼"NOR);
        set("long", @LONG
这是丹凤门城门上的望楼，一队队壮健的金吾卫盔甲
鲜明，手持陌刀长戟，强弓利箭，警惕的注视着城下过望
行人；城门北面就是皇宫禁地大明宫。
LONG        );

        set("exits", ([
                "east" : __DIR__"citywall7",
                "west" : __DIR__"citywall9",
        ]));

        set("objects", ([
		      __DIR__"npc/jinwu-4": 1,
		      __DIR__"npc/jinwu-2": 1
        ]));
        
        set("locate_level",4);

        set("outdoors", "changan");
        set("changan", 4); // 0-郊外 1-外城 2-皇城 3-禁宫 4-城墙
        setup();   
}

void init()
{
        object ob, *inv;
        int lp;
        
        if (interactive(ob = this_player()) ) 
        {
                if (ob->query("special_skill/sociability"))
                    	 return;  //sociability不被追杀
                message_vision(CYN"四周突然冲过来无数金吾卫，远处弓箭刷刷刷地射过来！\n$N还是赶快跑吧！\n"NOR,ob);
                ob->start_busy(10);
                ob->receive_damage("qi",1000,"被金吾卫的弓箭射");
                ob->receive_wound("qi",500,"被金吾卫的弓箭射");
                inv=all_inventory(this_object());
                for(lp=0;lp<sizeof(inv);lp++)
                {
                	if ( inv[lp]->query("id")=="jin wu" )
                	{
                		message_vision("$N大喝道：大胆毛贼，这个地方也是你等能够闯的？\n", inv[lp]);
                		ob->apply_condition("cakiller", 60);
                		inv[lp]->kill_ob(ob);
                	}
                }
        }
}