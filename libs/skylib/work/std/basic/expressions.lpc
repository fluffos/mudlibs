/**
 * This is an inheritable to handle certain sorts of expressions in stuff.
 * These expression can be setup by players (or creators) and then run
 * or evaluated.  It allows controlling the types usable by the expression
 * handlers, strings, arrays, mappings, integers and floats.
 * @author Pinkfish
 * @started Thu May  4 22:44:34 PDT 2000
 */
#include <money.h>
#include <expressions.h>

#define EXPRESSION_AND       -1
#define EXPRESSION_OR        -2
#define EXPRESSION_NOT       -3
#define EXPRESSION_FALSE     -4
#define EXPRESSION_TRUE      -5
#define EXPRESSION_GREATOR_THAN     -6
#define EXPRESSION_LESS_THAN        -7
#define EXPRESSION_EQUAL_TO         -8
#define EXPRESSION_GREATOR_OR_EQUAL -9
#define EXPRESSION_LESS_OR_EQUAL    -10
#define EXPRESSION_PLUS             -11
#define EXPRESSION_MINUS            -12
#define EXPRESSION_MULTIPLY         -13
#define EXPRESSION_DIVIDE           -14
#define EXPRESSION_IF               -15
#define EXPRESSION_NOT_EQUAL_TO     -16

#define EXPRESSION_TREE         0
#define EXPRESSION_PARSE_STRING 1
#define EXPRESSION_TYPE         2

#define EXPRESSION_FUNC_NAME    0
#define EXPRESSION_FUNC_NO_ARGS 1

class variable_thing {
   int type;
   function value;
}

class function_thing {
   int type;
   function value;
   int* arg_types;
}

private mixed* parse_operator(string str, string token);
string query_expression_string(class parse_node* expr, int brief);
class parse_node evaluate_expression(class parse_node* expr, mixed args ...);
mixed query_property(string name);

private nosave mapping _variables;
private nosave mapping _functions;
private nosave string _error_string;

void create() {
   _variables = ([ ]);
   _functions = ([ ]);
   _error_string = "no error";
} /* create() */

/**
 * This method returns the last error if there was an error in the parsing.
 * @return the last error
 */
string query_last_expression_error() {
   return _error_string;
} /* query_last_expression_error() */

/**
 * This method adds in an allowed variable and specifies it's type.
 * @param name the name of the variable
 * @param type the type of the variable
 * @param value the value of the variable
 */
void add_allowed_variable(string name, int type, function value) {
   class variable_thing bing;

   bing = new(class variable_thing);
   bing->type = type;
   bing->value = value;
   _variables[name] = bing;
} /* add_allowed_variable() */

/**
 * This method adds in an allowe function and specifies the types it
 * takes.
 * @param name the name of the function
 * @param type the return type of the function
 * @param args the types of the arguements (an array)
 * @param value the function to call to get the value
 */
void add_allowed_function(string name, int type, int* args, function value) {
   class function_thing bing;

   bing = new(class function_thing);
   bing->type = type;
   bing->arg_types = args;
   bing->value = value;
   _functions[name] = bing;
} /* add_allowed_function() */

/**
 * This method returns the type of the variable.
 * @param name the name of the variable to check
 * @return the type of the variable, EXPRESSION_TYPE_ERROR if there is no
 * variable
 */
int query_variable_type(string name) {
   if (_variables[name]) {
      return _variables[name]->type;
   }
   return EXPRESSION_TYPE_ERROR;
} /* query_variable_type() */

/**
 * This method returns the value of the variable.
 * @param name the name of the variable to find
 * @return the value of the variable, 0 if not found
 */
function query_variable_value(string name) {
   if (_variables[name]) {
      return _variables[name]->value;
   }
   return 0;
} /* query_variable_value() */

/**
 * This method returns the type of the function.
 * @param name the name of the function to check
 * @return the type of the function, EXPRESSION_TYPE_ERROR if there is no
 * function
 */
int query_function_type(string name) {
   if (_functions[name]) {
      return _functions[name]->type;
   }
   return EXPRESSION_TYPE_ERROR;
} /* query_function_type() */

/**
 * This method returns the value of the function.
 * @param name the name of the function to find
 * @return the value of the function, 0 if not found
 */
function query_function_value(string name) {
   if (_functions[name]) {
      return _functions[name]->value;
   }
   return 0;
} /* query_function_value() */

/**
 * This method returns the name of the type.
 * @param type the type to get the string name of
 * @return the string name of the type
 */
string query_type_name(int type) {
   switch (type) {
   case EXPRESSION_TYPE_INTEGER  :
      return "integer";
   case EXPRESSION_TYPE_STRING   :
      return "string";
   case EXPRESSION_TYPE_ARRAY    :
      return "array";
   case EXPRESSION_TYPE_MAPPING  :
      return "mapping";
   case EXPRESSION_TYPE_FLOAT    :
      return "float";
   case EXPRESSION_TYPE_BOOLEAN  :
      return "boolean";
   case EXPRESSION_TYPE_MONEY  :
      return "boolean";
   default :
      return "error";
   }
} /* query_type_name() */

