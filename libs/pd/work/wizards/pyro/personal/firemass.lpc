// original board code stolen from /wizards/seeker/box.c

#include <std.h>
#include <bboard.h>
#include <daemons.h>

//inherit OBJECT;
inherit BAG;

#define DRAGTITLE "Astral Dragon $N the Capable"
#define ANGTITLE "$N, archbishop of cheese legion"
#define FIGHTTITLE "$N the legendary red dragon"

mapping title;
string tm;

int fix_stats();

void create()
{
  ::create();
  set_name("mass of fire");
  set_short("%^RED%^a pulsating mass of pure fire%^RESET%^");
  set_long("The mass pulsates and quivers. It seems to have no form, and yet have every form at once.");
  set_id( ({ "mass", "mass of fire", "mass of pure fire", "fire", "MUD_Master_Key" }) );
  set_mass(1);
  set_curr_value("gold", 0);
  set_max_internal_encumbrance(99999);
  set("no store", 1);
  set_property("no steal", 1);
  set_property("no auction", 1);
  set_read("default", "Commands:\n"
   "<godragon> - makes you a astral dragon\n"
   "<gorogue> - makes you an archangel rogue\n"
   "<gofight> - makes you a lvl50 red dragon\n"
   "<blist> - lists all the boards\n"
   "<bread> - attempts to read any unread posts\n"
   "<bpost on [board]> - posts on a certain board.\n"
   "<makewax> - creates a new ball of wax.\n"
   "Properties:\n"
   "Master key - should open any door");
}

void init()
{
  ::init();
  add_action("__list", "blist");
  add_action("__read", "bread");
  add_action("__post", "bpost");
  add_action("go_dragon", "godragon");
  add_action("fix_stats", "fixstats");
  add_action("go_rogue", "gorogue");
  add_action("go_fight", "gofight");
  add_action("make_wax", "makewax");
}

int __post(string str) {
  string *st, b;
  if(!wizardp(this_player())) return notify_fail("The power would destroy you.\n");
  if (!str || str=="")
    return notify_fail("Post on which board?\n");
  if (sscanf(str, "on %s", b) != 1)
    return notify_fail("Post on which board?\n");
  st = get_dir(BBOARD_DIR);
  if (!st)
    return notify_fail("That board doesnt exist.\n");
  if (member_array(b+".o", st)==-1)
    return notify_fail("That board doesnt exist.\n");

  if (!title) title = ([]);
  /*
      if((int)BBOARD_D->get_num_posts(b) >= max_posts) {
          notify_fail("You will first have to remove a note!\n");
          return 0;
      }
  */
  if(strlen(str) > 30) {
    notify_fail("Title cannot contain more than 30 characters.\n");
    return 0;
  }
  if(title[this_player()]) write("Warning! You are already marked as posting!");
  title[this_player()] = str;
  tm = b;
  write("Edit post.\n");
  this_player()->edit(BBOARD_EDIT+(string)this_player()->query_name(),"postit", this_object());
  return 1;
}

varargs int postit() {
  int x;

  x = (int)BBOARD_D->post_message(tm, title[this_player()]);
  if(x == BBOARD_OK) write("Posted.\n");
  else if(x == EDIT_ABORT) write("Edit aborted.\n");
  else if(x == BAD_DATA) write("Error in posting call.\n");
  map_delete(title, this_player());
  return 1;
}

