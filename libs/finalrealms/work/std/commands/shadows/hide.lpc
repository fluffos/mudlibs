/* The hide in shadows shadow.  Cute huh?
 */

#define LEVEL_MOD 2
object tp;
int found;

void dest_hide_shadow();

void setup_shadow(object ob) {
   if(ob->query_hide_shadow())
   {
      return;
   }
  tp = ob;
  shadow(ob,1);
}

int attack_by(object him)
{
  dest_hide_shadow();
  return tp->attack_by(him);
}

int cast(string str)
{
  dest_hide_shadow();
  return tp->cast(str);
}

int attack_ob(object him)
{
  dest_hide_shadow();
  return tp->attack_ob(him);
}

object *move_player(string dir, string dest, string mess, object ob) {
  if ( !ob || ob != tp )
    dest_hide_shadow();
  return (object *)tp->move_player(dir, dest, mess, ob);
}

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
  dest_hide_shadow();
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
  call_out("do_dest_hide_shadow",0);
  found = 1;
}

void do_dest_hide_shadow() {
  destruct(this_object());
}

int query_hide_shadow()
{
  int i;
  i = random((int)tp->query_level() * LEVEL_MOD );
  i = (i==0) ? 1 : i;
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

