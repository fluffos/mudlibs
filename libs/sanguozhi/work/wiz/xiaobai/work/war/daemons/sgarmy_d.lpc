// /daemons/sgarmy_d.c
// this is used to handle the armys in sanguo
// an army for each city at war time, and an army
// includes several troops
// by xiaobai, August 2001

#include <sgarmy.h>
#include <mudlib.h>
#include <security.h>

inherit M_ACCESS;

private mapping p_armies=([]);
private class SGarmy p_army;
private int p_maxid=1;

nosave protected int save_mark;

#define SAVE_FILE "/data/daemons/sgarmy"

////////// functions /////////

//
void create()

// whether an id is valid, 1 for yes, 0 for no
int id_valid( int par_nId );

// 查一下 army 是否好的，好的话返回 0
int illegal_army( int par_nId );

// 存起所有数据
void save_data();

// 每3秒检查一次，恢复能量，npc 部队动作
void army_heart();

// 产生一个新的 army
int new_army_id( class SGarmy par_armyPlan );

// 获取某方面军的整个数据
SGarmy get_army( int par_nId );

// 战场所在
string get_wararea( int par_nId );

// 转换所属城市
string set_city( int par_nId, string par_strCity );
string get_city( int par_nId );

// 方面军的名字，国家城市名部份
string get_name_prefix( int par_nId )

// 方面军的名字，由国家城市名组成
string get_name( int par_nId );

// get side
string get_side( int par_nId )

// add a troop to an army
int add_troop( int par_nArmyId );

// remove a troop from an army
int remove_troop( int par_nArmyId, int par_nTroopId );

// remove an army
void remove_army( int par_nId );

void clear_all();

void remove(); 

int clean_up(); 

// don't call this until you know what you are going to do
int force_clear();

////////////////// implemetation //////////////////////////

void create()
{
    unguarded(1, (: restore_object, SAVE_FILE, 1 :));
    call_out("army_heart",5);
    
    return;

}  // end create

int id_valid( int par_nId )
{
    int* keys;
    
    if ( !p_armies )
        return 0;
    
    keys = keys( p_armies );
    
    if ( member_array( par_nId, keys ) < 0 )
        return 0;
    else
        return 1;
    
}  // end id_valid

int illegal_army( int par_nId )
{
	int task_id,*t;
  	object o,env;

	if( !id_valid( par_nId ) )
	    return 1;
	else
	    p_army = p_armies[par_nId];
		    
	if(( p_army->m_strSide != "a" )&&( p_army->m_strSide ! = "d" ))
	    return 1;
	
	task_id = p_army->m_nTaskId;
	
	if(p_side=="a")
		t=TASK_D->get_task(task_id,"att_army");
	else
		t=TASK_D->get_task(task_id,"def_army");

	if( !t )
	    t=({});

	if( member_array( par_id, t ) == -1 )
	    return 2;

	return 0;
}

void save_data()
{
    save_mark++;
    if((save_mark<0)||(save_mark>20))
    {
        save_mark=0;
        unguarded(1, (: save_object, SAVE_FILE :));
    }
}

void army_heart()
{
	int* keys;
    int nTrpId;

	remove_call_out("army_heart");
    call_out("army_heart",3);

    keys=keys( p_armies );
    
    // deal with each army
	foreach(int nArmyId in keys)
	{
		if(illegal_army(nArmyId))
		{	
			remove_army( nArmyId );
			continue;
		}

		p_army = find_army( nArmyId );
		
		foreach( nTrpId in p_army->m_nTrpIdArr )
		{
		    TROOP_D->recover_energy( nTrpId );

    		if( TROOP_D->is_npc( nTrpId ) )
            {
//                int task_id=troops[p_id]["task_id"];
//                if (!task_id) return;
                WARAI_D->auto_action( nTrpId );
                if (TASK_D->get_task( p_army->m_nTaskId, "type" ) == TT_WAR )
                   if ( p_army->m_strSide == "d" )
                       WARAI_D->auto_jimou( nTrpId );
            }		    			    
		}
		//if((troops[p_id]["side"]=="a")&&(random(2)==0))
		//	add_morale(p_id,-1); // this work moved into the recover_energy
	
	}  // end loop, for all armies
	
    save_data();
    
    TROOP_D->save_data();

}  // end army_heart()

