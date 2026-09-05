// story:laojun

#include <ansi.h>

string give_gift();

protected mixed *story = ({
        "玉皇大帝：老君，你那儿有没有能提高人轻功的药？",
        "太上老君：有，有，我这儿正好新研制了一种仙丹。",
        "玉皇大帝大喜道：好，快给我两颗。",
        "太上老君掏出一葫芦：喏，这儿。",
        "玉皇大帝：" HIC "哎呀！" NOR,
        "太上老君：不好，怎么掉了，马上派人去找找。",
        "玉皇大帝：算了算了，不就一仙丹嘛，再给我一颗就是了。",
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
        STORY_D->give_gift("/clone/story/obj/xiandan", 1,
                           HIM "\n“啪”的一声一枚仙丹掉到你面前。\n\n" NOR);
        return HIM "听说天庭遗落了一枚仙丹。\n" NOR;
}
