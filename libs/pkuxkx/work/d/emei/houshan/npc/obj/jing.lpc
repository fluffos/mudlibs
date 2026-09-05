// 大般涅槃经
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("经文", ({"jing", "paper"}));
        set_weight(200);
        set("is_jing",1);
        set("unit", "页");
        set("long","这是一页大般涅槃经的经文。\n");
        set("material", "paper");
}

void init()
{
    add_action("do_hedui","hedui");
    add_action("do_bu","gai");
}

int do_hedui()
{
    object me=this_player();
    string jingwen="如是我闻。一时，世尊住王舍城之\n灵鹫山。其时，韦提希子，摩揭陀\n王阿阇世欲征伐跋耆人。于此，彼\n如是言：‘\n彼等虽有如是大神力、大威力，我\n欲伐此跋耆人，我欲根绝跋耆人，\n我欲令灭亡跋耆人，我欲令致破灭\n跋耆人。’\n";
    string * jing_wen=({"如","是","我","闻。","一","时，","世","尊","住","王","舍","城","之","灵","鹫","山。","其","时，","韦","提","希","子，","摩","揭","陀","王","阿","阇","世","欲","征","伐","跋","耆","人。","于","此，","彼","如","是","言：‘","彼","等","虽","有","如","是","大","神","力、","大","威","力，","我","欲","伐","此","跋","耆","人，","我","欲","根","绝","跋","耆","人，","我","欲","令","灭","亡","跋","耆","人，","我","欲","令","致","破","灭","跋","耆","人。’"});
    string word,word2;
    string afterjingwen;
    if (me->query_temp("emnewbiejob/jingwen/hedui"))
    {
        tell_object(me,"你刚刚核对过经文了，再翻要翻烂了。\n");
        return 1;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢！\n");
        return 1;
    }
    while (strwidth(word)!=2)
    {
        word=jing_wen[random(sizeof(jing_wen))];
    }
    while (strwidth(word2)!=2||word2==word)
    {
        word2=jing_wen[random(sizeof(jing_wen))];
    }
    me->set_temp("emnewbiejob/jingwen/word",word);
    me->set_temp("emnewbiejob/jingwen/word2",word2);
    me->set_temp("emnewbiejob/jingwen/hedui",1);
    afterjingwen=replace_string(jingwen,word,word2,1);
    message_vision(HIY"$N开始认真核对经文。\n"NOR,me);
    tell_object(me,"原文：\n"+jingwen+"\n\n");
    tell_object(me,"抄本：\n"+afterjingwen+"\n");
    tell_object(me,"抄错了哪个字，快把它改正(gai)吧。\n");
    return 1;
}

int do_bu(string arg)
{
    object me=this_player();
    string word1,word2;
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢！\n");
        return 1;
    }
    if (!me->query_temp("emnewbiejob/jingwen/hedui"))
    {
        tell_object(me,"连核对都没核对？你想蒙混过关吗？。\n");
        return 1;
    }
    if (me->query_temp("emnewbiejob/jingwen/fail"))
    {
        tell_object(me,"既然弄成这样，快回去承认错误吧。\n");
        return 1;
    }
    if (!arg)
    {
        tell_object(me,"你要补上经文上缺的什么字？\n");
        return 1;
    }
    if (sscanf(arg, "%s to %s", word1,word2) != 2)
    {
        tell_object(me,"请用格式gai <错字> to <新字>。\n");
        return 1;
    }
    message_vision(HIY"$N开始修改经文，把文中所有"+word1+"都换成了"+word2+"。\n"NOR,me);
    if (wizardp(me))
    {
        tell_object(me,"你要改正的字是："+me->query_temp("emnewbiejob/jingwen/word2")+"\n"
        +"你输入的是："+word1+"\n"
        +"正确的字是："+me->query_temp("emnewbiejob/jingwen/word")+"\n"
        +"你输入的是："+word2+"\n");
    }
    if (word1!=me->query_temp("emnewbiejob/jingwen/word2")||word2!=me->query_temp("emnewbiejob/jingwen/word"))
    {
        
        me->set_temp("emnewbiejob/jingwen/fail",1);
        tell_object(me,"经文被你改的面目全非了。\n");
        return 1;
    }
    else
    {
        message_vision("$N看着修改好的经文，吹干墨迹，好不得意。\n",me);
        if (random(3)&& me->query_skill("mahayana",1)< 160)
        {
            me->improve_skill("mahayana",((int)me->query_skill("mahayana",1)/5+me->query("int")*7/3+random(me->query("kar"))*2));
            tell_object(me,HIW"回忆修改经文的过程，你的大乘涅槃功有了些许进步。\n"NOR);
        }
        me->set_temp("emnewbiejob/jingwen/finish",1);
        return 1;
    }
}