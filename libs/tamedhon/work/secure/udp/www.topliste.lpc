/* Tamedhon MUDlib
 *
 * /secure/udp/www.topliste.c -- WWW Questliste
 *
 * $Date: 2006/07/16 13:00:00 $
 * $Revision: 1.1 $
 * $Log: www.questliste.c,v $
 *
 */


#pragma strong_types
#pragma combine_strings

#include <properties.h>
#include <www.h>

string Request()
{
  string text;
/*
  text=explode(ctime(time())," ")[2];
  if (text==" " || text=="")
    text=explode(ctime(time())," ")[3];
*/

 
 // Tage durch random ersetzt.... switch(text) 
  switch(to_string(random(32))) {
   case "1" :
   case "19" :
   case "28" :
   default:
   text=read_file("/p/service/querolin/listen/gestopliste.txt");
   break;
   case "2" :
   case "11" :
   case "29" :
   text=read_file("/p/service/querolin/listen/xptopliste.txt");
   break;
   case "12" :
   case "30" :
   text=read_file("/p/service/querolin/listen/lxptopliste.txt");
   break;
   case "4" :
   case "13" :
   case "31" :
   text=read_file("/p/service/querolin/listen/fptopliste.txt");
   break;
   case "5" :
   case "23" :
   text=read_file("/players/querolin/items/wp/listen/gesspiele.txt");
   break;
   case "15" :
   case "24" :
   text=read_file("/players/querolin/items/wp/listen/maxpkt.txt");
   break;
   case "16" :
   case "25" :
   text=read_file("/log/gilden/abgtopliste.sort");
   break;
   case "8" :
   case "26" :
   text=read_file("/p/service/querolin/listen/ergochachtopliste.txt");
   break;
   case "9" :
   case "18" :
   text=read_file("/p/service/querolin/listen/bewahrertopliste.txt");
   break;
   case "14" :
   case "20" :
   text=read_file("/gilden/files.atalai/save/ailiste");
   break;
   case "10" :
   case "21" :
   text=read_file("/gilden/files.sw/save/swliste");
   break;
   case "3" : 
   case "27" :
   text=read_file("/p/service/querolin/listen/slwtopliste.txt");
   break;
   case "17" :
   case "6" :
   text=read_file("/p/service/querolin/listen/spielertopliste.txt");
   break;
   case "7" :
   case "22" :
   text=read_file("/p/service/querolin/listen/atalaitopliste.txt");
   break;
  }
  return "<br>"
        +text;
}
