// hua_busy.c  
#include <login.h>  
int update_condition(object me, int duration) 
{         
        me->apply_condition("hua_busy", duration - 1);         
        if (duration < 1) return 0;
        return 1; 
} 
