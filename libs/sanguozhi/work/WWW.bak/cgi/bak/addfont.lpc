/*====================================================================
addfont.c

to link Chinese characters to their local font gif files.

@copyright reserved to Oliver Wu (oliver@irdu.nus.sg)

====================================================================*/

/*-------------------------------------------------------
system head files
-------------------------------------------------------*/
#include <daemons.h>
#include <net/http_d.h>

#define	TEST	0
#define	MAXPARALEN	32768

/*-------------------------------------------------------
-------------------------------------------------------*/
string main(string arg)
{
	string p;
	string ret;

	ret = sprintf ("<title>Demo for Chinese Viewer</Title>\n"
		 	"<h2>The Result through this viewer</h2>\n");
/*	
	while(fgets(line, MAXPARALEN, arg)) {
		p = line;
		while( *p!=0) { 
*/


	foreach(p,arg) {
			if ( p < 0x80) {
				ret += sprintf("%s",p);
				p++;
				continue;
			}
			ret += sprintf("<IMG SRC="gb/%02x/%02x\"",*p, *(p+1));
			ret += sprintf(" ALT=\"%c%c\"", *p, *(p+1));
			ret += sprintf(">");
			p += 2;
		}
	}

	return ret;
}
