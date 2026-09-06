// The magic flying carpet of Nightfall
//
// Completely rewritten by Softbyte on February 1997
// Original idea by Joern 
// 
// Location changes:
// Added Limerick/Ireland due to Analena's wish [Softbyte 18sep96]
// Removed Bay of Djin and Orient, added Kev [Mica 22Jan97]
// Slight changes Softbyte 29jan97 
// Introduced change ticket, Softbyte 13.3.97
// special offers , Softbyte 31mar97

#include <properties.h>
#include <moving.h>
#include <secure/wizlevels.h>
#include <magic.h>
#include <search.h>

inherit "obj/inroom";
inherit "/lib/money";

// ------------ Defines --------------------------------------- 
#define TP this_player()

#define TOPLIST "/p/magic/server/carpetserver"

#define LEVEL_NEWBIE 4

#define CARPET_KEY     0
#define CARPET_TARGET  1
#define CARPET_PRICE   2


// ------------ Variables ------------------------------------- 
private mapping *net;      // The carpet networks

private string carpet;          // "carpet" noun..change it when you 
public string QueryCarpet() {return carpet;}  // make e.g. dragons
public int SetCarpet(string s) {carpet=s;return 1;}


private int network;          // Which network are we running, default is 0
public int QueryNetwork() {return network;}
public int SetNetwork(int i)
{
  if (i>=sizeof(net)) return 0;   // network not existing
  RemoveId("_carpet"+to_string(network));
  network=i;
  AddId("_carpet"+to_string(network));
  return 1;
}
private mapping places;


// -------------External functions ---------------------------- 
// Here you can modify the price of a flight .. e.g. for elves
public varargs int ModifyPrice(int price,int nr,object pl)
{
  return price;
}

// Use this function to check whether a certain player is allowed to
// use the carpet. Return 1 for not allowed or a string stating the
// reason why he/she is not allowed
public varargs mixed ForbidFlying(object pl)
{
  if (!pl) pl=TP;
  if (QueryNetwork()==NETWORK_HLP && pl->QueryLevel()<20)
    return "This "+QueryCarpet()+
	   " is for HLPs only. You are not allowed to use it.\n"
	   "You stand up again.\n ";
  return 0;      // everybody is allowed
}

// ------------ Local functions ------------------------------- 
// Is object a flyer ?
public int IsFlyer(object ob)
{
  if (!ob) return 0;
  if (ob->QueryIsPlayer()) return 1;
  return 0;
}

