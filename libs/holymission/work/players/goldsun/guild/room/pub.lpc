/*   castle pub */

inherit "room/room";
#define NA "Lithius Castle"  
 
reset(arg) {
   if (arg) return;
   set_light( 1);
   short_desc= "In the castle pub";
   property=({"has_fire"});
   long_desc=
    "You have now entered the pub of the "+NA+".\n"+
    "In front of you, you can see some tables and chairs.\n"+
    "There is a nice fire here. On the wall you can see the menu,\n"
    "which gives you better information about food and drinks.\n";
    
    
    items=({
        "sign","There is something written on it",
        "menu","A small iron sign with something written on it",
        "table","A brown wooden table",
        "tables","Brown wooden tables",
	"wall","There is the menu hanging on the wall",
        "chair","A small wooden chair",
        "chairs","Some small wooden chairs" });

    dest_dir=({ "players/goldsun/guild/room/hall","east" });
        
}
 
init() {
  add_action("order","order"); 
  add_action("order","buy"); 
  add_action("read","read"); 
 ::init();
}


read(str) {
 if (str=="menu" || str=="sign") {
write(
     "()---------------------------------------------------------)\n"+
     " |                 FIGHTER's local PUB                    |\n"+
     " |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|\n"+
     " |We offer:                                               |\n"+
     " |                                                        |\n"+
     " |      Foods and drinks for the direct consume:          |\n"+
     " |                                                        |\n"+
     " |1   Dragon breath                          4000 coins   |\n"+
     " |2   Goldsun secret (mixed)                 2000 coins   |\n"+
     " |3   Wine                                    200 coins   |\n"+
     " |4   Beer                                     30 coins   |\n"+
     " |5   Mutton                                  600 coins   |\n"+
     " |6   Pitza                                   500 coins   |\n"+
     " |7   Muesly                                   40 coins   |\n"+
     " |8   Coffee                                   40 coins   |\n"+
     " |9   Water                                    12 coins   |\n"+
     " |10  Muzmuz special                          440 coins   |\n"+
     " |                                                        |\n"+
     " |You can consume also in numbers....<buy 3> for the Wine.|\n"+
     "()---------------------------------------------------------)\n");
    
     
  return 1;
  }
}
order(str)
{
 string name, short_desc,art, mess;
   int value, cost, strength, heal,i;
   object dummy;
 if (!str) {
  write("You might feel the chaos in this world..order what??\n");
  return 1;
}
  if (str == "dragon breath" || str=="breath" || str=="dragon" || str == "1") 
  {
   mess = "You are feeling strongly like dragon.... AHHHH";
   heal = 200;
   value = 4000;
   strength = 54;
   art ="alko";
  }
  else if (str == "secret" || str=="goldsun secret" ||
	     str=="Goldsun secret" || str == "2") {
  mess = "You feel the fire in whole your body.... AHHHH";
  heal= 150;
  value = 2000;
  strength = 50;
  art ="alko";
 }
  else if (str == "wine" || str == "3") {
  mess = "The wine makes you feel much better.... AHHHH";
  heal= 30;
  value = 200;
  strength = 16;
  art ="alko";
}
  else if (str == "beer" || str=="4") {
  mess = "You enjoy the good taste of a good beer.... AHHHH";
  heal= 8;
  value = 30;
  strength = 3;
  art = "alko";
}
  else if (str=="mutton" || str=="5") {
  mess = "MMMM.... Such a well roasted mutton";
  heal = 35;
  value = 600;
  strength = 25;
  art = "food";
}
  else if (str == "pitza" || str=="6") {
  mess = "MMMM.... Such a pitza tastes fine";
  heal = 25;
  value = 400;
  strength = 20;
  art = "food";
}
  else if (str == "muesly" || str=="7") {
  mess = "WELL.... Such a muesly block tastes fine";
  heal = 5;
  value = 40;
  strength = 6;
  art = "food";
}
  else if (str == "coffee" || str=="8") {
  mess = "WELL.... You feel your head getting clearer !";
  heal = 0;
  value = 40;
  strength = -2;
  art = "alko";
}
  else if (str == "water" || str == "9") {
  mess = "WELL.... You feel your head getting clearer !";
  heal = 0;
  value = 12;
  strength = -1;
  art = "alko";
}
  else if (str == "special" || str=="muzmuz special" || str=="Muzmuz special"
		|| str == "10")
 {
  mess = "You feel magic force through your body.";
  heal = 100;
  value = 440;
  strength = 7;
  art = "special";
}

 
else {
    write("The bartender stares at you, saying: We don't have that.\n");
    return 1;
  }
 
  if (call_other(this_player(), "query_money", 0) < value) {
    write("That costs " + value + " gold coins, which you don't have.\n");
    return 1;
  }
  if (art=="alko" || art=="special") {
  if (!call_other(this_player(), "drink_alcohol", strength)) {
    write("The bartender says: I think you've had enough.\n");
    
    return 1;
  }
 }
  else if (art=="soft") {
  if (!call_other(this_player(),"drink_soft",strength)){
  write("The bartender says: Sorry, I don't think you have a cow stomach.\n");
  return 1;
  }
}
  else if (art=="food") {
  if (!call_other(this_player(),"eat_food",strength)){
  write("The bartender says: I think you are sober.\n");
  say(this_player()->query_name()+" is hungry but the bartender refuses.\n");
  return 1;
  }
}

  write("You pay " + value + " coins.\n");
  this_player()->add_money(-value);
  if(art=="special") this_player()->restore_spell_points(heal);
  else this_player()->heal_self(heal);
  write(mess + ".\n");
  return 1;
}
