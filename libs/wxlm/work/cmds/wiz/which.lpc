inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string f;
       if (! SECURITY_D->valid_grant(me, "(wizard)"))  
	      return 0;  
	if( !arg ) return notify_fail("指令格式：which <指令>\n");

	if( f = me->find_command(arg) ) {
		write(f + "\n");
		return 1;       
	}
	write("你的指令路径中没有这个指令，请试试 localcmds 这个指令。\n");
	return 1;
}

     
