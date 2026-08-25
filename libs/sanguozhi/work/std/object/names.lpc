// Updated by stefan on 10 Jan 1997
// modified by fire on 5 April, 1998
/* Do not remove the headers from this file! see /USAGE for more info. */

/* grammar related stuff */
private nosave string * ids;
private nosave string * plurals;
private nosave string * adjs;

private string primary_id, primary_adj, chinese_id, unit;

/* calculated internally */
private nosave mixed internal_short;

/*
 * proper_name: Proper_name should only be set for objects who should not
 *     be refered to as "a xxx" or "the xxx"
 */
private nosave mixed proper_name;


/*
** Can be implemented by subclasses to provide additional stuff dynamically
*/
string * fake_item_id_list();
int is_visible();
string invis_name();
int test_flag(mixed);
string query_unit();

varargs mixed call_hooks(string, mixed, mixed);
private void resync();

void create() 
{
    parse_init();
    ids = ({});
    plurals = ({});
    adjs = ({});
    resync();
}

//:FUNCTION set_proper_name
//Set the proper name of an object.  Objects with proper names never have
//adjectives added in front of their names.
nomask void set_proper_name(string str)
{
    proper_name = str;
    resync();
}

string calculate_extra() {
//:HOOK extra_short
//The non-zero return values are added on to the end of the short descriptions
//when inv_list() is used (surrounded by parenthesis)
    return  call_hooks("extra_short", 
                       function(string sofar, mixed this) {
                           if (!this) return sofar;
                           return sofar + " (" + this + ")";
                       }
                       , "");
}

private void resync() {
    if (!proper_name) {
        if (!primary_id && sizeof(ids))
            primary_id = ids[0];
        if (!chinese_id && sizeof(ids) >= 2)
            chinese_id = ids[1];
        if (primary_id) {
            internal_short = primary_adj ? primary_adj : "";
            if (chinese_id) internal_short += chinese_id + "(" + primary_id + ")";
            else internal_short += primary_id;
        } else {
            internal_short = "不明物体"; //"nondescript thing";
        }
    } else
        internal_short = proper_name;
    parse_refresh();
}

//:FUNCTION short
//Return the 'short' description of a object, which is the name by which
//it should be refered to
string short()
{
    if(!is_visible())
        return invis_name();
    return evaluate(internal_short);
}

//### should be somewhere else?
string add_article(string str) {
    return "一"+query_unit()+str;
}

//:FUNCTION a_short
//return the short descriptions, with the word 'a' in front if appropriate
string a_short() {
  if (!proper_name) return add_article(short());
  return evaluate(proper_name);
}

/****** the id() functions ******/
int id(string arg) {
    if (! arrayp(ids)) return 0;
    return member_array(arg,ids) != -1;
}


/****** add_ ******/

//:FUNCTION add_adj
//Add an adjective.  The first adjective becomes the primary adjective.
//See add_secondary_id if you don't want that.
void
add_adj(string * adj... )
{
    if(!arrayp(adjs))
      adjs = adj;
    else
      adjs += adj;
    resync();
}


//:FUNCTION add_id
//Add an id
void add_id( string * id... )
{
    if(!arrayp(ids))
      ids = id;
    else
      ids += id;
    resync();
}

void add_chinese_id(string * cid... )
{
    if (sizeof(cid)) {
        chinese_id = cid[0];
        if (!arrayp(ids)) ids = cid;
        else ids += cid;
        resync();
    }
}
    
/****** set_ ******/
//These actually add, but the first argument becomes the primary id/adjective
void set_id( string * id... ) {
    ids += id;
    primary_id = id[0];
    if (sizeof(id)>=2) chinese_id = id[1]; 
    resync();
}

void set_adj( string * adj... ) {
    if(!arrayp(adjs))
      adjs = adj;
    else
      adjs += adj;
    primary_adj = adj[0];
    resync();
}

void set_unit(string u) {
    unit = u;
}

/****** remove_ ******/
//:FUNCTION remove_id
//Remove the given id
nosave protected
void remove_id( string * id... )
{
    if(!arrayp(ids))
      return;
    ids -= id;
    resync();
}

void remove_adj( string * adj ... ) {
    if(!arrayp(ids))
      return;
    adjs -= adj;
    resync();
}

/****** clear_ ******/

//:FUNCTION clear_id
//removes all the ids of an object.
void clear_id() {
    ids = ({ });
    plurals = ({ });
    resync();
}

//:FUNCTION clear_adj
//Remove all the adjectives from an object
void clear_adj() 
{
    adjs = ({ });
    resync();
}

/****** query_ ******/

//:FUNCTION query_id
//Returns an array containing the ids of an object
string * query_id() {
    string * fake = this_object()->fake_item_id_list();
    
    if (fake) return fake + ids;
    else return ids;
}

//:FUNCTION query_adj
//return the adjectives
string * query_adj()
{
    return adjs;
}

string query_unit()
{
    if (!unit) return "个";
    else return unit;
}

//:FUNCTION query_primary_id
//Returns the primary id of an object
string query_primary_id() {
    return primary_id;
}

//:FUNCTION query_primary_adj
//Returns the primary adj of an object
string query_primary_adj() {
    return primary_id;
}

//:FUNCTION query_primary_id
//Returns the primary name (primary adj + primary id) of an object
string query_primary_name() {
    return (primary_adj ? primary_adj + " " : "") + primary_id;
}
/****** parser interaction ******/

string * parse_command_id_list()
{
    if (test_flag(INVIS)) return ({ });
//### should strip non-alphanumerics here; might need an efun to do it
//### efficiently
    return query_id();
}

nomask string * parse_command_adjectiv_id_list() {
    if (test_flag(INVIS)) return ({ });
    return adjs;
}
string query_chinese_id()
{
    return chinese_id;
}
