/*
** Room for the Culture Center-Quest
** Author: Thragor@Nightfall, 03apr97
** Update:
*/

#include <properties.h>
#include <lock.h>
#include <magic.h>
#include <config.h>
#include <stdrooms.h>
#include <moving.h>
#include <search.h>

#define CCQUEST "NightfallI"
#define LOGFILE "/d/archwiz/common/log/NightfallI.log"

#define P_CABLE "CultureCable"
#define P_SWITCH "CultureSwitch"

#define P_ON "MachineOn"
#define P_CODE "MachineCode"

#define SWITCH_ON 1
#define SWITCH_OFF 0

#define TP this_player()
#define ME this_object()
#define SF(x) #'x //' Emacs-hack
#define D(x,y) "/players/thragor/lib/debug"->debug("thragor",x,y)

inherit "/std/room";

private void move_church(object pl)
{
  if (pl)
    pl->move(CHURCH,M_SILENT);
  tell_room(environment(pl),capitalize(pl->QueryName())+
	    " enters the world.\n",({pl}));
  if (!pl->QueryInvis())
    CHANNEL_D->SendEmote("news",capitalize(pl->QueryRealName()),
			     "enters the world", 1);
}

private void clean_quest()
{
  show_room(ME,({"Suddenly you feel sucked into the cube. Your mind "
		 "fades away and after a while you awake in a new world.\n"
		 "A virtual world.\n",
		 "Suddenly you feel sucked away. Your mind fades away and "
		 "after a while you awake in a new world. A virtual world.\n"})
	    );
  map_objects(filter_objects(deep_inventory(),"CCQuest"),"remove");
  map(filter_objects(deep_inventory(),"CCQuest"),SF(destruct));
  map(filter(all_inventory(),SF(query_once_interactive)),
	    SF(move_church));
  reset(); // Should close the door
  remove();
  if (ME) destruct(ME);
  return;
}

public void CheckQuest(object pl)
{
  if (!(pl && Query(P_CABLE) && Query(P_SWITCH)==SWITCH_ON))
    return;
  if (!Query(P_CABLE)->Query(P_ON))
    {
      tell_object(pl,"You suddenly recognize the red button on the cube.\n");
      return;
    }
  if (!Query(P_CABLE)->Query(P_CODE))
    {
      tell_object(pl,"The code is missing.\n");
      if (member(map_objects(deep_inventory(pl),"CCQuest"),"staff")!=-1)
	tell_object(pl,"Perhaps you could use the staff somehow?\n");
      return;
    }
  if (member(map_objects(deep_inventory(pl),"CCQuest"),
	     "ring")==-1)
    {
      tell_object(pl,"You think you still need something to represent "
		  "the spirit of the Mud.\n");
      return;
    }
  if (member(map_objects(pl->QueryArmours()||({})-({0}),"CCQuest"),
	     "ring")==-1)
    {
      tell_object(pl,"Perhaps, in this solemn moment, you should "
		  "wear the ring to symbolize the spirit of the mud.\n");
      return;
    }
  show_room(ME,"On the surface of the cube suddenly appears:\n"+
	    read_file(resolve_file("./WELCOME.NF1"))+
	    read_file(resolve_file("./NEWS.NF1")) );
  if (!QUESTMASTER->SetPlayerQuest(CCQUEST,pl))
    {
      tell_object(pl,"Once again you managed to build up your own MUD!\n");
      write_file(LOGFILE,sprintf("%s solved Culture Center Quest (%s)\n",
				 capitalize(pl->QueryRealName()||
					    pl->QueryName()||
					    pl->QueryShort()||
					    "someone"),
				 ctime()));
    }
  else
    tell_object(pl,"Congrats! You started your own MUD!\n");
  call_out(SF(clean_quest),0);
}

