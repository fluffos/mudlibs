// The purpose of this object is to let you experiment with LPC
// code. It has no purpose other than testing snippets of code.
// This is the line I am adding!

#include <const.h>

string myansi;
string ESCAPE;

create()
{
   ESCAPE = " ";
   ESCAPE[0] = 0x1B;
}

array_test() {
   string s;

   s = "0123456789";
   write("Here is the string: "+s+"\n");
   write("Clipped short: "+s[0..4]+"\n");
   write("Clipped long: "+s[0..20]+"\n");
   write("Clipped beyond the end: "+s[15..20]+"\n");
}

ansitest() {
   write(ESCAPE+"[0;37mThis is GRAY text I hope\n");
   write(break_string("This    is    the     string!", 79,0)+"\n");
}

mapping x;

maptest() {
   x = ([]);
   x["north"] = "env;room1";
   write("x[\"north\"]="+x["north"]+"\n");
}

start_batt_test() {
   call_other("battle/narrator", "add_fighter", this_player());
}

announce_test() {
   announce("The world is a pretty good place.");
}

pa(string *x) {
   int i;
   write("Array=");
   for(i=0;i<sizeof(x);i++) write(x[i]+" ");
   write("\n");
}

ad_test() {
   string *x;
   x = ({"a","b","c","d","e"});
   pa(x);
   x=array_delete(x,2);
   pa(x);
   x=array_delete(x,0);
   pa(x);
   x=array_delete(x,2);
   pa(x);
}

string teststr;

set_teststr(s) {
   teststr = s;
}

regexp_test(s) {
   write("regexp( ({ \""+teststr+"\"}), \""+s+"\" ) returns:\n");
   pa( regexp(({ teststr }), s) );
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

cmode_catch(x) {
   write("Character is '"+x+"', char#"+x[0]+"\n");
   if( x == "q" ) drop_interface(); //return;
   if( x == "e" ) {
      int *x;
      write("creating an error...\n");
      x[99] = -1;
   }
//   input_to("cmode_catch", INPUT_NOECHO|INPUT_CHARMODE|INPUT_IGNORE_BANG);
}

interface_test() {
   write("You are starting the interface test. Use 'i' to try the next layer, 'q' to back out.\n");
   add_interface("interface1", "prompt1> ");
}

interface1(string str) {
   if( str == "q" ) {
      write("Dropping this layer(1).\n");
      drop_interface();
      return;
   }
   if( str == "i" ) {
      write("Going up a layer.\n");
      add_interface("interface2", "prompt2> ");
      return;
   }
   write("Received(1): '"+str+"'\n");
   return;
}

interface2(string str) {
   if( str == "q" ) {
      write("Dropping this layer(2).\n");
      drop_interface();
      return;
   }
   if( str == "i" ) {
      write("Going up a layer.\n");
      add_interface("interface3", "prompt3> ");
      return;
   }
   write("Received(2): '"+str+"'\n");
   return;
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

int x;

print_x() {
   write("This is x: "+x+"\n");
}

set_x(y) {
   x = y;
}

test_enable_commands() {
   enable_commands();
   x = 99;
}