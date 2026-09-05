#include <ansi.h>
inherit FAMILY_NPC;
varargs void wield_weapon(string weapon);
int dest();
void create()
{
	string name,*tmp,*pinying;
    name=NAME_D->create_name();
    tmp=explode(name,"@");
    pinying=explode(tmp[1]," ");
    set_name(tmp[0],({tmp[1],pinying[0],pinying[1]}));
	set("gender", "男性" );
	set("age", 22+random(10));
    set("title",HIW+"狱中龙"+NOR);
	set("long", "这是一名不知道何派的弟子，被关在神教监狱很久了，今天终于找到机会出逃。\n");
	set("combat_exp", 10000000);
	set("attitude", "heroism");
	set("random_npc",1);
    set("food",500);
    set("water",500);
	set("chat_chance", 25);
    set("cantleave",1);
	setup();
    carry_object("/clone/cloth/cloth")->wear();
	call_out("leave",120);
    call_out("dest",240);
    call_out("moving",3);
}

int moving()
{
    object ob=this_object();
    object me;
    
    string *place=({"/d/riyuejiao/guodao1","/d/riyuejiao/guodao2","/d/riyuejiao/guodao3","/d/riyuejiao/guodaoa","/d/riyuejiao/guodaob","/d/riyuejiao/guodaoc","/d/riyuejiao/guodaod"});
    if (!stringp(ob->query("user_target")))
    {
		destruct(ob);
		return 1;
    }
	if (!me=find_player(ob->query("user_target")))
    {
        destruct(ob);
		return 1;
    }
    if (living(ob))
    {
        message_vision("$N大喝一声：挡我者死！夺路而去。\n",ob);
        ob->move(place[random(sizeof(place))]);
    }
    if ((me&&!living(me))||!me)
    {
        destruct(ob);
        return 1;
    }
	remove_call_out("moving");
    if (me->query("combat_exp")<100000)
    {   
        call_out("moving",18+random(5));
    }
	else
	{
		call_out("moving",12+random(5));
	}
    return 1;
}

void init()
{
    object ob=this_object();
    object me;
	if (ob->query("user_target"))
	me=find_player(ob->query("user_target"));
	else
	return;
	if (!userp(me))
	{
		return;
	}
    if (present(me,environment()))
    {
        fight_ob(me);
        me->fight_ob(ob);
    }
}

void unconcious()
{
    die();
}

int leave()
{
    this_object()->delete("cantleave");
}

int dest()
{
    object ob=this_object();
    object me;
    if (!ob->query("user_target"))
    {
        destruct(ob);
        return 1;
    }
	if (!me=find_player(ob->query("user_target")))
	{
        destruct(ob);
        return 1;
    }
    if (!ob->is_fighting()&&!ob->is_busy())
    {
        message_vision("$N终于遁走脱狱成功。\n",ob);
		if (me&&me->query_temp("rynewbiejob/prison/start")==2)
		{
			tell_object(me,"唉，"+ob->name()+"已经成功脱离了日月神教的范围。\n你的任务失败了。\n");
			me->delete_temp("rynewbiejob/prison/start");
			me->delete_temp("rynewbiejob/prison/prisoner_come");
			me->delete_temp("rynewbiejob/prison/xl_time");
			me->delete_temp("rynewbiejob/prison/xl_times");
			me->add_temp("rynewbiejob/prison/degree",-1);
		}
        
        destruct(ob);
    }
	else
	{
		remove_call_out("dest");
		call_out("dest",60);
	}
    return 1;
}

void die()
{
    object ob=this_object();
    object me;
    if (!me=find_player(ob->query("user_target")))
    {
        destruct(ob);
        return;
    }
    if (me&&me->query_temp("rynewbiejob/prison/start")==2&&ob->get_damage_origin_object()==me)
    {
        me->delete_temp("rynewbiejob/prison/start");
        me->delete_temp("rynewbiejob/prison/prisoner_come");
        me->delete_temp("rynewbiejob/prison/xl_time");
        me->delete_temp("rynewbiejob/prison/xl_times");
        me->add_temp("rynewbiejob/prison/degree",1);
        tell_object(me,"你杀死了在逃的"+ob->name()+"，可以去狱卒那看看还有什么事。\n");
    }
    me->delete_temp("rynewbiejob/prison/prisoner_come");
    destruct(ob);
    return;
}

int do_copy(object me)
{
	int level,exp;
	int addition = 1;
	int life = 0;

	if(!userp(me))
    {
        destruct(this_object());
		return 0;
    }
	exp = me->query("combat_exp");
    
	level = to_int(pow(exp/100,0.333)*8);
	if (exp<200000)
	{
		level=level*4/5;
	}
    set("combat_exp", me->query("combat_exp")/5*4);
	family_skill(this_object(), "random", level, 1);
	
    set("chat_chance_combat", 150);
	
	life = me->query("max_neili");

	set("max_qi", life);
	set("eff_qi", life);
	set("qi", life);
	set("max_jing", life);
	set("eff_jing", life);
	set("jing", life);
	set("max_jingli", life);
	set("jingli", life);
	set("max_neili", life*3/2);
	set("neili", life*2);

	set("user_target", me->query("id"));
	//wield_weapon();
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

