/**
 * Support for items capable of carrying things around.
 *
 * @author devo@eotl
 * @alias CarrierMixin
 */

#define CarrierBinDir       BinDir "/carrier"

/**
 * Return the CommandCode commands that will be made available to
 * implementors of this mixin. This will be invoked by objects implementing
 * CommandGiverMixin for each inherited blueprint.
 *
 * @return an array of paths to CommandCode objects
 */
public string *query_command_imports(object command_giver) {
  return ({
    CarrierBinDir "/get",
    CarrierBinDir "/drop",
    CarrierBinDir "/put"
  });
}
