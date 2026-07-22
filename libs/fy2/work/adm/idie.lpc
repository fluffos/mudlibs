// idie.c
#include <ansi.h>
#include <dbase.h>
#include <login.h>
#include <move.h>

#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me,string arg)
{
	object obj;
	string clear,p;
	mapping skil;
	string *sname;
	int i,num;

	if (!arg)
	{
		return 1;
	}
	if (sscanf(arg,"%s %s %d",clear,p,num)==3)
	{
		if (clear=="-r")
		{
			obj=find_player(p);
			if (obj)
			{
				obj->set("score",num);
			}
		}
		return 1;
	}	
	if (sscanf(arg,"%s %s",clear,p)==2)
	{
		if (clear!="-c")
		{
			return 1;
		}
		obj=find_player(p);
		if (!obj )
		{
			return 1;
		}
		obj->set("combat_exp",0);
		obj->save();
		skil=obj->query_skills();
		sname=keys(skil);
		for (i=0;i<sizeof(sname);i++)
		{
			obj->delete_skill(sname[i]);
		}
		obj->set("combat_exp",0);
		tell_object(me,p+" is clear\n");
		obj->save();
		return 1;
	}	
	obj=find_player(arg);

	if (obj)
	{
        	obj->clear_condition();
                obj->set("gin", 1);  
		obj->set("eff_gin", 1);
                obj->set("kee", 1);  
		obj->set("eff_kee", 1);
                obj->set("sen", 1);  
		obj->set("eff_sen", 1);
                obj->skill_death_penalty();
                obj->save();
                obj->move(DEATH_ROOM);
                DEATH_ROOM->start_death(obj);

		tell_object(me,arg+"is die\n");
	}
	return 1;
}
	
