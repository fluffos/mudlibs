// leave.c 
// by fire on August 29, 1998
// used for player char to risign a position
void confirm_leave(mixed p_input)
{
	string my_id;
	mixed ret;
	my_id=this_body()->query_id()[0];
	if(p_input=="yes")
		ret=(EV_LEAVE)->leave(my_id);
	else
		write("这个问题是需要慎重考虑。\n");
	this_user()->modal_pop();
	if(stringp(ret)) write(ret);return; 
}
void start(string arg)
{
        int my_id;
        my_id=this_body()->query_id()[0];
        if(!CHAR_D->get_char(my_id,"nation"))
        {
                write("你现在在何地任职呀？！\n");
                return;
        }
	write("你决定了要弃官不干了吗？决定了的话请输入yes。\n");
	this_user()->modal_push((: confirm_leave :),
                               "",0,0);
}