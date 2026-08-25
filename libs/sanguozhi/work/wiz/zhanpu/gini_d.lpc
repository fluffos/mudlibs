//gini_d.c by fire on June 22 1999
private mapping msg=
([
   "gini" : ([
"birth" : ({
"突然冒起一股%^BLUE%^篮烟%^RESET%^，烟雾中，一个$T递给$N一盏神灯，说道：\n我是你的保护神，当你需要我时，只要输入 gini 我就会帮助你。\n",
}),
"call" : ({
"$N从怀里掏出一盏阿拉伯神灯，用袖子擦了擦. . . . \n一股%^BLUE%^篮烟%^RESET%^从灯中冒出，慢慢地化成一个蓝色大怪精灵。\n",
}),
"come" : ({
"$N一擦神灯，$T急忙从远处飘来。\n",
}),
"go" : ({
"$T急忙从远处飘来，在$N的脑门上弹了一下。\n",
}),

"ask" : ({
"$T对$N作了个鬼脸，$R有何吩咐？\n",
}),
"disappear" : ({
"$N化作一股%^BLUE%^蓝烟%^BLUE^%，慢慢地消失了。\n",
}),
"return" : ({
"$N拿着神灯摇了摇，$T化作一股蓝烟，钻回灯中。\n",
}),
"readhint" : ({
"$T摇身一变，化成孙武模样，手持兵书，一本正经地对$N念到，\n",
}),

]), // end of gini

]);


private mixed * hints=({
"下士胜人于武；中士胜人于智；上士胜人于德。\n",
"三国不同于其他MUD，只埋头练功，不广结贤良，纵有通天本领，也难成大业。\n",
"好男儿纵横天下，如一日能君临天下，自是大好，\n不过若能得之遇明主以辅之，也不枉活一世。\n",
"千军易得，一将难寻，找到一个智勇全才，忠心耿耿的大将，真是难上又难。\n",
"民乃国之根本，民心切不可失也。\n",
"开始作工虽苦，但卧薪尝胆，大事究日可图也。\n",
"富贵不能淫，贫贱不能移，此乃真丈夫也。\n",
});
string get_hint() {
    return hints[random(sizeof(hints))];
}
string get_msg(string char,string typ) {
    mixed * tmp;
    if(!mapp(msg[char])) return "$N不知道该作什么好。\n";
    tmp=msg[char][typ];
    if(!arrayp(tmp)) return "$N不知道该作什么好。\n";
    return tmp[random(sizeof(tmp))];
}
string get_title(string char){
    switch (char) {
        case "gini":
           return "%^BLUE%^蓝色大精灵%^RESET%^(gini)";
        default :
           return "不只什么东西。\n";
    }
}
string get_long(string char) {
    switch (char) {
        case "gini":
           return "一个%^BLUE%^蓝色大精灵%^RESET%^，飘在空中，不断地做着鬼脸。\n";
        default :
           return "不只什么东西。\n";
    }
}
string get_name(string char) {
    switch (char) {
        case "gini":
           return "蓝色大精灵";
        default :
           return "不只什么东西。\n";
    }
}


string get_lamp_id(string my_type) {
    switch (my_type) {
        case "gini":
           return "lamp";
        default :
           return "不只什么东西。\n";
    }
}
string get_lamp_name(string my_type) {
    switch (my_type) {
        case "gini":
           return "阿拉伯神灯";
        default :
           return "不只什么东西。\n";
    }
}

string get_lamp_unit(string my_type) {
    switch (my_type) {
        case "gini":
           return "盏";
        default :
           return "不只什么东西。\n";
    }
}

string get_lamp_long(string my_type) {
    switch (my_type) {
        case "gini":
           return "一盏富有魔力的阿拉伯神，要使用就输入：gini\n";
        default :
           return "不只什么东西。\n";
    }
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
	p_id+=" gini";
	if(CHAR_D->char_exist(p_id)) {
		o=CHAR_D->find_char(p_id);
		if(!objectp(o)){CHAR_D->remove_char(p_id); return; }
		o->my_come();
	}
	else {
		CHAR_D->add_char(p_id);
		CHAR_D->set_char(p_id,"name",get_name(g_type));
		CHAR_D->set_char(p_id,"is_tmp",1);
		CHAR_D->set_char(p_id,"body","gini");
		CHAR_D->set_char(p_id,"master",oo->query_primary_id());
		CHAR_D->set_char(p_id,"type",g_type);
		CHAR_D->put_char(p_id,file_name(oo->query_room()));
		o=CHAR_D->find_char(p_id);
		o->my_birth();
	}
}
void check_gini() {
    object *os,lmp;
    call_out("check_gini",30);
    os=users()->query_body();
    if(sizeof(os)) {
        foreach(object o in os) {
	   if(objectp(o)) {
               lmp=present("gini lamp",o);
               if(!objectp(lmp)) gini_birth(o);
           }
        }
    }
}
void create() {
   check_gini();
}