/**
 * This method returns the string value of the operator name.
 * @param operator the operator name to return
 * @return the string name of the operator
 */
string query_operator_name(int operator) {
   switch (operator) {
   case EXPRESSION_AND       :
      return "and";
   case EXPRESSION_OR        :
      return "or";
   case EXPRESSION_NOT       :
      return "not";
   case EXPRESSION_FALSE     :
      return "false";
   case EXPRESSION_TRUE      :
      return "true";
   case EXPRESSION_GREATOR_THAN     :
      return ">";
   case EXPRESSION_LESS_THAN        :
      return "<";
   case EXPRESSION_EQUAL_TO         :
      return "=";
   case EXPRESSION_NOT_EQUAL_TO         :
      return "<>";
   case EXPRESSION_GREATOR_OR_EQUAL :
      return ">=";
   case EXPRESSION_LESS_OR_EQUAL    :
      return "<=";
   case EXPRESSION_PLUS             :
      return "+";
   case EXPRESSION_MINUS            :
      return "-";
   case EXPRESSION_MULTIPLY         :
      return "*";
   case EXPRESSION_DIVIDE           :
      return "/";
   case EXPRESSION_IF               :
      return "if";
   default :
      return "unknown";
   }
} /* query_operator_name() */

private class parse_node make_node(int type, mixed value) {
   class parse_node bing;

   bing = new(class parse_node);
   bing->type = type;
   bing->value = value;
   return bing;
} /* make_parse_node() */

/**
 * This method returns a null object of the specified type.
 * @param type the type to get the null object of
 * @return the null object
 */
class parse_node query_null_type(int type) {
   switch (type) {
   case EXPRESSION_TYPE_INTEGER  :
      return make_node(type, 0);
   case EXPRESSION_TYPE_MONEY  :
      return make_node(type, 0);
   case EXPRESSION_TYPE_STRING   :
      return make_node(type, "");
   case EXPRESSION_TYPE_ARRAY    :
      return make_node(type, ({ }));
   case EXPRESSION_TYPE_MAPPING  :
      return make_node(type, ([ ]));
   case EXPRESSION_TYPE_FLOAT    :
      return make_node(type, 0.0);
   case EXPRESSION_TYPE_BOOLEAN  :
      return make_node(EXPRESSION_TYPE_OPERATOR, EXPRESSION_FALSE);
   default :
      return 0;
   }
} /* query_null_type() */

/**
 * This method checks to see if the passed in character is an alpha
 * or not.
 * @param alpha the character to check
 * @return 1 if it alpha, 0 if not
 */
protected int is_alpha(int alpha) {
   if ((alpha >= 'a' && alpha <= 'z') ||
       (alpha >= 'A' && alpha <= 'Z')) {
      return 1;
   }
   return 0;
} /* isalpha() */

/**
 * This method checks to see if the passed in character is a number
 * or not.
 * @param number the character to check
 * @return 1 if it is a number, 0 if not
 */
protected int is_number(int number) {
   if (number >= '0' && number <= '9') {
      return 1;
   }
   return 0;
} /* is_number() */

/**
 * This method checks to see if the passed in character is a space or
 * a space equivilant.
 * @param space the character to check
 * @return 1 if it is a space, 0 if not
 */
protected int is_space(int space) {
   if (space == ' ' || space == '\t') {
      return 1;
   }
   return 0;
} /* is_space() */

/**
 * This checks to make sure that the type is a number based type.
 * This can be controlled to make sure that any added types are also
 * allowed to be treated as numbers.
 * @param type the type to check
 * @return 1 if it is a number, 0 if not
 */
protected int is_number_type(int type) {
   return type == EXPRESSION_TYPE_INTEGER ||
          type == EXPRESSION_TYPE_FLOAT ||
          type == EXPRESSION_TYPE_MONEY;
} /* is_number_type() */

private int is_valid_variable_name(int type) {
   return type == '_' ||
          is_alpha(type) ||
          is_number(type);
} /* is_number_type() */

/**
 * This method find the next token.  It can be overrideen in higher things
 * to deal with special token types (ie: money).
 * @param str the input string
 * @return ({ token, rest })
 */
