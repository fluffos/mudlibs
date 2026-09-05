#include <sys/files.h>

inherit CommandCode;

private variables private functions inherit ArgsLib;
private variables private functions inherit GetoptsLib;
private variables private functions inherit FileLib;

#define BLOCK_SIZE 1024

int do_command(string arg) {
  mixed *args = getopts(explode_args(arg), "ladps");
  if (!sizeof(args[0])) {
    args[0] = ({ THISP->query_cwd() });
  }

  mixed *files = ({ });
  foreach (string path : args[0]) {
    path = expand_path(path, THISP);
    if (is_directory(path) && !member(args[1], 'd') && (path[<1] != '/')) {
      path = path + "/";
    }

    string *f = expand_pattern(path, THISP);
    if (!sizeof(f)) {
      printf("%s: %s: no such file or directory\n", query_verb(), path);
      continue;
    }

    files += f;
  }
  
  // TODO add sorting options
  //files = sort(files, (: $1[0] > $2[0] :));
  mapping dirs = ([ ]);
  foreach (mixed *file : files) {
    string dir = dirname(file[0]);
    if (!member(dirs, dir)) {
      dirs[dir] = ({ });
    }
    dirs[dir] += ({ file });
  }

  string result = "";
  int first = 1;
  foreach (string dir, mixed *f : dirs) {
    if (!first) {
      result += "\n";
    }
    first = 0;

    string *out = allocate(sizeof(f));
    int index = 0;
    int total = 0;
    foreach (mixed file : f) {
      string name = file[0][(strlen(dir)+1)..];
      if (!member(args[1], 'a') && (name[0] == '.')) {
        continue;
      }
      string o = name;
      if (member(args[1], 'p') && (file[1] == -2)) {
        o += "/";
      }
      int blocks = 0;
      if (file[1] > 0) {
        blocks = file[1] / BLOCK_SIZE;
        if (file[1] % BLOCK_SIZE) { blocks++; }
      }
      total += blocks;
      if (member(args[1], 'l')) {
        o = sprintf("%-9s  %10d  %17s  %s", 
          (file[1] >= 0 ? "file" : 
            (file[1] == -2 ? "directory" : "")),
          (file[1] >= 0 ? file[1] : 0),
          strftime("%b %e " + 
                   (localtime()[5] == localtime(file[2])[5] ? " %R" : "%Y" ),
                   file[2]),
          o
        );
        if (member(args[1], 's')) {
          o = sprintf("%2d %s", blocks, o);
        }
      } else {
        if (member(args[1], 's')) {
          o = blocks + " " + o;
        }
      }
      out[index++] = o;
    }
    out -= ({ 0 });

    if (sizeof(dirs) > 1) {
      result += dir + ":\n";
    }
    if (member(args[1], 'l')) {
      result += sprintf("total %d\n%s\n", total, implode(out, "\n"));
    } else {
      // FUTURE implement variable page width
      if (member(args[1], 's')) {
        result += sprintf("total %d\n", total);
      }
      result += sprintf("%#-*s\n", 
                        THISP->query_screen_width(), implode(out, "\n"));
    }
  }

  printf(result);
  return 1;
}
