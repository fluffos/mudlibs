#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIY"古龙精选集"NOR, ({ "gulong book" }) );
            set("no_put", 1);
            set("shenshu", 1);
            set("value", 0);
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
	        
            set("unit", "本");
            set("material", "paper");
            set("long", "一本由神书合并成的卷册，你可以用(chayue)来查阅它。\n");
          }

    setup();
}
void init()
{
   add_action("do_cha","chayue");
}
int do_cha(string arg)
{
	object me,ob;
	int exp,pot,score,i;
	me =this_player();
 	if (!id(arg))
	return notify_fail("你要查什么？\n");

        ob=new(__DIR__"sdan");
        ob->move(me);
        ob=new(__DIR__"sdan");
        ob->move(me);
        ob=new(__DIR__"sdan");
        ob->move(me);
        ob=new(__DIR__"sdan");
        ob->move(me);
        ob=new(__DIR__"sdan");
        ob->move(me);
        ob=new(__DIR__"sdan");
        ob->move(me);
message("channel:chat", HIC"【江湖传闻】"GRN + me->query("name")+"得到六颗"+HIY":" + ob->query("name")+HIG"啦！\n"NOR,users() );
	destruct(this_object());
return 1;
}
