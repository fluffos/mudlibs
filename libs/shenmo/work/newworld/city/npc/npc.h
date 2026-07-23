//npc.h

void die()
{
int exp,lvl,pot,up,i,j,k;
mapping skills;
object obj;
object ob = this_object();
object me=ob->query_temp("last_damage_from");
obj=new(ob->query("obj"));
skills = me->query_skills();

if ( random(ob->query("persent"))==1 )
	{
	obj->move(environment(ob));
	message_vision(HIY"$N掉下了一"+obj->query("suit")+obj->name()+HIY"。\n"NOR,ob);
	}
me->start_busy(3);

exp = (int)ob->query("exp");
lvl = (int)me->query("level");
up=me->query("potential");
exp=exp/(1+lvl);
if ( exp<1 ) exp=1;
i=sizeof(skills);
pot = exp/4+random(exp/4);
me->add("combat_exp",exp);
me->add("potential",pot);
tell_object(me,HIY+ob->name()+HIY"死了，你赢得了"+chinese_number(exp)+"点武学经验和"+chinese_number(pot)+"潜能。\n"NOR);

/*
if ( i>0 )
	{
	k=exp/i;
	if( k<1) k=1;
        for( j=1;j<i;j++)
		me->improve_skill(skills[j],k);
	tell_object(me,HIY"你共学得"+chinese_number(i)+HIY"种技能，平均各加"+chinese_number(k)+HIY"点经验。\n"NOR);
	}
*/

if ( lvl<5 )
	{
	if ( up>=lvl*100 )
		{
		me->add("level",1);
		me->set("potential",0);
                message_vision(HIW"\n
━━━━━━━━━━ＬＥＶＥＬ　ＵＰ━━━━━━━━━━"HIY"\n
			$N升级了！\n"NOR,me);
		}

	}
else if ( lvl<10 )
	{
	if ( up>=lvl*500 )
		{
		me->add("level",1);
		me->set("potential",0);
                message_vision(HIW"\n
━━━━━━━━━━ＬＥＶＥＬ　ＵＰ━━━━━━━━━━"HIY"\n
			$N升级了！\n"NOR,me);
		}
	}
else if ( lvl<15 )
	{
	if ( up>=lvl*1000 )
		{
		me->add("level",1);
		me->set("potential",0);
                message_vision(HIW"\n
━━━━━━━━━━ＬＥＶＥＬ　ＵＰ━━━━━━━━━━"HIY"\n
			$N升级了！\n"NOR,me);
		}
	}
else if ( lvl<20 )
	{
	if ( up>=lvl*2000 )
		{
		me->add("level",1);
		me->set("potential",0);
                message_vision(HIW"\n
━━━━━━━━━━ＬＥＶＥＬ　ＵＰ━━━━━━━━━━"HIY"\n
			$N升级了！\n"NOR,me);
		}
	}
else if ( lvl<25 )
	{
	if ( up>=lvl*5000 )
		{
		me->add("level",1);
		me->set("potential",0);
                message_vision(HIW"\n
━━━━━━━━━━ＬＥＶＥＬ　ＵＰ━━━━━━━━━━"HIY"\n
			$N升级了！\n"NOR,me);
		}
	}
else if ( lvl<30 )
	{
	if ( up>=lvl*10000 )
		{
		me->add("level",1);
		me->set("potential",0);
                message_vision(HIW"\n
━━━━━━━━━━ＬＥＶＥＬ　ＵＰ━━━━━━━━━━"HIY"\n
			$N升级了！\n"NOR,me);
		}
	}
else 	{
	if ( up>=lvl*50000 )
		{
		me->add("level",1);
		me->set("potential",0);
                message_vision(HIW"\n
━━━━━━━━━━ＬＥＶＥＬ　ＵＰ━━━━━━━━━━"HIY"\n
			$N升级了！\n"NOR,me);
		}
	}
destruct(ob);
me->save();
}

