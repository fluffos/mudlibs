#include <ansi.h>
#include <command.h>
string insert_string(string str);
string insert_string(string str)
{
	      int len=strwidth(str);
	      int len1=len/2;
	      int i,j,k;
	      string temp="";
	      string *spch=({"☆","★","○","●","◎","◇","◆",
	      	"□","■","△","▲","※","〓","→","←","↑","↓"});
	      if (len1<10)
	      	{
	      	return str;
	        }
     		i=1+random(4);
     		j=5+random(4);
     		temp  =str[0..2i+1];
     		temp +=spch[random(sizeof[spch])];
     		temp +=str[2i+2..2j+1];
     		temp +=spch[random(sizeof[spch])];
     		temp +=str[2j+2..len]
     		return temp;
}
