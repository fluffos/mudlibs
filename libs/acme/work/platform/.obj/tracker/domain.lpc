/**
 * A service object for tracking domain configurations.
 *
 * @author devo@eotl
 * @alias DomainTracker
 */
#pragma no_clone
#include <sys/xml.h>
#include <domain.h>

private inherit FileLib;
private inherit DomainLib;

// ([ str domain_id : DomainConfig domain ])
private mapping domains;
// ([ str domain_id : ([ string child_id, ... ]) ])
private mapping children;
// ([ str domain_root : DomainConfig domain ])
private mapping domain_roots;

public void setup();
public void reconfig_signal(string file, string func);
protected struct DomainConfig parse_config(string domain_file);
protected void parse_directive(mixed *tag, struct DomainConfig config,
                               mixed *read_checker, mixed *write_checker);
protected void parse_configure_access(mixed *tag, mixed *read_checker,
                                      mixed *write_checker);
protected string get_parent_domain_file(string domain_file);
protected string get_domain_root(string domain_file);
protected int update_domain(struct DomainConfig config);
protected int delete_domain(struct DomainConfig config);
string query_domain_id(string path);
mapping query_children(string domain_id);
public string resolve_sysinclude(string file, string p);

/**
 * Setup the DomainTracker.
 */
public void setup() {
  FileTracker->subscribe(DOMAIN_FILE_REGEX, #'reconfig_signal); //'
  domains = ([ ]);
  children = ([ ]);
  domain_roots = ([ ]);
}

/**
 * Called when a domain.xml file is modified or removed.
 *
 * @param file path to domain.xml file
 * @param func write method (see valid_write())
 */
public void reconfig_signal(string file, string func) {
  object logger = LoggerFactory->get_logger(THISO);

  if (file_exists(file)) {
    struct DomainConfig config = parse_config(file);
    if (!config) {
      logger->warn("unable to parse config %O", file);
      return;
    }
    if (!update_domain(config)) {
      logger->warn("unable to update domain %O", config->domain_id);
      return;
    }
  } else {
    struct DomainConfig config = domains[query_domain_id(file)];
    if (config) {
      if (!delete_domain(config)) {
        logger->warn("unable to delete domain %O", config->domain_id);
        return;
      }
    }
  }
  return;
}

/**
 * Parse the configuration found by specified file and return it.
 *
 * @param  domain_file the domain.xml file to parse
 * @return             the parsed domain configuration
 */
protected struct DomainConfig parse_config(string domain_file) {
  object logger = LoggerFactory->get_logger(THISO);
  struct DomainConfig config = (<DomainConfig>);

  // root dir for
  config->root = get_domain_root(domain_file);

  // populate parent (parsing ancestor config(s) if necessary)
  struct DomainConfig parent_config;
  string parent_file = get_parent_domain_file(domain_file);
  if (parent_file) {
    string parent_root = get_domain_root(parent_file);
    if (member(domain_roots, parent_root)) {
      parent_config = domain_roots[parent_root];
    } else {
      parent_config = parse_config(parent_file);
      if (!parent_config) {
        logger->warn("unable to parse parent config %O", parent_file);
        return 0;
      }
      update_domain(parent_config);
    }
  }
  if (parent_config) {
    config->parent = parent_config->domain_id;
  }

  mixed *xml = xml_parse(read_file(domain_file));
  if (xml[XML_TAG_NAME] != "domain") {
    logger->info("invalid domain.xml: root tag must be <domain>");
    return 0;
  }
  if (!member(xml[XML_TAG_ATTRIBUTES], "id")) {
    logger->info("invalid domain.xml: root domain tag missing id attribute");
    return 0;
  }
  config->id = xml[XML_TAG_ATTRIBUTES]["id"];
  if (parent_config) {
    config->domain_id = parent_config->domain_id + DOMAIN_DELIM + config->id;
  } else {
    config->domain_id = config->id;
  }

  // initialize checkers
  mixed *read_checker =
    ({ #',,
       ({ #'=, 'result, 0 }) //'
    });
  mixed *write_checker = deep_copy(read_checker);

  // parse config directives
  if (pointerp(xml[XML_TAG_CONTENTS])) {
    foreach (mixed *tag : xml[XML_TAG_CONTENTS]) {
      parse_directive(tag, config, &read_checker, &write_checker);
    }
  }

  // finalize and compile checkers
  read_checker += ({ ({ #'return, 'result }) });
  write_checker += ({ ({ #'return, 'result }) });
  config->allow_read = lambda(
    ({ 'path, 'user, 'groups, 'domain, 'flavor, 'program }),
    read_checker
  );
  config->allow_write = lambda(
    ({ 'path, 'user, 'groups, 'domain, 'flavor, 'program }),
    write_checker
  );

  return config;
}

/**
 * Parse a configuration directive.
 *
 * @param tag           the XML tag specifying the directive
 * @param config        the domain config being built
 * @param read_checker  a partial closure which will completed with read
 *                      access logic
 * @param write_checker a partial closure which will be completed with write
 *                      access logic
 */
protected void parse_directive(mixed *tag, struct DomainConfig config,
                               mixed *read_checker, mixed *write_checker) {
  if (tag[XML_TAG_NAME] == "configureAccess") {
    parse_configure_access(tag, &read_checker, &write_checker);
  }
  return;
}

/**
 * Parse the "configureAccess" configuration directive.
 *
 * @param tag           the configureAccess tag
 * @param read_checker  a partial closure which will completed with read
 *                      access logic
 * @param write_checker a partial closure which will be completed with write
 *                      access logic
 */
protected void parse_configure_access(mixed *tag, mixed *read_checker,
                                      mixed *write_checker) {
  object logger = LoggerFactory->get_logger(THISO);

  // condition blocks for whether to apply this config at all
  mixed *relativePath, *startsWith, *endsWith;
  if (member(tag[XML_TAG_ATTRIBUTES], "relativePath")) {
    relativePath =
      ({ #'==,
         'path,  //'
         tag[XML_TAG_ATTRIBUTES]["relativePath"]
      });
  }
  if (member(tag[XML_TAG_ATTRIBUTES], "startsWith")) {
    startsWith =
      ({ #'==,
         ({ #'[..],
            'path,  //'
            0,
            strlen(tag[XML_TAG_ATTRIBUTES]["startsWith"]) - 1
         }),
         tag[XML_TAG_ATTRIBUTES]["startsWith"]
      });
  }
  if (member(tag[XML_TAG_ATTRIBUTES], "endsWith")) {
    endsWith =
      ({ #'==,
         ({ #'[<..,
            'path,  //'
            strlen(tag[XML_TAG_ATTRIBUTES]["endsWith"])
         }),
         tag[XML_TAG_ATTRIBUTES]["endsWith"]
      });
  }
  // build the condition
  read_checker += ({ #'?, ({ #'&& }) });
  write_checker += ({ #'?, ({ #'&& }) });
  if (relativePath) {
    read_checker[<1] += ({ relativePath });
    write_checker[<1] += ({ relativePath });
  }
  if (startsWith) {
    read_checker[<1] += ({ startsWith });
    write_checker[<1] += ({ startsWith });
  }
  if (endsWith) {
    read_checker[<1] += ({ endsWith });
    write_checker[<1] += ({ endsWith });
  }

  if (pointerp(tag[XML_TAG_CONTENTS])) {
    // configure the target objects this operation applies to
    foreach (mixed *op : tag[XML_TAG_CONTENTS]) {
      mapping users, groups, domains, flavors, programs;
      if (member(op[XML_TAG_ATTRIBUTES], "users")) {
        users = mkmapping(filter(explode(
                  op[XML_TAG_ATTRIBUTES]["users"], ","
                ), #'trim)); //'
      }
      if (member(op[XML_TAG_ATTRIBUTES], "groups")) {
        groups = mkmapping(filter(explode(
                  op[XML_TAG_ATTRIBUTES]["groups"], ","
                ), #'trim)); //'
      }
      if (member(op[XML_TAG_ATTRIBUTES], "domains")) {
        domains = mkmapping(filter(explode(
                  op[XML_TAG_ATTRIBUTES]["domains"], ","
                ), #'trim)); //'
      }
      if (member(op[XML_TAG_ATTRIBUTES], "flavors")) {
        domains = mkmapping(filter(explode(
                  op[XML_TAG_ATTRIBUTES]["flavors"], ","
                ), #'trim)); //'
      }
      if (member(op[XML_TAG_ATTRIBUTES], "programs")) {
        programs = mkmapping(filter(explode(
                  op[XML_TAG_ATTRIBUTES]["programs"], ","
                ), #'trim)); //'
      }

      // figure out what operation/permission we're configuring
      mixed *checker;
      int perm = -1;
      // new ops for load/clone/dest ?
      switch (op[XML_TAG_NAME]) {
      case "allowRead":
        read_checker += ({ 0 });
        checker = read_checker;
        perm = 1;
        break;
      case "allowWrite":
        write_checker += ({ 0 });
        checker = write_checker;
        perm = 1;
        break;
      case "denyRead":
        read_checker += ({ 0 });
        checker = read_checker;
        perm = 0;
        break;
      case "denyWrite":
        write_checker += ({ 0 });
        checker = write_checker;
        perm = 0;
        break;
      default:
        logger->info("invalid domain.xml: unknown configureAccess "
                     "operation: %O", op[XML_TAG_NAME]);
        break;
      }

      // build the condition and set the result if necessary
      if (checker) {
        mixed *cond = ({ #'|| }); //'
        if (users) {
          cond += ({ ({ #'member, users, 'user }) });
        }
        if (groups) {
          cond += ({ ({ #'sizeof, ({ #'-, groups, 'groups }) }) }); //'
        }
        if (domains) {
          cond += ({ ({ #'member, domains, 'domain }) });
        }
        if (flavors) {
          cond += ({ ({ #'member, flavors, 'flavor }) });
        }
        if (programs) {
          cond += ({ ({ #'member, programs, 'program }) });
        }
        checker[<1] = ({ #'?, cond, ({ #'=, 'result, perm }) }); //'
      }

    }
  }

  return;
}

/**
 * For a specified domain file, return the parent domain file, or 0 if no
 * parent domain exists.
 *
 * @param  domain_file the child domain file
 * @return             the parent domain file, or 0
 */
protected string get_parent_domain_file(string domain_file) {
  string dir = get_domain_root(domain_file);
  while (strlen(dir = dirname(dir))) {
    string file = dir + "/" DOMAIN_FILE;
    if (file_exists(file)) {
      return file;
    }
  }
  return 0;
}

/**
 * For a specified domain file, return the root dir for that domain.
 *
 * @param  domain_file the path to the domain file
 * @return             the domain root
 */
protected string get_domain_root(string domain_file) {
  return domain_file[0..<(strlen(DOMAIN_FILE) + 2)];
}

/**
 * Create a new domain or update an existing one.
 *
 * @param  config the domain configuration to update
 * @return        1 if confguration was successfully updated, otherwise 0
 */
protected int update_domain(struct DomainConfig config) {
  object logger = LoggerFactory->get_logger(THISO);
  // make sure incoming domain doesn't cause a id collision
  if (member(domains, config->domain_id)) {
    if (domains[config->domain_id]->root != config->root) {
      logger->info("new domain config at root %O conflicts with domain root "
                   "%O", config->root, domains[config->domain_id]->root);
      return 0;
    }
  }

  // removing existing domain at this root
  if (member(domain_roots, config->root)) {
    struct DomainConfig existing = domain_roots[config->root];
    string parent = existing->parent;
    if (parent) {
      m_delete(children[parent], existing->domain_id);
    }
    m_delete(domains, existing->domain_id);
    m_delete(domain_roots, config->root);
  }

  // add new config
  if (config->parent) {
    if (!children[config->parent]) {
      children[config->parent] = ([ ]);
    }
    children[config->parent] += ([ config->domain_id ]);
  }
  domains[config->domain_id] = config;
  domain_roots[config->root] = config;
  return 1;
}

/**
 * Delete a domain.
 *
 * @param  config the domain configuration to delete
 * @return        1 if domain was successfully deleted, otherwise 0
 */
protected int delete_domain(struct DomainConfig config) {
  object logger = LoggerFactory->get_logger(THISO);
  // make sure deleting subdomain won't cause sibling domain collision
  if (member(children, config->domain_id)) {
    string parent = "";
    if (config->parent) {
      parent = config->parent + DOMAIN_DELIM;
    }
    foreach (string child_id : children[config->domain_id]) {
      string id = domains[child_id]->id;
      if (member(domains, parent + id)) {
        logger->info("deleting config %O would cause sibling id collision",
                     config->domain_id);
        return 0;
      }
    }
  }

  // remove us from tracked domains
  m_delete(domain_roots, config->root);
  m_delete(domains, config->domain_id);

  // remove us from our parent's children
  if (config->parent) {
    m_delete(children[config->parent], config->domain_id);
  }

  // update our children to now belong to our parent
  if (member(children, config->domain_id)) {
    foreach (string child_id : children[config->domain_id]) {
      struct DomainConfig child = domains[child_id];
      child->parent = config->parent;
      m_delete(domains, child_id);
      if (child->parent) {
        child->domain_id = child->parent + DOMAIN_DELIM + child->id;
      } else {
        child->domain_id = child->id;
      }
      domains[child->domain_id] = child;
      children[config->parent] += ([ child->domain_id ]);
    }
  }

  return 1;
}

/**
 * For a given filesystem path, return the domain id the file belongs to.
 * Will discover new domains from domain.xml files if necessary.
 *
 * @param  path the path of the file for which to get domain
 * @return      the domain id of the file, or 0 if no domain could be found
 */
string query_domain_id(string path) {
  object logger = LoggerFactory->get_logger(THISO);
  do {
    if (member(domain_roots, path)) {
      return domain_roots[path]->domain_id;
    } else {
      string domain_file = path + "/" DOMAIN_FILE;
      if (file_exists(domain_file)) {
        struct DomainConfig config = parse_config(domain_file);
        if (!config) {
          logger->warn("unable to parse config %O", domain_file);
          return 0;
        }
        if (!update_domain(config)) {
          logger->warn("unable to update config %O", config->domain_id);
          return 0;
        }
        return config->domain_id;
      }
    }
  } while(path = dirname(path));
  return 0;
}

/**
 * Get the domain configuration for a specified domain id.
 *
 * @param  domain_id the domain id to get
 * @return           the DomainConfig of the specified id, or 0 if no domain
 *                   was found
 * @deprecated
 */
struct DomainConfig query_domain(string domain_id) {
  raise_error("FIXME");
  return deep_copy(domains[domain_id]);
}

/**
 * Get a list of child domains belonging to a specified domain.
 *
 * @param  domain_id the parent domain id
 * @return           a 1-d mapping of child domain ids
 */
mapping query_children(string domain_id) {
  if (!member(children, domain_id)) {
    return ([ ]);
  }
  return copy(children[domain_id]);
}

/**
 * Resolve a sysinclude (<file> style include) for files in a domain. First
 * the domain's .include/ directory will be tried, if no matching file was
 * found, the global include directory will be searched. The ".." directory
 * in the include path will back up not just one directory but one entire
 * domain, even if that domain spans multiple levels of the directory tree.
 * The parent domain's ".include/" directory will be searched for the file
 * path instead.
 *
 * @param  file the file (possibly relative) being included
 * @param  p    the compilation unit performing the include
 * @return      the resolved include file
 */
public string resolve_sysinclude(string file, string p) {
  if (p[<15..<1] == " (auto include)") {
    p = p[0..<16];
  }
  struct DomainConfig domain = deep_copy(domains[query_domain_id(p)]);

  string path = file;
  if (file[0] != '/') {
    path = domain->root + _IncludeDir "/" + file;
  }
  string *parts = explode(path, "/");
  parts -= ({ ".", "" });
  for (int i = 0; i < sizeof(parts); i++) {
    if (parts[i] == "..") {
      string id = query_domain_id("/" + implode(parts[0..(i - 1)], "/"));
      struct DomainConfig dc = query_domain(id);
      struct DomainConfig parent;
      if (dc->parent) {
        parent = query_domain(dc->parent);
      }
      if (parent) {
        parts = explode(parent->root, "/")[1..];
        i = sizeof(parts);
        parts += ({ _IncludeDir[0..<2] }) + parts[(i + 1)..];
      } else {
        i = 0;
        parts = ({ _IncludeDir[0..<2] }) + parts[(i + 1)..];
      }
    }
  }
  path = "/" + implode(parts, "/");
  if (!file_exists(path)) {
    path = file;
    if (file[0] != '/') {
      path = PlatformIncludeDir "/" + file;
    }
  }
  return path;
}

/**
 * Constructor. Make sure LoggerFactory and FileTracker have been preloaded.
 */
public void create() {
  // couple sanity checks
  if (!FINDO(LoggerFactory)) {
    destruct(THISO);
    raise_error("LoggerFactory must be preloaded for DomainTracker to "
                  "function properly\n");
  } 
  if (!FINDO(FileTracker)) {
    destruct(THISO);
    raise_error("FileTracker must be preloaded for DomainTracker to "
                  "function properly\n");
  } 
  setup();
}
