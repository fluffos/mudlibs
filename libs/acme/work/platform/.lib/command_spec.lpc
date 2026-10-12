/**
 * Library for parsing a command spec file.
 *
 * @author devo
 * @alias CommandSpecLib
 */
#include <sys/xml.h>
#include <command_spec.h>
#include <command.h>

inherit FileLib;

object logger = LoggerFactory->get_logger(THISO);

mixed *load_command_spec(string specfile);
mixed *parse_commands_xml(string specfile, mixed *xml);
varargs mixed *parse_command_xml(string specfile, mixed *xml, 
                                 mapping subcommand_map);
mixed *parse_fields_xml(string specfile, mixed *xml, mapping field_map);
mixed *parse_field_xml(string specfile, mixed *xml);
mixed *parse_args_xml(string specfile, mixed *xml, mapping field_map, 
                      mapping arg_lists);
mixed *parse_arg_xml(string specfile, mixed *xml, mapping field_map);
mixed *parse_opts_xml(string specfile, mixed *xml, mapping field_map, 
                      mapping opt_sets);
mixed *parse_opt_xml(string specfile, mixed *xml, mapping field_map);
mixed *parse_enum_xml(string specfile, mixed *xml);
mixed *parse_enum_value_xml(string specfile, mixed *xml);
mixed *parse_prompt_xml(string specfile, mixed *xml);
mixed *parse_validate_xml(string specfile, mixed *xml);
mixed *parse_syntax_xml(string specfile, mixed *xml, mapping field_map,
                        mapping arg_lists, mapping opt_sets, 
                        mapping subcommand_map);
mixed *parse_import_xml(string specfile, mixed *xml, mapping imports);
int parse_boolean(string value);
void parse_error(string specfile, string msg);

/**
 * Load a command specfile. See program doc for what a loaded command spec
 * value looks like.
 * 
 * @param  specfile      the spec filename
 * @return the loaded commands
 */
mixed *load_command_spec(string specfile) {
  mixed *xml = xml_parse(read_file(specfile));
  return parse_commands_xml(specfile, xml);
}

/**
 * Parse the &lt;commands&gt; tag.
 * 
 * @param  specfile      the spec filename
 * @param  xml           the deserialized xml to parse
 * @return the loaded commands
 */
mixed *parse_commands_xml(string specfile, mixed *xml) {
  xml[XML_TAG_ATTRIBUTES] ||= ([ ]);

  if (xml[XML_TAG_NAME] != "commands") {
    parse_error(specfile, "unknown document root");
  }

  mapping imports = ([ ]);
  mixed *commands = ({ });
  foreach (mixed *el : xml[XML_TAG_CONTENTS]) {
    switch (el[XML_TAG_NAME]) {
      case "command":
        mixed *command = parse_command_xml(specfile, el);
        if (command) {
          commands += ({ command });
        }
        break;
      case "import":
        mixed *command = parse_import_xml(specfile, el, imports);
        if (command) {
          commands += ({ command });
        }
        break;
      default:
        parse_error(specfile, "unknown element " + el[XML_TAG_NAME]);
        break;
    }
  }

  return commands;
}

/**
 * Parse the &lt;command&gt; tag.
 * 
 * @param  specfile        the spec filename
 * @param  xml             the deserialized xml to parse
 * @param  subcommand_map  a mapping of subcommand ids to subcommands, 
 *                         passed by reference
 * @return the loaded command
 */
