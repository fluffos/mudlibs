#include <std.h>
inherit ROOM;

string *descs = ({
"In every direction, the only visible thing is simply light, brilliant white "
"light. The maze is high in the clouds, with hundreds of twisting passages in "
"every which way.",
"In every direction one could possibly walk, there is a cloud passageway leading "
"there. Up, down, all around, everywhere! Bright white light engulfs the "
"heavens.",
"The sun seems ever closer, as you can wander in every direction. Go ahead, "
"wander, wander to your hearts content! In fact, I hope you get lost. Thats what "
"you get, you little wanna-be angel!",
"This maze is copywrite Primal Darkness (Inferno): Christmas 2000 BC. This is as "
"good as the room descriptions are gonna get. Yah, yah, complain why dont you?",
"Damn, you're lost! You are screwed, just turn back. Go away, we dont want you. "
"Go be a demon or something. I heard liches are nice.. hit the road!",
"You're lost.",
"What are you looking for... I guess it's not here, better turn back!",
"Are you still here? Jeez, people these days are persistant. Go away, take the "
"hint. *hint* *hint* *nudge*",
"There is nowhere else to go, but back where you came. Passages lead north, "
"south, east, west, down, up, northeast, northwest, southeast, southwest.",
"I hear the exit <out> is really fun. <psst>, it's a secret way to finish the "
"quest. Why don't ya just tell me if out is a good way to go.. It's not like "
"you'll leave the maze or anything...",
"An airplane flys by with a banner attached to the back: Eat at Joe's.",
"You are currently infringing on Primal Darkness (c) copywrite laws. Turn back "
"before we release the dogs......... Still there, 'eh? Go away before we are "
"forced to hunt you down and kill you for sport.",
"Archangel? Angel? What are you talking about?? This is the demon quest maze!",
"It's a bird! It's a plane, no wait.. It's a raging, out of control demon!! "
"Run for your lives!",
"What? You think you could do better room descriptions? A godly voice sounds in "
"your mind, 'mortal, I strike thee down!'",
"You are standing on top of a cloud. An airplane flys by, all the passengers "
"point at you and scream. The plane plummets towards the ground and lands on "
"the top of a house. No wait.. that was just a bird.",
"Fa la la la la  la la la la. Twelve reindeers fly past you. A fat guy in the "
"back of the sleigh with no fashion sense looks at you funny.",
"Amelia Airheart flys past you in a plane. Wait.. shouldn't she be dead by now?",
"You hear dogs barking from the distance.. And bees. And dogs that spit out "
"bees. And ... lawyers!",
"This maze has been reposessed. Please go elsewhere.",
"Leave ere you invoke my terrible verbal wrath!",
"That's it.. now you've done it.. 'Gosh darn you, please leave my maze. "
"Thank you, come again!'",
"You are high in the clouds, suddenly a old woman flys by you "
"on a bike! Wait thats not a old woman thats a whitch!",
});
object *total_rooms = ({ });
string nowleave, lastleave = "rock", tlast = "on", xlast = "peeps";
int roomcount = 0;
mapping opps = ([
"south"     : "north",
"north"     : "south",
"east"      : "west",
"west"      : "east",
"northwest" : "southeast",
"northeast" : "southwest",
"southeast" : "northwest",
"southwest" : "northeast",
"down"      : "up",
"up"        : "down"
]);

int query_roomcount() { return roomcount; }
object *query_rooms() { return total_rooms; }
string query_xlast() { return xlast; }
string query_tlast() { return tlast; }
string query_lastleave() { return lastleave; }
void set_total_rooms(object *ob) { total_rooms = ob; }
void set_xlast(string str) { xlast = str; }
void set_tlast(string str) { tlast = str; }
void set_lastleave(string str) { lastleave = str; }
void set_roomcount(int x) { roomcount = x; }

void create() {
 int i;
 ::create();
   set_name("A maze in the clouds");
   i = random(sizeof(descs) - 1);
   set_long(descs[i]);
   i = random(9) + 1;
   set_properties(([
     "no teleport" : 1, "no attack" : 1, "no magic" : 1, "no bump" : 1,
     "no steal" : 1
   ]));
   set_exits(([
     "up"        : "default", //file_name(this_object()),
     "out"       : "/d/lodos/l1m8",
     "east"      : "default", //file_name(this_object()),
     "west"      : "default", //file_name(this_object()),
     "down"      : "default", //file_name(this_object()),
     "south"     : "default", //file_name(this_object()),
     "north"     : "default", //file_name(this_object()),
     "northwest" : "default", //file_name(this_object()),
     "southwest" : "default", //file_name(this_object()),
     "northeast" : "default", //file_name(this_object()),
     "southeast" : "default" //file_name(this_object())
   ]));
}

int no_do() { write("You can not do that. Bwaahahaha"); return 1; }

void init() {
 ::init();
   add_action("no_do", "survey");
   add_action("no_do", "scan");
   add_action("no_do", "peer");
   add_action("u",     "up");
   add_action("clean", "out");
   add_action("e",     "east");
   add_action("w",     "west");
   add_action("d",     "down");
   add_action("s",     "south");
   add_action("n",     "north");
   add_action("nw",    "northwest");
   add_action("sw",    "southwest");
   add_action("ne",    "northeast");
   add_action("se",    "southeast");
}

int clean() {
   this_player()->move_player("/d/lodos/l1m8", "out");
   total_rooms->remove();
   this_object()->remove();
   return 1;
}

int walk() {
   object ob;
   if (roomcount >= 1153) {
     this_player()->move_player("/d/lodos/o1", "light");
     total_rooms->remove();
     this_object()->remove();
     return 1;
   }
   ob = new("/wizards/inferno/amaze");
   if (this_object()->query_exit(nowleave) == "default") {
     add_exit(file_name(ob), nowleave);
     ob->add_exit(file_name(this_object()), (string)opps[nowleave]);
     if (lastleave != nowleave || tlast != nowleave || xlast != nowleave)
       roomcount++;
   }
   xlast = tlast;
   tlast = lastleave;
   lastleave = nowleave;
   ob->set_xlast(xlast);
   ob->set_tlast(tlast);
   ob->set_lastleave(lastleave);
   total_rooms += ({ this_object() });
   ob->set_total_rooms(total_rooms);
   ob->set_roomcount(roomcount);
   return 0;
}

int u()  { nowleave = "up"; return walk();        }
int n()  { nowleave = "north"; return walk();     }
int ne() { nowleave = "northeast"; return walk(); }
int nw() { nowleave = "northwest"; return walk(); }
int e()  { nowleave = "east"; return walk();      }
int se() { nowleave = "southeast"; return walk(); }
int s()  { nowleave = "south"; return walk();     }
int sw() { nowleave = "southwest"; return walk(); }
int w()  { nowleave = "west"; return walk();      }
int d()  { nowleave = "down"; return walk();      }
