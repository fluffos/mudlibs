#include <treasure.h>

void
create_treasure()
{
    set_name("newspaper");
    set_id(({ "news", "paper" }));
    set_short("A newspaper");
}

long() {
    cat("/NEWSPAPER");
}

status
read_cmd(string str)
{
    environment(this_player())->tell_here(sprintf("%s reads the newspaper.",
	(string)this_player()->query_name()));
    long();
    return 1;
}

query_weight() { return 1; }

get() { return 1; }

query_value() { return 5; }
