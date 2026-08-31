
#include <std.h>
#include <security.h>
#include <dragonevent.h>
#include <daemons.h>

#define EVENT_DATE "August 9th, 2008"
#define EVENT_DIR "/d/events/dragonaug2008/"
#define FAIL(s) return notify_fail(s+"\n")

#define tp this_player()
#define to this_object()

inherit DAEMON;
inherit ROOM;

mapping myData = ([]);

void init_data();
void clear_data();
int saveme();
int restoreme();
void set_data(mixed, mixed);
mixed query_data(mixed);
void remove_beams(int);
void ogre_king_event_start();

void ogre_king_giveup(string);

void create() {
  init_data();
  restoreme();
  daemon::create();
  room::create();
  set_no_clean(1);
  set_properties( ([ "light" : 2, "indoors" : 1, "no scry" : 1, "no teleport" : 1 ]) );
  set_short("control room");
  set_long(
    "\nNorth: Cave of courage / old caves portal"
    "\nEast: Throne of Ogre King"
    "\nWest: 4-gem pillar"
    "\nSouth: Captured Black Dragon Platform"
    "\nDown: Entrance to New Ogre Caves"
    "Commands:"
    "\n"
    "<event trigger [trigger] [args]>, "
    "\n"
    "<event status>, "
    "<event scry [player]>, "
    "\n"
    "<event set [key] [value]>, "
    "<event query [key]>, "
    "\n"
    "<event save>, "
    "<event restore>, "
    "<event reset>, "
    "<event clear>, "
    "<event start> "
  );
  set_exits( ([
    "east" : DRAG_ROOMS"ogrekingentrance",
    "west" : DRAG_ROOMS"ogre86",
    "north" : DRAG_ROOMS"py/entrance",
      "south" : DRAG_ROOMS"ogre120",
    "down" : DRAG_ROOMS"ogre69",
  ]) );
}

void init() {
  room::init();
  if (tp && wizardp(tp)) {
    add_action("event_cmd", "event");
  }
}

void tell(string str) {
  if (str && strlen(str))
    message("info",
      str+"\n("+
      (previous_object() == to ? "" : "prev:"+identify(previous_object())+", ")+
      "tp:"+identify(tp)+")",
      to);
}

int event_cmd(string str) {
  string cmd, args;

  if (!str) str = "status";

  if (sscanf(str, "%s %s", cmd, args) < 2)
    cmd = str;

  return call_other(this_object(), "event_"+cmd, args);

}

int event_status(string str) {
  string *k;
  if (!sizeof(myData)) FAIL("Event data not initialized: <event reset> to do so.");
  k = keys(myData);
  tell(implode(efun::map(sort_array(k, 1), (: (identify($1)+": "+identify($2[$1])) :), myData), "\n"));
  return 1;
}

int event_reset(string str) {
  init_data();
  return 1;
}

int event_clear(string str) {
  clear_data();
  return 1;
}

int event_set(string str) {
  string k, v;
  mixed tmp;
  if (!str || sscanf(str, "%s %s", k, v) < 2) FAIL("Syntax: <event set [key] [value]>");
  tmp = to_int(v);
  set_data(k, (nullp(tmp) ? v : tmp) );
  return 1;
}

// this looks weird, but it will display in the room when any object sets/queries data
// this could be useful for debugging
int event_query(string str) {
  if (!str) FAIL("Syntax: <event query [key]>");
  tell("Query for "+str+": "+query_data(str));
  return 1;
}

int event_save(string str) {
  if (saveme())
    tell("Event data saved.");
  else
    tell("Error saving event data.");
  return 1;
}

int event_restore(string str) {
  switch (restoreme()) {
    case 1: tell("Event data restored from file."); break;
    case -1: tell("Error restoring event data: file does not exist."); break;
    default: tell("Error restoring event data.");
  }
  return 1;
}

