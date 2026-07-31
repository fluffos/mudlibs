#include <ansi.h>
inherit NPC;

void create()
{
        set_name("孙剑",({"sun jian","sun"}));
//      set("title",HIY"菊花园"NOR);
        set("title",HIR"性烈如火"NOR);
        set("long","
孙剑相貌堂堂，浓眉大眼，身上的皮肤已晒成了紫铜色，他眼睛瞪着你的时候你绝不会
去看别人，也没法子再去看别人。他的名字本来是孙剑如， 但他觉得这“如” 字有点
女人气，所以就自己将“如”字去掉。他不愿自己身上沽着一星一点女人气。他也和他
父亲一样慷慨好义，就算将自己身上的衣服脱下来给别人穿也在所不惜。\n");
        
        set("gender","男性");
        set("group","juyuan");
        
        set("age",32);          
        set("int",52);
        set("cor",30);
        set("cps",20);
        set("str",45);
        
        set("neili",1500);
        set("max_neili",1500);
        set("force_factor",120);
        set("max_atman",500);
        set("atman",500);
        set("max_mana",500);
        set("mana",500);
        set("combat_exp",8500000);  
        set("attitude", "friendly");
        
        set("resistance/kee",30);
        set("resistance/gin",30);
        set("resistance/sen",30);
        
        set("inquiry", ([
                "老伯": "老伯就是我父亲。\n",
                "老伯": "老伯就是我父亲。\n",   
           ]));
        
//      set("death_msg",CYN"\n$N狂笑着道“你们全都去死吧，死光了最好。”\n"NOR);        
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([ 
        ]) );           

        set("chat_chance",1);
        set("chat_msg",({
                "\n孙剑也许是站的太久了，神情显得有点不耐烦。\n",
        }) );                   
        
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
 
} 
void init() {
        ::init();
        add_action("do_answer","answer");
}  
int do_answer(string arg)
{
        switch (arg) {
                case "律香川":
                case "lv xiangchun":    command("say 好，你去吧！\n");
                                        this_player()->set_temp("zangbei/see_lv",1);
                                        break;
                case "老伯":
                case "孙玉伯":          command("say 我父亲现在正忙，改日再来吧。\n");
                                        break;
                case "sun jian":
                case "孙剑":            if (this_player()->query("gender")=="女性" && this_player()->query("age")<40
                                                && this_player()->query("age")>16)
                                                message_vision(CYN"$N赫赫一笑：“现在不是时候，等我把这儿的事办完了吧。”\n"NOR,this_object());
                                        else message_vision(CYN"$N大笑道，你我素昧平生，找我何事！\n"NOR,this_object());
                                           break;
                case "陆漫天":
                case "lu mantian":
                case "韩棠":
                case "han tang":        command("say 他现在正忙，改日再来吧。\n");
                                        break;
                default:                command("say 这里没有这个人。\n");
        }
        return 1;               
}     
