inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string key, chinz;

	if( !arg )
		return notify_fail("指令格式：chinese 英文==中文 注意不要有空格。\n");

	if( sscanf(arg, "%s==%s", key, chinz)==2 ) {
		if (chinz == "none") {
			write("删除("+key+")("+to_chinese(key)+")。\n");
			CHINESE_D->remove_translate(key);
		} else {
			CHINESE_D->add_translate(key, chinz);
			write("添加("+key+")(" + chinz + ")。\n");
		}
		return 1;
	}

	return 0;
}

int help()
{
	write ( @HELP
指令格式：chinese 英文==中文|none
HELP
	);
	return 1 ;
}
