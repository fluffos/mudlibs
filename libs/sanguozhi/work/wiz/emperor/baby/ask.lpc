///**************************************************************
// Updated by stefan on 10 Jan 1997 and fire on 23 Dec 1997
/* Do not remove the headers from this file! see /USAGE for more info. */
// ok
//emperor add sleep on 2000.2.28
#include <verb.h>
inherit VERB_OB;
void bkiss(object liv1, object liv2)
{
        liv1->simple_action("$N说道：“好呀！”\n");
        liv1->simple_action("$N轻轻托住烈火的脸，给他一个深情的吻。\n");
}
mixed can_ask_liv_about_wrd(object liv, string str) 
{
        return 1;
}
mixed do_ask_liv_about_wrd(object liv, string item)
{
        string p_act;
        string p_askstr;
		mixed ret;
		ret=this_body()->query_asklist(item,"target");
		if(ret==(liv->query_id()[0]))
		{
			string filename,funname;
			filename=this_body()->query_asklist(item,"filename");
			funname=this_body()->query_asklist(item,"funname");
			call_other(load_object(filename),funname,this_body(),liv);
			return;
		}
        
		p_act=item;
        p_askstr=liv->query_ask_str(item);
	if ( this_body() == liv ) {
		write("你难道自己还不知道？\n");
		return 1;
	}
        if(stringp(p_askstr))
             this_body()->targetted_action(p_askstr,liv);
        else
        switch(item)
        {
                case "name":
                    this_body()->targetted_action(
"$N向$t问到：“请教先生尊姓大名。”\n",liv);
                        break;
                case "here":
                        this_body()->targetted_action(
"$N向$t问到：“在下初到贵宝地，不知这里有些什么风土人情？\n",liv);
                        break;
                case "rumors":
                       this_body()->targetted_action(
"$N向$t问到：“不知最近有没有听说什么消息？\n",liv);
                        break;
                case "bkiss" :
                       this_body()->targetted_action(
"$N向$T问道：“$m小姐，能亲亲我吗？”\n",liv);
                        call_out((: bkiss , liv, this_object() :), 3);
                        return;
/* emperor add */
                case "sleep" :
                       this_body()->targetted_action(
"$N温柔地对$T道：$c，我们行房如何？\n",liv);
                       break;
/* emperor add over */
                case "all" :
                       this_body()->targetted_action(
"$N对$T道：$s生性愚鲁，望$R不吝赐教。\n",liv);
                       break;
                default :                                               
                        this_body()->targetted_action("$N向$t打听关于<"+p_act+">的消息。\n",liv);
        }
        liv->be_asked(this_body(), item);
     return 1;
}
mixed do_ask_str_about_wrd(string str, string item)
{
	object o;
	o=ENV_LIV(str);
	if(!objectp(o)) return;
	do_ask_liv_about_wrd(o,item);
}

mixed * query_verb_info()
{
     return ({ ({"STR about WRD" }) });
}
