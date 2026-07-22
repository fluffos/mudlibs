// util.c
#include <ansi.h>
#include <localtime.h>
#include <command.h>

string process_bar(int n)
{
        string sp;
        int start;

        if (n < 0) n = 0; else
        if (n > 100) n = 100;

        sp = "                                                  " NOR;
        if (n == 100)
        {
                sp[22] = '1';
                sp[23] = '0';
                sp[24] = '0';
                sp[25] = '%';
                start = 22;
        } else
        if (n >= 10)
        {
                sp[23] = (n / 10) + '0';
                sp[24] = (n % 10) + '0';
                sp[25] = '%';
                start = 23;
        } else
        {
                sp[24] = n + '0';
                sp[25] = '%';
                start = 24;
        }

        n /= 2;
        if (start > n)
        {
                sp = sp[0..start-1] + HIY + sp[start..<0];
                sp = sp[0..n - 1] + BBLU + sp[n..<0];
        } else
        {
                sp = sp[0..n - 1] + BBLU + sp[n..<0];
                sp = sp[0..start-1] + HIY + sp[start..<0];
        }

        sp = NOR + BCYN + sp;
        return sp;
}

object get_object(string name)
{
        object ob;
        if (ob = find_object(name))
                return ob;

        return load_object(name);
}

// calculate the color char in a string
int color_len(string str)
{
        int i;
        int extra;

        extra = 0;
        for (i = 0; i < strlen(str); i++)
        {
                if (str[i] == ESC[0])
                {
                        while ((extra++, str[i] < 'A' ||
                                         str[i] > 'z' ||
                                         str[i] > 'Z' && str[i] < 'a') && i < strlen(str))
                                i++;
                }
        }
        return extra;
}

// to a appromix time
string appromix_time(int n, int flag)
{
        string s;
        string os;
        int odd;
        int bn;

        if (n <= 0)
                return flag ? "马上就" : "马上";

        bn = 1;
        if (n < bn * 60)
        {
                // bn 单位是秒钟
                s = "秒钟";
                odd = 0;
        } else
        if (bn *= 60, n < bn * 60)
        {
                // bn 单位是分钟
                s = "分钟";
                os = "秒钟";
                odd = n % bn;
                n /= bn;
        } else
        if (bn *= 60, n < 24 * bn)
        {
                // bn 单位是小时
                s = "小时";
                os = "分钟";
                odd = (n % bn) / 60;
                n /= bn;
        } else
        if (bn *= 24, n < 30 * bn)
        {
                // bn 单位是天
                s = "天";
                os = "小时";
                odd = (n % bn) / (60 * 60);
                n /= bn;
        } else
        if (n < 365 * bn)
        {
                // bn 单位是天
                s = "个月";
                os = "天";
                odd = (n % (30 * bn)) / bn;
                n /= 30 * bn;
        } else
        {
                // bn 单位是天
                s = "年";
                os = "个月";
                odd = (n % (365 * bn)) / (bn * 30);
                n /= 365 * bn;
        }

        s = chinese_number(n) + s;
        if (odd)
                s += "零" + chinese_number(odd) + os;

        if (flag) s += "以后";
        return s;
}

string up_case(string arg)
{
        int i;
        for (i = 0; i < strlen(arg); i++)
                if (arg[i] >= 'a' && arg[i] <= 'z')
                        arg[i] = arg[i] - 32;
        return arg;
}


string filter_color(string arg)
{
	arg = replace_string(arg, BLK, "");
	arg = replace_string(arg, RED, "");
	arg = replace_string(arg, GRN, "");
	arg = replace_string(arg, YEL, "");
	arg = replace_string(arg, BLU, "");
	arg = replace_string(arg, MAG, "");
	arg = replace_string(arg, CYN, "");
	arg = replace_string(arg, WHT, "");
	arg = replace_string(arg, HIR, "");
	arg = replace_string(arg, HIG, "");
	arg = replace_string(arg, HIY, "");
	arg = replace_string(arg, HIB, "");
	arg = replace_string(arg, HIM, "");
	arg = replace_string(arg, HIC, "");
	arg = replace_string(arg, HIW, "");
	arg = replace_string(arg, NOR, "");
        arg = replace_string(arg, BOLD, "");
        arg = replace_string(arg, BLINK, "");
        return arg;
}


