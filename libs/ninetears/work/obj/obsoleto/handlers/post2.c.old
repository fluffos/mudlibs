#include <ed.h>
#include <post.h>

inherit "/std/object";

mapping *box_info;
mapping my_groups;
static int current;
static mapping mud_groups, tmp_post;
static string owner;
static int just_sending, fwd_flag;
static int *delete;

void headers(int x);
void do_mail(string str);
void get_to(string str);
void add_group(string str);
void remove_group(string str);
void do_groups(string str);
void do_help(string str);
void do_save(string cmd, string str);
void do_reply(string cmd, string arg);
void do_forward(string cmd, string arg);
void do_quit(string cmd);
void verify_quit(string str);
void really_quit(string str);
void handle_delete(string cmd, string arg);
void do_header(string str);
void read_mail(int x);
void get_cc(string str);
string letter_head(mapping this_letter, int ansi);
string get_header_time(int x);

void create() {
    ::create();
    set_name("carrier pigeon");
    set_aliases(({ "pigeon","dead pigeon","carrier pigeon","box", "post box", POST_ID }) );
   set_short("A dead carrier pigeon");
    set_long("You mail with this.\n");
    fwd_flag = -1;
    box_info = ({});
    my_groups = ([]);
    mud_groups = ([]);
    tmp_post = ([]);
}

void init() {
    int i;

    if(this_player() != environment(this_object())) {
      call_out("dest_me",0,0);
        if(this_object()) destruct(this_object());
        return;
    }
    box_info = ({});
    my_groups = ([]);
    mud_groups = (mapping)POSTAL_D->query_mud_groups();
    owner = (string)this_player()->query_name();
    restore_object(DIR_POSTAL+"/"+owner);
    if(!(i=sizeof(box_info))) {
        current = 0;
        return;
    }
    current = -1;
    for(i=0; i<sizeof(box_info) && current == -1; i++)
      if(!box_info[i]["read"]) current = i;
    delete = allocate(sizeof(box_info));
}

