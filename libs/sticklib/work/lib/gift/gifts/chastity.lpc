// This "gift" is actually a punishment for sexual crimes. /Graah
#include <treasure.h>
#include <properties.h>

void
create_treasure()
{
    set_name("chastity belt");
    set_short("Chastity Belt (worn)");
    set_long("It is a belt made of steel, locked around your waist. \
You cannot remove it, it is a punishment for your crimes!");
    set_id(({ "belt", "chastity" }));
}

string
query_auto_load()
{
    return "/lib/gift/gifts/chastity:";
}

int
query(int f)
{
    return (f == OBJ_NO_DROP);
}

int drop() { return 1; }
