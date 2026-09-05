inherit CommandCode;

#include <expand_object.h>

#define DEFAULT_CONTEXT "(here,me)"

private variables private functions inherit ArgsLib;
private variables private functions inherit GetoptsLib;
private variables private functions inherit ObjectExpansionLib;

private string format_muted(mapping muted);

int do_command(string arg) {
  mixed *args;
  args = getopts(explode_args(arg), "vrgm:l:M:L:t-d-i-w-e-f-");
  mapping opts = args[1];

  if (!sizeof(opts)) {
    opts['v'] = 1;
  }
  object rel;
  if (member(opts, 'r')) {
    mixed *r = expand_objects(opts['r'], THISP, DEFAULT_CONTEXT, LIMIT_ONE);
    if (sizeof(r)) {
      rel = r[0][OB_TARGET];
    }
  }
  int reconfig = member(opts, 'g');

  arg = implode(args[0], " ");
  mixed *targets = expand_objects(arg, THISP, DEFAULT_CONTEXT,
                                  MATCH_BLUEPRINTS|STALE_CLONES);
  string out = "";
  foreach (mixed *t : targets) {
    object target = t[OB_TARGET];
    object logger =
      LoggerFactory->get_logger(target, rel || target, reconfig);

    // FIXME can't use logger inside inline closure this will error!
    if (member(opts, 't')) { filter(opts['t'], (: logger->trace($1) :)); }
    if (member(opts, 'd')) { filter(opts['d'], (: logger->debug($1) :)); }
    if (member(opts, 'i')) { filter(opts['i'], (: logger->info($1) :)); }
    if (member(opts, 'w')) { filter(opts['w'], (: logger->warn($1) :)); }
    if (member(opts, 'e')) { filter(opts['e'], (: logger->error($1) :)); }
    if (member(opts, 'f')) { filter(opts['f'], (: logger->fatal($1) :)); }

    if (member(opts, 'm')) {
      int line = to_int(opts['l']);
      logger->mute(opts['m'], line);
      out += sprintf("%s: %s: muted %s%s\n",
                      query_verb(), object_name(target), opts['m'],
                      (line ? sprintf(", line %d", line) : ""));
    }
    if (member(opts, 'M')) {
      int line = to_int(opts['L']);
      if (!logger->unmute(opts['M'], line)) {
        out += sprintf("%s: %s: cannot unmute line while program is muted",
                        query_verb(), object_name(target));
      } else {
        out += sprintf("%s: %s: unmuted %s%s\n",
                        query_verb(), object_name(target), opts['M'],
                        (line ? sprintf(", line %d", line) : ""));
      }
    }
    if (member(opts, 'v')) {
      out += sprintf(
        "  Logger: %O\n"
        "Category: %s\n"
        "     UID: %s\n"
        "   Level: %s\n"
        "   Muted: %-=*s\n",
        logger,
        logger->query_category(),
        getuid(logger),
        logger->query_level(),
        THISP->query_screen_width() - 8,
        format_muted(logger->query_muted())
      );
    }
  }

  write(out);
  return 1;
}

private string format_muted(mapping muted) {
  string out = "";
  foreach (string prog, mapping lines : muted) {
    if (mappingp(lines)) {
      foreach (int line : lines) {
        out += sprintf("%s, line %d\n", prog, line);
      }
    } else {
        out += prog + "\n";
    }
  }
  return out;
}
