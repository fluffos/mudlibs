#include <object.h>
#include <inven.h>

struct PaintPattern {
   int pos;
   int color;
   int depth;
   string pattern;
};

struct PaintPattern *patterns = ({ });

string query_name() {
   return "_custom_floor";
}

object id( string param ) {
   return param == query_name()?this_object():0;
}

int query_is_landscape() {
   return 1;
}

int add_pattern( string pattern, int color, int pos, int depth ) {
   patterns += ({ (<PaintPattern> pos, color, depth, pattern) });
   return sizeof(patterns)-1;
}

void remove_pattern( int i ) {
   patterns = patterns[..i-1] + patterns[i+1..];
}

struct PaintPattern *query_patterns() {
   return patterns;
}

void set_patterns( struct PaintPattern *x ) {
   patterns = x;
}

void on_map_paint( object painter ) {
   struct PaintPattern p;

   foreach( p : patterns ) {
      painter->paint_shape( CX(p->pos), CY(p->pos), p->pattern, p->color, p->depth );
   }
}
