#include "http.h"

string www_function(string fname) {
  string ret;
  mixed *stuff;

  ret = "<hr>\
<center>\
<font size=\"-1\"><a href=\"telnet://discworld.mudpuddle.com:4242\">Discworld MUD</a>'s \
world wide web pages.<br>\
brought to you by<br>\
<strong>Cut Me Own Throat Dibblers \
<a href=\"http:sassages.html\">Sensational Sassages</a>;\
buy one while they are hot.</strong><br>";
  if (fname == "footer") {
    fname = HTTPD->query_current_file();
  }
  stuff = stat(fname);
  if (stuff) {
    ret += "File last modified: "+HTTPD->format_date(stuff[1])+", ";
  }
  ret += "Retrieved "+HTTPD->query_current_no_reads()+" times";
  return  ret+"<br>\n<hr>\
Lost?  Try Discworld's <a href=\"/index.html\">home page</a>.\
</center>";
} /* www_function() */
