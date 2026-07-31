#include <ansi.h>
inherit NPC;  
void create()
{
        set_name(HIY"替补"NOR,({"guardian"}));
//      set("title",YEL"恶人窟守卫"NOR);
        set("long", "这是一伙专门打劫行商的马贼。\n");
        set("age",30+random(20));
        set("attitude", "friendly");
        set("combat_exp", 4500000);
        set("dungeon_npc","eren");
                
        set("max_mana", 1000);
        set("mana", 1000);
        set("max_neili",1000);
        set("neili",1000);
                
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);
        
        set("chat_chance", 1);
        set("chat_msg", ({
        }) );


        set("force_factor",60);
        setup();
        carry_object(__DIR__"obj/oldcloth")->wear();
        
}  
void init() {
        
   object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}  
void greeting(object ob) {
        
        if( !ob || environment(ob) != environment() ) return;
        call_out("event1",1,ob,0); 
}  
string *event1_msg=     ({
        CYN"马贼首领说：“我知道你的来意，你是为那孩子而来。\n"NOR,
        CYN"马贼首领说：“你可知道他的父亲是谁？[穿肠剑]司马烟的名字想来你
不会陌生。“马贼首领的脸上露出怨毒之色，“我全家一十三口，包括
我那未满月的孩子，都是死在司马烟的剑下。“\n"NOR,
        CYN"马贼首领一指周围，我这几个兄弟，之所以落到在此潦倒，也是拜司马
烟所赐。\n"NOR,
        CYN"“我练成武艺，再入恶人谷时，司马贼子竟已病死，我恨我不能手刃。。
所幸苍天有眼，他还留下了个孽种。\n"NOR,
        CYN"马贼首领说：“父债子还，自古如此，更何况此子从小在恶人谷长大，耳
闻目濡皆是穷凶极恶之事，起居住行皆在血腥仇杀之中，若任其长大，又
是一个司马烟，不如就此除去。“\n"NOR,
        CYN"马贼首领说：此事无可再议，你若执意要出头，只有先杀我。“\n"NOR,
        });  
void event1(object me, int count)
{
        if (environment(me)!=environment(this_object()) || this_object()->is_fighting()) return;
        tell_object(me,event1_msg[count]+"\n");
        if(++count==sizeof(event1_msg))
        {
                message_vision(CYN"“你已杀了"+chinese_number(me->query("MKS"))+"人，我等自然不会在你眼中。“\n"NOR,me);
                return;
        }
        else call_out("event1",1,me,count);
        return ;
}        
