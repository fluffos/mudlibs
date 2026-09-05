#include <ansi.h>
#include <lib/usr/term_settings.h>
#define WRAP SCREEN_WIDTH

/* Prototypes */
string lalign(string text, int field);

string
date_time()
{
  string old, new, t;

  old = ctime();

  switch(old[4..6])
  {
    case "Jan" : new = "01"; break; 
    case "Feb" : new = "02"; break;
    case "Mar" : new = "03"; break;
    case "Apr" : new = "04"; break;
    case "May" : new = "05"; break;
    case "Jun" : new = "06"; break;
    case "Jul" : new = "07"; break;
    case "Aug" : new = "08"; break;
    case "Sep" : new = "09"; break;
    case "Oct" : new = "10"; break;
    case "Nov" : new = "11"; break; 
    case "Dec" : new = "12"; break;
  }
  
  new += "/";

  if (old[8..8] == "" || old[8..8] == " ")
    new += "0";
  else
    new += old[8..8];

  new += old[9..9];
  new += "/";
  new += old[22..23];
  new += " "+old[11..15];
  return new;
}

/* ********************************************************************
 * instr()
 *
 * returns 1 if 'str' is present in 'arg', 0 otherwise
*/
status instr(string arg, string str) {
  string junk, junk2, longstr;
  int ack;

  if (!arg || arg == "")
    return 0;
  longstr = arg+"";
  sscanf(arg,"%s",longstr); /* apparently necessary, *bog* */
  if (longstr == str)
    return 1;
  if (sscanf(longstr,str+"%s",junk) == 1) 
    return 1;
  if (sscanf(longstr,"%s"+str, junk) == 1)
    return 1;
  if (sscanf(longstr,"%s"+arg+"%s",junk,junk2) == 2)
    return 1;
  return 0;
}
/* ********************************************************************
 * Remove Color
 *
 * Returns the string passed minus the color codes.  
 * Mainly useful for formatting text.
*/
string remove_color(string text) {
  int i, siz;
  string *temp;
  string junk;

  if (!instr(text,ESC))
    return text;
  temp = explode(text,ESC);
  siz = sizeof(temp);

  for (i = 0; i < siz; i++) 
    sscanf(temp[i], "[%sm%s", junk, temp[i]);

  text = implode(temp,"");
  return text;
}

/* ********************************************************************
 * ansi_strlen()
 *
 * Returns the strlen minus the ansi codes.
*/
int ansi_strlen(string arg) {
  return strlen(remove_color(arg));
}
/* ********************************************************************
 * Formatting Functions
 * 
 * ralign    - pass it text and field size, it returns text right-aligned
 * lalign    - same, but it aligns it to the left, pads the rest
 * center    - returns text centered in field
 * line_wrap - wraps lines ... 76 chars
*/

string lalign(string text, int field) {
  int len, pad, i, ack;
  string str;

  text = text+"";
  len = strlen(remove_color(text));

  if (len > field)
    return "len bigger than field";

  pad = field - len;

  str = "                                                          ";
  text += str[1..pad];
  return text;
}

string ralign(string text, int field) {
  int len, pad, i, ack;
  string str;

  text = text+"";
  str = "                                                    ";
  len = strlen(remove_color(text));

  if (len > field)
    return "len > field";

  pad = field - len;
  text = str[1..pad] + text;

  return text;
}

string center(string text, int field) {
  int i, pad, len, ack;
  string str, extra_pad;

  text = text+"";
  str = "                                                      ";
  extra_pad = "";
  if (instr(text,ESC))
    len = strlen(remove_color(text));
  else
    len = strlen(text);

  if (len > field)
    return ("Len: "+len+" Field: "+field);

  pad = (field - len)/2;

  if ((pad * 2) + len < field)
    extra_pad = " ";

  text = str[1..pad] + text + str[1..pad] + extra_pad;
  return text;
}

varargs string line_wrap(string text, int width) {
  string *words;
  int i, siz, count, spaces;

  if (!width) width = WRAP;
  
  text = text + ""; /* types don't always maintain integrity */
  
  if (!text || !strlen(text))
    return "";
    
  count = 0;
    
  if (!strlen(text) || ansi_strlen(text) < width)
    return text;

  words = explode(text, " ");
  siz = sizeof(words);

  for (i = 0; i < siz; i++) {
    /*
    if (words[i] == "") {
      words[i] = " ";
      count++;
      continue;
    }
    */
    count += 1 + ansi_strlen(words[i]);

    if (count > width && words[i] != " ") {
      count = ansi_strlen(words[i]);
      words[i] = "\n" + words[i]+" ";
    }
    else if (words[i] != " ") {
      words[i] += " ";
/*
      count++;
*/
    }
  }


  text = implode(words, "");
  return text;
}

/**********************************************************************
 * get_color_name(), get_color_code()
 * 
 * These functions convert a color name to color code, or the reverse.
*/
string get_color_code(string name) {

  switch(name) {
    case "black" : return BLK;
    case "bold black" : return HIK;
    case "red" : return RED;
    case "bold red" : return HIR;
    case "cyan" : return CYN;
    case "bold cyan" : return HIC;
    case "green" : return GRN;
    case "bold green" : return HIG;
    case "yellow" : return YEL;
    case "bold yellow": return HIY;
    case "blue" : return BLU;
    case "bold blue" : return HIB;
    case "magenta" : return MAG;
    case "bold magenta" : return HIM;
    case "white" : return WHT;
    case "bold white" : return HIW;
    case "normal" : return NORM+NORM;
    default : return "";
  }
}

string get_color_name(string code) {

  switch(code) {
    case BLK : return "black";
    case HIK : return "bold black";
    case RED : return "red";
    case HIR : return "bold red";
    case CYN : return "cyan";
    case HIC : return "bold cyan";
    case GRN : return "green";
    case HIG : return "bold green";
    case YEL : return "yellow";
    case HIY : return "bold yellow";
    case BLU : return "blue";
    case HIB : return "bold blue";
    case MAG : return "magenta";
    case HIM : return "bold magenta";
    case WHT : return "white";
    case HIW : return "bold white";
    case NORM : return "normal";
    case NORM+NORM : return "normal";
    default : return "";
  }
}
/* ********************************************************************
 * Various Sorting functions
*/
int sort_by_level(object ob1, object ob2) {
  return (ob1->query_level() < ob2->query_level());
}
/* ********************************************************************
 * Array deletion
 *
 * I'm not sure if we can use 'mixed' here, I haven't had any success
 * with it on previous attempts at least, so I'm going to just slap in
 * a string array deletion for right now, although I can add checks for
 * other types of arrays later on, if necessary.
*/
string *
s_delete(string *list, string entry) 
{
     int index, i, siz;
     string *temp;

     index = member_array(entry, list);

     if (index < 0)
       return list;

     siz = sizeof(list);
     temp = ({ });

     for (i = 0; i < siz; i++)
       if (i != index)
         temp += ({ list[i] });

     return temp;
}
