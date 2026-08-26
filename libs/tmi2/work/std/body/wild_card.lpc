//  File:    /std/body/wild_card.c
//  Creator: unknown; this "cool" file originated from Portals
//
//  This file is inherited by /std/body, and performs wild card
//  expansion of filenames.

// filter out files that begin with a dot "."
int remove_dots(string tmp) {
    return (tmp[0] != '.');
}

varargs string *wild_card(string str, int keepdots) {
    string work;
    string *tmp, *pf;
    int i, s;

    // resolve pathname, with str either relative to cwd/absolute
    if ((work = resolv_path((string)this_object()->query("cwd"), str)) == "/")
        return ({ "/" }); /* Handle special case from resolv_path() */

    if (file_size(work) == -2)
        return ({ work }); /* Special case */

    // separate pathname into dirname, pf[0], and filename, pf[1]
    //   and append a trailing slash on parent path (except root)
    pf = path_file(work);
    if (pf[0] != "/")
        pf[0] = pf[0] + "/"; /* Handle a special case of path_file() */

    // get_dir() accepts wildcards
    //   returns an array of strings containing filenames only
    if (tmp = get_dir(work))
        // don't need these...
        tmp -= ({ ".", ".." });
    else
        return ({ });

    // remove dot . files, e.g. ".login", ".quit", ... etc
    if (!keepdots)
        tmp = filter_array(tmp, "remove_dots", this_object());

    // construct absolute pathnames
    //   ie append file/dir names to parent path
    s = sizeof(tmp);
    for (i = 0; i < s; i++)
        tmp[i] = pf[0] + tmp[i];

    return tmp;
}
