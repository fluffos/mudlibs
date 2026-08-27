inherit "/obj/monster";
#define COMM_ROOM "/d/am/uu/uni/comm_room"
#define CHAR "/std/spells/wizard/chars/"

object my_player,
       caster,
       notebook;
string thingy;

void start_home(string s1, object ob);

void setup() {
  set_name("demon");
  set_long("A small demon with a large note book.  He is looking "
           "furtively around the room.  He seems in somewhat of a hurry.\n");
  notebook = clone_object("/std/object");
  notebook->set_name("notebook");
  notebook->add_alias("book");
  notebook->add_plural("books");
  notebook->add_adjective(({ "large", "note" }));
  notebook->set_long("A large note book, it looks almost brand new.\n");
  notebook->set_short("large note book");
  notebook->move(this_object());
  add_property("demon", 1);
} /* setup() */

/* Who says you can kill my nice demon? */
void adjust_hp(int hp, object at) {
} /* adjust_hp() */

void set_caster(object ob) {
  caster = ob;
} /* set_caster() */

void event_person_say(object ob, string start, string mess, string lang) {
  string s1, s2, s3;
  string *bits;

  if (ob == caster && !my_player) {
    if (sscanf(mess, "%s@%s", s1, s2) != 2)
      init_command("'I don't understand!");
    else {
      bits = explode(s1+"%", " ");
      if (!bits || !sizeof(bits)) {
        init_command("'I don't understand!");
        return ;
      }
      s3 = bits[sizeof(bits)-1];
      s3 = s3[0..strlen(s3)-2];
      bits = explode(s2, " ");
      if (!bits || !sizeof(bits)) {
        init_command("'I don't understand!");
        return ;
      }
      s3 += "@"+bits[0];
      init_command("'Ok, I am off to finger "+s3+".");
      call_out("start_home", 0, s3, caster);
    }
  }
} /* event_person_say() */

/* Off we rush! */
void start_home(string str, object bing) {
  mixed *co_ords;

/* we are already doing silly things.  Patience please. */
  if (my_player)
    return ;
  thingy = str;
  my_player = bing;
  co_ords = COMM_ROOM->query_co_ord();
  add_property("goto co-ordinates", co_ords);
  add_property("goto property", "communication room");
  add_triggered_action("finger", "goto_co_ord", this_object(), "got_home");
} /* start_home() */

void got_home(int bing) {
  if (!bing) {
/* Damn. */
    move_player("X", COMM_ROOM);
  }
  tell_room(environment(),
      short(0)+" wanders over to one of the black windows and taps some "
      "keys madly.  It then stares intently into the window.\n");
  init_command("finger "+thingy);
} /* got_home() */

void got_player(int bing) {
  if (!bing) {
/* Froodle buns */
    move_player("X", environment(my_player));
  }
  init_command("give note book to "+my_player->query_name());
  init_command("smile "+my_player->query_name());
  call_out("go_away", 20);
} /* got_player() */

void finger_callback(int type, string mess) {
  switch (type) {
    case 0 :
/* We are off! */
/*
 * Will try and find the owner.  Stuff it.  At this point teleport and
 * give it to them.
 */
      tell_room(environment(),
              short(0)+" scribbles something hurridly down in its notebook.\n");
      if (!my_player) {
/* Arrrgghhh! */
        command("cry");
        command("'I have been deserted!");
        init_command("sigh");
        call_out("go_away", 10);
        return ;
      }
/*
      move_player("X", file_name(environment(my_player)));
      init_command("give note book to "+my_player->query_name());
      call_out("go_away", 10);
 */
/* Ok, now we try and find our pooooor little player.  pat pat */
      add_property("goto player", my_player->query_name());
      add_triggered_action("player", "goto_player", this_object(),
                           "got_player");
      break;
    case 1 :
/* Got an error.  drats */
      tell_room(environment(), short(0)+" looks carefully at the window "
                "and frowns.\n");
      notebook->set_read_mess("Got an error during "+mess+"\n");
      notebook->add_read_mess(({ CHAR+"finger_demon", "warning" }), 0,
                              "wizard spells", 0);
      break;
    case 2 :
/* Real info */
      tell_room(environment(), short(0)+" stares into the window then "
                "suddenly scribbles something down on its notebook.\n");
      notebook->set_read_mess(mess);
      notebook->add_read_mess(({ CHAR+"finger_demon", "warning" }), 0,
                              "wizard spells", 0);
      break;
  }
} /* finger_callback() */

string garble_text(mixed bing, object ob) {
  call_out("do_dest", 10, ob);
  return "Warning, this note will self destruct in ten seconds.\n";
} /* warning() */

string magic_text(mixed bing, object ob) {
  call_out("do_dest", 10, ob);
  return "Warning, this note will self destruct in ten seconds.\n";
} /* warning() */

void do_dest(object ob) {
  object ob2;

  if (!ob) return ;
  ob2 = environment(ob);
  if (living(ob2)) {
    tell_room(environment(ob2), ob2->query_cap_name()+"'s "+
              ob->short()+" spontaneously combusts.\n", ({ ob2 }));
    tell_object(ob2, "Your "+ob->short()+" spontaneously combusts.\n");
  } else {
    tell_room(ob2, ob->short()+" spontaneously combusts.\n");
  }
  ob->dest_me();
} /* do_dest() */

void go_away() {
  command("wave");
  tell_room(environment(), short(0)+" becomes slowly more transperent "
                           "and then vanishes utterly.\n");
  dest_me();
} /* go_away() */
