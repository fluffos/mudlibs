/*    /std/bboard.c
 *    from Nightmare 3.3
 *    the Nightmare bulletin board system
 *    created by Descartes of Borg 940920
 */

#include <std.h>
#include <daemons.h>
#include "bboard.h"

inherit OBJECT;

nosave private string __BoardID;
nosave private string *__EditOK;

void create() {
    Object::create();
    set_no_clean(1);
    set_prevent_get("You cannot get that!");
    set_prevent_put("You cannot put that in there!");
    set_prevent_drop("Drop a bulletin board?");
    __EditOK = ({});
}

void init() {
    Object::init();
    add_action("cmd_post", "post");
    add_action("cmd_read", "read");
    add_action("cmd_followup_and_respond", ({ "followup", "respond "}));
    add_action("cmd_remove", "remove");
    add_action("cmd_edit", "edit");
    if(!creatorp(this_player())) return;
    add_action("cmd_save", "save");
}

 private int valid_edit(string author) {
    string *allowed;
    string who;

    who = (string)this_player()->query_name();
    if(who == author) return 1;
    if(archp(this_player())) return 1;
    if(member_array(who, __EditOK) != -1) return 1;
    return (int)master()->valid_apply(({}));
}

int cmd_post(string str) {
    string file;

    if(!str) return notify_fail("You must specify a subject.\n");
    if(file_exists(file = DIR_TMP+"/"+(string)this_player()->query_name())) {
        message("system", "You have an abandoned post waiting.",this_player());
        message("system", "        e)dit it, or start n)ew", this_player());
        message("prompt", "\nCommand (default 'n'): ", this_player());
        input_to("begin_post", str, file, (: continue_post :));
    }
    else begin_post("n", str, file, (: continue_post :));
    return 1;
}

protected void begin_post(string cmd, string subj, string file, function f) {
    if(cmd == "" || !cmd) cmd = "n";
    else cmd = cmd[0..0];
    if(cmd != "n" && cmd != "e") {
        message("system", "Invalid bulletin board command.", this_player());
        return;
    }
    if(cmd == "n" && file_exists(file)) rm(file);
    (*f)(subj, file);
}

void continue_post(string subj, string file) {
    this_player()->edit(file, (: end_post :), (: abort_edit :), ({ subj, 0 }));
}

void abort_edit() {
    string file;

    file = (string)this_player()->query_edit_filename();
    if(file && file_exists(file)) rm(file);
}

void end_post(mixed *args) {
    string subj, file, msg;

    if(!(file = (string)this_player()->query_edit_filename())) {
        message("system", "Ack! Lost the file!", this_player());
        return;
    }
    subj = args[0];
    if(!(msg = read_file(file))) {
        message("system", "No file read!", this_player());
        if(file_exists(file)) rm(file);
        return;
    }
    else rm(file);
    if(!args[1])
      BBOARD_D->add_post(query_board_id(),
        (string)this_player()->query_CapName(), args[0], msg);
    else {
        mapping mail;
    }
    message("system", "Message posted!", this_player());
}

int cmd_read(string str) {
    mapping *posts;
    int x, i, maxi;

    maxi = sizeof(posts = (mapping *)BBOARD_D->query_posts(query_board_id()));
    if(!str) {
        for(i=0, x = -1; i<maxi; i++)
          if(member_array((string)this_player()->query_name(),
            posts[i]["read"]) == -1) {
              x = i;
              break;
          }
        if(x == -1) return notify_fail("No unread posts.\n");
    }
    else if(!(x = to_int(str))) return notify_fail("Read what?\n");
    else x--;
    if(x < 0 || x >= sizeof(posts))
      return notify_fail("Invalid post number.\n");
    str = "Post number "+(x+1)+" by "+posts[x]["author"]+"...\n";
    str += posts[x]["post"];
    BBOARD_D->mark_read(query_board_id(),x,(string)this_player()->query_name());
    this_player()->more(explode(str, "\n"), "system");
    return 1;
}

int cmd_followup_and_respond(string str) {
    mapping post;
    function f;
    string file, verb;
    int x;

    if(!str) return notify_fail(capitalize(verb=query_verb())+" which post?\n");
    if((x=to_int(str)) < 1 || x>(int)BBOARD_D->query_number_posts(query_board_id()))
      return notify_fail("Invalid post number.\n");
    x--;
    post = (mapping)BBOARD_D->query_post(query_board_id(), x);
    if((verb = query_verb()) == "respond") f = (: continue_mail, post :);
    else f = (: continue_followup, post :);
    str = post["subject"];
    if(!str) str = "Re: "+possessive_noun(post["author"])+" post";
    else if(strlen(str) <= 4 || str[0..3] != "Re: ") str = "Re: "+str;
    if(file_exists(file = DIR_TMP+"/"+(string)this_player()->query_name())) {
        message("system", "You have an abandoned post waiting.",this_player());
        message("system", "        e)dit it, or start n)ew", this_player());
        message("prompt", "\nCommand (default 'n'): ", this_player());
        input_to("begin_post", str, file, f);
    }
    else begin_post("n", str, file, f);
    return 1;
}

