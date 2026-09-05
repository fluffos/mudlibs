inherit NPC;
#include <ansi.h>
string* names = ({
HIR"红衣"NOR,HIY"黄衣"NOR,BLK"黑衣"NOR,HIW"白衣"NOR,HIC"青衣"NOR,
});
string* ids = ({
"hongyi dizi","huangyi dizi","heiyi dizi","baiyi dizi","qingyi dizi",
});
string* clothes = ({
"/d/shenlongdao/obj/hongyi","/d/shenlongdao/obj/huangyi","/d/shenlongdao/obj/heiyi","/d/shenlongdao/obj/baiyi","/d/shenlongdao/obj/qingyi",
});
string* sexs = ({
"女","男",
});
void create()
{
                                int i=random(5);
                                int j=random(2);
                                string weapon;
                                string cloth;
                                
        set_name(names[i]+"弟子", ({ids[i],"shenlong dizi","dizi"}));
        set("per", random(15) + 15);
        set("gender", j<1?"女性":"男性");
        set("age", random(20) + 25);
        set("str", random(10) + 21);
        set("con", random(10) + 21);
        set("int", random(10) + 21);
        set("dex", random(10) + 21);
        set("combat_exp", 80000 + random(200000)); 
        set("attitude", "friendly");
        set_skill("force", 50+random(30));
        set_skill("whip", 50+random(30));
        set_skill("dodge", 50+random(30)); 
        set_skill("parry", 50+random(30));
        set_skill("dagger", 50+random(30));
        set_skill("dulong-bi", 50+random(30));
        set_skill("shenlong-bian", 50+random(30));
        set_skill("shenlong-xinfa", 50+random(30));
        set_skill("yixingbu", 50+random(30));
        
        map_skill("dodge", "yixingbu");
        map_skill("force", "shenlong-xinfa");
        map_skill("parry", "shenlong-bian");
        map_skill("whip", "shenlong-bian");
        map_skill("dagger", "dulong-bi");
        set("title",HIY"神龙教"NOR);
        set_temp("apply/attack", 10);
        set_temp("apply/defense", 10);
        set_temp("apply/armor", 200);
        set_temp("apply/damage", 20+random(30));

        set("eff_qi", 600); 
        set("qi", 600); 
        set("max_qi", 600); 
        set("eff_jing", 600); 
        set("jing", 600); 
        set("max_jing", 600); 
        set("eff_jingli", 1000); 
        set("neili", 1000); 
        set("max_neili", 1000);
        set("jiali", 30);
        
        weapon = "/d/gumu/obj/changbian";
        setup();
        carry_object(weapon)->wield();
        carry_object(clothes[i])->wear();
}
