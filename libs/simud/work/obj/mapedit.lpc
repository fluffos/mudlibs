#include <wizard.h>
#include <const.h>
#include <textdraw.h>
#include <object.h>
#include <keys.h>

// Prototypes

void draw_map();
void draw_room_list();
void update();
void catch_tell( string data );

object area;
object *rooms = ({ });
int width, height;
int view_width, view_height;
int mx, my, top_room;
int nx, ny, nz;
int cx, cy, cz, room_select, code_count;
int markx, marky;
int refresh_map;
int refresh_room_list;
int refresh_status;
nosave string keybuf;
int bottom_line;
int tilemode;
int pendown;
string last_color;
string *termbuf;
string *tilechars, *tilecolors;
mapping colors;

create() {
   ::create();
   termbuf = ({ });
   colors = ([ ]); // Cache ANSI codes.
}

// Taken from fulledit. Ought to be a library function really.
varargs void input_box( string prompt, string finish_to, int box_width, string initial_text ) {
   if( !initial_text ) initial_text = "";
   drawbox( width / 2 - box_width / 2 - 2, height / 2 - 2, box_width + 4, 4, "~[007" );
   gotoxy( width / 2 - box_width / 2, height / 2 - 1 );
   write( prompt );
   line_input( width / 2 - box_width / 2, box_width, height / 2, 0, finish_to, initial_text );
}

// From fulledit again.
void editor_message( string str ) {
   catch_tell(process_string("~CDEF[~CLABEditor~CDEF] "+str+"\n"));
}

/// Query the area being edited. For debugging/hacking.
object query_area() {
   return area;
}

/// For easier debugging; this object is named 'Mapedit'
string query_name() {
   return "Mapedit";
}

/// For easier debugging; lets you refer to this object as 'Mapedit'
object id( string val ) {
   if( val == "Mapedit" )
      return this_object();
   else
      return 0;
}

/** Handles the terminal; like fulledit's. Should probably make the scrolling
 * terminal's a full library routine.
 */
void catch_tell( string data ) {
   if( !data || data == "" ) data = "BLANK";
   if( sizeof(termbuf) != height / 5 )
      refresh_status = 1;
   termbuf = add_text( termbuf, data, width, height / 5 );
   draw_terminal( termbuf, 1, height-sizeof(termbuf)+1, environment(this_object()) );
   bottom_line = height - sizeof(termbuf);
   view_height = bottom_line - 2;
}

void set_area( object x ) {
   area = x;
}

string roomcode( int c ) {
   string tmp;

   if( tilemode ) {
      return tilechars[c];
   }
   else {
      tmp = "  ";
      tmp[0] = '0' + (c / 26);
      tmp[1] = 'A' + (c % 26);
      return tmp;
   }
}

#define set_color(new_color) ((new_color==last_color)?"":(colors[last_color = new_color]?colors[new_color]:(colors[new_color]=process_ansi(new_color))))

string _set_color( string s ) { return set_color(s); }
//string set_color( string new_color ) {
//   if( new_color == last_color )
//      return "";
//   return last_color = new_color;
//}

string roomcolor( int c ) {
   if( tilemode ) {
      return set_color(tilecolors[c]);
   }
   else {
      return set_color("~[" + (c / 10) + (c % 10) + "0");
   }
}

void full_refresh() {
   msg_bare("~CLRS");
   gotoxy( 1, 1 );
   refresh_map = refresh_room_list = refresh_status = 1;
   update();
   gotoxy( 1, 1 );
}

