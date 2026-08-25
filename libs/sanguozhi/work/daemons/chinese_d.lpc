// Updated by stefan 10 Jan 1997
// added s_digit by tset 30 Nov 1998
// chinese_d.c
// A minor chinese-english or english-chinese converter.
// by Annihilator@Eastern.Stories 09-27-93
// adapted for ES2-lib 01-18-95

#include <localtime.h>
#include <log.h>

inherit M_DAEMON_DATA;

nosave protected string *c_digit = ({ "零","十","百","千","万","亿","兆" });
nosave protected string *c_num = ({"零","一","二","三","四","五","六","七","八","九","十"});
nosave protected string *s_digit = ({"①","②","③","④","⑤","⑥","⑦","⑧","⑨","⑩"});
nosave protected string *k_digit = ({"○","⑴","⑵","⑶","⑷","⑸","⑹","⑺","⑻","⑼","⑽","⑾","⑿","⒀","⒁","⒂","⒃","⒄","⒅","⒆","⒇"});
nosave protected string *sym_tien = ({ "甲","乙","丙","丁","戊","己","庚","辛","壬","癸" });
nosave protected string *sym_dee = ({ "子","丑","寅","卯","辰","巳","午","未","申","酉","戌","亥" });


mapping dict = ([]);

void add_translate( string key, string chinz );
void remove_translate( string key );

void create()
{
    ::create();
}

string * s_array() { return s_digit; }

string chinese_number2(int i) {
    if( i < 1 || i > 10 ) return "Ⅹ";
    else return(s_digit[i-1]);
}

string chinese_number3(int i)
{
    if( i < 0 || i > 20 ) return "Ⅹ";
    else return(k_digit[i]);
}

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


// This is called by to_chinese() simul_efun
private string chinese(string str)
{
    if( !undefinedp( dict[str] ) ) return dict[str];
    else return str;
}

void remove_translate( string key )
{
  map_delete( dict, key );

  LOG_D->log(LOG_FILE_CHINESE, sprintf("%s删除中文对应 %s 于%s\n",
    this_player()->short(), key, CHINESE_D->chinese_time(time()))
  );
  save_me();
}

void add_translate( string key, string chinz )
{
    dict[key] = chinz;

    LOG_D->log(LOG_FILE_CHINESE, sprintf("%s设定 %s 对应到中文 %s 于%s\n",
      this_user()->short(), key, chinz, CHINESE_D->chinese_time(time()))
    );
   save_me();
}

mapping query_translate()
{
  if( !undefinedp( dict )) return dict;
  else return ([]);
}

// 中式的时间
string chinese_date(int date)
{
    mixed *local;

    local = localtime(date);

    return sprintf("%s%s年%s月%s日%s时",
        sym_tien[local[LT_YEAR]%10], sym_dee[local[LT_YEAR]%12],
        chinese_number(local[LT_MON]+1),
        chinese_number(local[LT_MDAY] + (local[LT_HOUR]>23? 1 : 0)),
        sym_dee[local[LT_HOUR]/2]);
        // chinese_number((local[LT_MIN]+1)%2 * 2 + local[LT_MIN]/30 + 1));
}

// 中文的时间
string chinese_time(int date)
{
        mixed *local;
    int   hour, min;
    string  msg;

        local = localtime(date);
        hour  = local[LT_HOUR];
    min = local[LT_MIN];

        msg = sprintf("%s年%s月%s日",
                chinese_number(local[LT_YEAR]),
                chinese_number(local[LT_MON]+1),
                chinese_number(local[LT_MDAY])
          );
    if ( (hour>12) )
      msg += "下午"+chinese_number(hour-12)+"时";
        else msg += "上午"+chinese_number(hour)+"时";
        if (min==0)
      msg += "正";
    else
      msg += chinese_number(min)+"分";

    return msg;
}

// 转换时间区间为几天几小时几分几秒
string chinese_period(int sec)
{
  mixed *local;
  string msg;
  int    day, hour, min;

  if(sec==0) return c_digit[0];
  day = sec/86400;
  sec = sec % 86400;
  hour = sec/3600;
  sec = sec % 3600;
  min = sec / 60;
  sec = sec % 60;
  msg = "";
  if (day>0) msg += chinese_number(day)+"天";
  if (hour>0) msg += chinese_number(hour)+"小时";
  if (min>0) msg += chinese_number(min)+"分";
  if (sec>0) msg += chinese_number(sec)+"秒";

  if ((msg != "")&&(min||sec)) msg += "钟";
  return msg;
}

string chinese_value (int value)
{
        int gold, silver, coin;

        if( !value )
                return sprintf("一文不值");
        else
        {
          gold = value/10000;
          silver = (value%10000)/100;
          coin = value%10000%100;

          if (coin)
              return sprintf("%s%s%s文钱",
                gold?chinese_number(gold)+"两金":"",
                silver?chinese_number(silver)+"两银":"",
                chinese_number(coin));
          else if (silver)
              return sprintf("%s%s两银子",
                gold?chinese_number(gold)+"两金":"",
                chinese_number(silver));
          else
              return sprintf("%s两金子",
                chinese_number(gold));
        }
}
