// migong lev12  xuantie-jian

#include <ansi.h>

inherit NPC;


string* names = ({
"赵","钱","孙","李","周","吴","郑","王","冯","陈","褚","卫",
"蒋","沈","韩","杨","朱","秦","尤","许","何","吕","施","张",
"孔","曹","严","华","金","魏","陶","姜","戚","谢","邹","喻",
"柏","水","窦","章","云","苏","潘","葛","奚","范","彭","郎",
"鲁","韦","昌","马","苗","凤","花","方","傻","任","袁","柳",
"邓","鲍","史","唐","费","廉","岑","薛","雷","贺","倪","汤",
"藤","殷","罗","华","郝","邬","安","常","乐","呆","时","付",
"皮","卞","齐","康","伍","余","元","卜","顾","盈","平","黄",
"和","穆","肖","尹","姚","邵","湛","汪","祁","毛","禹","狄",
"米","贝","明","藏","计","伏","成","戴","谈","宋","茅","庞",
"熊","纪","舒","屈","项","祝","董","梁","樊","胡","凌","霍",
"虞","万","支","柯","昝","管","卢","英","仇","候","岳","帅",
"司马","上官","欧阳","夏候","诸葛","闻人","东方","赫连","皇甫",
"尉迟","公羊","澹台","公治","宗政","濮阳","淳于","单于","太叔",
"申屠","公孙","仲孙","辕轩","令狐","钟离","宇文","长孙","幕容",
"司徒","师空","颛孔","端木","巫马","公西","漆雕","乐正","壤驷",
"公良","拓趾","夹谷","宰父","谷梁","楚晋","阎法","汝鄢","涂钦",
"段千","百里","东郭","南郭","呼延","归海","羊舌","微生","梁丘",
"左丘","东门","西门","佰赏","南官",

"缑","亢","况","后","有","琴","商","牟","佘","耳","墨","哈",
"谯","年","爱","阳","佟","第","五","言","福","蒯","钟","宗",
"林","石",
});

string* nm2 = ({
"忠","孝","礼","义","智","勇","仁","匡","宪","令","福","禄","大","小","晓",
"高","可","阿","金","世","克","叔","之","公","夫","时","若","庆","文","武",
"多","才","长","子","永","友","自","人","为","铁","","","","","","","","",
"","","","","","","","","","","","","","",
});

string* nm3 = ({
"霸","白","班","斌","宾","昌","超","诚","川","鼎","定","斗",
"法","飞","风","锋","钢","罡","贯","光","海","虎","华",
"浩","宏","济","坚","健","剑","江","进","杰","俊","康",
"良","麟","民","明","鸣","宁","培","启","强","荣","山",
"泰","涛","挺","伟","熙","祥","雄","旭",
"毅","瑜","羽","宇","岳","舟",
});


void create()
{
  
       int i = random(sizeof(names));
int b;
   set_name(names[i]+nm2[random(sizeof(nm2))]+nm3[random(sizeof(nm3))], 
 ({ "jianmo dizi" , "dizi" }));
 
set("title", HIC"剑魔弟子"NOR);
   set("gender", "男性" );
 set("long",
"剑魔的亲传弟子。\n");
        set("attitude", "aggressive");
        set("vendetta/authority",1);
	  set("force_factor",100+random(200));
  set("max_qi",6000+random(3000));
  set("max_jing",6000+random(3000));
  set("max_sen",6000+random(3000));
  set("max_neili",12000+random(3000));
  set("max_mana",3000+random(3000));
  set("eff_neili",12000+random(3000));
  set("neili",12000+random(3000));
        set("per", 1);
        set("age", 42);

       set("int", 20);

       set("jiali" , 100);
        set("shen", -10000);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 6000000+random(2000000));
                 set_skill("unarmed", 400+random(100));

set_skill("xuantie-sword", 400+random(100));

set_skill("yunv-shenfa", 400+random(100));

set_skill("force", 400+random(100));
set_skill("anranxiaohun-zhang", 400+random(100));
set_skill("sword", 400+random(100));

set_skill("parry", 400+random(100));

set_skill("hubo", 400+random(100));

set_skill("dodge", 400+random(100));

set_skill("xuantie-jianfa", 400+random(100));

set_skill("yunv-xinfa", 400+random(100));

  
        map_skill("sword", "xuantie-jianfa");
  
      map_skill("parry", "xuantie-jianfa");

 map_skill("force", "yunv-xinfa");

 map_skill("dodge", "yunv-shenfa");
 
map_skill("unarmed"  , "anranxiaohun-zhang");
prepare_skill("unarmed", "anranxiaohun-zhang");
set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
               
      (:     perform_action, "sword.xunlei" :),
	
           (: command("hubo")  :),	
         (: exert_function, "recover" :),
        (: exert_function, "powerup" :),
      }) );
if (random(2)==0)
{
b=2;
        set_skill("dodge",300);
        set_skill("cuff",300);
        set_skill("unarmed",300);
        set_skill("parry",300);
        set_skill("blade",320);
         set_skill("feitian-yujianliu",350);
         set_skill("wuxing-dun",300);
        set_skill("shayi",300);
         set_skill("aikido",300);
         set_skill("shayi-xinfa",300);
        set_skill("force",300);

        set_skill("literate",250);
        map_skill("blade", "feitian-yujianliu");
        map_skill("force", "shayi-xinfa");
              map_skill("unarmed", "aikido");
        map_skill("dodge", "wuxing-dun");
        map_skill("parry", "feitian-yujianliu");
        create_family("飞天御剑流", 5, "传人");
         set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.break" :),
                (: perform_action, "unarmed.qin" :),
                (: perform_action, "unarmed.niu" :),
                (: perform_action, "unarmed.yaozhan" :),
                (: perform_action, "blade.chaodao" :),
                (: perform_action, "blade.tianxiang" :),
                (: perform_action, "blade.longlianda" :),
                (: perform_action, "blade.suodi" :),
                (: perform_action, "blade.jiu" :),
                (: perform_action, "unarmed.sanchong" :),
        }));
}
            set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
 
          set_temp("apply/armor", 200);
        set_temp("apply/damage", 200);


        setup();

        carry_object("/d/migong/obj/cloth")->wear();
if (random(2)==0)
   carry_object("/d/migong/obj/sword")->wield();
else carry_object("/d/feitian/npc/obj/wushidao")->wield();
	add_money("gold", random(5));
	

}

void init( )
{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
ob->start_busy(1);
        call_out("hunting",0);
        }
	if(!environment()->query("no_fight") && random(10) < 5)
        call_out("hunting",0);
}

void hunting()
{
	int i;
        object *ob;
        ob = all_inventory(environment());
        for(i=sizeof(ob)-1; i>=0; i--) {
        if( !ob[i]->is_character() || ob[i]==this_object() || !living(ob[i])) continue;
        if(ob[i]->query("vendetta/authority")) continue;
                kill_ob(ob[i]);
                ob[i]->fight(this_object());
        }
}

void die()
{
        object ob, me, corpse;
        
        ob = this_object();
        me = query_temp("last_damage_from");
        if (!me) return;    
             me->add("score",1);
        me->add("shen",10);

        message_vision(WHT"$N口中鲜血狂喷,倒地而亡。\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));me->add("combat_exp",random(12));me->add("potential",random(8));
        if((int)me->query("combat_exp") < 9000000)   {
        message("vision", me->name() + "为江湖除害,增加了600经验和250潜能。\n", me);
        me->add("combat_exp",600);
        me->add("potential",250);
        destruct(ob);
        }
        destruct(ob);
        return;
}
