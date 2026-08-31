//  Buddy List by Nightshade

#include <std.h>
inherit DAEMON;

int cmd_enemylist(string str) {
    string *list, total;
    if(!str) {
	list = this_player()->query_full_enemy();
    if(sizeof(list) > 400) {
      for(int i=1; i < sizeof(list); i++)
        this_player()->remove_enemy(list[i]);
    list = ({});
    }
	if(sizeof(list) < 1) {
	    write("No enemies in list.");
	    return 1;
	}
	write("%^RED%^+=+=%^BOLD%^( %^WHITE%^Enemy List %^RED%^)%^RESET%^%^RED%^=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=%^RESET%^\n");
	//  write("  %^BOLD%^%^CYAN%^Enemies\n%^BLUE%^==============================================================");
	total = "   "+capitalize(list[0]);
	if(sizeof(list) > 1)
	    for(int i=1; i < sizeof(list); i++)
		total += ", "+capitalize(list[i]);
	write(total);
	return 1;
    }
    if(sscanf(str,"add %s", str) == 1) {
	str = lower_case(str);
          if( sizeof( this_player()->query_full_enemy() ) >= 400 )
              return notify_fail("Your enemylist is full.\n");
	if(member_array(str, this_player()->query_full_enemy())+1) {
	    write(capitalize(str)+" is already in your list!");
	    return 1;
	}
	this_player()->add_enemy(str);
	write(capitalize(str)+" added to your list.");
	return 1;
    }
    if(sscanf(str,"remove %s", str) == 1) {
	if(!this_player()->remove_enemy(str) && !this_player()->remove_enemy(lower_case(str)))
	    write("Enemy not found.");
	else
	    write(capitalize(str)+" removed.");
	return 1;
    }
    write("Syntax: <enemylist add [person]>\nSyntax: <enemylist remove [person]>\nSyntax: <buddylist>\n");
    return 1;
}

void help() {
    message("info", "Syntax: <enemylist add [person]>\n"
      "Syntax: <enemylist remove [person]>\n"
      "Syntax: <enemylist>\n"
      "The enemylist informs you when people on your list come on and offline.\n"
      "If you type only <enemylist>, it will display everyone in your list.", this_player());
}
