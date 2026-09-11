// by fire on Dec 12, 1997 deposit.c
#include <sanguo.h>
inherit VERB_OB;
void do_deposit_str(string str)
{
    string *sentence;
    int i;
    int number;
    mixed ss;
    sentence = explode(str, " ");
    i = sizeof(sentence);
    if( i == 1 )
		ss=environment(this_body())->deposit(sentence[0],1);
    else
    {
        if ( i == 2 )
        {
            if( sscanf(sentence[0], "%d", number) == 1)
            {
                if ((number>200000)||(number<0))
				{
					write("你身上没有这么多钱！\n");
					return;
				}
				ss=environment(this_body())->deposit(sentence[1],number);
            }
	    else
		ss=environment(this_body())->deposit("Thisisnothing",1); 
		// this will give a correct deposit format
	}
	else
		ss=environment(this_body())->deposit("Thisisnothing",1);
		// this will give a correct deposit format
    }
	if(!ss)
	write("还是到钱庄存钱比较安全。\n");
}
mixed * query_verb_info() {
    return ({ ({ "STR" }) , ({ "cun"}) });
}
