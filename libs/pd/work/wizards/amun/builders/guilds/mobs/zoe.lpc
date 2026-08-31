#include <std.h>
#include <daemons.h>
#include <arlon.h>
#include <security.h>
#include <tirun.h>
#include <boat.h>
#define DESCRIBE_PRICE 5000 
#define NAME_PRICE 1000
inherit MONSTER;
void create() {
    ::create();
    set_name("Zoe");
    set_short("Zoe");
    set_level(70);
    set_race("human");
    set_body_type("human");
    set_gender("female");
    set_id(({ "monster", "zoe" }));
    set_long( "Zoe is the guild wax maker. She works hard to customize waxes for each guild.  You may <%^CYAN%^set%^RESET%^> your descriptions, or <%^CYAN%^rename%^RESET%^> your waxes.");
}
void init() {
    ::init();
    add_action("f_set", "set");
    add_action("w_rename", "rename");
}
int f_set(string s) {
    object ob;
    if(!s) return notify_fail("Syntax: <set [description]>\n");
    ob=present("wax", this_player());
    if(!ob) ob=new(OBJ"seal_blank");
    if(!ob->query_owner()) ob->set_owner(this_player()->query_name());
    ob->load();
    if(!ob->query_valid_long(s)) { 
	write("Your description contains illegal words.  Please remove all swear words.\n"); 
	return 1; 
    }
    if(this_player()->query_money("gold") < DESCRIBE_PRICE) {
	write("You do not have the "+DESCRIBE_PRICE+" gold required to "
	  "change the description of your waxes.");
	return 1;
    }
    this_player()->add_money("gold", -DESCRIBE_PRICE);
    write("You change the description of your waxes.\n");
    ob->set_long_short(s);
    return 1;
}
int w_rename(string s) {
    object ob;
    if(!s) return notify_fail("Syntax: <rename [name]>\n");
    ob=present("wax", this_player());
    if(!ob) ob=new(OBJ"seal_blank");
    if(!ob->query_owner()) ob->set_owner(this_player()->query_name());
    ob->load();
    if(!ob->query_valid_long(s)) { 
	write("Your wax name contains illegal words.  Please remove all swear words.\n"); 
	return 1; 
    }
    if(this_player()->query_money("gold") < NAME_PRICE) {
	write("You do not have the "+NAME_PRICE+" gold required to "
	  "change the name of your waxes.");
	return 1;
    }
    this_player()->add_money("gold", -NAME_PRICE);
    write("You change the name of your waxes.\n");
    ob->set_long_short(s);
    return 1;
}
