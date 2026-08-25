// fight.c
// by fire on April 2 1999
#include <verb.h>
inherit VERB_OB;
mixed direct_fight_str(string str) {
	return 1;
}
mixed do_fight_str(string str)
{
	object o, env;
    	mixed ret;
	o=ENV_LIV(str);
	env = this_body()->query_room();
	ret=env->query("no_fight");

	if( stringp(ret)){
		write(ret); return;
	}
	if(ret==1) {
		write("这儿不是比武的地方。\n");
		return;
	}
	if(!objectp(o)) return;
	if(o==this_body()) {
		write("自己打自己？笑话。\n");
		return;
	}
	if (objectp(o->query_link())){
	    string a_id,b_id;
	    a_id=this_body()->query_primary_id();
            b_id=o->query_primary_id();
	    if(FIGHT_D->get_fight_peer(b_id)!=a_id) {
	      FIGHT_D->set_fight_peer(a_id,b_id);
	      tell(o,this_body()->query_chinese_id()+
		  "想和你比武。如果你同意，就请输入：\n%^RED%^     fight "+a_id+"%^RESET%^\n");
	      write( "因为"+o->query_chinese_id()+"是在线玩家，要比武，必需等对方同意才行。\n");
		return;
			                             }
		}
	ret=FIGHT_D->can_fight(this_body(),o);
}

mixed * query_verb_info()
{
     return ({ ({"STR" }) });
}
