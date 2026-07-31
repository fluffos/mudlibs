 // bandaged.c
inherit __DIR__"generic_condition";
#include <ansi.h>
#include <condition.h>  
inherit F_CLEAN_UP; 
int update_condition(object me, int duration)
{
        if( (int)me->query("eff_kee") < (int)me->query("max_kee") )
                me->receive_curing("kee", 3);
        
        me->apply_condition("bandaged", duration - 1);
        if( !duration ) return 0; 
        return CND_CONTINUE;
} 
int condition_type()
{
// in condition.h
/* 
#define NO_CURE                 10
#define NON_POISON              9
#define BLOOD_POISON            8
#define NERVE_POISON            7
#define BRAIN_POISON            6
#define OBSCENE_POISON          5
#define GENERIC                 0 
*/ 
        return NO_CURE;
}     
