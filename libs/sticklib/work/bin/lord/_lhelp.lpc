#include <lord.h>
#define LEVEL 0
#define VALUE 1
/*
	Lord Command:	lhelp
	Syntax:		lhelp
			lhelp <level number>
	Conditions:
		Must be a lord/lady
		Must be of equal or greater level
			to see help for a level
	Effects:
		None
*/

mixed	*help_lines;
int	help_size,
last_change;

int read_lord_file();

int lhelp_cmd(string str,object us)
{
    int lev,o_level,x,y;
    string *help_message;

    if(LL < SQUIRE)
	return 0;

    if( !(help_lines) || (last_change > file_time(LORD_DOC)) )
	if( !(read_lord_file()) ) return 0;

    o_level=(int)us->query_level();

    if (!str) {
	for(y=0;y<help_size;y++){
	    if(help_lines[y][LEVEL] > o_level) break;

	    if(help_message) help_message += ({ help_lines[y][VALUE] });
	    else help_message = ({ help_lines[y][VALUE] });
	}
    } else {
	if (sscanf(str, "%d", lev) != 1)
	    return notify_fail("Usage: lhelp\nOr:    lhelp <level number>.\n"),0;

	if (lev > o_level)
	    return notify_fail("You are not able to see help for higher levels.\n"),0;

	for(y=0;y<help_size;y++){
	    if(help_lines[y][LEVEL] < o_level) continue;
	    if(help_lines[y][LEVEL] > o_level) break;

	    if(help_message) help_message += ({ help_lines[y][VALUE] });
	    else help_message = ({ help_lines[y][VALUE] });
	}
    }

    if( !(help_message) || !(sizeof(help_message)) )
	if(lev) return notify_fail(sprintf("lhelp: no help aviable for level: %d\n",lev)),0;
	else return notify_fail("lhelp: Sorry there is no help aviable at your level\n"),0;

    us->more(help_message);
    return 1;
}


int read_lord_file() {
    int x,y,tmp1;
    string help_file,tmp2;
    string *help_work;

    help_lines=0;
    last_change=file_time(LORD_DOC);
    help_file=read_file(LORD_DOC);
    if(!help_file) help_file = "";
    help_work=explode(help_file,"\n");

    if(!(help_work && (x=sizeof(help_work))))
	return notify_fail("lhelp: error in help file please report to an admin.\n"),0;

    for(y=0;y<x;y++)
	if(sscanf(help_work[y],"%d %s",tmp1,tmp2)==2)
	    if(help_lines)	help_lines += ({ ({ tmp1, help_work[y] }) });
	    else		help_lines = ({ ({ tmp1, help_work[y] }) });

    if(help_lines) if(help_size=sizeof(help_lines)) return 1;

    help_lines=0;
    help_size=0;
    last_change=0;
    return notify_fail("lhelp: error in help file please report to an admin.\n"),0;
}
