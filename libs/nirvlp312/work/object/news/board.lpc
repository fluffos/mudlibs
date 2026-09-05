#define TP this_player()
#define LOWER lower_case
#define TPRN TP->query_real_name()
#define CAP         capitalize
#define MESS_CHUNK 2500
#include <ansi.h>

inherit "/obj/treasure";

int board_id;
string subj, message;

set_board_id(int this_id) { board_id = this_id; }

query_board_id() { return board_id; }
query_weight() { return 1; }

get() { return 0; }

int add_read(string list, string post_id)
{
    if(!TP->valid_board(board_id)) return 0;
    list = list + ":" + post_id;
    db_get_rs("update board_records set message_list='" + list + "' where board_id = " + board_id + " and name='" + LOWER(TPRN)+"'");
    return 1;
}

string *parse_read(string read_list)
{
    string *tmp_list, *my_list;
    int x;
    mixed *tmp;

    if(!TP->valid_board(board_id)) return 0;
    my_list = explode(read_list,":");
    tmp_list = my_list;
    for(x = 0; x < sizeof(my_list); x++)
    {
	tmp = db_get_rs("select post_id from board_posts where post_id=" + my_list[x]);
	if(!sizeof(tmp)) tmp_list -= ({ my_list[x] });
    }

    if(tmp_list != my_list)
    {
	read_list = implode(tmp_list,":");
	db_get_rs("update board_records set message_list='" + read_list + "' where board_id = " + board_id + " and name='" + LOWER(TPRN)+"'");
    }

    return tmp_list;
} 

short()
{
    mixed *tmp;
    string bname, mess_list, *rs, *read_list;
    int total;
    if(!TP->valid_board(board_id)) return 0;
    tmp = db_get_rs("select board_name from boards where board_id=" + board_id);
    if(sizeof(tmp)) { rs = tmp[0]; if(sizeof(rs)) bname = rs[0]; }
    tmp = db_get_rs("select count(*) from board_posts where board_id=" + board_id);
    if(sizeof(tmp)) { rs = tmp[0]; if(sizeof(rs)) total = (int)rs[0]; }
    tmp = db_get_rs("select message_list from board_records where board_id=" + board_id + " and name='" + LOWER(TPRN)+"'");
    if(sizeof(tmp)) { rs = tmp[0]; if(sizeof(rs)) mess_list = rs[0]; }
    if(mess_list) read_list = parse_read(mess_list);
    return bname + " [" + total + " messages, " + (total-sizeof(read_list)) + " unread]";
}

long(string password)
{
    mixed *tmp;
    string mess_list, *rs, *read_list;
    int x;

    if(!TP->valid_board(board_id)) return 0;
	write("==============================\n"+
	  "Read and write notes!\n"+
	  "'note <subject>' to write a new note.\n"+
	  "'read #' to read.\n"+
	  "'remove #' to remove a note.\n"
	  "==============================\n\n");
    read_list = ({ });
    tmp = db_get_rs("select message_list from board_records where board_id=" + board_id + " and name='" + LOWER(TPRN)+"'");
    if(sizeof(tmp)) { rs = tmp[0]; if(sizeof(rs)) mess_list = rs[0]; }
    if(mess_list) read_list = parse_read(mess_list);

    tmp = db_get_rs("select post_id,subject,author,post_time from board_posts where board_id=" + board_id + " order by post_time");
    if(sizeof(tmp))
    {
	for(x = 0; x < sizeof(tmp); x++)
	{
	    rs = tmp[x];
	    write((x+1) + "] ");
	    if(member(read_list,rs[0]) == -1) write(HIR+"*"+NORM);
	    write(rs[1] + " [" + CAP(rs[2]) + ", " + ctime((int)rs[3]) + "]\n");
	}
    }
    write("\n");
}

init()
{
    ::init();
    add_action("read","read");
    add_action("note","note");
    add_action("remove","remove");
}

