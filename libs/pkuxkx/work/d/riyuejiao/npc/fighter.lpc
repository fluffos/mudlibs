#include <ansi.h>
#include "/d/riyuejiao/bonus.h"
inherit FAMILY_NPC;
varargs void wield_weapon(string weapon);
int ask_fight();

void create()
{
	string name,*tmp,*pinying;
    name=NAME_D->create_name();
    tmp=explode(name,"@");
    pinying=explode(tmp[1]," ");
    set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
	set("gender", "男性" );
	set("age", 22+random(10));
	set("long", "这是一名日月神教的弟子，他负责训练入门弟子，专用别派的招式。\n");
	set("combat_exp", 10000000);
	set("attitude", "heroism");
	set("random_npc",1);
    set("food",500);
    set("water",500);
    set("bonus",8);
	set("chat_chance", 25);
	set("uni_target", 1);
    set("inquiry", ([
                "比武"  :     (: ask_fight :),
                "biwu"  :     (: ask_fight :),
                "fight"  :     (: ask_fight :),
                "比划"  :     (: ask_fight :),
        ]));
	setup();
    carry_object("/clone/cloth/cloth")->wear();
	
    call_out("dest",240);
}

int dest()
{
    object ob=this_object();
    object me;
    if (ob->query("uni_target") && ob->query("uni_target")!=1)
    {
        me=find_player(ob->query("uni_target"));
    }
    if (me)
    {
        me->delete_temp("rynewbiejob/lianwu/start");
    }
    if (!ob->is_fighting()&&!ob->is_busy())
    {
        message_vision("$N见没有什么弟子可以调教，于是离去休息了。\n",ob);
        destruct(ob);
    }
    call_out("dest",60);
    return 1;
}

void die()
{
    object ob=this_object();
    object me;
    if (ob->query("uni_target") && ob->query("uni_target")!=1)
    {
        me=find_player(ob->query("uni_target"));
    }
    if (me)
    {
        me->delete_temp("rynewbiejob/lianwu/start");
    }
    if (ob->get_damage_origin_object()==me)
    {
        me->set_temp("rynewbiejob/lianwu/half",1);
        bonus(me);
    }
    message_vision("一个声音冷冷道：$N这么不经打？死了也白死，拖出去扔下后崖。\n",ob);
    message_vision("几个弟子过来，把$N的尸体抬了出去。\n",ob);
    destruct(ob);
    return;
}

int do_copy(object me)
{
	int level,exp;
	int addition = 1;
	int life = 0;

	if(!objectp(me))
		return 0;
	exp = me->query("combat_exp");
    
	level = to_int(pow(exp/100,0.333)*10);
    set("combat_exp", me->query("combat_exp")/10*(11+random(2)));
	family_skill(this_object(), "random", level, 1);
	
    set("chat_chance_combat", 150);
	
	life = exp/(120-random(41));

	set("max_qi", life);
	set("eff_qi", life);
	set("qi", life);
	set("max_jing", life);
	set("eff_jing", life);
	set("jing", life);
	set("max_jingli", life);
	set("jingli", life);
	set("max_neili", life*1.5);
	set("neili", life*2);

	set("uni_target", me->query("id"));
	wield_weapon();
}

varargs void wield_weapon(string weapon)
{
	if(!weapon && query("use_weapon1"))
		wield_weapon(query("use_weapon1"));
	if(!weapon && query("use_weapon2"))
		wield_weapon(query("use_weapon2"));
	if(!weapon)
		return;
	switch(weapon)
	{
	case "sword":
		carry_object("/clone/weapon/changjian")->wield();
		break;
	case "blade":
		carry_object("/clone/weapon/gangdao")->wield();
		break;
	case "staff":
		carry_object("/clone/weapon/gangzhang")->wield();
		break;
	case "whip":
		carry_object("/clone/weapon/changbian")->wield();
		break;
	case "zhen":
		set("gender", "无性");
		carry_object("/d/city/obj/flower_shoe")->wear();
		carry_object("/d/city/obj/pink_cloth")->wear();
		carry_object("/d/city/obj/goldring")->wear();
		carry_object("/d/city/obj/necklace")->wear();
		carry_object("/d/quanzhou/obj/xiuhua")->wield();
		carry_object("/d/riyuejiao/obj/xiuhuajia");
		break;
	case "dagger":
                carry_object("/clone/weapon/bishou")->wield();
		break;
        case "xiao":
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/obj/shizi");
                carry_object("/d/taohuadao/npc/obj/yuxiao")->wield();
         break;
         case "ling":
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/npc/obj/jinhua");
                carry_object("/d/mingjiao/obj/shenghuo-ling")->wield();
         break;
	case "hammer":
		carry_object("/d/dalunsi/npc/obj/iron-falun")->wield();
		break;
	default:
	}
	return;
}
int ask_fight()
{
    object ob=this_object();
    object me=this_player();
    if (me->query("family/family_name")!="日月神教")
    {
        command("ah");
        command("say 你是何人？");
        return 1;
    }
    if (base_name(environment(ob))!="/d/riyuejiao/lianwu1"&&base_name(environment(ob))!="/d/riyuejiao/lianwu2")
    {
        command("say 此处施展不开，不宜比武。");
        return 1;
    }
    if (!me->query_temp("rynewbiejob/lianwu/start"))
    {
        command("say 没有教主许可，不得擅自比武？");
        return 1;
    }
    if (ob->query("uni_target")!=me->query("id"))
    {
        command("say 你确定要找我比武？我看不是吧？");
        return 1;
    }
    ob->set("eff_qi", ob->query("max_qi"));
    ob->set("qi",     ob->query("max_qi"));
    ob->set("jing",   ob->query("max_jing"));
    ob->set("neili",  ob->query("max_neili"));
    me->add_busy(2);
    command("say 好吧，我们切磋切磋，点到即止。");
    ob->fight_ob(me);
    me->fight_ob(ob);
    me->set_temp("rynewbiejob/lianwu/kaishi",1);
    call_out("checking",1,me,ob);
    return 1;
}
int checking(object me, object ob)
{
        int my_max_qi, his_max_qi;

        my_max_qi  = ob->query("max_qi");
        his_max_qi = me->query("max_qi");

        if (ob->is_fighting())
        {
                call_out("checking",2, me, ob);
                return 1;
        }

        if ( !present(me, environment()) ) return 1;

        if (( (int)me->query("qi")*100 / his_max_qi) < 50 )
        {
                if (me->query_temp("rynewbiejob/lianwu/kaishi"))
                {
                    command("say 看来" + RANK_D->query_respect(me) +
                        "还得多加练习，方能在本教诸多弟子中出人头地 !\n");
                    me->set_temp("rynewbiejob/lianwu/half",1);
                    bonus(me);
                    destruct(ob);
                }
                
                return 1;
        }

        if (( (int)ob->query("qi")*100 / my_max_qi) <= 50 )
        {
            if (me->query_temp("rynewbiejob/lianwu/kaishi"))
            {
                command("say 我教弟子人才辈出，长江后浪推前浪啊!\n");
                bonus(me);
                destruct(ob);
                return 1;
            }
        }
        return 1;
}

