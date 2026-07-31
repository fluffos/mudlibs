#include <ansi.h>
inherit NPC;

string *nm1_jp =({
"山本","龟田","姿三","大岛","松下","横田","东芝","候本","川野","山口",
"铃木","岗仓","小岛","井上","安奈","浅田","佐藤","广末","大竹","大村",
"伯佐","富冈","东乡",
});

string *id_jp =({
"shanben","guitian","zisan","dadao","songxia","hengtian","dongzhi","houben","chuangye","shankou",
"lingmu","gangcang","xiaodao","jinshang","annai","qiantian","zuoteng","guangmu","dazhu","dachun",
"bozuo","fugang","dongxiang",
});

string *nm2_jp =({
"太郎","次郎","三郎","四郎","五郎","十一郎","十四郎","二十六","俊树",
"宁次","英机","冶字","俊雄","牧夫","光夫","敬一","英世","漱石","渝吉",
"一叶","子规","稻造","伊冲","松园","深水","大观","丰国","孝和","茂",
"川","卫","岛寿","光云","安治","山乐","梦二",
});

void create()
{
   int i = random(sizeof(nm1_jp));
    set_name(nm1_jp[i]+nm2_jp[random(sizeof(nm2_jp))], ({id_jp[i]}));
    set("gender", "男性" );//性别与上面对应
//        set_name("东洋倭寇", ({ "wokou", "japan wokou" }) );
        set("long",
"一个身长不足四尺满脸又是伤疤加横肉的小日本。\n");
        set("attitude", "aggressive");
        set("vendetta/authority",1);
	set("nickname",HIR"倭寇将军"NOR);
  set("force_factor",2+random(390));
  set("max_qi",3000+random(690));
  set("max_jing",3000+random(890));
  set("max_sen",3000+random(890));
  set("max_neili",3000+random(890));
  set("max_mana",3000+random(890));
  set("eff_neili",3000+random(390));
  set("neili",3000+random(1390));
        set("per", 1);
        set("age", 22);
        set("shen", -10000);
        set("intellgent",1);
	set("pursuer",1);
        set("combat_exp", 400000+random(2000000));
	set("bellicosity", 10000);
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "blade.leitingpili" :),
                (: perform_action, "blade.kuang" :),
                (: random_move :),
        }) );
        set("chat_chance", 10);
        set("chat_msg", ({
                "倭寇将军喝道：男人的,统统的杀啦,杀啦的！！\n",
                "倭寇将军笑道：花姑娘的,留下,让皇军快活,快活的!\n",
                "倭寇将军笑道：杀喼喼!统统的杀啦,杀啦的！！\n",
                (: random_move :),
        }) );

        set_skill("unarmed", 80+random(180));
        set_skill("blade", 80+random(180));
        set_skill("parry", 80+random(180));
        set_skill("dodge", 80+random(180));
      //  set_skill("wind-blade", 80+random(180));

        map_skill("blade", "wind-blade");
        map_skill("parry", "wind-blade");
        set_temp("apply/attack", 20);
        set_temp("apply/defense",50);
        set_temp("apply/armor", 50);
        set_temp("apply/damage", 20);

        setup();

        carry_object(__DIR__"obj/japancloth")->wear();
        carry_object(__DIR__"obj/japanblade")->wield();
	add_money("silver", random(50));
}
void init( )
{
	object ob;
        remove_call_out("hunting");
	if( interactive(ob = this_player())  ) {
        call_out("hunting",1);
        }
	if(!environment()->query("no_fight") && random(10) < 5)
        call_out("hunting",1);
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

        message_vision(WHT"$N大叫一声,天皇万岁!!倒地而亡。\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));
        if((int)me->query("combat_exp") > 10000)   {
        message("vision", me->name() + "由于成功的保卫了祖国,增加了2000修为和1000潜能。\n", me);
        me->add("combat_exp",2000);
        me->add("potential",1000);
		me->add("score",2);
        me->add("shen",10);
        destruct(ob);
        }
        return;
}
