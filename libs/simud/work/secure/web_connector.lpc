#include <const/exitsconst.h>
#include <wizard.h>
#include <const.h>

#define BOMB(m) { write("-1\nError: " + m + "\n"); destruct(this_object()); return; }

// last arg to valid_read/valid_write is a dummy
#ifdef COMPAT_FLAG
#define MASTER "obj/master"
#else
#define MASTER "/secure/master"
#endif

string input_so_far;

void issue_command( string str );

void quit() {
  destruct(this_object());
}

void create() {
}

void notify_connect() {
  set_prompt("");
  input_to("read_input");
  input_so_far = "";
  call_out("time_out", 15);
}

void read_input( string curr_line ) {
  if( curr_line == "\27" )
    issue_command( input_so_far );
  else {
    input_so_far += curr_line;
    remove_call_out("time_out");
    call_out("time_out", 15);
    input_to("read_input");
  }
}

void time_out() {
  quit();
}

void issue_command( string str ) {
  string cmd, args, arg, arg2, file;
  string *dir;
  object ob;

  call_out("quit", 0);

  while(str[<1..] == "\n") str = str[<2..];

  if (sscanf(str, "%s %s", cmd, args) != 2) {
    cmd = str;
    args = "";
  }

  //debug("web_connector command: " + cmd + ", args: " + args);

  write("\n\n_~!\n");

  switch(cmd) {

  case "valid_read":
    if (sscanf(args, "%s %s", arg, arg2) != 2)
      BOMB("Tried to check valid_read but didn't give a uid and file.");
    if( legal_filename(arg) && file_size(arg) == -2 && arg[<1] != '/' ) arg += "/";
    write(MASTER->valid_read(arg, arg2, "valid_write", this_object()) + "\n");
    break;

  case "valid_write":
    if (sscanf(args, "%s %s", arg, arg2) != 2)
      BOMB("Tried to check valid_write but didn't give a uid and file.");
    if (strstr(arg, "/data", 0) == 0)
      //BOMB("Web editor cannot edit files in /data (don't ask why, just trust me.)");
      write("0\n");
    if (strstr(arg, "/players", 0) == 0 && arg2 != "root")
      write("0\n");
    if( legal_filename(arg) && file_size(arg) == -2 && arg[<1] != '/' ) arg += "/";
    write(MASTER->valid_write(arg, arg2, "valid_write", this_object()) + "\n");
    break;

  case "valid_write_dir":
    if (sscanf(args, "%s %s", arg, arg2) != 2)
      BOMB("Tried to check valid_write_dir but didn't give a uid and dir.");
    if( legal_filename(arg) && file_size(arg) == -2 && arg[<1] != '/' ) arg += "/";
    if( !dir = get_dir(arg) )
      BOMB("Tried to check valid_write_dir but wasn't a valid dir.");
    foreach( file : dir )
      write(file + " " + MASTER->valid_write(arg + file, arg2, "valid_write", this_object()) + "\n");
    break;

  case "getuid":
    int lev = "/secure/master_security"->query_player_level(args);
    if( lev == 1000 )
       write( "root\n");
    else
       write( args + "\n" );
    break;

  case "areamap":
   object area = find_thing(args);
   if (!area) {
      debug("Can't find area '" + args + "'", "web");
      write(0);
      break;
   }

   // type of map
   if (area->query_is_world_map())
      write("map area\n\n");
   else
      write("normal area\n\n");

   // print dimensions
   int nx = area->query_xdim();
   int ny = area->query_ydim();
   int nz = area->query_zdim();
   if( nx <= 0 || ny <= 0 || nz <= 0 ) {
      debug("Area '" + args + "' has no grid.", "web");
      write(0);
      break;
   }
   write(nx + " " + ny + " " + nz + "\n\n");

   // tile types
   string * tile_small = "/daemon/map"->query_tile_small();
   string * tile_small_color = "/daemon/map"->query_tile_small_color();

   string * grid_values = area->query_grid_values();
   string grid;
   int i = 0;
   if (area->query_is_world_map()) {
      foreach(grid : grid_values) {
         write( "" + (i + 1) + " " + tile_small[i] + " " + tile_small_color[i] + " " + grid + "\n" );
         i++;
      }
   } else {
      foreach(grid : grid_values) {
         write( "" + (i + 1) + " " + i + " " + "~[" + ((((i+8)%15+1) > 9) ? "" : "0") + ((i+8)%15+1) + "0" + " " + grid + "\n" );
         i++;
      }
   }
   write("\n");

   // print grid
   grid = area->query_grid();
   int x, y, z;

   for(z = 0; z < nz; z++) {
      for(y = 0; y < ny; y++) {
         for(x = 0; x < nx; x++) {
            write(to_int(grid[x + y * nx + z * nx * ny]) + " ");
         }
         write("\n");
      }
      write("\n");
   }

   break;

  default:
    BOMB("A web script issued a command to the MUD, but the MUD didn't understand it.");
  }
}

// this doesn't seem to be used by anything
void slow_send( string buf ) {
   write( buf[..31999] );
   if( strlen(buf) > 32000 )
      call_out("slow_send", 0, buf[32000..]);
   else
      call_out("quit", 0);
}

