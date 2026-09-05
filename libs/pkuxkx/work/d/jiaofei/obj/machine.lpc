inherit ITEM;

int stopped = 0;

int isstopped()
{
    return stopped;
}
int ismachine()
{
	return 1;
}

//寻找所有敌人
int filter_enemy(object ob)
{
	if(userp(ob) && present(ob,environment()))		
	{		
		if(ob->query("jiaofei/tmz/xinren") > 0 || ob->query("mud_age") < 86400)
			return 0;
		else
		{			
			return 1;		
		}
	}
	return 0;
}