#include <ansi.h>

#define badWords ({"fuck","shit","cock","cunt","dick","tits"})
#define badWordSize 6
#define badChars ({"!","@","%","#","^","&","*","$"})
#define badCharSize 8

string sanitize_text(string text)
{
  int x, y, *case_positions;
  string a, b, c, char, newText;
  string cname;
  int cnf;
/*
  if(this_player() && (string)this_player()->query_real_name()=="earwax")
    return crypt(text, 0);
*/
/* not a great fix */
  if(this_player()) {
    cname = (string)this_player()->query_name();
    if(strlen(text) > strlen(cname)) {
      if(text[0..strlen(cname)-1] == cname) {
        cnf = 1;
        text = text[strlen(cname)..strlen(text)-1];
      }
    }
  }
  case_positions = ({ });
  y = strlen(text);
  for(x=0;x<y;x++)
   case_positions += ({ (text[x..x]==capitalize(text[x..x])) });
  text = lower_case(text);
  for(x=0;x<badWordSize;x++)
    while(sscanf(text,"%s"+badWords[x]+"%s",a,b))
    {
      c = (badChars[random(badCharSize)]+badChars[random(badCharSize)]+
           badChars[random(badCharSize)]+badChars[random(badCharSize)]);
      if(!a) a ="";
      if(!b) b ="";
/*
      if(!random(6)) c = "[expletive deleted]";
      else if(!random(6)) c = "XXXXXXX";
      else if(!random(6)) c = BEEP+HIM+"BEEP"+NORM;
      else if(!random(6)) c = "NAUGHTYWORD"+NORM;
      else if(!random(6)) c = "<filth>";
      else if(!random(6)) c = "(INSERT PERVERTED RANTING HERE)";
      text = a+c+b;
  */
    }
  while(sscanf(text,"%sbitch%s",a,b) || sscanf(text,"%spussy%s",a,b)) {
      c = (badChars[random(badCharSize)]+badChars[random(badCharSize)]+
           badChars[random(badCharSize)]+badChars[random(badCharSize)]+
           badChars[random(badCharSize)]);
/*
      if(!random(6)) c = "[expletive deleted]";
      else if(!random(6)) c = "XXXXXXX";
      else if(!random(6)) c = BEEP+HIM+"BEEP"+NORM;
      else if(!random(6)) c = "NAUGHTYWORD"+NORM;
      else if(!random(6)) c = "<filth>";
      else if(!random(6)) c = "(INSERT PERVERTED RANTING HERE)";
      if(!a) a = ""; if(!b) b = ""; text = a+c+b;
 */
  }
  newText = "";
  for(x=0;x<y;x++)
  {
    char = text[x..x];
    newText += (case_positions[x]?capitalize(char):char);
  }
  if(cnf) newText = cname + newText;
  return newText;
}
