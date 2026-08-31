/*    /lib/secure/include/cfg.h
 *    from the Dead Souls mud library
 *    maintained by Cratylus http://ww.dead-souls.net
 * 
 *    modified by lash (ccoker) for use in
 *    The Brass Ring mud
 *     - added skills cfg file for use with
 *       skill advancement system
 *     - added this header
 *    last modified 20/05/20
 */

#ifndef __CFG_H__
#define __CFG_H__

#include "dirs.h"

#define CFG_ALIASES		DIR_SECURE_CFG "/aliases.cfg"
#define CFG_CLASSES             DIR_SECURE_CFG "/classes"
#define CFG_DAYS                DIR_CFG "/days.cfg"
#define CFG_FLASH_POLICY        DIR_SECURE_CFG "/flashpolicy.cfg"
#define CFG_GROUPS		DIR_SECURE_CFG "/groups.cfg"
#define CFG_IP_UNRESTRICT	DIR_SECURE_CFG "/ip_unrestrict.cfg"
#define CFG_IP_BLACKLIST        DIR_SECURE_CFG "/ip_blacklist.cfg"
#define CFG_MONTHS              DIR_CFG "/months.cfg"
#define CFG_MOONS               DIR_CFG "/moons.cfg"
#define CFG_PRELOAD		DIR_SECURE_CFG "/preload.cfg"
#define CFG_PRIVS		DIR_SECURE_CFG "/privs.cfg"
#define CFG_RACES               DIR_SECURE_CFG "/races"
#define CFG_READ		DIR_SECURE_CFG "/read.cfg"
#define CFG_SKILLS		DIR_SECURE_CFG "/skills.cfg"
#define CFG_TIME                DIR_CFG "/time.cfg"
#define CFG_TIMEZONES           DIR_CFG "/timezones.cfg"
#define CFG_TIMEZONE            DIR_CFG "/timezone.cfg"
#define CFG_WHERE               DIR_CFG "/where.cfg"
#define CFG_WRITE		DIR_SECURE_CFG "/write.cfg"

#endif /* __CFG_H__ */