void draw_map() {
   int x, y, z, c, cval;
   string mymap, name;

   gotoxy( 1, 1 );

   last_color = "";

   nx = area->query_xdim();
   ny = area->query_ydim();
   nz = area->query_zdim();
   if( nx <= 0 || ny <= 0 || nz <= 0 ) {
      msg("==> [Error] This object has no grid (It might not be initialized).");
      return;
   }

   // c = cell
   mymap = "  " + set_color("~CBRT");
   while( cx - mx >= view_width )
      mx += view_width / 2;
   while( cx < mx )
      mx -= view_width / 2;
   if( mx < 0 ) mx = 0;
   while( (cy - my) >= view_height )
      my += view_height / 2;
   while( cy < my )
      my -= view_height / 2;
   if( my < 0 ) my = 0;
   for( x = mx; x - mx < view_width; x++ )
      if( x >= nx )
         mymap += "   ";
      else
         mymap += pad( "" + x, 3, JUST_RIGHT );
   mymap += "\n";
   z = cz;
   for( y = my; y < view_height + my; y++ ) {
      if( y >= ny ) {
         mymap += process_ansi("~CEOL") + "\n";
         continue;
      }
      mymap += set_color("~CBRT") + pad( "" + y, 2, JUST_RIGHT );
      for( x = mx; x < view_width + mx; x++ ) {
         if( x >= nx ) {
            mymap += "   ";
            continue;
         }
         c = 0;
         c = area->query_cell_index( x, y, z );
         if( tilemode && c == 254 )
            area->set_cell_index( x, y, z, c = 0 );
         if( !tilemode )
            cval = c % 15 + 1;
         else
            cval = c;
         if( c == 254 ) {
            if( x == cx && y == cy  ) {
               mymap += set_color("~CDEF");
               mymap += "*" + set_color("~[007");
               mymap += ".." + set_color("~CDEF");
            }
            else
               mymap += set_color("~CDRK") + " ..";
         }
         else {
            if( x == cx && y == cy ) {
               mymap += set_color("~CDEF") + "*" + set_color("~[007") + roomcode(c) + set_color("~CDEF");
            }
            else
               mymap += roomcolor(cval) + " " + roomcode(c);
         }
      }
      mymap += "\n";
   }
   write( mymap );
}

void redraw_cell( int highlight ) {
   string mymap;
   int c, cval;

   if( cx < mx || cy < my || cx >= view_width + mx || cy >= view_height + my ) {
      draw_map();
      return;
   }

   gotoxy( (cx - mx) * 3 + 3, (cy - my) + 2 );
   c = area->query_cell_index( cx, cy, cz );
   if( tilemode && c == 254 )
      area->set_cell_index( cx, cy, cz, c = 0 );
   if( tilemode )
      cval = c;
   else
      cval = c % 15 + 1;
   if( c == 254 ) {
      if( highlight )
         mymap = "*~[007.." + set_color("~CDEF");
      else
         mymap = " ~CDRK.." + set_color("~CDEF");
   }
   else {
      if( highlight )
         mymap = set_color("~CDEF") + "*~[007" + roomcode(c) + "~CDEF";
      else
         mymap = " " + roomcolor(cval) + roomcode(c);
   }
   msg_bare( mymap + "~CDEF" );
}

void draw_room_list() {
   int i, y;
   string rline;

   while( room_select - top_room >= view_height )
      top_room += view_height / 2;
   while( room_select < top_room )
      top_room -= view_height / 2;

   if( top_room < 0 ) top_room = 0;

   // Gets a list of all objects in an area which return true on 'query_room'.
   if( !tilemode ) {
      rooms = area->query_grid_values();
      if( !rooms ) rooms = ({ });
      rooms = map( rooms, (: stringp($1)?present($1,area):0 :) );
      for( i = sizeof(rooms); --i > 0; )
      if( !objectp(rooms[i]) )
         area->set_grid_value(i, 0);
      code_count = sizeof(rooms);
      rooms += filter( all_inventory(area), (: $1->query_is_room() :) ) - rooms;
   }
   else {
      rooms = "/daemon/map"->query_tile_types();
      area->set_grid_values( rooms );
      code_count = sizeof(rooms);
   }

   if( room_select >= sizeof(rooms) )
      room_select = sizeof(rooms) - 1;

   // Draws the room list.
   y = 1;
   msg_bare("~CDEF");
   for( i = top_room; i < sizeof(rooms); i++ ) {
      if( y > view_height + 1 ) break;
      gotoxy( width - 20, y );
      if( objectp(rooms[i]) ) {
         if( i < code_count )
            rline = pad(roomcode(i) + " " + rooms[i]->query_name(), 19, JUST_LEFT);
         else
            rline = pad("** " + rooms[i]->query_name(), 19, JUST_LEFT);
      }
      else if( stringp(rooms[i]) ) rline = pad(roomcode(i) + " " + rooms[i], 19, JUST_LEFT);
      else rline = pad("   <blank>", 19, JUST_LEFT);
      if( y - 1 == room_select )
         msg_bare( "~[154" + rline + "~CDEF" );
      else
         msg_bare( rline );
      y++;
   }
   while( y <= view_height + 1 ) {
      gotoxy( width - 20, y++ );
      msg_bare("~CEOL");
   }
}

