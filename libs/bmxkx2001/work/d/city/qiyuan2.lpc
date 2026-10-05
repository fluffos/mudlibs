//Cracked by Roath
// qiyuan2.c



#include <ansi.h>
#include <room.h>
#include "/d/city/chess_room.h"

inherit ROOM;
string look_book();
void do_back(object ob);
int do_knock(object ob);

void create()
{
	set("short", "棋室");
	set("long", @LONG
这里是茶馆中的棋室之一，正是三五知己高谈阔论，品茶对奕的好地方。室     
内布置简单但也雅致。墙上挂著一幅对联 (duilian)。木桌上面放着象棋棋盘和
棋子，随时可以开始(start)下棋，桌上(table)除了棋具外，还放了一本小册子 
(book)。
LONG
	);
	set("exits", ([
		"south" : "/d/city/chaguan",
        ]));
        set("no_fight", 1);
        set("no_sleep_room",1);
	set("item_desc", ([
		"book" : (:look_book:),
		"table": "一张典雅的桃木小桌，上面放着棋盘和饮茶器具。\n",
		"duilian" : HIG"
	****** ******
	* 香 * * 水 *
	* 分 * * 汲 *
	* 花 * * 石 *
	* 上 * * 中 *
	* 露 * * 泉 *
	****** ******\n\n"NOR,
 	
	]));
	set("no_clean_up", 0);
        setup();
        set("no_user", 1);
}


int do_knock(string arg)
{       
        object me = this_player();
	object waiter;

        if ( (!arg )|| (arg != "table"))
	  {       
	        write("敲什么呀？(knock table)\n");
                return 1;
	  }
        if( (arg == "table") )
	  {     
                if(!(waiter = find_living("chaguan xiaoer")))
                  {
		        waiter = new("/d/city/npc/c_waiter");
		        waiter->move(environment(me));
                  }

                waiter->move(environment(me));
                message_vision("$N伸出两个指头来，敲了敲桌子，茶馆小二跑了过来。\n", me);
		remove_call_out("do_back");
	        call_out("do_back", 20 + random(10), waiter);
                return 1;
	  }
        return 1;
}

void do_back(object ob)
{
  message("vision", 
	  "客官您慢用，小的先退下了。\n", 
	  environment(ob), ({ob}));
  ob->move("/d/city/chaguan");
}

void reset()
{
        ::reset();
        set("no_clean_up", 1);
}