public int cmd_switch(string str)
{
  if (!TP||!str)
    return notify_fail("Switch what?\n",NOTIFY_NOT_OBJ),0;
  str = lower_case(str);
  if (!sizeof(regexp(({str}),"(\\<on\\>)|(\\<off\\>)")))
    return notify_fail("You can either switch it off or on.\n",
		       NOTIFY_NOT_VALID),0;
  if (sizeof(regexp(({str}),"\\<on\\>")))
    {
      if (Query(P_SWITCH)==SWITCH_ON)
	return notify_fail("The switch is already on.\n",
			   NOTIFY_NOT_VALID),0;
      Set(P_SWITCH,SWITCH_ON);
      write("The switch is now on. You suddenly feel a strong "
	    "wind coming from the box at the ceiling.\n");
      if (TP->QueryInvis())
	say("You hear a 'click' and suddenly there's much wind "
	    "coming from the box at the ceiling.\n");
      else
	show(({capitalize(TP->QueryName())+" switches the switch and "
		 "suddenly you feel a strong wind coming from the box at "
		 "the ceiling.\n",
		 "You hear a 'click' and suddenly there's much wind "
		 "coming from the box at the ceiling.\n"}) );
      CheckQuest(TP);
      return 1;
    }
  if (Query(P_SWITCH)==SWITCH_OFF)
    return notify_fail("The switch is already off.\n",
		       NOTIFY_NOT_VALID),0;
  Set(P_SWITCH,SWITCH_OFF);
  write("The switch is now off. The wind stops.\n");
  if (TP->QueryInvis())
    say("You hear a 'click' and suddenly there's no wind anymore.\n");
  else
    show(({capitalize(TP->QueryName())+" switches the switch and "
	     "suddenly there's no wind anymore.\n",
	     "You hear a 'click' and suddenly there's no wind "
	     "anymore.\n"}) );
  return 1;
}

public int cmd_plug(string str)
{
  string what,towhat;
  object owhat,otowhat;

  if (!TP||!str)
    return notify_fail("Plug what to what?\n",
		       NOTIFY_NOT_OBJ),0;
  str = norm_id(str);
  if (   sscanf(str,"%s into %s",what,towhat)!=2
      && sscanf(str,"%s to %s",what,towhat)!=2
      && sscanf(str,"%s in %s",what,towhat)!=2
     )
    return notify_fail("Plug what to what?\n",
		       NOTIFY_NOT_OBJ),0;
  owhat = search(TP,what,SEARCH_ENV_INV|SM_IGNLIGHT|SM_OBJECT);
  otowhat = search(TP,towhat,SEARCH_ENV_INV|SM_IGNLIGHT|SM_OBJECT);
  if (owhat && owhat==otowhat)
    return notify_fail("You can't plug something into itself.\n",
		       NOTIFY_NOT_VALID),0;
  if (owhat && otowhat)
    return notify_fail(sprintf("You can't plug %s into %s.\n",
			       owhat->Short(),
			       otowhat->Short()),
		       NOTIFY_NOT_VALID),0;
  if (strstr(str,"cable")==-1)
    {
      if (!owhat && !otowhat)
	return notify_fail(sprintf("You see neither %s nor %s in here.\n",
				   what,towhat),
			   NOTIFY_NOT_VALID),0;
      return notify_fail(sprintf("You only see %s in here.\n",
				 (owhat||otowhat)->Short()),
			 NOTIFY_NOT_VALID),0;
    }
  owhat = owhat||otowhat;
  if (!owhat)
    return notify_fail("You can't plug the cable into that.\n",
		       NOTIFY_NOT_VALID),0;
  if (owhat->CCQuest()!="machine")
    return notify_fail(sprintf("You can't connect %s to the cable.\n",
			       owhat->Short()),
		       NOTIFY_NOT_VALID),0;
  if (Query(P_CABLE) && environment(Query(P_CABLE))!=ME)
    Set(P_CABLE,0);
  if (Query(P_CABLE) && Query(P_CABLE)==owhat)
    return notify_fail("The cable is already plugged into it.\n",
		       NOTIFY_NOT_VALID),0;
  if (Query(P_CABLE))
    return notify_fail("There cable is already plugged into another cube.\n",
		       NOTIFY_NOT_VALID),0;
  if (environment(owhat)!=ME)
    return notify_fail("You can only plug the cable to something in the "
		       "room.\n",NOTIFY_NOT_VALID),0;
  Set(P_CABLE,owhat);
  write("You plug the cable into the cube.\n"
	"Somehow the cable seems to grow into the cube, so that it won't "
	"be possible to part cube and cable again.\n");
  if (TP->QueryInvis())
    show("Suddenly the cable attaches to the cube.\n");
  else
    show(capitalize(TP->QueryName())+" plugs a cable into a cube.\n");
  CheckQuest(TP);
  return 1;
}

private string detail_cable(string what)
{
  string res;
  res = "One end of the cable is fixed to the socket.\n";
  res+= Query(P_CABLE)?"The other end of the cable is fixed to a cube.\n"
                      :("The other end of the cable is loose.\n"
			"Perhaps you can plug it into something.\n");
  return res;
}