protected string* query_token(string str) {
   int i = 0;
   int j;

   while (strlen(str) > 1 && is_space(str[0])) {
      str = str[1..];
   }

   if (!strlen(str)) {
      return ({ "", str });
   }

   // parse money as money...  Make them enclose money inside two $'s.
   // ie: $4 dollars$
   if (str[0] == '$') {
      i = 1;
      while (strlen(str) > i &&
             (str[i] != '$')) {

         i++;
      }
      return ({ str[0..i], str[i+1..] });
   }

   if (str[0] == '-' || is_number(str[0])) {
      i = 0;
      while (strlen(str) > i + 1 &&
             is_number(str[i + 1])) {
         i++;
      }

      return ({ str[0..i], str[i+1..] });
   }

   if (is_alpha(str[0]) || str[0] == '_') {
      //
      // Zip through till we find a non-alpha, non-number.
      //
      while (strlen(str) > i + 1 &&
             is_valid_variable_name(str[i + 1])) {
         i++;
      }
      return ({ str[0..i], str[i+1..] });
   }

   if (str[0] == '"') {
      do {
         j = strsrch(str[i + 1..], "\"");
         if (j == -1) {
            _error_string = "Missing close \"\n";
            return 0;
         }
         i += j + 1;
      } while (str[i - 1] == '\\');
      return ({ str[0..i], str[i+1..] });
   }

   if (str[0] == '\'') {
      do {
         j = strsrch(str[i + 1..], "'");
         if (j == -1) {
            _error_string = "Missing close '\n";
            return 0;
         }
         i += j + 1;
      } while (str[i - 1] == '\\');
      return ({ str[0..i], str[i+1..] });
   }

   while (strlen(str) > i + 1 &&
          !is_alpha(str[i + 1]) &&
          !is_number(str[i + 1]) &&
          !is_space(str[i + 1]) &&
          member_array(str[i + 1], ({ '>', '<', '=', '!', '-', '$', '\'',
                                      '"', '_' })) == -1)
   {
      i++;
   }

   if (i) {
      return ({ str[0..i], str[i+1..] });
   }

   return ({ str[0..0], str[1..] });
} /* query_token() */

private mixed* parse_node(string str, string token) {
   class parse_node num;
   int type;
   int bing;
   int pos;
   string place;
   string fname;
   string* token_ret;
   mixed *stuff;
   mixed *args;

   while (strlen(str) &&
          str[0] == ' ') {
      str = str[1..];
   }

   if (_functions[token]) {
      fname = token;
      token_ret = query_token(str);
      if (!token_ret) {
         return 0;
      }
      if (token_ret[0] != "(") {
         _error_string = "Expected (, got " + token_ret[0] + " rest: " +
                     token_ret[1];
         return 0;
      }
      str = token_ret[1];

      // Get all the args...
      args = ({ });
      token_ret = query_token(str);
      if (!token_ret) {
         return 0;
      }
      if (token_ret[0] != ")") {
         do {
            stuff = parse_operator(token_ret[1], token_ret[0]);
            if (!stuff) {
               return 0;
            }
            pos = sizeof(args);
            if (sizeof(_functions[fname]->arg_types) <= pos) {
               _error_string = "To many arguments to " + token + " expected " +
                              sizeof(_functions[fname]->arg_types);
               return 0;
            }
            if (_functions[fname]->arg_types[pos] != stuff[EXPRESSION_TYPE]) {
               _error_string = "Expected arg " + (pos + 1) + " to be " +
                        query_type_name(_functions[fname]->arg_types[pos]) +
                        " not " + query_type_name(stuff[EXPRESSION_TYPE]);
               return 0;
            }
            str = stuff[EXPRESSION_PARSE_STRING];
            args += stuff[EXPRESSION_TREE];
            token_ret = query_token(str);
            if (!token_ret) {
               return 0;
            }
            if (token_ret[0] == ",") {
               token_ret = query_token(token_ret[1]);
            }
         } while (token_ret[0] != ")");
         if (token_ret[0] != ")") {
            _error_string = "Expected ')' got " + token_ret[0];
            return 0;
         }
         if (sizeof(args) < sizeof(_functions[fname]->arg_types)) {
            _error_string = "To few arguments to " + token + " expected " +
                           sizeof(_functions[fname]->arg_types);
            return 0;
         }
         return ({ args +
                  ({ make_node(EXPRESSION_TYPE_FUNCTION,
                               ({ fname, sizeof(args) })) }),
                  token_ret[1],
                  _functions[fname]->type });
      }
   }
   else switch (token) {
   case "true" :
      num = make_node(EXPRESSION_TYPE_OPERATOR, EXPRESSION_TRUE);
      type = EXPRESSION_TYPE_BOOLEAN;
      break;
   case "false" :
      num = make_node(EXPRESSION_TYPE_OPERATOR, EXPRESSION_FALSE);
      type = EXPRESSION_TYPE_BOOLEAN;
      break;
   case "" :
      _error_string = "No token found at: " + str;
      return 0;
   default :
      if (token[0] == '-' || is_number(token[0])) {
         sscanf(token, "%d", bing);
         num = make_node(EXPRESSION_TYPE_INTEGER, bing);
         type = EXPRESSION_TYPE_INTEGER;
      } else if (token[0] == '$') {
         place = query_property("place");
         if (!place) {
            place = "default";
         }
         bing = MONEY_HAND->value_from_string(token[1..<2], place);
         if (!bing) {
            bing = MONEY_HAND->value_from_string(token[0..<2], place);
         }
         if (bing) {
            num = make_node(EXPRESSION_TYPE_MONEY, bing);
            type = EXPRESSION_TYPE_MONEY;
         } else {
            _error_string = "Money value is invalid: " + token[1..<2] + " and " +
                            token[0..<2];
            return 0;
         }
      } else if (token[0] == '\"' || token[0] == '\'') {
         num = make_node(EXPRESSION_TYPE_STRING, token[1..<2]);
         type = EXPRESSION_TYPE_STRING;
      } else if (query_variable_type(token)) {
         num = make_node(EXPRESSION_TYPE_VARIABLE, token);
         type = query_variable_type(token);
      }
      break;
   }
   return ({ ({ num }), str, type });
} /* parse_node() */

