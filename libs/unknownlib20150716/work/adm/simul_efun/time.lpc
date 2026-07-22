// time.c
// 这两个函数使用不当会立刻当掉,予以保护.
// by Find.

nomask mixed *localtime( int time )
{
if( !intp(time) )
time=0;
if( time<0 )
time &= 0x7fffffff;

	return efun::localtime(time);
}

nomask string ctime(int time)
{
	if(!intp(time))
		return "";
	if( time < 0 )
		time = 0;

	return efun::ctime(time);
}

nomask string cctime(int need) /*by Find.*/
{
	string year = "", seg;
	int week,month,y,d,left,h,m,s;
	string *weeks = ({"星期日","星期一","星期二","星期三","星期四","星期五","星期六"});
	string *monthes = ({"一月","二月","三月",
"四月","五月","六月","七月","八月",
"九月","十月","十一月","十二月"});
	mixed *local;

	if(!intp(need))
		return "";
	if( need < 0 )
		need = 0;
	local = localtime(need);

	week = local[6];
	y = local[5];
	month = local[4];
	d = local[3];
	h = local[2];
	m = local[1];
	s = local[0];

	year += chinese_number((int)(y/1000));
	left = y%1000;
	year += chinese_number((int)(left/100));
	left = left%100;
	year += chinese_number((int)(left/10));
	left = left%10;
	year += chinese_number(left);
	year += "年";
        year = replace_string(year,"零","○");

	if(h<6) seg = "凌晨";
	else if(h<9) seg = "早晨";
	else if(h<12) seg = "上午";
	else if(h<14) seg = "中午";
	else if(h<18) seg = "下午";
	else seg = "晚上";

	if(h>12) h -= 12;

	return sprintf("%s%s%s日 %s %s %s点%s分%s秒",year,monthes[month],chinese_number(d),
		weeks[week],seg,chinese_number(h),chinese_number(m),chinese_number(s));
}