varargs mixed *parse_command_xml(string specfile, mixed *xml, 
                                 mapping subcommand_map) {
  xml[XML_TAG_ATTRIBUTES] ||= ([ ]);

  if (member(xml[XML_TAG_ATTRIBUTES], "ref")) {
    string ref = xml[XML_TAG_ATTRIBUTES]["ref"];
    if (subcommand_map && member(subcommand_map, ref)) {
      return subcommand_map[ref];
    } else {
      parse_error(specfile, "unknown subcommand reference " + ref);
    }
  } 
  
  string id;
  if (member(xml[XML_TAG_ATTRIBUTES], "id")) {
    id = xml[XML_TAG_ATTRIBUTES]["id"];
  }

  string controller;
  if (member(xml[XML_TAG_ATTRIBUTES], "controller")) {
    controller = xml[XML_TAG_ATTRIBUTES]["controller"];
  } else {
    parse_error(specfile, "missing attribute controller");
  }

  string *verbs;
  if (member(xml[XML_TAG_ATTRIBUTES], "primaryVerb")) {
    verbs = ({ xml[XML_TAG_ATTRIBUTES]["primaryVerb"] });
  } else {
    parse_error(specfile, "missing attribute primaryVerb");
  }

  int max_retry = DEFAULT_MAX_RETRY;
  if (member(xml[XML_TAG_ATTRIBUTES], "maxRetry")) {
    max_retry = to_int(xml[XML_TAG_ATTRIBUTES]["maxRetry"]);
  } 

  mixed *fields = ({ });
  mapping arg_lists = ([ ]);
  mapping opt_sets = ([ ]);
  mixed *syntax = ({ });
  mixed *validation = ({ });
  subcommand_map ||= ([ ]);
  mapping field_map = ([ ]);
  foreach (mixed *el : xml[XML_TAG_CONTENTS]) {
    switch (el[XML_TAG_NAME]) {
      case "fields":
        fields = parse_fields_xml(specfile, el, field_map);
        break;
      case "args":
        if (member(xml[XML_TAG_ATTRIBUTES], "id")) {
          arg_lists += ([
            xml[XML_TAG_ATTRIBUTES]["id"] :
            parse_args_xml(specfile, el, field_map, arg_lists)
          ]);
        }         
        break;
      case "opts":
        if (member(xml[XML_TAG_ATTRIBUTES], "id")) {
          opt_sets += ([
            xml[XML_TAG_ATTRIBUTES]["id"] :
            parse_opts_xml(specfile, el, field_map, opt_sets)
          ]);
        }         
        break;
      case "syntax":
        syntax += ({ parse_syntax_xml(specfile, el, field_map, 
                                      arg_lists, opt_sets, subcommand_map) });
        break;
      case "validate":
        validation += ({ parse_validate_xml(specfile, el) });
        break;
      case "subcommand":
        if (member(xml[XML_TAG_ATTRIBUTES], "id")) {
          subcommand_map += ([
            xml[XML_TAG_ATTRIBUTES]["id"] :
            parse_command_xml(specfile, el, subcommand_map)
          ]);
        }         
        break;
      default:
        parse_error(specfile, "unknown element " + el[XML_TAG_NAME]);
    }
  }

  return ({ id, controller, verbs, fields, syntax, validation, max_retry });
}

/**
 * Parse the &lt;fields&gt; tag.
 * 
 * @param  specfile        the spec filename
 * @param  xml             the deserialized xml to parse
 * @param  field_map       a mapping of field ids to fields
 * @return the loaded fields
 */
mixed *parse_fields_xml(string specfile, mixed *xml, mapping field_map) {
  xml[XML_TAG_ATTRIBUTES] ||= ([ ]);

  mixed *result = ({ });
  foreach (mixed *el : xml[XML_TAG_CONTENTS]) {
    switch (el[XML_TAG_NAME]) {
      case "field":
        mixed *field = parse_field_xml(specfile, el);
        if (field) {
          result += ({ field });
          field_map[field[FIELD_ID]] = field;
        }
        break;
      default:
        parse_error(specfile, "unknown element " + el[XML_TAG_NAME]);
        break;
    }
  }
  return result;
}

/**
 * Parse the &lt;field&gt; tag.
 * 
 * @param  specfile        the spec filename
 * @param  xml             the deserialized xml to parse
 * @return the loaded field
 */
