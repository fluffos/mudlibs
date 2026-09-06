/* #include <condition.h> to use this feature and stuff.
 *
 * It will make the object succeptible to breakage. When initializing such
 * an object, call set_max_condition() to define the item's actual
 * durability, otherwise... max condition will default to 1;
 *
 * Also, if an item is to be destroyed upon breakage (as opposed to simply
 * being flagged as broken), call set_dest_on_break(1) when initializing
 * the object.
 *
 * The moment an object actually breaks, the on_break() event is called.
 * If the object is set to dest upon breaking, it will dest as soon as the
 * event is finished executing.
 *
 * -- Allaryin (may 27, 2003)
 */

inherit "/inherit/desc";

// Default condition is 1000
CONDITION( 1000 )
UNBREAKABLE( 0 )
DEST_ON_BREAK( 0 )

int condition;

void set_max_condition(int x) { SBODY( "max_condition", x ) }

int query_max_condition() { QBODY( "max_condition", this_object()->query_default_max_condition() ) }

void set_dest_on_break(int x) { SBODY( "dest_on_break", x ) }

int query_dest_on_break() { QBODY( "dest_on_break", this_object()->query_default_dest_on_break() ) }

void set_unbreakable(int x) { SBODY( "unbreakable", x ) }

int query_unbreakable() { QBODY( "unbreakable", this_object()->query_default_dest_on_break() ) }

void set_breakable(int x) { set_unbreakable(!x); }

int query_breakable() { return !query_unbreakable(); }

int query_condition() { return condition; }

void set_condition(int x) {
   if (x <= 0) {
      if (query_unbreakable()) {
         x = 0;
      } else {
         object ob = environment(this_object());
         object old_target;
         string buf;
         if (ob->query_is_living()) {
            set_actor(ob);
            old_target = query_target();
            set_target(this_object());
            ob = environment(ob);
            buf = "~CWRN~Npos "+query_name()+" has broken.~CDEF";
         } else {
            set_actor(this_object());
            buf = "~CWRN~Name has broken.~CDEF";
         }
         if( this_object()->query_held() )
            this_object()->set_held( 0 );
         if( this_object()->query_worn() )
            this_object()->set_worn( 0 );
         if( !this_object()->on_break() ) {
            msg_room(ob, buf);
            if (old_target)
               set_target(old_target);
         }
         if( query_dest_on_break() ) {
            debug("dest on break...");
            destruct(this_object());
            return;
         }
         x = -1;
      }
   }
   condition = x;
}

void add_condition(int x) {
   set_condition(query_condition() + x);
}

int query_broken() { return query_condition() == -1; }

int query_condition_percent() {
   return 100 * query_condition() / query_max_condition();
}

string query_distant() {
   string base_distant = ::query_distant();

   if( !stringp(base_distant) ) return base_distant;

   if( !query_broken() ) return base_distant;
   if( strstr(base_distant, "HP") >= 0 || strstr(base_distant, "BROKEN") >= 0 ) return base_distant;

   return base_distant + " (broken)";
}

string query_specific() {
   string base_specific = ::query_specific();

   if( !stringp(base_specific) ) return base_specific;

   if( !query_broken() ) return base_specific;
   if( strstr(base_specific, "HP") >= 0 || strstr(base_specific, "BROKEN") >= 0 ) return base_specific;

   return base_specific + " (broken)";
}

string query_look() {
   string base_look = ::query_look();

   if( !stringp(base_look) ) return base_look;

   if( strstr(base_look, "HP") >= 0 || strstr(base_look, "BROKEN") >= 0 ) return base_look;
   if( query_broken() )
      return base_look + "\n\n" + capitalize("" + query_specific())+" is ~CWRNbroken~CDEF.";
   else
      return base_look + "\n\n" + capitalize("" + query_specific())+" is $(HP).";
}

string *query_alt_name() {
   string *base_alt_name = ::query_alt_name();
   if ( !query_broken() )
      return base_alt_name;

   if ( !sizeof(base_alt_name) )
      return ({ "broken " + query_name() });
   string str, *broken_name = ({ });
   foreach ( str : base_alt_name )
      broken_name += ({ "broken " + str });
   return base_alt_name + broken_name;
}

string query_plural() {
   if ( !query_broken() )
      return ::query_plural();
   else
      return "broken " + ::query_plural();
}

string *query_alt_plural() {
   string *base_alt_plural = ::query_alt_plural();
   if ( !query_broken() )
      return base_alt_plural;

   if ( !sizeof(base_alt_plural) )
      return ({ "broken " + ::query_plural() });
   string str, *broken_plural = ({ });
   foreach ( str : base_alt_plural)
      broken_plural += ({ "broken " + str });
   return base_alt_plural + broken_plural;
}

void _create_condition() {
   set_condition( query_max_condition() );
}
