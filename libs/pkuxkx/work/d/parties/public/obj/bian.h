#include <ansi.h>

void init()
{
    add_action("do_ke","write");
    add_action("do_ke","ke");
    call_out("price_down",1);
}

string re_color(string color)
{
    color = replace_string(color,"HIR",HIR);
    color = replace_string(color,"HIY",HIY);
    color = replace_string(color,"HIB",HIB);
    color = replace_string(color,"HIG",HIG);
    color = replace_string(color,"HIW",HIW);
    color = replace_string(color,"HIM",HIM);
    color = replace_string(color,"HIC",HIC);
    color = replace_string(color,"HBRED",HBRED);
    color = replace_string(color,"HBYEL",HBYEL);
    color = replace_string(color,"HBBLU",HBBLU);
    color = replace_string(color,"HBGRN",HBGRN);
    color = replace_string(color,"HBWHT",HBWHT);
    color = replace_string(color,"HBMAG",HBMAG);
    color = replace_string(color,"HBCYN",HBCYN);
    return color;
}

int input_color(string color,string arg,object me)
{
    string *colors=({HIR,HIY,HIB,HIG,HIW,HIM,HIC});
    color=re_color(color);
    if (member_array(color,colors)<0)
    {
        if (this_object()->query("try_color")<3)
        {
            tell_object(me,"请在"+HIR+"HIR"+NOR+","+HIY+"HIY"+NOR+","+HIB+"HIB"+NOR+","+HIG+"HIG"+NOR+","+HIW+"HIW"+NOR+","+HIM+"HIM"+NOR+","+HIC+"HIC"+NOR+"中选择题字的颜色。\n");
            input_to( (: input_color :),arg,me);
            this_object()->add("try_color",1);
            return 1;
        }
        else
        {
            message_vision("由于$N乱涂乱画，"+this_object()->query("name")+"被损毁了！",me);
            destruct(this_object());
            return 1;
        }
    }
    else
    {
        message_vision("$N在"+this_object()->query("name")+"上挥毫写下了“"+color+arg+NOR+"”这几个大字！\n",me);
        this_object()->set("input_word",color+arg+NOR);
        this_object()->set("long",this_object()->query("long")+"上面刻着"+this_object()->query("input_word")+"几个字\n");
        return 1;
    }
}
int input_color2(string color,string arg,object me)
{
    string bian4,*colors=({HBRED,HBGRN,HBBLU,HBMAG,HBWHT,HBCYN,HBYEL});
    color=re_color(color);
    if (member_array(color,colors)<0)
    {
        if (this_object()->query("try_color")<3)
        {
            tell_object(me,"请在"+HBRED+"HBRED"+NOR+","+HBGRN+"HBGRN"+NOR+","+HBBLU+"HBBLU"+NOR+","+HBMAG+"HBMAG"+NOR+","+HBWHT+"HBWHT"+NOR+","+HBCYN+"HBCYN"+NOR+","+HBYEL+"HBYEL"+NOR+"中选择题字的颜色。\n");
            input_to( (: input_color :),arg,me);
            this_object()->add("try_color",1);
            return 1;
        }
        else
        {
            message_vision("由于$N乱涂乱画，"+this_object()->query("name")+"被损毁了！",me);
            destruct(this_object());
            return 1;
        }
    }
    else
    {
        message_vision("$N在"+this_object()->query("name")+"上挥毫写下了“"+color+arg+NOR+"”这几个大字！\n",me);
        if (this_object()->query("bian_lv")>3)
        {
            bian4="\n";
            bian4+="╔════╗\n";
            bian4+=(sprintf("║%-8s║\n",BLINK+color+arg+NOR));
            bian4+="╚════╝\n";
            this_object()->set("input_word",bian4);
            this_object()->set("long",this_object()->query("long")+"上面刻着"+this_object()->query("input_word")+"几个字\n");
            return 1;
        }
        this_object()->set("input_word",color+arg+NOR);
        this_object()->set("long",this_object()->query("long")+"上面刻着"+this_object()->query("input_word")+"几个字\n");
        return 1;
    }
}
int input_word(string arg,object me)
{
    if (strwidth(arg)>30)
    {
        write("你不觉得自己提的字太长了点？要多大的匾额才写得下？\n");
        return 1;
    }
    else if (this_object()->query("bian_lv")>3&&strwidth(arg)!=8)
    {
        write("巫师题字，用四个字的成语才能显得自己很有素质。\n");
        return 1;
    }
    else if (this_object()->query("bian_lv")>2)
    {
        tell_object(me,"请在"+HBRED+"HBRED"+NOR+","+HBGRN+"HBGRN"+NOR+","+HBBLU+"HBBLU"+NOR+","+HBMAG+"HBMAG"+NOR+","+HBWHT+"HBWHT"+NOR+","+HBCYN+"HBCYN"+NOR+","+HBYEL+"HBYEL"+NOR+"中选择题字的颜色。\n");
        input_to( (: input_color2 :),arg,me);
        return 1;
    }
    else if (this_object()->query("bian_lv")>1)
    {
        tell_object(me,"请在"+HIR+"HIR"+NOR+","+HIY+"HIY"+NOR+","+HIB+"HIB"+NOR+","+HIG+"HIG"+NOR+","+HIW+"HIW"+NOR+","+HIM+"HIM"+NOR+","+HIC+"HIC"+NOR+"中选择题字的颜色。\n");
        input_to( (: input_color :),arg,me);
        return 1;
    }
    else
    {
        message_vision("$N在"+this_object()->query("name")+"上挥毫写下了“"+arg+"”这几个大字！\n",me);
        this_object()->set("input_word",arg);
        this_object()->set("long",this_object()->query("long")+"上面刻着"+this_object()->query("input_word")+"几个字\n");
        return 1;
    }
}
int bian(object me)
{
    tell_object(me,"请题字：\n");
    input_to( (: input_word :), me);
    return 1;
}

int price_down()
{
    this_object()->set("value",0);
    return 1;
}

int do_ke()
{
    object me=this_player();
    string name;
    if (me->is_busy()||me->is_fighting())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (this_object()->query("input_word"))
    {
        tell_object(me,"这块"+this_object()->query("name")+"上已经被题字了！\n");
        return 1;
    }
    if (me->query_skill("literate",1)<300*(int)this_object()->query("bian_lv"))
    {
        tell_object(me,"你的学问这么差，在"+this_object()->query("name")+"上题字，不怕别人笑话吗？\n");
        return 1;
    }
    if (this_object()->query("bian_lv")>2&&!me->query("guider"))
    {
        if (this_object()->query("bian_lv")>3&&!wizardp(me))
        {
            tell_object(me,"只有巫师才能"+this_object()->query("name")+"上题字！\n");
            return 1;
        }
        tell_object(me,"只有新手导师以上级别才可以在"+this_object()->query("name")+"上题字。\n");
        return 1;
    }
    if (this_object()->query("bian_lv")<=4)
    {
        bian(me);
    }
    else
    {
        tell_object(me,this_object()->query("name")+"出错！\n");
    }
    return 1;
}




