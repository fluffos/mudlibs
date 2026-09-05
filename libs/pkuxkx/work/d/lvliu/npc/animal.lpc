inherit NPC;
#include <ansi.h>
#include "animal.h"
int specialize(int i,object ob);
int grassland_gene(object ob);
int mountain_gene(object ob);
int forest_gene(object ob);
int lakeside_gene(object ob);

int get_its_attributes()
{
    object me=this_object();
	switch (random(4))
	{
		case 3: grassland_gene(me); break;
		case 2: mountain_gene(me); break;
		case 1: forest_gene(me); break;
		case 0: lakeside_gene(me); 
	}
	message_vision("$N走了过来。\n"NOR, me);
}

void create()
{
	set_name("动物",({"animal"}));
    set("race", "野兽");
	set("long","一只正在玩耍的动物，一副悠闲自得的样子，见了人来也毫不害怕。\n");
    set("verbs", ({ "bite" }));
    set("chat_chance", 20);
	set("chat_msg", ({
		(: random_move :),
	}) );
	set("lvliu_npc", 1);
	set("lvliu_animal", 1);
	setup();
	get_its_attributes();
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
        return 1;
    }
    if (member_array(ob->query("animal_code"),small_animal)!=-1)
    {
        set("race", "野兽");
        set("limbs", ({ "躯干","头部","脚","手","尾巴" }) );
        set("act_limbs", ({ "脚","手" }) );
        set("verbs", ({ "bite","hoof","claw" }));
        return 1;
    }
    if (member_array(ob->query("animal_code"),middle_animal)!=-1)
    {
        set("race", "野兽");
        set("limbs", ({ "躯干","头部","前爪","后爪" }) );
        set("act_limbs", ({ "前爪","后爪" }) );
        set("verbs", ({ "bite","hoof","claw" }));
        return 1;
    }
    if (member_array(ob->query("animal_code"),bird)!=-1)
    {
        set("race", "野兽");
        set("limbs", ({ "头部", "身体", "翅膀","爪子", "尾巴" }) );
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

