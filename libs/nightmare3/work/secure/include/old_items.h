private  nosave int i;
private  nosave string gval;
private  nosave string *gfuncs;

protected void set_item_functions(mixed *things, string *funcs) {
    mapping tmp;
    gfuncs = funcs;

    if((i=sizeof(things)) != sizeof(funcs)) return;
    tmp = allocate_mapping(i);
    while(i--) tmp[things[i]] = (: this_object(), gfuncs[i] :);
    set_items(tmp);
}

void add_item_function(string key, string val) {
    gval = val;
    add_item(key, (: this_object(), gval :));
}

void remove_item_function(string str) { remove_item(str); }

void set_item_descriptions(mixed *things, string *descs) {
    mapping tmp;
    int i;

    if((i=sizeof(things)) != sizeof(descs)) return;
    tmp = allocate_mapping(i);
    while(i--) tmp[things[i]] = descs[i];
    set_items(tmp);
}

void add_item_description(string str, string desc) {
    add_item(str, desc);
}

void remove_item_description(string str) { remove_item(str); }

