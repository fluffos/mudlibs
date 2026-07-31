#include <ansi.h>
inherit NPC;
int estate();
void create()
{
        set_name("高老大",({"gao laoda","gao"}));
        set("title",HIR"快活林"NOR);
        set("long","
高老大并不是大哥是大姬，她有一双极美丽的手，只不过略嫌太大了些，正显示出这双
手的主人那种倔强的性格。在战乱饥灾最严重的时候，十三岁的她一个人带大了四个孩
子，她几乎做过任何事，她偷，她抢，她骗，她甚至出卖过自已。那时无论谁只要给她
一套衣服，就可以在她身上得到一切。现在她却几乎拥有一切。\n");
        
        set("gender","女性");
        set("group","khlr");
        
        set("age",32);          
        set("int",52);
        set("cor",30);
        set("cps",20);
        set("str",40);
        
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
                "创伤":         (: estate() :),
                "快活林":       (: estate() :),
           "疤":           (: estate() :),
                "地契":         (: estate() :),
                "孟星魂":       "孟星魂，石群，小何，叶翔都是我一手带大的。\n",
                "孟星魂":       "孟星魂，石群，小何，叶翔都是我一手带大的。\n",
                "孟星魂":       "孟星魂，石群，小何，叶翔都是我一手带大的。\n",
                "孟星魂":       "孟星魂，石群，小何，叶翔都是我一手带大的。\n",
                "msg":          "yes",
        ]));
        
        set("death_msg",CYN"\n$N狂笑着道“你们全都去死吧，死光了最好。”\n"NOR);        
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([ 
        ]) );           
        set("chat_chance",1);
        set("chat_msg",({
                "\n高老大把紫红色的窗帘放下，一个人静静的坐在昏暗的屋内，她并不是厌恶光
亮，面是畏惧—也并不是怕她脸上的皱纹会被照出来，而是怕照出她心里的那
些创伤。这些创伤久已结成了疤，永远抹不去的疤。。\n",
        }) );                   
        
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
 
}  
int estate() {
        object ob,me;
        ob=this_object();
        me=this_player();
        
        if (me->query("zangbei/助高老大")) {
                message_vision("
高老大的手慢慢地伸过去握着了$N的手，缓缓接着道“我知道你也累得很，
但生活就是这样子的，我们要活下去，就不能停下来。”\n",me);
                return 1;
   }
        
        if (me->query("zangbei/杀孙玉伯",1)) {
                message_vision("
孙玉伯已经死了，不过，我们的交易是要用他的地契来结算的。\n",me);
                return 1;
        }
        
        if (me->query("combat_exp")<5000000) {
                message_vision("高老大看了看$N说，你这点能耐，恐怕帮不了我的忙。\n",me);
                return 1;
        }
        
        message_vision("\n
高老大环顾四周，慢慢地说：“这是我的屋子，屋子里所有的一切，全都是我
的。而这屋子，只不过是我财产中极小极小的部分。到这儿来的，不是家财万
贯的富商巨贸，就是名声显赫的武林豪杰，只要我开口他们就会去为我做任何
事，因为他们也同样有求于我。 
不过，这快活林的地却不是我的，很多年前，租下这快活林时我还很穷，现在
我的财产已足以买下五百座这样的园子，但是我却仍然得不到这快活林的地契。
因为这块地是孙玉伯的。 
我唯一的愿望就是这张地契，如果你能替我拿到它，我的一半财产就是你的，
我在济南泰安广场买下的那块土地也是你的。\n\n",me);
        me->set("zangbei/接刺杀任务",1);
        return 1;
} 
