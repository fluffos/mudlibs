#include <std.h>

inherit OBJECT;

nosave private string __Short, __Long, __File;
nosave private mapping __Actions, __Items, __Smells, __Listens, __Objects;
private void main_menu();
protected void primary_prompt();
private string describe_long();

void create() {
    Object::create();
    set_name("roomcreator");
    set_id( ({ "roomcreator" }) );
    set_adjectives( ({ "silly" }) );
    set_short("a room creator");
    set_long("A room creator");
    set_prevent_get( (: "remove" :) );
    set_prevent_put( (: "remove" :) );
    set_prevent_drop( (: "remove" :) );
    set_invis(1);
    set_mass(0);
    set_value(0);
    __Actions = ([]);
    __Items = ([]);
    __Smells = ([]);
    __Listens = ([]);
    __Objects = ([]);
}

void create_room(string str) {
    string file;

    file = absolute_path((string)this_player()->get_path(), str);
    if(!((int)master()->valid_write(file, this_player()))) {
        this_object()->remove();
        return;
      }
    __File = file;
    main_menu();
    primary_prompt();
    input_to("main_cmd");
  }

protected void primary_prompt() { message("prompt","\nCommand: ",this_player()); }

 private void main_menu() {
    message("info", "\n%^INITTERM%^The Nightmare Mudlib Room Creator "
      "\t\tDescartes of Borg 1993", this_player());
    message("info", sprintf("\n%s", center(sprintf("File name: %s", __File))),
      this_player());
    if(__Short) message("info", sprintf("\n\n%%^BOLD%%^Short:%%^RESET%%^ "
      "%s", __Short), this_player());
    else message("info","\n\n%^BOLD%^No short description set.",this_player());
    if(__Long) message("info", sprintf("\n\nLong:\n%s",
      describe_long()), this_player());
    else message("info", "\n\n%^BOLD%^No long description set.",this_player());
    message("info", "\n\n\t\tedit: L)ong description, S)hort description",
      this_player());
    message("info", "\tcreate/remove: a)ctions, i)tems, l)istens, o)bjects, "
      "s)mells", this_player());
}

 private string describe_long() {
    string *items;
    string ret;
    int i, j, x;

    i = sizeof(items = keys(__Items));
    ret = __Long;
    while(i--) {
        if(stringp(items[i]) && (x = strsrch(__Long, items[i])) != -1)
          ret = replace_string(ret, items[i], sprintf("%%^BOLD%%^GREEN%%^%s"
            "%%^RESET%%^", items[i]));
        else if(pointerp(items[i])) {
            j = sizeof(items[i]);
            while(j--)
              if((x = strsrch(__Long, items[i][j])) != -1)
                ret = replace_string(ret, items[i][j],
                  sprintf("%%^BOLD%%^GREEN%%^%s%%^RESET%%^", items[i][j]));
	  }
    }
    return ret;
}

protected void main_cmd(string str) {
    string *tmp;
    string args;

    if(str == "" || !str) {
        message("info", "\n%^RED%^Invalid room creator command.",
          this_player());
        primary_prompt();
        input_to("main_cmd");
        return;
    }
    str = (tmp = explode(str, " "))[0][0..0];
    if(sizeof(tmp) > 1) args = implode(tmp, " ");
    else args = "";
    switch(str) {
        case "a": this_object()->actions(args); return;
        case "h": this_object()->help(args); return;
        case "i": this_object()->items(args); return;
        case "l": this_object()->listens(args); return;
        case "L": this_object()->edit_long(); return;
        case "o": this_object()->Objects(args); return;
        case "s": this_object()->smells(args); return;
        case "S": this_object()->short(args); return;
    }
}

 private void edit_long() {
    if(__Long) write_file("/tmp/"+(string)this_player()->query_name()+
      ".RoomCreator", wrap(__Long, 75));
    message("info", "\n%^INITTERM%^Long description for: "+__File,
      this_player());
    this_player()->edit("/tmp/"+(string)this_player()->query_name()+
      ".RoomCreator", "change_long", this_object());
}

void change_long() {
    string str;

    if(str = read_file("/tmp/"+(string)this_player()->query_name()+
      ".RoomCreator")) __Long = replace_string(str, "\n", " ");
    main_menu();
    primary_prompt();
    input_to("main_cmd");
}
