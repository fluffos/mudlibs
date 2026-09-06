/* The bed, where players can "sleep" in while being absent */

inherit "/std/thing";

object player;
int    max_hp;

varargs void create()
{
  (::create());
  SetShort("a bed");
  SetLong(
"This is the bed where the owner can 'sleep' in while being outside of "
"AoH. If he want to wake up every log on here, he should feel at "
"'home'. Or he can 'relax' for to get new power.\n");
  AddId("bed");
  SetWeight(100000);
  SetValue(1233);
  SetNoGet("You can't take the bed away.\n");
}

void init()
{
  (::init());
  if(!({int})environment()->QueryIsOwner(getuid(this_player()))) return;
  add_action("sleep","sleep");
  add_action("home","home");
  add_action("relax","relax");
  add_action("wake_up","wake");
  add_action("wake_up","awake");
}

int sleep(string str)
{
  return ({int})this_player()->command_me("quit" + (str?" " + str:""));
}

int home(string str)
{
  string home;

  if(str) {
    notify_fail("Just type 'home'!\n");
    return 0;
  }
  if((home = object_name(environment())) == ({string})this_player()->QueryHome()) {
    notify_fail("You already live here.\n");
    return 0;
  }
  this_player()->SetHome(home);
  write("You choose this room as your new home.\n");
  say(capitalize(getuid(this_player())) + " now lives here.\n");
  return 1;
}

int relax(string str)
{
  if(str) {
    notify_fail("Just 'relax'!\n");
    return 0;
  }
  if(player) {
    notify_fail("You are already relaxing.\n");
    return 0;
  }
  set_heart_beat(1);
  max_hp = ({int})this_player()->QueryMaxHP();
  player = this_player();
  write("You lay down and relax a little bit.\n");
  say(capitalize(({string})this_player()->QueryName()) + " lays down and relax.\n");
  return 1;
}

int wake_up(string str)
{
  switch(query_verb()) {
  case "wake": if(!str && str != "up") {
      notify_fail("What do you want to wake?\n");
      return 0;
    }
    break;
  case "awake": if(str) {
      notify_fail("What do you want to awake?\n");
      return 0;
    }
    break;
  default: return 0;
  }
  if(player != this_player()) {
    notify_fail("You don't relax!\n");
    return 0;
  }
  player = 0;
  write("You awake...\n");
  say(capitalize(({string})this_player()->QueryName()) + " awakes and leaves the bed.\n");
  set_heart_beat(0);
  return 1;
}

void heart_beat()
{
  int spellp;
  int hitp;

  if(!player || !present(player)) {
    player = 0;
    set_heart_beat(0);
    return;
  }
  if((hitp = ({int})player->QueryHP()) >= max_hp) {
    tell_object(player,"Now you have relaxed enough and awake again.\n");
    tell_room(environment(),capitalize(({string})player->QueryName()) +
	      " awakes and leaves the bed.\n",({player}));
    player = 0;
    set_heart_beat(0);
    return;
  }
  if(!(spellp = ({int})player->QuerySP())) {
    tell_object(player,"You can't sleep anymore an awake.\n");
    tell_room(environment(),capitalize(({string})player->QueryName()) +
	      " awakes and leaves the bed.\n",({player}));
    player = 0;
    set_heart_beat(0);
    return;
  }
  if(!random(5)) {
    tell_object(player,"You are sleeping with the angels...\n");
    tell_room(environment(),capitalize(({string})player->QueryName()) +
	      " sleeps in the bed.\n",({player}));
  }
  player->SetHP(hitp+1);
  player->SetSP(spellp-1);
}

