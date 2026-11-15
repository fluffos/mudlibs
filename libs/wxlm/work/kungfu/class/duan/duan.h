// duan.h

int permit_recruit(object ob)
{
	if( ob->query("detach/段氏皇族") || ob->query("betrayer/段氏皇族") )
	{
		command("say 既然离开了我们段家，就不要回来了");
		return 0;
	}
	return 1;
}
