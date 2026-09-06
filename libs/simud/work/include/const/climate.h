#ifndef _CONST_CLIMATE_H_
#define _CONST_CLIMATE_H_

// In minutes -- rate at which weather
// changes. Between this and twice this.
#define WEATHER_DELAY	10

#define W_RAIN		0x00000001
#define W_SLEET		0x00000002
#define W_SNOW		0x00000004
#define W_HAIL		0x00000008
#define W_FOG		0x00000010
#define W_SAND		0x00000020
#define W_CLEAR		0x00000040
#define W_CLOUDY	0x00000080
#define W_OVERCAST	0x00000100
#define W_WINTER	0x00000200
#define W_SPRING	0x00000400
#define W_SUMMER	0x00000800
// Two symbols, same thing ... use your favorite.
#define W_FALL		0x00001000
#define W_AUTUMN	0x00001000
#define W_ALLYEAR	(W_WINTER|W_SPRING|W_SUMMER|W_AUTUMN)
#define W_MILD		0x00002000
#define W_STRONG	0x00004000
#define W_VIOLENT	0x00008000
#define W_WIND		0x00010000

#endif