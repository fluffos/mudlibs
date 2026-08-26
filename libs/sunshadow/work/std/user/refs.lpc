// File:       /std/user/refs.c
// Mudlib:     Nightmare
// Purpose:    To store refs in (See _refs)
// Author:     Douglas Reay (Pallando @ TMI, Nightmare, etc)
// Date V1.0:  93-06-05

nosave mapping refs;

void set_refs(mapping a)
{
    refs = (mapp(a) ? a : ([]));
}

mapping get_refs()
{
    return (refs ? copy(refs) : ([]));
}

void set_ref(string target_ref, mixed value)
{
    if (!refs) {
        refs = ([]);
    }
    if (!target_ref) {
        target_ref = "default";
    }
    if (undefinedp(value)) {
        map_delete(refs, target_ref);
    }else {
        refs[target_ref] = value;
    }
}

mixed get_ref(string target_ref)
{
    if (!refs) {
        refs = ([]);
    }
    if (!target_ref) {
        target_ref = "default";
    }
    return refs[target_ref];
}
