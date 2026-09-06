From: msheahan@carroll1.cc.edu (chiaroscuro)
Subject: text formatting function
Date: 3 Dec 1994 12:16:53 -0600
Organization: The Carroll College InterNet News site
Message-ID: <3bqcml$joh@carroll1.cc.edu>

The following is the function roughly equivalent to break_string() used by
Lost Souls (lostsouls.desertmoon.com 3000); this version of it demonstrated
about a 65% eval drop on most strings over our last implementation, which
was based on implode() and explode() like every break_string() function I've
ever seen.  If this kind of function is ubiquitous in your mudlib like it is
in ours, you'd probably kill a lot of lag by using it, which is why I'm
posting this as a public service.  It's written for Amylaar 3.2.1@70.  Enjoy.

								Chaos@LostSouls
--
/* function: format
 * arguments:
 *    string to be formatted
 * optional:
 *    indentation string | length (default is nothing)
 *    subsequent indentation string | length (if unspecified same as first)
 *    width specification (for other than default 76 chars)
 */
varargs string format(string what, mixed indent, mixed indent_subsequent,
	int width) {
int base, len, scan, pos, prep;
	if(!width)
	  width = 76;
	if(member(what, '\n') != -1) {
	  what = implode(explode(what, ".\n"), ".  ");
	  what = implode(explode(what, "\n"), " ");
	}
	if(!indent)
	  indent = "";
	else if(intp(indent))
	  indent = sprintf("%" + indent + "s", " ");
	len = strlen(what = indent + what);
	if(len <= width)
	  return what + "\n";
	if(!indent_subsequent)
	  indent_subsequent = indent;
	else if(intp(indent_subsequent))
	  indent_subsequent = sprintf("%" + indent_subsequent + "s"," ");
	prep = strlen(indent_subsequent);
	while(base + width < len) {
	  for(pos = 0, scan = base + width; !pos && scan > base; scan--)
	    if(what[scan] == ' ')
	      pos = scan;
	  if(!pos)
	    for(scan = base + width + 1; !pos && scan < len; scan++)
	      if(what[scan] == ' ')
		pos = scan;
	  if(!pos)
	    base = len;
	  else if(prep) {
	    what[pos..pos] = "\n" + indent_subsequent;
	    len += prep;
	    base = pos + prep + 1;
	  } else {
	    what[pos] = '\n';
	    base = pos + 1;
	  }
	}
	return what + "\n";
}
