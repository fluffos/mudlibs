// Daos

#include <std.h>

inherit DAEMON;

int cmd_hunters(string str) {
    object *hunters = this_player()->query_hunted(); 
    object attacker = this_player()->query_last_attacker();
    write("%^BLUE%^+=+=%^BOLD%^(%^RESET%^%^BOLD%^Hunters%^RESET%^%^BOLD%^BLUE%^)%^RESET%^BLUE%^=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=%^RESET%^\n");
    if (sizeof(hunters) == 0) {
	write("There is no one hunting you!\n");
	write("%^BLUE%^+=+==+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=%^RESET%^\n");
	return 1;
    } 
    if (!attacker) {
	write("%^BOLD%^No previous attacker.%^RESET%^\n"); 
	write("%^BLUE%^+=+==+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=%^RESET%^\n"); 
    }
    else {   
	write("%^BOLD%^Your last attacker is "+attacker->query_short()+".\n"); 
	write("%^BLUE%^+=+==+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=%^RESET%^\n");    
    }

    foreach(string desc in hunters->query_short()) {
	write(" "+desc+"\n"); 
    }  
    write("%^BLUE%^+=+==+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=%^RESET%^\n");
    return 1;  
}  

void help() {
    write("Syntax: <hunters>\n"
      "This command lets you know who is hunting you.\n"); 
} 
