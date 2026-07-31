// chinese_d.c
// A minor chinese-english or english-chinese converter.
// by Annihilator@Eastern.Stories 09-27-93
// adapted for ES2-lib 01-18-95

#include <localtime.h>

#define DICTIONARY DATA_DIR + "chinese"

inherit F_SAVE;

nosave string *c_digit = ({ "零","十","百","千","万","亿","兆" });
nosave string *c_num = ({"零","一","二","三","四","五","六","七","八","九","十"});
nosave string *sym_tien = ({ "甲","乙","丙","丁","戊","己","庚","辛","壬","癸" });
nosave string *sym_dee = ({ "子","丑","寅","卯","辰","巳","午","未","申","酉","戌","亥" });


mapping dict = ([]);

void add_translate( string key, string chinz );
void remove_translate( string key );

void create()
{
	seteuid(getuid());
	restore();
}

void remove() { save(); }

string chinese_number(int i)
{
	int v;
	if( i<0 ) return "负" + chinese_number(-i);
	if( i<11 ) return c_num[i];
	if( i<20 ) return c_num[10] + c_num[i-10];
	if( i<100 ) {
		if( i%10 ) return c_num[i/10] + c_digit[1] + c_num[i%10];
		else return c_num[i/10] + c_digit[1];
	}
	if( i<1000 ) {
		if( i%100==0 )
			return c_num[i/100] + c_digit[2];
		else if( i%100 < 10 )
			return c_num[i/100] + c_digit[2] + c_num[0] + chinese_number(i%100);
		else if( i%100 < 20 )
			return c_num[i/100] + c_digit[2] + c_num[1] + chinese_number(i%100);
		else return c_num[i/100] + c_digit[2] + chinese_number(i%100);
	}
	if( i<10000 ) {
		if( i%1000==0 )
			return c_num[i/1000] + c_digit[3];
		else if( i%1000 < 100 )
			return c_num[i/1000] + c_digit[3] + c_digit[0] + chinese_number(i%1000);
		else
			return c_num[i/1000] + c_digit[3] + chinese_number(i%1000);
	}
	if( i<100000000 ) {
		if( i%10000==0 )
			return chinese_number(i/10000) + c_digit[4];
		else if( i%10000 < 1000 )
			return chinese_number(i/10000) + c_digit[4] + c_digit[0] + chinese_number(i%10000);
		else
			return chinese_number(i/10000) + c_digit[4] + chinese_number(i%10000);
	}
	if( i>=1500000000 )
		return "无数";
	if( i%100000000==0 )
		return chinese_number(i/100000000) + c_digit[5];
	v = i-i/100000000*100000000;
		return chinese_number(i/100000000) + c_digit[5]+"又"+chinese_number(v);
}

string query_save_file() { return DICTIONARY; }

// This is called by to_chinese() simul_efun
string chinese(string str)
{
	if( !undefinedp( dict[str] ) ) return dict[str];
	else return str;
}

void remove_translate( string key )
{
	map_delete( dict, key );
	save();
}

void add_translate( string key, string chinz )
{
	dict[key] = chinz;
	save();
}

void dump_translate()
{
	string *k, str;
	int i;

	str = "";
	k = keys(dict);
	for(i=0; i<sizeof(k); i++)
		str += sprintf("%-30s %s\n", k[i], dict[k[i]]);
	write_file("/CHINESE_DUMP", str);
}

string chinese_date(int date)
{
	mixed *local;

	local = NATURE_D->getTime(date);
      printf("%O",local);
	return sprintf("%s%s年%s月%s日%s时%s刻",
		sym_tien[local[4]%10], sym_dee[local[4]%12],
		chinese_number(local[3]+1),
		chinese_number(local[2]+1),
		sym_dee[local[1]],
		chinese_number(local[0]+1), 
		date);
}

string chtime(int t)
{
string str="";  
int sec,min,hor;        
if ( t<=0 ) return str;
hor = t/3600;
t = t-hor*3600;
if ( t>0 )
        {
        min = t/60;
        t = t-min*60;
        }
if ( t>0 )      
        sec = t;
if ( hor )
        str+= hor+"小时 ";
if ( min )
        str+= min+"分钟 ";
if ( sec )
        str+= sec+"秒";
return str;
}

string flag_number(int num)
{
string str="";
int a,b,c,d,e,f,g,h,i;

if  ( num>2000000000 )
        error("数字大于2,000,000,000,会溢出!\n");

a = num/1000000000;
num-= a*1000000000;

b = num/100000000;
num-= b*100000000;
c = num/10000000;
num-= c*10000000;

d = num/1000000;
num-= d*1000000;

e = num/100000;
num-= e*100000;
f = num/10000;
num-= f*10000;

g = num/1000;
num-= g*1000;

h = num/100;
num-= h*100;
i = num/10;
num-= i*10;

if ( a>0 )
        str+= a+",";
if ( b>0 )
        str+= b+"";
else if ( a>0 )
        str+= "0";
if ( c>0 )
        str+= c+"";
else if ( b>0 || a>0 )
        str+="0";
if ( d>0 )
        str+= d+",";
else if ( a>0 || b>0 || c>0 )
        str+="0,";
if ( e>0 )
        str+= e+"";
else if ( a>0 || b>0 || c>0 || d>0 )
        str+="0";
if ( f>0 )
        str+= f+"";
else if ( a>0 || b>0 || c>0 || d>0 || e>0 )
        str+="0";
if ( g>0 )
        str+= g+",";
else if ( a>0 || b>0 || c>0 || d>0 || e>0 || f>0 )
        str+="0,";
if ( h>0 )
        str+= h+"";
else if ( a>0 || b>0 || c>0 || d>0 || e>0 || f>0 || g>0 )
        str+="0";
if ( i>0 )
        str+= i+"";
else if ( a>0 || b>0 || c>0 || d>0 || e>0 || f>0 || g>0 || h>0 )
        str+="0";
return str+num;
}

int wx_sk(int wx)
{
        float x,y;
        int sk;
        if( wx<=0 )
                return 1;
        if( wx>2100000000 )   
        	return 3000;
        x = to_float(wx);                
	x*= 10;
        y = pow(x,1/3.0);
        sk = to_int(y);
        return sk;
}

varargs string chinese_daoxing(int gain,int flag)
{        
    	int year,day,hour;
    	string str;

    	year=gain/1000;
    	day=(gain-year*1000)/4;
    	hour=(gain-year*1000-day*4)*3;
    	str="";
    	if( flag )
    	{
        	if(year) str=year+"年";
        	if(day) str+=day+"天";
        	if(hour) str+=hour+"时辰";
    	}
    	else
    	{
        	if(year) str=str+chinese_number(year)+"年";
        	if(day) str=str+chinese_number(day)+"天";
        	if(hour) str=str+chinese_number(hour)+"时辰";
    	}
    	return str;
}