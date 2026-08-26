/*
        Bandit Tabard effect.
        Wrytten by Drakkos Thee Creator.
        2/23/2000
*/

#include "path.h"        
#include <effect.h>


string query_classification() 
{ 
        return "other.clothing.bandit_tabard"; 
}


string query_shadow_ob() 
{ 
        return "/std/shadows/attached/tabard_shad"; 
}


void beginning( object player ) 
{
        player->submit_ee( "test_worn", 30, EE_CONTINUOUS );
} 


void merge_effect( object player ) 
{ 
        return; 
}


void end( object player ) 
{

} /* end() */


int check_effect( object thing ) 
{
        if (!thing)
        {
                return 0;
        }
        
        return member_array(file_name( this_object()),
         (string *)thing->query_wear_effects() ) != -1;
} 


void test_worn( object player ) 
{
        
        if (player->still_auto_loading())
        {
                return;
        }

        
        if ( !sizeof( filter_array( (object *)player->query_armours(),
                "check_effect", this_object() ) ) ) 
        {
                player->submit_ee( 0, 0, EE_REMOVE );
                return;
        }
} 

