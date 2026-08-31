// /std/ext/persist_data.c
// Module to handle persistent saving of data
//
// Created:     2024/02/02: Gesslar
// Last Change: 2024/02/02: Gesslar
//
// 2024/02/02: Gesslar - Created

private nosave int persistent = 0;
private nosave string data_file = 0;

varargs string set_data_file(string file);

// whether this object will save/load
varargs int set_persistent(int x: (: 1 :)) {
    x = !!x;

    if(!data_file) set_data_file();

    if(x == 1)
        PERSIST_D->register_persistent(this_object());
    else
        PERSIST_D->unregister_persistent(this_object());

    return persistent = x;
}

int query_persistent() {
    return persistent;
}

// the save file, if none, provided, the object will determine its own
// save file based on the master_object() to be backwards compatible with
// old save.c
varargs string set_data_file(string file) {
    if(!file) {
        file = object_data_file(this_object());
    }

    file = chop(file, __SAVE_EXTENSION__, -1);
    data_file = file;

    return data_file;
}

string query_data_file() {
    return data_file;
}

private string get_base_path(string path) {
    int pos = strsrch(path, "/", -1);

    return path[ 0 .. pos - 1 ];
}

// saving and loading data
int save_data() {
    string base;

    if(!persistent)
        return 0;

    if(!data_file)
        set_data_file();

    if(!data_file)
        return 0;

    base = get_base_path(data_file);
    if(!directory_exists(base))
        if(strsrch(data_file, "/data/") == 0)
            if(!assure_dir(base))
                return 0;

    return save_object(data_file);
}

int restore_data() {
    if(!persistent)
        return 0;

    if(!data_file)
        data_file = object_data_file(this_object());

    if(!ofile_exists(data_file))
        return 0;

    return restore_object(data_file);
}
