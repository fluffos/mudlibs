/*    /std/obj/deed.c
 *    from Nightmare IV
 *    a deed to a new estate
 *    created by Descartes of Borg 940515
 */

#include <std.h>
#include <dirs.h>
#include <daemons.h>
#include <security.h>

inherit OBJECT;

nosave private string __File, __Short, __Long, __Smell, __Listen;
nosave private int __Indoors;

void create() {
    Object::create();
    set_name("estate deed");
    set_id( ({ "deed", "estate deed" }) );
    set_adjectives( ({ "estate", "an", "a" }) );
    set_short("an estate deed");
    set_long("A script of paper indicating that the bearer may claim "
      "land in places which allow such claiming for the building of "
      "an estate.  The owner, a high mortal, should take the deed to "
      "the place where the estate is to be built and type <build estate>."
    );
    set_mass(0);
    set_value(10);
    set_destroy();
}

void init() {
    Object::init();
    add_action("cmd_build", "build");
}

protected int cmd_build(string str) {
    if(str != "estate") return 0;
    message("system", "You will now be asked to give some information "
      "about the estate you plan to build.  In the room you now stand, "
      "the description \"The estate of "+
      capitalize((string)this_player()->query_name())+" stands here.\"  "
      "will appear.  Players will type <enter estate> to get into "
      "the entrance room of your estate.  The information you are "
      "being asked is dedicated to configuring the entrance area to your "
      "estate.  Make sure that your entrance area makes sense with respect "
      "to the area surrounding it, or approval will move it.", this_player());
    message("prompt", "\nFirst, is this entrance indoors or outdoors? ",
      this_player());
    input_to("get_indoors");
  }

protected void get_indoors(string str) {
    if(!str) str = "";
    if(str == "indoors") __Indoors = 1;
    else if(str == "outdoors") __Indoors = 0;
    else {
      message("prompt", "Answer \"indoors\" or \"outdoors\": ", this_player());
        input_to("get_indoors");
        return;
    }
    message("system", "Now you will asked to give a one line description "
      "of the entrance area.  For example, \"the entrance to "+
      possessive_noun(this_player())+" estate\" is a good short. "
      "Make sure the words are lower case unless referring to a proper "
      "noun.", this_player());
    message("prompt", "Enter a short description: ", this_player());
    input_to("get_short");
  }

protected void get_short(string str) {
    if(str == "" || !str) {
        message("prompt", "Enter a valid short: ", this_player());
        input_to("get_short");
        return;
      }
    __Short = str;
    message("system", "Now create a verbose description for the room.  "
      "This is what people will see when they type \"look\".",this_player());
    message("system", "You will enter an editor like when you mail to "
      "enter this long description.",this_player());
    if(file_exists("/tmp/"+geteuid(this_player())+".build"))
      rm("/tmp/"+geteuid(this_player())+".build");
    this_player()->edit("/tmp/"+geteuid(this_player())+".build",
      "get_long", this_object());
}

protected void get_long(){
    string str;

    if(!(str = read_file("/tmp/"+this_player()->query_name()+".build"))) {
        __Indoors = 0;
        __Short = 0;
        message("system", "Build aborted.", this_player());
        return;
    }
    __Long = capitalize(replace_string(str, "\n", " "));
    message("system", "If you want to have a general smell to the room, "
      "enter it here.  Just hit <return> if there is no general scent.",
      this_player());
    message("prompt", "Enter smell: ", this_player());
    input_to("get_smell");
}

protected void get_smell(string str) {
    if(str == "" || !str) __Smell = 0;
    else __Smell = capitalize(str);
    message("prompt", "Now any general sounds? ", this_player());
    input_to("get_listen");
}

protected void get_listen(string str) {
    if(str == "" || !str) __Listen = 0;
    else __Listen = capitalize(str);
    __File = sprintf("%s/%s/%d.dat", ESTATES_DIRS, geteuid(this_player()),
      time());
    seteuid(UID_ESTATES);
    if(file_size(sprintf("%s/%s", ESTATES_DIRS, geteuid(this_player()))) !=-2)
      mkdir(sprintf("%s/%s", ESTATES_DIRS, geteuid(this_player())));
    write_file(__File, sprintf("set_property: $indoors;#%d\n", __Indoors));
    write_file(__File, sprintf("set_short: $%s\n", __Short));
    write_file(__File, sprintf("set_long: $%s\n", __Long));
    write_file(__File, sprintf("add_exit: $%s;$out\n",
      file_name(environment(this_player()))));
    if(__Smell) write_file(__File,sprintf("set_smell: $default;$%s",__Smell));
    if(__Listen)
      write_file(__File, sprintf("set_listen: $default;$%s", __Listen));
    ESTATES_D->create_estate(environment(this_player()), __File,
      geteuid(this_player()));
    message("system", "Estate begun.", this_player());
}






