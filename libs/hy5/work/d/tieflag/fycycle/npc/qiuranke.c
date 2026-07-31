 inherit NPC;
#include <ansi.h>
int regive_book();
void create()
{
        set_name("虬髯大汉", ({ "qiuran han","han" }) );
        set("gender", "男性" );
        set("class", "shaolin" ); 
        set("age", 51);
        set("str", 100);
        set("cor", 60);
        set("cps", 60);
        set("con", 50);
        set("int", 50);
        set("max_qi", 50000);
        set("max_jing", 5000);
        set("max_sen", 5000);
        set("max_neili", 5000);
        set("neili", 20000);
        set_temp("apply/attack", 300);
        set_temp("apply/damage", 200);
        set("long", "一个腰粗膀阔，魁梧异常的虬髯大汉，身穿一套粗布棉袄，
衣裤上都打了补钉。看上去有些落魄，但举手投足之间不自
禁流露出一种盖世英雄的气概！\n");
        set("chat_chance", 2);
        set("chat_msg", ({
    "虬髯大汉作了一个四方揖，朗声说道：在下河南人氏。路经贵地，一不求名，\n二不为利，只为小女年已及笄，尚未许得婆家，因此斗胆比武招亲。\n",
    "虬髯大汉似乎是自言自语：听说叶开年轻英俊，是个英雄人物，怎么没见他来？\n",
                }) );
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.luori" :),
                (: perform_action, "dodge.luoyeqiufeng" :),
                (: exert_function, "shield" :),
        }) );
                set("inquiry", ([
                "丢了风尘简" : (: regive_book :),
                "lost fengchen book" : (: regive_book :),
        ]));
         
        set("combat_exp", 20000000);
        set("attitude", "friendly");
        set_skill("yijinjing", 200);
        set_skill("fall-steps", 200);
        set("force_factor", 50);
        set_skill("force", 300);
        set_skill("unarmed", 300);
        set_skill("iron-cloth", 300);
        set_skill("parry", 300);
        set_skill("dodge", 300);
        set_skill("move", 300);
        set_skill("luoriquan", 300);
        map_skill("unarmed","luoriquan");
        map_skill("force","yijinjing");
            map_skill("iron-cloth","yijinjing");
        map_skill("dodge","fall-steps");
        set("no_arrest", 1);
        setup();
        carry_object("/clone/misc/cloth")->wear();
}
int accept_fight(object me)
{
        command("say 老朽技艺未精，怎是这位大侠敌手？\n");
        return 0;
} 
int regive_book()
{
        object item,me;
        int copies;
        me = this_player();
        if (me->query("m_success/戏风尘")&& me->query("风尘简"))
        {
                copies = me->query("m_success/戏风尘");
                if (copies > 3)
                {
                        message_vision("$N对$n怒道:我已三番四次的赠书于你,既然你不知珍惜,又何必再问.\n",this_object(),me);
                        return 1;
                }
                me->set("m_success/戏风尘",copies+1);
                item = new(__DIR__"obj/" + me->query("风尘简"));
           item->move(me);
                message_vision("$N递给$n一册竹简道:此乃我心血所著,请好好收藏,切勿再丢!\n",this_object(),me);
        }else
        {
                message_vision("$N望着$n冷笑道:做人要以诚为本.我生平最恨欺诈之徒.你好大的胆,竟敢欺骗于我.\n",this_object(),me);
                kill_ob(me);
        }
        return 1; 
} 
void zhaoqin(object me){
        object hong;
        
        
        if(me->query("gender") == "女性" && 
             !( (string) me->name() == "叶开") ){
                message_vision("$N苦笑道：这个。。这位女侠情意俺替小女答谢了。\n", this_object());
        } else if (me->query("age") >= 30){
                message_vision("$N微怒道：阁下一把年纪，难道要我女儿守活寡么？\n", this_object());
        } else if (me->query("combat_exp") < 300000){
                message_vision("$N拱手道：恕俺直言，阁下才学未精，拳脚无眼，还是请回吧。\n", this_object());
        } else if (me->query("m_success/戏风尘")){
                message_vision("$N哼声道：人贵知足，岂能妄求？\n", this_object());
        } else {
                
                hong = present("redcloth girl", environment(this_object()));
                message_vision("$N捋了捋胡须，朗声笑道：好！就让小女陪阁下过几招吧！\n", this_object());
                me->set_temp("marks/fight_hongfunv", 1);
        }
        return;
} 
void lose_fight(object obj){
        object red, item;
        int i; 
        red = present("redcloth girl", environment(this_object()));
        message_vision("$N哈哈大笑道：好！好！李靖诚不欺我！乱世艰难，沧海横流，当有英雄辈出！\n", this_object());
        message_vision("$N也爽朗地笑道：大哥，你可赌输了，别抵赖呦！\n", red);
        message_vision("$N点了点头。\n", this_object());         
        message_vision(CYN"\n$N掏出一册竹简，郑重肃然地交给了$n。\n"NOR, this_object(),obj);
        message_vision("\n$N负手望天，叹道：苍狗白云，世事沧桑。想我虬髯客远赴天涯三十年，\n", this_object());
        message_vision("这乱世红尘也该是少年英雄们的天下了。也罢，这一册竹简乃是我游历海内诸国所著，\n", this_object());
   message_vision("当赠于这位少年英雄！\n", this_object());   
        message_vision("$N毕恭毕敬收起风尘简。\n", obj); 
        if(!obj->query("m_success/戏风尘")){
                obj->set("m_success/戏风尘", 1);
                obj->add("combat_exp", 3000);
                obj->add("score", 2000);
        }
//      string *books = ({"book0", "book1", "book2", "book3", "book4"});
//      item = books[random(4)];
        i = random(6);
    item = new(__DIR__"obj/book" + i);
        item->move(obj);
        obj->set("风尘简","book"+i);
        message_vision(HIG"\n$N仰天笑道：三妹，这一遭游戏红尘，不旺此生啊！走罢！\n"NOR, this_object()); 
        message_vision(HIG"$N轻轻携起红裳女子之手，飘然而去。\n"NOR, this_object());
        environment(this_object())->remove_flag();
        destruct(red);
        destruct(this_object()); 
        
} 
void win_fight(object obj){
        message_vision("$N拍了拍$n的肩膀，哈哈大笑：后生可畏，前途无量，别气馁别气馁！\n", this_object(), obj); 
        obj->set("marks/戏风尘", 1);
        return;
}    
