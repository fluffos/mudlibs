

// The purpose of this object is to let you experiment with LPC
// code. It has no purpose other than testing snippets of code.

#include <const.h>
#include <textdraw.h>

string myansi;
string ESCAPE;

mapping newm=([]);

mixed name, email, vars, coord, env_vars;

create()
{
   ESCAPE = " ";
   ESCAPE[0] = 0x1B;
}

cat_test() {
   cat("/text/news.cod", 1, 10);
   write("cat called\n");
   return;
}

array_test() {
   string s;

   s = "0123456789";
   write("Here is the string: "+s+"\n");
   write("Clipped short: "+s[0..4]+"\n");
   write("Clipped long: "+s[0..20]+"\n");
   write("Clipped beyond the end: "+s[15..20]+"\n");
   write("all_inventory of this object is pointerp? "+ pointerp(all_inventory(this_object())) +"\n");
}

ansitest() {
   write(ESCAPE+"[0;37mThis is GRAY text I hope\n");
   write(break_string("This    is    the     string!", 79,0)+"\n");
}

start_batt_test() {
   call_other("battle/narrator", "add_fighter", this_player());
}

announce_test() {
   announce("The world is a pretty good place.");
}

string teststr;

set_teststr(s) {
   teststr = s;
}

sec_test(s) {
   int i;
   i = call_other("/secure/file_security", "query_read_access", s, this_object());
   write("query_read_access(s) for test/test returns: " + i + "\n");
}

wsec_test(s) {
   int i;
   i = call_other("/secure/file_security", "query_write_access", s, this_object());
   write("query_write_access(s) for test/test returns: " + i + "\n");
}

time_test() {
   write("ctime(time()) returns: "+ctime(time())+"\n");
}

cmode_test() {
   write("Type something, see what happens :)\n");
//   input_to("cmode_catch", INPUT_NOECHO|INPUT_CHARMODE|INPUT_IGNORE_BANG);
   add_interface("@cmode_catch", 0);
}

interface3(string str) {
   if( str == "q" ) {
      write("Dropping this layer(3).\n");
      drop_interface();
      return;
   }
   if( str == "i" ) {
      write("No more layers.\n");
      return;
   }
   if( str == "e" ) {
      int *x;
      write("Creating error...\n");
      x[99] = -1;
      return;
   }
   write("Received(3): '"+str+"'\n");
   return;
}

call_out_test() {
   msg("Call out test: this_player() is currently "+as_string(this_player()) );
   call_out("_call_out_test", 1, this_player());
}

_call_out_test(object ob) {
   msg_object(ob, "this_player() after a call_out is "+as_string(this_player()) );
}

object tp;

void hb_test() {
   set_heart_beat(1);
}

void heart_beat() {
   tp = this_player();
   debug("tp is " + as_lpc(tp));
   set_heart_beat(0);
}

line_in() {
   msg("Doing line input...\n\n\n");
   line_input( 1, this_player()->query_term_width() - 1, this_player()->query_term_height(), 0, "line_input_return", "sample text" );
}

line_input_return( s ) {
   msg( "Line input returns: '"+s+"'" );
}

co_error() {
   return 1/0;
}

make_error() {
   call_out("co_error", 0);
}

str_test() {
   string abc;
   int d;

   abc = "Hello\0 there kids.";
   write("abc len = "+strlen(abc)+"\n");
   d = abc[0];
   write("d is "+d+"\n");
}

void timer_mtest() {
   call_out("mtest",0);
}

void mtest() {
   destruct(find_object("/secure/master")); load_object("/secure/master");
}

string pathtest()
{
   string p, zbuf;
   mapping floor;
   p = find_path("BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB0<000000000000000000000000000000000000000000000000BB00000000000000000000000000000000000000000000000000BB0000000000000000000000@0000000000000000@@@00000000BB000000000000000000000@@@00000000000000@@@@@0000000BB000000:::00000000000@@@@@0000000000000@@@@@0000000BB00000:::::000000000000<00000000000000000@000000000BB00000::B::000@@@000000000000000000000000<000000000BB000000000000@@@@@000000000000000000000000000000000BB000000000000@@@@@000000000000000000000000000000000BB00000000000000@00000000000000000000000000000000000BB00000000000000<00000000000000000000000000000000000BB0000000000000000000@@@@@00000000000000000000000000BB0000000000000000000@0<0@00000000000000000000000000BB000000000000000000000<0000000000000000000000000000BB00000000000000000000000000000000000000000000000000BB00000000000000000000000000000000000000000000000000BB00000000000000000000000000000000000000000000000000BB00000000000000000000000000000000000000000000000000BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB", 50, 18, 8, 8, ([ 64: 1, 52: 1, 48: 1, 49: 1, 50: 1, ]), 52 );
   msg("Initial path is " + as_lpc(p) );
   zbuf = find_room(";coco2;room_80.96")->query_zbuf();
   floor = FLOOR_CHARS;
   p = find_path( zbuf, 50, 18, 8, 8, floor, 52 );
   msg("Second path is " + as_lpc(p) );
   return find_path( find_room(";coco2;room_80.96")->query_zbuf(), 50, 18, 8, 8, FLOOR_CHARS, 52 );
}

void b() {
   write("in b(), previous_object() is "+as_lpc(previous_object()));
}

void a() {
   write("in a(), previous_object() is "+as_lpc(previous_object()));
   b();
}

void rtest( int range ) {
   int *dist = allocate(range);
   int i;

   for( i = range * 1500; i--; )
      dist[(int) (((float) random(0x7fffffff) / (float) 0x7fffffff) * range)]++;

   msg( as_lpc(dist) );
}

#include <const/cityconst.h>

int unbuilt() {
   return UNBUILT;
}
