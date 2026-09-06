/** This object tracks the statistics on any object that can be forged, built,
 * constructed, assembled, devised, or otherwise created within the game rules.
 * It contains information like material requirements and building time.
 *
 * Each entry in the catalog is indexed by the name of the unit. Here is a
 * rough layout of the formatting:
 *
 * ([ name: ({ filename, unit_type, requirements ... }), ... ])
 *
 * \a filename is the file which should be cloned to create this unit. It
 * may refer to either a .c or a .o file.
 *
 * \a unit_type is an integer which acts as a typing variable for this
 * unit. If UNIT_BUILDING were 2, then the 'build' command could check
 * that the item's type is 2 before allowing you to build it.
 *
 * \a requirements fill out the remainder of the array. Each requirement
 * is a string, of the format "name:amount". Generally, \a name gives the
 * resource type, and \a amount is an integer (in string base 10 representation)
 * giving the amount of that resource necessary to build the object.
 * There is one special requirement, "time", given in seconds. For
 * example, "time:30" means the object requires 30 seconds to build
 * (30 minutes of game time).
 */

/// The mapping containing the catalog.
mapping catalog;

/** Initializes the catalog, loading it from disk if one has been made before.
 */
void create() {
   catalog = ([ ]);
   if( file_exists("/data/catalog.o") )
      restore_object("/data/catalog");
}

/** Allows object editors to manipulate this object.
 */
string catalog_info() {
   return "catalog";
}

/** \return The entire catalog mapping. Please do not modify the return value directly.
 */
mapping query_catalog() {
   return catalog;
}

/** Allows you to set the entire catalog at once. This function has a single safeguard,
 * in that it only allows you to pass in mappings; however, it is still possible to
 * cause a lot of damage by passing in a bogus catalog to this function.
 */
int set_catalog( mapping m ) {
   if( mappingp(m) ) catalog = m;
   else return 0;
   save_object("/data/catalog");
   return 1;
}
