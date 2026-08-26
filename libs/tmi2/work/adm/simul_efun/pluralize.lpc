/* $Id: pluralize.c,v 1.6 1994/05/14 09:58:20 vax Exp vax $
 * purpose: this file does the brunt of the pluralization work.
 *
 * $Log: pluralize.c,v $
 * Revision 1.6  1994/05/14  09:58:20  vax
 * Fixed some small syntax errors.
 *
 * Revision 1.5  1994/05/14  09:42:00  vax
 * Modified pluralize_verb to bring it up to date.  Added many small
 * touches (putting *x->*xes back, etc).  General speedups with ``len''.
 *
 * Revision 1.4  1994/05/10  10:26:08  vax
 * Added mapping (hash-table) lookup for exceptions.
 * Filtered out tabs.
 * Many small speedups.
 *
 * Revision 1.3  1994/05/09  22:48:34  vax
 * I really really fixed the "mosquito"/"domino" bug now.
 *
 * Revision 1.2  1994/02/12  11:29:54  vax
 * Changed this to use un_article (new simul_efun).
 *
 * Revision 1.1  1994/02/12  11:28:41  vax
 * Initial revision
 *
 * old stuff:
 * author:  Pinkfish 
 * history: written by pinkfish one day, and modified for the TMI
 *  distribution mudlib by Buddha on 3-14-92.  No changes were needed. ;-)
 * Changelog:
 *  7 Nov 1993 by VaX#n8
 *      o General revamp
 *  18 Jan 1994 VaX#n8 (vax)
 *      o Special cases for "datum" and "sphinx" added.
 *  27 Jan 1994 VaX#n8 (vax)
 *      o Rule for '*o' -> '*oes' (mosquito -> mosquitoes) fixed.
 * This is obsolete:
 * NB: it is always preferable for objects to set their plural using
 *     "set_plural()" (on std/object), but if the relevant programmer hasn't
 *     done so, "query_plural()" (also on std/object) calls this efun for
 *     a hopefully reasonable approximate.  objects should _always_ call
 *     call "query_plural()" to get the plural form of an object's "short()",
 *     failure to do so is treason, and subject to punishment by summary
 *     execution.  The Computer is your friend.
 */

#define VOWELS ({'a', 'e', 'i', 'o', 'u'})

mapping pluralize_exceptions = ([
    "fish" : "fish",
    "deer" : "deer",
    "sheep" : "sheep",
    "child" : "children",
    "tooth" : "teeth",
    "ox" : "oxen",
    "vax" : "vaxen",
    "bus" : "buses",
    "mouse" : "mice",
    "goose" : "geese",
    "fife" : "fifes",
    "staff" : "staves",
    "dynamo" : "dynamos",
    "datum" : "data",
    "sphinx" : "sphinges",
    "moose" : "moose",
    ]);

