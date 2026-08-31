#include "/obj/lw.h"

#define HOME		"/players/shadowmonk/"
#define TP     		this_player()
#define TO     		this_object()

#define NAME    	query_name()
#define RNAME   	query_real_name()
#define SNAME		query_short_name()
#define LEVEL   	query_level()
#define STR        	query_str()
#define INT        	query_int()
#define WIS        	query_wis()
#define DEX        	query_dex()
#define CON        	query_con()
#define CHR        	query_chr()
#define GLD             query_guild()
#define QPRO		query_pronoun()    // he/she/it
#define QPOS		query_possessive() // his/her/its
#define QOBJ		query_objective()  // him/her/it
#define SP         	query_sp()
#define MAXSP      	query_max_sp()
#define HP         	query_hp()
#define MAXHP      	query_max_hp()

#define ADDSP(x)   	restore_spell_points(x)
#define ADDHP(x)   	reduce_hit_point(-(x))
#define HIT(x)     	hit_player(x)   //  reduce hit points

#define TPN		TP->RNAME
#define TPCN		CAP(TP->RNAME)
#define CNM(x) 		CAP( x->RNAME)

#define CAP		capitalize
#define ENV		environment

#define CM(x)   	move_object(clone_object(x),this_object())
#define CLONE		clone_object
#define MOVE		move_object
#define FP      	find_player

#define TTP(x)		writelwnl(x)
#define TTPN(x)		writelw(x)
#define TOP(x,y)	say(lwnl(x), y)  
#define TOPN(x,y)	say(lw(x), y)  
#define TAL(x)          tell_room(TO, lwnl(x))
#define TALN(x)         tell_room(TO, lw(x))
#define TOB(x,y)	tell_object(y, lwnl(x))
#define TOBN(x,y)	tell_object(y, lw(x))
#define TME(x) 		tell_object( find_player( "shadowmonk" ), lwnl(x) )
#define TMEN(x)		tell_object( find_player( "shadowmonk" ), lw(x) )
#define TENV(x)         tell_room(environment(), lwnl(x))
#define TENVN(x)	tell_room(environment(), lw(x))
#define TRM(x,y)	tell_room(y, lwnl(x))
#define TRMN(x,y)	tell_room(y, lw(x))

varargs void TELL( object main0, string str0, string str2, object main1, string str1 ) {
    int     i;
    object *env;
    if( !main0 || !str0 || !str2 )
        return;
    if( !objectp( main0 ) || !stringp( str0 ) || !stringp( str2 ) )
        return;
    if( !objectp( ENV( main0 ) ) )
        return;
    env = all_inventory( ENV( main0 ) ); 
    TOB( str0, main0 );
    if( !main1 ) {
        main1 = main0;
        str1 = "";
    }
    else TOB( str1, main1 );
    for( i=sizeof( env )-1; i>=0; i-- )
        if( env[i] != main0 && env[i] != main1 && living( env[i] ) )
            TOB( str2, env[i] );
}