mixed *parse_field_xml(string specfile, mixed *xml) {
  xml[XML_TAG_ATTRIBUTES] ||= ([ ]);

  string id;
  if (member(xml[XML_TAG_ATTRIBUTES], "id")) {
    id = xml[XML_TAG_ATTRIBUTES]["id"];
  } 

  string type;
  if (member(xml[XML_TAG_ATTRIBUTES], "type")) {
    type = xml[XML_TAG_ATTRIBUTES]["type"];
  } else {
    parse_error(specfile, "missing attribute type");
  }

  int required = 0;
  if (member(xml[XML_TAG_ATTRIBUTES], "required")) {
    required = parse_boolean(xml[XML_TAG_ATTRIBUTES]["required"]);
  } 

  string prompt_setting = DEFAULT_PROMPT;
  if (member(xml[XML_TAG_ATTRIBUTES], "prompt")) {
    prompt_setting = xml[XML_TAG_ATTRIBUTES]["prompt"];
  } 

  string default_val = 0;
  if (member(xml[XML_TAG_ATTRIBUTES], "default")) {
    default_val = xml[XML_TAG_ATTRIBUTES]["default"];
  }

  int max_retry = DEFAULT_MAX_RETRY;
  if (member(xml[XML_TAG_ATTRIBUTES], "maxRetry")) {
    max_retry = to_int(xml[XML_TAG_ATTRIBUTES]["maxRetry"]);
  } 

  mixed *enum, *prompt;
  mixed *validation = ({ });
  foreach (mixed *el : xml[XML_TAG_CONTENTS]) {
    switch (el[XML_TAG_NAME]) {
      case "enum":
        enum = parse_enum_xml(specfile, el);
        break;
      case "prompt":
        prompt = parse_prompt_xml(specfile, el);
        break;
      case "validate":
        validation += ({ parse_validate_xml(specfile, el) });
        break;
      default:
        parse_error(specfile, "unknown element " + el[XML_TAG_NAME]);
        break;
    }
  }

  return ({ id, type, required, prompt_setting, max_retry, default_val, enum, 
            prompt, validation });
}

/**
 * Parse the &lt;args&gt; tag.
 * 
 * @param  specfile        the spec filename
 * @param  xml             the deserialized xml to parse
 * @param  field_map       a mapping of field ids to fields
 * @param  arg_lists       a mapping of args ids to args
 * @return the loaded args
 */
mixed *parse_args_xml(string specfile, mixed *xml, mapping field_map, 
                      mapping arg_lists) {
  xml[XML_TAG_ATTRIBUTES] ||= ([ ]);

  if (member(xml[XML_TAG_ATTRIBUTES], "ref")) {
    string ref = xml[XML_TAG_ATTRIBUTES]["ref"];
    if (arg_lists && member(arg_lists, ref)) {
      return arg_lists[ref];
    } else {
      parse_error(specfile, "unknown args reference " + ref);
    }
  } 

  mixed *args = ({ });
  foreach (mixed *el : xml[XML_TAG_CONTENTS]) {
    switch (el[XML_TAG_NAME]) {
      case "arg":
        mixed *arg = parse_arg_xml(specfile, el, field_map);
        if (arg) {
          args += ({ arg });
        }
        break;
      default:
        parse_error(specfile, "unknown element " + el[XML_TAG_NAME]);
        break;
    }
  }

  return args;
}

/**
 * Parse the &lt;arg&gt; tag.
 * 
 * @param  specfile        the spec filename
 * @param  xml             the deserialized xml to parse
 * @param  field_map       a mapping of field ids to fields
 * @return the loaded arg
 */
mixed *parse_arg_xml(string specfile, mixed *xml, mapping field_map) {
  xml[XML_TAG_ATTRIBUTES] ||= ([ ]);

  if (member(xml[XML_TAG_ATTRIBUTES], "fieldRef")) {
    return field_map[xml[XML_TAG_ATTRIBUTES]["fieldRef"]];
  } else {
    return parse_field_xml(specfile, xml);
  }
}

/**
 * Parse the &lt;opts&gt; tag.
 * 
 * @param  specfile        the spec filename
 * @param  xml             the deserialized xml to parse
 * @param  field_map       a mapping of field ids to fields
 * @param  opt_sets        a mapping of opts ids to opts
 * @return the loaded opts
 */
