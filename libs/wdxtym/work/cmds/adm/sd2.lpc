// study.c

#include <skill.h>
#include <command.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object book, env = environment(me);

	if (! arg)
		return notify_fail("你要读什么？\n");

	if (me->is_busy())
		return notify_fail("你现在正忙着呢。\n");

	if (me->is_fighting())
		return notify_fail("你无法在战斗中专心下来研读新知！\n");

	if (environment(me)->query("no_learn") || environment(me)->query("no_study"))
		return notify_fail("你无法在这个地方安心读书。\n");

	if (! objectp(book = present(arg, me)))
		return notify_fail("没这本书可读啊？\n");

	if (! mapp(book->query("skill")))
		return notify_fail("你无法从这样东西学到任何东西。\n");

	if (!me->query_skill("literate", 1))
		return notify_fail("你是个文盲，先学点文化(literate)吧。\n");

	message("vision", me->name() + "开始专心地研读" + book->name() + "。\n", environment(me), me);

	me->set("book_skill/"+book->query("skill/name"),1);
	me->delete("afk");
	me->set("afk/room", env);
	me->set("afk/book", book);
	me->set("afk/file", "dushu");
	return 1;
}

int help(object me)
{
	write( @HELP
指令格式: study|du <物品名称>

这个指令使你可以通过阅读秘笈或其他物品自学某些技巧, 但前提
是: 你不能是个『文盲』。

see also : learn
HELP );
	return 1;
}
