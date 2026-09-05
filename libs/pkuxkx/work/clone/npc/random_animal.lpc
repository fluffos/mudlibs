//Zine 随机地图的动物
inherit NPC;
#include <ansi.h>
#include "animal_data.h"
int specialize(int i,object ob);
int gene(int i,object ob);
int grassland_gene(object ob);
int mountain_gene(object ob);
int forest_gene(object ob);
int desert_gene(object ob);
int lakeside_gene(object ob);
int get_its_attributes()
{
    object me=this_object();
    object env=environment(me);
	if (!env)
	{
		return 1;
	}
    if (env->query("type"))
    me->set("type",env->query("type"));
    if (me->query("type")=="沙漠")
    {
        desert_gene(me);
    }
    else if (me->query("type")=="草原")
    {
        grassland_gene(me);
    }
    else if (me->query("type")=="山地")
    {
        mountain_gene(me);
    }
    else if (me->query("type")=="林地")
    {
        forest_gene(me);
    }
    else if (me->query("type")=="湖泽")
    {
        lakeside_gene(me);
    }
    else
    {
        destruct(this_object());//无类型，不能跳出来一个名叫“动物”的动物。
    }
    return 1;
}

void create()
{
	set_name("动物",({"animal"}));
	set("long","这是一只动物。\n");
    set("race", "野兽");
    set("type", "沙漠");
    set("no_show",1);
    set("verbs", ({ "bite" }));
    set("chat_chance", 20);
	set("chat_msg", ({
		(: random_move :),
	}) );
	setup();
    call_out("get_its_attributes",1);
}

int gene(int i,object ob)
{
    object env=environment(ob);
    int n=random(100);
    if (n<=i)
    {
        ob->set("no_show",0);
        ob->set("gene_possibility",n);
        ob->set("long","这是一个生活在"+ob->query("type")+"的"+ob->query("name")+"。\n");
    }
    else
    {
        destruct(ob);//概率下，未达到出现条件。
    }
    return 1;
}

int specialize(int i,object ob)//特殊化，比如马匹和虫子肯定不应该同样的四肢
{
    object env=environment(ob);
    if (member_array(ob->query("animal_code"),big_animal)!=-1)
    {
        set("race", "马类");
        set("limbs", ({ "头部", "身体", "前蹄","后蹄", "尾巴" }) );
        set("act_limbs", ({ "前蹄","后蹄"}) );
        set("verbs", ({ "bite","hoof","zhuang" }));
        gene(i,ob);
        return 1;
    }
    if (member_array(ob->query("animal_code"),small_animal)!=-1)
    {
        set("race", "野兽");
        set("limbs", ({ "躯干","头部","脚","手","尾巴" }) );
        set("act_limbs", ({ "脚","手" }) );
        set("verbs", ({ "bite","hoof","claw" }));
        gene(i,ob);
        return 1;
    }
    if (member_array(ob->query("animal_code"),middle_animal)!=-1)
    {
        set("race", "野兽");
        set("limbs", ({ "躯干","头部","前爪","后爪" }) );
        set("act_limbs", ({ "前爪","后爪" }) );
        set("verbs", ({ "bite","hoof","claw" }));
        gene(i,ob);
        return 1;
    }
    if (member_array(ob->query("animal_code"),insect)!=-1)
    {
        set("race", "野兽");
        set("limbs", ({"爪子", "头部", "身体", "腿", "尾巴" }) );
        set("act_limbs", ({ "爪子", "尾巴" }) );
        set("verbs", ({ "bite","qian" }));
        gene(i,ob);
        return 1;
    }
    if (member_array(ob->query("animal_code"),snake)!=-1)
    {
        set("race", "蛇类");
        set("limbs", ({ "头部", "身体", "七寸", "尾巴" }) );
        set("act_limbs", ({ "尾巴" }) );
        set("verbs", ({ "bite","sao2" }));
        gene(i,ob);
        return 1;
    }
    if (member_array(ob->query("animal_code"),bird)!=-1)
    {
        set("race", "野兽");
        set("limbs", ({ "头部", "身体", "翅膀","爪子", "尾巴" }) );
        gene(i,ob);
        set("verbs", ({ "bite","claw","poke","sao" }));
        return 1;
    }
    destruct(ob);//无类型
    return 1;
}

