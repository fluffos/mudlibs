#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIR "十香软筋散" NOR, ({"shixiang ruanjinsan", "san"}));
        set_weight(1000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "小包");
                set("no_get", 1);
                set("no_sell",1);
		set("no_drop", 1);
                set("no_steal",1);
        }
       setup();
}

void init()
{ 
	if (!userp(this_player())) return;
	add_action("do_fu","fu");
        add_action("do_action", ({"nick", "describe", "sj", "chat", "chat*", "rumor", "rumor*", "party", "party*",
		"new", "new*", "say", "to", "set",
		"mm", "emote", "shout", "alias", "quit", "post", "ask", "tell", "reply", "whisper", "team","group","irc",}));
	call_out("drop",600);
}

int do_fu(string arg)
{
        object me, ob;
	me=this_player();

        if( !arg || !objectp(ob = present(arg, environment(me))) 
        || !ob->is_character() || ob == me)
                return notify_fail("虽然看起来很好吃，还是小心点吧。\n");
        if (ob->query("id") != me->query_temp("zhao/targetid") ||
            ob->query("name") != me->query_temp("zhao/target"))
                return notify_fail("他不是你的对象。\n");
        if (living(ob))
                return notify_fail("别太明目张胆了。\n");
        
        message_vision(HIR"$N将一小包十香软筋散全都让$n服下了！\n"NOR, me, ob);
        ob->apply_condition("ruanjin_poison",10);
        destruct(this_object());
        return 1;
}

int do_action(string arg)
{
//   if(!wizardp(this_player())) {
   write("你还是小心完成任务吧。\n");
   return 1;
// }
}

void drop()
{
  object me = this_player();
  if (!me) return;
  message_vision(HIY"$N一摸口袋，似乎少了什么东西。\n",me);
  me->delete_temp("zhao");
  destruct(this_object());
}
