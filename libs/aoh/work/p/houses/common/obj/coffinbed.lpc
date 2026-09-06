// The coffin, where players can "sleep" in while being absent
// similiar to the bed of the OEFC catalogue
// with the difference of the coffin:)
// this item is not only for the owner itself!!!
// it can be used as a guest-coffin for guest-vampires

inherit "/std/thing";

object player;
int    max_hp;

create()
{
  (::create());
  SetShort("a coffin");
  SetLong(
"This is the coffin where a vampire can 'sleep' in while being outside of "
MUDNAME ". If he want to wake up every log on here, he should feel at "
"his dark 'home'. Or he can 'relax' for to get new power for panda biting.\n");
  AddId("coffin");
  SetWeight(100000);
  SetValue(1233);
  SetNoGet(
    "You can't take the coffin away. But your hands are full of blood now.\n");
}

init()
{
  (::init());
  if(!environment()->QueryIsOwner(getuid(this_player()))) return;
  add_action("sleep","sleep");
  add_action("home","home");
  add_action("relax","relax");
  add_action("wake_up","wake");
  add_action("wake_up","awake");
//  add_action("open","open");    -> problems with vcoffin!
//  add_action("close","close");
}

/*
open(string str) {
  if(!str) return 0;
  if (str=="coffin") {
    if (open==1) {
      write("The coffin is already open.\n");
      say(this_player()->QueryName()+
        " tries to open the coffin, but fails.\n");
      return 1;
    }    
    open=1;
    write("You opened the coffin.\n"); 
    say(this_player()->QueryName()+" opens the coffin.\n");
    return 1;
  }
  notify_fail("what do you want to open?\n");
  return 0;
}

close(string str) {
  if (!str) return 0;
  if (str=="coffin") {
    if (open!=1) {
      write("You have to open the coffin first.\n");
      say(this_player()->QueryName()+" tries to close the coffin, but fails.\n");
      return 1;
    }
    open = 0;
    write("You close the coffin.\n");
    say(this_player()->QueryName()+" closes the coffin.\n");
    return 1;
  }
  notify_fail("What do you want to close?\n");
  return 0;
}
*/

sleep(string str)
{
  if (this_player()->QueryGuild()!="vampire") {
    notify_fail(
      "You cannot use the coffin - it is for vampires only.\n");
    return 0;
  }
  return this_player()->command_me("petrify" + (str?" " + str:""));
}

home(string str)
{
  string home;

  if(str) {
    notify_fail("Just type 'home'!\n");
    return 0;
  }
  if((home = object_name(environment())) == this_player()->QueryHome()) {
    notify_fail("You already live here.\n");
    return 0;
  }
  if (this_player()->QueryGuild()!="vampire") {
    write("You are no vampire and cannot use this coffin.\n");
    return 1;   // notify_fail doesn't works (home command!)
  }
  this_player()->SetHome(home);
  write("You choose this dark room as your new home.\n");
  say(capitalize(getuid(this_player())) + " now lives here.\n");
  return 1;
}

relax(string str)
{
  if(str) {
    notify_fail("Just 'relax'!\n");
    return 0;
  }
  if(player) {
    notify_fail("You are already relaxing.\n");
    return 0;
  }
  if (this_player()->QueryGuild()!="vampire") {
    write("Only vampires can relax in the coffin.\n");
    return 1;   // no notify_fail, cause the normal relax is working too
  }
  set_heart_beat(1);
  max_hp = this_player()->QueryMaxHP();
  player = this_player();
  write("You lay down and relax a little bit.\n");
  say(capitalize(this_player()->QueryName()) + 
    " lays down and dreams of blood of pandas.\n");
  return 1;
}

wake_up(string str)
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
  write("You awake... \n");
  say(capitalize(this_player()->QueryName()) + " awakes and leaves the coffin.\n");
  set_heart_beat(0);
  return 1;
}

heart_beat()
{
  int spellp;
  int hitp;

  if(!player || !present(player)) {
    player = 0;
    set_heart_beat(0);
    return;
  }
  if((hitp = player->QueryHP()) >= max_hp) {
    tell_object(player,"Now you have dreamed enough of panda blood.\n"
      "You awake again and will now search for a nice real panda to bite him.\n");
    tell_room(environment(),capitalize(player->QueryName()) +
	      " awakes and leaves the coffin.\n",({player}));
    player = 0;
    set_heart_beat(0);
    return;
  }
  if(!(spellp = player->QuerySP())) {
    tell_object(player,"You can't sleep anymore and awake.\n");
    tell_room(environment(),capitalize(player->QueryName()) +
	      " awakes and leaves the coffin.\n",({player}));
    player = 0;
    set_heart_beat(0);
    return;
  }
  if(!random(5)) {
    tell_object(player,
      "You are sleeping with the a nice dream. A dream of a sweet panda...\n");
    tell_room(environment(),capitalize(player->QueryName()) +
	      " sleeps in the coffin.\n",({player}));
  }
  player->SetHP(hitp+1);
  player->SetSP(spellp-1);
}
 
