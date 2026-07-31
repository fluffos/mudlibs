#include <ansi.h>
#include <dbase.h>
#include <login.h>
#include <move.h>
#include <pkla.h>
void cal_parta(object x,object me)
{
        string *my_key;
        my_key = keys(me->query_skills());
        foreach(x in my_key) {
                if( me->query_skill( x, 1 ) > 0 )
                        me->set_skill( x, me->query_skill( x, 1 )-1 );
                else
                        me->delete_skill(x);
        }
        if( me->query("functions" ) ) {
                my_key = keys(me->query("functions") );
                foreach(x in my_key) {
                        if( me->query_function(x) > 0 )
                                me->set_function( x, me->query_function(x)-1 );
                        else
                                me->delete_function(x);
                }
        }
        if( me->query("spells" ) ) {
                my_key = keys(me->query("spells") );
                foreach(x in my_key) {
                        if( me->query_spell(x) > 0 )
                                me->set_spell( x, me->query_spell(x)-1 );
                        else
                                me->delete_spell(x);
                }
        }
        return ;
}
