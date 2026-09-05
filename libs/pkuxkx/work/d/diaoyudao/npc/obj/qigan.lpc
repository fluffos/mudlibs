//  /d/diaoyudao/obj/qigan.c  旗杆
//  hongdou 98.10.07

#include <ansi.h>

inherit ITEM;

void create()
{
	object gan;
        set_name("旗杆", ({ "qi gan","qigan","gan"}) );
        set_weight(80000); 
		set_max_encumbrance(80000);
        set("no_get", 1);
	set("no_give",1);
	set("no_drop",1);
	set("no_steal",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
           set("no_shown",1);
           set("prep", "under");
           set("unit", "根");
           set("long", "这是一根立在中军大帐门前的旗杆，上面飘扬着一面旗子。
你向旗杆上一看不禁大怒，上面居然挂着一面东洋旗。\n");
	   }
	setup();
}


void init()
{
      add_action("do_climb", "climb");
}


int do_climb(string arg)
{
    object ob,gan;
    if (!id(arg)) return notify_fail("你要往哪儿爬？\n");
    else
    {
	if (!(ob = present("shuai qi", this_player())) || (this_object()->query_temp("挂")) )
        {
	    message_vision("\n$N轻松地爬上了旗杆，做了几个高难度动作，然后跳了下来。\n",this_player());
	    return 1;
	}
	message_vision(HIY"\n$N敏捷地爬上旗杆，撤下东洋旗，将一面帅旗挂了上去，随后飘然落地。\n"NOR,this_player());
	tell_object(this_player(),HIC"\n你的声望增加了！\n"NOR);
	this_player()->add("prestige",(random(10)+5));
	this_object()->set_temp("挂",1);
	this_object()->set("long", "这是一根立在中军大帐门前的旗杆，上面飘扬着一面旗子。
你看到旗上写着一个斗大的：“韦”字，虽然破旧，但仍显得气势威严。\n");
	destruct(ob);
	return 1;
    }
}

