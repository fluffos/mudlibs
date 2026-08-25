#include <std.h>

inherit OBJECT;

private mapping __GuildInfo;

void create() {
    ::create();
    set_no_clean(1);
    set_prevent_drop("You cannot drop that!");
    set_prevent_get("You cannot get that!");
    set_prevent_put("You cannot put that in there!");
    __GuildInfo = ([]);
    __GuildInfo["file"] = base_name(this_object());
}

void init() {
    if((string)this_player()->query_guild() != __GuildInfo["guild"]) {
      remove();
      if(this_object()) destruct(this_object());
      return;
    }
    if((string)this_player()->query_name() != __GuildInfo["leader"]) return;
    add_action("__Bring", "bring");
    add_action("__Initiate", "initiate");
    add_action("__Retire", "retire");
}

int __Initiate(string str) {
    object ob, tmp;

    if((string)this_player()->query_name() != __GuildInfo["leader"]) return 0;
    if(!str) return notify_fail("Initiate whom?\n");
    if(!(ob=present(lower_case(str),environment(this_player()))) || !living(ob)) 
      return notify_fail("No one of that nature here.\n");
    if(!((*__GuildInfo["test"])(ob))) return 1;
    if(this_player()->query_mp() < 200)
      return notify_fail("Too low on magic power.\n");
    if(ob->query_guild())
      return notify_fail("You may only initiate people without guild affiliation.\n");
    ob->set_guild(__GuildInfo["guild"]);
    ob->setenv("start", __GuildInfo["home"]);
    tmp = new(__GuildInfo["file"]);
    tmp->move(ob);
    this_player()->add_mp(-300);
    if(functionp(__GuildInfo["newbie"])) (*__GuildInfo["newbie"])(ob);
    else {
        if(stringp(__GuildInfo["newbie"]))
          message("info", __GuildInfo["newbie"], ob);
        else message("info", "You are now a member of the "+
          pluralize(__GuildInfo["guild"])+".", ob);
        message("other_action", (string)ob->query_cap_name() +
          " is now a member of the "+pluralize(__GuildInfo["guild"])+".",
          environment(ob), ({ ob }));
    }
    return 1;
}

int __Retire(string str) {
    object ob, tmp;

    if((string)this_player()->query_name() != __GuildInfo["leader"]) return 0;
    if(!str) return notify_fail("Retire whom?\n");
    if(!(ob = present(lower_case(str), environment(this_player()))))
      return notify_fail(sprintf("No %s here!\n", capitalize(str)));
    if(!living(ob))
      return notify_fail(sprintf("%s is not alive!\n", capitalize(str)));
    if((string)ob->query_guild() != __GuildInfo["guild"])
      return notify_fail(capitalize(str)+" is not one of us!\n");
    ob->set_guild(0);
    if(tmp=present(__GuildInfo["guild"]+"_guild", ob)) tmp->remove();
    message("my_action", capitalize(str)+" is no longer a member of the "+
      pluralize(__GuildInfo["guild"])+"!", this_player());
    message("other_action", (string)this_player()->query_cap_name() +
      " has removed you as a member of the "+pluralize(__GuildInfo["guild"])+
      "!", ob);
    return 1;
}

mixed *query_auto_load() { return ({ __GuildInfo["file"], ({}) }); }

void init_arg(mixed *arg) {
    if(functionp(__GuildInfo["welcome"])) (*__GuildInfo["welcome"])(arg);
}

string extra_look() { 
    if(stringp(__GuildInfo["guild description"]))
      return (string)environment(this_object())->query_cap_name() + " "+
        __GuildInfo["guild description"];
    else if(functionp(__GuildInfo["guild description"]))
      return (string)((*__GuildInfo["guild description"])());
    else return 0;
}

string get_title(int lev) { return capitalize(__GuildInfo["guild"]); }

int __Bring(string str) {
    object who;

    if(!str) return notify_fail("Bring whom?\n");
    if(!(who = find_player(lower_case(str))))
      return notify_fail(capitalize(str)+" is nowhere to be found.\n");
    if((string)who->query_guild() != __GuildInfo["guild"])
      return notify_fail(capitalize(str)+" is not one of you!\n");
    if(environment(who)->query_property("no teleport")) {
	notify_fail("A magic force blocks your powers.\n");
	return 0;
    }
    if(environment(this_player())->query_property("no teleport")) {
	notify_fail("A magic force blocks your powers.\n");
	return 0;
    }
    if(environment(this_player())->query_property("no magic")) {
	notify_fail("A magic force blocks your powers.\n");
	return 0;
    }
    if((int)this_player()->query_mp() < 70) {
	notify_fail("Too low on magic power,\n");
	return 0;
    }
    who->move_player(environment(this_player()));
    who->move(environment(this_player()));
    who->describe_current_room(1);
    return 1;
}

void set_guild_name(string str) {
    if(stringp(__GuildInfo["guild"])) return;
    __GuildInfo["guild"] = str;
}

void set_new_member(mixed val) { __GuildInfo["newbie"] = val; }

void set_welcome(mixed val) { __GuildInfo["welcome"] = val; }

void set_guild_description(mixed val) { __GuildInfo["guild description"]=val; }

void set_leader(string str) {
    if(!user_exists(str)) {
        error("No such user: "+str+".  You must have a real leader.");
        return;
    }
    __GuildInfo["leader"] = str;
}

void set_guild_test(function f) { __GuildInfo["test"] = f; }

void set_guild_object(string str) { __GuildInfo["file"] = str; }

void set_guild_home(string str) { __GuildInfo["home"] = str; }

string query_guild_name() { return __GuildInfo["guild"]; }

mixed query_new_member() { return __GuildInfo["newbie"]; }

mixed query_welcome() { return __GuildInfo["welcome"]; }

mixed query_guild_description() { return __GuildInfo["guild description"]; }

string query_leader() { return __GuildInfo["leader"]; }

function query_test() { return __GuildInfo["test"]; }

string query_guild_object() { return __GuildInfo["file"]; }

string query_guild_home() { return __GuildInfo["home"]; }
