//      /std/room/senses.c
//      from the Nightmare Mudlib
//      allows players to search, hide, smell, listen in every room
//      created by Descartes of Borg 18 june 1993
//      modified to save MAJOR memory by Descartes of Borg 930830

#include <config.h>
#include <rooms.h>

object __Search_Obj;
private mapping __Smells, __Listens, __Searches;

void set_search(string item, mixed desc);
void set_smell(string item, mixed desc);
void set_listen(string item, mixed desc);
void remove_search(string item);
void remove_smell(string item);
void remove_listen(string item);
mixed query_search(string item);
mixed query_smell(string item);
mixed query_listen(string item);
/*
#define __SENSES_C
#include <old_room.h>
*/

void create() {
    __Search_Obj = 0;
    __Smells = ([]);
    __Listens = ([]);
    __Searches = ([]);
}

void initiate_senses() {
    add_action("hide_something", "hide");
    add_action("search_room", "search");
    add_action("smell_things", "smell");
    add_action("do_listen", "listen");
}

int hide_something(string str) {
    int tmp, tmp_wt;
    object ob;

    if(this_player()->query_paralyzed())
      return notify_fail("You cannot move.\n");
    if(!str) return notify_fail("Hide what?\n");
    if(effective_light(this_player()) < -1) 
      return notify_fail("It is too dark.\n");
    if(effective_light(this_player()) > 8)
      return notify_fail("It is too bright to do that.\n");
    if(!(ob = present(lower_case(str), this_player())))
      return notify_fail("You do not have that.\n");
    if(living(ob) || ob->query_property("no hide"))
      return notify_fail("You cannot hide that.\n");
    if(ob->drop()) return 1;
    if(this_player()->query_disable()) return 1;
    this_player()->set_disable();
    tmp_wt = (int)ob->query_weight();
    tmp = 25*(tmp_wt/1000);
    this_player()->add_sp(-1);
    if(random(tmp) > random((int)this_player()->query_skill("stealth"))) {
        notify_fail("You are unable to hide "+str+".\n");
        return 0;
    }
    if(__Search_Obj) {
        message("my_action", sprintf("You are unable to hide %s.", str),
          this_player());
        return 1;
    }
    this_player()->add_skill_points("stealth", random(tmp_wt));
    message("my_action", "You hide it in the shadows.", this_player());
    if(random(101) > (int)this_player()->query_skill("stealth"))
        message("other_action", sprintf("%s hides something.",
          (string)this_player()->query_cap_name()), environment(this_player()),
          ({ this_player() }));
    __Search_Obj = ob;
    ob->move(ROOM_CACHE);
    return 1;
}

int search_room(string str) {

    if(this_player()->query_paralyzed())
      return notify_fail("You are unable to move.\n");
    if(effective_light(this_player()) < -6)
      return notify_fail("It is too dark.\n");
    if(effective_light(this_player()) > 7)
      return notify_fail("It is too bright to see anything.\n");
    if(__Search_Obj && str == "shadows") {
        message("my_action", sprintf("You find %s",
          (string)__Search_Obj->query_name()), this_player());
        message("other_action", sprintf("%s finds something in the shadows.",
          (string)this_player()->query_cap_name()), environment(this_player()),
          ({ this_player() }));
        __Search_Obj->move(this_object());
        __Search_Obj = 0;
        return 1;
    }
    if(!__Searches) return notify_fail("You find nothing of interest.\n");
    if(str == "default") return notify_fail("What is a default?\n");
    if(!str || str == "") str = "default";
    if(functionp(__Searches[str])) (*__Searches[str])(str);
    else if(stringp(__Searches[str])) {
        message("my_action", __Searches[str], this_player());
        message("other_action", (string)this_player()->query_cap_name() +
          " searches around.", this_object(), ({ this_player() }) );
    }
    else message("my_action", "You find nothing odd.", this_player());
    return 1;
}

status smell_things(string str) {
    if(!str || str == "") str = "default";
    if(!__Smells || !__Smells[str]) {
        if(!this_object()->id(str))
          return notify_fail("You do not notice that here.\n");
        else message("smell", "You smell no odd odors.", this_player());
        return 1;
    }
    if(functionp(__Smells[str]))
      message("smell", (string)((*__Smells[str])(str)), this_player());
    else if(stringp(__Smells[str])) {
        message("smell", __Smells[str], this_player());
        if(str == "default") message("other_action",
          (string)this_player()->query_cap_name()+" smells around.",
          this_object(), ({ this_player() }));
        else message("other_action", (string)this_player()->query_cap_name()+
          " smells the "+str+".", this_object(), ({this_player()}));
    }
    else message("smell","You notice no interesting odors.",this_player());
    return 1;
}

status do_listen(string str) {
    if(!str || str == "") str = "default";
    else if(sscanf(str, "to %s", str) != 1)
      return notify_fail("Listen to what?\n");
    if(!__Listens || !__Listens[str]) {
        if(!this_object()->id(str))
          return notify_fail("You do not notice that here.\n");
        else message("listen", "You hear nothing unusual.",this_player());
        return 1;
    }
    if(functionp(query_listen(str)))
      message("listen", (string)((*__Listens[str])(str)), this_player());
    else if(stringp(__Listens[str])) {
        message("listen", __Listens[str], this_player());
        if(str == "default") message("other_action",
          (string)this_player()->query_cap_name()+" listens intently.",
          this_object(), ({ this_player() }) );
        else message("other_action", (string)this_player()->query_cap_name()+
          " listens intently to "+str+".", this_object(),({this_player()}));
    }
    else message("listen", "You hear nothing unusual.", this_player());
    return 1;
}

void set_search(string item, mixed desc) {
   
    __Searches[(item ? item : "default")] = desc;
}

void remove_search(string item) { map_delete(__Searches, item); }

void set_smell(string item, mixed desc) {
    
    __Smells[(item ? item : "default")] = desc;
}

void remove_smell(string item) { map_delete(__Smells, item); }

void set_listen(string item, mixed desc) {
    
    __Listens[(item ? item : "default")] = desc;
}

void remove_listen(string item) { map_delete(__Listens, item); }

mixed query_search(string item) { 
    return (__Searches ? __Searches[item] : 0);
}

mixed query_smell(string item) {
    return (__Smells ? __Smells[item] : 0);
}

mixed query_listen(string item) {
    return (__Listens ? __Listens[item] : 0);
}
