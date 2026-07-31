// story:yanmen 雁门关外阻击

#include <ansi.h>

string show_time();
void create_quest();

mixed *story = ({
        (: show_time :),
        "少林方丈玄慈接到一封信件。", 
        "信中写道：契丹国有大批武士要来偷袭少林寺，想将寺中秘藏数百年的武功图谱一举夺去。",
        "玄慈大师心想：不行，要是契丹此举成功，大宋便有亡国之祸。",
        "玄慈大师一看，信中还写道：听说这些契丹武士要道经雁门。",
        "玄慈大师心想：要在雁门关外迎击，纵不能尽数将之歼灭，也要令他们的奸谋难以得逞。",
        "玄慈大师盘算：丐帮汪帮主，万胜刀王维义，黄山鹤云道长，还有一些武林朋友都可以去迎击。",
        "玄慈大师盘算：但是恐怕敌人人数还是会比我们多得多，况且我们这边武功精强者也是寥寥无几。",
        "玄慈大师发愁：这可怎么办呢？",
        "玄慈大师深深地叹了口气。",
        ".........", 
        "一场血战即将在雁门关外展开.........",
        (: create_quest :),
});

string prompt() { return HIY "【武林传奇】" NOR; }

void create()
{
        seteuid(getuid());
}

mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}

string show_time()
{
        return NATURE_D->game_time() + "，少林寺。";
}

void create_quest()
{
        catch(call_other(QUEST_DIR + "block.c", "startup"));
}

int query_interval() { return 86400; }
