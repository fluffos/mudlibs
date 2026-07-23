#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIR"无字神书"NOR, ({ "shenshu king" }) );
            set("no_put", 1);
            set("shenshu", 1);
            set("value", 0);
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
	        
            set("unit", "本");
            set("material", "paper");
            set("long", "神书中的神书，你可以用(chayue)来查阅它。\n");
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
        ob=new(__DIR__"sdan");
        ob->move(me);
        ob=new(__DIR__"sdan");
        ob->move(me);
        ob=new(__DIR__"sdan");
        ob->move(me);
        ob=new(__DIR__"sdan");
        ob->move(me);
i=random(6);
message("channel:chat", HIC"【江湖传闻】"GRN + me->query("name")+"完成了究极任务，到十六颗"+HIY":" + ob->query("name")+HIG"啦！\n"NOR,users() );
	if (i>4) {
        if ( me->query("per")< 41)
        {
	me->add("per",1);tell_object(me,HIM"以及一点容貌。\n"NOR);
        }
	}
	else if (i>3) {
        if ( me->query("dex")< 31)
        {
	me->add("dex",1);tell_object(me,HIM"以及一点身法。\n"NOR);
	}
	}
	else if(i>2)	{
        if ( me->query("str")< 31)
	{
	me->add("str",1);tell_object(me,HIC"以及一点臂力。\n"NOR);
	}
	}
	else if(i>1)	{
        if ( me->query("int")< 31)
	{
	me->add("int",1);tell_object(me,HIR"以及一点悟性。\n"NOR);
	}
	}
	else if(i>0)	{
        if ( me->query("con")< 31)
	{
	me->add("con",1);tell_object(me,HIM"以及一点根骨。\n"NOR);
	}
	}
	else {
        if ( me->query("kar")< 41)
	{
	me->add("kar",1);tell_object(me,HIM"以及一点福缘。\n"NOR);
	}
	}
        ob=new("/clone/box/book/book"+(random(12)+1));
        ob->move(me);
message("channel:chat", HIC"【江湖传闻】"GRN + me->query("name")+"得到"+HIR"失落的武林密籍:" + ob->query("name")+HIG"啦！\n"NOR,users() );
	destruct(this_object());
return 1;
}
