#include <ansi.h>

inherit NPC;
//inherit F_CLEAN_UP;

string *first_name = ({ "大头", "青面", "独角", "红发"});
string *name_words = ({ "鬼"});
int random_go(object me, string* dirs);

void create()
{
	string name;
        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))];
        set_name(name, ({"ghost"}));
        set("gender", "男性" );
	set("age", 30+random(20));
	set("class", "youling");
	set("env/invisibility", 1);
	set("title", RED "(鬼气)" NOR);
        set("combat_exp", 3000);
	set("daoxing", 5000);
	set("attitude", "heroism");
        set_skill("force", 250);
        set_skill("parry", 250);
        set_skill("unarmed", 250);
        set_skill("staff", 250);
        set_skill("lunhui-zhang",250);
        set_skill("jienan-zhi",250);
        set_skill("lotusmove",250);
        set_skill("spells",250);
        set_skill("buddhism", 250);
        map_skill("staff","lunhui-zhang");
        map_skill("unarmed","jienan-zhi");
        map_skill("spells","buddhism");
        map_skill("dodge","lotusmove");
        setup();
        carry_object(__DIR__"obj/tc_staff")->wear();
}

void copy_status(object me,object ob, string* dirs)
{
        mapping skill_status,map_status;
        string *sname,*mname;
        int i;


        skill_status=me->query_skills();
        sname=keys(skill_status);
        for(i=0;i<sizeof(skill_status);i++) {
                me->delete_skill(sname[i]);
        }
        skill_status=ob->query_skills();
        sname=keys(skill_status);
        for(i=0;i<sizeof(skill_status);i++) {
                me->set_skill(sname[i],skill_status[sname[i]]);
        }
        if ( mapp(map_status = me->query_skill_map()) ) {
                mname  = keys(map_status);

                for(i=0; i<sizeof(map_status); i++) {
                        me->map_skill(mname[i]);
                }
        }

        map_status = ob->query_skill_map();
        mname  = keys(map_status);

        for(i=0; i<sizeof(map_status); i++) {
                me->map_skill(mname[i], map_status[mname[i]]);
        }

        me->set("str",ob->query("str"));
        me->set("int",ob->query("int"));
        me->set("con",ob->query("con"));
        me->set("per",ob->query("per"));
        me->set("cor",ob->query("cor"));
        me->set("spi",ob->query("spi"));
        me->set("cps",ob->query("cps"));
        me->set("kar",ob->query("kar"));
        me->set("max_kee",ob->query("max_kee"));
        me->set("eff_kee",ob->query("eff_kee"));
        me->set("kee",ob->query("kee"));

        me->set("max_gin",ob->query("max_gin"));
        me->set("eff_gin",ob->query("eff_gin"));
        me->set("gin",ob->query("gin"));

        me->set("max_sen",ob->query("max_sen"));
        me->set("eff_sen",ob->query("eff_sen"));
        me->set("sen",ob->query("sen"));

        me->set("max_force",ob->query("max_force"));
        me->set("force",ob->query("force"));
        me->set("force_factor",ob->query("max_force")/20);

        me->set("max_mana",ob->query("max_mana"));
        me->set("mana",ob->query("mana"));
        me->set("mana_factor",ob->query("max_mana")/20);

        me->set("combat_exp",ob->query("combat_exp")*15/10);
	me->set("daoxing",ob->query("daoxing")*15/10);
	me->set("stay_time", time());

	random_go(me, dirs);


}

int random_go(object me, string* dirs)
{
        int             i, j, k;
        object  newob;
        mixed*  file;

        if( !sizeof(dirs) )  return 1;

    i = random(sizeof(dirs));    // pick up one directory

        file = get_dir( dirs[i]+"*.c", -1 );
        if( !sizeof(file) )             return 1;

        k = sizeof(file);
        while(1)  {
           j = random(k);
           if( file[j][1] > 0 )         break;          // pick up a file with size > 0
        }

    if( (newob=find_object(dirs[i]+file[j][0])) )   {
                me->move( newob ); 
        }
        else  {
                seteuid(getuid(me));
                newob = new(dirs[i]+file[j][0]);
                if (newob)   // now this is not necessary, only for debug use
                        me->move(newob);
        else  {
                        tell_object(me, "Error.\n");
                }
        }

        return 1;
}

int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}

void leave()
{
	object owner;
	message("vision",
		HIY + name() + "说道：现在我已经完成护卫任务，就此告辞！\n\n"
		+ name() + "化为一道金光，消失不见了。\n" NOR, environment(),
		this_object() );
	destruct(this_object());
}

void invocation(object who, string* dirs)
{       object me=this_object();
        copy_status(me,who, dirs);
        set("owner", who->query("id"));
        set("owner_ob", who);
}