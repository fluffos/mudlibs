
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "武侯祠");
        set("long", "这里是祭祀诸葛武侯的庙堂，上有杜甫题诗“丞相祠堂何处寻，\n锦官城外柏森森”。你不禁想凭吊(pingdiao)一番。\n");
       
        set("valid_startroom", 1);
        set("exits", ([
               
               "east" : __DIR__"southstreet1",
               "northwest" : __DIR__"baihuatan",
                
                
        ]));
        
        //set("outdoors", "chengdu");
        setup();
   
}

void init()
{
    add_action("do_pingdiao", "pingdiao");
    add_action("do_giveback", "huan");
}

int book()
{
    this_object()->delete("book");
    return 1;
}

int do_giveback()
{
    object me=this_player();
    object book;
    if (!present("yanqing quanpu",me))
    {
        return 0;
    }
    else
    {
        book=present("yanqing quanpu",me);
        destruct(book);
        message_vision("$N把一本燕青拳谱放回到了武侯像后面。\n",me);
        this_object()->delete("book");
        return 1;
    }
}

int do_pingdiao()
{
    object me=this_player();
    object book;
    object ob=this_object();
    if( me->is_busy() )
                return notify_fail("你正忙着呢。\n");
    if ( me->is_fighting())
                return notify_fail("你正忙着呢。\n");
    else
    {
        message_vision("$N躬身对武侯拜祭了下去。\n",me);
        me->add_busy(1+random(2));
		if (load_object("/d/hangzhou/obj/books/book_strategy_6")&&time()-COMBAT_D->query("Strategy_Book_Last_Generate")>3600*8&&me->query("antirobot/deactivity")<=2)
		{
			book=new("/d/hangzhou/obj/books/book_strategy_6");
			book->move(ob);
			message_vision(HBBLU+HIW+"$N突然出现在这里。\n"NOR,book);
			COMBAT_D->set("Strategy_Book_Last_Generate",time());
			return 1;
		}
        if (random(100)>85 && !ob->query("book"))
        {
            book=new("/d/luoyang/obj/yanqingbook");
            tell_object(me,"突然武侯像上掉下了一本手抄本的书籍。\n");
            book->move(this_object());
            ob->set("book",1);
            call_out("book",3600);
            return 1;
        }
        
    }
    return 1;
}

int valid_leave(object me,string dir)
{  
	if (dir=="northwest"||dir=="east")
    {
        if (me->query_temp("jn/step3")&&random(100)>49)
        {
            tell_object(me,"有人在布幔后轻声道：可否到信相寺一唔？\n");
            me->delete_temp("jn/step3");
            me->set_temp("jn/step3a",1);
        }
        
    }
	return ::valid_leave(me, dir);
}