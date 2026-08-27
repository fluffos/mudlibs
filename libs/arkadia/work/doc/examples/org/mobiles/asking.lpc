inherit "/std/monster";
#include <macros.h>

create_monster()
{
    int i;

    set_name("goblin");
    set_living_name("goblin");
    set_long("It's very small but it looks back on you and shows its teeth.\n");
    set_race_name("goblin");
    set_adj("small");

    set_gender(2); /* male = 0, female = 1, other = 2 */

    set_default_answer("The Goblin says: I don't know what you are talking " +
        "about.\n");
    add_ask(({"weather", "time"}), "The goblin frowns: I don't care about " +
        "weather nor time.\n");
    add_ask("fun", VBFC_ME("fun"));
}

fun()
{
    object for_who;

    for_who = previous_object();

    if (random(2))
    {
        command("say I'll tell you what I like, eating " +
                for_who->query_race_name() + "!!!!");
        command("laugh");
        return "";
    }

    return "The goblin laughs at you.\n";
}

