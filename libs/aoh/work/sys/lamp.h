#ifndef _SYS_LAMP
#define _SYS_LAMP

#define P_BRIGHTNESS "Brightness"
#define P_BURNING    "Burning"
#define P_BURN_STEP  "BurnStep"
#define P_FUEL       "Fuel"
#define P_FUEL_MAX   "FuelMax"
#define P_FUELVALUE  "FuelValue"
#define P_FUELWEIGHT "FuelWeight"
#define P_LAMPVALUE  "LampValue"
#define P_LAMPWEIGHT "LampWeight"
#define P_FUELTYPE   "FuelType"
#define P_LAMP_MSG   "LampMsg"

  /* Values of P_FUELTYPE */

#define PFT_NONE     0
#define PFT_OIL      "oil"
#define PFT_WOOD     "wood"
#define PFT_GAS      "gas"
#define PFT_WAX      "wax"

  /* Entries of P_LAMP_MSG - all are process_string()ed */

#define PLM_IS_BURNING  0  /* Lamp is already burning */
#define PLM_IS_DARK     1  /* Lamp is already dark */
#define PLM_NO_FUEL     2  /* Can't light lamp - no fuel left */
#define PLM_LIGHT       3  /* Message for player when lighting */
#define PLM_LIGHT_E     4  /* Message for envt when lighting */
#define PLM_UNLIGHT     5  /* Message for player when unlighting */
#define PLM_UNLIGHT_E   6  /* Message for env when unlighting */
#define PLM_BURNED_UP   7  /* Message for player when lamp runs out of fuel */
#define PLM_BURNED_UP_E 8  /* Message for env when lamp runs out of fuel */

#define PLM_MAX_MSGS 9

#endif
