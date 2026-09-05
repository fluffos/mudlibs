#include <ansi.h>

#define badWords ({"fuck","shit","cock","cunt","dick","tits","bitch","pussy"})
#define badWordSize 8
#define badChars ({"!","@","%","#","^","&","*","$"})
#define badCharSize 8

string sanitize_text(string text)
{
  int x, y, *case_positions;
  string a, b, c, char, newText;
  string cname;
  int cnf;

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
	  int z;
	  c = "";
	  for(z=0; z < strlen(badWords[x]); z++) c+= badChars[random(badCharSize)];
      if(!a) a ="";
      if(!b) b ="";
      text = a+c+b;
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