private mixed* parse_bracket(string str, string token) {
   mixed* stuff;
   string* token_ret;

   switch (token) {
   case "(" :
      token_ret = query_token(str);
      if (!token_ret) {
         return 0;
      }
      stuff = parse_operator(token_ret[1], token_ret[0]);
      if (stuff) {
         str = stuff[EXPRESSION_PARSE_STRING];
         token_ret = query_token(str);
         if (!token_ret) {
            return 0;
         }
         if (token_ret[0] !=  ")") {
            _error_string = "Could not find closing bracket at " + str;
            return 0;
         }
         str = token_ret[1];
         return ({ stuff[EXPRESSION_TREE], str,
                   stuff[EXPRESSION_TYPE] });
      }
      break;
   default :
      stuff = parse_node(str, token);
      if (stuff) {
         return ({ stuff[EXPRESSION_TREE],
                   stuff[EXPRESSION_PARSE_STRING],
                   stuff[EXPRESSION_TYPE] });
      }
      break;
   }
} /* parse_bracket() */

private mixed* parse_plus(string str, string token) {
   mixed *stuff;
   mixed *stuff2;
   int type;
   string* token_ret;
   string blue;

   stuff = parse_bracket(str, token);
   if (!stuff) {
      return 0;
   }

   str = stuff[EXPRESSION_PARSE_STRING];

   token_ret = query_token(str);
   if (!token_ret) {
      return 0;
   }

   switch (token_ret[0]) {
   case "+" :
      type = EXPRESSION_PLUS;
      break;
   case "-" :
      type = EXPRESSION_MINUS;
      break;
   }
   blue = token_ret[0];
   if (type) {
      token_ret = query_token(token_ret[1]);
      if (!token_ret) {
         return 0;
      }
      stuff2 = parse_plus(token_ret[1], token_ret[0]);
      if (!stuff2) {
         return 0;
      }
      if ((!is_number_type(stuff[EXPRESSION_TYPE]) ||
          !is_number_type(stuff2[EXPRESSION_TYPE])) &&
          type != EXPRESSION_PLUS) {
         _error_string = "Invalid types to " + blue +
                     " expected number got: " +
                     query_type_name(stuff[EXPRESSION_TYPE]) + " and " +
                     query_type_name(stuff2[EXPRESSION_TYPE]);
         return 0;
      }
      return ({ stuff[EXPRESSION_TREE] + stuff2[EXPRESSION_TREE] +
                ({ make_node(EXPRESSION_TYPE_OPERATOR, type) }),
                stuff2[EXPRESSION_PARSE_STRING], stuff[EXPRESSION_TYPE] });
   } else {
      return stuff;
   }
} /* parse_plus() */

private mixed* parse_multiply(string str, string token) {
   mixed *stuff;
   mixed *stuff2;
   string* token_ret;
   int type;
   string blue;

   stuff = parse_plus(str, token);
   if (!stuff) {
      return 0;
   }

   str = stuff[EXPRESSION_PARSE_STRING];

   token_ret = query_token(str);
   if (!token_ret) {
      return 0;
   }

   switch (token_ret[0]) {
   case "*" :
      type = EXPRESSION_MULTIPLY;
      break;
   case "/" :
      type = EXPRESSION_DIVIDE;
      break;
   }
   blue = token_ret[0];
   if (type) {
      token_ret = query_token(token_ret[1]);
      if (!token_ret) {
         return 0;
      }
      stuff2 = parse_multiply(token_ret[1], token_ret[0]);
      if (!stuff2) {
         return 0;
      }
      if (!is_number_type(stuff[EXPRESSION_TYPE]) ||
           !is_number_type(stuff2[EXPRESSION_TYPE])) {
         _error_string = "Invalid types to " + blue +
                     " expected number got: " +
                     query_type_name(stuff[EXPRESSION_TYPE]) + " and " +
                     query_type_name(stuff2[EXPRESSION_TYPE]);
         return 0;
      }
      return ({ stuff[EXPRESSION_TREE] + stuff2[EXPRESSION_TREE] +
                ({ make_node(EXPRESSION_TYPE_OPERATOR, type) }),
                stuff2[EXPRESSION_PARSE_STRING], stuff[EXPRESSION_TYPE] });
   } else {
      return stuff;
   }
} /* parse_multiply() */

