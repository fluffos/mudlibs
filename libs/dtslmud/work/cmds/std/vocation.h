
string replace_name(string wp)
{
        wp=replace_string(wp,"$HIR$","");
	wp=replace_string(wp,"$HIG$","");
	wp=replace_string(wp,"$HIY$","");
	wp=replace_string(wp,"$HIW$","");
	wp=replace_string(wp,"$HIB$","");
	wp=replace_string(wp,"$HIM$","");
	wp=replace_string(wp,"$HIC$","");
	wp=replace_string(wp,"$GRN$","");
	wp=replace_string(wp,"$RED$","");
	wp=replace_string(wp,"$BLK$","");
	wp=replace_string(wp,"$YEL$","");
	wp=replace_string(wp,"$BLU$","");
	wp=replace_string(wp,"$MAG$","");
	wp=replace_string(wp,"$CYN$","");
	wp=replace_string(wp,"$WHT$","");
        wp=replace_string(wp,"$NOR$","");
        
        return wp;
        
}

int check_legal_name(string name)
{
	int i;
	i = strlen(name);
	if( strlen(name) > 10) 
	{
		write("对不起，你最多只能起五个汉字的名字。\n");
		return 0;
	}
	while(i--) 
	{
		if(name[i] <= ' ') 
		{
			write("对不起，你的中文字不能用控制字元。\n");
			return 0;
		}
		if(i%2 == 0 && !is_chinese(name[i..<0])) 
		{
			write("对不起，请您用「中文」取名字。\n");
			return 0;
		}
	}
	
	return 1;
}

int is_leagel_name(string str)
{
  string name=str;
  
  name=replace_name(name);
  
  return check_legal_name(name);
  
}