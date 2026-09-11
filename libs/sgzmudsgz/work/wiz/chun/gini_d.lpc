//gini_d.c by fire on June 22 1999
//Modilied by suicide on Aug 29 2000
inherit M_ACCESS;

inherit __DIR__+"gini_d/wiz";
#define SAVE_FILE "/data/daemons/gini"

private mapping msg;

private mixed * hints;

private mixed * faqs;

void save_data()
{
       unguarded(1, (: save_object, SAVE_FILE :));
}
void create()
{
    unguarded(1, (: restore_object, SAVE_FILE, 1 :));
    return;
}

mixed get_hint(int i) {
    if(!i)
	return hints[random(sizeof(hints))];
    if(i==-1)
	return hints;
    if(i>sizeof(hints)) return "总共有"+sizeof(hints)+"条提示。\n";
    if(i<0) i=1;
        return hints[i-1];
       
}
mixed add_hint(string str) {
	hints-=({str});
	hints+=({str});
	save_data();
	return hints;
}
string remove_hint(int i) {
	string str;
	str=hints[i];
	hints-=({str});
	save_data();
	return str;
}

/*mixed add_faq(string question,function f) 
{       
	faqs-=({question});
	faqs+=({question});
	save_data();
	return faqs;    
}*/




mixed get_msg(string char,string typ,int n) {
    mixed * tmp;
    if(!mapp(msg[char])){SGSYS("no gini type of "+char); return "没有这样的gini。\n"; }
    if(!sizeof(typ))
       return msg[char];
    tmp=msg[char][typ];
    if(!arrayp(tmp)) { SGSYS("no gini act of "+typ+" for gini "+char);
          return "没有这样的动作。\n"; }
    if(!sizeof(tmp)) { SGSYS("no gini act of "+typ+" for gini "+char);
        return "$N不知道该做什么好。\n"; }
    if(!n)
       return tmp[random(sizeof(tmp))];
    if(n==-1) return tmp;
    return tmp[n-1];
}

mixed add_msg(string gin,string typ,string str) {
	if(!mapp(msg[gin])) return "no gini type of "+ gin+"\n";
	if(!arrayp(msg[gin][typ])) return "no act type of "+typ+"\n";
	msg[gin][typ]-=({str});
	msg[gin][typ]+=({str});
	save_data();
	return msg[gin][typ];
}

mixed rm_msg(string gin,string typ,int i) {
	string str;
	if(!mapp(msg[gin])) return "no gini type of "+ gin+"\n";
	if(!arrayp(msg[gin][typ])) return "no act type of "+typ+"\n";
	str=msg[gin][typ][i-1];
	msg[gin][typ]-=({str});
	save_data();
	return msg[gin][typ];
}

mixed add_typ(string gin,string typ) {
	if(!mapp(msg[gin])) return "no gini type of "+ gin+"\n";
	if(!arrayp(msg[gin][typ])) {
		msg[gin][typ]=({});
		save_data();
		 return "ok\n";
	}
	return "such type already exist\n";
}
mixed add_new_gini(string gin) {
	string *ks;
	if(!sizeof(gin)) return "非法gini类型。\n";
	if(mapp(msg[gin])) return "这种gini类型已经存在了。\n";
	msg[gin]=([]);
	ks=get_n_act();
	foreach(string k in ks) {
		msg[gin][k]=({});
	}
	save_data();
	return "新gini类型增加成功。\n";
}
mixed rm_old_gini(string gin) {
	if(!sizeof(gin)) return "非法gini类型。\n";
	if(!mapp(msg[gin])) return "这种gini类型不存在。\n";
	map_delete(msg,gin);
	save_data();
	return "旧gini类型删除成功。\n";
}
void gini_birth(object oo) {
        string p_id,g_type;
        object o;
        g_type=oo->get_gini();
        if(!sizeof(g_type)){
           g_type="gini";
           oo->set_gini(g_type);
        }

        p_id=oo->query_primary_id();
        //p_id+=" gini";
        p_id+=" ";
        p_id+=g_type;
        //SUBUG(p_id);
        CHAR_D->add_char(p_id);
        CHAR_D->set_char(p_id,"name",get_msg(g_type,"name",0));
        CHAR_D->set_char(p_id,"is_tmp",1);
        CHAR_D->set_char(p_id,"body","gini");
        CHAR_D->set_char(p_id,"master",oo->query_primary_id());
        CHAR_D->set_char(p_id,"g_type",g_type);
        CHAR_D->set_char(p_id,"type",0);
	CHAR_D->set_char(p_id,"gender",to_int(get_msg(g_type,"gender",0)));
        CHAR_D->put_char(p_id,file_name(oo->query_room()));
        o=CHAR_D->find_char(p_id);
        o->my_birth();
        o->my_do("follow "+this_body()->query_primary_id());
}
void play_get_gini(string p)
{
    object o=find_body(p);
    object os;
    if(!objectp(o)) return;
    os=present("gini lamp",o);
    if(objectp(os)) return;
    gini_birth(o);
}
void play_enter(string p) {
     call_out("play_get_gini",10,p);
}



