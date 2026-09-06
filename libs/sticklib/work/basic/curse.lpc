/****************************************************************
*								*
* Standard module defining curses and blesses of objects.	*
* At least standard armour and weapon files use this.		*
*								*
* V1.01 02-oct-94						*
*								*
* Last changes 02-oct-94 by Doomdark.				*
*								*
****************************************************************/

#include <curse.h>

#define	IS_IDENTIFIED_BY(X) (X&&identified_by&&\
(member(identified_by, X) >= 0))
#define CURSE_FIRST(X,Y) (sscanf(X,"<CURSE> %s",Y)==1)
#define CURSE_IN_MIDDLE(X,Y,Z) (sscanf(X,"%s <CURSE> %s",Y,Z)==2)
#define CURSE_LAST(X,Y) (sscanf(X,"%s <CURSE>",Y)==1)

inherit	"/basic/id";	/* Let's use the standard id-definitions. */

/* Prototypes. */

void set_curse(int a, int b);

/* And then the global variables we have. */

int curse_level, curse_type;
int max_curse_level;

/* These two variables define curse/bless; curse_level indicates
 * how much object's properties will be enhanced; negative amounts
 * mean that object will be inferior, positive superior; usually
 * curse_level is directly added to some property of the object.
 * For example, curse_level is added to the weapons' weapon class.
 * Curse_type indicates whether it's a curse or a bless (or neither).
 * At the moment we only have these types: cursed -> -1, blessed -> +1
 * and none -> 0. There may be more types in the future. File
 * /include/curse.h defines CT_CURSED, CT_BLESSED and CT_NONE, so
 * please use them instead of the straight numeric values.
 */

object *identified_by;

/* This array keeps track of players who know about our
 * curse/bless. Those player-objects that are in the list
 * can see curse texts (like 'blessed +3', 'cursed -2' etc.).
 */

string curse_short, curse_long;

/* These strings define the texts that players 'see' when they
 * identify this object; set_curse_short and set_curse_long can be used
 * to define these variables too. Note that 'set_curse' sets these
 * variables, so if you want to change them, do that after calling
 * 'set_curse'.
 * Usually these strings will be something like 'blessed +3',
 * '+2', 'cursed -5' etc. and 'It is blessed and has +3 bonus' etc.
 */

string curse_short1, curse_short2;
string curse_name1, curse_name2;

/* These variables are used to allow the correct placement
 * of the curse-text; that is, if you want to place 'blessed +3'
 * somewhere else than to the beginning of the name or short
 * description (like 'There is a blessed +3 sword here').
 * In that case, you'd use 'set_short("There is a <CURSE> sword here.");'
 * This module would then handle the placement so that players
 * who see the curse would get "There is a blessed +3 sword here",
 * and others "There is a sword here.". You can set the name
 * exactly same way.
 */

/****************************************************************
*								*
*	Now all the set-functions used to define the curse.	*
*								*
****************************************************************/

void set_curse_type(int ct) { curse_type = ct; }
void set_curse_level(int cl) { curse_level = cl; }
void set_max_curse_level(int mcl)
{
    max_curse_level = mcl;
    if (!mcl) return;
    if (mcl > 0 && (curse_level > 0 && curse_level > mcl)
      || (curse_level < 0 && curse_level < -mcl))
	set_curse(mcl, curse_type);	// Let's keep curse updated!
}
void set_curse_short(string s) { curse_short = s; }
void set_curse_long(string s) { curse_long = s; }

void
set_curse(int c_level, int c_type)
{
    status tmp;
    if (c_level != curse_level || c_type != curse_type) tmp = 1;
    curse_type = c_type;
    curse_level = c_level;

    /* Let's check that curse-level won't be too high (for example,
     * weapons shouldn't get curse that would drop their wc below
     * 3, and armours shouldn't get a curse that would get them to
     * have negative ac (or should they? *grin*).
     */
    if (max_curse_level)
	if (curse_level > 0) {
	    if (curse_level > max_curse_level)
		curse_level = max_curse_level;
	} else if (curse_level < -max_curse_level)
	    curse_level = -max_curse_level;
    switch (curse_type) {
    case CT_CURSED:
	curse_short = "cursed";
	curse_long = "It is cursed";
	break;
    case CT_BLESSED:
	curse_short = "blessed";
	curse_long = "It is blessed";
	break;
    default:
	curse_short = "";
	curse_long = "It isn't cursed or blessed";
    }
    if (curse_level) {
	if (curse_type != CT_NONE) {
	    curse_short += " ";
	    curse_long += " and it has a ";
	} else curse_long += ", but it has a ";
	if (curse_level > 0) {
	    curse_short += "+" + curse_level;
	    curse_long += "+" + curse_level + " bonus";
	} else {
	    curse_short += curse_level;
	    curse_long += curse_level + " penalty";
	}
    }
    curse_long += ".";
    if (tmp) this_object() -> update_curse();
    /* Finally, let's inform the 'parent-object' (the one that has
     * inheritted us) that our curse has been changed (if it has).
     */
}

