

#include <ansi.h>
string look_wall()
{
	object ob,me=this_player();
	if (!query("wall")||!stringp(query("wall"))) return "城墙有什么好看的？\n";
	if (!ob=load_object(query("wall"))) return "城墙有什么好看的？\n";
	write(BCYN+HIW+"你向上眺望，看到了：\n"+NOR);
	"/cmds/std/look.lpc"->mudlook_room(me,ob,0);
	message("vision",me->name()+"拼命伸长脖子，向上望着城墙头发呆。\n",environment(me),({me}));
	return "\n";
}


