// gini.c 
// this cmd is used to call gini
#include <mudlib.h>
#include <daemons.h>
#include <sanguo.h>
inherit CMD;

int can_call_gini()
{string area;
if (wizardp(this_body())) return 1;
area = (this_body()->query_room())->get_area();
if ((area=="huayin")||(area=="wiz_area")) return 1;
else return 0;

}

private void main(string arg)
{
	string g_type,p_id;
	object o,lamp;
	string cmd,para;
	int is_new=0;
        lamp=present("gini lamp",this_body());
	if(!arg) arg="";
        if(!objectp(lamp)) {
            this_body()->other_action("$N喃喃自语，又蹦又跳，向发了疯一样，不知在干什么。\n");
            write("你没有神灯，召不来精灵。\n");
	    return;
        }
        if (!can_call_gini())
           {
           write("现在只有在华阴村才能呼唤自己的宠物!\n");
           return;
           }
	g_type=this_body()->get_gini();
	if(!sizeof(g_type)){
	   g_type="gini";
	   this_body()->set_gini(g_type);
	}
	p_id=this_body()->query_primary_id();
	//p_id+=" gini";
	p_id+=" ";
	p_id+=g_type;
	
	o=CHAR_D->find_char(p_id);
	if(!objectp(o)) {
		CHAR_D->add_char(p_id);
		CHAR_D->set_char(p_id,"name",GINI_D->get_msg(g_type,"name"));
		CHAR_D->set_char(p_id,"is_tmp",1);
		CHAR_D->set_char(p_id,"body","gini");
		CHAR_D->set_char(p_id,"master",this_body()->query_primary_id());
		CHAR_D->set_char(p_id,"g_type",g_type);
		CHAR_D->set_char(p_id,"type",0);
		CHAR_D->set_char(p_id,"gender",to_int(GINI_D->get_msg(g_type,"gender",0)));
		CHAR_D->put_char(p_id,file_name(this_body()->query_room()));
		o=CHAR_D->find_char(p_id);
		o->my_call();
		o->my_do("follow "+this_body()->query_primary_id());
		is_new=1;
		//printf("\n\n");
	}
	o->set_lastcall();
	if(o->query_room()!=this_body()->query_room()) {
		o->my_come();
		printf("\n");
	}
        if(sscanf(arg,"%s %s",cmd,para)!=2)
        {
                 cmd=arg;
                 para="";
        }
	switch(cmd) {
		case "return" : 
			o->my_return();
			return;
		case "old" : //
			if(DAY_D->get_can_war()) {
				write("战争时间暂时禁止。\n");
				return;
			}
			if(wizardp(this_body())) 
			   o->my_call_old_player();
			else
			   write("该功能暂时不对玩家开放!\n");
			return;
			
			return;
		case "do" :
			if(wizardp(this_body())) 
			   o->my_do(para);
			else
			   write("该功能暂时不对玩家开放!\n");
			return;
		case  "faq" :
	                if (para=="") {
				write("格式：gini faq <主题>\n"+
				"例如：gini faq 钱  [主题中英文皆可]\n");
				return;
				}
		        o->my_faq(para);
		        return;
		        
		
//-------------------------------------------------------//
//         followings are wizard gini commands           //
//-------------------------------------------------------//
		case "wiz": //
			if(wizardp(this_body())) 
				write(GINI_D->wiz_can_do());
			else {
				o->my_do("ah");
			}
			return;
		case "list" :
		        if(wizardp(this_body())) 
			   write(GINI_D->gini_list());
			else
			   o->my_do("ah");
			return;
		case "change" : // change to another gini
		        if(wizardp(this_body())) {
			  if(!GINI_D->gini_exist(para)) {
				write(
                    "没有这种类型的gini，用 %^H_CYAN%^gini list%^RESET%^ 查类型清单。\n");
				return; 
			}
			o->my_return();
			this_body()->set_gini(para);
			//SUBUG(para);
			GINI_D->gini_birth(this_body());}
			else
			   o->my_do("ah");
			return;
		case "check" :
			if(wizardp(this_body())) {
				if(sizeof(para))
					g_type=para;
				more(GINI_D->do_gini_check(g_type));
			}
			return;
	       	case "actrule" :
			if(wizardp(this_body())) {
				if(sizeof(para))
					g_type=para;
				write(GINI_D->act_rule());
			}
			return;
		case "add":
			if(wizardp(this_body())) {
				write(GINI_D->add_new_gini(para));
			}
			return;
		case "addact":
			if(wizardp(this_body())) {
				string p_typ,p_act,*ks;
				int num;
				num=sscanf(para,"%s %s",p_typ,p_act);
				if(num!=2) {
					write("格式：gini addact <typ> <act>\n"+
					"例如：gini addact come GMflya\n");
					return;
				}
				ks=GINI_D->get_n_act();
				if(member_array(p_typ,ks)==-1) {
					write("没有这种类型的动作。\n"+
					"用gini check查看所有的动作类型。\n");
					return;
				}
				printf("%O\n",GINI_D->add_msg(g_type,p_typ,p_act));
				return;
			}
			return;
		 case "rmact":
			if(wizardp(this_body())) {
				string p_act,*ks;
				int num,p_index;
				num=sscanf(para,"%s %d",p_act,p_index);
				if(num!=2) {
					write("格式：gini rmact <act> <index>\n"+
					"例如：gini rmact birth 1\n");
					return;
				}
				/*ks=GINI_D->get_n_act();
				if(member_array(p_typ,ks)==-1) {
					write("没有这种类型的动作。\n"+
					"用gini check查看所有的动作类型。\n");
					return;
				}*/
				printf("%O\n",GINI_D->rm_msg(g_type,p_act,p_index));
				return;
			}
			return;
	 	 case "hintlist" :
			if(wizardp(this_body())) {
				if(sizeof(para))
					g_type=para;
				more(GINI_D->get_hint(-1));
			}
			return;
		 case "addhint" :
			if(wizardp(this_body())) {
				string p_hint;
				int num;
				num=sscanf(para,"%s",p_hint);
				if(num!=1) {
					write("格式：gini addhint <hint>\n"+
					"例如：gini addhint 三国只有做官或打工才能挣钱哦!\n");
					return;
				}
				printf("%O\n",GINI_D->add_hint(p_hint));
				return;
			}
			return;
		case "rmhint" :
		
			if(wizardp(this_body())) {
				int num,p_hint;
				num=sscanf(para,"%d",p_hint);
				if(num!=1) {
					write("格式：gini rmhint <index>\n"+
					"例如：gini rmhint 1\n");
					return;
				}
				printf("%O\n",GINI_D->remove_hint(p_hint));
				return;
			}
			return;
		 
		 default :
		        if (!is_new)
		       	   o->my_help();
			return;

	}
}