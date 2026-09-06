/* find - cross between unix find and hyp's dir */

inherit "std/thing";
#include <config.h>

#define ME this_object()
#define TP this_player()
#define TI this_interactive()

#define USAGE "Usage: find [dirs] [-name regexp] [-type f|d] [-newer file] [-print] [-exec cmd | -catch cmd]\n"

string *cmd;
string pattern;
int printit, newertime, type, catchit;

usage() { write("Find: " USAGE); return 1; }

void init() {
  ::init();
  AddId("find");
  SetShort("Find");
  SetLong("Find a program inspired by unix find.\n" USAGE
"The cmd may contain {}, which are replaced by the names of matching files.\n");
  add_action("find", "find");
}

is_newer(f, p) {
	string ff;
	ff = p ? p+"/"+f : f;
/*	write("newertime "+newertime+" size(`"+ff+"') "+file_size(ff)
 *	      +" date "+((-1 == file_size(ff)) ? 0 : file_date(ff))+"\n");
 *	write("return "
 *	      +((-1 == file_size(ff)) ? 0 : newertime < file_date(ff))+"\n");
 */
	return (-1 == file_size(ff)) ? 0 : newertime < file_date(ff);
}

is_type(f, p) {
	string ff;
	int s;
	ff = p ? p+"/"+f : f;
	s = file_size(ff);
	/* write("type "+type+" size(`"+ff+"') "+s+"\n"); */
	return (type < 0 ? s == type : s >= 0);
}

/* descend through dir */
finddir(dir, pref) {
  string *entries, *matches;
  int i;

  if (geteuid(ME) != geteuid(TI)) {
    write("This is not your Find.\n");
    destruct(ME);
    return 0;
  }
  dir = MASTER->make_path_absolute(pref ? pref+dir : dir);
  if (-2 != file_size(dir)) return;
  entries = get_dir(dir+"/*");
  if (!entries) return;
  /* write(sizeof(entries)+" entries\n"); */
  entries -= ({".", ".."});
  if (!entries || !sizeof(entries)) return;

  matches = entries;
  /* write(sizeof(entries)+" entries\n"); */
  if (pattern) matches = regexp(entries, pattern);
  /* write(sizeof(matches)+" matches after regexp\n");*/
  if (newertime) matches = filter(matches, #'is_newer/*'*/, dir);
  /* write(sizeof(matches)+" matches after newer\n"); */
  if (type) matches = filter(matches, "is_type", this_object(), dir);
  /* write(sizeof(matches)+" matches after newer\n"); */
  if (matches && sizeof(matches)) {
    /* write("eval preds\n");*/
    for (i = 0; i < sizeof(matches); i++) {
      /* write("eval preds "+i+"\n");*/
      if (printit) write(dir+"/"+matches[i]+"\n");
      if (cmd) {
	string err, d;
	/* write("size is "+sizeof(cmd)+" cmd0 is `"+cmd[0]+"'\n");*/
	d = implode(cmd, dir+"/"+matches[i]);
	/* write("Doing `"+d+"'\n");*/
	if (catchit) {
	  if (err = catch(this_player()->command_me(d)))
	    write("* catched "+err+" for "+d+"\n");
	} else this_player()->command_me(d);
      }
    }
  }
  /* write(sizeof(entries)+" entries to recurse\n");*/
  filter(entries, #'finddir /*'*/, dir+"/");
}

find(str) {
  string *args, *dirs, foo;
  int i;

  if (!str || "" == str) return usage();
  
  cmd = pattern = printit = newertime = type = catchit = 0;
  dirs = ({});
  args = explode(str, " ");
  /* first the dirs to look through */
  for (i = 0; i < sizeof(args) && "" != args[i] && '-' != args[i][0]; i++)
    dirs += ({args[i]});
  if (!sizeof(dirs)) dirs = ({"."});
  
  /* now the predicates */
  for ( ; i < sizeof(args) && "" != args[i] && args[i][0] == '-'; i++) {
    switch(args[i]) {
    case "-name":
      if (sizeof(args) == ++i) return usage();
      pattern = args[i];
      continue;
    case "-newer":
      if (sizeof(args) == ++i) return usage();
      foo = MASTER->make_path_absolute(args[i]);
      if (-1 == file_size(foo)) {
	write("Find: "+args[i]+": not accessible.\n");
	return 1;
      }
      newertime = file_date(foo);
      continue;
    case "-type":
      if (sizeof(args) == ++i) return usage();
      if ("f" == args[i]) type = 1;
      else if ("d" == args[i]) type = -2;
      else return usage();
      continue;
    case "-print": printit = 1; continue;
    case "-catch": catchit = 1;
    case "-exec":
      cmd = explode(implode(args[++i..], " "), "{}");
      i = sizeof(args);
      break;
    }
  }
  if (!cmd) printit = 1;

  write("size dirs "+sizeof(dirs)+" newer "+newertime+" type "+type
	+" pattern `"+pattern+"' printit "+printit+" cmd `"
	+implode(cmd,"?")+"'\n");
  for (i = 0; i < sizeof(dirs); i++) write("dirs["+i+"] `"+dirs[i]+"'\n");

  filter(dirs, #'finddir/*'*/);
  return 1;
} 
