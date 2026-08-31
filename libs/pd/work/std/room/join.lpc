#include <std.h>
#include <tirun.h>
#include <daemons.h>

inherit ROOM;

string cl, subcl;
int align;
string preview_info, join_info;
string *badraces;

void init() {
    ::init();
    add_action("become", "become");
    add_action("preview","preview");
}
void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no bump", 1);
}
void set_class(string c) { cl = c; }
void set_subclass(string s) { subcl = s; }
void set_hall(string dir) {
  add_exit(ROOMS+cl+"/"+subcl+"/"+subcl+"_hall", dir);
  add_pre_exit_function(dir, "check_go");
}
void set_preview(string stuff) { preview_info = stuff; }
void set_join(string stuff) { join_info = stuff; }
void set_badraces(string *r) { badraces = r; }
int preview() {
 if (this_player()->query_class() != cl ||
     this_player()->query_subclass() != "none")  {
        message("info", "You have not the talent to join.", this_player());
        return 1;
    }
    if(this_player()->query_subclass() == subcl){
        message("info", "You are already one of the chosen.", this_player());
        return 1;
    }
    message("info", (string)this_player()->query_cap_name()+" seeks to learn about "+pluralize(cl)+".", this_object(), ({ this_player() }));
    message("info", preview_info, this_player());
    return 1;
}
int become(string str) {
    if(!str) {
        notify_fail("Become what?\n");
        return 0;
    }
    if(str != subcl) {
        notify_fail("You cannot become that here.\n");
        return 0;
    }
    if((string)this_player()->query_class() != cl) {
        write("You must choose the path of "+capitalize(cl)+" first.");
        return 1;
    }
     if (sizeof(badraces) && member_array(this_player()->query_race(), badraces) != -1) {
          write("You are "+a_or_an(this_player()->query_race())+" "+this_player()->query_race()+"!");
          return 1;
      }
   if (this_player()->query_subclass()!="none")
        return notify_fail("You have already chosen your path in life!");

    write(join_info);
    say(this_player()->query_cap_name()+" becomes "+a_or_an(cl)+" "+cl+".",
this_player());
    this_player()->set_subclass(subcl);
    this_player()->set_alignment(align);
    this_player()->setenv("TITLE", "$N the novice "+subcl);
    this_player()->init_skills(cl);
    this_player()->setenv("start",
"/d/tirun/"+cl+"/"+subcl+"/"+subcl+"_hall");
   this_player()->register_channels();
    return 1;
}
int check_go() {
    if(wizardp(this_player())) return 1;
    if((string)this_player()->query_subclass() != subcl) {
        write("You cannot penetrate the force field that blocks the passage.");
        say(this_player()->query_cap_name()+" tries to get into the "
            ""+subcl+"'s inner sanctum, but fails.", this_player());
        return 0;
    }
    if (sizeof(regexp(this_player()->query_riders()->query_class(), cl, 2))) {
      message("info", "You may not bring non-"+pluralize(cl)+" inside.", this_player());
      return 0;
    }
    return 1;
}