mixed *parse_opts_xml(string specfile, mixed *xml, mapping field_map, 
                      mapping opt_sets) {
  xml[XML_TAG_ATTRIBUTES] ||= ([ ]);

  if (member(xml[XML_TAG_ATTRIBUTES], "ref")) {
    string ref = xml[XML_TAG_ATTRIBUTES]["ref"];
    if (opt_sets && member(opt_sets, ref)) {
      return opt_sets[ref];
    } else {
      parse_error(specfile, "unknown opts reference " + ref);
    }
  } 

  mixed *opts = ({ });
  mixed *longopts = ({ });
  foreach (mixed *el : xml[XML_TAG_CONTENTS]) {
    switch (el[XML_TAG_NAME]) {
      case "opt":
        mixed *opt = parse_opt_xml(specfile, el, field_map);
        if (opt) {
          opts += ({ opt });
        }
        break;
      case "longopt":
        mixed *longopt = parse_opt_xml(specfile, el, field_map);
        if (longopt) {
          longopts += ({ longopt });
        }
        break;
      default:
        parse_error(specfile, "unknown element " + el[XML_TAG_NAME]);
        break;
    }
  }

  return ({ opts, longopts });
}

/**
 * Parse the &lt;opt&gt; tag.
 * 
 * @param  specfile        the spec filename
 * @param  xml             the deserialized xml to parse
 * @param  field_map       a mapping of field ids to fields
 * @return the loaded opt
 */
mixed *parse_opt_xml(string specfile, mixed *xml, mapping field_map) {
  xml[XML_TAG_ATTRIBUTES] ||= ([ ]);

  mixed *result;

  if (member(xml[XML_TAG_ATTRIBUTES], "fieldRef")) {
    result = field_map[xml[XML_TAG_ATTRIBUTES]["fieldRef"]];
  } else {
    result = parse_field_xml(specfile, xml);
  }

  if (member(xml[XML_TAG_ATTRIBUTES], "param")) {
    result += ({ xml[XML_TAG_ATTRIBUTES]["param"] });
  } 

  if (member(xml[XML_TAG_ATTRIBUTES], "multi")) {
    result += ({ parse_boolean(xml[XML_TAG_ATTRIBUTES]["multi"]) });
  } else {
    result += ({ DEFAULT_OPT_MULTI });
  }

  return result;
} 

/**
 * Parse the &lt;enum&gt; tag.
 * 
 * @param  specfile        the spec filename
 * @param  xml             the deserialized xml to parse
 * @return the loaded enum
 */
mixed *parse_enum_xml(string specfile, mixed *xml) {
  xml[XML_TAG_ATTRIBUTES] ||= ([ ]);

  string id;
  if (member(xml[XML_TAG_ATTRIBUTES], "id")) {
    id = xml[XML_TAG_ATTRIBUTES]["id"];
  } 

  int multi = DEFAULT_ENUM_MULTI;
  if (member(xml[XML_TAG_ATTRIBUTES], "multi")) {
    multi = parse_boolean(xml[XML_TAG_ATTRIBUTES]["multi"]);
  } 

  string delim = DEFAULT_DELIM;
  if (member(xml[XML_TAG_ATTRIBUTES], "delim")) {
    delim = xml[XML_TAG_ATTRIBUTES]["delim"];
  } 

  mixed *values = ({ });
  foreach (mixed *el : xml[XML_TAG_CONTENTS]) {
    switch (el[XML_TAG_NAME]) {
      case "value":
        values += ({ parse_enum_value_xml(specfile, el) });
        break;
      default:
        parse_error(specfile, "unknown element " + el[XML_TAG_NAME]);
        break;
    }
  }

  return ({ id, multi, delim, values });
}

/**
 * Parse the &lt;value&gt; tag.
 * 
 * @param  specfile        the spec filename
 * @param  xml             the deserialized xml to parse
 * @return the loaded enum value
 */
