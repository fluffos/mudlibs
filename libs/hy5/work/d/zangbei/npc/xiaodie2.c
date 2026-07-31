#include <ansi.h>
inherit NPC;
int check_other(object me); 
void create()
{
        set_name("小蝶",({"xiao die","xiaodie"}));
        set("long","
小蝶美丽得仿佛是自河水中升起的洛神，她的眼睛纵然在薄雾中看来还是那么
明亮，她的声音比春天的流水更动听。鲜红的斗篷，如流水般飘动，漆黑的头
发在风中飞舞，明亮的眼睛中，带着种说不出的怜悯和同情。\n");
        
        set("gender","女性");
                
        set("age",20);          
        set("int",52);
        set("per",100);
        set("cps",20);
        set("str",10);
        
        set("combat_exp",10000);  
        set("attitude", "friendly");
        
        
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([ 
        ]) );           
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
     
        }) );
        set("chat_chance",1);
        set("chat_msg",({
                "小蝶轻轻问道“我只问你，你活过没有？”\n",
                "小蝶轻轻道“一个人若连活都没有活过，怎么能死？”\n",
                
        }) );                   
        
        setup();
        carry_object(__DIR__"obj/redcloak")->wear();
    
}  
void init()
{       
        object me;
        ::init();
        if( interactive(me = this_player()) && !is_fighting() ) {
                if (!me->query("zangbei/星星楼") && !me->query("zangbei/助孙玉伯") && !me->query("zangbei/杀孙玉伯"))
                        return;
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        } 
} 
void greeting(object me)
{
        object ob;
        ob=this_object();
        if( !me || environment(me) != environment() ) return;
        if (me->query("zangbei/星星楼")) {
                message_vision("小蝶向$N甜甜地一笑，偎在$N怀里。\n",me);
                return;
        }
        if (me->query("zangbei/助孙玉伯")) {
                message_vision("小蝶咬着嘴唇静静地凝视着$N，向$N招了招手，转身向雾中走去。\n",me);
                me->set("zangbei/星星楼",1);
                tell_object(me,"透过雾气，你隐约看见在远处有一幢小红楼。\n");
                destruct(this_object());
                return;
        }
        if (me->query("zangbei/杀孙玉伯")) {
                message_vision("小蝶幽幽地说，“你，难道真的要去杀我爹爹？难道你就不要我们的未来了么？”\n",me);
                return;
        }
        
        
}  
