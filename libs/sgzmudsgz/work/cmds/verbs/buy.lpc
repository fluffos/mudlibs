// by fire on Dec 12, 1997 buy.c
// ok
inherit VERB_OB;
void do_buy_str(string str)
{
    mixed ss,ret;
    ss=PARASE_D->sep_id_num(str);
        if(!ss) {write("你想买什么？\n"); return 0;}
        ret=environment(this_body())->buy(ss[0],ss[1]);
        if(!ret)
        {
                object room;
                int i,sum;
                object *livs;
                room=this_body()->query_room();
                livs=all_inventory(room);
                sum=sizeof(livs);
                for(i=0;i<sum;++i) {
                        if(livs[i]->is_maker())
                        {
                                livs[i]->to_buy(livs[i],this_body(),str);
				    this_body()->start_busy(2);
                                return;
                        }
                }
                write("这儿不象是能买东西的地方呀。\n");
        }
        else {
	    this_body()->start_busy(2);
        }
}
mixed * query_verb_info() 
{
    return ({ ({ "STR" }) });
}
