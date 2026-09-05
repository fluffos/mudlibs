
string chinese_number(int i)
{
	return CHINESE_D->chinese_number(i);
}

string to_chinese(string str)
{
	return CHINESE_D->chinese(str);
}

 int is_chinese(string str)
  {
      if (!str)
          return 0;

      return pcre_match(str, "^\\p{Han}+$");
  }

string gb_to_utf8(string input)
{
	return input;
}


string utf8_to_gb(string input)
{
	return input;
}

//返回字符串形式的日期时间格式，根据输入模式来确定具体的返回格式
//mode=0，则返回yyyy-mm-dd hh24:mi:ss格式的时间
//mode=1，则返回yyyy-mm-dd格式的时间
//如果time未输入则直接取当前时间
string gctime(int time, int mode)
{
  mixed* lt;
  
  if ( !time )
    lt=localtime(time());
  else
    lt=localtime(time);
  
  if ( !mode )
    return sprintf("%d-%2'0'd-%2'0'd %2'0'd:%2'0'd:%2'0'd", lt[5], lt[4]+1, lt[3], lt[2], lt[1]+1, lt[0]+1);
  else
    return sprintf("%d-%2'0'd-%2'0'd", lt[5], lt[4]+1, lt[3]);
}