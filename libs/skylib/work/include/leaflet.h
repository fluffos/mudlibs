/**
 * This contains some defines for the leaflet system.
 * @author Sandoz, 2002.
 */

/**
 * This class stores the data for ordered printouts.
 * @member the id of the printer that is printing the leaflet
 * @member time the collection time
 * @member number the number of copies we need
 * @member lang the language to copy into
 * @member file the base name of the thing we're copying
 * @member num the number of the auto load save file
 * @member save the auto load arrays of the leaflet
 * @member new_leaflet this means the leaflet is brand
 * new and no-one else has printed it before
 */
class print_data {
    int id;
    int time;
    int number;
    string lang;
    string file;
    mixed save;
    int new_leaflet;
}
