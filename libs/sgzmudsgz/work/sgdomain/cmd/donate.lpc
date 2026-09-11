// donatete.c
// by fire on August 14, 1998
string s_ret;
string p_where;
int i_amt;
void confirm_donate(mixed p_input)
{
        string my_id;
        my_id=this_body()->query_id()[0];
        if(p_input=="yes")
                (EV_DONATE)->donate(my_id,p_where,i_amt);
        else
                write("这种事得慎重考虑考虑。\n");
        this_user()->modal_pop();
}
void start(string arg)
{
        int my_id,task_id;
        int* my_task;
	string p_amt;
	int n_bank,n_salary;
        my_id=this_body()->query_id()[0];
        if(!CHAR_D->get_char(my_id,"nation"))
        {
                write("等你混了个一官半职之后，再考虑捐赠不捐赠吧。\n");
                return;
        }
if(CHAR_D->get_char(my_id,"ranknation")==R_KING) {
    write ("身为一国之主怎么能向自己捐钱呢？还是多考虑考虑百姓吧。\n");

    return;
}
	if(!arg)
		arg="";
	if(sscanf(arg,"%s %s",p_where,p_amt)!=2)
	{
		p_amt=arg;
		p_where="here";
	}
	i_amt=to_int(p_amt);
	if((i_amt<5)||((p_where!="here")&&(p_where!="nation")))
	{
                write("用法错误！");
                write("用 cmd help donate 查看详细帮助。\n");
                return;
        }
	n_bank=this_body()->query_amt_money("bank")/10000;
	n_salary=CHAR_D->get_char(my_id,"gold");
	if(i_amt>(n_bank+n_salary))
	{
		write("你帐户上没有那么多金可以捐赠，请用money查帐。\n");
                return;
	}
        write("你决定了要捐赠吗？如果决定了请输入yes。\n");
        this_user()->modal_push((: confirm_donate :),
                               "",0,0);
}
