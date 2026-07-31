// hhs		阴阳合欢散
// 2/9/2k  by emnil

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIB"阴阳合欢散"NOR, ({ "hehuan san","san" }) );
        set("long",HIB"这是血刀老祖秘制的药粉，只需要撒(sa)一点点就能发挥做用。\n"NOR);
        set("unit", "包");
        set("weight", 90);
        set("no_sell",1);
        set("value", 0);
}

void init()
{
        add_action("do_sa","sa");
}

int do_sa(string arg)
{
    object me=this_player() , ob , bb;

	if (!arg) return notify_fail("你要撒谁？\n");

	ob = present(arg, environment(me));
	if (!ob || !living(ob)) return notify_fail("你要撒谁？\n");

	if (!wizardp(me) && ob->query("gender")!="女性" )
		return notify_fail("有没有搞错呀，老祖可不是兔子！\n");
	
	if (!wizardp(me) && (userp(ob) || ob->query("id")!="beauty"))
		return notify_fail("这个女人好象不是老祖要的那个啦！\n");

    bb=present("body guard", environment(me));
    if(!objectp(bb) || bb!=ob->query("guard"))
        bb=present("super guard", environment(me));
    if(objectp(bb) && bb==ob->query("guard"))
		return notify_fail("人家有保镖在呢！你这么干太冒险了吧！\n");

	if( objectp(ob->query("guard")) )
		return notify_fail("hmm，你似乎在利用BUG！\n");

        if (!ob->query("ok"))
		ob->kill_ob(me);
        message_vision(HIB"$N"HIB"嘿嘿阴笑了几声，用指甲向$n"HIB"轻轻弹了点粉沫。\n"MAG"不一会儿，$n"MAG"就满面通红的晕了过去！\n"NOR,me, ob);

	ob->unconcious();
	ob->set("hhs",1);
	ob->set_leader(me);

	return 1;
}
