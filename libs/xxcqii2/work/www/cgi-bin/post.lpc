#include <mudlib.h>
#define SHOW_POST_HTML "/www/html/showpost.htm"

inherit F_CLEAN_UP;

string gateway(string arg) {
	string str;mapping board;
	str=read_file(SHOW_POST_HTML);
	board="/www/cgi-bin/board_list"->query_boards();
	if(undefinedp(board[arg]))
	{
		str=read_file("/www/html/warning.htm");
		return str;
	}
	str = replace_string(str,"$CHINESE_MUD_NAME",CHINESE_MUD_NAME);
	str = replace_string(str,"$BOARD_NAME",board[arg][0]);
	str = replace_string(str,"$BOARD_ID",arg);
	return str;
}