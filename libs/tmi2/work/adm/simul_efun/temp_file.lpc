// Provides a file to use in conjunction with edit()
// base should be something like  "idea", "describe", "mail"
// Changed by Pallando (93-03-17)

#include <config.h>

varargs string temp_file( string base, object obj )
{
    if( !obj ) obj = this_player();
    return TMP_DIR + base + "-" + getoid( obj );
}
