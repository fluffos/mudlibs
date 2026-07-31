// line.c

#include <command.h>
#include <dbase.h>
#include <origin.h>

nosave object lineup_leader, *lineup;
nosave string lineup_form;

int set_form(string form)
{
	lineup_form = form;
	return 1;
}

string query_form()
{
	return lineup_form;
}

int delete_form()
{
	lineup_form = 0;
}

int set_lineup_leader(object ob)
{
    if( ob==this_object() )
        error("set_leader: Cannot set this_object() as leader.\n");
    lineup_leader = ob;
}

object query_lineup_leader() 
{ 
	return lineup_leader; 
}

int delete_lineup_leader()
{
	lineup_leader=0;
}

int add_lineup_member(object ob)
{
    if( ob==this_object() )
    	return 0;

    if( arrayp(lineup) ) 
    {
        if( member_array(ob, lineup)==-1 ) 
        {
            for(int i=sizeof(lineup)-1; i>=0; i--)
            {
            	if( lineup[i] )
            	{
                	lineup[i]->remove_lineup_effect();
                }
            }

            lineup -= ({ 0 });
            lineup += ({ ob });

            for(int i=sizeof(lineup)-1; i>=0; i--)
            {
            	if( lineup[i] )
            	{
                	lineup[i]->set_lineup(lineup);
                }
            }

            for(int i=sizeof(lineup)-1; i>=0; i--)
            {
            	if( lineup[i] )
            	{
                	lineup[i]->apply_lineup_effect();
                }
            }

        } 
        else
		{
			error( "Add lineup member twice.\n" );
            return 0;
		}
    } 
    else 
    {
    	lineup = ({ this_object(), ob });
        ob->set_lineup(lineup);
        this_object()->apply_lineup_effect();
        ob->apply_lineup_effect();
    }
    return 1;
}

int is_lineup_leader()
{
    return arrayp(lineup) && lineup[0]==this_object();
}

int set_lineup(object *t)
{
    lineup = t;
}

varargs int dismiss_lineup(object ob)
{
    int i;

    if( !arrayp(lineup) ) 
    {
    	lineup_form = 0;
    	return 0;
    }
        
    if( !ob ) 
    {
        if( lineup[0]==this_object() ) 
        {
            for(i=sizeof(lineup)-1; i>=0; i--)
            {
            	if( lineup[i] )
            	{
                	lineup[i]->remove_lineup_effect();
                }
            }

            lineup -= ({ 0 });
            for(i=1; i<sizeof(lineup); i++)
            {
            	if( lineup[i] )
            	{
                	lineup[i]->set_lineup(0);
                	lineup[i]->delete_form();
                }
            }
        } 
        else 
        {
            for(i=sizeof(lineup)-1; i>=0; i--)
            {
            	if( lineup[i] )
            	{
                	lineup[i]->remove_lineup_effect();
                }
            }
            
            lineup -= ({ 0 });
            for(i=0; i<sizeof(lineup); i++)
            {
            	if( lineup[i] )
            	{
                	lineup[i]->dismiss_lineup( this_object() );
                }
            }

            for(i=sizeof(lineup)-1; i>=0; i--)
            {
            	if( lineup[i] )
            	{
                	lineup[i]->apply_lineup_effect();
                }
            }
        }
        lineup = 0;
        lineup_form = 0;
    } 
    else
    {
        lineup -= ({ ob });
    }

    return 1;
}

object *query_lineup()
{
    return lineup;
}


int remove_lineup_effect()
{
	object me = this_object();
	
	if( !me )
		return 0;
	
	me->add_temp("apply/attack",- me->query_temp("lineup/apply"));
	me->add_temp("apply/dodge",- me->query_temp("lineup/apply"));
	me->delete_temp("lineup/apply");
    
    return 1;
}

int apply_lineup_effect()
{
	int apply;
	int skill,min_skill;
	int leader_skill;
	int i;
	object me = this_object();
	
	if( !me )
		return 0;

	if( !lineup[0] )
		return 0;
		
	min_skill=lineup[0]->query_skill(lineup_form,1);
	leader_skill = ( lineup[0] )->query_skill(lineup_form,1);

	
	if( query_temp("lineup/apply") )
		error( "Apply lineup effect twice.\n" );

	if( !arrayp(lineup) || sizeof(lineup) == 1 )
		return 0;
	
	for(i=0;i<sizeof(lineup);i++)
	{
		if( lineup[i] )
		{
			if( ( lineup[i]->query_skill(lineup_form,1) )<min_skill)
			{
				min_skill = lineup[i]->query_skill(lineup_form,1);
			}
		}
	}
	skill = me->query_skill(lineup_form,1);
	
	apply = ( skill / 4 + leader_skill / 2 + min_skill ) * ( sizeof(lineup) + 3 );
	if( sizeof(lineup) == SKILL_D(lineup_form)->query_limit() )
		apply = apply * 3;
		
	apply = apply / 40;
	
	if( sizeof(lineup)==1 )
		apply = 0;

    add_temp("apply/attack", apply);
    add_temp("apply/dodge", apply);
    set_temp("lineup/apply",apply);
    
    return 1;
}
