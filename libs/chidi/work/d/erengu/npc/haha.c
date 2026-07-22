#include <ansi.h>
inherit SMART_NPC;
int give_mission(); 
void create()
{
        set_name(HIY"替补"NOR,({"guardian"}));
        set("nickname","笑里藏刀");
        set("long", "这人矮矮胖胖，笑脸圆圆，活脱是个和气生财的酒店掌柜。。\n");
        set("age",45);
        set("attitude", "friendly");
        set("combat_exp", 4000000);
                        
        set("max_mana", 1000);
        set("mana", 1000);
        set("max_force",1500);
        set("force",1500);
                
        set("resistance/gin",30);
        set("resistance/kee",30);
        set("resistance/sen",30);
        
        set("inquiry", ([
                "胖子" : (: give_mission :),
                "原料" : (: give_mission :),
                "豆腐胖子" : (: give_mission :),
                "欧阳豆腐铺" : (: give_mission :),
                "欧阳丁" : (: give_mission :),
                "欧阳当" : (: give_mission :),
                "ouyang ding" : (: give_mission :),
                "ouyang dang" : (: give_mission :),
                "小烟" : "村里的小孩，昨天还在这儿玩来着。",
                 "哈哈酒楼": "哈哈酒楼当然是我开的喽。",
                 "娇娇客栈": "娇娇客栈是屠娇娇的女儿开的。",
                "屠小娇": "娇娇客栈是屠娇娇的女儿屠小娇开的。",
                "恶人谷": "这恶人谷三字早已没人提了。",
                "燕南天": "燕大侠的名字谁人不晓，村里还有他的铁像呢。",
                "万春流": "万神医有起死回生之能。",
                "杜老爹": "杜老爹专打暗器，听说要打他的暗器，还得学好听风辨器才行。",
                "轩辕三光": "他输的只剩下那间当铺了。",
                "山雀舌": "知道我还要你帮忙？",
                   "烤山猪肉": "知道我还要你帮忙？",
                "沙虫肝": "知道我还要你帮忙？",
                "熊掌": "知道我还要你帮忙？",
        ])); 
                
        set("chat_chance", 1);
        set("chat_msg", ({
                "圆脸胖子笑道：“兄台远来，想必饿了，快请用些酒莱，再谈正事。”\n",
                "哈哈儿皮笑肉不笑地道，“哈哈，哈哈，我哈，你哈？”\n", 
                "哈哈儿愁眉苦脸地说，最近客人少了好多，都是那两个该死的豆腐胖子。”\n",                         
        }) );
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: auto_smart_fight() :),    
        }) );
        
        CHAR_D->setup_char(this_object());
        auto_npc_setup("guardian",200,170,0,"/d/eren2/npc/obj/","fighter_u","all");
        set_name("哈哈儿",({"haha er"}));
        set("force_factor",60);
        setup();
        carry_object("/obj/armor/cloth")->wear();
        
} 
void init()
{
        object ob; 
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) 
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
} 
void greeting(object ob)
{   
        if( !interactive(ob) || environment(ob) != environment() ){
                return;
        }
        message_vision("$N笑嘻嘻走了过来，拱手笑道：“兄台远来辛苦了。”\n", this_object() );
           return;
}  
int give_mission() {
        object me,ob;
        
        ob=this_object();
        me=this_player();
        
        if (me->query("marks/恶人窟",1)) {
                message_vision("哈哈儿皮笑肉不笑地拍拍$n：“好说，好说，今天我作东。\n",ob,me);
                return 1;
        }
        
        if (me->query_temp("eren/haha_1")||me->query_temp("eren/haha_2")
                ||me->query_temp("eren/haha_3")) {
                tell_object(me,"哈哈儿凑在你耳边说：“怎么样？到手了哈？“\n");
                return 1;
        }
        message_vision(CYN"$N叹了口气说:生意不好做哈，自古只听说过豆腐西施，没想到豆腐胖子
也这么厉害哈，我这儿顾客越来越少了。\n"NOR,ob);
        tell_object(me,"哈哈儿小声说，客官是否能帮小的哈一个小忙？\n"); 
        tell_object(me,"哈哈儿说：也就是搞些原料，客人想吃烤山猪肉你是否能弄到哈？\n\n");       
        me->set_temp("eren/haha_1",1);
        return 1;
} 
int accept_object(object who, object ob)
{       
        if (ob->query("name")=="烤山猪肉" && who->query_temp("eren/haha_1"))
        {
                ccommand("spank "+who->query("id"));
                if (!who->query("eren/haha_1")) {
                        who->add("potential",100);
                        who->add("combat_exp",1000);
                        who->set("eren/haha_1",1);
                        tell_object(who,WHT"你被奖励了！一百潜能，一千经验值！\n"NOR);
                }
                message_vision("$N说:再替我搞些山雀舌吧。\n",this_object());
                who->set_temp("eren/haha_2",1);
                return 1;
        }
   if (ob->query("name")==HIG"山雀舌"NOR && who->query_temp("eren/haha_2")
                && who->query("eren/haha_1"))
        {
                ccommand("spank "+who->query("id"));
                if (!who->query("eren/haha_2")) {
                        who->add("potential",100);
                        who->add("combat_exp",1000);
                        who->set("eren/haha_2",1);
                        tell_object(who,WHT"你被奖励了！一百潜能，一千经验值！\n"NOR);
                }
                message_vision("$N说:再替我搞些"+YEL"熊掌"NOR+"吧。\n",this_object());
                who->set_temp("eren/haha_3",1);
                return 1;
        }
        if (ob->query("name")==YEL"熊掌"NOR && who->query_temp("eren/haha_3")
                && who->query("eren/haha_1") && who->query("eren/haha_2"))
        {
                ccommand("spank "+who->query("id"));
                if (!who->query("eren/haha_3")) {
                        who->add("potential",100);
                        who->add("combat_exp",1000);
                        who->set("eren/haha_3",1);
                        tell_object(who,WHT"你被奖励了！一百潜能，一千经验值！\n"NOR);
                }
                message_vision("$N说:好，好，若你能搞到沙虫肝，我一定能把胖子比下去。\n",this_object());
                message_vision("$N说：我必有重谢！。。。$N向$n挥了挥手。\n",this_object(),who);
                who->set_temp("eren/haha_4",1);
                return 1;
        }       
        if (ob->query("name")==YEL"沙虫肝"NOR && who->query_temp("eren/haha_4")
                && who->query("eren/haha_1") && who->query("eren/haha_2")
                && who->query("eren/haha_3"))
        {
                ccommand("ack "+who->query("id"));
                message_vision("$N结结巴巴地说：你你你哈，活着哈。。。。\n",this_object());
                who->set("marks/恶人窟",1);
                who->delete_temp("eren/haha",1);
                who->delete_temp("eren/haha",2);
                who->delete_temp("eren/haha",3);
                who->delete_temp("eren/haha",4);
           tell_object(who,"哈哈儿凑在你耳边说：告诉你个天大的机密，村里的铁像下埋着宝物，都归你了。\n",this_object());
                ccommand("grin");
                return 1;
        }       
        return 0;       
}     
