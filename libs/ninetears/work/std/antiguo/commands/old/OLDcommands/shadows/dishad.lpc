/*
    Dissapear, high level thief skill
    Taniwha
    Backstab and steal are suppressed while this is active
 */
#define LEVEL_MULT 4
#define THRESH 10
object tp;
int found;
void dest_hide_shadow();
void setup_shadow(object ob) {
  tp = ob;
  shadow(ob,1);
  tp->add_static_property("noguild",1);  /* supress everything else */
}
attack_by(object him)
{
  dest_hide_shadow();
  return tp->attack_by(him);
}
attack_ob(object him)
{
  dest_hide_shadow();
  return tp->attack_ob(him);
}
/*
object *move_player(string dir, string dest, string mess, object ob) {
  dest_hide_shadow();
  return (object *)tp->move_player(dir, dest, mess, ob);
}
*/

int do_death(string str) {
  dest_hide_shadow();
  return (int)tp->do_death(str);
}
int do_loud_say(string str) {
  dest_hide_shadow();
  return (int)tp->do_loud_say(str);
}
int do_emote(string str) {
  dest_hide_shadow();
  return (int)tp->do_emote(str);
}
int do_echo(string str) {
  dest_hide_shadow();
  return (int)tp->do_echo(str);
}
int do_say(string str) {
  dest_hide_shadow();
  return (int)tp->do_say(str);
}
int event_player_search() {
  if(random((int)tp->query_level() * LEVEL_MULT) < THRESH)  dest_hide_shadow();
  else tell_object(tp,"You escape the search!\n");
}
int soul_com(string str) {
  int i;
  if ((i = (int)tp->soul_com(str)) == 1)
    dest_hide_shadow();
  return i;
}
void dest_hide_shadow() {
  tell_room(environment(tp), "You notice "+tp->query_cap_name()+" nearby.\n",
            ({ tp }));
  tell_object(tp, "You have been noticed.\n");
  tp->remove_static_property("noguild");
  call_out("do_dest_hide_shadow",0);
  found = 1;
}
void do_dest_hide_shadow() {
  destruct(this_object());
}
int query_hide_shadow()
{
  int i;

  i = random((int)tp->query_level()/2) + (int)tp->query_level() / 4;
  i =  (i==0) ? 1 : i;
  return i;
}
string pretty_short() { 
  if (found && tp)
    return (string)tp->pretty_short();
  return 0;
}
string short() {
  if (found && tp || (query_verb() && query_verb() == "who"))
    return (string)tp->short();
  return 0;
}
string pretty_plural() {
  if (found && tp)
    return (string)tp->pretty_plural();
  return 0;
}
string query_plural() {
  if (found && tp)
    return (string)tp->query_plural();
 return 0;
}

