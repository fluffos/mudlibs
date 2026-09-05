
//Create by pal
//cometh@tom.com
//2003.10.6
//用来和自建山庄配合，列出玩家当前所买物品。
int main()
{
	object me;
	mapping *item,goods;
	string itemname,str;
	int i;

        me=this_player();
	if( !me->query("selfcreate/havecreated"))
	{
		tell_object(me,"你没有创建自己的山庄。\n");
		return 1;
	}

	item=me->query_temp("selfitem");//selfitem标记
	if( !item || !sizeof(item))
	{
		tell_object(me,"你并没有购买任何物品。\n");
		return 1;
	}
	str="";
	str="你购买了下列物品：\n";
	for(i=0;i<sizeof(item);i++)
	{
		goods=item[i];
		itemname=sprintf("%s(%s)",goods["name"],goods["id"]);
		str+=sprintf("一%s%-30s\n",goods["unit"],itemname);
	}
	tell_object(me,str);
	return 1;
}