// trans_color
// raw = 0, only forecolor
// raw = 1, include backround color
// raw = 2, include blink & others
varargs string trans_color(string arg, int raw)
{
        // forecolor
        arg = replace_string(arg, "$BLK$", BLK);
        arg = replace_string(arg, "$RED$", RED);
        arg = replace_string(arg, "$GRN$", GRN);
        arg = replace_string(arg, "$YEL$", YEL);
        arg = replace_string(arg, "$BLU$", BLU);
        arg = replace_string(arg, "$MAG$", MAG);
        arg = replace_string(arg, "$CYN$", CYN);
        arg = replace_string(arg, "$WHT$", WHT);
        arg = replace_string(arg, "$HIR$", HIR);
        arg = replace_string(arg, "$HIG$", HIG);
        arg = replace_string(arg, "$HIY$", HIY);
        arg = replace_string(arg, "$HIB$", HIB);
        arg = replace_string(arg, "$HIM$", HIM);
        arg = replace_string(arg, "$HIC$", HIC);
        arg = replace_string(arg, "$HIW$", HIW);
        arg = replace_string(arg, "$NOR$", NOR);

        if (raw)
        {
                // Background color
                arg = replace_string(arg, "$BBLK$", BBLK);
                arg = replace_string(arg, "$BRED$", BRED);
                arg = replace_string(arg, "$BGRN$", BGRN);
                arg = replace_string(arg, "$BYEL$", BYEL);
                arg = replace_string(arg, "$BBLU$", BBLU);
                arg = replace_string(arg, "$BMAG$", BMAG);
                arg = replace_string(arg, "$BCYN$", BCYN);
        }

        if (raw == 2)
        {
                // special effect
                arg = replace_string(arg, "$U$", U);
                arg = replace_string(arg, "$BLINK$", BLINK);
                arg = replace_string(arg, "$REV$", REV);
                arg = replace_string(arg, "$HIREV$", HIREV);
                arg = replace_string(arg, "$BOLD$", BOLD);
        }

        return arg;
}

// append color after the $N、$n、$w for the string color won't be
// break by the NOR after the name
string append_color(string arg, string default_color)
{
        arg = replace_string(arg, "$N", "$N" + default_color);
        arg = replace_string(arg, "$n", "$n" + default_color);
        arg = replace_string(arg, "$w", "$w" + default_color);
        return arg;
}

// change to english sigh to chinese
//!();:'"?.,
//！（）；：‘“”“”？。，
string chinese_desc(string arg)
{
        arg = replace_string(arg, ",", "，");
        arg = replace_string(arg, "!", "！");
        arg = replace_string(arg, "(", "（");
        arg = replace_string(arg, ")", "）");
        arg = replace_string(arg, ";", "；");
        arg = replace_string(arg, ":", "：");
        arg = replace_string(arg, "'", "‘");
        arg = replace_string(arg, "?", "？");
        arg = replace_string(arg, ".", "。");
        arg = replace_string(arg, "\"", "\" ");
        return arg;
}

// is the string1 be a substring of string2
int is_sub(string s_str, string m_str)
{
        if (! m_str || ! s_str) return 0;
        return strsrch("," + m_str + ",", "," + s_str + ",") != -1;
}

// add a s_str
string add_sub(string s_str, string m_str)
{
        string *slist;
        int i;

        if (! s_str || is_sub(s_str, m_str))
                return m_str;

        slist = explode(s_str, ",");
        slist -= ({ "" });
        for (i = 0; i < sizeof(slist); i++)
                if (! is_sub(slist[i], m_str))
                        if (m_str == 0 || m_str == "")
                                m_str = slist[i];
                        else
                                m_str += "," + slist[i];

        return m_str;
}

// remove a s_str
string remove_sub(string s_str, string m_str)
{
        string *slist;
        string *trilist;

        if (! m_str || m_str == s_str) return 0;
        slist = explode(m_str, ",") - ({ "" });
        trilist = explode(s_str, ",");
        slist -= trilist;
        if (! sizeof(slist)) return 0;
        m_str = implode(slist, ",");
        return m_str;
}

