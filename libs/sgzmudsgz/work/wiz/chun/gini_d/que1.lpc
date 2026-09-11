//que1.c by fire on June 22 1999
private mapping msg=
([
   "gini" : ([
"call_old_player" : ({
"$N一指$T道：喂，伙计，给咱找个高手来指点指点。\n",
}),
"busy" : ({
"$T对$N道：主人，我上一向任务还没完成呢。\n",
}),
"noneed" : ({
"$T对$N道：主人，这点小事，不用我帮你也可以办到呀。\n",
}),
"toosoon" : ({
"$T对$N道：主人，刚施过此法术，法力还没恢复呀。\n",
}),
"nooldplyer" : ({ 
"$T掏出望远镜四面望了一通道：主人，合适的高手找不到呀。\n",
}),
"magic" : ({
"$T掏出一个水晶球，口中还念着一些听不懂得咒语。水晶球颜色越来越深，突然冒出一道蓝光。\n",
}),
"birth" : ({
"突然冒起一股%^BLUE%^篮烟%^RESET%^，烟雾中，一个$T递给$N一盏神灯，说道：\n我是你的保护神，当你需要我时，只要输入 gini 我就会帮助你。\n若你不需要我了，输入 gini return，我就会消失。\n",
}),
"call" : ({
"$N从怀里掏出一盏阿拉伯神灯，用袖子擦了擦. . . . \n一股%^BLUE%^篮烟%^RESET%^从灯中冒出，慢慢地化成一个蓝色大怪精灵。\n",
"GTbow",
}),
"come" : ({
"$N一擦神灯，$T急忙从远处飘来。\n",
"GS主人，有何吩咐。",
"$T对$N作了个鬼脸，$R有何吩咐？\n",
}),
"go" : ({
"$T急忙从远处飘来，在$N的脑门上弹了一下。\n",
"GS主人我来拉。",
}),

"ask" : ({
"$N对$T道：gini，你都能干什么呢？\n",
"$N对$T道：gini，让我看看你的本事吧。\n",
}),
"disappear" : ({
"$N化作一股%^BLUE%^蓝烟%^RESET%^，慢慢地消失了。\n",
}),
"return" : ({
"$N拿着神灯摇了摇，$T化作一股蓝烟，钻回灯中。\n",
}),
"readhint" : ({
"$T摇身一变，化成孙武模样，手持兵书，一本正经地对$N念到，\n",
}),
"do" : ({
"$N对$T使了个眼色。\n",
"$N在$T耳边嘀咕了些什么。\n",
"$N若无其事地看了$T一眼。\n",
}),
"know" : ({
"$T道：我的本事可大了。\n",
"GS我的拿手戏可多了。",
}),
"random" : ({
"GEface","GMack","GS很久很久以前，有一个阿拉伯青年，他的名字就叫：“阿 . 里 . 吧 . 吧 . . . .”",
"GMbow",
"GT主人，你还好吗？","MEhehe","MGpat","MA$N大喊一声：“住口”\n",
"$T突然变成一个魔鬼，张开嘴一口把$N吞了下去。\n",
}),

]), // end of gini

]);


private mixed * hints=({
"下士胜人于武；中士胜人于智；上士胜人于德。\n",
"三国不同于其他MUD，只埋头练功，不广结贤良，纵有通天本领，也难成大业。\n",
"好男儿纵横天下，若他日能君临天下，自是大好，\n但能得遇明主以辅之，也不枉活一世。\n",
"千军易得，一将难求，找到一个智勇双全，忠心耿耿的大将，真是难上又难。\n",
"民乃国之根本，亦载舟，亦覆舟，故民心切不可失也。\n",
"开始工作虽苦，但卧薪尝胆，大事终可图也。\n",
"富贵不能淫，贫贱不能移，此乃真丈夫也。\n",
});
string get_hint() {
    return hints[random(sizeof(hints))];
}
string get_msg(string char,string typ) {
    mixed * tmp;
    if(!mapp(msg[char])) return "$N不知道该做什么好。\n";
    tmp=msg[char][typ];
    if(!arrayp(tmp)) return "$N不知道该做什么好。\n";
    return tmp[random(sizeof(tmp))];
}
string get_title(string char){
    switch (char) {
        case "gini":
           return "%^BLUE%^蓝色大精灵%^RESET%^(gini)";
        default :
           return "不知道是什么东西。\n";
    }
}
string get_long(string char) {
    switch (char) {
        case "gini":
           return "一个%^BLUE%^蓝色大精灵%^RESET%^，飘在空中，不断地做着鬼脸。\n";
        default :
           return "不知道是什么东西。\n";
    }
}
string get_name(string char) {
    switch (char) {
        case "gini":
           return "蓝色大精灵";
        default :
           return "不知道是什么东西。\n";
    }
}


