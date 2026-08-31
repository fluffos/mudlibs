#include <daemons.h>
#include <socket.h>
#include <network.h>

mapping data;

string removePost(mapping data);
string getBoardPost(mapping data);
string getBoardList(mapping data);
string postBoardMessage(mapping data);

string removePost(mapping data) {
	if(!BBOARD_D->remove_message(args[1], (int)(to_int(args[2])-1))) {
		return "true";
	}
	return "false";
}

string getBoardPost(mapping data) {
   mapping *dat;
   string out="";
   i--;
   dat = BBOARD_D->get_posts(board);
   BBOARD_D->set_read(board, who, i);
   if(!dat) return "";
   out += "title="+dat[i]["title"]+"&date="+dat[i]["date"]+"&owner="+dat[i]["owner"]+"&message="+dat[i]["message"];
   return out;
}

string getBoardPostList(mapping data) {
   mapping *dat;
   string out="";
   int i;
   dat = BBOARD_D->get_posts(board);
   if(!dat) return "";
   for(i=0; i < sizeof(dat); i++) {
     out += "title="+dat[i]["title"]+"&date="+dat[i]["date"]+"&owner="+dat[i]["owner"]+"";
     if((i+1) < sizeof(dat)) out += "|~|";
   }
   return out;
}

string postBoardMessage(mapping data) {
    string txt;
    txt=BBOARD_D->post_web_message(data['board'], data['poster'], data['title'], data['message']);
    return txt;
}

