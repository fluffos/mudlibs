/* This command searches a file's inheritance tree for the actual definition
 * of a method so you know where to go to edit it ;)
 *  -- Al (Oct 1, '03)
 *
 * Zarylse [2003-10-01]
 *  - fixed error that happened when no parameters were given
 *  - reformatted to three-space indents, spacing within parenteses
 *  - allowed function names to end with "()"
 */

#define NOT_FOUND ("__NOT_FOUND__")

/* This function is the great recursive beast that traverses the inheritance
 * tree until it finds the last mention of a function
 */
string find_function( string file, string func ) {
   string *parents, tmp, result = NOT_FOUND;
   mixed *funcs;
   object obj = find_object( file );
   funcs = functionlist( obj );
   // defined in this file
   if ( member(funcs,func) != -1 ) {
      // search parents
      parents = inherit_list( obj );
      foreach ( tmp : parents ) {
         // for some reason, files are listed as inheriting themselves
         if ( tmp == file )
            continue;
         // recursion! yay!
         result = find_function( tmp, func );
         if ( result != NOT_FOUND )
            return result;
      }
      // not found in any parents, must be here then
      return file;
   } else {
      // not defined in this file
      return NOT_FOUND;
   }
}

int main( string arg ) {
   object obj;
   string file, func, result;

   WIZ_CHECK

   if ( !arg || sscanf(arg, "%s %s", file, func) != 2 )
      return notify_fail( "==> [Syntax] ffind <file> <function>\n" );

   file = this_player()->make_path_absolute(file);
   obj = find_object( file );
   if ( !obj )
      return notify_fail( "==> That file does not exist\n");

   // removes ending parentheses if included in function name
   if ( func[<2..] == "()" )
      func = func[..<3];

   if ( member(functionlist(obj), func) == -1 ) {
      msg( func + "() is undefined in " + file + "." );
      return 1;
   }
   result = find_function( file, func );
   msg( func + "() is defined in " + result + "." );
   return 1;
}
