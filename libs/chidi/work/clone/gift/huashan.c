// story:huashan.c

#include <ansi.h>

string give_gift();

private mixed *story = ({
        "岳不群：哎呀，人老了，身子骨也不行了。",
        "岳不群：阿冲啊，你那里有没有强身建骨的什么药没有？",        
        "令狐冲：有，有，我这儿正好有几颗伟哥，还是从海外得来的。",
        "岳不群大喜道：好，快给我两颗。",
        "令狐冲疑惑道：莫非......",
        "岳不群长叹一声：不是不是，是我们家那口子是越来越不行了。",
        "令狐冲掏出一葫芦：喏，这儿。不过，这药好象是男士专用的。",
        "岳不群：" HIC "哎呀！" NOR,
        "岳不群：那可不行。看来这药不大适合你师娘用。",
        "岳不群随手将伟哥还给了令狐冲。",
        "令狐冲：不好，怎么掉了，马上派人去找找。",
        "岳不群：算了算了，不就一颗药丸嘛，你再去找一颗就是了。",
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
        STORY_D->give_gift("/d/city/obj/jitui", 1,
                           HIM "\n“啪”的一声一枚药丸掉到你面前。\n\n" NOR);
        return HIM "听说华山派遗落了一枚药丸。\n" NOR;
}
