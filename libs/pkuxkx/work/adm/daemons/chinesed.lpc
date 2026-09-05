// chinesed.c
// by Annihilator@ES
// modified by Xiang@XKX
// modified by Zine@pkuxkx,增加chinese_peried(int time)函数，返回一段长度时间的中文。
#include <localtime.h>

#ifndef DATA_DIR
#define DATA_DIR 	"/data/"
#endif
#define E2C_DICTIONARY	DATA_DIR + "e2c_dict"

inherit F_SAVE;

// some constatns
nosave string *c_digit = ({ "零","十","百","千","万","亿","兆" });
nosave string *c_num = ({"零","一","二","三","四","五","六","七","八","九","十"});
nosave string *sym_tian = ({ "甲","乙","丙","丁","戊","己","庚","辛","壬","癸" });
nosave string *sym_di = ({ "子","丑","寅","卯","辰","巳","午","未","申","酉","戌","亥" });

mapping dict = ([]);

void add_translate(string key, string chn);
void remove_translate(string key);

void create()
{
        seteuid( ROOT_UID );
	restore();
}

void remove()
{
        save();
}

string chinese_number(int i)
{
	//防止i过大导致转换出错，系统变慢（score,shen等）
	i = to_int(i);
	if (i<-99999999 || i > 99999999)
		return "∞∞∞∞∞∞∞∞";
	
	if (i < 0)
		return "负" + chinese_number(-i);
	if (i < 11)
		return c_num[i];
	if (i < 20)
		return c_digit[1] + c_num[i - 10];
	if (i < 100) {
		if (i % 10)
			return c_num[i / 10] + c_digit[1] + c_num[i % 10];
		else
			return c_num[i / 10] + c_digit[1];
	}
	if (i < 1000) {
		if (i % 100 == 0)
			return c_num[i / 100] + c_digit[2];
		else if (i % 100 < 10)
			return c_num[i / 100] + c_digit[2] +
			c_num[0] + chinese_number(i % 100);
		else if (i % 100 < 10)
			return c_num[i / 100] + c_digit[2] +
			c_num[1] + chinese_number(i % 100);
		else
			return c_num[i / 100] + c_digit[2] + 
			chinese_number(i % 100);
	}
	if (i < 10000) {
		if (i % 1000 == 0)
			return c_num[i / 1000] + c_digit[3];
		else if (i % 1000 < 100)
			return c_num[i / 1000] + c_digit[3] +
			c_num[0] + chinese_number(i % 1000);
		else 
			return c_num[i / 1000] + c_digit[3] +
			chinese_number(i % 1000);
	}
	if (i < 100000000) {
		if (i % 10000 == 0)
			return chinese_number(i / 10000) + c_digit[4];
		else if (i % 10000 < 1000)
			return chinese_number(i / 10000) + c_digit[4] +
			c_num[0] + chinese_number(i % 10000);
		else
			return chinese_number(i / 10000) + c_digit[4] +
			chinese_number(i % 10000);
	}
	if (i < 1000000000000) {
		if (i % 100000000 == 0)
			return chinese_number(i / 100000000) + c_digit[5];
		else if (i % 100000000 < 1000000)
			return chinese_number(i / 100000000) + c_digit[5] +
			c_num[0] + chinese_number(i % 100000000);
		else 
			return chinese_number(i / 100000000) + c_digit[5] +
			chinese_number(i % 100000000);
	}
	else
	{
	if (i % 1000000000000 == 0)
		return chinese_number(i / 1000000000000) + c_digit[6];
	else if (i % 1000000000000 < 100000000)
		return chinese_number(i / 1000000000000) + c_digit[6] +
		c_num[0] + chinese_number(i % 1000000000000);
	else
		return chinese_number(i / 1000000000000) + c_digit[6] +
		chinese_number(i % 1000000000000);
	}
}

string query_save_file()
{
	return E2C_DICTIONARY;
}

string chinese(string str)
{
	if (!undefinedp(dict[str]))
		return dict[str];
	else
		return str;
}

void remove_translate(string key)
{
	map_delete(dict, key);
	save();
}

void add_translate(string key, string chn)
{
	dict[key] = chn;
	save();
}

