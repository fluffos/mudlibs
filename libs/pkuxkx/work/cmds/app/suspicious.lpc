

inherit  F_CLEAN_UP;

int  listing(object  who)
{
	int potstr, potint, potcon, potdex;
	int potkar, potper, potspi;

	potstr = (int)who->query("str");
	potint = (int)who->query("int");
	potcon = (int)who->query("con");
	potdex = (int)who->query("dex");
	
	potkar = (int)who->query("kar");
	potper = (int)who->query("per");
	potspi = (int)who->query_spi();
	
	if ( potstr>=50 || potint>=50 || potcon>=50 || potdex>=50 
		|| potkar>=50 || potper>=50 || potspi>=50
		|| (potstr+potint+potcon+potdex)>=190
		|| (potkar+potper+potspi)>=144 )
	{
		write  (sprintf("  %-30s  exp:%-10d  age:%-3d  str:%2d/int:%2d/con:%2d/dex:%2d   kar:%2d/per:%2d/spi:%2d\n",
			who->query("name")+"("+who->query("id")+ ")", (int)who->query("combat_exp"), (int)who->query("age"), 
			potstr , potint	, potcon , potdex , potkar , potper , potspi));
		return 1;
	}
	return 0;
}

mixed  main(object  me,  string  arg,  int  remote)
{
	object  *ulist;
	int  i, c = 0;

	write("查找属性可疑的在线玩家......\n");
	ulist  =  users();
	i  =  sizeof(ulist);
	while  (i--)  {
//		if (wizardp(ulist[i])) continue;
		c += listing(ulist[i]);
	}
	if (c>0) 
		write("共计 "+c+" 个可疑玩家。\n");
	else
		write("没有发现可疑玩家。\n");
	return  1;
}

int  help  (object  me)
{
                write(@HELP
指令格式  :  suspicious
  
可查看有哪些在线玩家的先天属性比较可疑。
  
  
HELP
);
                return  1;
}
