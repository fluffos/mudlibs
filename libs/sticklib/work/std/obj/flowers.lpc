// Added cardtext, flnam, flval, flcol and read 22.12.1991 //Frobozz
//
// Re-coded 07-feb-95 by Doomdark.

#include <treasure.h>

string sender,cardtext,flnam,flcol;
int flval;

void
create_treasure()
{
    set_name("bunch of red roses");
    set_id(({ "bunch", "flowers" }));
    set_short("A bunch of red roses");
    set_weight(0);
}

void
init()
{
    add_action("smell_cmd", "smell");
}

void
update_me()
{
    set_name("bunch of "+flcol+" "+flnam);
    set_id(({ "card", "bunch", "flowers", "bunch of "+flnam,
	"bunch of "+flcol+" "+flnam, flcol + " " +flnam, flnam }));
}

varargs string
query_long(string str, object who)
{
    if(str == "card")
	return cardtext + "\n" + "        "+sender+".";
    return "They look beautiful and smell wonderful. There's a small card\
 attached to them. Maybe you should read it?";
}

status
read_cmd(string str)
{
    if (str!="card") return 0;
    this_player()->tell_me(query_long(str));
    return 1;
}

status
smell_cmd(string str)
{
    object ob;
    int i;
    if (!str || !(ob = present(str, environment())))
	return notify_fail("Smell what?\n"), 0;
    if (ob != this_object())
	return (int) ob -> smell_cmd(str);
    if (str == "card" || sscanf(str, "card %d")) {
	this_player()->tell_me("It doesn't smell of anything special.");
	return 1;
    }
    this_player()->tell_me("Ok. Aaaaahhhhhhhhhhhhhhhhhhhh...");
    environment(this_player()) -> tell_here((string)this_player()->query_name()
      + " smells a bunch of flowers.", this_player());
    return 1;
}

void set_sender(string str) { sender = str; }
void set_cardtext(string str) { cardtext=str; }

void
set_flowers(string str)
{
    flnam = str;
    update_me();
}

void
set_colour(string str)
{
    flcol = str;
    update_me();
}

void set_value(int i) { flval=i; }

string query_sender() { return sender; }
int query_value() { return flval; }