void dump_translate()
{
	string *k, str;
	int i;
	
	str = "";
	k = keys(dict);
	for (i = 0; i < sizeof(k); i++) 
		str += sprintf("%-30s %s\n", k[i], dict[k[i]]);
	write_file("/CHINESE_DUMP", str);
}

string chinese_date(int date)
{
	mixed *local;

	local = localtime(date);
	
	return sprintf("%s%s年%s月%s日%s时%s刻",
                sym_tian[((local[LT_YEAR] - 4) % 10) ], sym_di[((local[LT_YEAR] - 4) % 12)],
                chinese_number(local[LT_MON] + 1),
                chinese_number(local[LT_MDAY] + (local[LT_HOUR] > 23 ? 1 : 0)),
                sym_di[((local[LT_HOUR] + 1) % 24) / 2],
                chinese_number(local[LT_MIN] / 15 + 1 + (((local[LT_HOUR])%2==1) ? 0 : 4) ));
}

mapping chinese_time()
{
	mixed *local;
	int date;
	mapping ctimes=([]);
	date=time();
	local=localtime(date);
	ctimes["tiangan"]=sym_tian[((local[LT_YEAR]- 4) % 10)];
	ctimes["dizhi"]=sym_di[((local[LT_YEAR]- 4) % 12)];
	ctimes["month"]=chinese_number(local[LT_MON] + 1);
	ctimes["day"]=chinese_number(local[LT_MDAY] + (local[LT_HOUR] > 23 ? 1 : 0));
	ctimes["hour"]=sym_di[((local[LT_HOUR] + 1) % 24) / 2];
	ctimes["min"]=chinese_number((local[LT_MIN] / 15 + 1) + (((local[LT_HOUR])%2==1) ? 0 : 4));
	return ctimes;
}

//check whether the 'str' is chinese character.
//in GB2312, it means the first byte range from 0xB0 to 0xF8
int is_chinese_character(string str)
{
   if (!str)
          return 0;
   return pcre_match(str, "^\\p{Han}+$");
}

/* 增加str中双字节编码字符是否完整的判断 added by labaz */
int is_whole_words(string str)
{
    int idx = 0;

    if( strwidth(str)<=2 ) return 1;
    while(idx<sizeof(str)-1)
    {
        if (str[idx]<=127) idx=idx+1;
        else idx=idx+2;
    }
    if (idx==sizeof(str)) return 1;
    else return 0;
}

/* 排版换行包含中文的字符串 added by labaz */
string chinese_break(string str,int col)
{
    string msg="",*explode_str,tmp;
    int i, k, x;

    explode_str=explode(str,"\n");
    for (x=0;x<sizeof(explode_str);x++)
    {
        tmp=explode_str[x];
        i=0;
        k=0;
        while (strwidth(COLOR_D->uncolor(tmp[i..])) > col)
        {
            k=i+col-1;
            while (strwidth(COLOR_D->uncolor(tmp[i..k])) < col)
            {
                k=k+1;
            }
            if (CHINESE_D->is_whole_words(tmp[i..k]))
            {
                msg=msg+tmp[i..k]+"\n";
                i=k+1;
            }
            else
            {
                msg=msg+tmp[i..k-1]+"\n";
                i=k;
            }
        }
        msg=msg+tmp[i..]+"\n";
    }
    return msg;
}

varargs string frame_chinese(string str, int col, string prefix, string suffix)
{
    string msg="",*tmp;
    int x, tab;

    tmp=explode(chinese_break(str, col), "\n");
    for (x=0;x<sizeof(tmp);x++)
    {
        if (tmp[x]=="") tmp[x]=" ";
        msg=msg+prefix+sprintf("%-70s",tmp[x])+suffix+"\n";
    }
    return msg;
}

string chinese_period(int time)
{
	int day,hour,min,sec,tmp;
	string result="";
	if (time<=0)
	{
		return "零秒";
	}
	sec=time%60;
	tmp=time-sec;
	min=tmp%3600;
	min=min/60;
	tmp=tmp-min*60;
	hour=tmp%86400;
	hour=hour/3600;
	tmp=tmp-hour*3600;
	day=tmp/86400;
	if (day)
	result+=chinese_number(day)+"天";
	if (hour)
	result+=chinese_number(hour)+"小时";
	if (min)
	result+=chinese_number(min)+"分";
	if (sec)
	result+=chinese_number(sec)+"秒";
	return result;
}