//Cracked by Kafei
#include "room.h"

inherit ROOM;

int valid_leave();


void create()
{
        set("short", "天龙寺大门");
        set("long", @LONG
这里松柏幽幽，碧荫连天。你走在林间小径上只觉得心宁
神静。 前面有两颗菩提树在道路两旁，路的尽头有一堵高高
的砖墙，正中是一扇橡木门，门上一块黑匾(bian)。
LONG
        );


        set("outdoors", "dali");
          set("item_desc", ([
                "bian" : 			
"       \n"
"　　　　　　　　≌≌≌≌≌≌≌≌≌≌≌≌≌≌≌≌≌\n"
"　　　　　　　　≌≌　　　　　　　　　　　　　≌≌\n"
"　　　　　　　　≌≌　  　天   龙   寺        ≌≌\n"
"　　　　　　　　≌≌　　　　　　　　　　　　　≌≌\n"
"　　　　　　　　≌≌≌≌≌≌≌≌≌≌≌≌≌≌≌≌≌\n"
        ]));


        set("exits", ([ /* sizeof() == 1 */
  "enter" : __DIR__"tianls2.c",
  "southdown" : __DIR__"hongshengt.c",
]));
		set("objects", ([
		__DIR__"npc/ming-ku" : 1,
		__DIR__"npc/ming-nan" : 1,
		]));
         set("cost", 2);
        setup();  
}

void init()
{
        add_action("do_kill","kill");
}

int do_kill(string arg)
{
        object ob, ob1, room, me = this_player();

        if ( !arg ) return 0;

        if ( !ob=present(arg, environment(me)) ) return 0;

        if ( ob->query("id") == "ming ku" && me->query("family/family_name") != "大理段家" ) {
           message_vision("$n对著$N喝道：「"+RANK_D->query_rude(ob)+"！今日不是你死就是我活。\n", ob, me);
           if ( ob1=present("ming nan", environment(me)) ) {
				if(!( room = find_object(__DIR__"tianls10")) )
					room = load_object(__DIR__"tianls10");
				if(!objectp(room))
					return notify_fail("ERROR:not found 'tianls10' \n");
                message_vision("$N大惊道：大胆狂徒！竟敢在天龙寺行凶杀人，待我去禀报方丈去！\n", ob1);
                message_vision("$N急急忙忙向寺里跑去。\n", ob1);
                ob1->move(room);
				message("vision","只见明难慌慌张张地跑了进来，脸色十分难看。\n", room);
				me->kill_ob(ob);
				if( !userp(ob) )
				{
					ob->accept_kill(me);
					if (!ob->is_grpfight()) 
                        ob->kill_ob(me);
				}
				me->set_temp("enter_tianlong", 1);
//				me->apply_condition("dlkiller", 100);
				return 1;
           }
           if ( !ob1 ) return 0;
           return 1;
        } 
        if ( ob->query("id") == "ming nan" && me->query("family/family_name") != "大理段家" ) {
           message_vision("$n对著$N喝道：「"+RANK_D->query_rude(ob)+"！今日不是你死就是我活。\n", ob, me);
           if ( ob1=present("ming ku", environment(me)) ) {
				if(!( room = find_object(__DIR__"tianls10")) )
					room = load_object(__DIR__"tianls10");
				if(!objectp(room))
					return notify_fail("ERROR:not found 'tianls10' \n");
                message_vision("$N大惊道：大胆狂徒！竟敢在天龙寺行凶杀人，待我去禀报方丈去！\n", ob1);
                message_vision("$N急急忙忙向寺里跑去。\n", ob1);
                ob1->move(room);
				message("vision","只见明苦慌慌张张地跑了进来，脸色十分难看。\n", room);
				me->kill_ob(ob);
				if( !userp(ob) )
				{
					ob->accept_kill(me);
					if (!ob->is_grpfight()) 
                        ob->kill_ob(me);
				}
				me->set_temp("enter_tianlong", 1);
//				me->apply_condition("dlkiller", 100);
				return 1;
           }
           if ( !ob1 ) return 0;
           return 1;
        } 
}
/*
int valid_leave(object me, string dir)
{
    object *inv;
    mapping myfam, mygen;
    int i;

    myfam = (mapping)me->query("family");
        if( dir=="enter" && !wizardp(me) )
                return notify_fail("一股无形的力量把你推了出来！\n一个洪亮的声音在你耳边响起：老衲暂不接待凡客！施主请回吧。\n");

    if ((!myfam || myfam["family_name"] != "大理段家" ) && dir == "enter") {
        inv = all_inventory(me);
        for(i=sizeof(inv)-1; i>=0; i--)
		if (inv[i]->is_character())
			return notify_fail("你不能带着其他玩家离开这里。\n");
		if(objectp(present("ming ku", environment(me))))
			return notify_fail("明苦拦住你说道：这位" + RANK_D->query_respect(me) + "请回吧，本寺不接待生人。\n");
		else if(objectp(present("ming nan", environment(me))))
			return notify_fail("明难迈步挡在你身前，双手合什说道：阿弥陀佛，这位" + RANK_D->query_respect(me) + "请回吧，本寺不接待生人，还请施主鉴谅。\n");
    }
    return ::valid_leave(me, dir);
}*/