int event_trigger(string str) {
  string trig, args;
  string *trigdata, *callargs;

  if (!str) str = "list";

  if (str == "list") {
    if (!sizeof(myData["triggers"])) FAIL("No triggers defined.");
    tell("Triggers:\n"+
      implode(efun::map(myData["triggers"], (: ($1[0]+": "+$1[1]+"->"+$1[2]) :) ), "\n")
    );
  }
  else {
    if (sscanf(str, "%s %s", trig, args) < 2) trig = str;
    trigdata = myData["triggers"][trig];
    if (!trigdata || !sizeof(trigdata)) FAIL("Trigger named "+trig+" does not exist.");
    callargs = ({ trigdata[2] });
    if (sizeof(args)) callargs += ({ args });
    call_other(load_object(trigdata[1]), callargs);
    tell("Triggered "+trig+": "+trigdata[1]+"->"+identify(callargs));
  }

  return 1;
}

int event_scry(string str) {
  object pl, room;
  string short, long, file, exits, livs, items;
  string *props;

  if (!str) FAIL("Scry whom?");

  if (!(pl = find_player(str))) FAIL("Nobody named \""+capitalize(str)+"\" logged on.");

  if (!(room = environment(pl))) FAIL(capitalize(pl->query_subjective())+" has no environment.");

  props = room->regexp_query_property(".*");
  props = efun::map(props, (: ($1+": "+identify($2->query_property($1))) :), room);
  short = room->query_short();
  long = room->query_long(0);
  file = file_name(room);
  exits = room->query_long_exits();
  livs = room->describe_living_contents();
  items = room->describe_item_contents();

  tell( 
    "%^BOLD%^%^BLUE%^"
    "=+=+=( Scry )+=+=+"
    "%^RESET%^\n"
    ""+file+"\n"
    ""+implode(props, ", ")+"\n"
    ""+short+"\n"+long+"\n"
    ""+exits+"\n\n"
    ""+livs+"\n"
    ""+items+"\n"
    "%^BOLD%^%^BLUE%^"
    "=+=+=+=+=+=+=+=+=+"
    "%^RESET%^"
  );

  return 1;
}

// completely clear out all data and only put back the bare minimum required to save/restore
void clear_data() {
  string *saveinfo;
  myData = ([]);
  saveinfo = path_file(base_name(this_object()));
  tell("Event data initialized.");
  myData["triggers"] = ({});
  if (sizeof(saveinfo) == 2) {
    myData["savepath"] = saveinfo[0]+"/";
    myData["savefile"] = saveinfo[1]+".o";
  }
}

// set all data to initial values which would be good for starting the event
// the "started" flag is not turned on here, though
void init_data() {
  clear_data();
  ogre_king_event_start();
  set_data("canProveCourage", 1);
  load_object(DRAG_ROOMS"instance_d")->
    destruct_instances_with_instance_id("Event Test Of Courage Instance");

  set_data("denyEntranceToPillarRoomViaDoor", 1);
  DOOR_D->set_closed("Ogre King Event's Door", 1);

  set_data("cankillgemogre", 1);
  set_data("canloadgemogre", 1);
  set_data("canchargegem", 1);
  set_data("cangathergems", 1);
  set_data("canloadcrystaldragon", 1);

  set_data("canfindportalpiece", 1);
  set_data("canfindogredagger", 1);

  set_data("speechguidedragon", -1);
  set_data("speechdragonelder", -1);
  set_data("speechdragonmage", -1);
  set_data("speechfinaldragon", -1);

  set_data("prisonbeams", 8);

  set_data("denyOldCaveEntrance", 1);
  // this is just a reminder to turn on later, eventstarted || allowdragonstofly is checked
  set_data("allowdragonstofly", 0);
}

void set_data(mixed key, mixed value) {
  if (!myData) clear_data();
  //edited by pyro -- should work even if value == 0
  if(key) myData[key] = value;
  tell("Set "+identify(key)+" to: "+identify(value));
  saveme();
}

