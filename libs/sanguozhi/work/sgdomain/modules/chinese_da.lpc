// Updated by stefan 10 Jan 1997
// chinese_da.c modified by fire 11 Dec 1997
// A minor chinese-english or english-chinese converter.
// by Annihilator@Eastern.Stories 09-27-93
// adapted for ES2-lib 01-18-95
nosave protected string *c_digit = ({ "零","十","百","千","万","亿","兆" });
nosave protected string *c_num = ({"零","一","二","三","四","五","六","七","八","九"
,"十"});
nosave protected string *sym_tien = ({ "甲","乙","丙","丁","戊","己","庚","辛","壬",
"癸" });
nosave protected string *sym_dee = ({ "子","丑","寅","卯","辰","巳","午","未","申","
酉","戌","亥" });
mapping dict = ([]);
void add_translate( string key, string chinz );
void remove_translate( string key );
//void create()
//{
//    ::create();
//}                  // deleted by fire
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
            return c_num[i/100] + c_digit[2] + c_num[0] + chinese_number(i
%100);
        else if( i%100 < 20 )
            return c_num[i/100] + c_digit[2] + c_num[1] + chinese_number(i
%100);
        else return c_num[i/100] + c_digit[2] + chinese_number(i%100);
    }
    if( i<10000 ) {
        if( i%1000==0 )
            return c_num[i/1000] + c_digit[3];
        else if( i%1000 < 100 )
            return c_num[i/1000] + c_digit[3] + c_digit[0] +
chinese_number(i%1000);
        else
            return c_num[i/1000] + c_digit[3] + chinese_number(i%1000);
    }
    if( i<100000000 ) {
        if( i%10000==0 )
            return chinese_number(i/10000) + c_digit[4];
        else if( i%10000 < 1000 )
            return chinese_number(i/10000) + c_digit[4] + c_digit[0] +
chinese_number(i%10000);
        else
            return chinese_number(i/10000) + c_digit[4] + chinese_number(i
%10000);
    }
    if( i<1000000000000 ) {
        if( i%100000000==0 )
            return chinese_number(i/100000000) + c_digit[5];
        else if( i%100000000 < 10000000 )
            return chinese_number(i/100000000) + c_digit[5] + c_digit[0] +
chinese_number(i%100000000);
        else
            return chinese_number(i/100000000) + c_digit[5] +
chinese_number(i%100000000);
    }
        if( i%1000000000000==0 )
            return chinese_number(i/1000000000000) + c_digit[6];
        else if( i%1000000000000 < 100000000000 )
            return chinese_number(i/1000000000000) + c_digit[6] +
c_digit[0] + chinese_number(i%1000000000000);
        else
            return chinese_number(i/1000000000000) + c_digit[6] +
chinese_number(i%1000000000000);
}
string chinese_value (int value)
{
        int gold, silver, coin;
        if( !value )
                return sprintf("一文不值\n");
        else
        {
          gold = value/10000;
          silver = (value%10000)/100;
          coin = value%10000%100;
          if (coin)
              return sprintf("%s%s%s文钱\n",
                gold?chinese_number(gold)+"两金":"",
                silver?chinese_number(silver)+"两银":"",
                chinese_number(coin));
          else if (silver)
              return sprintf("%s%s两银子\n",
                gold?chinese_number(gold)+"两金":"",
                chinese_number(silver));
          else
              return sprintf("%s两金子\n",
                chinese_number(gold));
        }
}
