#include <ansi.h>
inherit __DIR__"song_officer";
#include "/d/song/tasks/taiyiju.h"
void create()
{
	call_out("npc_to_player",1,"太医局丞",40,-1);
	::create();
}

int dest(object book)
{
	if(book)
	destruct(book);
	return 1;
}

int accept_object(object me, object book)
{
    if (me->query_temp("songtasks/taiyiyuan/task")!=1)
        return notify_fail("我说过要你帮忙吗？\n");
	if (book->query("drugcode")!=me->query_temp("songtasks/taiyiyuan/target"))
	    return notify_fail("你找回来的是"+me->query_temp("songtasks/taiyiyuan/drug")+"吗？\n");
	message_vision("$N接过$n手里的"+book->query("name")+"，放在鼻边嗅嗅，高兴地道：不错不错，就是它了。\n",this_object(),me);
	me->add_busy(1);
	call_out("dest",1,book);
    me->set_temp("songtasks/taiyiyuan/1/finish",1);
	tell_object(me,"你觉得"+this_object()->name()+"兴奋得有点忘乎所以了，都把你的奖励忘了，还是提醒他一下吧(ask finish)。\n");
	return 1;
}