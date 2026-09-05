
#ifndef CONFIG_H
#define CONFIG_H

/**************************************************** 
 *                                                  *
 *      Opciones relacionadas con los rangos        *
 *                                                  *
 ****************************************************/
/* No cambiar estos parametros */
#define ADMIN_RANK	"dios"
#define ADMIN_LEVEL	1000
#define PLAYER_RANK	"jugador"

#define ADMIN_EMAIL	"admin@mundooscuro.com"
       
/* SYSTEM INITIAL USERS/GROUPS */
#define ROOT		"mudlib" 
#define NOBODY		"nobody"
#define SYSTEM_USERS	({ ROOT, NOBODY })
#define SYSTEM_GROUPS	({  })


#define IRC_CHANNEL 	"irc"
#define SYSTEM_CHANNELS ({ IRC_CHANNEL })

/**************************************************** 
 *                                                  *
 *        Opciones relacionadas con el LOGIN        *
 *                                                  *
 ****************************************************/

/* Especifica el numero maximo y minimo de caracteres 
 * del nick y el password. 
 */
#define LOGIN_MIN_NAME 3
#define LOGIN_MAX_NAME 12
#define LOGIN_MIN_PASS 5
#define LOGIN_MAX_PASS 12

/* NO_NEW_PLAYERS: definir para deshabilitar la 
 * creacion de nuevos jugadores. 
 */
#undef NO_NEW_PLAYERS

/* LOGIN_TIME: definir el tiempo maximo permitido de login, 
 * en segundos.
 */
#define LOGIN_TIME 240


/**************************************************** 
 *                                                  *
 *        Conexion al servidor de BD's MySQL        *
 *                                                  *
 ****************************************************/

/* Configura la direccion del servidor MySQL, y el nombre 
 * de usuario y de la base de datos 
 */
#define BD_HOST	"127.0.0.1"
#define BD_USER "mud"
#define BD_NAME "mundooscuro"

#endif /* CONFIG_H */


/* Colores */
#define COLOR_MARK	"$"

#define HISTORY_SIZE	20


#define RESET_GRANTS