mixed *parse_enum_value_xml(string specfile, mixed *xml) {
  xml[XML_TAG_ATTRIBUTES] ||= ([ ]);

  string value;
  if (member(xml[XML_TAG_ATTRIBUTES], "value")) {
    value = xml[XML_TAG_ATTRIBUTES]["value"];
  } else {
    parse_error(specfile, "missing attribute value");
  }

  string label;
  if (member(xml[XML_TAG_ATTRIBUTES], "label")) {
    label = xml[XML_TAG_ATTRIBUTES]["label"];
  } 

  string type;
  if (member(xml[XML_TAG_ATTRIBUTES], "type")) {
    type = xml[XML_TAG_ATTRIBUTES]["type"];
  } else {
    parse_error(specfile, "missing attribute type");
  }

  return ({ value, label, type });
}

/**
 * Parse the &lt;prompt&gt; tag.
 * 
 * @param  specfile        the spec filename
 * @param  xml             the deserialized xml to parse
 * @return the loaded prompt
 */
mixed *parse_prompt_xml(string specfile, mixed *xml) {
  xml[XML_TAG_ATTRIBUTES] ||= ([ ]);

  int no_echo = DEFAULT_NO_ECHO;
  if (member(xml[XML_TAG_ATTRIBUTES], "noEcho")) {
    no_echo = parse_boolean(xml[XML_TAG_ATTRIBUTES]["noEcho"]);
  } 

  string msg = xml[XML_TAG_CONTENTS][0]; // TODO parse message

  return ({ no_echo, msg });
}

/**
 * Parse the &lt;validate&gt; tag.
 * 
 * @param  specfile        the spec filename
 * @param  xml             the deserialized xml to parse
 * @return the loaded validation
 */
mixed *parse_validate_xml(string specfile, mixed *xml) {
  xml[XML_TAG_ATTRIBUTES] ||= ([ ]);

  string validator;
  if (member(xml[XML_TAG_ATTRIBUTES], "validator")) {
    validator = xml[XML_TAG_ATTRIBUTES]["validator"];
  } else {
    parse_error(specfile, "missing attribute validator");
  }

  int negate = DEFAULT_NEGATE;
  if (member(xml[XML_TAG_ATTRIBUTES], "negate")) {
    negate = parse_boolean(xml[XML_TAG_ATTRIBUTES]["negate"]);
  } 

  string fail = 0;
  string *params = ({ });
  foreach (mixed *el : xml[XML_TAG_CONTENTS]) {
    switch (el[XML_TAG_NAME]) {
      case "param":
        params += ({ el[XML_TAG_ATTRIBUTES]["value"] });
        break;
      case "fail":
        fail = el[XML_TAG_CONTENTS][0]; // TODO parse message
        break;
      default:
        parse_error(specfile, "unknown element " + el[XML_TAG_NAME]);
        break;
    }
  }

  return ({ validator, fail, params, negate });
}

/**
 * Parse the &lt;syntax&gt; tag.
 * 
 * @param  specfile        the spec filename
 * @param  xml             the deserialized xml to parse
 * @param  field_map       a mapping of field ids to fields
 * @param  arg_lists       a mapping of args ids to args
 * @param  opt_sets        a mapping of opts ids to opts
 * @param  subcommand_map  a mapping of subcommand ids to subcommands, 
 *                         passed by reference
 * @return the loaded enum
 */