private string detail_switch(string what)
{
  string res;
  res = "The switch may be used to switch something on and off.\n";
  res+= (Query(P_SWITCH)==SWITCH_ON
	 ?"Right now the switch is on.\n"
	 :"Right now the switch is off.\n");
  return res;
}

private string detail_box(string what)
{
  string res;
  res = "The box has many strange openings.\n";
  res+= (Query(P_SWITCH)==SWITCH_ON
	 ?"A strong wind blows out of the openings.\n"
	 :"Perhaps poisonous gas will come out of it.\n");
  return res;
}

public int prevent_leave(mixed dest,int method,mixed extra)
{
  object ob;
  ob = previous_object();
  if (   method!=M_NOCHECK
      && method!=M_DESTRUCT
      && ob
      && ob->CCQuest()=="machine"
      && Query(P_CABLE)==ob
      && dest // it should be possible to destruct the machine
     )
    {
      write("The cube is connected to the cable. You can't "
	    "remove it.\n");
      return ME_NO_LEAVE;
    }
  return (::prevent_leave(dest,method,extra));
}

public void create()
{
  (::create());
  SetIntShort("Another reality...");
  SetIntLong("You had a strange feeling when you entered this room. "
	     "You felt as if you awakened out of a dream.\n"
	     "The walls of the room are bare, made of concrete. "
	     "At the ceiling is a huge box with some openings pointing "
	     "towards the middle of the room.\n"
	     "The portal to the south looks quite funny in this bare room, "
	     "as it carries many ornaments and doesn't fit into this "
	     "boring environment.\n"
	     "At one side of the portal is a small switch.\n");
  Set(P_CANSEE,1);
  Set(P_SWITCH,SWITCH_OFF);
  SetTPort(TPORT_NO); // This is another reality, no teleport
  ForbidAllMagic(); // Same. Another reality...
  AddDetail("ornaments",
	    "They look nice.. but you don't understand their meaning.\n");
  AddDetail("room",SF(QueryIntLong));
  AddDetail("ceiling","There's a strange box.\n");
  AddDetail(({"strange box","huge box","box","box at ceiling",
	      "openings"}),
	    SF(detail_box));
  AddDetail(({"strange feeling","feeling"}),
	    "This reality is not virtual anymore.\n");
  AddDetail("walls",
	    "The walls are made of concrete. A wall socket in the western "
	    "wall is equipped with a cable.\n");
  AddDetail(({"wall socket","socket"}),
	    "There's a label on the socket.\n");
  AddDetail(({"label","label on socket","socket label","letters"}),
	    "There are a few letters saying: INTERNET.\n");
  AddReadMsg(({"label","label on socket","socket label","letters"}),
	     "INTERNET");
  AddDetail("cable",SF(detail_cable));
  AddDetail(({"switch","small switch"}),SF(detail_switch));
  AddDetail(({"southern wall","wall south","south wall"}),
	    "The wall is bare except a huge golden portal and a "
	    "switch at one side of the portal.\n");
  AddDetail(({"western wall","wall west","west wall"}),
	    "There's a wall socket at the wall.\n");
  AddDetail(({"northern wall","wall north","north wall",
	      "western wall","wall west","west wall"}),
	    "The wall is bare.\n");
  AddDetail(({"concrete","grey concrete","gray concrete","strong concrete"}),
	    "It's grey and strong concrete.\n");
  AddDetail(({"grey and strong concrete","strong and grey concrete",
	      "gray and strong concrete","strong and gray concrete"}),
	    "Seems you really want to look for every detail, eh? ;-)\n"
	    "Very nice, indeed. Go on! And don't forget to report, if "
	    "a detail is missing.\n");
  AddRoomCmd("plug",SF(cmd_plug));
  AddRoomCmd("switch",SF(cmd_switch));
  AddDoor("south",
	  "./jokeroom",
	  ([
	    P_SHORT:"a golden portal",
	    P_LONG:("The portal looks very heavy .\n"),
        P_DOORCODE:"cc_door",
	    P_LOCKSTATE:LOCK_LOCKED,
	    P_IDS:({"portal"}),
	    P_ADS:({"golden","huge"}),
	    P_KEYCODE:"cc_key",
	    P_KEYIDS:({"cc_key"}),
	    P_PICK_CHANCE:0
	  ])
	 );
}