string get_lamp_id(string my_type) {
    switch (my_type) {
        case "gini":
           return "lamp";
        default :
           return "不知道是什么东西。\n";
    }
}
string get_lamp_name(string my_type) {
    switch (my_type) {
        case "gini":
           return "阿拉伯神灯";
        default :
           return "不知道是什么东西。\n";
    }
}
string get_lamp_unit(string my_type) {
    switch (my_type) {
        case "gini":
           return "盏";
        default :
           return "不知道是什么东西。\n";
    }
}

string get_lamp_long(string my_type) {
    switch (my_type) {
        case "gini":
           return "一盏富有魔力的阿拉伯神灯，要使用就输入：gini\n";
        default :
           return "不知道是什么东西。\n";
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

        CHAR_D->add_char(p_id);
        CHAR_D->set_char(p_id,"name",get_name(g_type));
        CHAR_D->set_char(p_id,"is_tmp",1);
        CHAR_D->set_char(p_id,"body","gini");
        CHAR_D->set_char(p_id,"master",oo->query_primary_id());
        CHAR_D->set_char(p_id,"g_type",g_type);
        CHAR_D->set_char(p_id,"type",0);
        CHAR_D->put_char(p_id,file_name(oo->query_room()));
        o=CHAR_D->find_char(p_id);
        o->my_birth();
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

void check_gini() {
/*    object *os,lmp;
    call_out("check_gini",30);
    os=users()->query_body();
    if(sizeof(os)) {
        foreach(object o in os) {
           if(objectp(o)) {
               lmp=present("gini lamp",o);
               if(!objectp(lmp)) gini_birth(o);
           }
        }
    } */
}
void create() {
   check_gini();
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
	g_id=p_id+" gini";
	o_gini=CHAR_D->find_char(g_id);
	o_ply=find_body(p_id);
	if(!objectp(o_gini)) return;
	if(!objectp(o_ply)) return;
	g_typ=CHAR_D->get_char(g_id,"g_type");
	act=get_msg(g_typ, typ);
	p_t=act[0..1];
	switch(p_t) {
	case "GE" :  // gini emote
		o_gini->responda(act[2..<1]);
		return ;  // self semote
	case "GM" :  // gini emote to master
		o_gini->responda(act[2..<1]+" "+p_id); // to his master
		return ;
	case "GA" :  // master act
		o_gini->targetted_action(act[2..<1],o_ply);
		return ;

	case "ME" :  // master emote
		o_ply->responda(act[2..<1]);
		return ;  // self semote
	case "MG" :  // master emote to gini
		o_ply->responda(act[2..<1]+" "+g_id);
		return ;  // self semote
	case "MA" :  // master act
		o_ply->targetted_action(act[2..<1],o_gini);
		return ;
	case "GS" :  // gini say
		o_gini->responda("say "+act[2..<1]);
		return ;
	case "GT" : // gini tell
		o_gini->responda("tell "+p_id+" "+act[2..<1]);
		return ;
	default :
		o_ply->targetted_action(act,o_gini);
		return ;
	}
}
string what_can_do() {
return 
"%^H_BLUE%^gini%^RESET%^：               召唤我的到来。
%^H_BLUE%^gini do %^H_RED%^some thing%^RESET%^： 让我做一些事。
  例如：%^H_GREEN%^gini do hi %^RESET%^  我就会鞠躬。
%^H_BLUE%^gini return%^RESET%^；        我就会先藏起来。
%^H_BLUE%^gini old%^RESET%^；           我就会找个高手来帮助你。

";
}