private mixed* parse_compare(string str, string token) {
   mixed *stuff;
   mixed *stuff2;
   string* token_ret;
   int type;
   string blue;

   stuff = parse_multiply(str, token);
   if (!stuff) {
      return 0;
   }

   str = stuff[EXPRESSION_PARSE_STRING];

   token_ret = query_token(str);
   if (!token_ret) {
      return 0;
   }

   switch (token_ret[0]) {
   case ">=" :
      type = EXPRESSION_GREATOR_OR_EQUAL;
      break;
   case "<=" :
      type = EXPRESSION_LESS_OR_EQUAL;
      break;
   case ">" :
      type = EXPRESSION_GREATOR_THAN;
      break;
   case "<" :
      type = EXPRESSION_LESS_THAN;
      break;
   case "<>" :
   case "!=" :
      type = EXPRESSION_NOT_EQUAL_TO;
      break;
   case "==" :
   case "=" :
      type = EXPRESSION_EQUAL_TO;
      break;
   }
   blue = token_ret[0];
   if (type) {
      token_ret = query_token(token_ret[1]);
      if (!token_ret) {
         return 0;
      }
      stuff2 = parse_compare(token_ret[1], token_ret[0]);
      if (!stuff2) {
         return 0;
      }
      if ((!is_number_type(stuff[EXPRESSION_TYPE]) ||
           !is_number_type(stuff2[EXPRESSION_TYPE])) &&
          type != EXPRESSION_EQUAL_TO &&
          type != EXPRESSION_NOT_EQUAL_TO)
      {
         _error_string = "Invalid types to " + blue +
                     " expected number got: " +
                     query_type_name(stuff[EXPRESSION_TYPE]) + " and " +
                     query_type_name(stuff2[EXPRESSION_TYPE]);
         return 0;
      }
      return ({ stuff[EXPRESSION_TREE] + stuff2[EXPRESSION_TREE] +
                ({ make_node(EXPRESSION_TYPE_OPERATOR, type) }),
                stuff2[EXPRESSION_PARSE_STRING],
                EXPRESSION_TYPE_BOOLEAN });
   } else {
      return stuff;
   }
} /* parse_compare() */

private mixed* parse_not(string str, string token) {
   mixed *stuff;

   if (token == "not") {
      stuff = query_token(str);
      if (!stuff) {
         return 0;
      }
      stuff = parse_not(stuff[1], stuff[0]);
      if (!stuff) {
         return 0;
      }
      if (stuff[EXPRESSION_TYPE] != EXPRESSION_TYPE_BOOLEAN) {
         _error_string = "Invalid type to not expected boolean got: " +
                     query_type_name(stuff[EXPRESSION_TYPE]);
         return 0;
      }
      return ({ stuff[EXPRESSION_TREE] +
                ({ make_node(EXPRESSION_TYPE_OPERATOR, EXPRESSION_NOT)  }),
                stuff[EXPRESSION_PARSE_STRING],
                EXPRESSION_TYPE_BOOLEAN });
   } else {
      return parse_compare(str, token);
   }
} /* parse_not() */

private mixed* parse_boolean(string str, string token) {
   mixed *stuff;
   mixed *stuff2;
   string* token_ret;
   string blue;
   int type;

   stuff = parse_not(str, token);
   if (!stuff) {
      return 0;
   }

   str = stuff[EXPRESSION_PARSE_STRING];

   token_ret = query_token(str);
   if (!token_ret) {
      return 0;
   }
   switch (token_ret[0]) {
   case "and" :
      type = EXPRESSION_AND;
      break;
   case "or" :
      type = EXPRESSION_OR;
      break;
   }

   blue = token_ret[0];

   if (type) {
      token_ret = query_token(token_ret[1]);
      if (!token_ret) {
         return 0;
      }
      stuff2 = parse_boolean(token_ret[1], token_ret[0]);
      if (!stuff2) {
         return 0;
      }
      if (stuff[EXPRESSION_TYPE] != stuff2[EXPRESSION_TYPE] ||
          stuff[EXPRESSION_TYPE] != EXPRESSION_TYPE_BOOLEAN) {
         _error_string = "Invalid types to " + blue +
                     " expected boolean got: " +
                     query_type_name(stuff[EXPRESSION_TYPE]) + " and " +
                     query_type_name(stuff2[EXPRESSION_TYPE]);
         return 0;
      }
      return ({ stuff[EXPRESSION_TREE] + stuff2[EXPRESSION_TREE] +
                ({ make_node(EXPRESSION_TYPE_OPERATOR, type) }),
                stuff2[EXPRESSION_PARSE_STRING],
                stuff2[EXPRESSION_TYPE] });
   } else {
      return stuff;
   }
} /* parse_boolean() */

