// story:niulang 牛郎织女

#include <ansi.h>

string give_gift();

private mixed *story = ({
        "江湖风平浪静。",
});

void create()
{
        seteuid(getuid());
}

mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}
