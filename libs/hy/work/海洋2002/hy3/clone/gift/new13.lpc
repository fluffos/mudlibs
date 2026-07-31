// story:jiuyang 九阳神功

#include <ansi.h>

static string char_id;
static string char_name;

int give_gift();
object select_character();

mixed *story = ({
        "一堆佛经。",
        "那人拿起一本细细的看了半天，却不得要领，这分明就是一本佛经，没有半点武功诀窍。",
        "那人沉思片刻，将书反了过来，逆句读、跳字读，还是没有什么奥妙。",
        "盛怒之下，那人用力将佛经扔了开去，又拣起一本，却是《金刚经》。",
        "研读片刻，还是一堆废话。",
        "“岂有此理，少林寺的藏经阁就放了这些东西？”那人心中暗道：“莫非少林僧人其实都不会武功？”",
        "随拣随丢，须臾已经翻了几十本经书，没有找到半点头绪。",
        "那人不由得暗暗叫苦，看了看地上躺着的慧真和道一二人，心想：这次闯进藏经阁，实在是干冒奇险，居然...",
        "一时间那人不由得心头大怒，将手中的经书撕了个粉碎，霎时纸片飞扬。",
        "忽然几张碎纸片飘过那人的眼前，似乎写着：力从人借，气由脊发。胡能气由脊发...",
        "那人见识不凡，看了这几句心中登时一动，这分明是极上乘的武学诀窍！",
        "那人看了看手中剩下的半卷经书，赫然是一本：《楞伽经》，只见夹缝中密密麻麻的写着一些文字。",
        "只是经书已经缺了一半，如何是好？那人连忙在地上慢慢寻找，把碎纸一片片寻回。",
        "待到碎片悉数裱好，已然过了两个时辰，那人细细读过，原来这《楞伽经》夹缝中居然录有一份九阳真经。",
        "那人心下暗自琢磨：当年华山论剑，也不过是争夺一本九阴真经而已，今天我得了此书，当真是奇遇。",
        "那人随即将烛台拿近，慢慢揣摩真经要旨，只是真经博大精深，一时未能全然领悟。",
        "眼见天色渐晚，那人不敢久留，揣起经书，想了想，又把经文开头一段扯下撕碎，这才收好。",
        "那人暗道，待我回去细细研读这九阳真经，他日天下无敌，岂不美哉？",
        "想罢，那人跃出窗去，悄然飘失在夜幕中。",
        (: give_gift :),
});

string prompt() { return HIG "【武林奇遇】" NOR; }

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
                        if (ob->query("family/family_name")!="明教") continue;
                        if (!ob->query_skill("jiuyang-shengong", 1)) continue;
                        if (ob->query("story/jiuyang")) continue;                        
                                
                }
if(!ob) return 1;
if ((int)ob->query_skill("jiuyang-shengong", 1) >1)
{
        if (ob->query_skill("jiuyang-shengong", 1) < 100)
                ob->set_skill("jiuyang-shengong", 100);
}
        ob->set("story/jiuyang", 1);
if (ob)
{
tell_object(ob, HIC "你学习到了九阳神功。\n" NOR);
        CHANNEL_D->do_channel(this_object(), "rumor", "听说少林寺"
                              "藏经阁失窃，遗失楞伽经一本。");
}
        STORY_D->remove_story("new13");
      }
        return 1;
}