private mixed* parse_operator(string str, string token) {
   mixed *stuff;
   mixed *stuff2;
   mixed *stuff3;
   string* token_ret;

      switch (token) {
      case "if" :
         token_ret = query_token(str);
         if (!token_ret) {
            return 0;
         }
         stuff = parse_operator(token_ret[1], token_ret[0]);
         if (!stuff) {
            return 0;
         }

         if (stuff[EXPRESSION_TYPE] != EXPRESSION_TYPE_BOOLEAN) {
            _error_string = "Invalid type to if expected boolean got: " +
                        query_type_name(stuff[EXPRESSION_TYPE]);
            return 0;
         }
         token_ret = query_token(stuff[EXPRESSION_PARSE_STRING]);
         if (!token_ret) {
            return 0;
         }
         if (token_ret[0] != "then") {
            _error_string = "Expected 'then' got " + token_ret[0];
            return 0;
         }

         token_ret = query_token(token_ret[1]);
         if (!token_ret) {
            return 0;
         }
         stuff2 = parse_operator(token_ret[1], token_ret[0]);
         if (!stuff2) {
            return 0;
         }
         token_ret = query_token(stuff2[EXPRESSION_PARSE_STRING]);
         if (!token_ret) {
            return 0;
         }
         if (token_ret[0] == "else") {
            token_ret = query_token(token_ret[1]);
            if (!token_ret) {
               return 0;
            }
            stuff3 = parse_operator(token_ret[1], token_ret[0]);
            if (!stuff3) {
               return 0;
            }
            if (stuff2[EXPRESSION_TYPE] != stuff3[EXPRESSION_TYPE]) {
               _error_string = "Types on both sides of an if must match: " +
                        query_type_name(stuff2[EXPRESSION_TYPE]) + " and " +
                        query_type_name(stuff3[EXPRESSION_TYPE]);
               return 0;
            }
            token_ret = query_token(stuff3[EXPRESSION_PARSE_STRING]);
            if (!token_ret) {
               return 0;
            }
         } else {
            stuff3 = ({ ({ query_null_type(stuff2[EXPRESSION_TYPE]) }) });
         }
         if (token_ret[0] != "endif") {
            _error_string = "Expected 'endif' got " + token_ret[0];
            return 0;
         }
         return ({ stuff[EXPRESSION_TREE] +
                   stuff2[EXPRESSION_TREE] +
                   stuff3[EXPRESSION_TREE] +
                   ({ make_node(EXPRESSION_TYPE_OPERATOR, EXPRESSION_IF) }),
                   token_ret[1],
                   stuff2[EXPRESSION_TYPE] });
         break;
      default :
         stuff = parse_boolean(str, token);
         if (!stuff) {
            return 0;
         }
         return stuff;
      }
} /* parse_operator() */

/**
 * A very small recursive decent parser which must return a boolean
 * value.
 * @param str the input string
 * @return the array control structure
 */
class parse_node* parse_boolean_string(string str) {
   mixed* stuff;
   string* token_ret;

   token_ret = query_token(lower_case(str));
   if (!token_ret) {
      return 0;
   }
   stuff = parse_operator(token_ret[1], token_ret[0]);

   if (!stuff) {
      return ({ });
   }

   if (strlen(stuff[EXPRESSION_PARSE_STRING])) {
      _error_string = "Unable to parse the rest of: " +
                      stuff[EXPRESSION_PARSE_STRING];
      return ({ });
   }

   if (stuff[EXPRESSION_TYPE] != EXPRESSION_TYPE_BOOLEAN) {
      _error_string = "Invalid return type, expected boolean got " +
                     query_type_name(stuff[EXPRESSION_TYPE]);
      return ({ });
   }

   return stuff[EXPRESSION_TREE];
} /* parse_boolean_string() */

/**
 * A very small recursive decent parser which must return a integer
 * value.
 * @param str the input string
 * @return the array control structure
 */
class parse_node* parse_integer_string(string str) {
   mixed* stuff;
   string* token_ret;

   token_ret = query_token(lower_case(str));
   if (!token_ret) {
      return 0;
   }
   stuff = parse_operator(token_ret[1], token_ret[0]);


   if (!stuff) {
     //printf("%O", _error_string);
      return ({ });
   }

   if (strlen(stuff[EXPRESSION_PARSE_STRING])) {
      _error_string = "Unable to parse the rest of: " +
                      stuff[EXPRESSION_PARSE_STRING];
     //printf("%O", _error_string);
      return ({ });
   }

   if (stuff[EXPRESSION_TYPE] != EXPRESSION_TYPE_INTEGER) {
      _error_string = "Invalid return type, expected integer got " +
                     query_type_name(stuff[EXPRESSION_TYPE]);
//printf("%O", query_expression_string(stuff[EXPRESSION_TREE], 0));
//printf("%O", evaluate_expression(stuff[EXPRESSION_TREE]));
      return ({ });
   }

//printf("%O", query_expression_string(stuff[EXPRESSION_TREE], 0));
//printf("%O", evaluate_expression(stuff[EXPRESSION_TREE]));

   return stuff[EXPRESSION_TREE];
} /* parse_integer_string() */

/**
 * A very small recursive decent parser which must return a money
 * value.
 * @param str the input string
 * @return the array control structure
 */
class parse_node* parse_money_string(string str) {
   mixed* stuff;
   string* token_ret;

   token_ret = query_token(lower_case(str));
   if (!token_ret) {
      return 0;
   }
   stuff = parse_operator(token_ret[1], token_ret[0]);


   if (!stuff) {
     //printf("%O", _error_string);
      return ({ });
   }

   if (strlen(stuff[EXPRESSION_PARSE_STRING])) {
      _error_string = "Unable to parse the rest of: " +
                      stuff[EXPRESSION_PARSE_STRING];
     //printf("%O", _error_string);
      return ({ });
   }

   if (stuff[EXPRESSION_TYPE] != EXPRESSION_TYPE_MONEY) {
      _error_string = "Invalid return type, expected money got " +
                     query_type_name(stuff[EXPRESSION_TYPE]);
//printf("%O", query_expression_string(stuff[EXPRESSION_TREE], 0));
//printf("%O", evaluate_expression(stuff[EXPRESSION_TREE]));
      return ({ });
   }

//printf("%O", stuff[EXPRESSION_TREE]);
//printf("%O", query_expression_string(stuff[EXPRESSION_TREE], 0));
//printf("%O", evaluate_expression(stuff[EXPRESSION_TREE]));

