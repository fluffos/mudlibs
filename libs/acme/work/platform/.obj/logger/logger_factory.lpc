/**
 * The LoggerFactory. This service object is responsible for instantiating
 * new logger objects and configuring them from properties files located
 * throughout the filesystem. When new loggers are created, they are added to
 * a pool so that they may be reused again in a later execution without the
 * overhead of re-configuration. The factory is responsible for cleaning up
 * logger objects which are no longer in use.
 *
 * @alias LoggerFactory
 */
#pragma no_clone
#include <sys/debug_info.h>
#include <sys/objectinfo.h>
#ifdef EOTL
#include <acme.h>
#include AcmeLoggerInc
#else
#include <logger.h>
#include <object.h>
#endif

#ifdef EOTL
#include AcmeFormatStringsInc
#include AcmeFileInc
private inherit AcmeFormatStrings;
private inherit AcmeFile;
#else
private inherit FileLib;
private inherit ObjectLib;
private inherit ZoneLib;
private inherit FormatStringLib;
#endif

// FUTURE add color

/** ([ str zone : ([ str euid : obj logger ]) ]) */
private mapping loggers;
/** ([ obj logger : int ref_count ]) */
private mapping local_ref_counts;
/** ([ str format : cl formatter ]) */
private mapping formatters;
/** a Logger instance for the factory to use */
private object factory_logger;
/** all Logger instances must share a Logger
    (or else things would get crazy pretty fast) */
private object logger_logger;

public void setup();
public varargs object get_logger(mixed zone, object rel, int reconfig);
protected mapping read_config(string zone, string dir);
protected mapping read_properties(string prop_file);
protected string read_prop_value(mapping props, string prop, string path, 
                                 string zone);
protected mixed *parse_output_prop(string val);
public object get_null_logger();
public int release_logger(mixed zone, string euid);
protected int clean_up_loggers();
protected void init_static_loggers();

/**
 * Setup the LoggerFactory.
 */
public void setup() {
  seteuid(getuid());
  loggers = ([ ]);
  formatters = ([ ]);
  local_ref_counts = ([ ]);
  init_static_loggers();
}

/**
 * Retrieve a logger instance for the given zone from the pool, or create
 * a new one from configuration. A zone is represented as a hierarchical
 * string of the form, "superzone.zone.subzone.<...>". The zone may
 * also be specified as a filesystem path, in which case the path
 * delimiters (forward slashes) will be converted to the zone delimiter
 * (periods).
 *
 * @param  zone     an object or string representing the zone; if an
 *                  object is specfied, it's load_name(E) will be used.
 * @param  rel      optional object to use for resolving relative paths in
 *                  configuration files; if unspecified, previous_object()
 *                  will be used.
 * @param reconfig  set this flag to 1 if you need to re-read the logger
 *                  configuration
 * @return          a logger instance
 */
public varargs object get_logger(mixed zone, object rel, int reconfig) {
  return logger_logger;
  // normalize some input
  mixed *pathinfo = get_path_info(zone);
  zone = pathinfo[PATH_INFO_ZONE];
  if (!rel) {
    rel = previous_object();
  }

  // check for special loggers
  if (pathinfo[PATH_INFO_ONAME] == LoggerFactory) {
    return factory_logger;
  }
  if (pathinfo[PATH_INFO_ONAME] == Logger) {
    return logger_logger;
  }

  // check our cache
  string euid = geteuid(rel);
  object logger = 0;
  if (member(loggers, zone)) {
    logger = loggers[zone][euid];
  }
  if (!reconfig && logger) {
    return logger;
  }

  // build our configuration
  mapping config = read_config(zone, load_name(rel));
  efun::printf("%O %O %O\n", zone, rel, config);
  if (!member(config, "output")) {
    // no output
    return get_null_logger();
  }
  if (!member(config, "format")) {
    config["format"] = DEFAULT_FORMAT;
  }
  if (!member(config, "level")) {
    config["level"] = DEFAULT_LEVEL;
  }

  // compile formatter
  closure formatter = formatters[config["format"]];
  if (!formatter) {
    formatter = parse_format(config["format"], LOGGER_MESSAGE,
                             ({ 'zone, 'priority, 'message, 'caller }));
    formatters[config["format"]] = formatter;
  }

  // configure our logger
  string factory_euid = geteuid();
  seteuid(euid);
  if (!logger) {
    logger = clone_object(Logger);
    export_uid(logger);
    if (!member(loggers, zone)) {
      loggers[zone] =  ([ ]);
    }
    loggers[zone][euid] = logger;
    if (!member(local_ref_counts, logger)) {
      local_ref_counts[logger] = 0;
    }
    local_ref_counts[logger]++;
  }
  logger->set_zone(zone);
  logger->set_output(config["output"]);
  logger->set_formatter(formatter);
  logger->set_level(config["level"]);
  seteuid(factory_euid);
  return logger;
}

