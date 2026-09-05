/**
 * A module to support character objects.
 *
 * @author devo@eotl
 * @alias CharacterMixin
 */

inherit NameMixin;
inherit LiteracyMixin;
inherit SpeechMixin;

mapping CAPABILITIES_VAR = ([ CAP_CHARACTER ]);

/**
 * Initialize AvatarMixin. If this function is overloaded, be advised
 * that the mixin's private variables are initialized in the parent
 * implementation.
 */
protected void setup() {
  NameMixin::setup();
  LiteracyMixin::setup();
  SpeechMixin::setup();
}

/**
 * Returns true to designate that this object represents a character.
 *
 * @return 1
 */
public nomask int is_character() {
  return 1;
}
