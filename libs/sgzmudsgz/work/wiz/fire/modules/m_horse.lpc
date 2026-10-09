// m_horse.c by fire on Jan 9 1998
inherit NON_ROOM;
inherit M_SMARTMOVE;
inherit M_MESSAGES;
string short();
string get_riders_as_string();
private string mount_msg = "$N翻身上马。" ;
private string dismount_msg= "$N一翻身，跳下马来。";
private nosave string arrival_msg= "骑着一匹战马奔驰而来。\n";
private nosave string departure_msg="骑在马上向远方离去。\n";
protected void set_arrival_msg(string s)
{
  arrival_msg = s;
}
protected void set_departure_msg(string s)
{
  departure_msg = s;
}
string get_arrival_msg()
{
  return get_riders_as_string()+arrival_msg;
}
string get_departure_msg()
{
  return get_riders_as_string()+departure_msg;
}
//### this isn't right, but I didn't want to redesign _too_ much just yet
string *get_player_message(string message, mixed arg) {
    string mess;
    if ( message == "leave" )
      {
    mess = get_departure_msg() ||  //"The $N $vleave $o.\n";
                                 "$N离开了$o。\n";
      }
    else if ( message == "enter" )
      {
    mess = get_arrival_msg() || //"The $N $venter.\n";
                                  "$N走了进来。\n";
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
int can_travel()
{
  return 1;
}
object * get_riders()
{
  return filter(all_inventory(this_object()), (:$1->is_living():));
}
string show_contents()
{
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
      return 0;
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
  if(!inventory_visible() || !sizeof(get_riders()))
    {
      return base_desc;
    }
  else
    {
      return base_desc+"马上骑着"+get_riders_as_string()+"。\n";
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
int is_vehicle()
{
  return 1;
}
protected void set_get_on_msg(string s)
{
  mount_msg = s;
}
protected void set_get_off_msg(string s)
{
  dismount_msg = s;
}
string query_get_on_msg()
{
  return mount_msg;
}
string query_get_off_msg()
{
  return dismount_msg;
}
string handle_exit_msgs(object last_loc)
{
  return query_get_on_msg() || //"$N $vget on "+short()+".\n";
                               "$N站上了"+short()+"。\n";  
}
private void mount_it_already()
{
  if(environment(this_body()) == this_object())
    {
      write("你已经骑在马上了。\n");
      return;
    }
  this_body()->move_to(file_name(this_object()), short());
}
void get_on()
{
  mount_it_already();
}
mixed stand()
{
  return query_get_off_msg() ;
}
int get_off()
{
  if(environment(this_body()) != this_object())
    return 0;
  
  return stand();
}
int direct_get_off_obj()
{
  return 1;
}
int direct_get_on_obj()
{
  return 1;
}
mixed is_horse()
{
	return 1;
}
