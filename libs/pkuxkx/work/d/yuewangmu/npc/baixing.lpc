inherit NPC;
//老百姓
#include <ansi.h>
void consider();


void create()  
{       set_name("忧国志士", ({ "baixing" }));
	set("gender", "男性");
        set("age", random(10) + 30);
        set("shen", 1000);
        set("str", 10+random(10));
        set("dex", 15+random(10));
   set("long",HIW"当地的百姓,从他的神色看,他并不十分高兴\n"NOR);
        set("combat_exp", 2000+random(2000));
        set("shen_type", 1);
        set("attitude", "friendly");

       set_skill("unarmed", 10+random(10));
    set("chat_chance_combat", 75+random(75));
 set("chat_msg_combat", ({
    (HIY"我才不怕你呢,岳王爷死都不怕,我怕什么?\n"NOR),
  (HIY"岳王爷在世的时候,我都在他手下当过兵呢,什么我没见过?\n"NOR)
       }) );
        set_skill("dodge", 10+random(10));
        set_skill("parry", 10+random(10));


        set_temp("apply/attack", 10);
        set_temp("apply/defense", 10+random(10));
        set_temp("apply/armor", 10+random(10));
        set_temp("apply/damage", 10+random(10));

        set("max_neili", 80);
        set("max_qi",200);
        set("max_jing",100);
        set("max_jingli",40);
        set("neili", 80);
        set("qi",200);
        set("jing",100);
        //set("jingli",40);

        set("jiali", 1);
        
        set("inquiry",([
               "风波亭"  : ("风波亭是岳王爷遇难的地方,现在被秦桧狗贼给占了!\n"),
               "秦桧"  : ("那个大奸臣!说起来我就有气!\n"),
               "杀秦桧"  : ("要是我有钱,我就买杀手杀他!哼!\n"),
               "岳王坟"  : ("听说最近总有人想盗墓,要是我知道了,我就对他不客气!\n"),
                "岳飞"  : ("岳王爷是我们的民族英雄啊,没想到...."),
        ]));


        set("chat_chance", 8);
        set("chat_msg", ({
"呜呜...呜呜...\n",
"岳王爷,你是死得好冤啊!\n",
"岳王爷,我一定为你报仇!杀了秦桧这贱人!\n",
"我也要像您那样,为国家做出自己的贡献!\n"
"没有岳王爷,咱们国家可怎么办啊?\n",
"听说秦桧手下有十大高手日夜保护他,要见他一面都难呢!我看侠士你的武功平平,还是算了吧\n",
"侠士,你要是武功高强就去把秦桧干掉吧!\n",
"唉,....岳王爷\n",
"秦桧这狗贼!\n",
"要不,壮士你教我武功,我去杀那狗贼!!\n",
"秦桧狗贼,什么时候才死啊!大伙都盼着这天呢!\n"
        }) );

        setup();
}
