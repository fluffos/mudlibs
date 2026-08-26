#include <std.h>

int id(string str) { return (str == "toy"); }

string query_short() { return "a toy"; }

string query_long()
{
    write("This is a silly toy.\n");
}

int get() { return 1; }


void init()
{
     add_action("cmd_toy", "toy");
}

int cmd_toy()
{
    seteuid(geteuid(previous_object()));
    printf("This object has the euid of : %s\n", geteuid(this_object()));
    return 1;
}


void move(object ob)
{
     move_object(this_object(), ob);
}
