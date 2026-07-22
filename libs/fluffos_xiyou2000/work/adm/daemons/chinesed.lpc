// cracked by vikee 2/09/2002   vikee@263.net
// chinese_d.c
// A minor chinese-english or english-chinese converter.
// by Annihilator@Eastern.Stories 09-27-93
// adapted for ES2-lib 01-18-95
// xyj date system. - mon@xyj 99/07/22

#include <localtime.h>

#define DICTIONARY DATA_DIR + "chinese"

inherit F_SAVE;

nosave string *c_digit = ({ "零","十","百","千","万","亿","兆" });
nosave string *c_num = ({"零","一","二","三","四","五","六","七","八","九","十"});
nosave string *sym_tien = ({ "甲","乙","丙","丁","戊","己","庚","辛","壬","癸" });
nosave string *sym_dee = ({ "子","丑","寅","卯","辰","巳","午","未","申","酉","戌","亥" });

// mon 99/07/22
nosave int pseudo_day, last_day=-1;
// this is the time of 1996/12/12 GMT, the creation date of xyj world.
// becareful if change this number, as it may break the syncronization
// between the "time" command output and the room day phase description.
nosave int time_0=850348800; 

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
	if( i<1000000000000 ) {
		if( i%100000000==0 )
			return chinese_number(i/100000000) + c_digit[5];
		else if( i%100000000 < 10000000 )
			return chinese_number(i/100000000) + c_digit[5] + c_digit[0] + chinese_number(i%100000000);
		else
			return chinese_number(i/100000000) + c_digit[5] + chinese_number(i%100000000);
	}
		if( i%1000000000000==0 )
			return chinese_number(i/1000000000000) + c_digit[6];
		else if( i%1000000000000 < 100000000000 )
			return chinese_number(i/1000000000000) + c_digit[6] + c_digit[0] + chinese_number(i%1000000000000);
		else
			return chinese_number(i/1000000000000) + c_digit[6] + chinese_number(i%1000000000000);
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

/*
string chinese_date(int date)
{
	mixed *local;

	local = localtime(date);

	return sprintf("%s%s年%s月%s日%s时%s刻",
		sym_tien[(local[LT_YEAR]+6)%10], sym_dee[(local[LT_YEAR]+10)%12],
		chinese_number(local[LT_MON]+1),
		chinese_number(local[LT_MDAY] + (local[LT_HOUR]>23? 1 : 0)),
		sym_dee[(local[LT_HOUR]%24)/2],
		chinese_number(local[LT_HOUR]%2 * 2 + local[LT_MIN]/30 + 1) );
}
*/

string chinese_date(int time)
{
    int year, month, day, hour2, quarter;
    
    if(time<=time_0)
	time=0;
    else 
	time-=time_0;

    year=time/86400;
    time%=86400;
    month=time/7200;
    time%=7200;
    day=time/1440;
    time%=1440;
    hour2=time/120;  // this is one 时辰(two hours).
    time%=120;
    quarter=time/30; // this is one quarter of a 时辰.
    
    if(day!=last_day) {
	last_day=day;
	pseudo_day=day*6;
    }
    
//    write(sprintf("%s\n%s\n%d\n",
//		ctime(time_0),ctime(0),time()));
    return sprintf("西游%s年%s月%s日%s时%s刻",
	    chinese_number(year+1),
	    chinese_number(month+1),
	    chinese_number(pseudo_day+1),
	    sym_dee[hour2],
	    chinese_number(quarter+1));
}
