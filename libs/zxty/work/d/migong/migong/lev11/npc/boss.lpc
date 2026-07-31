// migong lev11  huoyan-dao

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
 ({ "sha shou" , "shou" }));
 
set("title", HIR"杀手之王"NOR);
   set("gender", "男性" );
 set("long",
"天下杀手的总头目，一直在暗中活动着。\n");
        set("attitude", "aggressive");
        set("vendetta/authority",1);
	  set("force_factor",100+random(200));
  set("max_qi",9000+random(2500));
  set("max_jing",9000+random(2500));
  set("max_sen",90000+random(2500));
  set("max_neili",19000+random(2500));
  set("max_mana",9000+random(2500));
  set("eff_neili",19000+random(2500));
  set("neili",19000+random(5000));
        set("per", 1);
        set("age", 50);
set("no_get",1);
       set("jiali" , 50);
        set("shen", -10000);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 5000000+random(2000000));
                 set_skill("strike", 360+random(60));

set_skill("longxiang", 360+random(60));

set_skill("xiaowuxiang", 360+random(60));

set_skill("force", 360+random(60));
set_skill("huoyan-dao", 360+random(60));
set_skill("parry", 360+random(60));

set_skill("dodge", 360+random(60));

set_skill("lamaism", 360+random(60));

set_skill("shenkong-xing", 360+random(60));

         map_skill("parry", "huoyan-dao");

 map_skill("force", "xiaowuxiang");

 map_skill("dodge", "shenkong-xing");
 
map_skill("strike"  , "huoyan-dao");
prepare_skill("strike", "huoyan-dao");
set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
             
   (: perform_action, "strike.fen" :),

     (: perform_action, "strike.xiuluo" :),
	
    (: perform_action, "strike.honglian" :),
	
     (: perform_action, "strike.fen" :),
	
     (: exert_function, "recover" :),	
       (: perform_action, "dodge.tianmaxingkong" :),

     (: exert_function, "shield" :),
     }) );
            set_temp("apply/attack", 250);
        set_temp("apply/defense", 250);
 
          set_temp("apply/armor", 250);
        set_temp("apply/damage", 250);


        setup();

        carry_object("/d/migong/obj/cloth")->wear();

add_money("gold", 30);
        

}

void init( )
{
	object ob;	
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
        ob->start_busy(3);
        call_out("hunting",0);
        }
	if(!environment()->query("no_fight"))
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
        object ob, me, corpse,obj;
        int maxpot;
        int exp,pot,score,i; 
        ob = this_object();
        me = query_temp("last_damage_from");
        if (!me) return;    
             me->add("score",1);
        me->add("shen",10);

        message_vision(WHT"$N口中鲜血狂喷,倒地而亡。\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));me->add("combat_exp",random(12));me->add("potential",random(8));
if (me->query("migong/lev11"))
{
if( !environment(me)->query("no_fight")
&& random(4)==1)
{
obj=new("/d/migong/obj/npct"); 
maxpot=me->query_temp("maxpot")+10;
obj->do_copy(me,maxpot,2);
obj->set("usename",me->query("name"));
obj->move(environment(me));
message_vision(HIY"$N狂笑道：让你见识是一下武术的真髓! !\n"NOR, obj);
me->start_busy(3);
me->kill_ob(obj);
obj->kill_ob(me);
}
else 
{
		obj = new("/clone/npc/antirobot"+(2+random(2)));
		obj->test_robot(me);
}
}
if (!me->query("migong/lev11"))
{
me->set("migong/lev11",1);
message("channel:chat", HIM"【江湖谣言】听说"+me->name() + "完成了迷宫第十一层!"NOR"。\n", users());
exp = 400000+random(25000);
pot = exp/2;
score = random(300)+550;
             me->add("combat_exp",exp);
             me->add("potential",pot);
             me->add("score",score);
tell_object(me,HIW"你被奖励了：\n" +
             chinese_number(exp) + "点实战经验\n"+
             chinese_number(pot) + "点潜能\n" +
            chinese_number(score)+"点江湖阅历\n"NOR);
i=random(8);
	if (i==7) {
        if ( me->query("per")< 60)
        {
	me->add("per",1);tell_object(me,HIM"以及一点容貌。\n"NOR);
        }
	}
	else if (i==6) {
        if ( me->query("kar")< 60)
        {
	me->add("kar",1);tell_object(me,HIM"以及一点福缘。\n"NOR);
        }
	}
	else if (i==5) {
        if ( me->query("dex")< 60)
        {
	me->add("dex",1);tell_object(me,HIM"以及一点身法。\n"NOR);
        }
	}
	else if (i==4) {
        if ( me->query("str")< 60)
        {
	me->add("str",1);tell_object(me,HIM"以及一点力量。\n"NOR);
        }
	}
	else if (i==3) {
        if ( me->query("per")< 60)
        {
	me->add("per",1);tell_object(me,HIM"以及一点容貌。\n"NOR);
        }
	}
	else if (i==2) {
        if ( me->query("kar")< 60)
        {
	me->add("kar",1);tell_object(me,HIM"以及一点福缘。\n"NOR);
        }
	}
	else if (i==1) {
        if ( me->query("con")< 60)
        {
	me->add("con",1);tell_object(me,HIM"以及一点根骨。\n"NOR);
        }
	}
	else if (i==0) {
        if ( me->query("int")< 60)
        {
	me->add("int",1);tell_object(me,HIM"以及一点悟性。\n"NOR);
        }
	}
	else if (me->query("per")< 100) {
	me->add("per",1);tell_object(me,HIM"以及一点容貌。\n"NOR);
	}
}
        if((int)me->query("combat_exp") < 8000000)   {

if (random(45) < 1)
{
             corpse=new("/clone/gem/gem");
             message_vision("$N得到一颗亮晶晶的宝石。\n",killer);
             command("rumor "+killer->query("name")+"得到一颗"+corpse->query("name")+"!"NOR"。\n");
             corpse->move(killer);
}        
        message("vision", me->name() + "为江湖除害,增加了1000经验和500潜能。\n", me);
        me->add("combat_exp",1000);
        me->add("potential",500);
        destruct(ob);
        }
        destruct(ob);
        return;
}
