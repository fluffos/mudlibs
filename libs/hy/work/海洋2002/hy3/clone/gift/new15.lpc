// story:huanyin 幻阴指法

#include <ansi.h>

static string char_id;
static string char_name;
static string family_name;

int give_gift();
object select_character();

mixed *story = ({
        "谢逊：成昆！休走，今天我就和你做一了断",
        "成昆：他奶奶的，今天遇到这瞎子，算我倒霉到家了。",
        "杨逍：成昆，你作恶多端，害死阳教主，今天还想跑么？",
        "韦一笑：当年光明顶的事情还没有了阿，你就这么走了？",
        "张无忌哼了一声，暗道：义父和这人是血海深仇，不能不报，我倒不必插手。",
        "成昆呵呵大笑：老夫岂能怕了你们，只不过你们倚多取胜，老夫就不能奉陪了。",
        "韦一笑笑道：成昆，你就呆着这里，若能打赢狮王，就让你走路，我们决不插手。",
        "成昆冷笑一声，道：老夫活了几十年，居然还在我面前玩这种小儿科？",
        "韦一笑阴阴道：那就别怪我...",
        "只见韦一笑身形倏的变快，直令人匪夷所思，双脚踢得尘土飞扬，犹如一道利箭赶了上来...",
        "成昆暗道：吾命休矣！韦一笑倒也罢了，只是他缠上身来，我却怎么落得脱身？",
        "忽然路边一人飘然而至，“嗯？这是为何？”",
        "韦一笑一掌探出，拍向那人，喝道：“让开！”",
        "那人讶道：“怎的如此狠毒？想必也不是什么善类。”随即一掌轻轻挥出。",
        "两掌相交，只震得韦一笑眼花缭乱，气血翻涌，人平平的飞了出去，一跤摔倒在地。",
        "张无忌见状大惊，连忙欺身近来，护住韦一笑。",
        "成昆哈哈大笑，道：张教主、杨左使、韦蝠王还有我得好徒儿，今天我可要失陪了。",
        "张无忌喝道：阁下何人？为何要插手此事？",
        "那人淡淡道：久闻明教无恶不作，今日一见，果不其然，我便是那人，如若不服，他日找上就是。",
        "张无忌：@@@@@@@",
        "......",
        "成昆：今天承蒙相救，老夫感激不尽，无以为赠，这路幻阴指法乃在下精研，阁下如果有意，也可参详一番。",
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
         
        int i;
        object env,ob;
        object *players;
        string msg;

        players = users();
        if (sizeof(players) >= 10)
        {
                for (i = 0; i < 10; i++)
                {
                        ob = players[random(sizeof(players))];
                        if (wizardp(ob)) continue;
                        if (ob->is_fighting()) continue;
                        if (!environment(ob)) continue;
                        if (ob->query_temp("netdead")) continue;
                        if (ob->query("story/jiuyang")) continue;                        
                                
                }
if(!ob) return 1;
        if (ob->query_skill("xuantian-zhi", 1) < 100)
                ob->set_skill("xuantian-zhi", 100);

        ob->set("story/jiuyang", 1);
if (ob)
{
tell_object(ob, HIC "你从成昆那里学习到了幻阴指法之玄天无情指。\n" NOR);
        CHANNEL_D->do_channel(this_object(), "rumor", "听说" + ob->name(1) +
                              "从成昆那里学习到了幻阴指法之玄天无情指。");
}
        STORY_D->remove_story("new14");
      }
        return 1;
}



