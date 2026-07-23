// try home   room1.c
// by snowtu@2003

inherit F_SAVE;

int save_room();
string check_str(string str);
string whos=this_object()->query("owner");
void get_long_text(string str, string text);
void get_bed_long_text(string str, string text);
void fullup(object obj); 

int is_home() {return 1;}

void init()
{
object me=this_player(), env=this_object();

add_action("go_out", "out");

if( me->query("id")==whos || !userp(me) ) 
	{
tell_object(me,HIC"\n欢迎主人归来！你可以用sets来装修，name来取名。\n"NOR);
add_action("set_long", "sets");
add_action("set_short", "name");
add_action("do_get", "qing");
add_action("do_kick", "gan");
       }

else if( me->query_temp("player-room/onwer")!=whos ) 
	{
	write("主人不在家，您还是呆会儿再来吧。\n");
	me->move("/d/city/kezhan");
       message_vision(CYN"$N尴尬地从"+this_object()->query("short")+CYN"走了出来。\n"NOR,me);
	return;
       } 
else  tell_object(me,HIC"欢迎欢迎热烈欢迎。\n"NOR);
return;
}

int do_get(string arg)
{
object me,who,where;
string name;
me = this_player();
where = this_object();
name =where->query("short");

if ( !arg || arg==whos )
       return notify_fail("你确定有这个客人？\n");

who=find_player(arg);

if ( !who || !userp(who) )  
       return notify_fail("没有这个人......\n");
 
tell_object(who,me->name()+"邀请你去他的"+name+"一聚。\n");
who->set_temp("player-room/onwer",whos);
tell_object(me,"你邀请"+who->name()+"来你的"+name+"一聚。\n");
return 1;
}

int go_out()
{
object me=this_player();
tell_room(this_object(),me->query("name")+"推开门，走了出去。\n",({me}));
me->move("/d/city/kezhan");
message_vision("$N推开门，走了出来。\n",me);
return 1;
}

int set_short(string str)
{
    if(!str) return 0;

    str=check_str(str);
    this_object()->set("short",str);
//    set_name(this_object()->query("short"), ({this_object()->query("file_name")}));
    save_room();
    return 1;
}

int set_long()
{   string str;
    this_player()->edit( (:get_long_text, str :) );
    return 1;
}

void get_long_text(string str, string text)
{
    str=check_str(text);
    this_object()->set("long",str);
    save_room();
    return;
}

string check_str(string str)
{ 
    str=replace_string(str,"\"","");
    str=replace_string(str,";","");
    str=replace_string(str,"\\","");
    str=replace_string(str,"/","");
    str=replace_string(str,"'","");
    str=replace_string(str,"`","");
    str=replace_string(str,",","");
    str=replace_string(str,"!","");
    str=replace_string(str,"~","");
    str=replace_string(str,"{","");
    str=replace_string(str,"}","");
    str=replace_string(str,"$","");
    str=replace_string(str,"&","");
    return str;
}

int clean_up()
{    //clean_up homes
    object *inv,*inv1;
    int i,j;

    if( !clonep() && this_object()->query("no_clean_up") ) return 1;

    inv = all_inventory();
    for(i=sizeof(inv)-1; i>=0; i--) {
      if(userp(inv[i])) return 1;
      if(inv[i]->query("if_bed")) {  //a bed object
        inv1=all_inventory(inv[i]);
        if(sizeof(inv1)>0)
          for(j=sizeof(inv1)-1; j>=0; j--) {
            if (userp(inv1[j])) return 1;
          }
      }
    }

    destruct(this_object());
    return 0;
}    

void alternative_die(object me)
{
fullup(me);
}

void unconcious(object who)
{
  if (who->query("kee")<0 || who->query("sen")<0) alternative_die(who);
   else unconcious(who);
}

void die(object who)
{
if ( userp(who) )
    alternative_die(who);
else destruct(who);
}

void fullup(object obj) {
  if (!obj) return;
  obj->set("kee",(int)obj->query("max_kee"));
  obj->set("eff_kee",(int)obj->query("max_kee"));
  obj->set("sen",(int)obj->query("max_sen"));
  obj->set("eff_sen",(int)obj->query("max_sen"));
  obj->set("force",(int)obj->query("max_force")*2);
  obj->set("mana",(int)obj->query("max_mana")*2);
}

int save_room()
{
string file;

file=this_object()->query_save_file();

write("存档 ．．．．．\n");
if( save() ) {
	write("保存成功.\n");
	return 1;
	} else {
        write("等系统更新，房间自然会恢复原状，您尽情涂鸦吧。\n");
       return 0;
        }
}

int do_kick(string arg)
{
object me,who;
me=this_player();

if ( !arg || arg==whos )
       return notify_fail("你确定有这个客人？\n");

who=find_player(arg);

if ( !who|| !userp(who) )  
       return notify_fail("没有这个人......\n");

if ( present(who,this_object() ) )
  {
  who->move("/d/city/kezhan");
  message_vision("$N被$n从"+this_object()->query("short")+"赶了出来！\n",who,me);
  }
who->delete_temp("player-room/onwer");
tell_object(who,me->name()+"不再准备邀请你了！\n");
tell_object(me,"你改变主意，决定不再邀请"+who->name()+"！\n");
return 1;
}