/**
 * Read in logger configuration for the specified zone. Starting in the
 * specified directory, this function will look for the file
 * "etc/logger.properties", and inspect the file for any configuration
 * properties which apply to the specified zone. The result is a mapping
 * of the form:
 * <code>
 * ([ "output" : ({ ({ int type, string target }), ... }),
 *    "format" : str format_string,
 *    "level"  : str level
 * ])
 * </code>
 * FUTURE better to use a struct than a mapping here
 *
 * @param  zone     the zone to match configuration properties against
 * @param  dir      the starting directory from which to search for
 *                  properties files
 * @return          the configuration mapping
 */
protected mapping read_config(string zone, string dir) {
  mapping result = ([ ]);  
  while (dir = dirname(dir)) {
    mapping props = read_properties(dir + "/" PROP_FILE);
    if (props) {
      foreach (string prop : ALLOWED_PROPS) {
        string val = read_prop_value(props, prop, dir, zone);
        if (val) {
          switch (prop) {
            case "output":
              if (!member(result, "output")) {
                mixed *output = parse_output_prop(val);
                if (output) {
                  result["output"] = output;
                }
              }
              break;
            case "format":
              if (!member(result, "format")) {
                result["format"] = val;
              }
              break;
            case "level":
              if (!member(result, "level")) {
                if (member(LEVELS, val) != -1) {
                  result["level"] = val;
                }
              }
              break;
          }
        }
        if (sizeof(result) == sizeof(ALLOWED_PROPS)) { break; }
      }
      if (sizeof(result) == sizeof(ALLOWED_PROPS)) { break; }
    }
  }
  return result;
}

/**
 * Parse a properties file into a mapping of property names to their values.
 * Properties are defined in a single line, of the format "name=value". Lines
 * beginning with "#" will be treated as comments.
 *
 * @param  prop_file the path to the property file
 * @return           a mapping of property names to values, or 0 if the file
 *                   could not be read
 */
protected mapping read_properties(string prop_file) {
  mapping result = ([ ]);
  int count = 0;

  string body = read_file(prop_file);
  if (!body) {
    return 0;
  }
  string *lines = explode(body, "\n");
  foreach (string line : lines) {
    count++;
    if (!strlen(line)) { continue; }
    if (line[0] == '#') { continue; }

    int equals = member(line, '=');
    if (equals == -1) {
      factory_logger->warn("Malformed property on line %d of %s",
        count, prop_file);
      continue;
    }

    string prop = line[0..(equals-1)];
    string val = line[(equals+1)..];
    result[prop] = val;
  }
  return result;
}

/**
 * Look for a property in the property mapping by name which matches a
 * specific zone, and return its value.
 *
 * @param  props    the property map
 * @param  prop     the name of the property to find
 * @param  path     zones in the property file will be resolved relative
 *                  to this path (delimited by periods)
 * @param  zone     the zone which a property must match to be returned
 * @return          the property value for the specified property name and
 *                  zone, or 0 if no matching property could be found
 */
protected string read_prop_value(mapping props, string prop, string path, 
                                 string zone) {
  if (zone[0..(strlen(path) - 1)] != path) {
    return 0;
  }
  string rel_zone = zone[strlen(path)..];
  while (1) {
    string prop_name = sprintf("%s%s.%s", PROP_PREFIX, rel_zone, prop);
    if (member(props, prop_name)) {
      return props[prop_name];
    }
    int pos = rmember(rel_zone, '.');
    if (pos < 0) {
      break;
    }
    rel_zone = rel_zone[0..(pos - 1)];
  }
  return 0;
}

/**
 * Translate the property value of an output property to something more
 * structured than a string. The result will be of the form:
 *
 * <code>({ ({ int type, string target }), ... })</code>
 *
 * where type is one of 'c' or 'f' and target is an object spec or a file
 * path, for console output or file output, respectively.
 *
 * @param  val the value of the output property
 * @return     an array of output targets
 */
