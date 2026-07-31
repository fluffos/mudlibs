// migong lev9 般若掌 一指禅

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
   set_name(names[i]+nm2[random(sizeof(nm2))]+nm3[random(sizeof(nm3))],
 ({ "man" }));

set("title", HIB"武林败类"NOR);
   set("gender", "男性" );
 set("long",
"无恶不做的江湖败类。\n");
        set("attitude", "aggressive");
        set("vendetta/authority",1);
	  set("force_factor",100+random(200));
  set("max_qi",5000+random(2000));
  set("max_jing",5000+random(2000));
  set("max_sen",5000+random(2000));
  set("max_neili",5000+random(2000));
  set("max_mana",2000+random(2000));
  set("eff_neili",5000+random(2000));
  set("neili",2000+random(2000));
        set("per", 1);
        set("age", 32);

       set("jiali" , 100);
        set("shen", -10000);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 3500000+random(1200000));
                 set_skill("strike", 330+random(50));

 set_skill("finger", 330+random(50));

set_skill("hunyuan-yiqi", 330+random(50));

set_skill("yijinjing", 330+random(50));

set_skill("force", 330+random(50));
set_skill("banruo-zhang", 330+random(50));

set_skill("parry", 330+random(50));

set_skill("dodge", 330+random(50));

set_skill("shaolin-shenfa", 330+random(50));

set_skill("yizhi-chan", 330+random(50));


        map_skill("strike", "banruo-zhang");

      map_skill("parry", "banruo-zhang");

 map_skill("force", "yijinjing");

 map_skill("dodge", "shaolin-shenfa");

map_skill("finger"  , "yizhi-chan");
prepare_skill("finger", "yizhi-chan");
prepare_skill("strike", "banruo-zhang");
set("chat_chance_combat", 80);
        set("chat_msg_combat", ({

      (: perform_action, "strike.san" :),

       (: perform_action, "finger.dian" :),

      (: perform_action, "finger.jingmo" :),

     //(: exert_function, "recover" :),
    (: exert_function, "jingang" :),
 }) );
            set_temp("apply/attack", 150);
        set_temp("apply/defense", 150);

          set_temp("apply/armor", 150);
        set_temp("apply/damage", 150);


        setup();

        carry_object("/d/migong/obj/cloth")->wear();

add_money("silver", random(10));


}

void init()
{	
	object ob; 

	ob = this_player();
	::init();
	if (interactive(ob) && ! is_fighting()){
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}
void greeting(object ob)
{
		kill_ob(ob);
}

void die()
{
        object ob, me;
        ob = this_object();
        me=  this_object()->query_last_damage_from();
        if (!me) 
        return;            
        message_vision(WHT"$N口中鲜血狂喷,倒地而亡。\n"NOR,ob,me);
        if((int)me->query("combat_exp") > 500000)   {
        message("vision", me->name() + "为江湖除害,增加了500修为和500潜能。\n", me);
        me->add("combat_exp",500);
        me->add("potential",500);
        }

        ::die();
}