// m_answer.c  by fire on July 20 1998
private mapping answer=([]); 
nomask void clear_answer()
{
  answer=([]);
}
nomask void set_answer(string c_id, function f) 
{
	answer["target"]=c_id;
	answer["fun"]=f;
}
nomask int query_answer(string p_id)
{
	if (answer["target"]==p_id)
		return 1;
	return 0;
}
nomask void answer_answer(object who)
{
	this_object()->targetted_action
		("$N对$t说道：“你说什么我听不懂呀。”\n",who);
                return;
}
nomask void be_answered(object who, string item)
{
	string a_id;
	a_id=(who->query_id())[0];
	if(query_answer(a_id))
	{
                evaluate(answer["fun"],this_object(),who,item);
	}
	else
	{
		this_object()->answer_answer(who);
	}
}
mixed direct_answer_wrd_to_liv(string item,object liv)
{
    return 1;
}