// Query all players who are on board the carpet 
public object *QuerySitters()
{
object *sitting;
  sitting=filter(all_inventory(this_object()),#'IsFlyer);
  return sitting||({});
}

// The shortcuts a player can type when sitting on the carpet
public mixed *QueryCarpetShortcuts()
{
mapping places;
  places=net[QueryNetwork()];
  return m_values(places);
}

// Get all indices of the carpet locations
public string *QueryCarpetIndex()
{
mapping places;
  places=net[QueryNetwork()];
  return m_indices(places);
}

// The cost to fly to the target
public int QueryCarpetCost(int target)
{
mapping places;
string *idx;
  places=net[QueryNetwork()];
  idx=m_indices(places);
  return places[idx[target],CARPET_PRICE];
}

// The Filename of the carpet location
public string QueryCarpetFile(int target)
{
mapping places;
string *idx;
  places=net[QueryNetwork()];
  idx=m_indices(places);
  return places[idx[target],CARPET_TARGET];
}

// ------------ Internal functions ---------------------------- 
/* Here the prices are calculated */
private int CalculatePrice(int price,int nr,object pl)
{
  if (!pl) pl=TP;
  price=price*30*pl->QueryLevel()/100;
  if (TP->QueryLevel()<=LEVEL_NEWBIE) price=0;
  price=ModifyPrice(price);
  return price;
}

/* Read the carpet prices */
string readletters()
{
string *idx;
int price,i,size;
string s,tmp;

  idx=QueryCarpetIndex();
  if (!idx || !sizeof(idx)) return "This "+QueryCarpet()+" is out of order.\n";
  size=sizeof(idx);
  s="You read the intricated letters on the "+QueryCarpet()+"...\n\n";
  s+="   ===> " MUDSHORT " Carpet Inc. offers you a ride to the following places <===\n";
  s+="\n";

  for (i=0;i<size;i+=3)
  {
     tmp=idx[i]+" ("+to_string(CalculatePrice(QueryCarpetCost(i),i,TP))+")";
     s+=sprintf("%-26.26s",tmp);
	 if (i+1 < size)
	 {
       tmp=idx[i+1]+" ("+to_string(CalculatePrice(QueryCarpetCost(i+1),i+1,TP))+")";
       s+=sprintf("%-26.26s",tmp);
	 }
	 if (i+2 < size)
	 {
       tmp=idx[i+2]+" ("+to_string(CalculatePrice(QueryCarpetCost(i+2),i+2,TP))+")";
       s+=sprintf("%-26.26s",tmp);
	 }
     s+="\n";
  }
  s+="\n";
  s+="             ===> Enjoy flying with " MUDSHORT " Carpet Inc. <===\n";
  return s;
}

/* Define the carpet networks */
private void MakeNetwork()
{
 net=({
// Carpet LARGE Network  -- default
     ([
  "Lorinia":          ({"lorinia"});
                      "d/woodland/common/lorinia/airport";         100,
  "Wooden City":      ({"wooden city","Wooden City"}); 
                      "d/woodland/common/city/airport1";           100,
  "Hobbiton":         ({"hobbiton"});
                      "d/halfling/common/room/hobbiton/hrelonroad_2";       100,
  "Crescent Lake":    ({"crescent lake","lake","Crescent Lake"}); 
                      "d/woodland/common/shore/sshore29";          100,
  "Orccaves":         ({"orccaves","orc caves"});
                      "d/shadows/common/room/outskirts/airport";   100,
  "England":          ({"england"});
                      "d/avalon/common/village/carpet_port";       150,
  "Nightfall-City":   ({"nf-city","nightfall-city" });
                       "d/archwiz/common/room/city/cmarket";       100,
  "Miner's Town":     ({"miner's town","miners town"});
                      "d/woodland/common/border/tower2";           100,
  "Dwarven Mines":    ({"dwarven mines","mines"});
                      "d/halfling/common/room/dwarf/road3";        100,
  "Dark City":        ({"dark city"});
                      "d/shadows/common/room/darkcity/street1";    150,
  "Ireland":          ({"ireland"});
                      "d/ireland/common/york/cliff";               150,
  "Limerick":         ({"limerick"});                   
                      "/d/ireland/common/beach/beach1";            160,
  "Netherhells":      ({"netherhells","netherhell"});
                      "d/shadows/common/room/nethell/boul1";       150,
  "Wasteland":        ({"wasteland","waste lands"});
                      "d/wasteland/common/room/plain/pass1";       150,
  "Camelot":          ({"camelot","camelot castle"});
                      "d/avalon/common/camelot/hof/hof7";          100,
  "Surf City":        ({"surf city","surfcity"});
                      "d/halfling/common/room/surf/beach2";          150,
  "Clondike Village": ({"clondike", "clondike village"});
                      "d/orient/common/room/clondike/road1";              100,
  "Sandy Island":     ({"sandy island", "sandyisland"});
                      "d/woodland/common/sandy/vill2";             100,
  "Isle of the Magi": ({"isle of the magi", "isle"});
                      "d/woodland/common/isle/sisland5";         100,
  "Giant Village":    ({"giant village"});
                      "d/orient/common/room/giant/g32";          100,
  "El Essaman":       ({"essaman","el essaman", "elessaman"});
                      "d/orient/common/room/essaman/towertop";          100,
  "Port Chien":       ({"port chien"});
                      "d/orient/common/room/portchien/intersection";    100,
  "Kiev":              ({"kiev" });
                      "d/orient/common/room/kiev/airport";            100,
  "Mandukam":         ({"mandukam"});
                      "d/woodland/common/mandukam/path1";          100
     ]),

// Carpet SMALL Network 
     ([
  "Lorinia":          ({"lorinia"});
                      "d/woodland/common/lorinia/airport";         100,
  "Wooden City":      ({"wooden city"}); 
                      "d/woodland/common/city/airport1";           100,
  "Hobbiton":         ({"hobbiton"});
                      "d/halfling/common/room/hobbiton/hrelonroad_2";       100,
  "Crescent Lake":    ({"crescent lake","lake"}); 
                      "d/woodland/common/shore/sshore29";          100,
  "England":          ({"england"});
                      "d/avalon/common/village/carpet_port";       150,
  "Nightfall-City":   ({"nf-city", "nightfall-city", "nightfall"});
                       "d/archwiz/common/room/city/cmarket";               100,
  "Miner's Town":     ({"miner's town","miners town"});
                      "d/woodland/common/border/tower2";           100,
  "Dwarven Mines":    ({"dwarven mines","mines"});
                      "d/halfling/common/room/dwarf/road3";          100,
  "Dark City":        ({"dark city"});
                      "d/shadows/common/room/darkcity/street1";    150,
  "Ireland":          ({"ireland"});
                      "d/ireland/common/york/cliff";               150,
  "Surf City":        ({"surf city","surfcity"});
                      "d/halfling/common/room/surf/beach2";          150,
  "Sandy Island":     ({"sandy island", "sandyisland"});
                      "d/woodland/common/sandy/vill2";             100,
  "Giant Village":    ({"giant village"});
                      "d/orient/common/room/giant/g32";            100,
  "El Essaman":       ({"essaman","el essaman","elessaman"});
                      "d/orient/common/room/essaman/towertop";     100,
  "Kiev":              ({"kiev" });
                      "d/orient/common/room/kiev/airport";         100,
  "Mandukam":         ({"mandukam"});
                      "d/woodland/common/mandukam/path1";          100
     ]),

// Carpet HLP Network 
     ([
  "Caroba":           ({"caroba","Caroba"});
                      "d/woodland/common/ellil/caroba/airport";    100,
  "Lorinia":          ({"lorinia"});
                      "d/woodland/common/lorinia/airport";         100,
  "Nightfall-City":   ({"nf-city", "nightfall-city", "nightfall"});
                       "d/archwiz/common/room/city/cmarket";       100,
  "Trondheim":        ({"trondheim","valhalla"});
                      "/d/valhalla/common/midgard/city/cport";     150,
  "Vecna":            ({"vecna"});
                      "d/vecna/common/room/city/st1";              180
     ]),

// Woodland fast network
     ([
  "Lorinia":          ({"lorinia"});
                      "d/woodland/common/lorinia/airport";         30,
  "Wooden City":      ({"wooden city","Wooden City"}); 
                      "d/woodland/common/city/airport1";           30,
  "Crescent Lake":    ({"crescent lake","lake","Crescent Lake"}); 
                      "d/woodland/common/shore/sshore29";          30,
  "Miner's Town":     ({"miner's town","miners town"});
                      "d/woodland/common/border/tower2";           40,
  "Sandy Island":     ({"sandy island", "sandyisland"});
                      "d/woodland/common/sandy/vill2";             35,
  "Isle of the Magi": ({"isle of the magi", "isle"});
                      "d/woodland/common/isle/sisland5";           42,
  "Mandukam":         ({"mandukam"});
                      "d/woodland/common/mandukam/path1";          38
     ])

     });
}

// Sit down on the carpet
int sit(string str)
{
string what;
object ob;
mixed s;
  notify_fail("Sit down on what?\n");
  if (!str || !TP) return 0;
  
  if ( (1==sscanf(str,"on %s",what) ) ) str=what;
  else if (1==sscanf(str,"down on %s",what) ) str=what;

  if ( !(ob=TP->Search(str,SEARCH_ENV|SM_OBJECT)) ) return 0;
  if (ob!=this_object()) return 0;
  
  if (environment(TP)==this_object())
  {
	notify_fail("You are already sitting on "+QueryShort()+".\n");
	return 0;
  }
  else
  {
    if (s=ForbidFlying(TP))
    {
	  if (stringp(s))
	    write(s);
	  else
	    write("You are not allowed to use this "+QueryCarpet()+
	        ". You stand up again.\n ");
	  return 1;
    }
    TP->move(this_object(),M_SPECIAL,({
	  "sits down on "+QueryShort(),
	  "sits down on "+QueryShort(),
	  "sit down on "+QueryShort()  }) );
  }
  return 1;
}

// Leave the carpet
int leave(string str)
{
string what;
object ob;

//write(object_name(this_object())+" leave..\n");

  notify_fail("Leave what?\n");
  if (!TP) return 0;
  if (!str) str=QueryCarpet();

   if (!id(str))  // if not id give search chance
   {
     if ( !(ob=TP->Search(str,SEARCH_ENV|SM_OBJECT)) ) return 0;
     if (ob!=this_object()) return 0;
//     write(object_name(this_object())+" found me\n");
     return 0;
   }
  if (environment(TP)!=this_object())
  {
	notify_fail("You don't sit on "+QueryShort()+".\n");
    return 0;
  }
  else
  {
    TP->move(environment(this_object()),M_SPECIAL,({
	  "leaves "+QueryShort(),
	  "leaves "+QueryShort(),
	  "leave "+QueryShort()  }) );
  }
  return 1;
}

// Check whether an idendical carpet is in the array
private int check_carpet(object ob)
{
  if (!ob || !ob->id("_magiccarpet")) return 0;
  if (ob==this_object()) return 0;
  if (ob->QueryNetwork()==QueryNetwork()) return 1;
  return 0; 
}

// Fly to the location given if the player(s) is/are sitting on it
int fly(string str) 
{
int i,ni,target,cost,have,cflag;
string file,flyer,tmpfly;
object room,pl,ob,start;
mixed *keys;
object *sitting;
object *obs;

  notify_fail("Fly to where?\n");
  if (!str || !TP) return 0;

  str=lower_case(str);

  if (environment(TP)!=this_object())
  {
    notify_fail("You're not sitting on the "+QueryCarpet()+".\n");
    return 0;
  }
  keys = QueryCarpetShortcuts();  

  target=-1;
  for (i=0; i<sizeof(keys);i++)
  {
    if (member(keys[i], str) >= 0) 
	{
	  target=i;
      break;
    }
  }
  if (target<0)
  {
    notify_fail("Unfortunaltely, the "+QueryCarpet()+
	            " won't fly to that place.\n");
    return 0;
  }
  have = QuerySomeonesValue(TP);
  cost=QueryCarpetCost(target);
  cost=CalculatePrice(cost,target,TP);
  file=QueryCarpetFile(target);
  room=load_object(file);
  start=environment(this_object());
  if (room==start)
  {
    return (int)notify_fail("You are already there.\n");
  }

  ob=present("_changeticket",TP);
  i=TP->QueryAttr("CarpetFlights");
  ni=TP->Query("CarpetFreeFlight");

  if (!ni || ni<i) ni=i+3+random(6)+random(6);
  if (i==ni && cost>0 )
  {
    write(
     "As you are a good customer of ours, Magic Carpet Inc. offers you this\n"
     "flight is for free ... Congratulation.\n"); 
     cost=0;
    ni=i+5+random(6)+random(6);
  }
  else if ( ob  && ob->Query("ticketprice")>0 
    && ob->Query("network")!=QueryNetwork()
    && ob->Query("owner")==TP->QueryRealName() )
  {
    cost-=ob->Query("ticketprice");
    if (cost<0) cost=0;
    ob->remove();
    write("You use your transfer flight ticket.\n");
  }
  if (ob) cflag=1;
  else cflag=0;



  i++;   // i is CarpetFlights

  tmpfly=TOPLIST->GetTopname(TP->QueryRealLevel()); // old top flyer
  if (!IS_WIZARD(TP) &&
      TOPLIST->RecordFlight(TP->QueryRealName(),i,TP->QueryRealLevel()))
  {
    if (tmpfly!=TP->QueryRealName())
    {
      write("Congratulations, you are the top flyer of your level.\n");
    }
  }
  tmpfly=TOPLIST->GetTopname(TP->QueryRealLevel()); // abbr. only
  if (cost>0 && tmpfly==TP->QueryRealName() )
  {
    write("As top flyer you get 30% off on your ticket price.\n");
    cost=cost-(30*cost)/100;
    if (cost<0) cost=0;
  }
  
  // Begin the payment procedure
  if (cost >0 && have < cost)
  {
    write("You don't have enough money to fly to that place.\n");
    write("You would need "+ cost +" coins.\n");
    return 1;
  }
  if (cost >0 && !PayValue(TP, cost))
  {
    write("You don't have the proper money to pay the flight.\n");
    return 1;
  }

  TP->SetAttr("CarpetFlights",i);
  TP->Set("CarpetFreeFlight",ni);  // next free flight

  if (!cflag && cost>0)
  {
    ob=clone_object("/p/magic/obj/changeticket");
	ob->move(TP,M_SILENT);
	ob->Set("ticketprice",cost);
	ob->Set("network",QueryNetwork());
	ob->Set("owner",TP->QueryRealName());
	ob->StartRemove();
	write("You receive a transfer flight ticket.\n");
  }
  sitting=QuerySitters();
  if (sizeof(sitting)>1) 
    flyer=implode(map_objects(sitting-({TP}),"QueryName"),", ");
  else 
    flyer=0;
  obs=filter(all_inventory(room),#'check_carpet);
  move(room,M_SILENT);
  for (i = 0; i < sizeof(sitting); i++)
  {
    pl = sitting[i];
    if (pl && environment(pl) == this_object())
    {
	  if (pl==TP) 
	  {
		tell_object(pl, "You start flying "+QueryShort()+" to "+
		   capitalize(str)+".\n");
		if (flyer) tell_object(pl, "Your passengers are: "+flyer+".\n");
	  }
	  else
	  {
		tell_object(pl, capitalize(TP->QueryName()||"")+" starts flying "+
		  QueryShort()+ " to "+capitalize(str)+".\n");
		if (flyer)
		  tell_object(pl, "You are one of the passengers ("+flyer+").\n");
	  }
	  tell_room(start,
	    capitalize(pl->QueryName()||"")+" flies out on "+QueryShort()+".\n",
		sitting);
	  tell_object(pl, "Sitting on "+QueryShort()+
	     " you rise into the air and fly away. After a short\n"
         "time you land in "+capitalize(str)+".\n");
	  tell_room(room,
	    capitalize(pl->QueryName()||"")+" arrives on "+QueryShort()+".\n",
		sitting);
      tell_object(pl, "You leave the "+QueryCarpet()+".\n");
	  pl->move(environment(this_object()),M_SILENT);
    }
  }
  if ( obs && sizeof(obs)>0 )  // remove double carpets
  {
    this_object()->remove();
  }
  return 1;
}

// Look at the toplist of carpet flyers
string looklist()
{
string s;
  s=TOPLIST->Toplist()||"";
  s+="\n        You flew "+TP->QueryAttr("CarpetFlights")+" times.\n";
  return s;
}

// Create a standard oriental flying carpet
// Overwrite this for your own carpet
public void MakeCarpet()
{
  SetCarpet("carpet");   // what id do we have
  AddId(QueryCarpet());
  AddAdjective("flying");
  AddAdjective("oriental");
  AddAdjective("colourful");
  SetShort("a colourful flying "+QueryCarpet());
  SetIntShort("on a colourful flying "+QueryCarpet());
  SetLong(
  "This is a large oriental carpet which is looking very comfortable and\n"
  "fluffy. Its fabric is made of all colours of the rainbow and with\n"
  "silver letters there is some text written into it. Some of the letters\n"
  "written at the edge of the carpet seem to form a small toplist\n"
  "Legends tell that these carpets can be used for flying to many locations\n"
  "far away.\n");
  SetIntLong(
  "You are sitting on a large oriental carpet. In silver letters some text\n"
  "is stiched into the carpet.\n"
  "You can 'leave' the carpet or 'fly' to a locations.\n");
  AddDetail(({"text","letter","letters","sign","language"}),
  "Although the text is written in an old oriental language you think you\n"
  "can manage to read it.\n");
  AddSubDetail(({"text","letter","letters","sign","language"}),
  "Although the text is written in an old oriental language you think you\n"
  "can manage to read it.\n");
  AddSubDetail(({"fabric","colour","colours"}),
  "The carpet is woven out of a strange fabric which shines in all colours\n"
  "of the rainbow.\n");
  AddDetail(({"fabric","colour","colours"}),
  "The carpet is woven out of a strange fabric which shines in all colours\n"
  "of the rainbow.\n");
  AddDetail(({"list","toplist"}),#'looklist);
  AddSubDetail(({"list","toplist"}),#'looklist);

  AddSubReadMsg(({"text","letter","letters","sign","language"}),
    #'readletters);
  AddReadMsg(({"text","letter","letters","sign","language","carpet"}),
    #'readletters);
  SetReadMsg(#'readletters);   // for compatibiltiy only

  SetWeight(3000);
  SetValue(20000);

}

public create()
{
  ::create();
  if (!is_clone()) return;

  seteuid(getuid());

  MakeCarpet();
  MakeNetwork();

  AddId("_magiccarpet");

  Set(P_NOGET,
    "You can't get this magic "+QueryCarpet()+".\n");
  Set(P_INFO,
    "This "+QueryCarpet()+" can be used for flying to other cities.\n");
  Set(P_MAGIC,
    "This "+QueryCarpet()+" can be used for flying to other cities.\n");
  Set(P_TPORT,TPORT_NO);
  SetBright(0);
  SetMaxWeight(1000000);

  // Set this to choose the network your carpet is running on
  SetNetwork(NETWORK_LLP);    // Default network

  Set("Debug",0);   // No Debugging
  AddExit("leave",#'leave);
  AddRoomCmd("fly",#'fly);
}

void init()
{
  ::init();
  if (!TP) return;
  add_action("sit","sit");
}

public int allow_enter(int method, mixed extra)
{
  if (!previous_object()) return ME_NO_ENTER;
  if (ForbidFlying(previous_object())) return ME_NO_ENTER;
  return ::allow_enter(method,extra);
}

void PlayerNetdead(int arg)
{
  if (arg==0) /* reenter mud */
  {
  }
  else  /* 1,-1 */
  {
    TP->move(environment(this_object()),M_SPECIAL,({
	  "leaves "+QueryShort(),
	  "leaves "+QueryShort(),
	  "leave "+QueryShort()  }) );
  }
}