void start_mail(string str) {
    if(str && str != "") {
        str = (string)this_player()->expand_nickname(str);
        just_sending = 1;
        do_mail(str);
        return;
    }
    write("Imaginary Intermud Postal Service (IIPS) 1.0 for the Discworld Mudlib\n");
    write("Descartes of Borg 1993    (type \"?\" for help)\n");
    write("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    if(this_player()->getenv("MAIL_NO_HEADERS")) do_mail(0);
    else headers(0);
}

void do_mail(string str) {
    if(str) get_to(str);
    else {
        write(POST_PROMPT);
        input_to("postal_cmd");
    }
}

void postal_cmd(string str) {
    string cmd, arg;
    string *args;
    int x, i;

    if(!str || str == "") {
        for(current=-1,i=0,x=sizeof(box_info); i<x && current==-1; i++)
          if(!box_info[i]["read"]) current = i;
        cmd = (current+1)+"";
    }
    else cmd = str;
    if(sscanf(cmd, "%d", x)) {
        if(x>0 && x<=sizeof(box_info)) {
            read_mail(current = x-1);
            return;
        }
        else {
            write("Invalid letter number (\"?\" for help)\n");
            do_mail(0);
            return;
        }
    }
    cmd = (args = explode(str, " "))[0][0..0];
    if(sizeof(args) > 1) arg = implode(args[1..sizeof(args)-1], " ");
    else arg = "";
    arg = (string)this_player()->expand_nickname(arg);
    switch(cmd) {
        case "a": add_group(arg); break;
        case "x": remove_group(arg); break;
        case "g": do_groups(arg); return;
        case "?": do_help(arg); return;
        case "s": case "S": 
            if(!wizardp(this_player())) 
              write("Save option only available to immortals.\n");
            else do_save(cmd, arg);
            break;
        case "R": case "r": do_reply(cmd, arg); return;
        case "F": case "f": do_forward(cmd, arg); return;
        case "Q": case "q": do_quit(cmd); return;
        case "m": get_to(arg); return;
        case "d": case "u": handle_delete(cmd, arg); break;
        case "h": do_header(arg); return;
        default:
          write("Invalid postal command (\"?\" for help)\n");
    }
    do_mail(0);
}

void do_groups(string str) {
    if(!str || str == "") {
      write("Personal and "+mud_name()+" groups for the IIPS:\n");
      this_player()->set_finish_func("do_mail", this_object());
      this_player()->more_string(format_page(keys(mud_groups)+keys(my_groups),
        4));
      return;
    }
    if(!mud_groups[str] && !my_groups[str]) {
      write("Group "+str+" does not exist.\n");
    }
    else if(mud_groups[str]) {
      write("Members of the "+mud_name()+" IIPS group "+str+":\n");
      write(format_page(mud_groups[str], 4));
    }
    else {
      write("Members of your personal IIPS group "+str+":\n");
      write(format_page(my_groups[str], 4));
    }
    do_mail(0);
}

void add_group(string str) {
    string *members;
    string grp, a, b;
    int i;

    if(!str || str == "") {
        write("No group specified.\n");
        return;
    }
    grp = (members=explode(lower_case(str), " "))[0];
    i = sizeof(members -= ({ grp }));
    if(member_array(grp, members) != -1) {
        write("You cannot define a group as a member of itself.\n");
        return;
    }
    if(mud_groups[grp]) {
        write(mud_name()+" has already defined a group called "+grp+".\n");
        return;
    }
    if(user_exists(grp)) {
        write("A player by the name "+grp+" already exists.\n");
        return;
    }
    if(!my_groups[grp]) my_groups[grp] = ({});
    my_groups = (mapping)POSTAL_D->add_group(owner, grp, members);
    write("Group "+grp+" added to.\n");
}

void remove_group(string str) {
    string *members;
    string grp;

    if(!str || str == "") {
        write("No group specified.\n");
        return;
    }
    grp = (members = explode(str, " "))[0];
    if(!my_groups[grp]) {
        write("No such group "+grp+".\n");
        return;
    }
    if(!sizeof((members = members-({grp})))) members = my_groups[grp];
    my_groups = (mapping)POSTAL_D->remove_group(owner, grp, members);
    write("Members removed from group "+grp+".\n");
}

void do_help(string str) {
    if(!str) str = "";
    switch(str) {
        case "r": case "R":
          write("Commands r and R\n");
          write("Syntax: <r (#) (all)>\n");
          write("        <R (#) (all)>\n\n");
          write(wrap("Allows you to reply to the author of the "
          "current letter or of the letter specified.  If you "
          "specify \"all\" as a parameter, the reply goes to the author "
          "of the letter as well as all people originally addessed.  "
          "The \"R\" command differs from the \"r\" command in that "
          "the \"R\" command includes the original text in your reply."));
          break;
        case "f": case "F":
          write("Commands f and F\n");
          write("Syntax: <f (#) ([list])\n        <F (#) ([list])\n\n");
          write(wrap("Forwards a copy of the current letter or of "
          "the letter specified to the recipient list.  "
          "The \"F\" command allows you to add text."));
          break;
        case "q": case "Q":
          write("Commands q and Q\n");
          write("Syntax: <q>\n        <Q>\n");
          write(wrap("Quits out of the mailer.  The \"Q\" command"
          "quits without making any changes to the mail (nothing "
          "is deleted).  \"q\" deleteds letters marked for delteion"));
          break;
        case "a":
          write("Command a\nSyntax: <a [group] [list]>\n\n");
          write(wrap("Adds a list of players to an individualized "
          "mailer group.  If no such group exists, one is created."));
          break;
        case "x":
          write("Command x\nSyntax: <x [group] [list]>\n\n");
          write(wrap("Deletes a list of players from your mailer group "
          "of choice.  If no player list is given, the whole "
          "groups is deleted."));
          break;
        case "g":
          write("Command g\nSyntax: <g ([group])>\n\n");
          write(wrap("Lists mud and personal groups for the IIPS mailer.  "
          "If no group is specified, all group names are listed.  Otherwise the "
          "members of the group named are listed."));
          break;
        case "s": case "S":
          write("Commands s and S\nSyntax: <s (#) [filename]>\n");
            write("        <S (#) [filename]>\n\n");
          write(wrap("Only available to immortals.  Saves the post specified "
          "or the current post to the file filename in the wizards mail save "
          "directory."));
          break;
        case "u":
          write("Command u\nSyntax: <u (#)>\n\n");
          write(wrap("Undeletes a letter marked for deletion."));
          break;
        case "d":
          write("Command d\nSyntax: <d (#)>\n\n");
          write(wrap("Marks a letter for deletion upon quitting mail."));
        case "h":
          write("Command h\nSyntax: <h (#)>\n\n");
          write(wrap("Lists the headers for all letters, or letters "
          "beginning at the letter number specified."));
          break;
        case "m":
          write("Command m\nSyntax: <m [list]>\n\n");
          write(wrap("Allows you to create a letter and send it to "
          "the list of players and groups you specify.  You will "
          "be prompted at the end of creating the mail for a list "
          "of players or groups who should get carbon copies."));
          break;
        default:
            this_player()->set_finish_func("do_mail", this_object());
            this_player()->more_string(read_file(wizardp(this_player()) ?
                POST_IMMORTAL_HELP : POST_USER_HELP));
          return;
    }
    do_mail(0);
}

void do_save(string cmd, string str) {
    string tmp, where;
    int i, x;

    if(!str || !(i=strlen(str))) {
        write("You must specify the name of a file to save to.\n");
        return;
    }
    if(sscanf(str, "%d %s", x, where) != 2) where = str;
    else {
        i = strlen(where);
        current = x-1;
    }
    if(current < 0 || current >= sizeof(box_info)) {
        write("Invalid letter number  (\"?\" for help).\n");
        return;
    }
    while(i--)
      if(lower_case(where)[i] < 'a' || lower_case(where)[i] > 'z') {
          write("You may only use alphabetic characters.\n");
          return;
      }
    tmp = "/w/"+owner+"/"+where;
    if(file_size(tmp) > -1) x = 1;
    else x = 0;
    write_file(tmp, (string)LETTER_D->get_message(box_info[current]["id"]));
    if(!x) write("Letter written to new file: "+tmp+".\n");
    else write("Letter appended to file: "+str+".\n");
    if(cmd == "S") delete[current] = 1;
    return;
}

void do_header(string str) {
    int x;

    if(!str || str == "") headers(0);
    else {
        x = atoi(str);
        if(x > 0 && x<=sizeof(box_info)) headers(x-1);
        else {
            write("Invalid letter number (\"?\" for help).\n");
            do_mail(0);
        }
    }
}

void headers(int x) {
    string lines;
    int i;

    if(!(i=sizeof(box_info))) {
        write("No letters are currently in your post box.\n");
        current = 0;
        do_mail(0);
        return;
    }
    for(lines = ""; x<i; x++) {
      lines += (x+1)+" "+(box_info[x]["read"] ? "     " :
          "(new)")+(x==current ? ">" : (delete[x] ? "*" : " "))+
          arrange_string(capitalize(box_info[x]["from"]), 16)+" "+
          arrange_string(get_header_time(box_info[x]["date"]), 12)+
          box_info[x]["subject"]+"\n";
    }
    this_player()->set_finish_func("do_mail", this_object());
    this_player()->more_string(lines);
}

string get_header_time(int x) {
    string a, b, c, d;

    if(sscanf(ctime(x), "%s %s  %s %s", a, b, c, d) != 4)
      sscanf(ctime(x), "%s %s %s %s", a, b, c, d);
    return a+" "+b+" "+c;
}


void old_handle_delete(string cmd,string arg)
{
    if(arg && arg != "") current = atoi(arg)-1;
    if(current < 0 || current >= sizeof(box_info)) {
        write("Invalid letter number (\"?\" for help).\n");
        return;
    }
    if(cmd == "u" && !delete[current]) {
        write("Letter "+(current+1)+" is not marked for deletion.\n");
        return;
    }
    if(cmd == "d" && delete[current]) {
        write("Letter "+(current+1)+" is already marked for deletion.\n");
        return;
    }
    if(cmd == "u") {
        delete[current] = 0;
        write("Letter "+(current+1)+" is no longer marked for deletion.\n");
        return;
    }
    delete[current] = 1;
    write("Letter "+(current+1)+" is now marked for deletion.\n");
    return;
}
void handle_delete(string cmd, string arg) {
   string *list;
   int i;
   int start,end;
   if(!arg || arg == "") old_handle_delete(cmd,arg);
   list = explode(arg,",");
   switch(sizeof(list))
   {
    case 0:
      write("Invalid letter number \"?\" for help.\n");
   break;
   case 1:
      old_handle_delete(cmd,arg);
    break;
   case 2:
    start = atoi(list[0]);
      end = atoi(list[1]);
      if(start >=0 && end > start)
      for(i = start; i <=end; i++) old_handle_delete(cmd,sprintf("%d",i));
    break;
   default:
     for(i = 0; i < sizeof(list); i++)
   {
      old_handle_delete(cmd,list[i]);
    }
   break;
   }
}

void do_quit(string str) {
    if(!this_player()->getenv("MAIL_DELETE_PROMPT") || str == "Q")
        really_quit(str);
    else if(member_array(1, delete) == -1) really_quit(str);
    else {
        write("Delete all marked letters? (y/n) ");
        input_to("verify_quit");
    }
}

void verify_quit(string str) {
    if(!str || str == "" || lower_case(str[0..0]) == "y") really_quit("q");
    else if(lower_case(str[0..0]) == "n") {
        write("Files will remain undeleted.\n");
        really_quit("Q");
    }
    else {
        write("Invalid input.\nDelete all marked letters? (y/n) ");
        input_to("verify_quit");
    }
}

void really_quit(string str) {
    int i, x;

    if(str == "Q") {
        write("No letters deleted or marked as read.\n");
        dest_me();
        if(this_object()) destruct(this_object());
        return;
    }
    i = sizeof(box_info);
    while(i--) {
        if(delete[i]) {
            x++;
            POSTAL_D->remove_post(owner, box_info[i]["id"]);
        }
    }
    POSTAL_D->flush_files();
    write(x+" letters deleted.\n");
    dest_me();
    if(this_object()) destruct(this_object());
}

void get_to(string str) {
    if(!str || str == "") {
        write("No users or groups named.\n");
        do_mail(0);
        return;
    }
    tmp_post = ([]);

    // Fix by Aragorn
    str = replace_string(str,"@@","");

    tmp_post["to"] = explode(str, " ");
    tmp_post["from"] = (string)this_player()->query_name();
    tmp_post["date"] = time();
    write("Subject: ");
    input_to("get_subject");
}

void get_subject(string str) {
    string tmp_str;
    int i, max;

    if(!str || str == "") str = "[No subject]";

    str = replace_string(str,"@@","");
    tmp_post["subject"] = str;
    write(letter_head(tmp_post, (int)this_player()->query_ansi()));
    this_player()->do_edit(0, "get_text", this_object());
}

void abort() {
    if(just_sending) {
        dest_me();
        if(this_object()) destruct(this_object());
        return;
    }
    do_mail(0);
}

void get_text(string str) {
    if(!str) {
        abort();
        return;
    }
    if(fwd_flag != -1) {
        str += "\n-----\n"+
          "Original message sent by "+capitalize(box_info[fwd_flag]["from"])+
          " to "+capitalize(owner)+" on "+ctime(box_info[fwd_flag]["date"])+
          ":\n-----\n"+(string)LETTER_D->get_message(box_info[fwd_flag]["id"]);
        fwd_flag = -1;
    }

    // Fix by Aragorn
    str = replace_string(str, "@@","");

    tmp_post["message"] = str+"\n";
    tmp_post["message"] += (string)POSTAL_D->read_sig(owner);
    if(!this_player()->getenv("MAIL_NO_CC")) {
        write("Cc: ");
        input_to("get_cc");
        return;
    }
    get_cc("");
}

void get_cc(string str) {
    string dead;
    string *who, *diff, *orig;

    if(!tmp_post["cc"]) tmp_post["cc"] = ({});

    // Fix by Aragorn
    if (str) str = replace_string(str,"@@","");
    if(str && str != "") tmp_post["cc"] += explode(lower_case(str), " ");
    orig = uniq_array(tmp_post["to"]+tmp_post["cc"]);
    diff = orig - (who=(string *)POSTAL_D->post_mail(tmp_post));
    if(sizeof(who)) 
        write("Mail sent successfully to:\n"+format_page(who, 3)+"\n");
    else {
        if(wizardp(this_player())) dead = "/w/"+owner+"/dead.letter";
        else dead = DIR_TMP+"/post/"+owner+".dead";
        write("No recipients found.  Appending to "+dead+".\n");
        write_file(dead, tmp_post["message"]+"\n");
    }
    MAIL_S->flush_mail_queue();
    POSTAL_D->flush_files();
    if(just_sending) {
        dest_me();
        if(this_object()) destruct(this_object());
        return;
    }
    do_mail(0);
}

void do_reply(string cmd, string arg) {
    string *tmp;
    string recep;
    int x, i;

    if(arg && arg != "") {
        if(sscanf(arg, "%d %s", x, recep) != 2) {
            if(!sscanf(arg, "%d", x)) recep = arg;
            else {
                recep = "";
                current = x-1;
            }
        }
        else current = x-1;
    }
    else recep = "";
    if(current < 0 || current >= sizeof(box_info)) {
        write("Invalid letter number (\"?\" for help).\n");
        do_mail(0);
        return;
    }
    else if(recep != "" && recep != "all" && recep != "to") {
        write("Invalid reply parameter: "+recep+" (\"?\" for help).\n");
        do_mail(0);
        return;
    }
    tmp_post["from"] = (string)this_player()->query_name();
    if(recep == "") {
        tmp_post["to"] = ({ box_info[current]["from"] });
        tmp_post["cc"] = ({});
    }
    else if(recep == "to") {
        tmp_post["to"] = ({box_info[current]["from"] })+box_info[current]["to"];
        tmp_post["cc"] = ({});
    }
    else {
        tmp_post["to"] = ({box_info[current]["from"] })+box_info[current]["to"];
        tmp_post["cc"] = box_info[current]["cc"];
    }
    tmp_post["date"] = time();
    if(strlen(box_info[current]["subject"]) < 4 ||
      box_info[current]["subject"][0..3] != "RE: ")
        tmp_post["subject"] = "RE: "+box_info[current]["subject"];
    else tmp_post["subject"] = box_info[current]["subject"];
    write(letter_head(tmp_post, (int)this_player()->query_ansi()));
    this_player()->do_edit( (cmd == "R" ?
      "On "+ctime(box_info[current]["date"])+", "+
      capitalize(box_info[current]["from"])+" wrote:\n>\n>"+
      replace_string((string)LETTER_D->get_message(box_info[current]["id"]),
      "\n", "\n> ")+"\n" : 0), "get_text", this_object());
}

void do_forward(string cmd, string arg) {
    string recep;
    int x, i;

    if(!arg || arg == "") {
        write("Recepient for forward missing (\"?\" for help).\n");
        do_mail(0);
        return;
    }
    if(sscanf(arg, "%d %s", x, recep) == 2) {
        current = x-1;
        tmp_post["to"] = explode(lower_case(recep), " ");
    }
    else tmp_post["to"] = explode(lower_case(arg), " ");
    if(current < 0 || current >= sizeof(box_info)) {
        write("Invalid letter number (\"?\" for help).\n");
        do_mail(0);
        return;
    }
    tmp_post["from"] = (string)this_player()->query_name();
    tmp_post["date"] = time();
    if(strlen(box_info[current]["subject"]) < 10 ||
      box_info[current]["subject"][0..9] != "(forward) ")
        tmp_post["subject"] = "(forward) "+box_info[current]["subject"];
    else tmp_post["subject"] = box_info[current]["subject"];
    tmp_post["cc"] = ({});
    write(letter_head(tmp_post, (int)this_player()->query_ansi()));
    if(cmd == "F") {
        fwd_flag = current;
        this_player()->do_edit(0, "get_text", this_object());
    }
    else {
        get_text("\n-----\nOriginal letter sent by "+capitalize(box_info[current]["from"])+" to "+capitalize(owner)+" "+ctime(box_info[current]["date"])+":\n"+
          "-----
"+(string)LETTER_D->get_message(box_info[current]["id"])+"\n");
    }
}

void read_mail(int x) {
    string borg;

    borg = "Letter "+(x+1)+(delete[x] ? "[DELETED]:\n" : ":\n");
    borg += letter_head(box_info[x], (int)this_player()->query_ansi());
    borg += "\n"+(string)LETTER_D->get_message(box_info[x]["id"])+"\n";
    POSTAL_D->mark_read(owner, box_info[x]["id"]);
    box_info[x]["read"] = 1;
    this_player()->set_finish_func("do_mail", this_object());
    this_player()->more_string(borg);
}

string letter_head(mapping this_letter, int ansi) {
    int i, max;
    string ret;

    ret = ctime(this_letter["date"])+" from ";
    ret += "%^GREEN%^"+capitalize(this_letter["from"])+"%^RESET%^\n";
    ret += "To: ";
    for(i=0, max = sizeof(this_letter["to"]); i<max; i++)
      ret += capitalize(this_letter["to"][i])+" ";
    if(!sizeof(this_letter["cc"])) ret = wrap(ret);
    else {
        ret = wrap(ret)+"Cc: ";
        for(i=0, max = sizeof(this_letter["cc"]); i<max; i++)
          ret += capitalize(this_letter["cc"][i])+" ";
        ret = wrap(ret);
    }
    ret += "Subject: %^GREEN%^"+this_letter["subject"]+"%^RESET%^\n";
    return ret;
}

int valid_shadow() { return 1; }

int drop () { return 1; }

int get() { return 0; }