protected mixed *parse_output_prop(string val) {
  mixed *result = ({ });
  string *targets = explode(val, ",");
  foreach (string spec : targets) {
    if (spec[1] != ':') {
      factory_logger->warn("Malformed output spec: %s", spec);
      continue;
    }
    int type = spec[0];
    string target = spec[2..];
    result += ({ ({ type, target }) });
  }
  return result;
}

/**
 * Return a new no-op logger.
 * @return the logger instance
 */
public object get_null_logger() {
  object logger = clone_object(Logger);
  logger->set_zone("");
  logger->set_output(({ }));
  logger->set_formatter("");
  logger->set_level(LVL_OFF);
  return logger;
}

/**
 * Releases a logger object from the logger pool, thereby removing any
 * references to it held by the factory. If there are no other references,
 * the logger will also be destructed.
 *
 * @param  zone     an object or string representing the zone; if an
 *                  object is specfied, it's load_name(E) will be used.
 * @param  euid     the euid of the logger to release
 * @return          1 if a logger was released, 0 if no logger was found
 */
public int release_logger(mixed zone, string euid) {
  mixed *pathinfo = get_path_info(zone);
  zone = pathinfo[PATH_INFO_ZONE];
  if (member(loggers, zone)) {
    object logger = loggers[zone][euid];
    if (logger) {
      m_delete(loggers[zone], euid);
      local_ref_counts[logger]--;
      int ref_count = (int) object_info(logger, OINFO_BASIC, OIB_REF);
      int local_ref_count = local_ref_counts[logger];
      if ((ref_count - local_ref_count) <= STANDING_REF_COUNT) {
        m_delete(local_ref_counts, logger);
        destruct(logger);
      }
      if (!sizeof(loggers[zone])) {
        m_delete(loggers, zone);
      }
      return 1;
    }
  }
  return 0;
}

/**
 * Clean up stale loggers, called once per reset. A logger is considered
 * stale if it hasn't been referenced in 5 minutes, and is referenced by
 * nothing except the LoggerFactory.
 *
 * @return the number of logging zones released (may be more than the
 *         number loggers destructed if loggers are shared between zones)
 */
protected int clean_up_loggers() {
  int result = 0;
  foreach (string zone, mapping euids : loggers) {
    foreach (string euid, object logger : euids) {
      if (!logger) { continue; }

      int ref_time = (int) object_info(logger, OINFO_BASIC, OIB_TIME_OF_REF);
      if ((time() - ref_time) >= LOGGER_STALE_TIME) {
        result += release_logger(zone, euid);
      }
    }
  }
  return result;
}


/**
 * To keep things from getting really confusing, we have two statically
 * configured loggers, one for the factory itself to use, and one for all
 * loggers to use.
 */
protected void init_static_loggers() {
  string euid = geteuid();

  seteuid(LOGGER_LOGGER_UID);
  logger_logger = clone_object(Logger);
  export_uid(logger_logger);
  logger_logger->set_level(LVL_DEBUG);
#ifdef EOTL
  logger_logger->set_output(parse_output_prop("a:me"));
#else
  logger_logger->set_output(parse_output_prop("c:me"));
#endif
  logger_logger->set_formatter(
    parse_format(DEFAULT_FORMAT, LOGGER_MESSAGE,
                 ({ 'zone, 'priority, 'message, 'caller }))
  );
  logger_logger->set_zone(get_zone(THISO));

  seteuid(FACTORY_LOGGER_UID);
  factory_logger = clone_object(Logger);
  export_uid(factory_logger);
  factory_logger->set_level(LVL_WARN);
  factory_logger->set_output(parse_output_prop("f:/log/logger_factory.log"));
  factory_logger->set_formatter(
    parse_format(DEFAULT_FORMAT, LOGGER_MESSAGE,
                 ({ 'zone, 'priority, 'message, 'caller }))
  );
  factory_logger->set_zone(get_zone(THISO));

  seteuid(euid);
  return;
}

/**
 * Initialize logger and formatter maps.
 *
 * @return number of seconds until first reset
 */
public void create() {
  setup();
}

/**
 * Clean up stale loggers.
 * @return number of seconds until next reset
 */
public int reset() {
  clean_up_loggers();
  return FACTORY_RESET_TIME;
}

