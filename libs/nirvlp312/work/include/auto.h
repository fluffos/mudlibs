/*
 * Injected as FluffOS "global include file" before every compile.
 *
 * status: LPMud 3.1.2-DR / Amylaar boolean-ish synonym for int.
 * move_object: 1-arg lfun so rewritten A->move_object(B) call_other()
 * sites actually dispatch (call_other never falls back to the efun).
 * Inline find-or-load so this file does not depend on simul_efun
 * (simul_efun itself includes this file).
 */
#ifndef NIRVLP312_AUTO_H
#define NIRVLP312_AUTO_H

#define status int

varargs string extract(string s, int from, int to) {
    if (!stringp(s))
        return s;
    if (undefinedp(to))
        return s[from..];
    return s[from..to];
}

mixed resolve_ob(mixed x) {
    object o;

    if (!stringp(x))
        return x;
    o = find_object(x);
    if (!o)
        o = load_object(x);
    return o;
}

varargs void move_object(mixed dest) {
    object o;

    if (stringp(dest)) {
        o = find_object(dest);
        if (!o)
            o = load_object(dest);
        dest = o;
    }
    if (dest)
        efun::move_object(dest);
}

#endif