int grassland_gene(object ob)
{
    int i=random(sizeof(grassland_animal));
    ob->set_name(grassland_animal[i],({grassland_animal_id[i],"animal"}));
    ob->set_weight(grassland_animal_weight[i]);
    ob->set("combat_exp",grassland_animal_exp[i]);
    ob->set("animal_code",grassland_animal_number[i]);
    ob->set("chat_chance",grassland_animal_move[i]);
    ob->specialize(grassland_animal_possibility[i],ob);
    return 1;
}

int desert_gene(object ob)
{
    int i=random(sizeof(desert_animal));
    ob->set_name(desert_animal[i],({desert_animal_id[i],"animal"}));
    ob->set_weight(desert_animal_weight[i]);
    ob->set("combat_exp",desert_animal_exp[i]);
    ob->set("animal_code",desert_animal_number[i]);
    ob->set("chat_chance",desert_animal_move[i]);
    ob->specialize(desert_animal_possibility[i],ob);
    return 1;
}

int mountain_gene(object ob)
{
    int i=random(sizeof(mountain_animal));
    ob->set_name(mountain_animal[i],({mountain_animal_id[i],"animal"}));
    ob->set_weight(mountain_animal_weight[i]);
    ob->set("combat_exp",mountain_animal_exp[i]);
    ob->set("animal_code",mountain_animal_number[i]);
    ob->set("chat_chance",mountain_animal_move[i]);
    ob->specialize(mountain_animal_possibility[i],ob);
    return 1;
}

int forest_gene(object ob)
{
    int i=random(sizeof(forest_animal));
    ob->set_name(forest_animal[i],({forest_animal_id[i],"animal"}));
    ob->set_weight(forest_animal_weight[i]);
    ob->set("combat_exp",forest_animal_exp[i]);
    ob->set("animal_code",forest_animal_number[i]);
    ob->set("chat_chance",forest_animal_move[i]);
    ob->specialize(forest_animal_possibility[i],ob);
    return 1;
}

int lakeside_gene(object ob)
{
    int i=random(sizeof(lakeside_animal));
    ob->set_name(lakeside_animal[i],({lakeside_animal_id[i],"animal"}));
    ob->set_weight(lakeside_animal_weight[i]);
    ob->set("combat_exp",lakeside_animal_exp[i]);
    ob->set("animal_code",lakeside_animal_number[i]);
    ob->set("chat_chance",lakeside_animal_move[i]);
    ob->specialize(lakeside_animal_possibility[i],ob);
    return 1;
}

int random_move()
{
    mapping exits;
    string *dirs;
    int i;

    if(!environment()) return 0;
    if(sizeof(environment()->query("exits")) == 0) return 0;
    if( !mapp(exits = environment()->query("exits")) ) return 0;
    dirs = keys(exits);
    i = random(sizeof(dirs));
    if( !environment()->valid_leave(this_object(), dirs[i]) ) return 0;
    if (!load_object(environment()->query("exits/"+dirs[i]))->blind_random_map()) return 0;
    command("go " + dirs[i]);
}

void die()
{
	object food;
	object ob=this_object();
	string food_name=ob->query("name")+"肉";
	string food_id=ob->query("id")+" rou";
	food=new(__DIR__"random_animal_food");
	food->set_name(food_name, ({food_id, "rou"}));
	food->set("long", "一大块"+ob->query("name")+"的生肉。\n");
	food->set("unit", "块");
	food->set_weight(ob->weight()/5*4);
	food->set("food_remaining", ob->weight()/400);
    food->set("food_supply", 25+random(25));
	food->move(environment(ob));
    COMBAT_D->announce(ob, "dead");
    ob->remove_all_killer();
	destruct(ob);
	return;
}
