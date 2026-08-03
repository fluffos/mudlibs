// flower.h 各种花
// modified by amy&&jingxue for xycq 2004/4/15

#include <ansi.h>
#include <dbase.h>
#include <armor.h>

inherit COMBINED_ITEM;

string *allid = ({
        "red rose",                    //0
        "white rose",                  //1
        "hyacinth",                    //2
        "valentine",                   //3
        "lavender",                //4
        "moth orchid",          //5
        "flame lily",                  //6
        "calla",                       //7
        "sky stars",            //8
        "snapdragon",              //9
        "bird of paradise",        //10
        "forget-me-not",                //11
        "carnation",            //12
        "lilac",                       //13
        "tulip",                //14
});
string *allname = ({
        HIR"红玫瑰"NOR,         //0
        HIW"白玫瑰"NOR,         //1
        HIM"粉风信子"NOR,               //2
        HIG"情人草"NOR,         //3
        MAG"熏衣草"NOR,             //4
       HIC"蝴蝶兰"NOR,          //5
        HIR"火百合"NOR,         //6
        HIG"马蹄莲"NOR,         //7
        HIW"满天星"NOR,         //8
        HIM"粉金鱼草"NOR,              //9
        HIC"天堂鸟"NOR,         //10
        HIB"勿忘我"NOR,         //11
        HIY"黄康乃馨"NOR,               //12
        HIM"紫丁香"NOR,         //13
        MAG"紫郁金香"NOR,               //14
});
string *alllong = ({
        "娇色欲滴的红玫瑰，象征着热恋。",                      //0
        "晶莹可爱的白玫瑰，象征着纯洁与高贵。",         //1
        "清丽芳香的粉色风信子，象征着倾慕与浪漫。",            //2
       "蓬松轻盈，状如云雾的情人草，象征着爱意永恒。",    //3
       "紫色浪漫，花香柔和的熏衣草，象征着等待爱情。",    //4
        "娇艳小巧，美丽别致的蝴蝶兰，象征着我爱你。",      //5
        "明艳灿烂的火红色百合，象征着热烈的爱。",       //6
       "纯洁甘美，清秀挺拔的马蹄莲，象征着永结同心。",   //7
        "楚楚动人，温柔多情的满天星；象征着纯洁的心。",   //8
       "活泼开朗的粉色金鱼草，象征着花好月圆。",        //9
        "气质高贵，色彩瑰丽的天堂鸟，象征着热恋中的情侣。",     //10
       "花姿不凋，花色不褪的勿忘我；象征着眷恋不舍。",   //11
        "雍容富丽的黄色康乃馨，象征着长久的友谊。",            //12
        "清新淡雅，惹人喜爱的紫丁香，象征着初恋与羞涩。",       //13
        "典雅妩媚的紫色郁金香，象征着永不磨灭的爱情。", //14
});

void create()
{
        int i;
        seteuid(getuid());
        i = FLO;
        if (i > sizeof(allid)-1)
                i = sizeof(allid)-1;
        if (i > sizeof(allname)-1)
                i = sizeof(allname)-1;
        if (i > sizeof(alllong)-1)
                i = sizeof(alllong)-1;
        set_name(allname[i], ({allid[i], "flower"}));
        set_weight(100);
        set("long",alllong[i]);
        set("unit", "束");
        set("base_unit","朵");
        set_amount(1);
        set("base_value", 5000);
        set("value", 5000);
        set("armor_prop/armor", 1);
        set("armor_prop/personality", 10);
        set("can_song",1);      //这个标记为可以送的花
        setup();
}

int init ()
{
        add_action ("do_smell", "smell");
        add_action ("do_smell", "wen");
        return 1;
}

int do_smell (string arg)
{
        object me = this_player();
        object flower = this_object();
        string name = flower->query("name");
        string msg;

        if (arg != "flower" && arg != flower->query("id"))
                return 0;

        switch (random(9))
        {
        case 0:
                { msg = "$N闻了闻"+name+"，想起当年那好熟悉的清香味。\n"; break; }
        case 1:
                { msg = "$N低头嗅了一下"+name+"，扭过头去打了一个香香喷。\n"; break; }
        case 2:
                { msg = "$N捧着"+name+"一嗅，泪水滴在花瓣上。\n"; break; }
        case 3:
                { msg = "$N将一朵"+name+"放在鼻子下，想啊想啊……\n"; break; }
        case 4:
                { msg = "$N捧着"+name+"闻了一下：唉，今夕是何夕。\n"; break; }
        case 5:
                { msg = "$N将"+name+"捧起闻了闻，又惦记起昨天的故人。\n"; break; }
        case 6:
                { msg = "$N不禁将"+name+"轻轻一闻，思绪绵绵如窗外的细雨。\n"; break; }
        case 7:
                { msg = "$N闻了闻"+name+"，痴痴地听着窗外飘过的小雨。\n"; break; }
        case 8:
                { msg = "$N将"+name+"轻轻一嗅，不禁念道：明日天涯何处……\n"; break; }
        }
        message_vision (msg,me);
        return 1;
}

varargs void message_vision(string msg, object me, object you)
{
        string my_gender, your_gender, my_name, your_name;
        string str1, str2, str3;
        object *list = all_inventory(environment(me));
        int i = sizeof (list);

        my_name= me->name();
        my_gender = me->query("gender");
        str1 = replace_string(msg,  "$P", gender_self(my_gender));
        str1 = replace_string(str1, "$N", gender_self(my_gender));
        str3 = replace_string(msg,  "$P", my_name);
        str3 = replace_string(str3, "$N", my_name);
        if (you)
        {
                your_name= you->name();
                your_gender= you->query("gender");
                str2 = replace_string(msg,  "$P", gender_pronoun(my_gender));
                str2 = replace_string(str2, "$p", gender_self(your_gender));
                str2 = replace_string(str2, "$N", my_name);
                str2 = replace_string(str2, "$n", gender_self(your_gender));
                str1 = replace_string(str1, "$p", gender_pronoun(your_gender));
                str1 = replace_string(str1, "$n", your_name);
                str3 = replace_string(str3, "$p", your_name);
                str3 = replace_string(str3, "$n", your_name);
        }
        while (i--)
        {
                object ob = list[i];
                if (! ob->is_character())
                        continue;
                else if (ob == me)
                        tell_object(ob,str1);
                else if (ob == you)
                        tell_object (ob,str2);
                else if (! ob->query("env/brief_message"))
                        tell_object (ob,str3);
        }
}

