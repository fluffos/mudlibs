//wiz.c by fire on July 5 1999
private mapping m_act=
([ 
  "long" : "帮助精灵的外表look时。",
  "toosoon" : "告诉不能在短时间内让gini重复某项事情。",
  "ask" : "召唤gini时对gini的用语。",
  "name" : "gini的名字。",
  "title" : "在房间中的描述。",
  "go" : "gini从别处回到主人身边。",
  "disappear" : 
    "主人离开线时的自动消失。已gini为主语的simple_act,\n"+
     "不能有act对象。与其他动作的定义不同。",
  "come" : "把gini从别的房间招来。",
  "random" : "gini的随机动作",
  "birth" : "gini诞生，当玩家联线时。",
  "return" : "让gini消失。",
  "call_old_player" : "让gini找老玩家帮助。",
  "nooldplyer" : "找不到高手。",
  "call" : "召唤gini",
  "noneed" : "玩家等级太高，gini不愿意帮助。",
  "magic" : "gini 施法。",
  "readhint" : "gini 读提示 hint",
  "do" :  "让gini执行指令。",
  "know" : "召唤gini的回答。",
  "busy" : "gini正在执行一向任务，不能接受下一项任务。",

  "lamp_id" : "召唤gini信物的id",
  "lamp_long" : "召唤gini信物的描述。",
  "lamp_unit" : "召唤gini信物的单位。",
  "lamp_name" : "召唤gini信物的名称。",
  "gender" : "gini的性别：1 男，2 女",
]) ;

string *get_n_act() {
	return keys(m_act);
}

mixed do_gini_check(string typ) {
	string *r_keys,*n_keys;
	string ret,*ks;
	mixed acts;
	acts=GINI_D->get_msg(typ);
	if(!mapp(acts)) return acts;
	r_keys=keys(acts);
	n_keys=keys(m_act);
	ret="gini 类型："+typ+"\n";
	ret="---------------------------------------------------\n";
	if(!sizeof(r_keys)) ret+= "还没有定义任何动作。\n";
	else
	foreach(string k in r_keys) {
		ret+="关键字：%^H_GREEN%^"+k+"%^RESET%^";
		ret+="  解释：%^H_RED%^"+m_act[k]+"%^RESET%^\n";
		ks=acts[k];
		if(!sizeof(ks)) {
			ret+="   还没有定义。\n";
			continue; 
		}
		foreach(string s in ks) {
			if(s[<1]!='\n') s+="\n";
			ret+="   "+s;
		}
	}
	n_keys-=r_keys;
	if(sizeof(n_keys)) {
		ret+="%^H_RED%^还有以下动作没有定义。%^H_RED%^\n";
		ret+=
		"----------------------------------------------\n";
		foreach(string k in n_keys) {
			ret+="关键字：%^H_GREEN%^"+k+"%^RESET%^";
			ret+="  解释：%^H_RED%^"+m_act[k]+"%^RESET%^\n";
			ret+="  列子："+GINI_D->get_msg("gini",k);
			if(ret[<1]!='\n') ret+="\n";
		}
	}
	return ret;
}

string act_rule() {
	string ret;
	ret=
"gini动作规范解释：
一个gini的动作包括两部分：第一部分是%^H_RED%^两字母的说明，
%^RESET%^第二部分是%^H_RED%^具体的动作%^RESET%^，说明部分有以下规范：
1 %^H_BLUE%^GE%^RESET%^：gini做emote。
   例如：%^H_GREEN%^GEhi%^RESET%^  则gini会%^RED%^蓝色大精灵长揖到地，朗声道：小人蓝色大精灵这厢有礼了！%^RESET%^
2 %^H_BLUE%^GM%^RESET%^：gini对主人做emote。
   例如：%^H_GREEN%^GMhi%^RESET%^  则gini会%^RED%^蓝色大精灵友善地和你打了个招呼。%^RESET%^
3 %^H_BLUE%^GA%^RESET%^：gini(对主人)做动作
   例如：%^H_GREEN%^GA$N拍了拍$T的头%^RESET%^  则gini会%^RED%^蓝色大精灵拍了拍你的头%^RESET%^
   例如：%^H_GREEN%^GA$N拍了拍头%^RESET%^  则gini会%^RED%^蓝色大精灵拍了拍头%^RESET%^
4 %^H_BLUE%^ME%^RESET%^：主人做emote
   例如：%^H_GREEN%^MEhehe%^RESET%^  则你会%^RED%^你「嘿嘿嘿．．．」地奸笑了几声。%^RESET%^
5 %^H_BLUE%^MG%^RESET%^：主人对gini做emote
   例如：%^H_GREEN%^MGpat%^RESET%^  则你会%^RED%^你轻轻地拍了拍蓝色大精灵的头。%^RESET%^\n";
ret+=
"6 %^H_BLUE%^MA%^RESET%^：主人(对gini)做动作
   例如：%^H_GREEN%^MA$N对$T大喊一声：住口。%^RESET%^  则你会%^RED%^你对蓝色大精灵大喊一声：住口。%^RESET%^
7 %^H_BLUE%^GS%^RESET%^：gini 说话
   例如：%^H_GREEN%^MS从前有坐山. . .%^RESET%^  则gini会%^RED%^蓝色大精灵说道：从前有坐山. . .%^RESET%^
8 %^H_BLUE%^GT%^RESET%^：gini tell 主人
   例如：%^H_GREEN%^GThi%^RESET%^  则gini会%^RED%^蓝色大精灵(fire gini)告诉你：hi%^RESET%^
9 如果缺省，则为MA : 主人对gini做emote
   例如：%^H_GREEN%^$N对$T大喊一声：住口。%^RESET%^  则你会%^RED%^你对蓝色大精灵大喊一声：住口。%^RESET%^\n";
return ret;
}