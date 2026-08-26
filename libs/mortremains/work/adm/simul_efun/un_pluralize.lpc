/* $Id: un_pluralize.c,v 1.2 1994/05/10 10:25:40 vax Exp vax $
 * purpose: this file does the brunt of the un-pluralization work.
 * Based loosely on TMI-2's pluralize.
 * $Log: un_pluralize.c,v $
 * Revision 1.2  1994/05/10  10:25:40  vax
 * Filtered out tabs.
 *
 * Revision 1.1  1994/05/09  23:03:38  vax
 * Initial revision
 *
 */

#define VOWELS ({'a', 'e', 'i', 'o', 'u'})

mapping un_pluralize_exceptions = ([
    "fish" : "fish",
    "deer" : "deer",
    "sheep" : "sheep",
    "children" : "child",
    "teeth" : "tooth",
    "oxen" : "ox",
    "vaxen" : "vax",
    "buses" : "bus",
    "mice" : "mouse",
    "geese" : "goose",
    "cliffs" : "cliff",
    "fifes" : "fife",
    "dynamos" : "dynamo",
    "data" : "datum",
    "sphinges" : "sphinx",
    ]);

string un_pluralize(string str)
{
    string pre, suf; /* used temporarily in the beginning */
    string two, three;
    mixed rel;
    int one;

    if (!stringp(str) || (strlen(str) <= 1)) return "";

    // first, get rid of articles.
    str = un_article(str);
 
    // Deal with "swords of power" -> "sword of power" types
    if (sscanf(str, "%s of %s", pre, suf) == 2)
        return un_pluralize(pre) + " of " + suf;
 
    // only un_pluralize the last word, ie: lose adjectives.
    rel = explode(str, " ");
    if (rel && pointerp(rel) && sizeof(rel) > 1)
    {
        pre=implode(rel[0..<2], " ");
        if (sizeof(rel) > 1) pre += " ";
        return pre + un_pluralize(rel[sizeof(rel)-1]);
    }

    // trap the exceptions to the rules below and special cases.
    if (stringp(rel=un_pluralize_exceptions[str])) return rel;

    one = str[strlen(str)-1];
    two = str[<2..<1];
    three = str[<3..<1];

    // now handle "rules" ... god I hate english!!

    // Latin pluralization, I think
    // *us -> *i (virus -> viri), also radius
    if (one == 'i') return str[0..<1]+"us";

    /* Depends on letter leading the "ves".
     * *fe -> *ves (knife -> knives)
     * *f -> *ves (half -> halves)
     */
    if (three == "ves") return str[0..<4] + "f" +
        (member_array(str[<4],VOWELS) == -1) ? "" : "e" ; 

    // nouns ending in s, z, x, ch, and sh form plural by adding es.
    // ex: business, six, church, wish, quizz
    if ((two == "es") &&
        ((member_array(str[strlen(str)-3], ({ 's', 'z', 'o' })) != -1)
         || (member_array(str[<4..<3], ({ "ch", "sh" })) != -1)))
        return str[0..<3];

    // nouns ending in a consonant plus y form the plural by changing:
    // *y -> *ies (gumby -> gumbies)
    if (three == "ies" &&
    	(member_array(str[strlen(str)-4], VOWELS) == -1))
        return str[0..<4] + "y";

    // *man -> *men (foreman -> foremen)
    if (three == "men") return str[0..<3] + "an";

    // default, * -> *s
    if (one == 's') return str[0..<2];

    // give up :-)
    return str;
}

/* end of un_pluralize() */
