//Created by Shya July 16, 2000 for a teacher's classroom.//

inherit OBJECT;

void create() {
    set("author", "shya");
    set("long", @EndText
Black boards covered with Mr. Shallar's class notes on it.  
Maybe you should 'read' them.
.
EndText);
    set("short", "Black Boards");
    set("id", ({ "boards", "black", "black boards" }) );
}

void init() {
    add_action("read_boards", "read");
}

int read_boards(string str) {
    object ob;
    if (!str) return 0;
    ob = present(str, environment(TO));
    if (!ob) {
	write ("Read What?\n");
	return 1;
    }

    write(wrap(
	"You read the black board with Mr. Shallar's notes on them.\n"
	"Be a good student and copy them down for future reference.\n"
	"Pop Quiz tomorrow.\n"
	"Questions concerning the Louisiana territory purchase as well as the Louis & Clark expodition.\n"
      "Also an essay question regarding the rights and wrongs of that purchase.\n"
      "Any questions you might have please ask them when I am in the room.\n"
      "Thanks,  Mr. Shallar.\n"
));
    say(TPN+" reads Mr. Shallar's black board full of notes maybe you should too.\n");
    return 1;
}
