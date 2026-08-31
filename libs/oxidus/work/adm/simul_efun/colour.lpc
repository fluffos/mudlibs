#include <simul_efun.h>

/**
 * Adjusts a hex colour by a uniform step value across all RGB channels,
 * clamping each channel to the 0-255 range.
 *
 * @param {string} hex - The hex colour string to adjust
 * @param {float} step - The amount to add to each RGB channel
 * @returns {string} The adjusted colour as a `{{RRGGBB}}` colour code
 */
string gradient_hex(string hex, float step) {
  int *rgb = COLOUR_D->hex_to_rgb(hex);
  float *frgb;

  frgb = map(rgb, (: to_float :));
  frgb = map(frgb, (: clamp($1+$(step), 0.0, 255.0) :));

  rgb = map(frgb, (: to_int :));

  return sprintf("{{%02X%02X%02X}}", rgb...);
}