mixed query_data(mixed key) {
  if (!myData || !key || !myData[key]) return 0;
//  tell("Query for "+identify(key)+": "+identify(myData[key]));
  return myData[key];
}

int saveme() {
  int ret;
  seteuid(UID_EVENT);
  ret = save_object(myData["savepath"]+myData["savefile"]);
  seteuid(getuid());
  return ret;
}
int restoreme() {
  int ret;
  string filename = myData["savepath"]+myData["savefile"];
  if (!file_exists(filename)) return -1;
  seteuid(UID_EVENT);
  ret = restore_object(filename);
  seteuid(getuid());
  return ret;
}

void ogre_king_spawn_guard(object pObj, string pName) {
  int spawnNum = random(2)+1;
  int currSpawns = spawnNum + query_data("ogreKingSpawns:"+pName);
  spawnNum += random(76-currSpawns)<15?1:0;
  spawnNum += random(76-currSpawns)==1?1:0;
  if(spawnNum > 3) spawnNum = 3;
  if(!pObj) {
    return ogre_king_giveup(pName);
  }
  if(member_array(pName, query_data("OgKiPlayers")) == -1
      || environment(pObj)->query_instance_group_id() != "Ogre King Throne Instance") {
    return ogre_king_giveup(pName);
  }
  if(currSpawns >= 75) {
    message("info", "The ogre king has temporarily exhausted his supply of guards, no more will arrive until they have a chance to regroup.", pObj);
    return;
  }
  set_data("ogrekingspawnCALL_OUT:"+pName, call_out("ogre_king_spawn_guard", to_int((36 - (0.2666666 * currSpawns))+random(43 - (0.2666666 * currSpawns))), pObj, pName));
  for(int i = 0; i < spawnNum; i++)
    new(DRAG_MOBS"ogrekingguard")->move(environment(pObj));
  message("info", capitalize(cardinal(spawnNum))+" new guard"+(spawnNum>1 ? "s rush":" rushes")+" into the room.", pObj);
  set_data("ogreKingSpawns:"+pName, currSpawns);
}

void player_entered_ogre_king_instance(string pName) {
  if(!myData["OgKiPlayers"]) myData["OgKiPlayers"] = ({ });
  myData["OgKiPlayers"] -= ({ pName });
  myData["OgKiPlayers"] += ({ pName });
  set_data("ogreKingSpawns:"+pName, 0);
  set_data("ogreKingKills:"+pName, 0);
  new(DRAG_ITEMS"kingeventob")->move(find_player(pName));
  if(!query_data("ogrekingspawnCALL_OUT:"+pName))
    set_data("ogrekingspawnCALL_OUT:"+pName, call_out("ogre_king_spawn_guard", 45+random(15), find_player(pName), pName));
  else {
    //the current call_out should handle the spawn
  }
}

void ogre_killed(string killer) {
  set_data("ogreKingKills:"+killer, to_int(query_data("ogreKingKills:"+killer))+1);
  if(query_data("ogreKingKills:"+killer) < 40) return;
  if(load_object(DRAG_ROOMS"instance_d")
    ->get_instance_room(killer, DRAG_ROOMS"ogreking6", "Ogre King Throne Instance")
      ->make_king_killable()) {
    message("say", "%^CYAN%^The Ogre King shouts:%^RESET%^"
      "Guards? Guards! Guards, where are you?! I am defenseless, come to my aid!", find_player(killer));
    message("info", "The ogre king's guards are too thin in number to protect him any more, and he is open to attack.", find_player(killer));
  }
}

