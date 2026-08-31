#include <std.h>

inherit DAEMON;

void cmd_randletter() {
    string *letters;

    letters = {"a","b","c","d","e","f","g","h","i"};

    for (int i = 0; i < 25; i++) {
	write(random(letters[i]));
    }
}
