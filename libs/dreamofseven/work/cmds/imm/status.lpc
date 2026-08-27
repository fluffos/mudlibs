// status.c

inherit F_CLEAN_UP;

int main(object me,string arg)
{
	string msg;

	msg = (string)mud_status(arg=="detail" ? 1 : 0);
	if( stringp(msg) ) write(msg);

	return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : status [detail]
 
這個指令可以顯示出目前遊戲的一些相關資料及狀況.
 
HELP
    );
    return 1;
}
 