void ogre_king_giveup(string loser) {
  set_data("ogreKingKills:"+loser, 0);
  myData["OgKiPlayers"] -= ({ loser });
  set_data("ogreKingSpawns:"+loser, 0);
  remove_call_out(query_data("ogrekingspawnCALL_OUT:"+loser));
  set_data("ogrekingspawnCALL_OUT:"+loser, 0);
  //remove all the kingeventobs from the player
  if(find_player(loser))
    while(present("kingeventob", find_player(loser))) present("kingeventob", find_player(loser))->remove();
  //Pyro (8/11/08): This shouldn't be necessary now that spawned guards will despawn
  //load_object(DRAG_ROOMS"instance_d")->destruct_group_instance_pairing(loser, "Ogre King Throne Instance");
  //Pyro (8/11/08): This is required now that the instance does not reset itself when you leave it
  load_object(DRAG_ROOMS"instance_d")
    ->get_instance_room(loser, DRAG_ROOMS"ogreking6", "Ogre King Throne Instance")
      ->make_king_unkillable();
}

void ogre_king_killed(string killer) {
  object* players = efun::map(myData["OgKiPlayers"], (: find_player($1) :));
  players = filter(players, (: $1!=0 :));
  if(!killer || killer=="") return;
  if(!find_player(killer)) return;
  set_data("denyOgreKingThroneEntrance", 1);
  set_data("canKillOgreKing", 0);
  message("info", "The walls begin to break and the ceiling begins to crumble as you hear the Ogre King cry out his dying scream.", players);
  players->set_paralyzed(17, "Everything is happening too quickly.", "Things seem to have settled down.");
  call_out("oking_death_event", 3, players, killer);
  players->move(DRAG_ROOMS"ogrethronedestroyed");
  foreach(string tmpPlyr in myData["OgKiPlayers"]) {
    remove_call_out(query_data("ogrekingspawnCALL_OUT:"+tmpPlyr));
    set_data("ogrekingspawnCALL_OUT:"+tmpPlyr, 0);
  }
}

int oking_death_event(object* players, string winner) {
  players = filter(players, (: $1!=0 :));
  if(!find_player(winner)) { set_data("OGRE KING WINNER NOT FOUND: "+winner, 1); return 0; }
  message("info", "You twist and dodge around the falling debree and head towards the ogre king's room as all the ogres around you are crushed beneath heavy pillars and boulders.", players, find_player(winner));
 message("info", "The ogre king begins running about the room, screaming and crashing into the walls. His ruckus begins to cause the walls and roof around you to collapse.", find_player(winner));
  call_out("oking_death_further", 7, players, winner);
}

int oking_death_further(object* players, string winner) {
  players = filter(players, (: $1!=0 :));
  if(!find_player(winner)) { set_data("OGRE KING WINNER NOT FOUND: "+winner, 1); return 0; }
  message("info", "You reach the throne room, to find "+capitalize(winner)+" standing over the dead corpse of the ogre king. "+capitalize(winner)+" turns around to find you staring and winks at you.", players, find_player(winner));
  if(sizeof(players)>1) message("info", "You leap at the ogre king, knocking him to the floor, and drive your head through his torso. The ogre king lets out one final scream and is silent. You turn around to see others standing near the entry way to the throne room. You can't help but wink at them.", find_player(winner));
  else message("info", "You leap at the ogre king, knocking him to the floor, and drive your head through his torso. The ogre king lets out one final scream and is silent. You turn around to look for others but find that you are all alone. You can't help but wish that somebody had been there to see you.", find_player(winner));
  call_out("oking_death_final", 5, players, winner);
}

