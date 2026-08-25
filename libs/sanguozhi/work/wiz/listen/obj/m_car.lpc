#include <move.h>
inherit NON_ROOM;
inherit M_SMARTMOVE;
inherit M_MESSAGES;
string short();
string get_riders_as_string();
private string mount_msg = "$N跳入车中。" ;
private string dismount_msg= "$N打开车门，走下车来。";
private string arrival_msg= "开着一辆车飞驰而来。\n";
private string departure_msg="开着车向远方离去。\n";

private int m_att_abi=0;

private string owner="";
private int can_ride_two = 0;

int get_the_number_on_horse()
{
  // Get the inventory of the horse.
  object * inv = all_inventory(this_object());
  // Filter out anything that isn't living.
  object * riders = filter(inv, (: $1->is_living() :));
  return sizeof(riders);
}

void set_attack_ability(int p_attack)
{
  m_att_abi=p_attack;
}

int query_attack_ability()
{
	return m_att_abi;
}

protected void set_arrival_msg(string s){
  arrival_msg = s;
}
protected void set_departure_msg(string s){
  departure_msg = s;
}
string get_arrival_msg(){
  return get_riders_as_string()+arrival_msg;
}
string get_departure_msg(){
  return get_riders_as_string()+departure_msg;
}

//### this isn't right, but I didn't want to redesign _too_ much just yet
string *get_player_message(string message, mixed arg) {
    string mess;
    if ( message == "leave" )
      {
    mess = get_departure_msg();
      }
    else if ( message == "enter" )
      {
    mess = get_arrival_msg();
      }
    return action( ({ this_object() }), mess, arg);
}

string query_final_exit_value(string str, int is_normal)
{
  string ret;
  if((!(ret = ::query_exit_value(str, is_normal)) || ret[0] == '#')
     && environment())
    return environment()->query_exit_value(str, is_normal);
  return ret;
}
int can_travel(){
  return 1;
}

object * get_riders(){
  return filter(all_inventory(this_object()), (:$1->is_living():));
}
string show_contents(){
  if(environment(this_body()) != this_object())
    return inventory_recurse(0, get_riders());
  return "";
}

string get_riders_as_string()
{
  // Get the inventory of the horse.
  object * inv = all_inventory(this_object());
  // Filter out anything that isn't living.
  object * riders = filter(inv, (: $1->is_living() :));
  if(!sizeof(riders))
    {
      return "";
    }
  // Return a string that's a comma seperated list of the riders.
  if(sizeof(riders) == 1)
    {
      return riders[0]->short();
    }
  return implode(map(riders[0..<2], (: $1->short() :)), "、")+ "和" +
    riders[<1]->short();
}
string query_in_room_desc()
{
  string base_desc = ::query_in_room_desc();
  if(!inventory_visible() || !sizeof(get_riders())) {
      return base_desc;
    }
  else {
      string p_tmp;
      switch(random(5))
      {
                case 0:
                        p_tmp="雄赳赳地";
                        break;
                case 1:
                        p_tmp="得意洋洋地";
                        break;
                case 2:
                        p_tmp="充满自信地";
                        break;
                case 3:
                        p_tmp="大大方方地";
                        break;
                default:
                        p_tmp="舒舒服服地";
                        break;
      }
      if(sizeof(get_riders())==2)
      switch(random(3))
      {
             case 0:
                    p_tmp="得意洋洋地";
                        break;
             case 1:
                    p_tmp="大大方方地";
                    break;
             default:
                    p_tmp="舒舒服服地";
                    break;
      }
      return get_riders_as_string()+p_tmp+"坐在"+short()+"上\n";
    }
}
void notify_move()
{
    object *inv;
    object curr;
    inv = all_inventory(this_object());
    foreach(curr in inv)  {
        if(curr->query_link())
            curr->force_game_command("look");
    }
}
int is_vehicle(){
  return 1;
}
int is_horse() {
  return 1;
}
protected void set_ride_msg(string s){
  mount_msg = s;
}
protected void set_unride_msg(string s){
  dismount_msg = s;
}
string query_ride_msg() {
  return mount_msg;
}
string query_unride_msg() {
  return dismount_msg;
}
string handle_exit_msgs(object last_loc) {
  return query_ride_msg() || //"$N $vget on "+short()+".\n";
                               "$N坐上了"+short()+"。\n";  
}
private void mount_it_already()
{
  if(environment(this_body()) == this_object())  {
      write("你已经坐在车上了。\n");
      return;
    }
  if(this_body()->move(this_object())==MOVE_OK)
	  this_body()->simple_action(mount_msg);
  else
      this_body()->simple_action(
"$N想跳上"+short()+"，结果没上去掉了下来。\n");
}

