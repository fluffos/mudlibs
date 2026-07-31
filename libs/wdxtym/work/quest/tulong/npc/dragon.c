inherit NPC;
#include <ansi.h>
int big_blowing();

string *tattoo=({
	"clone/tattoo/body1",
	"clone/tattoo/body2",
	"clone/tattoo/body3",
	"clone/tattoo/body4",
	"clone/tattoo/body5",
	"clone/tattoo/body6",
	"clone/tattoo/body7",
	"clone/tattoo/body8",
	"clone/tattoo/body9",
	"clone/tattoo/body10",
});

void create()
{
        set_name(HIR"烈火孽龙"NOR, ({ "dragon" }) );
        set("race", "野兽");
        set("gender", "雄性");
        set("age", 200);
        set("long",
"这是一条全身赤红，吸天地之间的火气而长大的孽龙！它全身散发着赤红色的火焰。\n");

        set("str", 248);
        set("con", 252);
        set("dex", 222);

      set_skill("dodge", 1000);
	  set_skill("parry", 1000);
      set_skill("force", 1000);
      set_skill("unarmed", 1000);
      set_skill("dragon",1000);
      map_skill("unarmed", "dragon");
      map_skill("dodge", "dragon");
		map_skill("parry", "dragon");
		prepare_skill("unarmed", "dragon");

	    set("qi",10000000);
	    set("eff_qi",10000000);
		set("jing",10000000);
		set("eff_jing",10000000);
        set("max_qi", 10000000);
        set("max_jing", 10000000);
        set("max_neili", 10001000);
        set("attitude", "aggressive");
        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("chat_chance_combat", random(30)+10);
        set("chat_msg_combat", ({
		(: perform_action, "unarmed.penhuo" :),
		(: perform_action, "unarmed.tuwu" :),
		(: perform_action, "unarmed.yaoyao" :),
        (: big_blowing :)
        }) );

                set("combat_exp", 100011000+random(6001100));
                set("bellicosity", 30000 );

        set_temp("apply/attack", 1560+random(400));
        set_temp("apply/damage",1500+random(400));
        set_temp("apply/armor", 1500+random(400));

        setup();
}

void init()
{
        object ob=this_object();

        if( interactive (ob) )
        {
        remove_call_out("story_check");
        remove_call_out("check_time");
        }

        if( !ob->query_temp("story_start") )
        {
        call_out("story_check",2);
        ob->set_temp("story_start",1);
        }

        if( !ob->query_temp("check_time") )
        {
        call_out("check_time", 1);
        ob->set_temp("check_time",1);
        }
}

int story_check()
{
        string *story_msg=({}),str;
        int story_msg_len;

        story_msg+= ( {"你们这些愚蠢的人类。\n"});

        story_msg_len=sizeof(story_msg);
        str=story_msg[random(story_msg_len)];

        message("channel:chat",sprintf(MAG"【烈火孽龙】%s" NOR, str),users());
        remove_call_out("story_check");
        call_out("story_check",300);
		call_out("leave",1800);
}

int leave()
{
	object ob = this_object();
	message("channel:chat", HIM"【武林消息】"HIR + "烈火孽龙觉得中原太过无趣便离开了忘忧园！\n"NOR,users() );
	destruct(ob);
}

int big_blowing()
{
remove_call_out("hurting");
message_vision( HIR "\n\n烈火孽龙深深地吸入一口气，全身转为鲜红的火色，整个龙腹胀大了几倍！！\n\n" NOR,
this_object());
call_out("hurting",random(1)+1);


        return 1;
}

int hurting()
{
        int i;
        int dam;
        object *inv;
        message_vision( HIR "\n\n烈火孽龙吐出一股炽可焚金的火焰．．整个天地似乎都被燃烧着！！！\n\n",this_object());
        inv = all_inventory(environment(this_object()));
        for(i=sizeof(inv)-1; i>=0; i--)
        if( living(inv[i]))
        if( inv[i] != this_object())
        {
        dam = random(1000)+1000;
        if(dam <0) dam = 0;
        inv[i]->receive_wound("qi",dam);
        COMBAT_D->report_status(inv[i],1);
        }
        return 1;
}
void die()
{
        object obj,ob;
        object me;

		mapping team;
		int i,size;

		ob = this_object();
		me = ob->query_temp("last_damage_from");
		team = me->query_team();
		size = sizeof(team);
		if( random(50) == 1 )
		{
			obj=new(tattoo[random(10)]);
			obj->move(environment(ob));
		}
        if(objectp(team[i]=query_temp("last_damage_from") ));
        {
            if(!team[i]->query_temp("m_success/孽龙"))
            {

				for(i=0;i<size;i++)
				{
					if(!team[i]) continue;
					if(team[i]->query("boss/dragon")>=50000)
					{
						tell_object(team[i], HIR "\n\n一团火焰猛地升腾，一个声音说道：这两颗龙元就作为谢礼吧！！！\n"NOR);
						message("channel:chat", HBMAG"【屠龙】"+team[i]->query("name")+"成功地杀死了恶龙，得到修为 十五万 潜能 七万\n"NOR,users());
						obj = new("/quest/tulong/obj/drug");
						obj->move(team[i]);
						team[i]->set_temp("m_success/孽龙",1);
						team[i]->delete("boss/dragon");
						team[i]->add("combat_exp",100000);
						team[i]->add("potential",50000);
					}
				}

            }
        }
		destruct(this_object());
        ::die();
}

int receive_damage(string type, int damage, object who)
{

        if (! objectp(who))return 1;
        if (!who->query_temp("m_success/孽龙"))
        {

                who->add("combat_exp", 5 + random(5));
                who->add("potential", 5 + random(5));
        }
		who->add("boss/dragon",damage);
		message_vision("$N累计对孽龙造成"+ who->query("boss/dragon") +"点伤害。\n", who);
        return ::receive_damage(type, damage, who);

}