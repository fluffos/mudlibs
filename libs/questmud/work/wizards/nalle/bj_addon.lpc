// -N '03

#include <ansi.h>

string query_full_cardname(string str, int colour);
string query_subcard(string str);
string query_family(string str, int colour);

/****************************************************/

string query_full_cardname(string str, int colour)
{
 string result;
 string tmp1,tmp2;

 if(!str) return 0;
 if(!colour) colour=0;

 result="";
 result+=query_subcard  ( str[ strlen(str)-1 .. strlen(str)-1 ] );
 result+=" of ";
 result+=query_family   ( str[ 0 .. 0 ] , colour);

 return result;
}

/****************************************************/

string query_subcard(string str)
{
        switch(str)
        {
        case "2" :
        case "3" :
        case "4" :
        case "5" :
        case "6" :
        case "7" :
        case "8" :
        case "9" : return str;
        case "J" : return "Jack";
        case "Q" : return "Queen";
        case "K" : return "King";
        case "A" : return "Ace";

        default :       write("Error in query_subcard. Str was '"+str+"'\n"); 
                        return "Error!";
        }
}

/****************************************************/

string query_family(string str, int colour)
{
 string result;

        switch(str)
        {
        case "c" : result = "Clubs";    break;
        case "d" : result = "Diamonds"; break;
        case "h" : result = "Hearts";   break;
        case "s" : result = "Spades";   break;

        default :       write("Error in query_family. Str was '"+str+"'\n"); 
                        return "Error!";
        }

 // No colours
 if(!colour) return str;

 // If diamonds or hearts colour red
 if(str == "d" || str == "h")
   {
    return RED_F+result+OFF;     
   }

 // Rest in light black
   return sprintf("%c",27)+"[1;1;30m"+result+OFF;
}

/****************************************************/

