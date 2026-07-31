#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(HIG"金庸全集"NOR, ({ "jin book" }) );
            set("no_put", 1);
            set("value", 0);
            set("shenshu", 1);
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
	        
            set("unit", "本");
            set("material", "paper");
            set("long", "一本由神书合并成的卷册，你可以用(chayue)来查阅它。另外如果你有。。。的话，可以用(try)试试\n");
          }

    setup();
}
void init()
{
   add_action("do_cha","chayue");
   add_action("do_try","try");
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
int do_try(string arg)
{
	object me,newbook,ob;
	me = this_player();
 	if (!id(arg))
	return notify_fail("你要试什么？\n");

	newbook =new(__DIR__"bestbook");

    if (!(ob = present("gulong book", me))
        )
	tell_object(me,"书好象没齐.\n");
   else{
        if( ob->query("ownmake"))
	return notify_fail("这里面有假货吧。\n");
        if( !ob->query("shenshu"))
	return notify_fail("这里面有假货吧。\n");
        if(userp(ob))
	return notify_fail("这里面有假货吧。\n");
        if( ob->is_character() || ob->is_corpse() )
	return notify_fail("这里面有假货吧。\n");
        message_vision("$N试着把两本最强的神书重新组合成一本，不料竟然成功了。\n", me);
	newbook->move(me);
	destruct(present("gulong book",me));
	destruct(this_object());}return 1;
}