void redraw_room_name( int highlight ) {
   string rline;

   if( room_select < top_room || room_select - top_room > view_height )
      draw_room_list();

   if( objectp(rooms[room_select]) ) {
      if( room_select < code_count )
         rline = pad(roomcode(room_select) + " " + rooms[room_select]->query_name(), 19, JUST_LEFT);
      else
         rline = pad("** " + rooms[room_select]->query_name(), 19, JUST_LEFT);
   }
   else if( stringp(rooms[room_select]) ) rline = pad(roomcode(room_select) + " " + rooms[room_select], 19, JUST_LEFT);
   else rline = pad("   <blank>", 19, JUST_LEFT);

   gotoxy( width - 20, (room_select - top_room) + 1 );
   if( highlight )
      msg_bare( "~[154" + rline + "~CDEF" );
   else
      msg_bare( "~CDEF" + rline );
}

void update() {
   if( refresh_map ) {
      draw_map();
      draw_terminal( termbuf, 1, height-sizeof(termbuf)+1, environment(this_object()) );
   }
   if( refresh_room_list )
      draw_room_list();
   if( refresh_status ) {
      gotoxy( 1, bottom_line );
      msg_bare("~[007" + pad(" Acius's map editor   Floor: "+cz+"   Area: "+get_location(area), width - 1, JUST_LEFT) + "~[070" );
   }
   refresh_map = refresh_room_list = refresh_status = 0;
}

void start_edit( object target_area ) {
   if( target_area )
      area = target_area;
   if( !area ) {
      msg("Can't figure out which area to edit!");
      return;
   }
   width = environment(this_object())->query_term_width();
   height = environment(this_object())->query_term_height();
   view_width = (width - 24) / 3;
   bottom_line = height;
   view_height = bottom_line - 2;
   tilemode = area->query_is_world_map();
   tilechars = "/daemon/map"->query_tile_small();
   tilecolors = "/daemon/map"->query_tile_small_color();
   full_refresh();
   keybuf = "";
   add_interface("@keypress");
   set_interface_catch( 1 );
   cx = cy = cz = 0;
   mx = my = 0;
   top_room = 0;
   pendown = 0;
}

void paint_cell() {
   string room_name;
   if( objectp(rooms[room_select]) ) {
      room_name = rooms[room_select]->query_name();
      area->set_cell( cx, cy, cz, room_name );
      if( room_select >= code_count ) {
         refresh_room_list = 1;
         room_select = member( area->query_grid_values(), room_name );
         if( room_select == -1 ) room_select = 0;
      }
      redraw_cell(1);
   }
   if( stringp(rooms[room_select]) ) {
      area->set_cell_index( cx, cy, cz, room_select );
      redraw_cell(1);
   }
}

void paint_box() {
    int ix, iy, minx, maxx, miny, maxy;

    minx = min( markx, cx );
    miny = min( marky, cy );
    maxx = max( markx, cx );
    maxy = max( marky, cy );

    for( ix = minx; ix <= maxx; ix++ )
    for( iy = miny; iy <= maxy; iy++ ) {
       string room_name;
       if( objectp(rooms[room_select]) ) {
          room_name = rooms[room_select]->query_name();
          area->set_cell( ix, iy, cz, room_name );
          if( room_select >= code_count ) {
             refresh_room_list = 1;
             room_select = member( area->query_grid_values(), room_name );
             if( room_select == -1 ) room_select = 0;
          }
       }
       if( stringp(rooms[room_select]) ) {
          area->set_cell_index( ix, iy, cz, room_select );
       }
    }
    refresh_map = 1;
}

void issue_command( string str ) {
   string err;

   msg("~CDEF");
   err = catch(command(str, this_player()));
   if( err )
      catch_tell("Error in command: "+err);
}