// check the id is legal
int is_legal_id(string id)
{
        int i;

        if (! id) return 0;

        for (i = 0; i < strlen(id); i++)
                if (id[i] < 'a' || id[i] > 'z')
                        return 0;

        return 1;
}

// generate the short id for log
string log_id(object ob, int raw)
{
        string msg;
        if (raw) return sprintf("%-8s", geteuid(ob));

        msg = sprintf("%s(%s)", ob->name(1), geteuid(ob));
        msg = sprintf("%-16s", msg);
        return msg;
}

// generate time
string log_time()
{
        string msg = ctime(time());

        msg = msg[4..6] + "/" + msg[8..9] + "/" +
              msg[20..23] + " " + msg[11..18];
        return msg;
}


string remove_ansi(string str)
{
        string tmp = "";
        int i, j = 0, len;

        if( !stringp(str) ) return "";

        len = strlen(str);

        for( i = 0; i < len; i++ ) {
                if( str[i] == ESC[0] ) {
                        for( j = i; j < len; j++ ) {
                                i++;
                                if( ( str[i] > 'A' && str[i] < 'Z' )
                                 || ( str[i] > 'a' && str[i] < 'z') )
                                 break;
                        }
                }
                else tmp += str[i..i];
        }
        return tmp;
}
/*
type:  1 : 随即
       2 : 高亮
       3 : 暗
back:  1 : 底色
blink: 1 : 闪烁
*/


varargs string random_color(int type, int back, int blink)
{
        string  *color_a  = ({  RED,
                                GRN,
                                YEL,
                                BLU,
                                MAG,
                                CYN,
                                WHT,
                                HIK,
                                HIR,
                                HIG,
                                HIY,
                                HIB,
                                HIM,
                                HIC,
                                HIW
                                });

        string *color_b =   ({  BRED,
                                BGRN,
                                BYEL,
                                BBLU,
                                BMAG,
                                BCYN,
                                HBWHT,
                                BBLK
                                });
        string color;
        int    i;

        switch( type ) {
                case 1 :
                        i = random(15);
                        break;
                case 2 :
                        i = 8+random(7);
                        break;
                case 3 :
                        i = random(8);
                        break;
                default:
                        i = -1;
                        break;
        }

        if( i != -1 ) color = color_a[i];
        else color = "";

        if( back ) {
                int j;
                if( i > -1 && i < 8 ) 
                        color_b -= ({ color_b[i] });
                color += color_b[random(sizeof(color_b))];
        }

        if( blink ) color += BLINK;

        return color;
}


string get_color(string arg)
{
        if( strsrch(arg,BLK)!=-1 ) return BLK;
        if( strsrch(arg,RED)!=-1 ) return RED;
        if( strsrch(arg,GRN)!=-1 ) return GRN;
        if( strsrch(arg,YEL)!=-1 ) return YEL;
        if( strsrch(arg,BLU)!=-1 ) return BLU;
        if( strsrch(arg,MAG)!=-1 ) return MAG;
        if( strsrch(arg,CYN)!=-1 ) return CYN;
        if( strsrch(arg,WHT)!=-1 ) return WHT;
        if( strsrch(arg,HIR)!=-1 ) return HIR;
        if( strsrch(arg,HIG)!=-1 ) return HIG;
        if( strsrch(arg,HIY)!=-1 ) return HIY;
        if( strsrch(arg,HIB)!=-1 ) return HIB;
        if( strsrch(arg,HIM)!=-1 ) return HIM;
        if( strsrch(arg,HIC)!=-1 ) return HIC;
        if( strsrch(arg,HIW)!=-1 ) return HIW;
        return "";
}

