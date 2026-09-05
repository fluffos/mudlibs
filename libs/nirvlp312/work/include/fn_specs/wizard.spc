static status promote(string str);

static status plural_filter(object ob, string object_id);
static status present_filter(object ob, object who);

string plural_to_single(string plural);
static varargs object *FIND_OBJECT(string str, object who);
static object *PROCESS_ARG(string arg);
object *PROCESS_ARG_OB(mixed *ob_list, object *ob);

static status Put(string str);
static status Cat_file(string str);