int __read() {
  string *str, tmp;
  int i, read;
  int number;
  mapping msg;
  string *lines;
  object tp = this_player();

  if(!wizardp(tp)) return notify_fail("The power would destroy you.\n");

  if (!i = sizeof(str = get_dir(BBOARD_DIR)))
    return notify_fail("Board error!\n");

  while(i--)
  {
    sscanf(str[i], "%s.o", tmp);
    read =(int)BBOARD_D->get_num_read(tmp, (string)tp->query_name());
    if ((int)BBOARD_D->get_num_posts(tmp)-read > 0)
    {
      number = 1 + (int)BBOARD_D->get_new_post(tmp, (string)tp->query_name());
      msg = (mapping)BBOARD_D->get_message(tmp, number-1);
      if(!msg) {
        notify_fail("Invalid message number.\n");
        return 0;
      }
      lines = ({ ""+tmp +" board post #"+number+" by "+capitalize(msg["owner"])+", subject:
"+msg["title"] });

      lines += explode(msg["message"], "\n");
      tp->more(lines);
      BBOARD_D->set_read(tmp, (string)tp->query_name(), number-1);
      return 1;
    }

  }
}

int __list(string tt) {
  string *str, out, tmp;
  int read, unread, i;
  object tp = this_player();
  if(!wizardp(tp)) return notify_fail("The power would destroy you.\n");
  if (tt) return 0;
  write("Here are your current unread posts:"); 
  if (!i = sizeof(str = get_dir(BBOARD_DIR)))
    return notify_fail("Problem get_dir for "+BBOARD_DIR+" failed.\n");
  while(i--)
  {
    sscanf(str[i], "%s.o", tmp);
    read =(int)BBOARD_D->get_num_read(tmp, (string)tp->query_name());
    if (read==-1)
    {
      write(tmp+": 0");
      continue;
    }
    unread = (int)BBOARD_D->get_num_posts(tmp)-read;
    out = arrange_string(arrange_string(tmp, 17)+": ["+""+unread+"]", 25); 

    if ((i-1) > 0)
    {
      sscanf(str[i-1], "%s.o", tmp);
      read =(int)BBOARD_D->get_num_read(tmp,(string)tp->query_name());
      if (read==-1)
      {
        write(tmp+": 0");
        continue;
      }

      out +=
      arrange_string(arrange_string(tmp,17)+": ["+(BBOARD_D->get_num_posts(tmp)-read)+"]",25);
      i--;
    }
    if ((i-2) > 0)
    {
      sscanf(str[i-2], "%s.o", tmp);
      read =(int)BBOARD_D->get_num_read(tmp,(string)tp->query_name());
      if (read==-1)
      {
        write(tmp+": 0");
        continue;
      }

      out +=
      arrange_string(tmp,17)+": ["+(BBOARD_D->get_num_posts(tmp)-read)+"]";
      i--;
    }
    write(out);
  }
  return 1;
}

int go_fight(string str) {
  if(!wizardp(this_player())) return notify_fail("The power would destroy you.\n");

  this_player()->set_race("dragon");
  this_player()->set_class("dragon");
  this_player()->set_subclass("red");
  this_player()->set_gender("male");
  this_player()->new_body();
  this_player()->fix_skills();

  this_player()->set_stats("strength", 120);
  this_player()->set_stats("dexterity", 120);
  this_player()->set_stats("charisma", 120);
  this_player()->set_stats("constitution", 120);
  this_player()->set_stats("intelligence", 120);
  this_player()->set_stats("wisdom", 120);
  this_player()->set_level(50);
  this_player()->set_skill("flying", 175);
  this_player()->set_skill("perception", 200);
  this_player()->set_skill("defense", 325);
  this_player()->set_skill("melee", 275);
  this_player()->set_skill("attack", 275);
  this_player()->set_skill("breath", 250);
  this_player()->set_skill("claw", 225);
  this_player()->set_skill("tail", 225);

  this_player()->set_alignment(0);
  this_player()->remove_property("passive");

  this_player()->set_hp(this_player()->query_max_hp());
  this_player()->set_sp(this_player()->query_max_sp());
  this_player()->set_mp(this_player()->query_max_mp());

  this_player()->setenv("TITLE", FIGHTTITLE);
  return 1;
}

int go_dragon(string str) {
  object tp = this_player();

  if(!wizardp(tp)) return notify_fail("The power would destroy you.\n");
  tp->set_race("dragon");
  tp->set_class("dragon");
  tp->set_subclass("astral");
  tp->set_gender("neuter");
  tp->new_body();
  tp->fix_skills();
  tp->set_skill("breath", 5000);
  tp->set_skill("claw", 4500);
  tp->set_skill("tail", 4500);
  fix_stats();
  tp->setenv("TITLE", DRAGTITLE);
  return 1;
}

int go_rogue(string str) {
  object tp = this_player();

  if(!wizardp(tp)) return notify_fail("The power would destroy you.\n");
  tp->set_race("archangel");
  tp->set_class("rogue");
  tp->set_subclass("assassin");
  tp->set_gender("male");
  tp->new_body();
  tp->fix_skills();
  tp->set_skill("stealth", 5000);
  fix_stats();
  tp->setenv("TITLE", ANGTITLE);
  return 1;
}

int fix_stats() {
  if(!wizardp(this_player())) return notify_fail("The power would destroy you.\n");

  this_player()->set_stats("strength", 500);
  this_player()->set_stats("dexterity", 500);
  this_player()->set_stats("charisma", 500);
  this_player()->set_stats("constitution", 500);
  this_player()->set_stats("intelligence", 500);
  this_player()->set_stats("wisdom", 500);
  this_player()->set_level(1000);
  this_player()->set_skill("flying", 3500);
  this_player()->set_skill("perception", 4000);
  this_player()->set_skill("defense", 6000);
  this_player()->set_skill("melee", 5000);
  this_player()->set_skill("attack", 4500);

  this_player()->set_alignment(0);
  this_player()->set_property("passive", 1);

  this_player()->set_hp(this_player()->query_max_hp());
  this_player()->set_sp(this_player()->query_max_sp());
  this_player()->set_mp(this_player()->query_max_mp());

  return 1;
}

int query_auto_load() { return wizardp(this_player()); }

int get_wax(string str) { new("/d/nopk/tirun/obj/misc/seal_blank_new")->move(this_player()); return 1; }
int make_wax(string str) { if(!wizardp(this_player())) return 0; return get_wax(str); }
