#include <ansi.h>
int give_gift();
mixed *story =
({
        "话说某天雷公和电母吵架，雷公挨了电母一掌两拳三脚，心情十分郁闷。",
        "想来想去，没什么事情干......",
        "......",
        "要不出去打打雷，吓唬吓唬那些小妖怪吧？",
        "想到这里，雷公嘿嘿奸笑了几声。",
        "于是乎，带上震天锤，出门一拨云头就出门了",
        "轰隆隆......",
        "轰隆隆.........",
        "....................",
        "看着地下小妖怪吓得屁颠屁颠乱跑，雷公爽歪歪了",
        "突然传来一声大喝：",
        "“小雷崽子，活腻歪了，敢来你孙大圣门前打雷？”",
        "雷公低头一看，原来来到了花果山的地界",
         "雷公一哆嗦，手中不稳，震天锤掉下凡间。",
        (: give_gift :),
});

void create()
{
        seteuid(getuid());
}

mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}

int give_gift()
{
        STORY_D->give_gift("/clone/story/obj/zhentianchui", 1,
        HIY "\n一把"NOR+HIW"震天锤"HIY"从天而降，把地上砸了一个大坑。\n\n" NOR);
        return 1;
}

