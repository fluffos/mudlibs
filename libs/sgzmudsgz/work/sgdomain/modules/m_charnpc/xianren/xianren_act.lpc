// m_charaction.c by fire on Dec 1998
// this is used to handle npc chars auto action
void add_hook(string, function);
private string *p_autosay=({
"老夫纵观天下，真正是乱世出英雄啊。\n",
"看来东汉当真是气数已尽了。\n",
});
private string *p_autochat=({
"伏龙凤雏，得一可安天下，得二嘛，就难说了. . . .",
});
void add_say(string s) {
   p_autosay+=({s});
}
void add_chat(string s) {
 p_autochat+=({s});
}
void clear_say() {
  p_autosay=({}); 
}
void clear_chat() {
  p_autochat=({});
}
string find_target() {
    object *who = all_inventory(environment());
    object o;
    if (!sizeof(who)) 
        return this_object()->query_id()[0];
    o=who[random(sizeof(who))];
    if(!o->is_living()) return this_object()->query_id()[0];
    return o->query_id()[0];
}
void do_mychat() {
    string msg;
    if(!sizeof(p_autochat)) return;
    msg=p_autochat[random(sizeof(p_autochat))];
    CHANNEL_D->deliver_tell("gossip",this_object()->query_chinese_id(),msg);
}
void do_mysay(){
    string msg;
    if(!sizeof(p_autosay)) return;
    msg=p_autosay[random(sizeof(p_autosay))];
    this_object()->responda("say "+msg);
}
void do_mymovearea() {
        string p_id;
        string *p_a;
        string p_curarea,p_desarea;
        object p_o;
	p_id=this_object()->query_primary_id();
	p_o=this_object();
        p_curarea=p_o->query_room()->get_area();
        p_a=AREA_D->get_area(p_curarea,"neighbor");
        if(!sizeof(p_a))
             return;
        p_desarea=p_a[random(sizeof(p_a))];
        if(objectp(p_o))
        {
           p_o->simple_action("$N道：此处已经待够，该换换地方了。\n");
           p_o->simple_action("$N匆匆离开了．\n");
        }
        CHAR_D->appear(p_id,p_desarea);
        CHANNEL_D->deliver_tell("rumor","system","听说"+
        CHAR_D->get_char(p_id,"name")+"到了"+AREA_D->get_area(p_desarea, "name")+"一带。");
}
void do_myannouncearea() {
     string p_area;
     string p_id=this_object()->query_primary_id();
     p_area=this_object()->query_room()->get_area();
    CHANNEL_D->deliver_tell("gossip",CHAR_D->get_char(p_id,"name"), AREA_D->get_area(p_area,
"name")+"真是个好地方，老夫还要多游览几日。");
}
void do_my_semote()
{
    string *emotes = SOUL_D->list_emotes();
    string which = emotes[random(sizeof(emotes))];
    string *rules = keys(SOUL_D->query_emote(which));
    string rule = rules[random(sizeof(rules))];
    string comm, token;
    
    if (!environment()) return;
    comm = which;
    foreach (token in explode(rule, " ")) {
        comm += " ";
        switch (token) {
        case "OBJ":
        case "LIV":
            comm += find_target();
            break;
        default:
            comm += token;
        }
    }
    this_object()->responda(comm);
}
void do_my_moving()
{
   string *obvious_exits = 
       environment(this_object())->query_exit_directions();
   int random_exit,i;
   string my_exit;
   if(!sizeof(obvious_exits)) return;
   my_exit = obvious_exits[random(sizeof(obvious_exits))];
   this_object()->responda("go "+my_exit);
}
int valid_check()
{
    object env;
    env=environment(this_object());
    if(!objectp(env)) {
        SGSYS(this_object()->short()+"没有环境。");
        return 0;       
    }
    return 1;
}
void my_charaction()
{
   int act;
   act=random(20);
   switch(act)
   {
      case 0:
         do_mychat();
         return ;
      case 1:
         do_mymovearea();
         return;
      case 2:
         do_myannouncearea();
         return;
      case 3:
      case 4:
      case 5:
          do_my_semote();
          return;         
      case 6:
      case 7:
      case 8:
          do_mysay();
          return;
      default:
          do_my_moving();
          return;
   }
}
void stop_heart() {
  remove_call_out("my_heart");
}
void my_heart()
{
    call_out("my_heart",random(90)+60);
    add_hook("remove",(: stop_heart :));
    if(valid_check())
    { 
       my_charaction();
    }
    else
       this_object()->remove();
}
