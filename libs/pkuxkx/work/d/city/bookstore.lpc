// 书肆
// edit: by zine Oct 10 2010

inherit ROOM;
#include <ansi.h>



void create()
{
	set("short", "天月书肆");
	set("long", @LONG
这里是一家书肆，专卖各类人物的传记。一块招牌(zhaopai)挂在门前。一
个老掌柜在忙前忙后。
LONG
	);
	set("exits", ([ 
        "east" : __DIR__"shuyuan",
	]));
    set("item_desc", ([
		"zhaopai" : "天月书肆，本店代为发行(yin)已有各类私人书籍。\n", 
	]));
    set("no_fight",1);
    set("objects", ([
	    __DIR__"npc/bookseller" : 1,
        ]));
	setup();
	call_out("change_book",3600);
}

int change_book()
{
	object *sellers;
	int i;
	sellers=children("/d/city/npc/bookseller");
	for (i=0;i<sizeof(sellers);i++)
	{
		sellers[i]->set_vendor();
	}
	remove_call_out("change_book");
	call_out("change_book",3600);
	return 1;
}

void init()
{
    
    add_action("do_publish",({"yin"}));
    add_action("do_zeng",({"zeng"}));
	
}

int do_zeng(string arg)
{
    object me=this_player();
    object receiver;
    object book;
    if (me->is_busy() || me->is_fighting())
    {
        tell_object(me,"你正忙着哪！\n");
	    return 1;
    }
    if (me->query("personalbook/number")<=0)
    {
       tell_object(me,"你在这里付印的十本传记都已经赠出去了。”\n");
       return 1;
    }
    else
    {
        
        if (!arg)
	    {
		    tell_object(this_player(),"你要赠书给谁？\n");
		    return 1;
	    }
        else
	    {
		    receiver=find_player(arg);
		    if(objectp(receiver))
		    {
                book=new(__DIR__"npc/books/"+me->query("id")+"book");
			    book->move(receiver);
                me->add("personalbook/number",-1);
                me->add_busy(1);
                tell_object(me,"你赠送了一本人物传记给"+receiver->query("name")+"。\n");
                tell_object(receiver,me->query("name")+"赠送了一本人物传记给你。\n");
		        return 1;
            }
            else
            {   
                tell_object(me,"你的朋友现在不在。\n");
                return 1;
            }
        }
    }
}

int do_publish()
{
    object me=this_player();
    object book;
    if (me->query("repute")<10000000 && me->query("score")<10000 && me->query("combat_exp")<100000000)
    {
        tell_object(me,"你在江湖上只是一个无名小卒，出版了传记也没人看呀！\n");
        return 1;
    }
    if (me->query("balance")<1000000)
    {
        tell_object(me,"发行私人书籍需要一百两黄金，我看你的存款还不够。");
        return 1;  
    }
    else
    {
        if (book=find_object(__DIR__"npc/books/"+me->query("id")+"book"))
        {
            book=new(__DIR__"npc/books/"+me->query("id")+"book");
            book->move(me);
            tell_object(me,"书局掌柜道：“已经帮你付印了十本传记，你可以赠(zeng)给你的朋友。”\n");
            tell_object(me,"书局掌柜道：“额外一本是我特别赠给你样书，不要钱的。”\n");
            me->add("personalbook/number",10);
            me->add("balance",-1000000);
            return 1;
        }
        else
        {
            tell_object(me,"你要付印的书写好了吗，我这里没有任何记录？\n");
            return 1;
        }
    }
}

