//location:/quest/shijienan/give_item.h
//written by bugbug 2002.2.20
//function: give itemp depending on lucky

#define ITEM_PATH "/quest/shijienan/item/"

int give_item(object player,int lucky)
{
	string* item_file_name = get_dir(ITEM_PATH);
	int item_file_number=sizeof(item_file_name),temp;
	object item;
	int exp,kar;


	if( random(lucky) < 31 )
		return 0;
	//Nothing got.
	exp=(player->query("combat_exp")+player->query("daoxing"))/2;
	kar = player->query_kar();
	if(exp > 2100000)
	{
		if(!random(44)||wizardp(player))
		{
			if(!item = "/adm/daemons/Diabloset"->drop())
				error("error occurs when new in diabloset");
			if( ! item->move(player))
			{
				tell_object(player,"只听到轰隆一声"+item->query("name")+"消失在你的眼前!\n");
				destruct(item);
				tell_object(player,"你身上东西太多了，承受不了，真是可惜啊!\n");
				return 0;
			}
			
			CHANNEL_D->do_channel(this_object(),"rumor",HIR+player->query("name")+NOR+HIM"得到一"+item->query("unit")+NOR+HIM"传说中的"+NOR+item->query("name")+NOR"！\n");
		
		}
		else 
		{
			if( ! item = new(ITEM_PATH+item_file_name[random(item_file_number)]) )
				error("error occurs when new in file /quest/shiejienan/item.h");
			
			if( ! item->move(player))
			{
				tell_object(player,"只听到轰隆一声"+item->query("name")+"消失在你的眼前!\n");
				destruct(item);
				tell_object(player,"你身上东西太多了，承受不了，真是可惜啊!\n");
				return 0;
			}
		
			tell_object(player,"你获得了"+item->query("name")+"。\n");
		}
	}
	else 
	{
		if( ! item = new(ITEM_PATH+item_file_name[random(item_file_number)]) )
			error("error occurs when new in file /quest/shiejienan/item.h");
		
		if( ! item->move(player))
		{
			tell_object(player,"只听到轰隆一声"+item->query("name")+"消失在你的眼前!\n");
			destruct(item);
			tell_object(player,"你身上东西太多了，承受不了，真是可惜啊!\n");
			return 0;
		}
	
		tell_object(player,"你获得了"+item->query("name")+"。\n");
	}
	return 1;
}