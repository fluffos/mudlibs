 // jademaker.c
#include <ansi.h>
int stone();
inherit NPC; 
void create()
{
        set_name("罗达成", ({ "luo", "jade maker", "玉匠" }) );
        set("gender", "男性" );
        set("title", "老石匠");
        set("age", 55);
        set("long", "他有一双锐利的眼睛，那双眼可以分辨顽石和美玉；
他还有一双巧手，而那双手则可以把玉石变成最精美的玉器。\n");
        set("combat_exp", 140);
        set("str", 30);
        set("env/wimpy", 10);
        set("chat_chance", 1);
        set("chat_msg", ({
                "老玉匠自语道：“上次小玉送来的碧螺春味道纯正。”\n",
                "老玉匠喃喃自语道：“五色灵石，五色灵石，难道那只是一个传说吗？”\n",
        }) );
        set("inquiry", ([
                "碧螺春":       "老朽别的没什么爱好，就是喜爱喝些好茶。"
        ]) );
        setup();
        carry_object("/clone/misc/cloth")->wear();
}  
void init(){
        int i;
        object me;
    
        me = this_player();
        i = me->query("marks/Timeyantai");
//      4320
        if ( time() - i > 4320 && i != 0) {
                call_out("yantai", 1, me);   
        }
}  
int stone(){
   object me;
        me = this_player();
        if(this_object()->is_fighting() || this_object()->is_busy()) {
                return 0;
        }
        message_vision(YEL"$N微微一笑道：“传说，有五种灵异的宝石，任何人如果能得到其中的一
种，都能从中得到神奇的灵异力量。不过，这事儿我也只是听说的，风云城里
人来人往，你可以到那儿去打听一下。”\n"NOR, this_object());
        if(me->query("stone_mark")){
                message_vision(HIG"\n$N道：“更有传说，五色灵石可以结成一体保护它的主人。\n"NOR, this_object());
        }
        return 1;       
} 
void yantai(object me) {
        object obj;
    
        if (!random(300)) {
                message_vision(YEL"老石匠叹了口气对$n说道：“老了，手也不听话了，砚台做坏了，这是我家传砚台，\n"NOR,
                        this_object(), me);
                message_vision("就送给你吧。”\n", me);
                obj = new(__DIR__"obj/yantai2");
        } else {
                message_vision(YEL"老石匠说道：“这位" + RANK_D->query_respect(me) + "，这是加工好的砚台。\n"NOR, 
                        this_object(), me);
                if(me->query("marks/Coloryantai") == "青") {
                obj = new(__DIR__"obj/yantai");
                } else if (me->query("marks/Coloryantai") == "紫红") {
                        obj = new(__DIR__"obj/yantai1");
                }
        }
        obj->move(me);   
        me->delete("marks/Coloryantai");
        me->delete("marks/Timeyantai");
        me->delete("marks/玉石加工");
}   
int accept_object(object who, object ob){
        object me,dog;
        string color;
        
        me = this_player();
   if( ob->query("名茶")){
                message_vision("$N拿着茶叶放到鼻子底下嗅了嗅，露出满意的笑容。\n", this_object(), me);
                message_vision("$N说道：“多谢这位" + RANK_D->query_respect(me) + 
",老朽不才，你如果在加工玉石方面有需求，老朽到还略知一二。“ \n", this_object(), me);
                me->set("marks/玉石加工", 1);   
        } else if( ob->query("砚台料") == 1 ){
                message_vision("$N轻轻在" + ob->name() + "叩了两下，笑道:“不错， 不错，这可以做一个上好的砚台。”\n", this_object(), me);
                if(me->query("marks/玉石加工")) {
                        message_vision("$N说道：“这位" + RANK_D->query_respect(me) + "三天后来取砚台吧。”\n", this_object(), me);
                        color = ob->query("color");
                        me->set("marks/Timeyantai", time());
                        me->set("marks/Coloryantai", color);
                }else {
                        message_vision("老玉匠说道：“不过，老朽近来胃口不好，不再接活了。”\n", this_object(), me);
                        return 0;
                }
        } else if (ob->name()==YEL"龙井茶"NOR || ob->name()==GRN"狼山茶"NOR) {
                message_vision("$N说：“茶是上好的名茶，不过，放在店里时间似乎长了，不新鲜喽。”\n",this_object());
                return 0;
        } else if (ob->name()=="云雾茶") {
                message_vision(CYN"$N呸的一声说：“谋财害命之徒，给我滚得远远的。”\n"NOR,this_object());
                message_vision(CYN"$N吹了声口哨，屋里跳出一只牧羊狗。\n"NOR,this_object());
                command("say 虎子，替我赶他出去。");
                if (!dog=present("shepherd dog",environment(this_object()))) {
                        dog=new(__DIR__"sheepdog");
                        dog->move(environment(this_object()));
                }
                dog->fight_ob(me);
                me->fight_ob(dog);
                return 0;       
        }else {
                message_vision("老玉匠摇头说：“我不需要这个。”\n", me);
                return 0;
        }       
        return 1;
}   
