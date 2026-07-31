//fahongbao.c
//发红包

int main(object me, string arg)
{
	int num, number;
	string msg, type;
	
	//if (! is_root(me) && ! SECURITY_D->valid_grant(me, "(admin)"))
	//	return notify_fail("你没有权限。\n");
		
	if (!arg) {		
		tell_object(me, INPUTTXT("你想发什么红包？"ZJBR"格式(天机点，铜板，灵石，黄金 数量 份数)。","hongbao $txt#")+"\n");
	} else
	if (sscanf(arg, "%s %d %d", type, num, number) ==3) {
		if (type == "铜板")
			type = "balance";
		else
		if (type == "灵石")
			type = "yuanbao";
		else
		if (type == "黄金")
			type = "hj";
		else
		if (type == "天机点")
			type = "tianji1";
			
		else {
			tell_object(me, INPUTTXT("你想发什么红包？"ZJBR"格式(天机点，铜板，灵石，黄金 数量 份数)。","hongbao $txt#")+"\n");
			return 1;
		}
		
		HONGBAO_D->do_fahongbao(me, type, num, number);
	} else {
		tell_object(me, INPUTTXT("你想发什么红包？"ZJBR"格式(铜板、灵石 数量 份数)。","hongbao $txt#")+"\n");
	}
	return 1;
}