   return stuff[EXPRESSION_TREE];
} /* parse_integer_string() */

/**
 * This method returns the expresion as a string.
 * @param expr the expression
 * @param brief don't expand the variable names
 * @return the expression as a string
 */
string query_expression_string(class parse_node* expr, int brief) {
   string str;
   int i;
   string* stack;
   int* thing;
   string tmp;
   string place;
   int value;
   string indent;

   if (!sizeof(expr)) {
      return "No expression set.";
   }

   place = query_property("place");
   if (!place) {
      place = "default";
   }

   indent = "";
   str = "";
   stack = ({ });
   thing = ({ });
   for (i = 0; i < sizeof(expr); i++) {
      if (!classp(expr[i])) {
         stack += ({ "Broken element" });
         thing += ({ 0 });
         continue;
      }

      switch (expr[i]->type) {
      case EXPRESSION_TYPE_OPERATOR :
         value = expr[i]->value;
         switch (expr[i]->value) {
         case EXPRESSION_NOT :
            str = " " + query_operator_name(expr[i]->value) + " ";
            if (thing[<1] && thing[<1] != expr[i]->value) {
               str += "(" + stack[<1] + ")";
            } else {
               str += stack[<1];
            }
            stack = stack[0..<2];
            thing = thing[0..<2];
            break;
         case EXPRESSION_AND :
         case EXPRESSION_OR :
         case EXPRESSION_PLUS :
         case EXPRESSION_MINUS :
         case EXPRESSION_DIVIDE :
         case EXPRESSION_MULTIPLY :
         case EXPRESSION_GREATOR_THAN     :
         case EXPRESSION_LESS_THAN        :
         case EXPRESSION_EQUAL_TO         :
         case EXPRESSION_GREATOR_OR_EQUAL :
         case EXPRESSION_LESS_OR_EQUAL    :
         case EXPRESSION_NOT_EQUAL_TO     :
            tmp = stack[<2];
            if (thing[<2] && thing[<2] != expr[i]->value) {
               str = "(" + stack[<2] + ")";
            } else {
               str = stack[<2];
            }
            str += " " + query_operator_name(expr[i]->value) + " ";
            if (thing[<1] && thing[<1] != expr[i]->value) {
               str += "(" + stack[<1] + ")";
            } else {
               str += stack[<1];
            }
            stack = stack[0..<3];
            thing = thing[0..<3];
            break;
         case EXPRESSION_TRUE :
            str = "true";
            value = 0;
            break;
         case EXPRESSION_FALSE :
            str = "false";
            value = 0;
            break;
         case EXPRESSION_IF :
            if (brief) {
               str = "if " + stack[<3] + " then " + stack[<2] + " else " +
                     stack[<1] + " endif";
            } else {
               str = "if " + stack[<3] + " then\n" +
                     "   " + replace_string(stack[<2], "\n", "\n   ") +
                     "\nelse\n" +
                     "   " + replace_string(stack[<1], "\n", "\n   ") +
                     "\nendif";
            }
            stack = stack[0..<4];
            thing = thing[0..<4];
            value = 0;
            break;
         default :
            str = "Error!";
            break;
         }
         stack += ({ str });
         thing += ({ value });
         break;
      case EXPRESSION_TYPE_MONEY :
         stack += ({ MONEY_HAND->money_value_string(expr[i]->value, place) });
         thing += ({ 0 });
         break;
      case EXPRESSION_TYPE_INTEGER :
         stack += ({ "" + expr[i]->value });
         thing += ({ 0 });
         break;
      case EXPRESSION_TYPE_STRING :
         stack += ({ "\"" + expr[i]->value + "\"" });
         thing += ({ 0 });
         break;
      case EXPRESSION_TYPE_VARIABLE :
         stack += ({ expr[i]->value });
         thing += ({ 0 });
         break;
      case EXPRESSION_TYPE_FUNCTION :
         str = expr[i]->value[EXPRESSION_FUNC_NAME] + "(";
         str += implode(stack[<expr[i]->value[EXPRESSION_FUNC_NO_ARGS]..],
                        ", ");
         str += ")";
         stack = stack[0..<expr[i]->value[EXPRESSION_FUNC_NO_ARGS] + 1];
         thing = thing[0..<expr[i]->value[EXPRESSION_FUNC_NO_ARGS] + 1];
         stack += ({ str });
         thing += ({ 0 });
         break;
      default :
         stack += ({ "Unknown: " + expr[i]->type + " (" + expr[i]->value + ")" });
         thing += ({ 0 });
         break;
      }
   }
   return stack[<1];
} /* query_expression_string() */

/**
 * This method evaluates the expression and creates a nice end result
 * thingy.
 * @param expr the exrpession to evaluate
 * @param args the optional args parsed into the various function calls
 * @return the type and value of the expression, 0 if failed
 */