string pluralize(string str)
{
    string pre, suf; /* used temporarily in the beginning */
    string two, three, retval;
    int one,
        len; // used a few times as length of string.

    if (!stringp(str)) return "";

    // first, get rid of articles.  pluralized forms never have them ;)
    str = un_article(str);

    // len is used later.  It's not computed if str is not a string.
    if ((len = strlen(str)) < 2) return "";
 
    // Deal with "sword of power" -> "swords of power" types (Watcher 09/92)
    if (sscanf(str, "%s of %s", pre, suf) == 2)
        return pluralize(pre) + " of " + suf;
 

    // Changed on 5-1-95 by Shriekback to include items that have
    // parentheses strings at the end of its description.
    // Example: "light saber (off)" gets pluralized to "light sabers (off)"

    if (sscanf(str, "%s (%s)", pre, suf) == 2)
        return sprintf("%s (%s)", pluralize(pre), suf);

    // trap the exceptions to the rules below and special cases.
    if (stringp(retval=pluralize_exceptions[str])) return retval;

 // Leto added the next bit, since 'white mouse' became white mouses' while mouse became 'mice'
if(sscanf(str,"%s %s",one,two) == 2 ) return one+" "+pluralize(two);

    one = str[(len - 1)];
    two = str[<2..<1];
    three = str[<3..<1];

    // now handle "rules" ... god I hate english!!

    // Latin pluralization, I think
    // *us -> *i (virus -> viri), also radius
    if (two == "us") return str[0..<3]+"i";

    // nouns ending in s, z, x, o, ch, and sh form plural by adding es.
    // ex: business, six, church, wish, quizz, avocado
    if ((member_array(one, ({ 's', 'z', 'x', 'o' })) != -1)
        || (two == "ch") || (two == "sh"))
        return str + "es";

    // *fe -> *ves (knife -> knives)
    // exception: fife (above)
    if (two == "fe") return str[0..<3] + "ves";

    /*
     * *f -> *ves (half -> halves)
     * *ef -> *efs (chef -> chefs) (really a rule for a special case)
     * *ff -> *ffs (skiff -> skiffs, cliff -> cliffs)
     *             exception: staff (above)
     */
    if (one == 'f')
    {
        if (two == "ef" || two == "ff") return str + "s";
        return str[0..<2]+"ves";
    }

    // nouns ending in a consonant plus y form the plural by changing:
    // *y -> *ies (gumby -> gumbies)
    if (one == 'y' && (member_array(str[len-2], VOWELS) == -1))
      return str[0..<2]+"ies";

    // *man -> *men (foreman -> foremen)
    if (three == "man") return str[0..<3] + "en";

    // *is -> *es (this is from gordons pluralize ... )
    // if (two == "is") return str[0..<3] + "es";

    // default, * -> *s
    return str + "s";
}

/* end of pluralize() */

// mudlib: Basis
// note:   heavily based on Pinkfish's pluralizer (but simplified since this
//         one isn't meant to handle nouns or articles etc)
// Modified by VaX#n8
// Curiously enough, we "pluralize" the verb (add an s) when we don't pluralize
// the noun, and vice-versa.  For example:
// The company pays high taxes.
// The companies pay high taxes.

string pluralize_verb(string rel)
{
    string two;
    int i,
        one,  // the first onearacter of rel.
        len; // used a few times as length of string.

    if (!stringp(rel)) return "";

    // len is used later.  It's not computed if rel is not a string.
    if ((len = strlen(rel)) < 2) return "";

    // trap the exceptions to the rules below and special cases.
    // not really big enough to merit a hash table.
    switch (rel)
    {
        case "half" : return "halves";
        case "go" : return "goes";
        case "fish" : return "fishes";
        case "staff" : return "staves";
    }

    one = rel[len-1];
//  two = rel[<2..<1];
    two = rel[<2..<1];

    // A small rule for a special case below.
    // wiz -> wizzes
    if (two == "iz") return rel + "zes";

    // Saw this in the TMI-2 version, don't know why.
    // I personally think it's incorrect, it is for nouns.
    // iris -> irises
    // if (two == "is") return rel + "ses";

    // verbs, again, can end in x, s, o, ch, sh, or z.
    // box, hiss, smash, brush
    if ((member_array(one, ({ 's', 'z', 'x', 'o' })) != -1)
        || (two == "ch") || (two == "sh"))
        return rel + "es";

    // *fe -> *ves (knife -> knives)
    // exception: fife (above)
    if (two == "fe") return rel[0..<3] + "ves";

    /*
     * *f -> *ves (half -> halves)
     * *ef -> *efs (chef -> chefs) (really a rule for a special case)
     * *ff -> *ffs (skiff -> skiffs, cliff -> cliffs)
     */
    if (one == 'f')
    {
        if (two == "ef" || two == "ff") return rel + "s";
        return rel[0..<2]+"ves";
    }

    // *y -> *ies (gumby -> gumbies)
    if ((one == 'y') && (member_array(rel[len-2], VOWELS) == -1))
        { return rel[0..<2] + "ies"; }

    // default: (* -> *s)
    return rel + "s";
}
