#ifndef _INET3_H_
#define _INET3_H_

/* Define creation for the local name and the admin email
 * NOTE: the file will not load if you did not add an elif branch for your
 *       local machine because of missing admin-email!
 */

#ifndef LOCAL_NAME
#ifdef __HOST_NAME__
#if __HOST_NAME__ == MUDHOST
#define LOCAL_NAME      MUDSHORT
#define ADMIN_EMAIL     GAMESMGR
#define LOCAL_STATUS    "Under construction"
#elif __HOST_NAME__ == "shadowlands"
#define ADMIN_EMAIL     "michael.schaefer@dlr.de"
#define LOCAL_STATUS    "Private mudlib development"
#define LOCAL_NAME      MUDSHORT "-" __HOST_NAME__
#else
#define ADMIN_EMAIL     "noone@nohost.nodomain"
#define LOCAL_STATUS    "Unspecified mud"
#define LOCAL_NAME      MUDSHORT "-" __HOST_NAME__
#endif
#else   /* __HOST_NAME__ */
#define LOCAL_NAME      (MUDSHORT+(query_host_name() == "leander"?"":"-"+query_host_name()))
#endif  /* __HOST_NAME__ */
#endif /* !LOCAL_NAME */

/* Define some settings
 */

#define INET3D_LOG "INET3D"
#define PORT_I3_TCP_OOB  0

#endif
