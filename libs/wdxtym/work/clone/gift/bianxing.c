

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(YEL "变性丹" NOR, ({ "gender", "dan" }) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一颗可以让你变性别的丹药。\n");
                set("value", 5000);
                set("unit", "颗");
                set("only_do_effect", 1);
        }
}

int do_effect(object me)
{
		string msg;
        log_file("static/using", sprintf("%s(%s) eat 变性丹 at %s.\n",
                 me->name(1), me->query("id"), ctime(time())));

        message_vision("$N一仰脖，吞下了一颗" + this_object()->name() + "。\n", me);

		if(me->query("family/family_name") == "少林派" )
			return notify_fail("你还是先离开少林再变性吧。\n");

		if(me->query("family/family_name") == "灵鹫宫" )
			return notify_fail("你还是先离开灵鹫再变性吧。\n");

		if(me->query("family/family_name") == "峨嵋派" )
			return notify_fail("你还是先离开峨嵋再变性吧。\n");

		if(me->query("family/family_name") == "移花宫" )
			return notify_fail("你是移花宫的还敢变性，你想死吗？\n");

		if(me->query("gender") == "男性")
		{
			tell_object(me, HIW "你感觉自己的身体发生了的变化，做女人的感觉真好！\n" NOR);
			me->set("gender","女性");
			me->save();
		}else if(me->query("gender") == "女性")
		{
			tell_object(me, HIW "你感觉自己的身体发生了的变化，做男人的感觉真好！\n" NOR);
			me->set("gender","男性");
			me->save();
		}else if (me->query("gender") == "无性")
		{
				tell_object(me, HIW "请输入你想转变的性别（男性或女性）。\n" NOR);
				input_to("get_select",me);
		}

        destruct(this_object());
        return 1;
}

void get_select(string arg, object me)
{
        string msg;

        if (arg != "男性" && arg != "女性")
        {
                tell_object(me, HIW "请输入“ 男性 或 女性 ”！\n" NOR);
                input_to("get_select",me);
                return;
        }
        if (arg == "男性")
        {
				tell_object(me, HIW "恭喜你重拾男性雄风。\n" NOR);
                me->set("gender","男性");
                me->save();
                return;
        }
        if (arg == "女性")
        {
				tell_object(me, HIG "恭喜你可以成为真正的女人了！\n" NOR);
                me->set("gender","女性");
                me->save();
                return;
        }
        return;

}

int query_autoload() { return 1; }

