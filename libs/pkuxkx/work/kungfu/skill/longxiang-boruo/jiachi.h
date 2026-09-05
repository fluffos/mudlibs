
string* all_jiachi(object me)
{
	mapping buff;
	if (!objectp(me) || !me->query_temp("mizong_jiachi")) return ({ });
	buff = me->query_temp("mizong_jiachi");
	return keys(buff);
}

int buff_full(int pflv, string* buff)
{
	if (pflv>=5) return (sizeof(buff)>=2);
	else return (sizeof(buff)>=1);
}

string show_buff(string* buff)
{
	string allbuff = "";
	int sz;
	sz = sizeof(buff);
	if (sz<=0) return "";
	else {
		for (int i=0; i<sz; i++)
		{
			allbuff += buff[i];
			if (i<(sz-1)) allbuff += "、";
		}
		return allbuff;
	}
}