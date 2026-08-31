#include <simul_efun.h>

/**
 * Returns the data directory path for the specified object.
 *
 * @param {object} ob - The object to get the data directory for.
 * @returns {string} The data directory path for the object.
 */
string object_data_directory(object ob) {
    string source_dir = query_directory(ob);
    string save_dir;

    save_dir = mud_config("OBJECT_DATA_DIR") + source_dir[1..];

    return save_dir;
}

/**
 * Returns the data file path for the specified object.
 *
 * @param {object} ob - The object to get the data file for.
 * @returns {string} The data file path for the object.
 */
string object_data_file(object ob) {
    string source_dir = object_data_directory(ob);
    string source_file = query_file_name(ob);
    string save_file;

    save_file = source_dir + source_file;

    return save_file;
}

/**
 * Ensures the data directory for the specified object exists,
 * creating it if necessary.
 *
 * @param {object} ob - The object to ensure the data directory for.
 * @returns {string} The data directory path for the object, or 0 if creation
 *                     failed.
 */
string assure_object_data_dir(object ob) {
    string dir = object_data_directory(ob);

    if(directory_exists(dir))
        return dir;

    assure_dir(dir);

    if(directory_exists(dir))
        return dir;

    return 0;
}
