#include <ansi.h>

int errs( string msg )
{
if( !msg ) 
        return 0;
write(CYN+msg+NOR);
return 1;
}

