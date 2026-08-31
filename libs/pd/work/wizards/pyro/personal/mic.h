int noInvis, doFollow, isInvincible;
string micName;
object owner, following;

void init() {
  ::init();
  if(!query_invis() && !noInvis)
    set_invis(1, "Mic stealthed.", "");
}

int query_no_invis() { return noInvis; }
void set_no_invis(int i) { noInvis = i; set_invis(!i, "Mic "+(i?"no longer ":"")+"stealthed.", ""); }

varargs void toggle_follow(int i) {
  if(!nullp(i)) doFollow = i;
  else doFollow = !doFollow;
  if(owner)
    receive_message("info", (doFollow?"Now ":"No longer ")+"following.");
}

void set_follow(object ob) {
  if(!ob) return;
  following = ob;
  doFollow = 1;
  set_heart_beat(1);
}

object query_follow() { return following; }

int is_invincible() { return isInvincible; }
int query_override_invincible() { return isInvincible; }
/*
int is_invincible() {
  if(sizeof(inherit_list(this_object())) && 
    function_exists("is_invincible", load_object(inherit_list(this_object())[0])))
    return ::is_invincible();
  return isInvincible;
}
*/
void set_invincible(int i) { isInvincible = i; }

void heart_beat() {
  ::heart_beat();
  if(!doFollow || !following || !this_object()) return;
  if(following->is_room()) {
    if(environment(this_object()) != following)
      if(!this_object()->move(following) && owner) {
        this_object()->receive_message("move", "You have moved to "+file_name(environment(this_object())));
        this_object()->receive_message("move", environment(this_object())->describe_living_contents());
      }
  }
  else if (environment(following)) {
    if(!environment(this_object()) || !present(following, environment(this_object()))) {
      if(!this_object()->move(environment(following)) && owner) {
        if(!this_object()) return;
        this_object()->receive_message("move", "You have moved to "+file_name(environment(this_object())));
        this_object()->receive_message("move", environment(this_object())->describe_living_contents());
      }
    }
  }
}

string query_microphone_name() { return micName; }
void set_microphone_name(string name) { micName = name; }

object query_owner() { return owner; }
void set_owner(object ob) { owner = ob; }

void receive_message(mixed type, mixed message) {
  object messageTo = owner;
  ::receive_message(type, message);
  if(!messageTo) return;
  while(!messageTo->is_living() && !messageTo->is_room()) {
    messageTo = environment(messageTo);
    if(!messageTo) return;
  }
  message("info", "%^BOLD%^%^CYAN%^~%^RESET%^%^GREEN%^"
    +query_microphone_name()+"%^BOLD%^%^CYAN%^~%^RESET%^ "
    +message, messageTo, this_object());
}

int remove() {
  receive_message("info", "Microphone object deleted.");
  return ::remove();
}

varargs void die(object killer) {
  receive_message("info", "Died"
    +(environment(this_object())?(" in "+file_name(environment(this_object()))):"")
    +(killer?(" to "+(killer->is_player()?capitalize(killer->query_name()):file_name(killer))):"")+".");
  return ::die(killer);
}