mixed *parse_syntax_xml(string specfile, mixed *xml, mapping field_map,
                        mapping arg_lists, mapping opt_sets, 
                        mapping subcommand_map) {
  xml[XML_TAG_ATTRIBUTES] ||= ([ ]);

  int explode_args = -1;
  if (member(xml[XML_TAG_ATTRIBUTES], "explodeArgs")) {
    explode_args = to_int(xml[XML_TAG_ATTRIBUTES]["explodeArgs"]);
  } 

  int min_args = -1;
  if (member(xml[XML_TAG_ATTRIBUTES], "minArgs")) {
    min_args = to_int(xml[XML_TAG_ATTRIBUTES]["minArgs"]);
  } 

  int max_args = -1;
  if (member(xml[XML_TAG_ATTRIBUTES], "maxArgs")) {
    max_args = to_int(xml[XML_TAG_ATTRIBUTES]["maxArgs"]);
  } 

  string pattern;
  if (member(xml[XML_TAG_ATTRIBUTES], "pattern")) {
    pattern = xml[XML_TAG_ATTRIBUTES]["pattern"];
  }

  string format = DEFAULT_FORMAT;
  if (member(xml[XML_TAG_ATTRIBUTES], "format")) {
    format = xml[XML_TAG_ATTRIBUTES]["format"];
  }

  mixed *args = ({ });
  mixed *opts = ({ });
  mixed *longopts = ({ });
  mixed *validation = ({ });
  mixed *subcommands = ({ });
  foreach (mixed *el : xml[XML_TAG_CONTENTS]) {
    switch (el[XML_TAG_NAME]) {
      case "args":
        args = parse_args_xml(specfile, el, field_map, arg_lists);
        break;
      case "opts":
        opts += parse_opts_xml(specfile, el, field_map, opt_sets);
        break;
      case "opt":
        opts += ({ parse_opt_xml(specfile, el, field_map) });
        break;
      case "longopt":
        longopts += ({ parse_opt_xml(specfile, el, field_map) });
        break;
      case "validate":
        validation += ({ parse_validate_xml(specfile, el) });
        break;
      case "subcommand":
        subcommands += ({
          parse_command_xml(specfile, el, subcommand_map)
        });
        break;
      default:
        parse_error(specfile, "unknown element " + el[XML_TAG_NAME]);
        break;
    }
  }

  return ({ explode_args, min_args, max_args, pattern, format, 
            args, opts, longopts, validation, subcommands });
}

/**
 * Parse the &lt;import&gt; tag.
 * 
 * @param  specfile        the spec filename
 * @param  xml             the deserialized xml to parse
 * @param  imports         a mapping of imported specfiles to imported
 *                         commands, passed by reference
 * @return the imported command
 */
mixed *parse_import_xml(string specfile, mixed *xml, mapping imports) {
  xml[XML_TAG_ATTRIBUTES] ||= ([ ]);
  string id;
  if (member(xml[XML_TAG_ATTRIBUTES], "id")) {
    id = xml[XML_TAG_ATTRIBUTES]["id"];
  }

  string spec;
  if (member(xml[XML_TAG_ATTRIBUTES], "spec")) {
    spec = xml[XML_TAG_ATTRIBUTES]["spec"];
  } else {
    parse_error(specfile, "missing attribute spec");
  }

  string primary_verb;
  if (member(xml[XML_TAG_ATTRIBUTES], "primaryVerb")) {
    primary_verb = xml[XML_TAG_ATTRIBUTES]["primaryVerb"];
  } else {
    parse_error(specfile, "missing attribute primaryVerb");
  }

  mixed *commands = imports[spec];
  if (!commands) {
    commands = load_command_spec(expand_path(spec, specfile));
    imports[spec] = commands;
  }
  foreach (mixed *command : commands) {
    if (sizeof(command[COMMAND_VERBS]) 
        && (primary_verb == command[COMMAND_VERBS][0])) {
      command = deep_copy(command);
      command[COMMAND_ID] = id;
      command[COMMAND_CONTROLLER] = 
        expand_path(command[COMMAND_CONTROLLER], spec);
      return command;
    }
  }

  return 0;
}

/**
 * Parse a boolean string.
 * 
 * @param  value         parse a boolean string
 * @return [description]
 */
int parse_boolean(string value) {
  return (lower_case(value) == TRUE_VALUE);
}

/**
 * Called during a parsing error.
 * 
 * @param  specfile      the spec filename
 * @param  msg           an error message
 */
void parse_error(string specfile, string msg) {
  raise_error(sprintf("Error parsing command spec %s: %s\n", specfile, msg));
}