/* With this we can set the identified-list. Do not use this unless
 * you know what you are doing... :-)
 */
void
set_identified_by(object *ob)
{
    if (ob && !pointerp(ob)) return;
    identified_by = ob;
}

/* With this we can add a player/monster to the identified-list. */
void
add_identified_by(object ob)
{
    if (!identified_by) identified_by = ({});
    if (ob && member(identified_by, ob) < 0)
	identified_by += ({ ob });
}

/* With this we can remove a player/monster from the identified-list. */
status
remove_identified_by(object ob)
{
    int x, s;
    if (!identified_by || (x = member(identified_by, ob)) < 0)
	return 0;
    s = sizeof(identified_by) - 1;
    if (!s) identified_by = 0;
    else if (!x) identified_by = identified_by[1..-1];
    else if (x == s) identified_by[0..-2];
    else identified_by = identified_by[0..x-1] + identified_by[x+1..-1];
    return 1;
}

/****************************************************************
*								*
* Now all the query-functions used to define the curse.	With	*
* these we can check things about the curse.			*
*								*
****************************************************************/

int query_curse_level() { return curse_level; }
int query_max_curse_level() { return max_curse_level; }
int query_curse_type() { return curse_type; }
string query_curse_short() { return curse_short; }
string query_curse_long() { return curse_long; }
int *query_curse() { return ({ curse_level, curse_type}); }
object *query_identified_by() { return identified_by; }

status is_cursed() { return IS_CURSED; }	/* Is cursed? */
status is_blessed() { return IS_BLESSED; }	/* Is blessed? */
status is_identified_by(object ob) { return IS_IDENTIFIED_BY(ob); }
status is_curseable() { return 1; } /* Sure, we can be cursed! */

/****************************************************************
*								*
* Then, let's redefine some functions defined in "/basic/id";	*
* this way we can show extra info to players who have		*
* identified us.						*
*								*
****************************************************************/

void
set_name(string s)
{
    if (!CURSE_FIRST(s, curse_name2) && !CURSE_IN_MIDDLE(s, curse_name1, curse_name2)
      && !CURSE_LAST(s, curse_name1)) {
	/* Now, since most objects that may get cursed don't specify the place
	 * where the curse_text should be placed, let's just suppose the text
	 * should be the first text (ie. "sword" -> "blessed +3 sword").
	 */
	curse_name1 = 0;
	curse_name2 = s;
    }
    /* Let's also set the 'normal' name (without curse_texts). */
    if (curse_name1) {
	if (!curse_name2) ::set_name(curse_name1);
	else ::set_name(curse_name1 + " " + curse_name2);
    }
    else ::set_name(curse_name2);
}

private status
is_article(string s)
{
    return s == "a" || s == "an" || s == "the" || s == "A" || 
    s == "An" || s == "The";
}

private string *
get_article(string s)
{
    string tmp, tmp2;
    if (sscanf(s, "%s %s", tmp, tmp2) < 2 || !is_article(tmp)) return 0;
    return ({ tmp, tmp2 });
}

