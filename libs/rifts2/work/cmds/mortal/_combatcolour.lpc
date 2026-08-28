// --==** /cmds/mortal/_combatcolour.c **==--
// Darke Domain
// Zephlen 1999
#include <std.h>

#define COLOURS ({"red", "yellow", "green", "blue", "cyan", "black",\
                  "magenta", "white", "orange"})
#define SPECIALS ({"flash", "bold", "none"})

string forgr, backgr, special;

void set_combatcolour();

int cmd_combatcolour(string str)
{
  if(str == "reset")
  {
    message("info", "You set your combat colour back to black and "
                    "white.", this_player());
this_player()->set_property("combat color", "");
    return 1;
  }
  message("info", "Please enter the forground colour. Your choices 

are:\n"
"red, green, yellow, blue, magenta, cyan, black, orange "
                  "and white.  ",
                  this_player());
  input_to("get_forground");
  return 1;
}

void get_forground(string str)
{
  if(!str || (member_array(str, COLOURS, 0) == -1))
  {
    message("info", "You need to enter a valid colour.", this_player());
    return;
  }
  forgr = str;
  message("info", "Please enter the special feature for the forground. "
                  "Your choices are:\nflash, bold and none.  ",
                  this_player());
  input_to("get_special");
  return;
}

void get_special(string str)
{
  if(!str || (member_array(str, SPECIALS, 0) == -1))
  {
    message("info", "You need to enter a valid special feature.", 
            this_player());
    return;
  }
  special = str;
  message("info", "Please enter the background colour. Your choices 
are:\n"
                  "red, green, yellow, blue, magenta, cyan, black, 
orange "
                  "and white.  ",
                  this_player());
  input_to("get_background");
  return; 
}

void get_background(string str)
{
  if(!str || (member_array(str, COLOURS, 0) == -1))
  {
    message("info", "You need to enter a valid colour.", this_player());
    return;
  }
  if(str == forgr)
  {
    message("info", "You cant have the forground and background as the "
                    "same colour.", this_player());
    return;
  }
  backgr = str;
  set_combatcolour();
  return;
}  

string convert_forgr_colour(string col)
{
  switch(col)
{
    case "orange" :
      return "%^ORANGE%^";
    case "red" :
      return "%^RED%^";
    case "blue" :
      return "%^BLUE%^";
    case "green" :
      return "%^GREEN%^";
    case "yellow" :
      return "%^YELLOW%^";
    case "magenta" :
      return "%^MAGENTA%^";
    case "cyan" :
      return "%^CYAN%^";
    case "white" :
      return "%^WHITE%^";
    case "black" :
      return "%^BLACK%^";
    case "flash" :
      return "%^FLASH%^";
    case "bold" :
      return "%^BOLD%^";
  }
}

string convert_bkgr_colour(string col)
{
  switch(col)
  {
    case "orange" :
return "%^B_ORANGE%^";
    case "red" :
return "%^B_RED%^";
    case "blue" :
return "%^B_BLUE%^";
    case "green" :
return "%^B_GREEN%^";
    case "yellow" :
return "%^B_YELLOW%^";
    case "magenta" :
return "%^B_MAGENTA%^";
    case "cyan" :
return "%^B_CYAN%^";
    case "white" :
return "%^B_WHITE%^";
    case "black" :
return "%^B_BLACK%^";
  }
}

void set_combatcolour()
{
string colour_string;

  if(special != "none")
    colour_string = convert_forgr_colour(special); 
  if(special == "none")
    colour_string = convert_forgr_colour(forgr);
  else
    colour_string += convert_forgr_colour(forgr);
  colour_string += convert_bkgr_colour(backgr);
  message("info", colour_string + "YOUR COLOUR", this_player());
this_player()->set_property("combat color", colour_string);
  message("info","Your combat colour has been set.", this_player());
  return;
}

void help()
{
  message("info", "This command sets the colour your attack will appear 
"
                  "in during combat. Type 'combatcolour' and follow the 
"
                  "instructions to set your colour. You can type "
                  "'combatcolour reset' and it will make put you back to 
"
                  "black and white.", this_player());
  return;
}
