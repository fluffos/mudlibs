//  /ludingshan/npc/obj/jing42_2.c 四十二章经之二
// hongdou 98.10.18

#include <ansi.h>
//inherit F_SAVE;
//inherit F_AUTOLOAD;

inherit ITEM;

//int do_tear(string arg);

void init()
{
        add_action("do_tear", "tear");
}

void create()
{
        set_name(CYN"四十二"HIM"章经"NOR, ({"42 jing2","jing2","jing"}));
        set_weight(1000);
	set("no_give",1);
	set("no_put",1);
	set("no_steal",1);
	set("no_drop","你不觉得可惜吗？\n");
	set("no_get",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "\n一本"+HIM+"镶红"+NOR+"旗的四十二章经，封皮(binding)很精致。\n");
                set("unit", "本");
                set("material", "paper");
		set("value",0);
        }
        setup();
}


int do_tear(string arg)
{
        object me,obj;
	string dir;
	me = this_player();
	
        if( !arg || arg=="" ) return 0;

	if((arg=="42 jing2") || (arg=="jing2"))
	{
	    message_vision("$N一下把经书撕得粉碎。\n", this_player());
	    destruct(this_object());
	    return 1;
	}

	if( sscanf(arg, "jing2 %s", dir)==1 ) 
	{
   	   if( dir=="binding" ) {
		if(this_object()->query("hasgot"))
		message_vision("$N将封皮撕开,发现羊皮已经被取走了。\n", this_player());
		else
		{
		message_vision("$N将封皮撕开，几块羊皮掉了下来。\n", this_player());
            	message_vision("$N将羊皮包好，小心收藏起来。\n", this_player());
        	if (!(obj = present("yang pi", me)))
		{
		    obj=new("/u/hongdou/ludingshan/obj/yangpi");
		    obj->move(me);
		}
		me->set("42jing2", 1);
                this_object()->set("hasgot",1);  
		set("long", "\n这是一本普普通通的经书，你从上面学不到什么东西。\n");
		set("no_get",0);
		set("no_give",0);
		set("no_put",0);
		set("no_steal",0);
		set("no_drop",0);
		set("value",20);
		set("no_store",1);
        	}
	}
        else
	{
	message_vision("$N一下把经书撕得粉碎。\n", this_player());
	destruct(this_object());
	}
	return 1;
        }	
}
/*
string query_autoload()
{
        return query("name");
}
*/