void continue_followup(mapping post, string subj, string file) {
    message("prompt", "\nInclude original text (default 'n'): ",this_player());
    input_to("check_include_text", subj, file, post, 0);
}

void continue_mail(mapping post, string subj, string file) {
    message("prompt", "\nInclude original text (default 'n'): ",this_player());
    input_to("check_include_text", subj, file, post, 1);
}

protected void check_include_text(string ans, string subj, string file, mapping post, int mail) {
    string msg;

    if(ans == "" || !ans) ans = "n";
    else ans = ans[0..0];
    if(ans == "y") {
        msg = post["author"] + " once wrote...\n>";
        msg += implode(explode(post["post"], "\n"), "\n> ")+"\n";
        write_file(file, msg);
    }
    this_player()->edit(file, (: end_post :), (: abort_edit :),
      ({ subj, (mail ? post : 0) }));
}

int cmd_remove(string str) {
    mapping post;
    int x;

    if((x = to_int(str)) < 1 ||
      x > (int)BBOARD_D->query_number_posts(query_board_id()))
        return notify_fail("Invalid post number.\n");
    post = (mapping)BBOARD_D->query_post(query_board_id(), x-1);
    if(!valid_edit(convert_name(post["author"])))
      return notify_fail("You do not have permission to remove that!\n");
    BBOARD_D->remove_post(query_board_id(), x-1);
    message("system", "Post "+x+" removed.", this_player());
    return 1;
}

int cmd_edit(string str) {
    mapping post;
    string file;
    int x;

    if((x = to_int(str)) < 1 ||
      x > (int)BBOARD_D->query_number_posts(query_board_id()))
        return notify_fail("Invalid post number.\n");
    post = (mapping)BBOARD_D->query_post(query_board_id(), x-1);
    if(!valid_edit(convert_name(post["author"])))
      return notify_fail("You do not have permission to edit that post!\n");
    file = DIR_TMP+"/"+(string)this_player()->query_name()+".bb";
    if(file_exists(file)) rm(file);
    write_file(file, post["post"]);
    this_player()->edit(file, (: end_edit :),(: abort_edit :),
      ({ post["subject"], x-1 }) );
    return 1;
}

void end_edit(mixed *args) {
    string file, msg;

    if(!(file = (string)this_player()->query_edit_filename())) {
        message("system", "Ack! Lost the file!", this_player());
        return;
    }
    if(!(msg = read_file(file))) {
        message("system", "No file read!", this_player());
      return;
    }
    else rm(file);
    BBOARD_D->remove_post(query_board_id(), args[1]);
    BBOARD_D->add_post(query_board_id(),
      (string)this_player()->query_CapName(), args[0], msg);
    message("system", "Message posted!", this_player());
}

varargs string query_long(string str) {
    mapping *posts;
    string msg;
    int i, maxi;

    msg = Object::query_long(str);
    maxi = sizeof(posts = (mapping *)BBOARD_D->query_posts(query_board_id()));
    if(!maxi) msg += "There are currently no posts.\n";
    else for(i=0; i < maxi; i++) {
        int lu;

        if(!this_player()) lu = 1;
        else if(member_array((string)this_player()->query_name(),
          posts[i]["read"]) == -1) lu = 0;
        else lu = 1;
        msg += sprintf("[%:-3d] %s %:-17s \"%:-27s %s\n",
          (i+1), (lu ? "     " : "(new)"), posts[i]["author"]+":",
          posts[i]["subject"]+"\"", query_board_time(posts[i]["time"]));
    }
    return msg;
}

void set_board_id(string str) { __BoardID = str; }

string query_board_id() { return __BoardID; }

string query_board_time(int x) {
    string date, day, mon, year, hour, ret;

    if(sscanf(ctime(x), "%s %s  %s %s %s", day, mon, date, hour, year) !=5)
        sscanf(ctime(x), "%s %s %s %s %s", day, mon, date, hour, year);

    sscanf(hour, "%s:%s:%*s", hour, ret);
    return(hour+ret+" "+day+" "+date+" "+mon);
}