void keypress( string c ) {
   int code;

   if( !c ) {
      full_refresh();
      return;
   }

   keybuf += c;
   code = this_player()->translate_code( keybuf );

   if( code != KEY_NONE ) {
      switch( code ) {
      case KEY_UP:
         redraw_cell(0);
         cy--;
         if( cy < 0 ) {
            object ob = query_area()->query_north_area();
            if( ob ) {
               set_area(ob);
               cy = ob->query_ydim()-1;
               full_refresh();
            }
            else
               cy = 0;
         }
         if( pendown ) paint_cell();
         redraw_cell(1);
         break;
      case KEY_DOWN:
         redraw_cell(0);
         cy++;
         if( cy >= ny ) {
            object ob = query_area()->query_south_area();
            if( ob ) {
               set_area(ob);
               cy = 0;
               full_refresh();
            }
            else
               cy = ny - 1;
         }
         if( pendown ) paint_cell();
         redraw_cell(1);
         break;
      case KEY_RIGHT:
         redraw_cell(0);
         cx++;
         if( cx >= nx ) {
            object ob = query_area()->query_east_area();
            if( ob ) {
               set_area(ob);
               cx = 0;
               full_refresh();
            }
            else
               cx = nx - 1;
         }
         if( pendown ) paint_cell();
         redraw_cell(1);
         break;
      case KEY_LEFT:
         redraw_cell(0);
         cx--;
         if( cx < 0 ) {
            object ob = query_area()->query_west_area();
            if( ob ) {
               set_area(ob);
               cx = ob->query_xdim() - 1;
               full_refresh();
            }
            else
               cx = 0;
         }
         if( pendown ) paint_cell();
         redraw_cell(1);
         break;
      case KEY_BACKSPACE:
         if( area->remove_cell( cx, cy, cz ) )
            refresh_room_list = 1;
         redraw_cell(1);
         break;
      case KEY_PGUP:
         redraw_cell(0);
         if( cy > my ) cy = my;
         else cy -= view_height / 2;
         if( cy < 0 ) cy = 0;
         redraw_cell(1);
         break;
      case KEY_PGDN:
         redraw_cell(0);
         if( cy < my + view_height - 1 ) cy = my + view_height - 1;
         else cy += view_height / 2;
         if( cy >= ny ) cy = ny - 1;
         redraw_cell(1);
         break;
      case KEY_HOME:
         redraw_cell(0);
         if( cx > mx ) cx = mx;
         else cx -= view_width / 2;
         if( cx < 0 ) cx = 0;
         redraw_cell(1);
         break;
      case KEY_END:
         redraw_cell(0);
         if( cx < mx + view_width - 1 ) cx = mx + view_width - 1;
         else cx += view_width / 2;
         if( cx >= nx ) cx = nx - 1;
         redraw_cell(1);
         break;
      case KEY_F2:
      case KEY_CTRL_D:
         input_box( "Enter MUD command to execute:", "issue_command", width * 3 / 4 );
         break;
      }
      keybuf = "";
   }
   else {
      if( keybuf[0] < 32 || keybuf[0] > 127 ) return;
      switch( keybuf[0] ) {
         case 'i':
            redraw_room_name(0);
            room_select = area->query_cell_index( cx, cy, cz );
            if( room_select == 254 ) room_select = 0;
            redraw_room_name(1);
            break;
         case 'd':
            if( pendown = !pendown ) paint_cell();
            break;
         case 'q': drop_interface(); gotoxy( 1, height ); msg(""); destruct(this_object()); return;
         case '+':
            redraw_room_name(0);
            room_select++;
            if( room_select >= sizeof(rooms) ) room_select = sizeof(rooms) - 1;
            redraw_room_name(1);
            break;
         case '-':
            redraw_room_name(0);
            room_select--;
            if( room_select < 0 ) room_select = 0;
            redraw_room_name(1);
            break;
         case 'r':
            full_refresh();
            break;
         case ' ':
            paint_cell();
            break;
         default : break;
         case 'm':
            markx = cx;
            marky = cy;
            break;
         case 'b':
            paint_box();
            break;
         case '<':
            if( cz > 0 ) {
               cz--;
               refresh_map = refresh_room_list = refresh_status = 1;
            }
            break;
         case '>':
            if( cz < nz -1 ) {
               cz++;
               refresh_map = refresh_room_list = refresh_status = 1;
            }
            break;
      }
      keybuf = "";
   }
   update();
}
