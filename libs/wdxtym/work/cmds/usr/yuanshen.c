// time.c

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if(!arg)
	{
		write("升级元神的指令是 yuanshen up");
	}
	else if(arg=="up")
		F_LEVELL->improve_levell(me);

	return 1;
}