int read(string arg, string password, int left_off)
{
    int total, mess_num, x;
    string mess_list, *rs, *read_list;
    mixed *tmp;

    if(!TP->valid_board(board_id)) return 0;
    read_list = ({ });
    tmp = db_get_rs("select message_list from board_records where board_id=" + board_id + " and name='" + LOWER(TPRN)+"'");
    if(!sizeof(tmp)) db_get_rs("insert into board_records (name,board_id) VALUES('" + LOWER(TPRN) + "'," + board_id + ")");
    if(sizeof(tmp)) { rs = tmp[0]; if(sizeof(rs)) mess_list = rs[0]; }
    if(mess_list) read_list = parse_read(mess_list);
    mess_list = implode(read_list,":");
    tmp = db_get_rs("select count(*) from board_posts where board_id=" + board_id);
    if(sizeof(tmp)) { rs = tmp[0]; if(sizeof(rs)) total = (int)rs[0]; }
    if(!total)
    {
	write("The board is empty.\n");
	return 1;
    }
    tmp = db_get_rs("select post_id,author,subject,message,post_time from board_posts where board_id=" + board_id + " order by post_time");
    if(arg && sscanf(arg,"%d",mess_num) == -1) mess_num = -1;
    if(!arg)
    {
	for(x = 0; x < sizeof(tmp); x++)
	{
	    rs = tmp[x];
	    if(!mess_num && member(read_list,rs[0]) == -1) mess_num = (x+1);
	}
    }
    if(!arg && !mess_num)
    {
	write("No unread messages.\n");
	return 1;
    }

    if(mess_num < 1 || mess_num > total)
    {
	write("Please enter a message number between 1 and " + total + ".\n");
	return 1;
    }

    rs = tmp[mess_num - 1];
    if(!left_off) write("==================================\nAuthor : " + CAP(rs[1]) + "\nSubject: " + rs[2] +"\nDate   : " + ctime((int)rs[4])+"\n\n==================================\n\n");
    write(rs[3]);
    if(!left_off) write("\n\n==================================\n\n");
    if(member(read_list,rs[0]) == -1) add_read(mess_list,rs[0]);
    return 1;
}

int remove(string arg)
{
    int total, mess_num;
    string mess_list, *rs;
    mixed *tmp;

    if(!TP->valid_board(board_id)) return 0;
    tmp = db_get_rs("select count(*) from board_posts where board_id=" + board_id);
    if(sizeof(tmp)) { rs = tmp[0]; if(sizeof(rs)) total = (int)rs[0]; }
    if(!total)
    {
	write("The board is empty.\n");
	return 1;
    }
    if(!arg || sscanf(arg,"%d",mess_num) != 1 || mess_num > total || mess_num < 1)
    {
	write("Please select a number between 1 and " + total + " to remove.\n");
	return 1;
    }

    tmp = db_get_rs("select post_id,author from board_posts where board_id=" + board_id + " order by post_time");
    rs = tmp[mess_num -1];
    if(rs[1] != LOWER(TPRN) && TP->query_level() < 1000)
    {
	write("You may only remove your own messages.\n");
	return 1;
    }
    db_get_rs("delete from board_posts where post_id=" + rs[0]);
    write("Removed message " + arg + ".\n");
    return 1;
}

int write_note(string str)
{
    if(!TP->valid_board(board_id)) return 0;
    if(str == "~q" || (str == "**" && message == ""))
    {
	write("Aborting.\n");
	return 1;
    }

    if(str == "**")
    {
    subj = db_conv_string(subj);
    message = db_conv_string(message);
	db_get_rs("insert into board_posts (board_id,author,subject,message,post_time) values(" + board_id + ",'" + LOWER(TPRN) + "','" + subj + "','" + message + "'," + time() +")");
	write("\nMessage written.\n");
      if(!this_player()->query_invis() && board_id == 3)  /* verte */
        emit_channel("announce", "(announce) A new announcement has been posted on the Village Green board!\n");
	return 1;
    }
    message = message + str + "\n";
    write("] ");
    input_to("write_note");
    return 1;
}

int note(string str)
{
    int total;
    string *rs;
    mixed *tmp;

    if(!TP->valid_board(board_id)) return 0;
    if(!str)
    {
	write("Please try again, this time supplying a subject.\n");
	return 1;
    }

    tmp = db_get_rs("select count(*) from board_posts where board_id=" + board_id);
    if(sizeof(tmp)) { rs = tmp[0]; if(sizeof(rs)) total = (int)rs[0]; }

    if(total >= 50)
    {
	write("This board cannot hold more posts.\n"+
	  "Please mail admin and let them know!\n");
	return 1;
    }
    subj = str;
    message = "";

    write("Writing new post.\nType '**' on a blank line to finish.\nType ~q on a blank line to abort.\n] ");
    input_to("write_note");
    return 1;
}