int new_army_id( class SGarmy par_armyPlan )
{
    int *list;
    int nId = 0;
    class SGarmy armyNew = new(class SGarmy);

    if( !p_armies )
        p_armies = ([]);

    list=keys( p_armies );
    p_maxid++;
	
	if(p_maxid>1000)
	    p_maxid=1;

    while(member_array(p_maxid,list)!=-1)
        p_maxid++;
    
    armyNew->m_nArmyId = p_maxid;
    armyNew->m_strNationId = par_armyPlan->m_strNationId;
    armyNew->m_strCityId = par_armyPlan->m_strCityId;
    armyNew->m_strLeader = par_armyPlan->m_strLeader;
    armyNew->m_strSide = par_armyPlan->m_strSide; 
    
    // xiaobai: 显示颜色，钱粮暂无
    
    armyNew->m_nCntTroop = 0;
    armyNew->m_mTrpIds = ([]);
    
    p_armies[p_maxid] = armyNew;
       
    return p_maxid;         
        
}  // end new_army_id

// 获取某方面军的整个数据
SGarmy get_army( int par_nId )
{
    if ( !id_valid( par_nId ) )
        return NULL;
    else
        return p_armies[par_nId];
  
}  // end get_army

// 战场所在
string get_wararea( int par_nId )
{
    if ( !id_valid( par_nId ) )
        return "";
    
    p_army = p_armies[par_nId];
    
    return TASK_D->get_task( p_army->m_nTaskId, "area" );
    
}  // end get_wararea

// 转换所属城市
string set_city( int par_nId, string par_strCity )
{
    if ( !id_valid( par_nId ) )
        return "";
    
    p_army = p_armies[par_nId];
    
    p_army->m_strCity = par_strCity;
    
    return p_army->m_strCity;

}  // end set_city

string get_city( int par_nId )
{
    if ( !id_valid( par_nId ) )
        return "";
    
    p_army = p_armies[par_nId];

    return p_army->m_strCity;

}  // end get_city

string get_name_prefix( int par_nId )
{
	string strNationName;
	string strCityName;
	string strRet = "";

    if ( !id_valid( par_nId ) )
        return "";

    p_army = p_armies[par_nId];

	strNationName = COUNTRY_D->get_country( p_army->m_strNationId, "name" );
	strCityName = AREA_D->get_area( p_army->m_strCityId, "name" );

    sprintf( strRet,"%s%s", strNationName, strCityName );
	
	return p_ret;
	
}  // end get_name_prefix

string get_name( int par_nId )
{
	string strNationName;
	string strCityName;
	string strRet = "";

    if ( !id_valid( par_nId ) )
        return "";

    p_army = p_armies[par_nId];

	strNationName = COUNTRY_D->get_country( p_army->m_strNationId, "name" );
	strCityName = AREA_D->get_area( p_army->m_strCityId, "name" );

    sprintf( strRet,"%s%s%s", strNationName, strCityName, "方面军" );
	
	return p_ret;
	
}  // end get_name

string get_side( int par_nId )
{
    if ( !id_valid( par_nId ) )
        return "";

    p_army = p_armies[par_nId];
                
    return p_army->m_strSide;

}  // end get_side

// add a troop to an army
int add_troop( int par_nArmyId )
{
    int nRet = 0;
    
    if ( !id_valid( par_nId ) )
        return 0;
        
    p_army = p_armies[par_nId];
    
    nRet = TROOP_D->new_troop_id( par_nArmyId );
    
    if ( nRet >  0 )
    {
        // got a valid new troop id
        p_army->m_nCntTroop++;
        p_army->m_nTrpIdArr += ({nRet});
    }
    
    return nRet;
    
}  // end add_troop

// remove a troop from an army
int remove_troop( int par_nArmyId, int par_nTroopId )
{
    if ( !id_valid( par_nId ) )
        return 0;
        
    p_army = p_armies[par_nId];

    if ( member_arry( par_nTroopId, p_army->m_nTrpIdArr ) == -1 )
    {
        // the troop is not in this army
        return 0;        
    }
    else    
    {
        p_army->m_nTrpIdArr -= ({par_nTroopId});
        p_army->m_nCntTroop--;
        
        TROOP_D->remove_troop( par_nTroopId );
    }
    
    return 1;    
    
}  // end remove_troop

void remove_army( int par_nId )
{
    if ( !id_valid( par_nId ) )
        return;
        
    p_army = p_armies[par_nId];
    
    // remove all troops of the army
    foreach( int nTrpId in p_army->m_nTrpIdArr )
    {
        remove_troop( par_nId, nTrpId );
    }    
	
	map_delete( p_armies, par_nId );

}  // remove army

void clear_all()
{
	int* keys;
	int i,sum;
	
	keys = keys( p_armies );
	sum = sizeof(keys);
	
	for( i=0; i<sum; ++i )
	{
		remove_army( keys[i] );
	}	

}  // end clear_all

void remove() 
{
	save_mark=20;
	save_data();

}  // end remove

int clean_up() 
{
   return 0; // means never_again

}  // end clean_up

// don't call this until you know what you are going to do
int force_clear()
{
	p_armies = ([]);
	save_data();
	return 1;

}  // end force_clear

////////////////////////////// EOF ////////////////////////////////