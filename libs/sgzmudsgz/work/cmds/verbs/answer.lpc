// answer.c
// by fire on July 20, 1998
// ok
#include <verb.h>
inherit VERB_OB;

mixed can_answer_wrd_to_liv(string str,object liv) 
{
        return 1;
}
mixed do_answer_wrd_to_liv(string item, object liv )
{
    string p_act;
    string p_use;
    p_use=this_body()->query_userid();
    p_act=item;
    switch(item)
    {
        case "yes":
		case "是":
			this_body()->targetted_action("$N对$T答道：是。\n",liv);
            break;
        case "no":
		case "不":
			this_body()->targetted_action("$N对$T答道：不。\n",liv);
            break;
        default :                                               
		this_body()->targetted_action("$N对$T答道："+p_act+"\n",liv);
     }
     liv->be_answered(this_body(), item);
     return 1;
}
mixed do_answer_str_to_str(string item, string str )
{
	object o;
	o=ENV_LIV(str);
	if(!objectp(o)) return;
	do_answer_wrd_to_liv(item, o);
}

mixed * query_verb_info()
{       
     return ({ ({"STR to STR" }) });
}