int oking_death_final(object* players, string winner) {
  object winnerObj = find_player(winner);
  players = filter(players, (: $1!=0 :));
  if(!winnerObj) { set_data("OGRE KING WINNER NOT FOUND: "+winner, 1); return 0; }
  message("info", capitalize(winner)+" rifles through the ogre king's corpse and takes something from his pocket. The throne room has stopped shaking, but the entire area has been demolished, leaving only rubble behind.", players, winnerObj);
  message("info", "Something on the ogre king's corpse catches your eye, and so you reach down and quickly pocket it. The throne room has stopped shaking, but the entire area has been demolished, leaving only rubble behind.", winnerObj);

  winnerObj->add_exp(1000000);
  winnerObj->set_stats("dexterity", winnerObj->query_base_stats("dexterity")+4);
  winnerObj->set_stats("constitution", winnerObj->query_base_stats("constitution")+4);
  new(DRAG_ITEMS"ogrekingreward")->move(winnerObj);
  message("info", "%^BOLD%^%^BLACK%^You hear a deep roar resonate through the cave.%^RESET%^", players);
 /* Pyro (8/11/08): I decided to not have all the player data cleared on the event's end. Might as well store that info.
  foreach(object ob in players) {
    ogre_king_giveup(ob->query_name());
  }
  foreach(string plyr in myData["OgKiPlayers"]) {
    ogre_king_giveup(plyr);
  }
 */
  myData["OgKiPlayers"] = ({ });
  set_data("winnerogreking", winner);
  load_object(DRAG_ROOMS"instance_d")->destruct_instances_with_instance_id("Ogre King Throne Instance");
  remove_beams(2);
}


void notify_cave_losers(object winnerObj) {
  load_object(DRAG_ROOMS"instance_d")->
    destruct_instances_with_instance_id("Event Test Of Courage Instance");
  load_object(DRAG_ROOMS"py/dump")->give_final_speech(winnerObj);
}

void cave_of_courage_completed(object winnerObj) {
  if(!winnerObj || !winnerObj->is_player()) return;
  if(!query_data("canProveCourage")) return;
  set_data("canProveCourage", 0);
  set_data("winnerCaveOfCourage", winnerObj->query_name());
  winnerObj->add_exp(1000000);
  winnerObj->set_stats("intelligence", winnerObj->query_base_stats("intelligence")+1);
  winnerObj->set_stats("wisdom", winnerObj->query_base_stats("wisdom")+1);
  winnerObj->set_stats("charisma", winnerObj->query_base_stats("charisma")+1);
  new(DRAG_ITEMS"rewardbag")->move(winnerObj);
  new(DRAG_WEP"ogredagger")->move(winnerObj);
  call_out("notify_cave_losers", 0, winnerObj);
  winnerObj->move(DRAG_ROOMS"py/winnerroom");
  remove_beams(2);
}


void ogre_king_event_start() {
  set_data("canKillOgreKing", 1);
  set_data("denyOgreKingThroneEntrance", 0);
  myData["OgKiPlayers"] = ({ });
  load_object(DRAG_ROOMS"instance_d")->destruct_instances_with_instance_id("Ogre King Throne Instance");
}

void start_events() {
  object dr;

  init_data();

  set_data("eventstarted", 1);

  set_data("testing", 1); // this line must be removed before the real start!
  set_data("cavenodeaths", 0); // change to 1 if you don't want players to be able to die in the cave

  dr = load_object(DRAG_MOBS+"guidedragon");
  dr->move(this_object());
  dr->set_speech(0);
  dr->start_speech();
}

int event_start(string str) { start_events(); return 1; }

void remove_beams(int x) {
  object dr;
  int total = query_data("prisonbeams") - x;
  if (total < 0) {
    total = 0;
    tell("%^BOLD%^%^RED%^Error: tried to set prison beams to <0 !!%^RESET%^");
    CHAT_D->do_raw_chat("system", "DRAG_D <system> Event Error: tried to set prison beams to <0.");
  }
  set_data("prisonbeams", total);
  message("info", "%^BOLD%^%^WHITE%^"
    +cardinal(x)+" beam"+(x==1?"":"s")+" of light draw"+(x==1?"s":"")+" back into "+(x==1?"a column":"the columns")+"!"
    "%^RESET%^",
    load_object(DRAG_PRISON_ROOM) );

  if (total == 0) {
    dr = load_object(DRAG_MOBS+"finaldragon");
    dr->move(DRAG_PRISON_ROOM);
    dr->set_speech(0);
    dr->start_speech();
    set_data("eventstarted", 0);
    set_data("eventfinished", 1);
  }
}
