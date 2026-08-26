/**
 * /secure/simul_efun/base_name.c from the Nightmare Mudlib.
 * Returns the name of the file of an object without extensions.
 * Based on the simul_efun originally by Truilkan@Basis
 * Created by Descartes of Borg 22 december 1992
 */
#if !efun_defined(base_name)
/**
 * This method returns the name of the file of an object without
 * the # extensions.
 * @param val the ob or string name
 * @return the base name of the object
 */
string base_name( mixed val ) {
    string name, base;

    if( stringp(val) )
        name = val;
    else
        name = file_name(val);

    if( sscanf( name, "%s#%*d", base ) == 2 )
        return base;
    else
        return name;

} /* base_name() */
#endif
