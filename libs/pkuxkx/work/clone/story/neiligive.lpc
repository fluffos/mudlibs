// story:laojun

#include <ansi.h>

string give_gift();

protected mixed *story = ({
        "欧阳克：叔父，帮帮我....",
        "欧阳锋说道：什么事？",
        "欧阳克：最近我做那个事不行了........",
        "欧阳锋叹了一口气道：没用，我60岁还很行。",
        "欧阳克：.........",
        "欧阳锋：" RED "给你我们家祖传的神药补补！" NOR,
        "欧阳克：快拿来....",
        HIG"欧阳锋突然大叫一声，发了疯..." NOR,
        RED"欧阳锋把丹药扔下了山。" NOR,
        (: give_gift :)
});

void create()
{
        seteuid(getuid());
}

mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}

string give_gift()
{
        STORY_D->give_gift("/clone/story/obj/neili", 1,
                           HIM "\n“啪”的一声一支万年雪莲掉到你面前。\n\n" NOR);
        return HIM "听说白驼山遗落了一支万年雪莲。\n" NOR;
}
