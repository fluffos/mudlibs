#include <daemons.h>
#include <socket.h>
#include <network.h>

mapping data;
string get_board_data(string board);
string get_board_post(string who, string board, int i);
string do_post_message(string board, string poster, string title, string message);
int SEQ_OK = 0;
int SEQ_INVARG = -1;
int SEQ_ERROR = -2;

void load_socket() {
    int fd;
    fd = socket_create(STREAM, "");
    socket_bind(fd, 8500);
    socket_listen(fd, "incoming_connect");
}

void incoming_connect(int fd) {
    socket_accept(fd, "incoming_data", "");
}

int incoming_data(int fd, string txt) {
    string cmd, arg, *args, user, pass, path, file;

    if(sscanf(txt, "%s|%s", cmd, arg) != 2) cmd = txt;
    if(arg) args = explode(arg, "&");
    switch(cmd) {
      case "get_board":
        if(!args || !args[0])
          socket_write(fd, "Bad request.");

        if(args[0] == "all_messages")
          socket_write(fd, get_board_data(args[1]));

        if(args[0] == "single_message")
          socket_write(fd, get_board_post(args[1], args[2], (int)to_int(args[3])));

        if(args[0] == "post_message")
          socket_write(fd, do_post_message(args[1], args[2], args[3], args[4]));

        if(args[0] == "delete_message") {
          if(!BBOARD_D->remove_message(args[1], (int)(to_int(args[2])-1)))
            socket_write(fd, "Post deleted.");
          else
            socket_write(fd, "There was a problem with removing the post.");
        }         
        break;

      default: 
        socket_write(fd, "Unknown command.");
        break;
    }
    socket_close(fd);
}

void create() {
    call_out("load_socket", 5);
    data=([]);
}

string get_board_post(string who, string board, int i) {
    mapping *dat;
    string out="";

    i--;
    dat = BBOARD_D->get_posts(board);
    BBOARD_D->set_read(board, who, i);

    if(!dat)
      return "";

    out += "title="+dat[i]["title"]+"&date="+dat[i]["date"]+"&owner="+dat[i]["owner"]+"&message="+dat[i]["message"];

    return out;
}

string get_board_data(string board) {
    mapping *dat;
    string out="";
    int i;

    dat = BBOARD_D->get_posts(board);

    if(!dat)
      return "";

    for(i=0; i < sizeof(dat); i++) {
      out += "title="+dat[i]["title"]+"&date="+dat[i]["date"]+"&owner="+dat[i]["owner"]+"";
      if((i+1) < sizeof(dat))
        out += "|~|";
    }

    return out;

}

string do_post_message(string board, string poster, string title, string message) {
    string txt;
    txt=BBOARD_D->post_web_message(board, poster, title, message);
    return txt;
}