void
set_short(string s)
{
    if (!CURSE_FIRST(s, curse_short2) && !CURSE_IN_MIDDLE(s, curse_short1, curse_short2)
      && !CURSE_LAST(s, curse_short1)) {
	/*
	 * Now, since most objects that may get cursed don't specify the place
	 * where the curse_text should be placed, let's check out if we could
	 * guess the 'right place'... If not, let's just suppose that curse_text
	 * should come out first (ie. "sword" -> "blessed +3 sword").
	 */
	string base, tmp, tmp2, tmp3, tmp4;
	string *art;
	curse_short1 = curse_short2 = 0;
	if (sscanf(s, "%s %s", tmp, tmp2) == 2) {
	    if (is_article(tmp)) {
		/*
		 * If the first 'word' was an article, let's just suppose the curse_text
		 * should be placed after it... "A sword" -> "A cursed -2 sword" etc.
		 */
		curse_short1 = tmp;
		curse_short2 = tmp2;
	    } else switch (tmp) {
	    case "There": case "there":
		/* It's probably something like "There is/are (a/an/the) ..." ? */
		if (sscanf(tmp2, "%s %s", tmp3, tmp4) == 2 &&
		  (tmp3 == "is" && tmp3 == "are")) {
		    curse_short1 = tmp + " " + tmp3;
		    if (!(art = get_article(tmp4)))
			curse_short2 = tmp4;
		    else {
			curse_short1 += " " + art[0];
			curse_short2 = art[1];
		    }
		}
		break;
	    case "You": case "you":
		/* Maybe something like "You (can) see (a/an/the) ..." ? */
		if (sscanf(tmp2, "see %s", tmp3))
		    curse_short1 = tmp + " see";
		else if (sscanf(tmp2, "can see %s", tmp3))
		    curse_short1 = tmp + " can see";
		else break;
		if (!(art = get_article(tmp3)))
		    curse_short2 = tmp3;
		else {
		    curse_short1 += " " + art[0];
		    curse_short2 = art[1];
		}
		break;
	    default:
		curse_short1 = 0;
		curse_short2 = s;
	    }
	}
    }
    if (!curse_short1 && !curse_short2) {
	curse_short1 = 0;
	curse_short2 = s;
    }

    /* Let's also set the 'normal' short description (without curse_texts). */
    if (curse_short1) {
	if (!curse_short2) ::set_short(curse_short1);
	else ::set_short(curse_short1 + " " + curse_short2);
    }
    else ::set_short(curse_short2);	
}

varargs status
id(string s, object who)
{
    string tmp;
    /* Little kludgy here right now... It should be enhanced later... */
    if (!who) who = this_player();
    if (!curse_short || !who || !IS_IDENTIFIED_BY(who)) return ::id(s);
    if (curse_type == CT_CURSED && sscanf(s, "cursed %s", tmp))
	s = tmp;
    else if (curse_type == CT_BLESSED && sscanf(s, "blessed %s", tmp))
	s = tmp;
    if (curse_level) {
	string tmp2;
	if (curse_level < 0) tmp2 = "" + curse_level;
	else tmp2 = "+"+curse_level;
	if (sscanf(s, tmp2+" %s", tmp)) s = tmp;
    }
    if (s == query_name(0, who)) return 1;
    /* In case 'curse_short' is located somewhere else than in middle... */
    return ::id(s);
}

varargs string
query_name(int mode, object who)
{
    if (!who) who = this_player();
    if (!curse_short || (!who && !(who = this_player())) ||
      !IS_IDENTIFIED_BY(who)) return ::query_name(mode, who);
    if (!curse_name1) return curse_short + " " + curse_name2;
    if (!curse_name2) return curse_name1 + " " + curse_short;
    return curse_name1 + " " + curse_short + " " + curse_name2;
}

varargs string
query_short(int mode, object who)
{
    if (!curse_short || (!who && !(who = this_player())) ||
      !IS_IDENTIFIED_BY(who)) return ::query_short(mode, who);
    if (!curse_short1) return curse_short + " " + curse_short2;
    if (!curse_short2) return curse_short1 + " " + curse_short;
    return curse_short1 + " " + curse_short + " " + curse_short2;
}

varargs string
query_long(string what, object who)
{
    if (!who && !(who = this_player())) return ::query_long(what, who);
    /* Let's remove 0s from identified-list. */
    if (pointerp(identified_by) && sizeof(identified_by))
	identified_by -= ({ 0 });
    if (!IS_IDENTIFIED_BY(who)) return ::query_long(what, who);
    return ::query_long(what, who) + "\n" + curse_long;
}

/****************************************************************
*								*
* Finally, let's save the data about the curse... Nasty...	*
*								*
****************************************************************/

mapping
save_variables()
{
    mapping var;
    if (!mappingp(var = ::save_variables())) var = ([]);
    var += ([
      "curse_level" : curse_level
      ,"max_curse_level" : max_curse_level
      ,"curse_type" : curse_type
      ,"curse_short" : curse_short
      ,"curse_short1" : curse_short1
      ,"curse_short2" : curse_short2
      ,"curse_long" : curse_long
      ,"curse_name1" : curse_name1
      ,"curse_name2" : curse_name2
    ]);
    return var;
}

void
restore_variables(mapping var)
{
    curse_level = var["curse_level"];
    max_curse_level = var["max_curse_level"];
    curse_type = var["curse_type"];
    curse_short = var["curse_short"];
    curse_short1 = var["curse_short1"];
    curse_short2 = var["curse_short2"];
    curse_long = var["curse_long"];
    curse_name1 = var["curse_name1"];
    curse_name2 = var["curse_name2"];
    ::restore_variables(var);
}
