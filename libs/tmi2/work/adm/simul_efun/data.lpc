// Originally from Truilkan... the user versions were whipped up by Buddha

#include <config.h>
#include <uid.h>

string data_dir(object obj) {
   return DATA_DIR + base_name(obj);
}

string data_file(object obj) {
   return data_dir(obj) + "/" + (geteuid(obj) ? geteuid(obj) : getuid(obj));
}

varargs string user_data_dir(object obj, string name) {
   string ret;
   if (!name) name = (geteuid(obj));
   if (!name) return "" ;
//   if (!name) error("user_data_dir: Can't determine user's name.\n");
   ret = data_dir(obj) + "/" + extract(name, 0, 0);
   return ret;
}

varargs string user_data_file(object obj, string name) {
   string dir, ret;
   dir = (name ? user_data_dir(obj, name) : user_data_dir(obj));
   //ret = dir + "/" + (name ? name : geteuid(obj)) + __SAVE_EXTENSION__;
   ret = dir + "/" + (name ? name : geteuid(obj));
   return ret;
}

void assure_user_save_dir(object user) {
	string dir, path, *parts;
	int j;
        if (previous_object() != user) return;
	path = user_data_dir(user);
        if (file_size(path) == -1) {
                seteuid(ROOT_UID);
	        parts = explode(path, "/");
		dir = "";
		for (j = 0; j < sizeof(parts); j++) {
                	dir += parts[j];
                	mkdir(dir);
                	dir += "/";
        	}
        }
	if (file_size(path) == -1)
		write("assure_save_dir failed!\n");
}

void assure_save_dir(object user) {
        string dir, path, *parts;
        int j;
        if (previous_object() != user) return;
        path = data_dir(user);
        if (file_size(path) == -1) {
                seteuid(ROOT_UID);
                parts = explode(path, "/");
                dir = "";
                for (j = 0; j < sizeof(parts); j++) {
                        dir += parts[j];
                        mkdir(dir);
                        dir += "/";
                }
        }
}