//转换需要的
nomask mapping _count(mixed v)
{
	int w_y,y,w,g;
	mapping temp = ([]);
	w_y = y = w = g = 0;
	if( !intp(v) )
	{
		return 0;
	}		
	
	g = v;
	if( g/10000 )
	{
		w+= g/10000;
		g = g%10000;
	}
	if( w/10000 )
	{
		y+= w/10000;
		w = w%10000;
	}
	if( y/10000 )
	{
		w_y+= y/10000;
		y = y%10000;
	}
	temp = ([
		"wanyi" : w_y,
		"yi"	: y,
		"wan"	: w,
		"ge"	: g,
	]);
	return temp;
}

nomask string _query_count2(mixed temp)
{
	int w_y,y,w,g;
	string str,tmp;
	
	if( intp(temp) )
		temp = _count(temp);
	else if( !temp || !mapp(temp) )
		temp = ([
			"wanyi" : 0,
			"yi"	: 0,
			"wan"	: 0,
			"ge"	: 0,
		]);	
	if( undefinedp(temp["wanyi"]) )
		temp["wanyi"] = 0;
	if( undefinedp(temp["yi"]) )
		temp["yi"] = 0;
	if( undefinedp(temp["wan"]) )
		temp["wan"] = 0;
	if( undefinedp(temp["ge"]) )
		temp["ge"] = 0;
		
	w_y = (int)temp["wanyi"];
	y = (int)temp["yi"];
	w = (int)temp["wan"];
	g = (int)temp["ge"];
	str = "";
	
	if( w_y==0 && y==0 && w==0 && g==0 )
		return "0";
	
	if( w_y>0 )
	{
		tmp = w_y+"";
		if( strlen(tmp)==4 )
			str+= sprintf("%c%c%c%c",tmp[0],tmp[1],tmp[2],tmp[3]);
		else if( strlen(tmp)==3 )
			str+= sprintf("%c%c%c",tmp[0],tmp[1],tmp[2]);
		else if( strlen(tmp)==2 )
			str+= sprintf("%c%c",tmp[0],tmp[1]);
		else	str+= sprintf("%c",tmp[0]);
	}	
	if( y>0 )
	{
		tmp = y+"";
		if( strlen(tmp)==4 )
			str+= sprintf("%c%c%c%c",tmp[0],tmp[1],tmp[2],tmp[3]);
		else if( strlen(tmp)==3 )
			str+= (w_y>0?"0":"")+sprintf("%c%c%c",tmp[0],tmp[1],tmp[2]);
		else if( strlen(tmp)==2 )
			str+= (w_y>0?"00":"")+sprintf("%c%c",tmp[0],tmp[1]);
		else	str+= (w_y>0?"000":"")+sprintf("%c",tmp[0]);
	}
	else if( w_y>0 )
		str+= "0000";

	if( w>0 )
	{
		tmp = w+"";
		if( strlen(tmp)==4 )
			str+= sprintf("%c%c%c%c",tmp[0],tmp[1],tmp[2],tmp[3]);
		else if( strlen(tmp)==3 )
			str+= (y>0||w_y>0?"0":"")+sprintf("%c%c%c",tmp[0],tmp[1],tmp[2]);
		else if( strlen(tmp)==2 )
			str+= (y>0||w_y>0?"00":"")+sprintf("%c%c",tmp[0],tmp[1]);
		else	str+= (y>0||w_y>0?"000":"")+sprintf("%c",tmp[0]);
	}
	else if( y>0 || w_y>0 )
		str+= "0000";

	if( g>0 )
	{
		tmp = g+"";
		if( strlen(tmp)==4 )
			str+= sprintf("%c%c%c%c",tmp[0],tmp[1],tmp[2],tmp[3]);
		else if( strlen(tmp)==3 )
			str+= (y>0||w_y>0||w>0?"0":"")+g;
		else if( strlen(tmp)==2 )
			str+= (y>0||w_y>0||w>0?"00":"")+g;
		else	str+= (y>0||w_y>0||w>0?"000":"")+g;
	}	
	else if( w_y>0 || y>0 || w>0 )
		str+= "0000";
	return str;
}

nomask int count_int(mixed num)
{
	string str;
	int v;
	mapping temp;
	if( !num )
		return 0;
	if( intp(num) )
		return num;
	else if( mapp(num) )
		temp = num;
	else	return 0;
	str = _query_count2(temp);
	sscanf(str,"%d",v);
	return v;
}		