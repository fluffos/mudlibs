/**
 * Support for maintaining character preferences.
 *
 * @author devo@eotl
 * @alias PreferencesMixin
 */

#define PreferencesBinDir       BinDir "/preferences"

/**
 * Return the CommandCode commands that will be made available to
 * implementors of this mixin. This will be invoked by objects implementing
 * CommandGiverMixin for each inherited blueprint.
 *
 * @return an array of paths to CommandCode objects
 */
public string *query_command_imports(object command_giver) {
  return ({
    PreferencesBinDir "/set"
  });
}