private void mount_it_already_other(object o)
{
	string p_id=o->query_id()[0];
	if(environment(o) == this_object())  {
      tell_user(p_id,"你已经坐在车上了。\n");
      return;
    }
  if(o->move(this_object())==MOVE_OK)
	  o->simple_action(mount_msg);
  else
      o->simple_action(
"$N想跳上"+short()+"，结果没上去掉了下来。\n");
}

void agree(object me,object own,string ans)

{
        switch(ans)
        {
                case "up":
own->targetted_action("$N对$T道：$m$c就请上来吧。\n",me);
            mount_it_already_other(me);
        me->clear_answer();
                        return;
                default:
    own->targetted_action("$N对$T道：不行，不行，车子太挤了。\n",me);
		me->responda("kick "+owner);
        me->clear_answer();
        return;
        }
}

void ride()
{
  string p_id;
  object * rids;
  int s;
  p_id = this_body()->query_id()[0];
  if((p_id==owner)||(owner==""))
  {
	mount_it_already();
	return;
  }
  rids=get_riders();
  s=sizeof(rids);
  if((s==0)||( (s==1)&&(rids[0]->query_id()[0]!=owner ) )) {
  	this_body()->simple_action(
		"$N伸手想打开"+short()+"的车门，却被电了一下。\n");
	this_body()->simple_action( short()
 	     +"对着$N发出剧烈的警报声：大家快来啊，有人偷车啊!\n");
        return;
  }
/*
  if(s>=4)  {
	  write("车上已经没位置了。\n");
	  return;
  }
*/
  // now seem ok to ask
  this_body()->targetted_action(
	  "$N对$T道：$m$c，可否让$C与$c一同坐车？\n",rids[0]);

  this_body()->set_answer(owner, (: agree :));
  rids[0]->responda("consider");
  tell_user(owner,"同意吗？同意就请输入 answer up to "+p_id+"\n");

}
mixed stand()
{
  return query_unride_msg() ;
}
int unride()
{
  if(environment(this_body()) != this_object())
    return 0;
  return stand();
}
int direct_unride_obj()
{
  return 1;
}
int direct_ride_obj()
{
  return 1;
}
int stat_me() {
    printf("房间: %s [ %s ]\n\n",
      short(), implode(query_exit_directions(1), ", "));
    ::stat_me();
    return 1;
}
void do_looking(int forced_look)
{
    this_look_is_forced = forced_look;
    if ( wizardp(this_body()) &&
      this_body()->query_shell_ob()->get_variable("show_loc") )
    {
    printf("[%s]\n", file_name(this_object()));
    }
    if ( environment(this_object())->query_light() < 1 )
    {
    write("这里很黑，什么也看不清楚。\n");
    }
    else
    {
        object * riders = filter(all_inventory(this_object()), (:
$1->is_living() :));

	printf("%s [exits: %s]\n",
	       environment(this_object())->get_brief(), 
	       environment(this_object())->show_exits());
	write(wrap(get_location_description()));
        if(sizeof(riders) == 1)
        {
                printf("你坐在%s上。\n",short());
        }
        else 
        {
                object oth;
                if (riders[0]==this_body())
                        oth=riders[1];
                else
                        oth=riders[0];
                printf("你和%s坐在%s上。\n",oth->short(),short());
        }
    }
}
varargs string inventory_recurse(int depth, mixed avoid) 
{
    return "";
}
void set_owner(string man_id)
{
  owner=man_id;
}
string query_owner()
{
	return owner;
}
int direct_ridetwo_obj()
{
  return 1;
}
int direct_rideone_obj()
{
  return 1;
}
