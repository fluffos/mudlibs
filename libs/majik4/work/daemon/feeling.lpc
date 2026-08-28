/* Majik 4 server
 * Copyright (C) 1998, 1999  Majik Development Team <majik@majik.netti.fi>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <feeling.h>

string *adverbs = ({
   "accusingly",
   "angrily",
   "bitterly",
   "boredly",
   "crookedly",
   "curiously",
   "diabolically",
   "doubtfully",
   "enthusiastically",
   "fiendishly",
   "gaily",
   "gently",
   "grimly",
   "gruffly",
   "happily",
   "hysterically",
   "jokingly",
   "joyfully",
   "knowingly",
   "maliciously",
   "miserably",
   "passionately",
   "proudly",
   "quickly",
   "quietly",
   "sadly",
   "slowly",
   "teasingly",
   "thoughtfully",
   "tiredly",
   "warily",
   "wildly",
});

mapping feelings = ([
"ah" : ({ "$n1 {let} out an 'ah' of comprehension", FEELTARG_OPTIONAL }),
"blink" : ({ "$n1 {blink} $s1 eyes", FEELTARG_OPTIONAL }),
"blush" : ({ "$n1 {blush}", FEELTARG_OPTIONAL }),
"bow" : ({ "$n1 {bow}", FEELTARG_OPTIONAL }),
"cackle" : ({ "$n1 {cackle}", FEELTARG_OPTIONAL }),
"cheer" : ({ "$n1 {cheer}", FEELTARG_OPTIONAL }),
"clap" : ({ "$n1 {clap}", FEELTARG_OPTIONAL }),
"curse" : ({ "$n1 {curse}", FEELTARG_OPTIONAL }),
"eh" : ({ "$n1 {go} 'Eh?'", FEELTARG_OPTIONAL }),
"giggle" : ({ "$n1 {giggle}", FEELTARG_OPTIONAL }),
"greet" : ({ "$n1 {greet}", FEELTARG_OPTIONAL }),
"grin" : ({ "$n1 {grin}", FEELTARG_OPTIONAL }),
"growl" : ({ "$n1 {go} 'Grrrrrrr...'", FEELTARG_OPTIONAL }),
"grunt" : ({ "$n1 {grunt}", FEELTARG_OPTIONAL }),
"hmm" : ({ "$n1 {go} 'Hmm...'", FEELTARG_OPTIONAL }),
"laugh" : ({ "$n1 {laugh}", FEELTARG_OPTIONAL }),
"mumble" : ({ "$n1 {mumble}", FEELTARG_OPTIONAL }),
"mutter" : ({ "$n1 {mutter}", FEELTARG_OPTIONAL }),
"nod" : ({ "$n1 {nod}", FEELTARG_OPTIONAL }),
"ponder" : ({ "$n1 {ponder}", FEELTARG_OPTIONAL }),
"scratch" : ({ "$n1 {scratch}", FEELTARG_OPTIONAL }),
"shake" : ({ "$n1 {shake} $s1 head", FEELTARG_OPTIONAL }),
"smile" : ({ "$n1 {smile}", FEELTARG_OPTIONAL }),
"snicker" : ({ "$n1 {snicker}", FEELTARG_OPTIONAL }),
"snort" : ({ "$n1 {snort}", FEELTARG_OPTIONAL }),
"turnback" : ({ "$n1 {turn} $s1 back on", FEELTARG_MUST }),
"wave" : ({ "$n1 {wave}", FEELTARG_OPTIONAL }),
"yawn" : ({ "$n1 {yawn}", FEELTARG_NONE }),
]);

mapping
query_feelings()
{
   return feelings;
}

string *
query_adverbs()
{
   return adverbs;
}

mapping
query_feeling(string str)
{
   return feelings[str];
}
