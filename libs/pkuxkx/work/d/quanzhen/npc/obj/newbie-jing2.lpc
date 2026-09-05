// zine qz newbie job
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("道德经", ({"daode jing",}));
        set_weight(200);
        set("is_jing","qz_newbie");
        set("unit", "本");
        set("long","这是一本誊抄的道德经文。\n");
        set("material", "paper");
}

void init()
{
    add_action("do_hedui","zhao");
    add_action("do_bu","gai");
}

int do_hedui()
{
    object me=this_player();
    string *color=({HIR,RED,HIB,BLU,HIY,YEL,HIM,MAG,HIC,CYN,HIW,WHT,HBRED,HBWHT,HBBLU,HBYEL,HBGRN,HBCYN,HBMAG});
    string jingwen="夫兵者，不祥之器，物或恶之，故\n有道者不处。君子居则贵左，用兵\n则贵右。兵者不祥之器，非君子之\n器，不得已而用之，恬淡为上。胜\n而不美，而美之者，是乐杀人。夫\n乐杀人者，则不可得志于天下矣。\n吉事尚左，凶事尚右。偏将军居左，\n上将军居右，言以丧礼处之。杀人\n之众，以悲哀泣之，战胜以丧礼处\n之。\n";
    string * jing_wen=({"夫","兵","者","不","祥","之","器","物","或","恶","之","故","有","道","者","不","处","君","子","居","则","贵","左","用","兵","则","贵","右","兵","者","不","祥","之","器","非","君","子","之","器","不","得","已","而","用","之","恬","淡","为","上","胜","而","不","美","而","美","之","者","是","杀","人","夫","杀","人","者","则","不","可","得","志","于","天","下","矣","吉","事","尚","左","凶","事","尚","右","偏","将","军","居","左","上","将","军","居","右","言","以","丧","礼","处","之","杀","人","之","众","以","悲","哀","泣","之","战","胜","以","丧","礼","处","之",});
    string word,word2;
    string jing_color,font_color;
    string afterjingwen;
    if (me->query_temp("qznewbiejob/task3/type")!="核对")
    {
        tell_object(me,"你想干嘛？\n");
        return 1;
    }
    if (me->query_temp("qznewbiejob/task3/hedui"))
    {
        tell_object(me,"你刚刚核对过经文了，再翻书就要烂了。\n");
        return 1;
    }
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢！\n");
        return 1;
    }
    jing_color=color[random(sizeof(color))];
    font_color=color[random(sizeof(color))];
    while (jing_color==font_color)
    {
        font_color=color[random(sizeof(color))];
    }
    word=jing_wen[random(sizeof(jing_wen))];
    jingwen=jing_color+jingwen+NOR;
    word2=font_color+word+NOR+jing_color;
    me->set_temp("qznewbiejob/task3/word",word);
    me->set_temp("qznewbiejob/task3/hedui",1);
    afterjingwen=replace_string(jingwen,word,word2,1);
    message_vision(HIY"$N开始认真核对经文。\n"NOR,me);
    tell_object(me,"原文：\n"+jingwen+"\n\n");
    tell_object(me,"抄本：\n"+afterjingwen+NOR+"\n");
    tell_object(me,"哪个字写模糊了，快把它改(gai)掉吧。\n");
    return 1;
}

int do_bu(string arg)
{
    object me=this_player();
    
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢！\n");
        return 1;
    }
    if (!me->query_temp("qznewbiejob/task3/hedui"))
    {
        tell_object(me,"连看都没看，你想蒙混过关吗？。\n");
        return 1;
    }
    if (!arg)
    {
        tell_object(me,"你觉得哪个字需要改正？\n");
        return 1;
    }
    if (arg!=me->query_temp("qznewbiejob/task3/word"))
    {
        tell_object(me,"你好像弄错了，越改越糟，这本书不能要了。\n");
        destruct(this_object());
        return 1;
    }
    tell_object(me,"你一眼就发现了错误所在，太明显了，去把"+this_object()->query("name")+"交给道童吧。\n");
    me->set_temp("qznewbiejob/task3/complete",1);
    return 1;
}