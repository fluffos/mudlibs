// full.c for apprentice
// written by snowman@SJ 29/10/1999

inherit F_CLEAN_UP;
 
int main(object me,string str)
{
	object ob;
        if (!geteuid()) seteuid(getuid());
        if (!str)
                ob = me;
        else	ob = present(lower_case(str), environment(this_player()));
        
        if (!ob) return notify_fail ("这里没有你所要叫醒的人。\n");
        
  	ob->revive();
  	if (wizardp(ob)) ob->reincarnate();

        if (me != ob)
            	message_vision("$N指着$n叫了两声：起来，起来......于是$p就被唤醒了！\n", me, ob);
        else write("你唤醒了自己！\n");
        return 1;
}

int help(object me)
{
        write(@HELP
指令格式: wakeup [玩家ID]
 
 唤醒昏迷或睡觉的玩家。

HELP );
        return 1;
}
