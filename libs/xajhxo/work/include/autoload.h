#ifndef __AUTOLOAD__
#define __AUTOLOAD__

class Item {
    string BaseName;
    mixed  ItemInfo;
}

void clean_up_autoload();
void save_autoload();
void restore_autoload();

#endif

