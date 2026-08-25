#include <ansi.h>
#include <mudlib.h>
#include <move.h>
inherit LIVING;
string * fooddrink = ({ 
"grape","peach","smssj","youji","hmgua","flin","strawberry","youzi",
"hstibang","yzfz","pumpkin","qzluyu","cphen","baoyu","yeqing","zongzi",
"wxhuotui","longxia","ybshrimp","wxmeat","gulurou","chunjuan","guozili",
"xhdoufu","dazhaxie","qzyy","tangyuan","shrimp","yzrice","cpeanut","mango",
"jbeef","jiangya","shizi","mldoufu","tanghulu","xfish","xihufish","pigleg",
"shaoe","zcrab","lbgao","bqhen","shaorou","yrpaomo","nbaiye","gqmixian",
"ctianluo","xrjiao","baozi","bzshrimp","glmifen","mugua","niangao",
"drunkshrimp","xianggua","ruzhu","mhtao","lizhi","larou","xing","yangtao",
"lizi","apple","bolo","jchen","ymbing","pear","dsbao","hsliyu","yxpeanut",
"sjkourou","banana","bjling","kaoji","lbzhou","kaoya","yuchi","orange",
"nrjiaozi","doufu","mooncake","jmantou","huntun","hsxz","jlxr","zpaigu",
"wxpeanut","xigua","nverhong","mgsoup","lzgeng","ynpuer","zhuyeqing",
"maojian","rscha","ldsha","rsdunji","fenjiu","hhdaqu","sdzi","hzlj",
"hsmj","jztang","coke","dhcha","huadiao","maotai","lsyw","gljiu","yzcha",
"qingkejiu","hzcha","bzkaocha","guihuajiu","putaojiu","jnchun","molihc",
"tgy","longjingcha","sssoup","ssjp","bjdw","mijiu","smtang","zscha",
"txlc","blchun","yanwo","qdbeer","ytdoufu","wyyc","sxhj","pepsi",
});

void setup()
{
        set_name("xiao si","小厮");
        set_in_room_desc("「"+YEL+"负责端盘送菜"+NOR+"」小厮(xiao si)");
        set_long("一个里里外外忙个不停的小厮。\n"+
        "找不到吃的吗？叫他送上来好了。(ask xiao si about food)。\n");
        set_gender(1);
        set_age(14);
        add_id("waiter");
        set_sg_rongmao(30);
        add_question("here","here");
        add_question("food","food");
        add_question("name","name");
        add_ask_str("food","$N对$T招了招手：$R，有什么吃喝的快拿上来吧！\n");
}

void ask_food(object usr)
{
        string p_obj;
      object ob;
        p_obj=fooddrink[random(sizeof(fooddrink))];
        ob=OBJ_D->clone_obj(p_obj);
        ob->move(usr);
        this_object()->targetted_action(
                "$N点了点头，对$T说道：好吧，您稍等。\n",usr);
        usr->responda("pat xiao si");
        return;
}
mixed special_answer(object ob, string str)
{
        object player;
        player = this_body();
        switch(str)
        {
        case "food":
                ask_food(player);
                return;
        case "name":
                this_object()->targetted_action("$N嘻嘻笑着道："+
"偏不告诉你，我只是临时来帮忙的。\n",ob);
                return;
        case "here":
                this_object()->targetted_action("$N说道：这里就是宴会厅呀
，"+
"这么多人呀，我都快忙死了。\n",ob);
                return;
        default:
                return;
        }
}

