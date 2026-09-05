//虚拟的不在线玩家
//by bing
inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;
inherit F_SAVE;

string query_save_file()
{
	
	return read_file("/d/xinfang/temproom");
}


void create()
{
	seteuid(geteuid());

	if (!restore())
		return;			
}