class parse_node evaluate_expression(class parse_node* expr, mixed args ...) {
   class parse_node bing;
   class parse_node new_node;
   class parse_node* stack;
   string fname;
   mixed* fargs;

   if (!sizeof(expr)) {
      return make_node(EXPRESSION_TYPE_BOOLEAN, 0);
   }

   stack = ({ });
   foreach (bing in expr) {
      if (!classp(bing)) {
         continue;
      }
      switch (bing->type) {
      case EXPRESSION_TYPE_OPERATOR :
         switch (bing->value) {
         case EXPRESSION_NOT :
            stack[<1] = make_node(EXPRESSION_TYPE_BOOLEAN, !stack[<1]->value);
            break;
         case EXPRESSION_AND :
            stack[<2] = make_node(EXPRESSION_TYPE_BOOLEAN, stack[<1]->value &&
                                                           stack[<2]->value);
            stack = stack[0..<2];
            break;
         case EXPRESSION_OR :
            stack[<2] = make_node(EXPRESSION_TYPE_BOOLEAN, stack[<1]->value ||
                                                           stack[<2]->value);
            stack = stack[0..<2];
            break;
         case EXPRESSION_PLUS :
            stack[<2] = make_node(stack[<1]->type, stack[<2]->value +
                                                   stack[<1]->value);
            stack = stack[0..<2];
            break;
         case EXPRESSION_MINUS :
            stack[<2] = make_node(stack[<1]->type, stack[<2]->value -
                                                   stack[<1]->value);
            stack = stack[0..<2];
            break;
         case EXPRESSION_DIVIDE :
            stack[<2] = make_node(stack[<1]->type, stack[<2]->value /
                                                   stack[<1]->value);
            stack = stack[0..<2];
            break;
         case EXPRESSION_MULTIPLY :
            stack[<2] = make_node(stack[<1]->type, stack[<2]->value *
                                                   stack[<1]->value);
            stack = stack[0..<2];
            break;
         case EXPRESSION_GREATOR_THAN     :
            stack[<2] = make_node(EXPRESSION_TYPE_BOOLEAN, stack[<2]->value >
                                                           stack[<1]->value);
            stack = stack[0..<2];
            break;
         case EXPRESSION_LESS_THAN        :
            stack[<2] = make_node(EXPRESSION_TYPE_BOOLEAN, stack[<2]->value <
                                                           stack[<1]->value);
            stack = stack[0..<2];
            break;
         case EXPRESSION_EQUAL_TO         :
            stack[<2] = make_node(EXPRESSION_TYPE_BOOLEAN, stack[<2]->value ==
                                                           stack[<1]->value);
            stack = stack[0..<2];
            break;
         case EXPRESSION_GREATOR_OR_EQUAL :
            stack[<2] = make_node(EXPRESSION_TYPE_BOOLEAN, stack[<2]->value >=
                                                           stack[<1]->value);
            stack = stack[0..<2];
            break;
         case EXPRESSION_LESS_OR_EQUAL    :
            stack[<2] = make_node(EXPRESSION_TYPE_BOOLEAN, stack[<2]->value <=
                                                           stack[<1]->value);
            stack = stack[0..<2];
            break;
         case EXPRESSION_NOT_EQUAL_TO     :
            stack[<2] = make_node(EXPRESSION_TYPE_BOOLEAN, stack[<2]->value !=
                                                           stack[<1]->value);
            stack = stack[0..<2];
            break;
         case EXPRESSION_IF               :
            if (stack[<3]->value) {
               new_node = stack[<2];
            } else {
               new_node = stack[<1];
            }
            stack = stack[0..<4] + ({ new_node });
            break;
         case EXPRESSION_TRUE             :
            stack += ({ make_node(EXPRESSION_TYPE_BOOLEAN, 1) });
            break;
         case EXPRESSION_FALSE            :
            stack += ({ make_node(EXPRESSION_TYPE_BOOLEAN, 0) });
            break;
         default :
            printf("Unknown operator %O\n", bing);
            break;
         }
         break;
      case EXPRESSION_TYPE_INTEGER :
         stack += ({ copy(bing) });
         break;
      case EXPRESSION_TYPE_STRING :
         stack += ({ copy(bing) });
         break;
      case EXPRESSION_TYPE_MONEY :
         stack += ({ copy(bing) });
         break;
      case EXPRESSION_TYPE_VARIABLE :
         stack += ({ make_node(query_variable_type(bing->value),
                               evaluate(query_variable_value(bing->value),
                                        args ...)) });
         break;
     case EXPRESSION_TYPE_FUNCTION :
         fname = bing->value[EXPRESSION_FUNC_NAME];
         fargs = stack[<bing->value[EXPRESSION_FUNC_NO_ARGS]..];
         stack = stack[0..<bing->value[EXPRESSION_FUNC_NO_ARGS] + 1];
         stack += ({ make_node(query_function_type(fname),
                               evaluate(query_function_value(fname),
                                        map(fargs, (: $1->value :)) +
                                        args ...)) });
         break;
      default :
         printf("Unknown type %O\n", bing);
         break;
      }
//printf("%O: %O\n", bing, stack);
   }
   return stack[<1];
} /* evaluate_expression() */
