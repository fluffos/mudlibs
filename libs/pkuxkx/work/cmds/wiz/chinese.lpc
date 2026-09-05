inherit F_CLEAN_UP;

int main(object me, string arg)
{
        string key, chinz;

        if( !arg || arg=="" )
                return notify_fail("指令格式：chinese <英文>==<中文>\n");

        if( sscanf(arg, "%s==%s", key, chinz)==2 ) {
		if (chinz == "null" ||chinz == "none" )
		{
			CHINESE_D->remove_translate(key);
			write( "删除："+key + "\nOk.\n");
			return 1;
			}
		else
		{
			CHINESE_D->add_translate(key, chinz);
			write( key + " == " + chinz + "\nOk.\n");
			return 1;
			}
		
        }
        return 0;
}

int help()
{
        write ( @HELP
指令格式：chinese <英文>==<中文>
          chinese <英文>==none (删除)
HELP
        );
        return 1 ;
}
