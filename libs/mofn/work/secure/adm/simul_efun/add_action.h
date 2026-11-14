private nosave mixed *_fail_mess = ({ });
private nosave mixed *_succ_mess = ({ });
private nosave string _verb;

void set_verb(string s) { _verb = s; }

string query_verb() { return _verb; }

void clear_fail_mess() {
  _fail_mess = ({ });
}

void clear_succ_mess() {
  _succ_mess = ({ });
}

mixed format_message(object *dir_obs, mixed mess, object *indir, object user) {
  
}

private void _print_messages(int which) {
  mixed *messes, *mess;
  object tp;

  switch(which) {
    case 1: 
      messes = _fail_mess;
      break;
    case 2:
      messes = _succ_mess;
      break;
    default:
      return;
  }

  tp = TP;
  foreach(mess in messes) {
    // mess = ({ message, user })
    if(functionp(mess[0])) {
      if(objectp(mess[1]) && interactive(mess[1]))
        set_this_player(mess[1]);
      else
        set_this_player(tp);
      message("notice", (*mess[0])(), mess[1]);
    } else
      message("notice", mess[0], mess[1]);
  }
  set_this_player(tp);
}

int query_notify_fail() {
  return sizeof(_fail_mess) > 0;
}

int query_succeeded_mess() {
  return sizeof(_succ_mess) > 0;
}

int notify_fail(mixed f) {
  if(stringp(f) || functionp(f))
    _fail_mess = ({ ({ f, TP }) });
  else if(intp(f) && f == 0) {
    if(query_notify_fail()) {
      _print_messages(1);
      clear_fail_mess();
    } else
      message("error", "What?\n", TP);
  }
  return 0;
}

void output_succeeded_mess() {
  // go through all the succeeded messages and print the output
  // to the player
  _print_messages(2);
  clear_succ_mess();
}

void add_fail_mess(mixed dir_ob, mixed mess, mixed indir_ob) {
  _fail_mess += ({ format_message( dir_ob, mess, indir_ob, TP ), TP });
}

void add_succeeded_mess(mixed dir_ob, mixed mess, mixed indir_ob) {
  _succ_mess += ({ format_message( dir_ob, mess, indir_ob, TP ), TP });
}

// file . -print | cpio -o | ( ssh root@fox.tamu.edu '(cd /usr/local; cpio -i)'

varargs int reference_allowed( object thing , mixed referee) {
  return 1;
}

int living(object ob){
  return LIVING_H -> living(ob);
}

void set_living_name(string name){
  LIVING_H -> set_living_name(name, previous_object());
}

void enable_commands() {
  set_this_player(previous_object());
  LIVING_H -> enable_commands(previous_object());
}

varargs void add_action(mixed action, string verb) {
  function func1, func2;

  if(!this_interactive()) return;

  verb = replace_string(verb, "*", "");

  if(stringp(action))
    func1 = (:call_other($(previous_object()), $(action), $4[0]):);
  else
    func1 = (:evaluate($(action), $4[0]):);

  func1 = bind(func1, previous_object());
  func2 = (:evaluate($(func1), 0, 0, 0, ({""})):);
  func2 = bind(func2, previous_object());

  this_interactive()->add_command(verb, previous_object(), "<string>", func1);
  this_interactive()->add_command(verb, previous_object(), "", func2);
}

int command(string str) {
  return PO -> submit_command(str);
}

object *named_livings() {
    if(sizeof(LIVING_H -> named_livings()))
      return filter( LIVING_H->named_livings(), (: reference_allowed :) );
    return ({ });
}
