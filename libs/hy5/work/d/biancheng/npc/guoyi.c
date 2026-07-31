#include <ansi.h>
#include <command.h> 
//inherit "/d/taiping/npc/smart_npc"; 
inherit NPC;
void create()
{ 
        set_name("郭易",({"guo yi","guo"}));
        set("title","躺在棺材里的");
        set("long", "
一个白发苍苍，枯干矮小的白衣老人，他的身体很衰弱，仿佛随时都会被风吹走，
又仿佛根本就是被风吹来的。他出现的地方，就是一座坟。他的人就站在棺材里。\n");
        set("age",67);
        set("combat_exp", 6500000);
        set("attitude", "friendly");     
        set("force_factor",100); 
        set("inquiry", ([
                "血鹦鹉" : "血鹦鹉的愿望是一定要付出代价的。\n\n",
                "parrot" : "血鹦鹉的愿望是一定要付出代价的。\n\n",
                "*":    "记不清楚了。。。。\n",
        ]));
        set("cor", 40);
        set("cps", 40);
        set("agi",40);
        set("fle",100);
        
        set_skill("unarmed",200);
        set_skill("dodge",150);
        set_skill("parry",160);
        set_skill("force",180);
        set_skill("move",200); 
        
        set("resistance/gin",10);
        set("resistance/kee",50);
        set("resistance/sen",10);
        
        set("chat_chance_combat", 100);
/*        set("chat_msg_combat", ({
                (: auto_smart_fight(60) :),    
        }) );
        
        auto_npc_setup("xuebin",250,180,0,"/obj/weapon/","fighter_w","taiji",2);
*/
        setup();
        carry_object(__DIR__"obj/whitecloth")->wear();
} 
void init() {
        
        object ob;
   ::init();
        add_action("do_answer","answer");
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}  
void greeting(object ob) {
        
        if( !ob || environment(ob) != environment() ) return;
//      if (query("tell_story")) return;
        call_out("bird_story_1",1,ob); 
} 
int bird_story_1(object who)
{
        if (! who->query_temp("parrot/listen_to_story")) {
                tell_object(who,HIR"\n郭易看了你一眼说：“我已是命不久矣，你我有缘相逢在这荒郊野地，你是否愿意听
我讲一个故事，一个属于另外一个世界的故事？”\n");
                tell_object(who,HIY"（ａｎｓｗｅｒ　ｙｅｓ／ｎｏ） \n"NOR);
                who->set_temp("answer_person",1);
        }
        return 1;
} 
int do_answer(string arg)
{
        object skinmask,who;
        who=this_player();
        if(!who->query_temp("answer_person")) return 0;
        if(arg=="yes")
        {
                message_vision(CYN"$N点了点头。\n"NOR,who);
                call_out("event1",1,who,0);
                set("tell_story",1);
                who->delete_temp("answer_person");
// 暂时取消永久mark,为以后重新解谜留余地
//                who->set("parrot/listen_to_story",1);
                who->set_temp("parrot/listen_to_story",1);
                return 1;       
        }
        if(arg=="no"){
                message_vision(CYN"$N无动于衷地摇了摇头。\n"NOR,who);
           message_vision(YEL"郭易叹了口气，不再言语。\n"NOR,who);
                who->delete_temp("answer_person");
                who->set_temp("parrot/listen_to_story",1);
                return 1;
        }
        
        return 0;
}  
string *event1_msg=     ({
        WHT"郭易道：“我要讲的，是血鹦鹉的故事。”\n",
        
        CYN"  “十万神魔十万滴魔血，才化成这只血鹦鹉。”"+WHT"老人的声音神秘而遥远，慢慢的
接着道："+CYN"“那一天，东方的诸魔和西方诸魔，为了庆贺魔王的寿诞，聚会到‘奇浓
嘉嘉普’来。”\n"NOR, 
        CYN"  “奇浓嘉嘉普就是诸魔的世界，没有头上的青天，也没有脚下的地方，只有风和
雾，寒冰和火焰。”\n"NOR, 
        CYN"  “那天是魔王十万岁的寿诞，九天十地间的诸魔都到齐了，都刺破中指滴出了一
滴魔血，化成了这只血鹦鹉，作他们的贺礼。”\n"NOR,
        
        CYN"  “这只血鹦鹉每隔七年都要降临到人间一次，也带来三个愿望。你只要能看见它，
它就会让你得到三个愿望。不管什么样的愿望，都能够实现，"+HIR"绝对能实现。”\n"NOR, 
        CYN"  “七年前有个人看见过它，而且实现了三个愿望。”\n"NOR, 
        WHT"  郭易眼睛充满了兴奋，又充满恐怖，绝不像是在说谎。\n"NOR, 
        CYN"  “这个人就是我的兄弟，富贵王王府的总管郭繁。”\n"NOR, 
        CYN"  “七年前，富甲天南的富贵王，他的宝库中珍宝如山，却在一夜间竟都神秘失踪
了。郭繁本来是富贵王的连襟，又是富贵王的亲信，可是这件事发生后，他也自知
脱不了干系。“\n"NOR, 
        CYN"  “他本来是想用死来表示清白的，谁知道就在他已将气绝的时候，就遇见了血鹦
鹉。所以他第一个愿望，就是要把那批失窃的珠宝找回来。”\n"NOR, 
        CYN"  “当时已是深夜，他虽然也曾听过血鹦鹉的传说，却还是半信半疑，只不过抱着
万一的希望而已，想不到……第二天早上真的有人将那批珠宝送回来了。送回来的
是个衣冠楚楚的中年人。。。”\n"NOR, 
        WHT"  郭易目中忽然又露出了恐惧之色，连说话的声音都开始发抖。\n"NOR, 
        CYN"  “他说他就是阴曹地府中的判官。他说他手下追魂索命的鬼卒，昨夜拘错了一个
人的魂魄，说死的本来是另一个人，却拘走了郭繁的独生子郭兰人。所以他就特地
去找到这批珠宝，作为补偿。说完了这句话，他的人就忽然不见了。”\n"NOR, 
        CYN"  “那位判官刚走了不久，就有人将郭兰人的尸身抬了回来。他是失足落水被淹死
的，死得很可怖，也很可怕。”\n"NOR, 
        CYN"  “郭繁的第二个愿望，当然是希望能救活自己的儿子。”\n"NOR, 
        CYN"  “那天晚上狂风暴雨。那时郭兰人的棺木还停在灵堂里，王爷也陪着郭总管在旁
边的花厅中等着，甚至王妃都在。他们也想看看这件不可思议的事，是不是真的会
发生。\n"NOR, 
        CYN"  “夜深，风急。灵堂中虽然传来一阵敲打的声音，敲打棺材的声音。接着，就有
人在棺材中大喊，要人打开棺材，放他出来。凄厉的呼声，赫然正是郭繁儿子的声
音，他们都听得出。“\n"NOR, 
        CYN"  “王爷和王妃都几乎快吓晕了。郭繁又准备冲出去救他的儿子，王爷和王妃都拉
住他，求他不要去。这件事实在太神秘，太可怕。郭繁不肯。王爷最宠爱的一个妃
子就忽然拔出把短刀，一刀刺死了他。就在他气绝的时候，灵堂中的呼喊敲打声也
立刻停止了。甚至连风雨都渐渐停止。\n"NOR, 
        CYN"  “郭繁一死，他的愿望也就消失了，他的儿子就不能复生，那批珠宝当然也跟着
再次神秘消失。”\n"NOR, 
        CYN"  “郭繁死了，他的妻子也死了，杀他的那位王妃，不到三天，就发了痴，宝库的
护卫们，也全都自杀谢罪，王爷既心痛他的爱妃又心疼他的珠宝，竟变了个白痴。”\n"NOR, 
        CYN"  “这个就是血鹦鹉的故事。也许这就是魔王要他的血鹦鹉每隔七年来一次人间的
原因。因为他知道意外的愿望所带给人的，有时并不是幸运，而是灾祸。”\n"NOR,
});  
void event1(object me, int count)
{
        if (environment(me)!=environment(this_object()) || this_object()->is_fighting()) {
                delete("tell_story");
                return;
        }
        tell_object(me,event1_msg[count]+"\n");
        if(++count==sizeof(event1_msg))
        {
                tell_object(me,RED"   郭易深深地看了你一眼说：血鹦鹉的愿望是一定要付出代价的。\n\n"NOR,this_object(),me);
                delete("tell_story");
                return;
        }
        else call_out("event1",1,me,count);
        return ;
}        
