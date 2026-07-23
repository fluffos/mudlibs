//lianhua.h

string *names=({ 
	HIY"静心莲花"NOR,"jingxin",
	HIW"如意莲花"NOR,"ruyi",
	HIY"金身莲花"NOR,"jinshen",
	WHT"孤禅莲花"NOR,"guchan",
	RED"涅磐莲花"NOR,"niepan",
});

void randomName()
{
string name,id,*ids;
int i = random(sizeof(names)/2)*2;
name = names[i];
id = names[i+1];
ids = ({id+" lianhua","lianhua","hua"});
this_object()->set_name(name,ids);
}

void check_owner()
{
object ob = this_object();
object env = environment();
if ( !userp(env) )
	{
	write("\n"+this_object()->name()+HIY"化作一道金光冲天而去。\n\n"NOR);
	destruct(ob);
	}
return;
}

int init()
{
	check_owner();
	add_action("do_wear","wear");
	add_action("do_remove", "remove");
}

int do_wear (string arg)
{
object me = this_player();
object jia = this_object();
string name = jia->query("name");
string msg;

if ( !present(jia,me) )				//不在身上 
	return 0;
if ( arg!="all" && !id(arg) )			//不是穿此
	return 0;
if ( query("equipped") || query("use")==1 )	//已穿此
	return 0;
if ( me->query_temp("armor/"+jia->query("armor_type")) )	//同类型已穿
	return 0;

msg = "$N背后现出一朵$n护住了$P的妙严肉身。\n";
jia->set("wear_msg",msg);
jia->set("use",1);
remove_call_out("jia_condition");
call_out("jia_condition",1,me,jia);
return 0;
}

int do_remove (string arg)
{
object me = this_player();
object jia = this_object();
string msg;

if ( !present(jia,me) )
	return 0;

if ( arg!= "all" && !id(arg) )
	return 0;

if ( !query("equipped") || query("use")==0 )
	return 0;

msg = "$N低诵我佛，$n随风碎成片片花瓣。\n"NOR;
jia->set("unequip_msg",msg);
jia->set("use",0);
remove_call_out("jia_condition");
return 0;
}

void jia_condition(object me,object ob)
{
string msg;
int i=(int)me->query_skill("spells");
i = i/2+random(i*2/3);
if ( i>800 ) i = 800;
if ( query("use")!=1 )
	return;
if ( COMBAT_D->check_class(me)=="xian" )  i*= 3;

if ( me->query_temp("armor/"+ob->query("armor_type"))!=ob )
	{
	ob->set("use",0);
	return;
	}

switch( query("addType") )
	{
	case "kee" :
		if ( me->query("kee")<me->query("max_kee") )
			{
			msg=HIG"$n"HIG"在$N"HIG"身后隐隐约约摆动，$P立刻觉得气血充沛起来！\n"NOR;
			message_vision(msg,me,ob);
			me->add("kee",i);
			if ( me->query("kee")>me->query("max_kee") )   me->set("kee",(int)me->query("max_kee") );
			}
		if ( me->query("eff_kee")<me->query("max_kee") )
			{
			msg=HIW"$n"HIW"在$N"HIW"身后隐隐约约摆动，$P立刻觉得气血充沛起来！\n"NOR;
			message_vision(msg,me,ob);
			me->add("eff_kee",i/2);
			if ( me->query("eff_kee")>me->query("max_kee") )   me->set("eff_kee",(int)me->query("max_kee") );
			}
		break;

	case "sen" :
			if ( me->query("sen")<me->query("max_sen") )
			{
			msg=HIG"$n"HIG"在$N"HIG"身后隐隐约约摆动，$P精神一振！\n"NOR;
			message_vision(msg,me,ob);
			me->add("sen",i);
			if ( me->query("sen")>me->query("max_sen") )   me->set("sen",(int)me->query("max_sen") );
			}
			if ( me->query("eff_sen")<me->query("max_sen") )
			{
			msg=HIW"$n"HIW"在$N"HIW"身后隐隐约约摆动，$P精神一振！\n"NOR;
			message_vision(msg,me,ob);
			me->add("eff_sen",i/2);
			if ( me->query("eff_sen")>me->query("max_sen") )   me->set("eff_sen",(int)me->query("max_sen") );
			}
		break;

	case "force" :
			if ( (int)me->query("force")/2<(int)me->query("max_force") )
			{
			msg=WHT"$n"WHT"在$N"WHT"身后隐隐约约摆动，$P顿时觉得内力充沛起来！\n"NOR;
			message_vision(msg,me,ob);
			me->add("force",i);
			if ( (int)me->query("force")/2 > (int)me->query("max_force") )
				me->set("force",(int)me->query("max_force")*2 );
			}
		break;

	case "mana" :
			if ( (int)me->query("mana")/2<(int)me->query("max_mana") )
			{
			msg=HIC"$n"HIC"在$N"HIC"身后隐隐约约摆动，$P顿时觉得法力充沛起来！\n"NOR;
			message_vision(msg,me,ob);
			me->add("mana",i);
			if ( (int)me->query("mana")/2>(int)me->query("max_mana") )
				me->set("mana",(int)me->query("max_mana")*2 );
			}
		break;
	}

i = me->query_skill("spells",1);
i/= 100;
if ( i<1 ) i=1;
if ( i>10 ) i=10;
i = 11-i;
remove_call_out("jia_condition");
call_out("jia_condition",i,me,ob);
}