// this is the main part to ask a gini to do sth
// gini is the first sub, the player is the second
// GE gini emote GM gini to master semote
// ME master emote MG master to gini semote
// GS gini say GT gini tell
void gini_act(string p_id,string typ) {
	string g_id,g_typ,act;
	object o_gini,o_ply;
	string p_t;
	//g_id=p_id+" gini";
	g_id=p_id+" "+this_body()->get_gini();
	o_gini=CHAR_D->find_char(g_id);
	o_ply=find_body(p_id);
	if(!objectp(o_gini)) return;
	if(!objectp(o_ply)) return;
	g_typ=CHAR_D->get_char(g_id,"g_type");
	act=get_msg(g_typ, typ,0);
	p_t=act[0..1];
	switch(p_t) {
	case "GE" :  // gini emote
		o_gini->responda(act[2..<1]);
		return ;  // self semote
	case "GM" :  // gini emote to master
		o_gini->responda(act[2..<1]+" "+p_id); // to his master
		return ;
	case "GA" :  // master act
		if(act[<1]!='\n') act+="\n";
		o_gini->targetted_action(act[2..<1],o_ply);
		return ;
	case "ME" :  // master emote
		o_ply->responda(act[2..<1]);
		return ;  // self semote
	case "MG" :  // master emote to gini
		o_ply->responda(act[2..<1]+" "+g_id);
		return ;  // self semote
	case "MA" :  // master act
		if(act[<1]!='\n') act+="\n";
		o_ply->targetted_action(act[2..<1],o_gini);
		return ;
	case "GS" :  // gini say
		o_gini->responda("say "+act[2..<1]);
		return ;
	case "GT" : // gini tell
		o_gini->responda("tell "+p_id+" "+act[2..<1]);
		return ;
	default :
		if(act[<1]!='\n') act+="\n";
		//act = "this is a \ntest\n";
		//tell_user("suicide",sprintf("[%O]\n",act));
		
		o_ply->targetted_action(act,o_gini);
		return ;
	}
}
int gini_exist(string g) {
	return (mapp(msg[g]));
}
string gini_list() {
	string ret="类型      名称\n";
	string *gs;
	gs=keys(msg);
	foreach(string g in gs) {
		ret+=g;
		ret+="      "+get_msg(g,"name",0);
		ret+="\n";
	}
	return ret;
}
string what_can_do() {
return "
%^H_BLUE%^gini              %^RESET%^          召唤我的到来。
%^H_BLUE%^gini do%^H_RED%^ some thing%^RESET%^          让我做一些事。
%^H_BLUE%^gini return       %^RESET%^          我就会先藏起来。
%^H_BLUE%^gini faq%^H_RED%^  thing%^RESET%^             向精灵询问有关主题的帮助。
%^H_BLUE%^gini old          %^RESET%^          我就会找个高手来帮助你。
%^H_BLUE%^gini wiz          %^RESET%^          巫师指令集。
%^H_BLUE%^gini help         %^RESET%^          gini指令的使用方法简介。

例如：%^H_CYAN%^gini do hi %^RESET%^             我就会鞠躬。
例如：%^H_CYAN%^gini faq 钱 %^RESET%^            向精灵询问有关钱的主题
";
}
string wiz_can_do() {
return 
"
-------------------JINI 设置指令---------------------------------
%^H_BLUE%^gini add %^H_RED%^some thing%^RESET%^： 增加新的gini类型。
%^H_BLUE%^gini rm %^H_RED%^some thing%^RESET%^： 删除旧的gini类型。
%^H_BLUE%^gini list         %^RESET%^    精灵类型列表。
%^H_BLUE%^gini change%^H_RED%^ type  %^RESET%^    更换精灵类型
---------------------动作管理------------------------------------
%^H_BLUE%^gini check%^RESET%^：            gini动作查看。
%^H_BLUE%^gini addact%^RESET%^：           增加动作。
%^H_BLUE%^gini rmact%^RESET%^：            删除动作。
%^H_BLUE%^gini actrule%^RESET%^：          动作解释。
---------------------提示管理------------------------------------
%^H_BLUE%^gini hintlist%^RESET%^：         列表提示集。
%^H_BLUE%^gini addhint%^RESET%^：          增加提示。
%^H_BLUE%^gini rmhint%^RESET%^：           删除提示。
---------------------问题管理------------------------------------
%^H_BLUE%^gini qlist%^RESET%^：            列表问题集。
%^H_BLUE%^gini addq%^RESET%^：             增加问题。
%^H_BLUE%^gini rmq%^RESET%^：              删除问题。

";
}
