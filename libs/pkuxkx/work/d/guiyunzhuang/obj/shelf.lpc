//Obj:/u/pingpang/obj/table.c
//Made by:pingpang
inherit ITEM;

void create()
{
        set_name("书架", ({ "shelf","shujia","jia"}) );
        set_weight(800); 
		set_max_encumbrance(80000);
        set("no_get", 1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("no_shown",1);
                set("unit", "个");
                set("long", "这是陆庄主平时放书的书架，上面摆着各种武功秘集和武功心法，好像有\n一本是内功心法，你可以用(search)找到它。又堆了许多古玩字画，你可\n以把它拿(na)起来。\n");
                set("value", 100);
	      }
}

void init()
{
    add_action("do_na","na");
}

int do_na()
{
    object me=this_player();
    object thing;
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (me->query("family/family_name") != "桃花岛")
    {
        tell_object(me,"一个声音冷冷对你道：小毛贼，这次我就不追究了，快滚吧。\n");
        return 1;
    }
    if (!me->query("thnewbiejob/jianding/start"))
    {
        tell_object(me,"你想了想，又把古玩字画放回了原处。\n");
        return 1;
    }
    if (me->query_temp("thnewbiejob/jianding/get"))
    {
        tell_object(me,"古玩字画不是被你拿走了吗？\n");
        return 1;
    }
    me->add_busy(1);
    if (random(100)>49)
    {
        thing=new(__DIR__"guwan2");
    }
    else
    {
        thing=new(__DIR__"zihua2");
    }
    thing->set("owner",me->query("id"));
	thing->set("no_sell_in_playershop",1);
    thing->set("陆乘风收集的古玩",1);
	thing->set("no_store",1);
    thing->move(me);
    message_vision("$N拣起了一套"+thing->name()+"。\n",me);
    me->set_temp("thnewbiejob/jianding/get",1);
    return 1;
}