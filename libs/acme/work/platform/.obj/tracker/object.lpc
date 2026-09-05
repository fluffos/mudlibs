/**
 * A module for tracking objects as they are loaded and destructed.
 *
 * @author devo@eotl
 * @alias ObjectTracker
 */
#pragma no_clone
#include <sys/objectinfo.h>
#include <sql.h>

inherit SqlMixin;

private inherit ArrayLib;

#define OBJECT_TABLE    "object"
#define OBJECT_ID       "object_id"
#define OBJECT_NAME     "object_name"
#define OBJECT_TIME     "object_time"
#define PROGRAM         "program"
#define DESTRUCT_TIME   "destruct_time"
#define LAST_REF_TIME   "last_ref_time"
#define GIGATICKS       "gigaticks"
#define TICKS           "ticks"

public void setup();
public void new_object(object o);
public void object_destructed(object o);
public string query_object_id(object ob);

/**
 * Setup the ObjectTracker.
 */
public void setup() {
  SqlMixin::setup();
  SqlMixin::table_info(OBJECT_TABLE, (:
    if (!$1) {
      SqlMixin::create_table(OBJECT_TABLE, mapping_array(
        ({ SQL_COL_NAME, SQL_COL_TYPE, SQL_COL_FLAGS, SQL_COL_DEFAULT }),
        ({ 
           ({ SQL_ID_COLUMN, SQL_TYPE_INTEGER, 
              SQL_FLAG_PRIMARY_KEY|SQL_FLAG_AUTOINCREMENT }),
           ({ OBJECT_ID, SQL_TYPE_TEXT, SQL_FLAG_UNIQUE }),
           ({ OBJECT_NAME, SQL_TYPE_TEXT }),
           ({ OBJECT_TIME, SQL_TYPE_INTEGER }),
           ({ PROGRAM, SQL_TYPE_TEXT }),
           ({ DESTRUCT_TIME, SQL_TYPE_INTEGER }),
           ({ LAST_REF_TIME, SQL_TYPE_INTEGER }),
           ({ GIGATICKS, SQL_TYPE_INTEGER }),
           ({ TICKS, SQL_TYPE_INTEGER })
        })
      ));
    }
    return;
  :));

  // TODO discover existing objects with debug_info()
  return;
}

/**
 * Invoked by the HookService when a new object is created.
 * 
 * @param  o             the object being created
 */
public void new_object(object o) {
  string program_id = ProgramTracker->query_program_id(o);
  mapping odata = ([ 
    OBJECT_ID : query_object_id(o),
    OBJECT_NAME : object_name(o),
    OBJECT_TIME : object_time(o),
    PROGRAM : program_id
  ]);
  //SqlMixin::insert(OBJECT_TABLE, odata);
  return;
}

/**
 * Invoked by the master object when an object is destructed.
 * 
 * @param  o             the object being destructed
 */
public void object_destructed(object o) {
  mapping odata = ([ 
    SQL_ID_COLUMN : query_object_id(o),
    DESTRUCT_TIME : time(),
    LAST_REF_TIME : object_info(o, OINFO_BASIC, OIB_TIME_OF_REF),
    GIGATICKS : object_info(o, OINFO_BASIC, OIB_GIGATICKS),
    TICKS : object_info(o, OINFO_BASIC, OIB_TICKS),
  ]);
  //SqlMixin::update(OBJECT_TABLE, odata);
  return;
}

/**
 * Get the object id for an object. Unlike most other trackers, object ids
 * aren't constructed with incrementing counters. Instead, they are based on
 * timestamps so the query operation is idempotent assuming I'm using that word
 * correctly.
 *
 * blueprint ids = "object_name#object_time#blueprint_counter"
 * clone ids = "object_name#object_time"
 * Reminder: clone object names are "load_name#clone_counter"
 *        
 * @param  ob            the object to get an id for
 * @return the object id
 */
public string query_object_id(object ob) {
  if (clonep(ob)) {
    return sprintf("%s#%d", object_name(ob), object_time(ob));
  } else {
    string program_id = ProgramTracker->query_program_id(ob);
    return sprintf("%s#%d#%d", 
                   object_name(ob), object_time(ob), 
                   ProgramTracker->query_program_count(program_id));
  }
}

/**
 * Constructor.
 */
public void create() {
  setup();
}