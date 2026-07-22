#pragma save_binary
//将衣服身上的action去掉
// tear.c

inherit F_CLEAN_UP;

int main(object me, string arg)
{
        object ob;
        if(!arg) return notify_fail("tear what?\n");
        ob=present(arg,me);
        if(!ob) ob=present(arg,environment(me));
        if(!ob)  return notify_fail("找不到"+arg+"\n");
        return ob->do_tear(arg);
        //if(!ob->do_tear(arg)) return notify_fail(arg+"撕不破\n");
        return 1;
}

int help(object me)
{
	write(@HELP
指令格式：tear 物品

HELP
	);
	return 1;
}

